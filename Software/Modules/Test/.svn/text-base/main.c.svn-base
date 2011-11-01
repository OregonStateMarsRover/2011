#include <stdlib.h>
#define F_CPU 1000000
#include <avr/delay.h>
#include <avr/interrupt.h>

#include "USART.h"
#include "Common/CommInterface/CommInterface.h"

void led_off(char led) {
        if (led==0) {
                PORTD |= (1<<6);
        }
        else if (led==1) {
                PORTD |= (1<<7);
        }
}

void led_on(char led) {
        if (led==0) {
                PORTD &= ~(1<<6);
        }
        else if (led==1) {
                PORTD &= ~(1<<7);
        }
}


int main(void) {
	char data[2];
	unsigned char i=0;
	unsigned char overflow = 0;
	unsigned int count;
	USART port0;
	CommInterface inf;
	CommPacket sendPkt;
	CommPacket *rcvdPacket;
	
	USART_InitPortStructs();
	USART_Open(&port0, 0, USART_BAUD_4800, 20, 20, true);
	CommInterfaceInit(&inf, &port0);
	
	DDRB |= (1<<0) | (1<<1);
	DDRD |= (1<<6) | (1<<7);
	led_off(0);
	led_off(1);
	
	sendPkt.target = 0;
	sendPkt.length = 2;
	sendPkt.data = data;

	PORTB &= ~(1<<0);
	PORTB &= ~(1<<1);
	while(1) {
		if (overflow>128)
			PORTB |= 1<<0;
		else
			PORTB &= ~(1<<0);
		
		overflow++;
		//sendPkt.data[0]=i++;
		//CommSendPacket(&inf, &sendPkt);
		//cli();
		count = CommRXPacketsAvailable(&inf);
		if (count) {
			led_on(0);
			rcvdPacket = CommGetPacket(&inf);
			if (rcvdPacket->target==1 && rcvdPacket->data[0]=='X') {
				data[0] = i++;
				data[1] = rcvdPacket->data[1];
				if (CommSendPacket(&inf, &sendPkt)) {
					PORTB |= (1<<1);
				}
				else {
					PORTB &= ~(1<<1);
				}
			}
			CommDeletePacket(rcvdPacket);
			free(rcvdPacket);
			inf.rx_pkts_queued = 0;
		}
		else {
			led_off(0);
		}
		//sei();
	}
}

