#include "Servo.h"

void ServoMotor_Init()
{
	PWM1_INIT(); //20ms -- 50hz
}

void ServoMotor_Set_Degree(ServoDegree degree)
{

	switch(degree)
	{
	case 0:
		PWM_Set_OCR(97);
		break;
	case 1:
		PWM_Set_OCR(316);
		break;
	case 2:
		PWM_Set_OCR(535);
		break;

	}

}
