/*
 * USBMFC.c
 *
 * Created: 21.09.2018 08:20:25
 *  Author: mariusft
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "Settings.h"
#include "USBMFC.h"
#include "adc.h"

uint8_t JoyStick_bit_x(void){
	uint8_t x = ADC_read(CHANNEL_4);
	return x;
};

uint8_t JoyStick_bit_y(void){
	uint8_t y = ADC_read(CHANNEL_3);
	return y;
};

uint8_t Slider_bit_R(void){
	uint8_t r = ADC_read(CHANNEL_2);
	return r;
};

uint8_t Slider_bit_L(void){
	uint8_t l = ADC_read(CHANNEL_1);
	return l;
};

struct JoyStick_bit USBMFC_JoyStick_bit(){
	uint8_t x = JoyStick_bit_x();
	uint8_t y = JoyStick_bit_y();
	struct JoyStick_bit pos = {x,y};
	return pos;
};


int8_t JoyStick_percent_x(void){
	int16_t x = JoyStick_bit_x();
	x = 200*(x)/255;
	return (x-100);
	};
	
int8_t JoyStick_percent_y(void){
	int16_t y = JoyStick_bit_y();
	y = 200*y/255;
	return (y-100);
	};

struct JoyStick_percent USBMFC_Joystick_percent(void){
	int8_t x = JoyStick_percent_x();
	int8_t y = JoyStick_percent_y();
	struct JoyStick_percent pos = {x,y};
	return pos;
};

char *JoyStick_position(void){
	uint8_t limit = 30;
	uint8_t limitup = 127+limit;
	uint8_t limitdown = 127-limit;

	struct JoyStick_bit JoyStickBits = USBMFC_JoyStick_bit();

	if ((JoyStickBits.x > limitup) && (JoyStickBits.y > limitup)){
		if (JoyStickBits.x > JoyStickBits.y){
			return "RIGHT";
		}
		else {
			return "UP";
		};
	} 
	else if ((JoyStickBits.x < limitdown) && (JoyStickBits.y < limitdown)){
		if (JoyStickBits.x < JoyStickBits.y){
			return "LEFT";
		}
		else {
			return "DOWN";
		};
	}
	else if (JoyStickBits.x > limitup){
		return "RIGHT";
	} 
	else if (JoyStickBits.y > limitup){
		return "UP";
	} 
	else if (JoyStickBits.x < limitdown){
		return "LEFT";
	}
	else if (JoyStickBits.y < limitdown){
		return "DOWN";
	}
	else {
		return "NEUTRAL";
	};
};




// %%Info til senere%%   
//printf("Slider L: %d, ",ADC_read(CHANNEL_1));
//printf("Slider R: %d, ",ADC_read(CHANNEL_2));
//printf("Joystick y: %d, ",ADC_read(CHANNEL_3));
//printf("Joystick x: %d\r\n",ADC_read(CHANNEL_4));