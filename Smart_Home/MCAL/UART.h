#ifndef MCAL_UART_H_
#define MCAL_UART_H_
#include "../STD_TYPES.h"
#include "../MACROS.h"



//void UART_init(long USART_BAUDRATE);
void UART_Init();
unsigned char UART_RxChar();
void UART_TxChar(char ch);
void UART_SendString(char *str);

/*
void UART_Init();
void UART_SendByte(uint8 data);
uint8 UART_RecByte();
void UART_SendString(char *str);
*/
#endif /* MCAL_UART_H_ */
