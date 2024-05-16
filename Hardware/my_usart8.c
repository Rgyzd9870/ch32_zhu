#include "debug.h"
#include "string.h"
#include "my_usart8.h"

#define RXBUF_SIZE8 1024 // DMA buffer size

u8 TxBuffer_u8[] = "\0";
u8 RxBuffer_u8[RXBUF_SIZE8]={0};  //只定义了临时缓存区

void UART8_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

/*******************************************************************************
* Function Name  : USART8_CFG
* Description    : Initializes the USART6 peripheral.
* 描述    ：   串口初始化
* RX:DMA2_11;TX:DMA2_10
* Input          : None
* Return         : None
*******************************************************************************/
void USART8_CFG(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    //开启时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART8, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

    GPIO_PinRemapConfig(GPIO_FullRemap_USART8, ENABLE);

    /* USART8 TX-->E14  RX-->E15 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOE, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;           //RX，输入上拉
    GPIO_Init(GPIOE, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = 38400;                    // 波特率(特殊)
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;     // 数据位 8
    USART_InitStructure.USART_StopBits = USART_StopBits_1;          // 停止位 1
    USART_InitStructure.USART_Parity = USART_Parity_No;             // 无校验
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // 无硬件流控
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; //使能 RX 和 TX

    USART_Init(UART8, &USART_InitStructure);

    USART_Cmd(UART8, ENABLE);                                        //开启UART

    USART_ITConfig(UART8, USART_IT_IDLE, ENABLE);

    /* 嵌套向量中断控制器组选择 */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    /* 配置USART为中断源 */
    NVIC_InitStructure.NVIC_IRQChannel = UART8_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;

    NVIC_Init(&NVIC_InitStructure);
}

/*******************************************************************************
* Function Name  : DMA8_INIT
* Description    : Configures the DMA.
* 描述    ：   DMA 初始化
* Input          : None
* Return         : None
*******************************************************************************/
void DMA8_INIT(void)
{
    DMA_InitTypeDef DMA_InitStructure;
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);

    // TX DMA 初始化
    DMA_DeInit(DMA2_Channel10);
    DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)(&UART8->DATAR);        // DMA 外设基址，需指向对应的外设
    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)TxBuffer_u8;                   // DMA 内存基址，指向发送缓冲区的首地址
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;                      // 方向 : 外设 作为 终点，即 内存 ->  外设
    DMA_InitStructure.DMA_BufferSize = 0;                                   // 缓冲区大小,即要DMA发送的数据长度,目前没有数据可发
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;        // 外设地址自增，禁用
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;                 // 内存地址自增，启用
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; // 外设数据位宽，8位(Byte)
    DMA_InitStructure.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte;         // 内存数据位宽，8位(Byte)
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;                           // 普通模式，发完结束，不循环发送
    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;                 // 优先级最高
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;                            // M2P,禁用M2M
    DMA_Init(DMA2_Channel10, &DMA_InitStructure);

    // RX DMA 初始化，环形缓冲区自动接收
    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)RxBuffer_u8;                   // 接收缓冲区
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;                      // 方向 : 外设 作为 源，即 内存 <- 外设
    DMA_InitStructure.DMA_BufferSize = RXBUF_SIZE8;                          // 缓冲区长度为 RXBUF_SIZE
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;                         // 循环模式，构成环形缓冲区
    DMA_Init(DMA2_Channel11, &DMA_InitStructure);

    DMA_Cmd(DMA2_Channel10, ENABLE);                                  //开启接收 DMA（需修改）
    DMA_Cmd(DMA2_Channel11, ENABLE);                                  //开启接收 DMA（需修改）
}


/*******************************************************************************
* Function Name  :  uartWriteHeart
* Description    :  send data to ESP8266 via UART6
* 描述    ：   向 WiFi 模组发送数据
* 采集开：0x8A;采集关：0x88
* Input          :  char * data          data to send   要发送的数据的首地址
*                   uint16_t num         number of data 数据长度
* Return         :  RESET                UART6 busy,failed to send  发送失败
*                   SET                  send success               发送成功
*******************************************************************************/
FlagStatus uartWriteHeart(char * data , uint16_t num)
{
    //如上次发送未完成，返回
    if(DMA_GetCurrDataCounter(DMA2_Channel10) != 0){
        return RESET;
    }

    DMA_ClearFlag(DMA2_FLAG_TC10);
    DMA_Cmd(DMA2_Channel10, DISABLE );           // 关 DMA 后操作
    DMA2_Channel10->MADDR = (uint32_t)data;      // 发送缓冲区为 data
    DMA_SetCurrDataCounter(DMA2_Channel10,num);  // 设置缓冲区长度
    DMA_Cmd(DMA2_Channel10, ENABLE);             // 开 DMA
    return SET;
}

