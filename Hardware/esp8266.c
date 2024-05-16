#include "debug.h"
#include "string.h"
#include "cJSON.h"
/* Global define */
#define RXBUF_SIZE 1024 // DMA buffer size
#define size(a)   (sizeof(a) / sizeof(*(a)))

const char *Token = "version=2018-10-31&res=products%2F04RLFX3eC5%2Fdevices%2FD003&et=1729454774&method=sha256&sign=tKkM3b5pYMxgBZ5DzQp0xITPgz3fKIZrrOlTB9A%2BNRA%3D";
const char* pubtopic = "$sys/04RLFX3eC5/D003/thing/property/post";
const char* subscribe = "$sys/04RLFX3eC5/D003/thing/property/set";
/* Global Variable */
u8 TxBuffer[] = "\0";
u8 RxBuffer[RXBUF_SIZE]={0};

/*******************************************************************************
* Function Name  : USARTx_CFG
* Description    : Initializes the USART6 peripheral.
* 描述    ：   串口初始化
* Input          : None
* Return         : None
*******************************************************************************/
void USART6_CFG(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    //开启时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART6, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    /* USART6 TX-->C0  RX-->C1 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;           //RX，输入上拉
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = 115200;                    // 波特率
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;     // 数据位 8
    USART_InitStructure.USART_StopBits = USART_StopBits_1;          // 停止位 1
    USART_InitStructure.USART_Parity = USART_Parity_No;             // 无校验
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // 无硬件流控
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; //使能 RX 和 TX

    USART_Init(UART6, &USART_InitStructure);
    DMA_Cmd(DMA2_Channel7, ENABLE);                                  //开启接收 DMA
    USART_Cmd(UART6, ENABLE);                                        //开启UART
}

/*******************************************************************************
* Function Name  : DMA_INIT
* Description    : Configures the DMA.
* 描述    ：   DMA 初始化
* Input          : None
* Return         : None
*******************************************************************************/
void DMA_INIT(void)
{
    DMA_InitTypeDef DMA_InitStructure;
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);

    // TX DMA 初始化
    DMA_DeInit(DMA2_Channel6);
    DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)(&UART6->DATAR);        // DMA 外设基址，需指向对应的外设
    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)TxBuffer;                   // DMA 内存基址，指向发送缓冲区的首地址
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;                      // 方向 : 外设 作为 终点，即 内存 ->  外设
    DMA_InitStructure.DMA_BufferSize = 0;                                   // 缓冲区大小,即要DMA发送的数据长度,目前没有数据可发
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;        // 外设地址自增，禁用
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;                 // 内存地址自增，启用
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; // 外设数据位宽，8位(Byte)
    DMA_InitStructure.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte;         // 内存数据位宽，8位(Byte)
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;                           // 普通模式，发完结束，不循环发送
    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;                 // 优先级最高
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;                            // M2P,禁用M2M
    DMA_Init(DMA2_Channel6, &DMA_InitStructure);

    // RX DMA 初始化，环形缓冲区自动接收
    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)RxBuffer;                   // 接收缓冲区
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;                      // 方向 : 外设 作为 源，即 内存 <- 外设
    DMA_InitStructure.DMA_BufferSize = RXBUF_SIZE;                          // 缓冲区长度为 RXBUF_SIZE
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;                         // 循环模式，构成环形缓冲区
    DMA_Init(DMA2_Channel7, &DMA_InitStructure);
}

