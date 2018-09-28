/*
 * uart.h
 *
 * Created: 31.08.2018 16:38:06
 *  Author: mariusft
 */ 


#ifndef UART_H_
#define UART_H_

/* funksjoner */

void USART_Init( unsigned int ubrr );
void USART_Transmit( unsigned char data );


unsigned char USART_Receive( void );


#endif /* UART_H_ */