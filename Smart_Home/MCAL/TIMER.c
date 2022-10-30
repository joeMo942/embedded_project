#include "TIMER.h"
uint32 Number_OVF =0 ;
uint32 INIAL_VALUE = 0;

volatile uint32 Num_OVF1 = 0;
volatile uint32 ICR_CAPT1 = 0;
volatile uint32 ICR_CAPT2 = 0;
volatile uint32 ICR_CAPT3 = 0;
volatile uint32 ICR_COUNTER = 0;

void TIMER0_Init()
{
	TCNT0 = 0x00;
	TCCR0 = 0x00;
	SET_BIT(TIMSK,0);

}
void TIMER0_Start()
{
	TCCR0 |= 0x05;

}
void TIMER0_Stop()
{
	TCCR0 = 0x00;
}

void TIMER0_Delay_ms(uint8 delay)
{
	uint32 Tick_Time = (1024 / 8) ;

	uint32 Total_Ticks = (delay * 1000) / Tick_Time ;

	Number_OVF = Total_Ticks / 256 ;

	INIAL_VALUE  =   256 - (Total_Ticks % 256) ;

	TCNT0 = INIAL_VALUE ;

	Number_OVF++;


}


void TIMER0_CTC_Init()
{
	TCNT0 = 0;
	TCCR0 |= 0x08;
	SET_BIT(TIMSK,1);

}
void TIMER0_CTC_delay_ms(uint32 delay)
{
	uint16 tick_time = 64/8; //64

	uint32 num_ticks = (delay*1000) / tick_time;

	 OCR0=100;

	 Number_OVF = num_ticks/OCR0;



}
void TIMER0_CTC_Start()
{
	TCCR0 |= 0x03;
}
void TIMER0_CTC_Stop()
{
	TCCR0 |= 0x00;
}



void PWM0_INIT()
{
	SET_BIT(DDRB,3); //output
	TCCR0 |= 0x68;
}

void PWM0_Generate(uint16 Duty_Cycle)
{
	OCR0 = ((Duty_Cycle * 256)/100)-1;
}
void PWM0_Start()
{
	TCCR0 |=0x05;
}


void PWM1_INIT()
{
	SET_BIT(DDRD,5);
	TCCR1B |=0x1B;
	TCCR1A |=0x82;
	ICR1 = 4999;
}

void PWM1_Generate(uint16 Duty_Cycle)
{
	OCR1A = ((Duty_Cycle * 4999)/100)-1;
}
void PWM_Set_OCR(uint16 degree)
{

	OCR1A = degree;
}



void PWM2_init()
{

	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);
	DDRB|=(1<<PB3);
}
void PWM2_Set_OCR(uint16 degree)
{

	OCR0= degree;
}



void ICU_Init()
{
	ICR1=0x0000;
	CLR_BIT(DDRD,6);
	TCCR1B |= 0x41;
	TCCR1A = 0x00;
   SET_BIT(TIMSK,2);
   SET_BIT(TIMSK,5);

}


ISR(TIMER1_OVF_vect)
{
	Num_OVF1++;

}

ISR(TIMER1_CAPT_vect)
{

	ICR_COUNTER++;
	if(ICR_COUNTER==1)
	{
		Num_OVF1=0;
		ICR_CAPT1 = ICR1;
		CLR_BIT(TCCR1B,6);
	}
	else if(ICR_COUNTER==2)
	{
		ICR_CAPT2 = ICR1 +(Num_OVF1*65535);//65535
		SET_BIT(TCCR1B,6);
	}
	else if(ICR_COUNTER==3)
	{
		ICR_CAPT3 = ICR1 +(Num_OVF1*65535);
		CLR_BIT(TIMSK,5);
	}


}







