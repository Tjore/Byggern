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

//#define F_CPU 4.9152E6
#include <util/delay.h>

void setup(void){
	USART_Init(MYUBRR);		// init UART communication
	fdevopen((int(*)(char, struct __file*))&USART_Transmit, (int(*)(struct __file*))&USART_Receive);	//configure fprint to use UART
	MCUCR |= (1<<SRE);		// use external memory
	SFIOR |= (1<<XMM2); // Ikke bruk PC7-PC4 til external memory
	ADC_init();
	SRAM_test();			// test write/read functionality
	oled_init();
	
}



int main(void){
	setup();
	//uint8_t x,y,L,R;
	char *joyPos;
	
	//oled_reset();
	//oled_write_command(0xD3);
	start_menu();

	while(1){

// 				for (int j=0; j<8; j++){
// 					oled_change_page(j);
// 				for (int i=0; i<127; i++){
// 					//oled_write_data(3);
// 					oled_write_data(0b00111111);
// 					oled_write_data(0b00111000);
// 					oled_write_data(0b00111000);
// 					oled_write_data(0b11111000);
// 					oled_write_data(0b00111111);
// 					oled_write_data(0b00111111);
// 					oled_write_data(0b00111111);
// 					oled_write_data(0b00000000);
// 				
// 				}
// 				}

		joyPos = JoyStick_position();
		printf(joyPos);

// 		oled_write_data(0b00001100);
// 		oled_write_data(0b00111110);
// 		oled_write_data(0b01111110);
// 		oled_write_data(0b11111100);
// 		oled_write_data(0b01111110);
// 		oled_write_data(0b00111110);
// 		oled_write_data(0b00001100);
// 		oled_write_data(0b00000000);

// 		oled_write_data(0b00001100);
// 		oled_write_data(0b00111110);
// 		oled_write_data(0b01101110);
// 		oled_write_data(0b11010100);
// 		oled_write_data(0b00111000);
// 		oled_write_data(0b00111110);
// 		oled_write_data(0b00001100);
// 		oled_write_data(0b00000000);


		oled_clear_line(0);
		oled_write_string(joyPos);
		oled_write_data(0b00001100);
		oled_write_data(0b00111110);
		oled_write_data(0b01111110);
		oled_write_data(0b11111100);
		oled_write_data(0b01111110);
		oled_write_data(0b00111110);
		oled_write_data(0b00001100);
		oled_write_data(0b00000000);
		oled_write_data(0b00001100);
		oled_write_data(0b00111110);
		oled_write_data(0b01101110);
		oled_write_data(0b11010100);
		oled_write_data(0b00111000);
		oled_write_data(0b00111110);
		oled_write_data(0b00001100);
		oled_write_data(0b00000000);
		_delay_ms(100);
		oled_goto_col(0);

}
}