/*******************************************************************************
* Function Name  :  uartWriteWiFi
* Description    :  send data to ESP8266 via UART6
* 描述    ：   向 WiFi 模组发送数据
* Input          :  char * data          data to send   要发送的数据的首地址
*                   uint16_t num         number of data 数据长度
* Return         :  RESET                UART6 busy,failed to send  发送失败
*                   SET                  send success               发送成功
*******************************************************************************/
FlagStatus uartWriteWiFi(char * data , uint16_t num)
{
    //如上次发送未完成，返回
    if(DMA_GetCurrDataCounter(DMA2_Channel6) != 0){
        return RESET;
    }

    DMA_ClearFlag(DMA2_FLAG_TC8);
    DMA_Cmd(DMA2_Channel6, DISABLE );           // 关 DMA 后操作
    DMA2_Channel6->MADDR = (uint32_t)data;      // 发送缓冲区为 data
    DMA_SetCurrDataCounter(DMA2_Channel6,num);  // 设置缓冲区长度
    DMA_Cmd(DMA2_Channel6, ENABLE);             // 开 DMA
    return SET;
}

/*******************************************************************************
* Function Name  :  uartReadWiFireceive
* Description    :  read some bytes from receive buffer 从接收缓冲区读出一组数据
* Input          :  char * buffer        buffer to storage the data 用来存放读出数据的地址
*                   uint16_t num         number of data to read     要读的字节数
* Return         :  int                  number of bytes read       返回实际读出的字节数
*******************************************************************************/
uint16_t rxBufferReadPos = 0;       //接收缓冲区读指针
uint32_t uartReadWiFi(char * buffer , uint16_t num)
{
    uint16_t rxBufferEnd = RXBUF_SIZE - DMA_GetCurrDataCounter(DMA2_Channel7); //计算 DMA 数据尾的位置
    uint16_t i = 0;
    if (rxBufferReadPos == rxBufferEnd){
        // 无数据，返回
        return 0;
    }

    while (rxBufferReadPos!=rxBufferEnd && i < num){
        buffer[i] = RxBuffer[rxBufferReadPos];
        i++;
        rxBufferReadPos++;
        if(rxBufferReadPos >= RXBUF_SIZE){
            // 超出缓冲区，回零
            rxBufferReadPos = 0;
        }
    }
    return i;
}

/*******************************************************************************
* Function Name  :  uartWriteWiFiStr
* Description    :  send string to ESP8266 via UART6    向 WiFi 模组发送字符串
* Input          :  char * str          string to send
* Return         :  RESET                UART busy,failed to send   发送失败
*                   SET                  send success               发送成功
*******************************************************************************/
FlagStatus uartWriteWiFiStr(char * str)
{
    uint16_t num = 0;
    while(str[num])num++;           // 计算字符串长度
    return uartWriteWiFi(str,num);
}

/*******************************************************************************
* Function Name  :  uartReadByteWiFi
* Description    :  read one byte from UART buffer  从接收缓冲区读出 1 字节数据
* Input          :  None
* Return         :  char    read data               返回读出的数据(无数据也返回0)
*******************************************************************************/
char uartReadByteWiFi()
{
    char ret;
    uint16_t rxBufferEnd = RXBUF_SIZE - DMA_GetCurrDataCounter(DMA2_Channel7);
    if (rxBufferReadPos == rxBufferEnd){
        // 无数据，返回
        return 0;
    }
    ret = RxBuffer[rxBufferReadPos];
    rxBufferReadPos++;
    if(rxBufferReadPos >= RXBUF_SIZE){
        // 超出缓冲区，回零
        rxBufferReadPos = 0;
    }
    return ret;
}
/*******************************************************************************
* Function Name  :  uartAvailableWiFi
* Description    :  get number of bytes Available to read from the UART buffer  获取缓冲区中可读数据的数量
* Input          :  None
* Return         :  uint16_t    number of bytes Available to read               返回可读数据数量
*******************************************************************************/
uint16_t uartAvailableWiFi()
{
    uint16_t rxBufferEnd = RXBUF_SIZE - DMA_GetCurrDataCounter(DMA2_Channel7);//计算 DMA 数据尾的位置
    // 计算可读字节
    if (rxBufferReadPos <= rxBufferEnd){
        return rxBufferEnd - rxBufferReadPos;
    }else{
        return rxBufferEnd +RXBUF_SIZE -rxBufferReadPos;
    }
}

