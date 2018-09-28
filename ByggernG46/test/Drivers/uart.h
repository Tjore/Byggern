

#ifndef UART_H_
#define UART_H_


/* Variabler / innstillinger */

#define FOSC 1843200 // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1


/* funksjoner */

void USART_Init( unsigned int ubrr )