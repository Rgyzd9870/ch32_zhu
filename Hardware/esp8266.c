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
* ����    ��   ���ڳ�ʼ��
* Input          : None
* Return         : None
*******************************************************************************/
void USART6_CFG(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    //����ʱ��
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART6, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    /* USART6 TX-->C0  RX-->C1 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;           //RX����������
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = 115200;                    // ������
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;     // ����λ 8
    USART_InitStructure.USART_StopBits = USART_StopBits_1;          // ֹͣλ 1
    USART_InitStructure.USART_Parity = USART_Parity_No;             // ��У��
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // ��Ӳ������
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; //ʹ�� RX �� TX

    USART_Init(UART6, &USART_InitStructure);
    DMA_Cmd(DMA2_Channel7, ENABLE);                                  //�������� DMA
    USART_Cmd(UART6, ENABLE);                                        //����UART
}

/*******************************************************************************
* Function Name  : DMA_INIT
* Description    : Configures the DMA.
* ����    ��   DMA ��ʼ��
* Input          : None
* Return         : None
*******************************************************************************/
void DMA_INIT(void)
{
    DMA_InitTypeDef DMA_InitStructure;
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);

    // TX DMA ��ʼ��
    DMA_DeInit(DMA2_Channel6);
    DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)(&UART6->DATAR);        // DMA �����ַ����ָ���Ӧ������
    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)TxBuffer;                   // DMA �ڴ��ַ��ָ���ͻ��������׵�ַ
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;                      // ���� : ���� ��Ϊ �յ㣬�� �ڴ� ->  ����
    DMA_InitStructure.DMA_BufferSize = 0;                                   // ��������С,��ҪDMA���͵����ݳ���,Ŀǰû�����ݿɷ�
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;        // �����ַ����������
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;                 // �ڴ��ַ����������
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; // ��������λ��8λ(Byte)
    DMA_InitStructure.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte;         // �ڴ�����λ��8λ(Byte)
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;                           // ��ͨģʽ�������������ѭ������
    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;                 // ���ȼ����
    DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;                            // M2P,����M2M
    DMA_Init(DMA2_Channel6, &DMA_InitStructure);

    // RX DMA ��ʼ�������λ������Զ�����
    DMA_InitStructure.DMA_MemoryBaseAddr = (u32)RxBuffer;                   // ���ջ�����
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;                      // ���� : ���� ��Ϊ Դ���� �ڴ� <- ����
    DMA_InitStructure.DMA_BufferSize = RXBUF_SIZE;                          // ����������Ϊ RXBUF_SIZE
    DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;                         // ѭ��ģʽ�����ɻ��λ�����
    DMA_Init(DMA2_Channel7, &DMA_InitStructure);
}

/*******************************************************************************
* Function Name  :  uartWriteWiFi
* Description    :  send data to ESP8266 via UART6
* ����    ��   �� WiFi ģ�鷢������
* Input          :  char * data          data to send   Ҫ���͵����ݵ��׵�ַ
*                   uint16_t num         number of data ���ݳ���
* Return         :  RESET                UART6 busy,failed to send  ����ʧ��
*                   SET                  send success               ���ͳɹ�
*******************************************************************************/
FlagStatus uartWriteWiFi(char * data , uint16_t num)
{
    //���ϴη���δ��ɣ�����
    if(DMA_GetCurrDataCounter(DMA2_Channel6) != 0){
        return RESET;
    }

    DMA_ClearFlag(DMA2_FLAG_TC8);
    DMA_Cmd(DMA2_Channel6, DISABLE );           // �� DMA �����
    DMA2_Channel6->MADDR = (uint32_t)data;      // ���ͻ�����Ϊ data
    DMA_SetCurrDataCounter(DMA2_Channel6,num);  // ���û���������
    DMA_Cmd(DMA2_Channel6, ENABLE);             // �� DMA
    return SET;
}

