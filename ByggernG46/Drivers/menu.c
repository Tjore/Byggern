/*
 * menu.c
 *
 * Created: 28.09.2018 12:26:34
 *  Author: haakofjo
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "menu.h"
#include "Oled.h"
#include "USBMFC.h"
#include <util/delay.h>


void start_menu(){

	char menuLines[4][16] = {"Start Game","Hi-Scores","Placeholder","  "};
	int8_t menuLinesLength = sizeof(menuLines)/sizeof(menuLines[1]) - 1;
	
	oled_cls();
	drawDoggo(0,4);
	oled_home();
	
	oled_write_string("# ");
	oled_write_string(menuLines[0]);
	for(int i=1; i<=menuLinesLength; i++ ){
		oled_pos(i,0);
		oled_write_string("  ");
		oled_write_string(menuLines[i]);
	}
	
	int8_t currentLine = 0;
	int8_t prevCurrentLine = 0;
	char *J_dir;
	
	while(1){
		J_dir = JoyStick_position();
		if(J_dir=="DOWN"){
			currentLine++;
			//_delay_ms(300); //TODO Finne en bedre løsning
		} else if(J_dir == "UP"){
			currentLine--;
			//_delay_ms(300); //TODO Finne en bedre løsning
		}
		
		if (currentLine>menuLinesLength){ 
			currentLine=0;
		}
		else if (currentLine<0){ 
			currentLine=menuLinesLength;
		}
		
		if (currentLine != prevCurrentLine){
			oled_clear_line(prevCurrentLine);
			oled_write_string("  ");
			oled_write_string(menuLines[prevCurrentLine]);
			oled_clear_line(currentLine);
			oled_write_string("# ");
			oled_write_string(menuLines[currentLine]);

			prevCurrentLine = currentLine;
			_delay_ms(300);
		}
	}
	
	
}


