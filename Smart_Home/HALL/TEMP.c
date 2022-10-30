#include "TEMP.h"

void TEMP_Init()
{
	ADC_vinit();
}

uint16 TEMP_Read()
{

	uint16 Digital_Output;
	uint16 temp;
	Digital_Output = ADC_u16Read();
	temp = ((Digital_Output * 4.88)/20)+1;
	return temp;

}









