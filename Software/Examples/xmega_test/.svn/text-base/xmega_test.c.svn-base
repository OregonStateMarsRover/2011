#include "xmega_test.h"

#undef USART_INTERRUPTS

int main(void){	
	unsigned char counter = 0;
	bool byteToBuffer;
	char readByte;
	init();
	init_transciever(0);
	
	#ifdef USART_INTERRUPTS
	while(1) {
		/* Software USART Loopback using interrupts: */
		/*if (USART_RXBufferData_Available(&USART_data)) {
			readByte = USART_RXBuffer_GetByte(&USART_data);
			USART_TXBuffer_PutByte(&USART_data, readByte);
		}*/
		
		USART_TXBuffer_PutByte(&USART_data, 'H');
		USART_TXBuffer_PutByte(&USART_data, '\n');
	}
	#else
	enable485(0, true);
	while(1) {
		/*do{
			// Wait until data received or a timeout.
			led_on(1);
		}while(!USART_IsRXComplete(getUSART(6)));
		led_off(1);
		readByte = USART_GetChar(getUSART(6));*/
		sendByte(6, 'H');
		sendByte(6, '\n');
	}
	#endif
	
	while(1){
		led_on(1);
		sendByte(6, counter++);
		_delay_ms(500);
		led_on(2);
		_delay_ms(500);
		led_on(3);
		sendByte(6,counter++);
		_delay_ms(500);
		led_on(0);
		sendByte(6,counter++);
		_delay_ms(500);
		sendByte(6,counter++);
		led_off(0);
		led_off(1);
		led_off(2);
		led_off(3);
		_delay_ms(500);
		/*_delay_ms(250);
		led_on(3);
		_delay_ms(250);
		led_off(3);*/
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
	init_uart(6);
	//init_uart(6);
}

void init_transciever(u08 addr) {
	if (addr==0) {
		PORTC.DIRSET = PIN1_bm;
	}
	else if (addr==1) {
		PORTC.DIRSET = PIN5_bm;
	}
	else if (addr==2) {
		PORTD.DIRSET = PIN1_bm;
	}
	else if (addr==3) {
		PORTD.DIRSET = PIN5_bm;
	}
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

void init_uart(char addr) {
	if (addr==0) {
		PORTC.DIRSET = PIN1_bm;
		PORTC.DIRSET = PIN3_bm;
		PORTC.DIRCLR = PIN2_bm;
		
		USART_data.usart = &USARTC0;
		USART_Format_Set(USART_data.usart, USART_CHSIZE_8BIT_gc,
			USART_PMODE_DISABLED_gc, false); // 8 bits, no parity, one stop bit
               	
		USART_Baudrate_Set(&USARTC0, 12 , 0); // 9600 baud at 2MHz
		
		USART_Rx_Enable(&USARTC0);
		USART_Tx_Enable(&USARTC0);
	}
	else if (addr==6) {
		PORTF.DIRSET = PIN4_bm;
		PORTF.DIRSET = PIN3_bm;
		PORTF.DIRCLR = PIN2_bm;
		
		PORTF.OUT = PIN4_bm;
		
		USART_data.usart = &USARTF0;
		#ifdef USART_INTERRUPTS
		USART_InterruptDriver_Initialize(&USART_data, &USARTF0, USART_DREINTLVL_LO_gc);
		#endif
		
		USART_Format_Set(USART_data.usart, USART_CHSIZE_8BIT_gc,
                     USART_PMODE_DISABLED_gc, false); // 8 bits, no parity, one stop bit
		
		#ifdef USART_INTERRUPTS
		USART_RxdInterruptLevel_Set(USART_data.usart, USART_RXCINTLVL_LO_gc);
		#endif
		
		USART_Baudrate_Set(&USARTF0, 12 , 0); // 9600 baud at 2MHz
		
		USART_Rx_Enable(&USARTF0);
		USART_Tx_Enable(&USARTF0);
		
		#ifdef USART_INTERRUPTS
		PMIC.CTRL |= PMIC_LOLVLEX_bm;
		sei();
		#endif
	}
}

USART_t * getUSART(u08 addr) {
	switch(addr) {
		case 0:
			return &USARTC0;
		case 1:
			return &USARTC1;
		case 2:
			return &USARTD0;
		case 3:
			return &USARTD1;
		case 6:
			return &USARTF0;
	}
}

void enable485(u08 addr, char enabled) {
	if (addr==0) {
		if (enabled)
			PORTC.OUTSET = PIN1_bm;
		else
			PORTC.OUTCLR = PIN1_bm;
	}
	else if (addr==1) {
		if (enabled)
			PORTC.OUTSET = PIN5_bm;
		else
			PORTC.OUTCLR = PIN5_bm;
	}
	else if (addr==2) {
		if (enabled)
			PORTD.OUTSET = PIN1_bm;
		else
			PORTD.OUTCLR = PIN1_bm;
	}
	else if (addr==3) {
		if (enabled)
			PORTD.OUTSET = PIN5_bm;
		else
			PORTD.OUTCLR = PIN5_bm;
	}
}

void sendByte(u08 addr,char byte) {
	USART_t * USART;
	
	if (addr==0) {
		USART=&USARTC0;
	}
	if (addr==6)
		USART=&USARTF0;
	
	led_off(0);
	do{
		// wait for USART to empty
		led_on(0);
	}while(!USART_IsTXDataRegisterEmpty(USART));
	led_off(0);
	
	USART_PutChar(USART, byte);
}

#ifdef USART_INTERRUPTS
ISR(USARTF0_RXC_vect)
{
	USART_RXComplete(&USART_data);
}

ISR(USARTF0_DRE_vect)
{
	USART_DataRegEmpty(&USART_data);
}
#endif

