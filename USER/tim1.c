#include "tim1.h"
#include "delay.h"
#include "uart.h"
#include "led.h"
#include "key.h"

u16 ADC_Value; 


void TIM1_Init(void)
{
  TIM1->PSCRH = 0x00; // ϵͳʱ�Ӿ�Ԥ��Ƶf=fck/(PSCR+1)
  TIM1->PSCRL = 0x9F; // PSCR=0x3E7F�� f=16M/(159+1)=10us
  TIM1->ARRH = 0x00; // �Զ����ؼĴ���ARR=0x01F4=500
  TIM1->ARRL = 0x64; // ÿ����500�β���һ���жϣ���1ms
  TIM1->IER |= 0x01; // ��������ж�
  TIM1->CR1 |= 0x01; // ������ʹ�ܣ���ʼ����
}

////////////////////   ��ʱ�ж�   ///////////////////////////  
#pragma vector=11+2
__interrupt void TIM1_UPD_OVF_TRG_BRK_IRQHandler(void)
{
  TIM1->SR1 = 0; ////����ж�   ����жϱ��
  ADC_Value = ADC1_GetConversionValue();
}












