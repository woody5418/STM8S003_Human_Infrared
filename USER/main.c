/*************** (C) COPYRIGHT  四维拓智 ***************************************
 * 文件名  ：main.c
 * 描述    ：工程模板    
 * 库版本  ：V1.1.0
 * 开发人员：Woody QQ：2490006131
 * 修改时间：2016-10-14
*******************************************************************************/


/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "delay.h"
#include "sysclock.h"
#include "led.h"
#include "key.h"
#include "uart.h"
#include "adc.h"

/*  Defines -----------------------------------------------------------*/
/*  Variate ---------------------------------------------------------*/
int main(void)
{ 
  u16 ADC_Value;
  
  /* 系统时钟初始化 */
  SystemClock_Init(); 
  delay_init(16);
  ADC_Init();
  LED_Init();
  KEY_Init();
  //enableInterrupts(); 	/* 开启总中断 */ 
  FAST_LED();

  while (1)
  { 
    ADC_Value = ADC1_GetConversionValue();   
    if(ADC_Value >= 45000)  // 高
    {
      
      if(ADC_Value >= 45000)
      {
        Key_Scan();
      } else 
      {
        ADC_Value=0;
        GPIO_WriteLow(GPIOA, GPIO_PIN_2);
      }
    }else  
    {
      GPIO_WriteLow(GPIOA, GPIO_PIN_2);
    }
  }
}

#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
    
  }
}
#endif