/*******************************************************************************
* Function Name  :  uartReadWiFireceive
* Description    :  read some bytes from receive buffer �ӽ��ջ���������һ������
* Input          :  char * buffer        buffer to storage the data ������Ŷ������ݵĵ�ַ
*                   uint16_t num         number of data to read     Ҫ�����ֽ���
* Return         :  int                  number of bytes read       ����ʵ�ʶ������ֽ���
*******************************************************************************/
uint16_t rxBufferReadPos = 0;       //���ջ�������ָ��
uint32_t uartReadWiFi(char * buffer , uint16_t num)
{
    uint16_t rxBufferEnd = RXBUF_SIZE - DMA_GetCurrDataCounter(DMA2_Channel7); //���� DMA ����β��λ��
    uint16_t i = 0;
    if (rxBufferReadPos == rxBufferEnd){
        // �����ݣ�����
        return 0;
    }

    while (rxBufferReadPos!=rxBufferEnd && i < num){
        buffer[i] = RxBuffer[rxBufferReadPos];
        i++;
        rxBufferReadPos++;
        if(rxBufferReadPos >= RXBUF_SIZE){
            // ����������������
            rxBufferReadPos = 0;
        }
    }
    return i;
}

/*******************************************************************************
* Function Name  :  uartWriteWiFiStr
* Description    :  send string to ESP8266 via UART6    �� WiFi ģ�鷢���ַ���
* Input          :  char * str          string to send
* Return         :  RESET                UART busy,failed to send   ����ʧ��
*                   SET                  send success               ���ͳɹ�
*******************************************************************************/
FlagStatus uartWriteWiFiStr(char * str)
{
    uint16_t num = 0;
    while(str[num])num++;           // �����ַ�������
    return uartWriteWiFi(str,num);
}

/*******************************************************************************
* Function Name  :  uartReadByteWiFi
* Description    :  read one byte from UART buffer  �ӽ��ջ��������� 1 �ֽ�����
* Input          :  None
* Return         :  char    read data               ���ض���������(������Ҳ����0)
*******************************************************************************/
char uartReadByteWiFi()
{
    char ret;
    uint16_t rxBufferEnd = RXBUF_SIZE - DMA_GetCurrDataCounter(DMA2_Channel7);
    if (rxBufferReadPos == rxBufferEnd){
        // �����ݣ�����
        return 0;
    }
    ret = RxBuffer[rxBufferReadPos];
    rxBufferReadPos++;
    if(rxBufferReadPos >= RXBUF_SIZE){
        // ����������������
        rxBufferReadPos = 0;
    }
    return ret;
}
/*******************************************************************************
* Function Name  :  uartAvailableWiFi
* Description    :  get number of bytes Available to read from the UART buffer  ��ȡ�������пɶ����ݵ�����
* Input          :  None
* Return         :  uint16_t    number of bytes Available to read               ���ؿɶ���������
*******************************************************************************/
uint16_t uartAvailableWiFi()
{
    uint16_t rxBufferEnd = RXBUF_SIZE - DMA_GetCurrDataCounter(DMA2_Channel7);//���� DMA ����β��λ��
    // ����ɶ��ֽ�
    if (rxBufferReadPos <= rxBufferEnd){
        return rxBufferEnd - rxBufferReadPos;
    }else{
        return rxBufferEnd +RXBUF_SIZE -rxBufferReadPos;
    }
}

/*******************************************************************************
* Function Name  :  RxBuffer_Printf
* Description    :  UARTx printf content of UART6 DMA RxBuffer  Debug���ڴ�ӡ�������е�����
* Input          :  char* data
* Return         :  char*  �������е�����
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
����: ��ȡDMA�����������ݣ��Ƚ����е��ַ����Ƿ��������ͬ
����: �ַ���
����: ��:1      ��:0
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
����: ����һ����Ϊ SSID������Ϊ PASSWORD �� WiFi ����
����: �ַ���
����: ��:1      ��:0
****************************************************************************/
void ESP8266_WIFICONTEST(char *ID,char *Password)
{
    char WIFI[256]="\0";
    sprintf(WIFI,"AT+CWJAP=\"%s\",\"%s\"\r\n",ID,Password);
    while(uartWriteWiFiStr(WIFI)==RESET);
    Delay_Ms(500);
}

