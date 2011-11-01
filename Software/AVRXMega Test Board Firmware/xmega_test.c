#include "xmega_test.h"

int main(void){
	init();
	return 0;
}

void init(void){
	DDRA=0x00;
	DDRB=0x00;
	DDRC=0x00;
	DDRD=0x00;
	DDRE=0b00000010;
	DDRF=0b11100000;
	
	
}

void led_on(u08 addr){
	switch(addr){
		case 0: PORTE |= (1<<1);
		case 1: PORTF |= (1<<5);
		case 2: PORTF |= (1<<6);
		case 3: PORTF |= (1<<7);
		case 255:{
			led_on(0);
			led_on(1);
			led_on(2);
			led_on(3);
		}
		default:
	}

}

void led_off(u08 addr){
	switch(addr){
		case 0: PORTE &= ~(1<<1);
		case 1: PORTF &= ~(1<<5);
		case 2: PORTF &= ~(1<<6);
		case 3: PORTF &= ~(1<<7);
		case 255:{
			led_off(0);
			led_off(1);
			led_off(2);
			led_off(3);
		}
		default:
	}
}