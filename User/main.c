/********************************** (C) COPYRIGHT *******************************
* File Name          : main.c
* Author             : WCH
* Version            : V1.0.0
* Date               : 2021/06/06
* Description        : Main program body.
*********************************************************************************
* Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
* Attention: This software (modified or not) and binary are used for 
* microcontroller manufactured by Nanjing Qinheng Microelectronics.
*******************************************************************************/

/*
 *@Note
 USART Print debugging routine:
 USART1_Tx(PA9).
 This example demonstrates using USART1(PA9) as a print debug port output.

*/

#include "debug.h"
#include "esp8266.h"
#include "stdio.h"
#include "string.h"
#include "my_usart8.h"

/* Global typedef */

/* Global define */

/* Global Variable */
u8 buff[256] ={0};

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	SystemCoreClockUpdate();
	Delay_Init();
	USART_Printf_Init(115200);
	printf("SystemClk:%d\r\n",SystemCoreClock);
    printf( "ChipID:%08x\r\n", DBGMCU_GetCHIPID() );
    printf("This is printf example\r\n");

	USART8_CFG();
	DMA8_INIT();
	USART_DMACmd(UART8,USART_DMAReq_Tx|USART_DMAReq_Rx,ENABLE);
	Delay_Ms(100);
	USART_SendData(UART8, 0x8a);

//	ESP8266_Init();
//	ESP8266_MQTTPUB(NULL);
//	ESP8266_MQTTSUB();

	while(1)
    {
//	    Rx8Buffer_Printf(buff);
//	    Delay_Ms(1280);


	}
}