/***************************************************************************
����: ���� MQTT �û�����
����: �ַ���
����: ��:1      ��:0
****************************************************************************/
void ESP8266_MQTTUSERCFG(char *DEVID,char *ID)
{
    char MQTTUSERCFG[256]="\0";
    sprintf(MQTTUSERCFG,"AT+MQTTUSERCFG=0,1,\"%s\",\"%s\",\"%s\",0,0,\"\"\r\n",DEVID,ID,Token);
    while(uartWriteWiFiStr(MQTTUSERCFG)==RESET);
    Delay_Ms(500);
}

/***************************************************************************
����: MQTT��������ƽ̨
����: �ַ���
����: ��
****************************************************************************/
void ESP8266_MQTTPUB(char *DATA)
{
    char cmdBuf[256];
    char buffer[256]={"\0"};

    cJSON* cjson_main = NULL;
    cJSON* cjson_params = NULL;
    cJSON* cjson_temperature = NULL;
    cJSON* cjson_humidity = NULL;

    /* ����һ��JSON���ݶ���(����ͷ���) */
    cjson_main = cJSON_CreateObject();
    /* ��������ַ������͵�JSON����(���һ������ڵ�) */
    cJSON_AddStringToObject(cjson_main, "id", "123");
    cJSON_AddStringToObject(cjson_main, "version", "1.0");
    /* ���һ��Ƕ�׵�JSON���ݣ����һ������ڵ㣩 */
    cjson_params = cJSON_CreateObject();
    cJSON_AddItemToObject(cjson_main, "params", cjson_params);
    /* �������Ƕ�׵�JSON���ݵ� cjson_params */
    cjson_temperature = cJSON_CreateObject();
    cJSON_AddNumberToObject(cjson_temperature, "value", 66);
    cJSON_AddItemToObject(cjson_params, "BatteryPercentage", cjson_temperature);

    cjson_humidity = cJSON_CreateObject();
    cJSON_AddNumberToObject(cjson_humidity, "value", 88);
    cJSON_AddItemToObject(cjson_params, "RespiratoryRate", cjson_humidity);

    cJSON_SetNumberHelper(cJSON_GetObjectItem(cjson_humidity,"value"),66);

    /* ��ӡJSON����(��������)���������� */
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
����: MQTT���ĵ���ƽ̨
����: void
����: ��
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

    // �˳�͸��
    while (uartWriteWiFi("+++", 3));
    Delay_Ms(100);
    // ��ѯ WiFi ģ���Ƿ���������
    uartWriteWiFi("AT\r\n",4);
    Delay_Ms(100);
    //�Ͽ��������������
    while(uartWriteWiFiStr("AT+CIPCLOSE\r\n")==RESET);
    Delay_Ms(100);
    // �Ͽ���mqtt������
    while(uartWriteWiFiStr("AT+MQTTCLEAN=0\r\n")==RESET);
    Delay_Ms(100);
    // ��ѯ WiFi ģ���Ƿ���������
    uartWriteWiFi("AT\r\n",4);
    Delay_Ms(100);
    // ��ѯ ��AT����
    uartWriteWiFi("ATE1\r\n",6);
    Delay_Ms(100);
    // ��Ϊ Station ģʽ
    while(uartWriteWiFiStr("AT+CWMODE=1\r\n")==RESET);
    Delay_Ms(100);
    while(uartWriteWiFiStr("AT+CWDHCP=1,1\r\n")==RESET)
    Delay_Ms(500);
    // ��Ϊ������ģʽ
    while(uartWriteWiFiStr("AT+CIPMUX=0\r\n")==RESET);
    Delay_Ms(100);
    //����һ����Ϊ SSID������Ϊ PASSWORD �� WiFi ����
    ESP8266_WIFICONTEST("Redmi K40","15813991772");
    Delay_Ms(1000);
    RxBuffer_Printf(buffer);
    Delay_Ms(100);
    //���� MQTT �û�����
    ESP8266_MQTTUSERCFG("D003","04RLFX3eC5");
    Delay_Ms(500);
    // ���� MQTT Broker
    while(uartWriteWiFiStr("AT+MQTTCONN=0,\"mqtts.heclouds.com\",1883,0\r\n")==RESET);
    Delay_Ms(1000);
    RxBuffer_Printf(buffer);
}
