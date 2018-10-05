/*
 * SPI_driver.c
 *
 * Created: 05.10.2018 09:16:05
 *  Author: mariusft
 */ 


#include <avr/io.h>
#include "SPI_driver.h"
#include "Settings.h"


void SPI_init(void){
	// aktiver utgangene for MOSI, SS og SCK (settes til output), 
	DDRB |= (1<<PB4)|(1<<PB5)|(1<<PB7);
	
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
	
	// sett slave-pin høy (inaktiv)
	set_bit(PORTB,PB4);
	};


void SPI_write(char data){
	/* Start transmission */
	SPDR = data;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)));
	};

	
char SPI_read(void){
	SPDR = 0x00;

	loop_until_bit_is_set(SPSR,SPIF);
	
	return SPDR;
	};
