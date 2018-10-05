/*
 * Settings.h
 *
 * Created: 31.08.2018 17:00:10
 *  Author: mariusft
 */ 


#ifndef SETTINGS_H_
#define SETTINGS_H_


/* Variabler / innstillinger */

#define F_OSC 4912500
#define F_CPU F_OSC	//klokkehastighet
#define BAUD 9600
#define MYUBRR (F_OSC)/16/BAUD-1

// makroer fra oppgbeskrivelsen
#define set_bit(reg,bit) (reg |= (1 << bit))
#define clear_bit(reg,bit) (reg &= ~(1 << bit))
#define test_bit( reg, bit ) (reg & (1 << bit))
#define loop_until_bit_is_set( reg, bit ) while( !test_bit( reg, bit ) )
#define loop_until_bit_is_clear( reg, bit ) while( test_bit( reg, bit ) )

// definerer minneallokasjon
#define external_oled_command ((volatile char*) 0x1000)
#define external_oled_data (volatile char*) 0x1200
#define external_oled_adc (volatile char*) 0x1400
#define external_oled_ram (volatile char*) 0x1800
#define external_ram_size 0x800


//definerer kommandoer til oled
#define OLED_PMODE_PAGE_ADDRESS 0xB0

#endif /* SETTINGS_H_ */