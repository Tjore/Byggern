/*
 * USBMFC.h
 *
 * Created: 21.09.2018 08:20:43
 *  Author: mariusft
 */ 



#ifndef USBMFC_H_
#define USBMFC_H_

uint8_t JoyStick_bit_x(void);
uint8_t JoyStick_bit_y(void);
uint8_t Slider_bit_R(void);
uint8_t Slider_bit_L(void);

struct JoyStick_bit{
	uint8_t x,y;
};

int8_t JoyStick_percent_x(void);
int8_t JoyStick_percent_y(void);

struct JoyStick_percent{
	int8_t x,y;
};
struct JoyStick_percent USBMFC_Joystick_percent(void);

char* JoyStick_position(void);

#endif /* USBMFC_H_ */