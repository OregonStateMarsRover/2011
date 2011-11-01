#include "mega48_test.h"

int main(void) {
	DDRD = (1<<DDD6) | (1<<DDD7);
	
	while(1) {
		PORTD = (1<<PORTD6);
		_delay_ms(500);
		PORTD = (1<<PORTD7);
		_delay_ms(500);
	}
}
