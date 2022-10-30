#ifndef HALL_LED_H_
#define HALL_LED_H_

#include "../MCAL/DIO.h"
//init
void LED1_Init();
void LED2_Init();
void LED3_Init();
void LED4_Init();
void LED5_Init();
void all_led_init();
//turn on
void LED1_TurnOn();
void LED2_TurnOn();
void LED3_TurnOn();
void LED4_TurnOn();
void LED5_TurnOn();
//turn off
void LED1_TurnOff();
void LED2_TurnOff();
void LED3_TurnOff();
void LED4_TurnOff();
void LED5_TurnOff();

void LED1_Toggle();

#endif /* HALL_LED_H_ */
