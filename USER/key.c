/********************************************************************
 *@file        key.c
 *@author      Woody      QQ：2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       KEY初始化以及扫描函数
 *******************************************************************/
#include "key.h"
#include "led.h"
#include "delay.h"

u8 key_led_flag=0;  // LED灯亮灭标志

/*******************************************************************************
 * 函数名：key_init
 * 描述  ：配置key的初始化
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 ******************************************************************************/
void KEY_Init(void)
{       
    GPIO_Init(GPIOC, GPIO_PIN_7, GPIO_MODE_IN_FL_NO_IT);      //人体红外     
}
/*******************************************************************************
 * 函数名：key_scan
 * 描述  ：配置key扫描函数,写EEPROM
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
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














