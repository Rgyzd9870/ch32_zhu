#include "timer6.h"
#include "lvgl.h"

void TIM6_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

void TIM6_Init(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE);           //使能TIM6时钟
    TIM_TimeBaseInitStructure.TIM_Period    = 10-1;               //自动重装载值
    TIM_TimeBaseInitStructure.TIM_Prescaler = 144-1;              //定时器分频
    TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
    TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
    TIM_TimeBaseInit(TIM6,&TIM_TimeBaseInitStructure);            //初始化TIM6

    TIM_ITConfig(TIM6,TIM_IT_Update,ENABLE);                       //使能定时器更新中断

    NVIC_InitStructure.NVIC_IRQChannel=TIM6_IRQn;                  //中断通道
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;                  //通道使能
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;        //先优先级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;               //从优先级

    NVIC_Init(&NVIC_InitStructure);                                //中断初始化
    TIM_Cmd(TIM6,ENABLE);                                          //使能定时器
}

void TIM6_IRQHandler(void)
{
    if( TIM_GetITStatus(TIM6, TIM_IT_Update) == SET )
    {
        lv_tick_inc(1); /* lvgl 的 1ms 心跳 */
        TIM_ClearITPendingBit(TIM6, TIM_IT_Update); // 清除掉 TIMx 的更新中断标志
    }
}
