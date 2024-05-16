#include "debug.h"
#include "string.h"
#include "my_usart8.h"

#define RXBUF_SIZE8 1024 // DMA buffer size

u8 TxBuffer_u8[] = "\0";
u8 RxBuffer_u8[RXBUF_SIZE8]={0};  //ֻ��������ʱ������

void UART8_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

/*******************************************************************************
* Function Name  : USART8_CFG
* Description    : Initializes the USART6 peripheral.
* ����    ��   ���ڳ�ʼ��
* RX:DMA2_11;TX:DMA2_10
* Input          : None
* Return         : None
*******************************************************************************/
void USART8_CFG(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    //����ʱ��
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
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;           //RX����������
    GPIO_Init(GPIOE, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = 38400;                    // ������(����)
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;     // ����λ 8
    USART_InitStructure.USART_StopBits = USART_StopBits_1;          // ֹͣλ 1
    USART_InitStructure.USART_Parity = USART_Parity_No;             // ��У��
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // ��Ӳ������
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; //ʹ�� RX �� TX

    USART_Init(UART8, &USART_InitStructure);

    USART_Cmd(UART8, ENABLE);                                        //����UART

    USART_ITConfig(UART8, USART_IT_IDLE, ENABLE);

    /* Ƕ�������жϿ�������ѡ�� */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    /* ����USARTΪ�ж�Դ */
    NVIC_InitStructure.NVIC_IRQChannel = UART8_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;

    NVIC_Init(&NVIC_InitStructure);
}

/*******************************************************************************
* Function Name  : DMA8_INIT
* Description    : Configures the DMA.
* ����    ��   DMA ��ʼ��
* Input          : None
* Return         : None
*******************************************************************************/
void DMA8_INIT(void)
{
    DMA_InitTypeDef DMA_InitStructure;
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);

    // TX DMA ��ʼ��
    DMA_DeInit(DMA2_Channel10);
    DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)(&UART8->DATAR);        // DMA �����ַ����ָ���Ӧ������
    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)TxBuffer_u8;                   // DMA �ڴ��ַ��ָ���ͻ��������׵�ַ
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;                      // ���� : ���� ��Ϊ �յ㣬�� �ڴ� ->  ����
    DMA_InitStructure.DMA_BufferSize = 0;                                   // ��������С,��ҪDMA���͵����ݳ���,Ŀǰû�����ݿɷ�
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;        // �����ַ����������
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;                 // �ڴ��ַ����������
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; // ��������λ��8λ(Byte)
    DMA_InitStructure.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte;         // �ڴ�����λ��8λ(Byte)
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;                           // ��ͨģʽ�������������ѭ������
    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;                 // ���ȼ����
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;                            // M2P,����M2M
    DMA_Init(DMA2_Channel10, &DMA_InitStructure);

    // RX DMA ��ʼ�������λ������Զ�����
    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)RxBuffer_u8;                   // ���ջ�����
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;                      // ���� : ���� ��Ϊ Դ���� �ڴ� <- ����
    DMA_InitStructure.DMA_BufferSize = RXBUF_SIZE8;                          // ����������Ϊ RXBUF_SIZE
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;                         // ѭ��ģʽ�����ɻ��λ�����
    DMA_Init(DMA2_Channel11, &DMA_InitStructure);

    DMA_Cmd(DMA2_Channel10, ENABLE);                                  //�������� DMA�����޸ģ�
    DMA_Cmd(DMA2_Channel11, ENABLE);                                  //�������� DMA�����޸ģ�
}


/*******************************************************************************
* Function Name  :  uartWriteHeart
* Description    :  send data to ESP8266 via UART6
* ����    ��   �� WiFi ģ�鷢������
* �ɼ�����0x8A;�ɼ��أ�0x88
* Input          :  char * data          data to send   Ҫ���͵����ݵ��׵�ַ
*                   uint16_t num         number of data ���ݳ���
* Return         :  RESET                UART6 busy,failed to send  ����ʧ��
*                   SET                  send success               ���ͳɹ�
*******************************************************************************/
FlagStatus uartWriteHeart(char * data , uint16_t num)
{
    //���ϴη���δ��ɣ�����
    if(DMA_GetCurrDataCounter(DMA2_Channel10) != 0){
        return RESET;
    }

    DMA_ClearFlag(DMA2_FLAG_TC10);
    DMA_Cmd(DMA2_Channel10, DISABLE );           // �� DMA �����
    DMA2_Channel10->MADDR = (uint32_t)data;      // ���ͻ�����Ϊ data
    DMA_SetCurrDataCounter(DMA2_Channel10,num);  // ���û���������
    DMA_Cmd(DMA2_Channel10, ENABLE);             // �� DMA
    return SET;
}

