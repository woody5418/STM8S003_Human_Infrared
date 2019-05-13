/********************************************************************
 *@file        key.c
 *@author      Woody      QQ��2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       KEY��ʼ���Լ�ɨ�躯��
 *******************************************************************/
#include "key.h"
#include "led.h"
#include "delay.h"

u8 key_led_flag=0;  // LED�������־

/*******************************************************************************
 * ��������key_init
 * ����  ������key�ĳ�ʼ��
 * ����  ����
 * ���  ����
 * ����  ���ⲿ����
 ******************************************************************************/
void KEY_Init(void)
{       
    GPIO_Init(GPIOC, GPIO_PIN_7, GPIO_MODE_IN_FL_NO_IT);      //�������     
}
/*******************************************************************************
 * ��������key_scan
 * ����  ������keyɨ�躯��,дEEPROM
 * ����  ����
 * ���  ����
 * ����  ���ⲿ����
 ******************************************************************************/
void Key_Scan(void)
{
  if(GPIO_ReadInputPin(GPIOC, GPIO_PIN_7) == 0)
  {
   // delay_ms(10);
      GPIO_WriteLow(GPIOA, GPIO_PIN_2);
      GPIO_WriteLow(GPIOD, GPIO_PIN_3);
  }else if(GPIO_ReadInputPin(GPIOC, GPIO_PIN_7) != 0)
  {
   // delay_ms(10);
      GPIO_WriteHigh(GPIOA, GPIO_PIN_2);
      GPIO_WriteHigh(GPIOD, GPIO_PIN_3);
  }
    
}














