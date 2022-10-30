#include "EEPROM.h"
#include <avr/io.h>

uint8 EEPROM_Read_Byte_From_Address(const uint16 Address)
{
	while (((EECR & (1 << EEWE))>>EEWE)==1);
	EEAR = Address;
	EECR |= (1 << EERE);
	return EEDR;
}

void EEPROM_Read_Block_From_Address(const uint16 Address, uint8* arr,const uint16 size)
{

	while (((EECR & (1 << EEWE))>>EEWE)==1);
	uint16 counter = 0;
	while (counter < size)
	{
		EEAR = Address + counter;
		EECR |= (1 << EERE);
		*(arr + counter) = EEDR;
		counter++;
	}
}

void EEPROM_Write_Byte_To_Address(const uint16 Address, const uint8 Data)
{

	while ( ( (EECR & (1 << EEWE) ) >>EEWE ) == 1);
	EEAR = Address;
	EECR |= (1 << EERE);
	if (EEDR != Data)
	{
		EEDR = Data;
		EECR |= (1 << EEMWE);
		EECR |= (1 << EEWE);
	}
	else
	{

	}

}

void EEPROM_Write_Block_To_Address(const uint16 Address, const uint8* arr,const uint16 size)
{
	uint16 counter = 0;
	while (counter < size)
	{
		while (( (EECR & (1 << EEWE) ) >>EEWE ) == 1);
		EEAR = Address + counter;
		EECR |= (1 << EERE);
		if (EEDR != (*(arr + counter)))
		{
			EEDR = *(arr + counter);
			EECR |= (1 << EEMWE);
			EECR |= (1 << EEWE);
		}
		else
		{

		}
		counter++;//increase bytes counter
	}
}

void EraseEEPROM()
{
 uint8_t sreg, i;
 uint16_t addr;
 uint8_t clear[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
 uint8_t data[8];




 // Write page by page using the block writing method
 for(addr = 0; addr < 86; addr += 8)
 {
   EEPROM_Read_Block_From_Address((void *)&data[0],(const void *)addr,8);
   for(i = 0; i < 8; i++)
     if(data[i] != 0xFF)
     {
       EEPROM_Write_Block_To_Address((void*)&clear[0], (void*)addr, 8);
       break;
     }
 }

;
}

