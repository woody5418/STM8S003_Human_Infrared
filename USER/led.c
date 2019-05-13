/********************************************************************
 *@file        led.c
 *@author      Woody      QQ��2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       LED ��ʼ���Լ�LED_Show����
 *******************************************************************/
#include "led.h"
#include "delay.h"

/*******************************************************************************
 * ��������LED_Init
 * ����  ������LED_Init�ĳ�ʼ������
 * ����  ����
 * ���  ����
 * ����  ���ⲿ����
 ******************************************************************************/
void LED_Init(void)
{       
    //����LED�Ĺܽ�Ϊ���ģʽ 
    GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_OUT_PP_HIGH_FAST );  // LED ��-ģ��
    GPIO_Init(GPIOA, GPIO_PIN_2, GPIO_MODE_OUT_PP_HIGH_FAST ); //LED -������
}
/*******************************************************************************
 * ��������FAST_LED
 * ����  ������FAST_LED��ʼ������
 * ����  ����
 * ���  ����
 * ����  ���ⲿ����
 ******************************************************************************/
void FAST_LED(void)
{
    GPIO_WriteHigh(GPIOD, GPIO_PIN_3);// ��
    delay_ms(20);
    GPIO_WriteLow(GPIOD, GPIO_PIN_3);//  ��
    delay_ms(20);
    
    GPIO_WriteHigh(GPIOD, GPIO_PIN_3);// ��
    delay_ms(40);
    GPIO_WriteLow(GPIOD, GPIO_PIN_3);//  ��
    delay_ms(40);
    
    GPIO_WriteHigh(GPIOD, GPIO_PIN_3);// ��
    delay_ms(40);
    GPIO_WriteLow(GPIOD, GPIO_PIN_3);//  ��
    delay_ms(40);
    
    GPIO_WriteHigh(GPIOD, GPIO_PIN_3);// ��
    delay_ms(40);
    GPIO_WriteLow(GPIOD, GPIO_PIN_3);//  ��
    delay_ms(40);
    
    GPIO_WriteHigh(GPIOD, GPIO_PIN_3);// ��
    delay_ms(40);
    GPIO_WriteLow(GPIOD, GPIO_PIN_3);//  ��
    delay_ms(40);
}















