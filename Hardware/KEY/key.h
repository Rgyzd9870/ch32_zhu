#ifndef __KEY_H
#define __KEY_H

#include "debug.h"

#define JOY_UP      GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_1)
#define JOY_DOWN    GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)
#define JOY_RIGHT   GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)
#define JOY_LEFT    GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_6)
#define JOY_SEL     GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_13)
#define SW1         GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)
#define SW2         GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_5)
#define Wake_Up     GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)

#define JOY_RIGHT_PRES   4
#define JOY_LEFT_PRES    3
#define JOY_DOWN_PRES    0
#define JOY_UP_PRES      0
#define JOY_SEL_PRES     5
#define SW1_PRES         0
#define SW2_PRES         0
#define Wake_Up_PRES     0

extern u8 key_value;

void KEY_Init(void);//IO初始化
u8 KEY_Scan(u8);    //按键扫描函数

#endif
