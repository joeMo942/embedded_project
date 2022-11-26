#include "HALL/KEYPAD.h"
#include "HALL/LCD.h"
#include "util/delay.h"
#include "HALL/BUZZER.h"
#include "HALL/LED.h"
#include "MCAL/DIO.h"
#include "HALL/SERVO.h"
#include "HALL/TEMP.h"
#include "MCAL/ADC.h"
#include "app/login.h"
#include "app/menu.h"
#include "MCAL/TIMER.h"
#include "MCAL/EXT_INTERRUPT.h"
#include "MCAL/UART.h"


/*
#define user_limit 4
#define pass_limit 4
*/
uint16 x;




int main()
{

    BUZZER_init();
	LCD_Init();
	KeyPad_Init();
	TEMP_Init();
	all_led_init();
	ServoMotor_Init();
	UART_Init();




uint8 counter_of_wrong_login=0;
uint8 x=login();
while(x==0)
{
counter_of_wrong_login++;
if(counter_of_wrong_login==3)
{
	BUZZER_START();
	_delay_ms(500);
	BUZZER_STOP();
}
x=login();
}
		if(x==1)
		{
			ServoMotor_Set_Degree(2);
			_delay_ms(500);
			ServoMotor_Set_Degree(0);
			admin_menu();
		}
		else if(x==2)
		{
			ServoMotor_Set_Degree(2);
			_delay_ms(500);
			ServoMotor_Set_Degree(0);
			user_menu();
		}


   return 0;
	}