/*******************************************************************************
* Function Name  :  uartReadHeart
* Description    :  read some bytes from receive buffer 从接收缓冲区读出一组数据(buffer)
* Input          :  char * buffer        buffer to storage the data 用来存放读出数据的地址
*                   uint16_t num         number of data to read     要读的字节数
* Return         :  i                  number of bytes read       返回实际读出的字节数
*******************************************************************************/
uint16_t rxBufferReadPos_u8 = 0;       //接收缓冲区读指针
uint32_t uartReadHeart(char * buffer , uint16_t num)
{
    uint16_t rxBufferEnd = RXBUF_SIZE8 - DMA_GetCurrDataCounter(DMA2_Channel11); // 计算的是已经接收到缓冲区中、但还没有被读取的数据的结束位置。
    uint16_t i = 0;
    if (rxBufferReadPos_u8 == rxBufferEnd){
        // 无数据，返回
        return 0;
    }

    while (rxBufferReadPos_u8!=rxBufferEnd && i < num){  //如果正在读取的数据小于需要读的DMA数据，并小于规定的最大读取值
        buffer[i] = RxBuffer_u8[rxBufferReadPos_u8]; //将自动缓冲区数据读出
        i++;  //读取总个数
        rxBufferReadPos_u8++;
        if(rxBufferReadPos_u8 >= RXBUF_SIZE8){
            // 超出缓冲区，回零
            rxBufferReadPos_u8 = 0;
        }
    }
    return i;
}

/*******************************************************************************
* Function Name  :  uartWriteHeartStr
* Description    :  send string to ESP8266 via UART6    向 心跳模组发送字符串
* Input          :  char * str          string to send
* Return         :  RESET                UART busy,failed to send   发送失败
*                   SET                  send success               发送成功
*******************************************************************************/
FlagStatus uartWriteHeartStr(char * str)
{
    uint16_t num = 0;
    while(str[num])num++;           // 计算字符串长度
    return uartWriteHeart(str,num);
}

/*******************************************************************************
* Function Name  :  uartReadByteHeart
* Description    :  read one byte from UART buffer  从接收缓冲区读出 1 字节数据
* Input          :  None
* Return         :  char    read data               返回读出的数据(无数据也返回0)
*******************************************************************************/
char uartReadByteHeart()
{
    char ret;
    uint16_t rxBufferEnd = RXBUF_SIZE8 - DMA_GetCurrDataCounter(DMA2_Channel11);
    // 计算的是已经接收到缓冲区中、但还没有被读取的数据的结束位置。
    if (rxBufferReadPos_u8 == rxBufferEnd){
        // 无数据，返回
        return 0;
    }
    ret = RxBuffer_u8[rxBufferReadPos_u8];
    rxBufferReadPos_u8++;
    if(rxBufferReadPos_u8 >= RXBUF_SIZE8){
        // 超出缓冲区，回零
        rxBufferReadPos_u8 = 0;
    }
    return ret;
}
/*******************************************************************************
* Function Name  :  uartAvailableHeart
* Description    :  get number of bytes Available to read from the UART buffer  获取缓冲区中可读数据的数量
* Input          :  None
* Return         :  uint16_t    number of bytes Available to read               返回可读数据数量
*******************************************************************************/
uint16_t uartAvailableHeart()
{
    uint16_t rxBufferEnd = RXBUF_SIZE8 - DMA_GetCurrDataCounter(DMA2_Channel11);//计算 DMA 数据尾的位置 = 缓冲区-当前DMA剩余数量
    // 计算可读字节
    if (rxBufferReadPos_u8 <= rxBufferEnd){
        return rxBufferEnd - rxBufferReadPos_u8;  //返回还可以读多少字节
    }else{
        return rxBufferEnd +RXBUF_SIZE8 -rxBufferReadPos_u8;
    }
}

/*******************************************************************************
* Function Name  :  Rx8Buffer_Printf
* Description    :  UARTx printf content of UART8 DMA RxBuffer_u8  Debug串口打印缓冲区中的内容
* Input          :  char* data
* Return         :  char*  缓冲区中的内容
*******************************************************************************/
void Rx8Buffer_Printf(char *buffer)
{

    memset(buffer,'\0',sizeof(buffer));
    int num = uartAvailableHeart();  //获取可以读的数据量
    if(num>=0)
    {
        uartReadHeart(buffer , 88); //读取数据到buffer
//        printf("%s\r\n",buffer);
    }
}

/***************************************************************************
描述: 获取DMA缓冲区的数据，比较其中的字符串是否与参数相同
参数: 字符串
返回: 有:1      无:0
****************************************************************************/
uint8_t heart_receive_judge(char *str)
{
    char *data;
    int num;
    char buffer[1024]={"\0"};  //正式储存区

    Delay_Ms(100);

    num = uartAvailableHeart(); //获取还有多少字节
    if (num > 0 )
    {
        uartReadHeart(buffer , num);
        printf("Revceived:\r\n%s",buffer);
    }

    data=strstr(buffer,str);
    if(data != NULL)
    {
        return 1;
    }
    return 0;
}

