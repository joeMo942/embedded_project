#include "LED.h"
//init
void LED1_Init()
{
DIO_SetPinDir(DIO_PORTB, DIO_PIN4, DIO_PIN_OUTPUT);
}
void LED2_Init()
{
DIO_SetPinDir(DIO_PORTB, DIO_PIN5, DIO_PIN_OUTPUT);
}
void LED3_Init()
{
DIO_SetPinDir(DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT);
}
void LED4_Init()
{
DIO_SetPinDir(DIO_PORTB, DIO_PIN7, DIO_PIN_OUTPUT);
}
void LED5_Init()
{
DIO_SetPinDir(DIO_PORTD, DIO_PIN6, DIO_PIN_OUTPUT);
}

//turn on
void LED1_TurnOn()
{
DIO_SetPinVal(DIO_PORTB, DIO_PIN4, DIO_PIN_HIGH);
}
void LED2_TurnOn()
{
DIO_SetPinVal(DIO_PORTB, DIO_PIN5, DIO_PIN_HIGH);
}
void LED3_TurnOn()
{
DIO_SetPinVal(DIO_PORTB, DIO_PIN6, DIO_PIN_HIGH);
}
void LED4_TurnOn()
{
DIO_SetPinVal(DIO_PORTB, DIO_PIN7, DIO_PIN_HIGH);
}
void LED5_TurnOn()
{
DIO_SetPinVal(DIO_PORTD, DIO_PIN6, DIO_PIN_HIGH);
}


//turn off

void LED1_TurnOff()
{
	DIO_SetPinVal(DIO_PORTB, DIO_PIN4, DIO_PIN_LOW);
}
void LED2_TurnOff()
{
	DIO_SetPinVal(DIO_PORTB, DIO_PIN5, DIO_PIN_LOW);
}
void LED3_TurnOff()
{
	DIO_SetPinVal(DIO_PORTB, DIO_PIN6, DIO_PIN_LOW);
}
void LED4_TurnOff()
{
	DIO_SetPinVal(DIO_PORTB, DIO_PIN7, DIO_PIN_LOW);
}
void LED5_TurnOff()
{
	DIO_SetPinVal(DIO_PORTD, DIO_PIN6, DIO_PIN_LOW);
}






void LED0_Toggle()
{
	DIO_TogllePin(DIO_PORTB, DIO_PIN5);
}

void all_led_init(){
	LED1_Init();
	LED2_Init();
	LED3_Init();
	LED4_Init();
	LED5_Init();
}








