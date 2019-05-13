/********************************************************************
 *@file        led.c
 *@author      Woody      QQ：2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       LED 初始化以及LED_Show函数
 *******************************************************************/
#include "led.h"
#include "delay.h"

/*******************************************************************************
 * 函数名：LED_Init
 * 描述  ：配置LED_Init的初始化函数
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 ******************************************************************************/
void LED_Init(void)
{       
    //定义LED的管脚为输出模式 
    GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_OUT_PP_HIGH_FAST );  // LED 灯-模块
    GPIO_Init(GPIOA, GPIO_PIN_2, GPIO_MODE_OUT_PP_HIGH_FAST ); //LED -开发板
}
/*******************************************************************************
 * 函数名：FAST_LED
 * 描述  ：配置FAST_LED初始化函数
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 ******************************************************************************/
void FAST_LED(void)
{
    GPIO_WriteHigh(GPIOD, GPIO_PIN_3);// 亮
    delay_ms(20);
    GPIO_WriteLow(GPIOD, GPIO_PIN_3);//  灭
    delay_ms(20);
    
    GPIO_WriteHigh(GPIOD, GPIO_PIN_3);// 亮
    delay_ms(40);
    GPIO_WriteLow(GPIOD, GPIO_PIN_3);//  灭
    delay_ms(40);
    
    GPIO_WriteHigh(GPIOD, GPIO_PIN_3);// 亮
    delay_ms(40);
    GPIO_WriteLow(GPIOD, GPIO_PIN_3);//  灭
    delay_ms(40);
    
    GPIO_WriteHigh(GPIOD, GPIO_PIN_3);// 亮
    delay_ms(40);
    GPIO_WriteLow(GPIOD, GPIO_PIN_3);//  灭
    delay_ms(40);
    
    GPIO_WriteHigh(GPIOD, GPIO_PIN_3);// 亮
    delay_ms(40);
    GPIO_WriteLow(GPIOD, GPIO_PIN_3);//  灭
    delay_ms(40);
}















