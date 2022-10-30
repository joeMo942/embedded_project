#include "KEYPAD.h"

#include <util/delay.h>


const uint8 KeyPad_Values[4][4] = {{'7' , '8' , '9' , '/'} ,
	                               {'4' , '5' , '6' , '*'} ,
								   {'3' , '2' , '1' , '-'} ,
								   {'c' , '0' , '=' , '+'}  };



void KeyPad_Init(void)
{

DIO_SetPinDir(KEYPAD_PORT, KEYPAD_COLUM_0, DIO_PIN_OUTPUT);
DIO_SetPinDir(KEYPAD_PORT, KEYPAD_COLUM_1, DIO_PIN_OUTPUT);
DIO_SetPinDir(KEYPAD_PORT, KEYPAD_COLUM_2, DIO_PIN_OUTPUT);
DIO_SetPinDir(KEYPAD_PORT, KEYPAD_COLUM_3, DIO_PIN_OUTPUT);

/*DIO_SetPinVal(KEYPAD_PORT, KEYPAD_COLUM_0, DIO_PIN_HIGH);
DIO_SetPinVal(KEYPAD_PORT, KEYPAD_COLUM_1, DIO_PIN_HIGH);
DIO_SetPinVal(KEYPAD_PORT, KEYPAD_COLUM_2, DIO_PIN_HIGH);
DIO_SetPinVal(KEYPAD_PORT, KEYPAD_COLUM_3, DIO_PIN_HIGH);*/

DIO_SetPinDir(KEYPAD_PORT, KEYPAD_ROW_0, DIO_PIN_INPUT);
DIO_SetPinDir(KEYPAD_PORT, KEYPAD_ROW_1, DIO_PIN_INPUT);
DIO_SetPinDir(KEYPAD_PORT, KEYPAD_ROW_2, DIO_PIN_INPUT);
DIO_SetPinDir(KEYPAD_PORT, KEYPAD_ROW_3, DIO_PIN_INPUT);


DIO_SetPullUpRes(KEYPAD_PORT, KEYPAD_ROW_0);
DIO_SetPullUpRes(KEYPAD_PORT, KEYPAD_ROW_1);
DIO_SetPullUpRes(KEYPAD_PORT, KEYPAD_ROW_2);
DIO_SetPullUpRes(KEYPAD_PORT, KEYPAD_ROW_3);


}

uint8 KeyPad_GetChar(void)
{
	const uint8 KeyPad_Values[4][4] = {{'7' , '8' , '9' , '/'} ,
                                       {'4' , '5' , '6' , '*'} ,
		                               {'1' , '2' , '3' , '-'} ,
		                                {'c' , '0' , '=' , '+'}  };

	uint8 row ,colume ,x;
	uint8 returnval='m';
	for(row=0;row<4;row++)
	{
		DIO_SetPinVal(KEYPAD_PORT, KEYPAD_COLUM_0, DIO_PIN_HIGH);
		DIO_SetPinVal(KEYPAD_PORT, KEYPAD_COLUM_1, DIO_PIN_HIGH);
		DIO_SetPinVal(KEYPAD_PORT, KEYPAD_COLUM_2, DIO_PIN_HIGH);
		DIO_SetPinVal(KEYPAD_PORT, KEYPAD_COLUM_3, DIO_PIN_HIGH);
		DIO_SetPinVal(KEYPAD_PORT, row, DIO_PIN_LOW);
		for(colume=0;colume<4;colume++)
		{
			x=DIO_GetPinVal(KEYPAD_PORT,(colume+4));
			if(x==0)
			{
				returnval=KeyPad_Values[row][colume];
				break;
			}
		}
			if(x==0)
			{
				break;
			}
		}
	return returnval;
	}



