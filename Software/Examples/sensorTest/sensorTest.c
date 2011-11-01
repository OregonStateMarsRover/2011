//Included Libraries
#include <avr/io.h>
#include <util/delay.h>

#include "OSURCLib.h"

//Function Prototypes
void init(void);
unsigned short read_adc_10(char address);

int main(void){
	init();
	SetupMotors();
	unsigned short adcVal;
	while(1){
		adcVal=read_adc_10;	
		SetMotor(0,adcVal*5);
		_delay_ms(50);
	}
	return 0;
}

//Initialization Function
void init(void){
	//Initialize Data Direction Registers
	DDRA=0b10000000;
	DDRB=0b01111111;
	//Initialize
	ADCSRA|=(1<<ADEN);
	TCCR1A = 0x00;
	TCCR1A = (1<<PWM1A) | (1<<PWM1B) | (1<<COM1A0) | (1<<COM1B0);
	TCCR1B = 0x00;
	TCCR1B |= (1<<CS12);
	TCCR1D = 0x00; 
	TCNT1 = 0;
	OCR1A = 0;
	OCR1B = 0;

}

unsigned short read_adc_10(char address){
	//Verify Valid ADC Channel
	if(address>=0 && address<=6){
		ADMUX|=address;		//Multiplex correct analog input
		ADCSRA|=(1<<ADSC);	//Start A-to-D conversion
		while((ADCSRA & (1<<ADIF))==0){
			//Wait until conversion completes
		}
		ADCSRA |= (1<<ADIF);
		return (ADCL) | (ADCH<<8);			
	}
	return 0;
}
