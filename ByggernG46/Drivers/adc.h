/*
 * adc.h
 *
 * Created: 14.09.2018 16:51:24
 *  Author: mariusft
 */ 

#include <avr/io.h>
#include <stdio.h>

#ifndef ADC_H_
#define ADC_H_


void ADC_init(void);
uint8_t ADC_read(uint8_t channel);

typedef enum {
	CHANNEL_1 = 0b00000100,
	CHANNEL_2,
	CHANNEL_3,
	CHANNEL_4
} adc_channel_t;

#endif /* ADC_H_ */