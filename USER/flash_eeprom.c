#include "flash_eeprom.h"
#include "uart.h"
#include "tim1.h"


u16 value_eeprom;
/*******************************************************************************
 * ˵��: ÿ���ͺŵ�EEPROM�Ĵ�С��һ�������ô˺�����ʱ��Ҫע�⽫Ҫд�����ֽ�����
         �Ĵ�С�Ƿ񳬹����ͺŵ�EEPROM�ĵ�ַ��
         ��������EEPROM���ͺ���STM8S208, STM8S207, STM8S007, STM8AF52Ax, STM8AF62Ax 
         EEPROM�ĵ�ַ�Ǵ�0x004000��0x0047ff����2048Byte,ÿ��Block��128Byte,һ��16��Block.
         BlockNum @ 1~16
         ��������EEPROM���ͺ���STM8S105, STM8S005, STM8AF626x
         EEPROM�ĵ�ַ�Ǵ�0x004000��0x0043ff����1024Byte,ÿ��Block��128Byte,һ��8��Block.
         BlockNum @ 1~8
         С������EEPROM���ͺ���STM8S103, STM8S003, STM8S903 
         EEPROM�ĵ�ַ�Ǵ�0x004000��0x00427f����1024Byte,ÿ��Block��64Byte,һ��10��Block.
         BlockNum @ 1~10

 ******************************************************************************/


void Init_EEPROM(void)
{
    FLASH_DeInit();
    //Define flash programming time.
    //���ʱ��Ϊ��׼���ʱ���һ��(1/2 tprog)
    FLASH_SetProgrammingTime(FLASH_PROGRAMTIME_STANDARD); 
}
/*
void WriteEEPROM(u16* data,u16 number)
{
  u16 i;  
  FLASH_SetProgrammingTime(FLASH_PROGRAMTIME_STANDARD);
  FLASH_Unlock(FLASH_MEMTYPE_DATA); // ����EEPROM
  //while (FLASH_GetFlagStatus(FLASH_FLAG_DUL) == RESET)
  for(i=0;i<(number*2);i++)   // д eeprom
  { 
    FLASH_EraseByte(FLASH_DATA_START_PHYSICAL_ADDRESS + i);
    FLASH_ProgramByte(FLASH_DATA_START_PHYSICAL_ADDRESS + i,*(char*)(data+i));
  }
  FLASH_WaitForLastOperation(FLASH_MEMTYPE_DATA);
  FLASH_Lock(FLASH_MEMTYPE_DATA); 
}
*/

void ReadEEPROM(u16* data,u16 number)
{
  u16 i,j;
  u8 data_change_H;
  u8 data_change_L;
  //u8 ir_eeprom_buffer[560];
  
  FLASH_Unlock(FLASH_MEMTYPE_DATA);
  data_change_H = FLASH_ReadByte(FLASH_DATA_START_PHYSICAL_ADDRESS);
  data_change_L = FLASH_ReadByte(FLASH_DATA_START_PHYSICAL_ADDRESS +1);
  number = (data_change_H & 0X00FF)<<8 | (data_change_L & 0x00FF);
  value_eeprom = number;
  for(i=0;i<number;i++)
  {
    data_change_H = FLASH_ReadByte(FLASH_DATA_START_PHYSICAL_ADDRESS + (j+2));
    data_change_L = FLASH_ReadByte(FLASH_DATA_START_PHYSICAL_ADDRESS + (j+3));
    j+=2;
    data[i+1] = (data_change_H & 0X00FF)<<8 | (data_change_L & 0x00FF);    
  }
  FLASH_Lock(FLASH_MEMTYPE_DATA);
  
  WriteEEPROM(TIM_IR_BUFFER,IR_FLAG_REMOVE);
}

void WriteEEPROM(u16* data,u16 number)
{
  u16 i;
  u16 n=0;
  u8 ir_eeprom_buffer[560];
  
  FLASH_SetProgrammingTime(FLASH_PROGRAMTIME_STANDARD);
  FLASH_Unlock(FLASH_MEMTYPE_DATA); // ����EEPROM
  ir_eeprom_buffer[0] = (u8)((number>>8)&0XFF);
  ir_eeprom_buffer[1] = (u8)(number&0XFF);
  for(i=0;i<number;i++)
  {
    ir_eeprom_buffer[n+2] = ((data[i+1]>>8)&0XFF);
    ir_eeprom_buffer[n+3] = (data[i+1]&0XFF);
    n+=2;
  }
  for(i=0;i<(number*2);i++)   // д eeprom
  {
    FLASH_EraseByte(FLASH_DATA_START_PHYSICAL_ADDRESS + i);
    FLASH_ProgramByte(FLASH_DATA_START_PHYSICAL_ADDRESS + i,ir_eeprom_buffer[i]);
  }
  FLASH_WaitForLastOperation(FLASH_MEMTYPE_DATA);
  FLASH_Lock(FLASH_MEMTYPE_DATA); 
}


