/*******************************************************************************
* Function Name  :  uartReadHeart
* Description    :  read some bytes from receive buffer �ӽ��ջ���������һ������(buffer)
* Input          :  char * buffer        buffer to storage the data ������Ŷ������ݵĵ�ַ
*                   uint16_t num         number of data to read     Ҫ�����ֽ���
* Return         :  i                  number of bytes read       ����ʵ�ʶ������ֽ���
*******************************************************************************/
uint16_t rxBufferReadPos_u8 = 0;       //���ջ�������ָ��
uint32_t uartReadHeart(char * buffer , uint16_t num)
{
    uint16_t rxBufferEnd = RXBUF_SIZE8 - DMA_GetCurrDataCounter(DMA2_Channel11); // ��������Ѿ����յ��������С�����û�б���ȡ�����ݵĽ���λ�á�
    uint16_t i = 0;
    if (rxBufferReadPos_u8 == rxBufferEnd){
        // �����ݣ�����
        return 0;
    }

    while (rxBufferReadPos_u8!=rxBufferEnd && i < num){  //������ڶ�ȡ������С����Ҫ����DMA���ݣ���С�ڹ涨������ȡֵ
        buffer[i] = RxBuffer_u8[rxBufferReadPos_u8]; //���Զ����������ݶ���
        i++;  //��ȡ�ܸ���
        rxBufferReadPos_u8++;
        if(rxBufferReadPos_u8 >= RXBUF_SIZE8){
            // ����������������
            rxBufferReadPos_u8 = 0;
        }
    }
    return i;
}

/*******************************************************************************
* Function Name  :  uartWriteHeartStr
* Description    :  send string to ESP8266 via UART6    �� ����ģ�鷢���ַ���
* Input          :  char * str          string to send
* Return         :  RESET                UART busy,failed to send   ����ʧ��
*                   SET                  send success               ���ͳɹ�
*******************************************************************************/
FlagStatus uartWriteHeartStr(char * str)
{
    uint16_t num = 0;
    while(str[num])num++;           // �����ַ�������
    return uartWriteHeart(str,num);
}

/*******************************************************************************
* Function Name  :  uartReadByteHeart
* Description    :  read one byte from UART buffer  �ӽ��ջ��������� 1 �ֽ�����
* Input          :  None
* Return         :  char    read data               ���ض���������(������Ҳ����0)
*******************************************************************************/
char uartReadByteHeart()
{
    char ret;
    uint16_t rxBufferEnd = RXBUF_SIZE8 - DMA_GetCurrDataCounter(DMA2_Channel11);
    // ��������Ѿ����յ��������С�����û�б���ȡ�����ݵĽ���λ�á�
    if (rxBufferReadPos_u8 == rxBufferEnd){
        // �����ݣ�����
        return 0;
    }
    ret = RxBuffer_u8[rxBufferReadPos_u8];
    rxBufferReadPos_u8++;
    if(rxBufferReadPos_u8 >= RXBUF_SIZE8){
        // ����������������
        rxBufferReadPos_u8 = 0;
    }
    return ret;
}
/*******************************************************************************
* Function Name  :  uartAvailableHeart
* Description    :  get number of bytes Available to read from the UART buffer  ��ȡ�������пɶ����ݵ�����
* Input          :  None
* Return         :  uint16_t    number of bytes Available to read               ���ؿɶ���������
*******************************************************************************/
uint16_t uartAvailableHeart()
{
    uint16_t rxBufferEnd = RXBUF_SIZE8 - DMA_GetCurrDataCounter(DMA2_Channel11);//���� DMA ����β��λ�� = ������-��ǰDMAʣ������
    // ����ɶ��ֽ�
    if (rxBufferReadPos_u8 <= rxBufferEnd){
        return rxBufferEnd - rxBufferReadPos_u8;  //���ػ����Զ������ֽ�
    }else{
        return rxBufferEnd +RXBUF_SIZE8 -rxBufferReadPos_u8;
    }
}

/*******************************************************************************
* Function Name  :  Rx8Buffer_Printf
* Description    :  UARTx printf content of UART8 DMA RxBuffer_u8  Debug���ڴ�ӡ�������е�����
* Input          :  char* data
* Return         :  char*  �������е�����
*******************************************************************************/
void Rx8Buffer_Printf(char *buffer)
{

    memset(buffer,'\0',sizeof(buffer));
    int num = uartAvailableHeart();  //��ȡ���Զ���������
    if(num>=0)
    {
        uartReadHeart(buffer , 88); //��ȡ���ݵ�buffer
//        printf("%s\r\n",buffer);
    }
}

/***************************************************************************
����: ��ȡDMA�����������ݣ��Ƚ����е��ַ����Ƿ��������ͬ
����: �ַ���
����: ��:1      ��:0
****************************************************************************/
uint8_t heart_receive_judge(char *str)
{
    char *data;
    int num;
    char buffer[1024]={"\0"};  //��ʽ������

    Delay_Ms(100);

    num = uartAvailableHeart(); //��ȡ���ж����ֽ�
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