/*******************************************************************************
* Function Name  :  RxBuffer_Printf
* Description    :  UARTx printf content of UART6 DMA RxBuffer  Debug串口打印缓冲区中的内容
* Input          :  char* data
* Return         :  char*  缓冲区中的内容
*******************************************************************************/
void RxBuffer_Printf(char *buffer)
{
    memset(buffer,'\0',sizeof(buffer));
    int num = uartAvailableWiFi();
    if (num > 0 )
    {
        uartReadWiFi(buffer , num);
        printf("%s\r\n",buffer);
    }
}

/***************************************************************************
描述: 获取DMA缓冲区的数据，比较其中的字符串是否与参数相同
参数: 字符串
返回: 有:1      无:0
****************************************************************************/
uint8_t esp8266_receive_judge(char *str)
{
    char *data;
    int num;
    char buffer[1024]={"\0"};

    Delay_Ms(100);

    num = uartAvailableWiFi();
    if (num > 0 )
    {
        uartReadWiFi(buffer , num);
        printf("Revceived:\r\n%s",buffer);
    }

    data=strstr(buffer,str);
    if(data != NULL)
    {
        return 1;
    }
    return 0;
}

/***************************************************************************
描述: 连接一个名为 SSID、密码为 PASSWORD 的 WiFi 网络
参数: 字符串
返回: 有:1      无:0
****************************************************************************/
void ESP8266_WIFICONTEST(char *ID,char *Password)
{
    char WIFI[256]="\0";
    sprintf(WIFI,"AT+CWJAP=\"%s\",\"%s\"\r\n",ID,Password);
    while(uartWriteWiFiStr(WIFI)==RESET);
    Delay_Ms(500);
}

/***************************************************************************
描述: 设置 MQTT 用户属性
参数: 字符串
返回: 有:1      无:0
****************************************************************************/
void ESP8266_MQTTUSERCFG(char *DEVID,char *ID)
{
    char MQTTUSERCFG[256]="\0";
    sprintf(MQTTUSERCFG,"AT+MQTTUSERCFG=0,1,\"%s\",\"%s\",\"%s\",0,0,\"\"\r\n",DEVID,ID,Token);
    while(uartWriteWiFiStr(MQTTUSERCFG)==RESET);
    Delay_Ms(500);
}

/***************************************************************************
描述: MQTT发布到云平台
参数: 字符串
返回: 无
****************************************************************************/
void ESP8266_MQTTPUB(char *DATA)
{
    char cmdBuf[256];
    char buffer[256]={"\0"};

    cJSON* cjson_main = NULL;
    cJSON* cjson_params = NULL;
    cJSON* cjson_temperature = NULL;
    cJSON* cjson_humidity = NULL;

    /* 创建一个JSON数据对象(链表头结点) */
    cjson_main = cJSON_CreateObject();
    /* 添加两条字符串类型的JSON数据(添加一个链表节点) */
    cJSON_AddStringToObject(cjson_main, "id", "123");
    cJSON_AddStringToObject(cjson_main, "version", "1.0");
    /* 添加一个嵌套的JSON数据（添加一个链表节点） */
    cjson_params = cJSON_CreateObject();
    cJSON_AddItemToObject(cjson_main, "params", cjson_params);
    /* 添加两个嵌套的JSON数据到 cjson_params */
    cjson_temperature = cJSON_CreateObject();
    cJSON_AddNumberToObject(cjson_temperature, "value", 66);
    cJSON_AddItemToObject(cjson_params, "BatteryPercentage", cjson_temperature);

    cjson_humidity = cJSON_CreateObject();
    cJSON_AddNumberToObject(cjson_humidity, "value", 88);
    cJSON_AddItemToObject(cjson_params, "RespiratoryRate", cjson_humidity);

    cJSON_SetNumberHelper(cJSON_GetObjectItem(cjson_humidity,"value"),66);

    /* 打印JSON对象(整条链表)的所有数据 */
    char *str = cJSON_PrintUnformatted(cjson_main);
    printf("%s\n", str);
    uint8_t size=0;
    while(*str!='\0')
    {
        str++;
        size++;
    }
    printf("%d\r\n",size);
    str = cJSON_PrintUnformatted(cjson_main);

    sprintf(cmdBuf,"AT+MQTTPUBRAW=0,\"%s\",%d,0,0\r\n",pubtopic,size);
    while(uartWriteWiFiStr(cmdBuf)==RESET);
    Delay_Ms(100);
    while(uartWriteWiFi(str,size)==RESET);
    Delay_Ms(100);
    RxBuffer_Printf(buffer);
}

