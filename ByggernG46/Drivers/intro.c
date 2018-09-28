/*
 * intro.c
 *
 * Created: 28.09.2018 15:06:45
 *  Author: haakofjo
 */ 


#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "FontBB.h"
#include "Oled.h"


void drawDoggo(uint8_t x, uint8_t y){
	for (int i = 0; i<3; i++){
		oled_goto_line(i+y);
		oled_goto_col(x);
		for (int j = 0; j<24; j++){
			oled_write_data(pgm_read_byte(&doggo[i][j]));
		}
	}
}

void drawDoggo2(uint8_t x, uint8_t y){
	for (int i = 0; i<3; i++){
		oled_goto_line(i+y);
		oled_goto_col(x);
		for (int j = 0; j<24; j++){
			oled_write_data(pgm_read_byte(&doggo2[i][j]));
		}
	}
}

void drawDoggoBone(uint8_t x, uint8_t y){
	oled_pos(y,x);
	for(int i=0; i<8; i++){
		oled_write_data(pgm_read_byte(&doggoBone[i]));	
	}
}




void intro(uint8_t x, uint8_t y){
/*uint8_t x = 128;*/
	for (int i=0; i<104; i++){
		drawDoggoBone(0,4);
		if (i%4 >=2 ){
			drawDoggo(x-i,y);
		} else {
			drawDoggo2(x-i,y);
		}
		_delay_ms(200);
	}

};
