/*
 * adc.c
 *
 * Created: 14.09.2018 16:51:09
 *  Author: mariusft
 */ 

#include "adc.h"
#include <avr/io.h>
#include <stdio.h>

#include "Settings.h"
#include <util/delay.h>
void ADC_init(){
	DDRE &= ~(1<<PINE0); // setter pinE0 til input?
}



uint8_t ADC_read(adc_channel_t channel){
		volatile char *adc = (char*) 0x1400; //startadresse for adc external memory
		
		*adc = channel; // 4 + channel
		_delay_us(60);
		//while(test_bit(PINE, PINE0)); // vent pa data
		
		return *adc;
}
