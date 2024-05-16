#ifndef _HARDWARE_MY_USART8_H_
#define _HARDWARE_MY_USART8_H_


void USART8_CFG(void);
void DMA8_INIT(void);
FlagStatus uartWriteHeart(char * data , uint16_t num);
uint32_t uartReadHeart(char * buffer , uint16_t num);
FlagStatus uartWriteHeartStr(char * str);
char uartReadByteHeart();
uint16_t uartAvailableHeart();
void Rx8Buffer_Printf(char *buffer);
uint8_t heart_receive_judge(char *str);


/*******************************************¡Ÿ ±JFC103ƒ⁄»›***************************************************************/




#endif /* HARDWARE_MY_USART8_H_ */
