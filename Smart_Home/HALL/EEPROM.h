#ifndef HEADERS_EEPROM_H_
#define HEADERS_EEPROM_H_

#include "../STD_TYPES.h"

uint8 EEPROM_Read_Byte_From_Address(const uint16 Address);
void EEPROM_Read_Block_From_Address(const uint16 Address, uint8* arr,const uint16 size);
void EEPROM_Write_Byte_To_Address(const uint16 Address, const uint8 Data);
void EEPROM_Write_Block_To_Address(const uint16 Address, const uint8* arr,const uint16 size);
void EraseEEPROM();

#endif
