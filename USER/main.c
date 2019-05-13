/*************** (C) COPYRIGHT  ��ά���� ***************************************
 * �ļ���  ��main.c
 * ����    ������ģ��    
 * ��汾  ��V1.1.0
 * ������Ա��Woody QQ��2490006131
 * �޸�ʱ�䣺2016-10-14
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
  
  /* ϵͳʱ�ӳ�ʼ�� */
  SystemClock_Init(); 
  delay_init(16);
  ADC_Init();
  LED_Init();
  KEY_Init();
  //enableInterrupts(); 	/* �������ж� */ 
  FAST_LED();

  while (1)
  { 
    ADC_Value = ADC1_GetConversionValue();   
    if(ADC_Value >= 45000)  // ��
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






