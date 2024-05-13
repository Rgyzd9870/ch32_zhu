#include "debug.h"
#include "key.h"

u8 key_value;

//按键初始化函数
void KEY_Init(void) //IO初始化
{
    GPIO_InitTypeDef  GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO|RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOE,ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOE, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

}
//按键处理函数
//返回按键值
//mode:0,不支持连续按;1,支持连续按;
u8 KEY_Scan(u8 mode)
{
    static u8 key_up=1;//按键按松开标志
    if(mode)key_up=1;  //支持连按
    if(key_up&&(JOY_UP==0||JOY_DOWN==0||JOY_RIGHT==0||JOY_LEFT==0||JOY_SEL==0||SW1==0||SW2==0||Wake_Up==1))
    {
        Delay_Ms(10);//去抖动
        key_up=0;
        if(JOY_UP==0)return JOY_UP_PRES;
        else if(JOY_DOWN==0)return JOY_DOWN_PRES;
        else if(JOY_RIGHT==0)return JOY_RIGHT_PRES;
        else if(JOY_LEFT==0)return JOY_LEFT_PRES;
        else if(JOY_SEL==0)return JOY_SEL_PRES;
        else if(SW1==0)return SW1_PRES;
        else if(SW2==0)return SW2_PRES;
        else if(Wake_Up==1)return Wake_Up_PRES;
    }else if(JOY_UP==1&&JOY_DOWN==1&&JOY_RIGHT==1&&JOY_LEFT==1&&JOY_SEL==1&&SW1==1&&SW2==1&&Wake_Up==0)key_up=1;
    return 0;// 无按键按下
}
