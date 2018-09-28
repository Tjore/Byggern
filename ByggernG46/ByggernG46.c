/*
 * ByggernG46.c
 *
 * Created: 31.08.2018 15:56:58
 *  Author: mariusft
 */ 


#include <avr/io.h>
#include <stdio.h>
#include "Drivers/Settings.h"
#include "Drivers/uart.h"
#include "Drivers/SRAM.h"
#include "Drivers/adc.h"
#include "Drivers/USBMFC.h"
#include "Drivers/Oled.h"
#include "Drivers/FontBB.h"
#include "Drivers/menu.h"
#include "Drivers/intro.h"

//#define F_CPU 4.9152E6
#include <util/delay.h>

void setup(void){
	USART_Init(MYUBRR);		// init UART communication
	fdevopen((int(*)(char, struct __file*))&USART_Transmit, (int(*)(struct __file*))&USART_Receive);	//configure fprint to use UART
	MCUCR |= (1<<SRE);		// use external memory
	SFIOR |= (1<<XMM2); // Ikke bruk PC7-PC4 til external memory
	ADC_init();
	//SRAM_test();			// test write/read functionality
	oled_init();
}



int main(void){
	setup();
	
	intro(103,4);
	_delay_ms(200);
	start_menu();
}