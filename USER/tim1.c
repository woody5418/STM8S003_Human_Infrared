#include "tim1.h"
#include "delay.h"
#include "uart.h"
#include "led.h"
#include "key.h"

u16 ADC_Value; 


void TIM1_Init(void)
{
  TIM1->PSCRH = 0x00; // 系统时钟经预分频f=fck/(PSCR+1)
  TIM1->PSCRL = 0x9F; // PSCR=0x3E7F， f=16M/(159+1)=10us
  TIM1->ARRH = 0x00; // 自动重载寄存器ARR=0x01F4=500
  TIM1->ARRL = 0x64; // 每记数500次产生一次中断，即1ms
  TIM1->IER |= 0x01; // 允许更新中断
  TIM1->CR1 |= 0x01; // 计数器使能，开始计数
}

////////////////////   定时中断   ///////////////////////////  
#pragma vector=11+2
__interrupt void TIM1_UPD_OVF_TRG_BRK_IRQHandler(void)
{
  TIM1->SR1 = 0; ////溢出中断   清除中断标记
  ADC_Value = ADC1_GetConversionValue();
}












