#include "xmega_test.h"

int main(void){
	init();
	while(1){
		led_on(1);
		_delay_ms(500);
		led_on(2);
		_delay_ms(500);
		led_on(3);
		_delay_ms(500);
		led_on(0);
		_delay_ms(500);
		led_off(0);
		led_off(1);
		led_off(2);
		led_off(3);
		_delay_ms(500);
	}
	return 0;
}

void init(void){
	PORTA.DIR=0x00;
	PORTB.DIR=0x00;
	PORTC.DIR=0x00;
	PORTD.DIR=0x00;
	PORTE.DIR=0b00000010;
	PORTF.DIR=0b11100000;
}

void led_on(u08 addr){
	switch(addr){
		case 0:{
			PORTE.OUT |= (1<<1);
			break;
		}
		case 1:{
			PORTF.OUT |= (1<<5);
			break;
		}
		case 2:{
			PORTF.OUT |= (1<<6);
			break;
		}
		case 3:{
			PORTF.OUT |= (1<<7);
			break;
		}
		case 255:{
			led_on(0);
			led_on(1);
			led_on(2);
			led_on(3);
			break;
		}
		default:{
			break;
		}
	}

}

void led_off(u08 addr){
	switch(addr){
		case 0:{
			PORTE.OUT &= ~(1<<1);
			break;
			}
		case 1:{
			PORTF.OUT &= ~(1<<5);
			break;
			}
		case 2:{
			PORTF.OUT &= ~(1<<6);
			break;
			}
		case 3:{
			PORTF.OUT &= ~(1<<7);
			break;
			}
		case 255:{
			led_off(0);
			led_off(1);
			led_off(2);
			led_off(3);
			break;
		}
		default:{
			break;
		}
	}
}
