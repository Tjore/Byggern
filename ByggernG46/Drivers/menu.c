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
	//init
	oled_cls();
	oled_home();
	oled_write_string("# ");
	oled_write_string("Start Game");
	oled_pos(1,0);
	oled_write_string("  Hi-Scores");
	oled_pos(2,0);
	oled_write_string("  Placeholder");
	
	
	int8_t currentLine = 0;
	int8_t prevCurrentLine = 0;
	char *J_dir;
	
	printf("%d\r\n",currentLine);
	
	char *menuLines = {"Start Game","Hi-Scores","Placeholder"};
	while(1){
		J_dir = JoyStick_position();
		if(J_dir=="DOWN"){
			currentLine++;
			_delay_ms(300); //TODO Finne en bedre løsning
		} else if(J_dir == "UP"){
			currentLine--;
			_delay_ms(300); //TODO Finne en bedre løsning
		}
		
		if (currentLine>2){ //TODO Max og min
			currentLine=0;
		}
		else if (currentLine<0){ //TODO Max og min
			currentLine=2;
		}
		
		if (currentLine != prevCurrentLine){
			oled_clear_line(prevCurrentLine);
			oled_write_string("  ");
			oled_write_string(menuLines[prevCurrentLine]);
			oled_clear_line(currentLine);
			oled_write_string("# ");
			oled_write_string(menuLines[currentLine]);

			prevCurrentLine = currentLine;
			printf("%d\r\n",currentLine);
		}
// 		if (Right_button){
// 			// gå inn i undermeny
// 		}
		//gjør ingenting
	}
	
	
}