/***************************************************************************
描述: MQTT订阅到云平台
参数: void
返回: 无
****************************************************************************/
void ESP8266_MQTTSUB(void)
{
    char cmdBuf[256];
    char buffer[256]="\0";

    sprintf(cmdBuf,"AT+MQTTSUB=0,\"%s\",0\r\n",subscribe);
    while(uartWriteWiFiStr(cmdBuf)==RESET);
    Delay_Ms(1000);
    RxBuffer_Printf(buffer);

    while(1)
    {
        while(!uartAvailableWiFi())
        {
            Delay_Ms(1000);
            printf("1\r\n");
        }
        RxBuffer_Printf(buffer);
    }
}

/*******************************************************************************
* Function Name  :  ESP8266_Init
* Description    :  Initializes ESP8266 and relevant peripheral
* Input          :  None
* Return         :  None
*******************************************************************************/
void ESP8266_Init(void)
{
    char buffer[1024]="\0";

    DMA_INIT();
    USART6_CFG();                                                 /* USART INIT */
    USART_DMACmd(UART6,USART_DMAReq_Tx|USART_DMAReq_Rx,ENABLE);

    // 退出透传
    while (uartWriteWiFi("+++", 3));
    Delay_Ms(100);
    // 查询 WiFi 模块是否正常工作
    uartWriteWiFi("AT\r\n",4);
    Delay_Ms(100);
    //断开与服务器的连接
    while(uartWriteWiFiStr("AT+CIPCLOSE\r\n")==RESET);
    Delay_Ms(100);
    // 断开与mqtt的连接
    while(uartWriteWiFiStr("AT+MQTTCLEAN=0\r\n")==RESET);
    Delay_Ms(100);
    // 查询 WiFi 模块是否正常工作
    uartWriteWiFi("AT\r\n",4);
    Delay_Ms(100);
    // 查询 打开AT回显
    uartWriteWiFi("ATE1\r\n",6);
    Delay_Ms(100);
    // 设为 Station 模式
    while(uartWriteWiFiStr("AT+CWMODE=1\r\n")==RESET);
    Delay_Ms(100);
    while(uartWriteWiFiStr("AT+CWDHCP=1,1\r\n")==RESET)
    Delay_Ms(500);
    // 设为单连接模式
    while(uartWriteWiFiStr("AT+CIPMUX=0\r\n")==RESET);
    Delay_Ms(100);
    //连接一个名为 SSID、密码为 PASSWORD 的 WiFi 网络
    ESP8266_WIFICONTEST("Redmi K40","15813991772");
    Delay_Ms(1000);
    RxBuffer_Printf(buffer);
    Delay_Ms(100);
    //设置 MQTT 用户属性
    ESP8266_MQTTUSERCFG("D003","04RLFX3eC5");
    Delay_Ms(500);
    // 连接 MQTT Broker
    while(uartWriteWiFiStr("AT+MQTTCONN=0,\"mqtts.heclouds.com\",1883,0\r\n")==RESET);
    Delay_Ms(1000);
    RxBuffer_Printf(buffer);
}
