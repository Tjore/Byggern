/*
 * Oled.c
 *
 * Created: 21.09.2018 15:37:08
 *  Author: mariusft
 */ 


#include <avr/pgmspace.h>
#include <stdio.h>
#include "Settings.h"
#include "Oled.h"
#include <util/delay.h>
#include "FontBB.h"
#include <string.h>



void oled_init(void)
{
	oled_write_command(0xae);        //  display  off
	oled_write_command(0xa1);        //segment  remap
	oled_write_command(0xda);        //common  pads  hardware:  alternative
	oled_write_command(0x12);
	oled_write_command(0xc8);        //common output scan direction:com63~com0
	oled_write_command(0xa8);        //multiplex  ration  mode:63
	oled_write_command(0x3f);
	oled_write_command(0xd5);        //display divide ratio/osc. freq. mode
	oled_write_command(0x80);
	oled_write_command(0x81);        //contrast  control
	oled_write_command(0x50);
	oled_write_command(0xd9);        //set  pre-charge  period
	oled_write_command(0x21);		 //Set column address
	oled_write_command(0x20);        //Set  Memory  Addressing  Mode
	oled_write_command(0x02);
	oled_write_command(0xdb);        //VCOM  deselect  level  mode
	oled_write_command(0x30);
	oled_write_command(0xad);        //master  configuration (Oled select iref)
	oled_write_command(0x00);		 //Horizontal addressing mode
	oled_write_command(0xa4);        //out  follows  RAM  content
	oled_write_command(0xa6);        //set  normal  display
	oled_write_command(0xaf);        //  display  on
	
	oled_cls();
	oled_home();
}



void oled_goto_line(uint8_t line){
	oled_write_command(0xB0 + line);
}

void oled_goto_col(uint8_t col){
	oled_write_command(0x0F & (col));
	oled_write_command(0x10 | (col>>4));
}

void oled_home(void){
	oled_goto_line(0);
	oled_goto_col(0);
}

void oled_pos(int line, int col){
	oled_goto_line(line);
	oled_goto_col(col);
}

void oled_clear_line(uint8_t line){
	oled_goto_line(line);
	for (int i = 0; i<128; i++){
		oled_write_data(0);
	}
	oled_goto_col(0);
}

void oled_cls(void){
	for (int row = 0; row<8; row++){
		oled_clear_line(row);
	}
	oled_home();
}

void oled_write_char(char tegn){
	int a = (int)tegn;
	for (int i=0; i<8; i++){
		oled_write_data(pgm_read_byte(&font8[a-32][i]));
	}
}

void oled_write_string(const char *streng){
	for (int i=0; i<strlen(streng); i++){
		oled_write_char(streng[i]);
	}
}
