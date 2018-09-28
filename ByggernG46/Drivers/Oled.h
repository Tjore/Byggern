/*
 * Oled.h
 *
 * Created: 21.09.2018 15:06:25
 *  Author: mariusft
 */ 


#ifndef OLED_H_
#define OLED_H_

#include <avr/pgmspace.h>
#include <stdio.h>
#include "Settings.h"

void oled_init(void);


static inline void oled_write_command(char c){
	*external_oled_command = c;
}
static inline void oled_write_data(char d){
	*external_oled_data = d;
}

// Def oled commands
void oled_goto_col(uint8_t col);
void oled_goto_line(uint8_t line);
void oled_home(void);
void oled_pos(int line, int col);
void oled_clear_line(uint8_t line);
void oled_cls(void);

void oled_write_char(char tegn);
void oled_write_string(const char *streng);

#endif /* OLED_H_ */