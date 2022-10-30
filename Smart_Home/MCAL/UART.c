#include "UART.h"
#include <avr/io.h>


void UART_Init()
{

	UCSRB |= (1 << RXEN) | (1 << TXEN);/* Turn on transmission and reception */
		UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);/* Use 8-bit character sizes */
		UBRRL = (((F_CPU / (9600 * 16UL))) - 1);		/* Load lower 8-bits of the baud rate value */
		UBRRH = ((((F_CPU / (9600 * 16UL))) - 1) >> 8);	/* Load upper 8-bits*/


	CLR_BIT(DDRD,0);
	SET_BIT(DDRD,1);

	UCSRB = 0x18;
	UCSRC = 0x86;

	UBRRL = (80000/(16*96))-1;

}

unsigned char UART_RxChar()
{
	while ((UCSRA & (1 << RXC)) == 0)
		{return 'm';};/* Wait till data is received */
	return(UDR);			/* Return the byte*/
}

void UART_TxChar(char ch)
{
	while (! (UCSRA & (1<<UDRE)));	/* Wait for empty transmit buffer*/
	UDR = ch ;
}

void UART_SendString(char *str)
{
	unsigned char j=0;

	while (str[j]!=0)		/* Send string till null */
	{
		UART_TxChar(str[j]);
		j++;
	}
}

/*
void UART_Init()
{
	CLR_BIT(DDRD,0);
	SET_BIT(DDRD,1);

	UCSRB = 0x18;
	UCSRC = 0x86;

	UBRRL = (160000/(16*96))-1;

}
void UART_SendByte(uint8 data)
{
	UDR = data;


	while (Read_bIT(UCSRA,5)==0);

}
uint8 UART_RecByte()
{
	uint8 RecData;

	while (Read_bIT(UCSRA,7)==0);

	RecData = UDR;

	return RecData;

}

void UART_SendString(char *str)
{
	unsigned char j=0;

	while (str[j]!=0)
	{
		UART_SendByte(str[j]);
		j++;
	}
}

 */








