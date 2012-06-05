#include <stdlib.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "GPS.h"
#include "USART.h"
#include "Common/CommInterface/CommInterface.h"
#include "LEDController.h"


#define AVR_ENTER_CRITICAL_REGION( ) uint8_t volatile saved_sreg = SREG; \
                                     cli();

#define AVR_LEAVE_CRITICAL_REGION( ) SREG = saved_sreg;

void CCPWrite( volatile uint8_t * address, uint8_t value )
{
#if defined __GNUC__
	AVR_ENTER_CRITICAL_REGION( );
	volatile uint8_t * tmpAddr = address;
#ifdef RAMPZ
	RAMPZ = 0;
#endif
	asm volatile(
		"movw r30,  %0"	      "\n\t"
		"ldi  r16,  %2"	      "\n\t"
		"out   %3, r16"	      "\n\t"
		"st     Z,  %1"       "\n\t"
		:
		: "r" (tmpAddr), "r" (value), "M" (CCP_IOREG_gc), "i" (&CCP)
		: "r16", "r30", "r31"
		);

	AVR_LEAVE_CRITICAL_REGION( );
#endif
}

ISR(OSC_XOSCF_vect)
{
	cli();
	while(1)
	{
/*		LedOff(LED_STATUS);
		_delay_ms(500);
		LedOn(LED_STATUS);
		_delay_ms(500);

		LedOff(LED_DNT);
		_delay_ms(100);	
		LedOff(LED_LBOG);
		_delay_ms(100);
		LedOff(LED_BBOG);
		_delay_ms(100);
		LedOff(LED_RBOG);
		_delay_ms(100);
		
		LedOn(LED_DNT);
		_delay_ms(100);
		
		LedOn(LED_LBOG);
		_delay_ms(100);
		LedOn(LED_BBOG);
		_delay_ms(100);
		LedOn(LED_RBOG);
		_delay_ms(100);*/
	}
}

ISR(BADISR_vect) {
	cli();
	while(1) {
/*		LedOff(LED_DNT);
		
		LedOff(LED_STATUS);
		_delay_ms(500);
		LedOn(LED_STATUS);
		_delay_ms(500);
		
		LedOff(LED_LBOG);
		_delay_ms(100);
		LedOff(LED_BBOG);
		_delay_ms(100);
		LedOff(LED_RBOG);
		_delay_ms(100);
		
		LedOn(LED_LBOG);
		_delay_ms(100);
		LedOn(LED_BBOG);
		_delay_ms(100);
		LedOn(LED_RBOG);
		_delay_ms(100);*/
	}
}

void ChangeClockFreq() {
	uint8_t clkCtrl;
	LedOff(LED_STATUS);
	CCPWrite( &OSC.XOSCFAIL, ( OSC_XOSCFDIF_bm | OSC_XOSCFDEN_bm ) );
	char failed = 0;
	
	do
	{
		failed = 0;
		
		OSC.XOSCCTRL = (uint8_t) OSC_FRQRANGE_12TO16_gc | 0b00001011;
		OSC.CTRL |= OSC_XOSCEN_bm;
		while ( (OSC.STATUS & OSC_XOSCRDY_bm) == 0 && failed==0) // wait for clock to stabilize
		{
			if (OSC.XOSCFAIL & OSC_XOSCFDIF_bm)
			{
				OSC.XOSCFAIL |= OSC_XOSCFDIF_bm;
				failed = 1;
			}
		}
	}
	while (failed);
	
	clkCtrl = ( CLK.CTRL & ~CLK_SCLKSEL_gm ) | CLK_SCLKSEL_XOSC_gc;
	CCPWrite( &CLK.CTRL, clkCtrl );
	
	LedOn(LED_STATUS);
}

int main(void) {
	
	char data[20];
	unsigned int count;
	char ret;
	USART gps_in;
	USART gps_out;
	USART mainU;
	
	ChangeClockFreq();

	LedInit();
	LedAllOff(0);
	/*while(1) {
		LedAllToggle();
		_delay_ms(1000);
	}*/

	USART_InitPortStructs();
	
	CommInterface inf;
	
	CommPacket rcvdPacket;
	char recvBuf[20];
	rcvdPacket.data=recvBuf;
	
	CommPacket Pkt;
	
	USART_Open(&mainU, 0, USART_BAUD_38400, 10, 10, true, true);
	LedInit();
	LedAllOff(0);
	CommInterfaceInit(&inf, &mainU);
	LedOff(LED_SOC);
	char buffer;
	
	while(1) {
		//LedAllToggle();
		//LedAllOff(0);

		//memcpy(&gpsPkt.data,&rmc, sizeof(rmc));
		//CommSendPacket(&inf, &gpsPkt);
		//_delay_ms(500);
		//continue;
		/*
		if (USART_RXUsed(&gps_in)) {
			buffer = USART_ReadByte(&gps_in);
			GPSinput(buffer);
		}
		count = CommRXPacketsAvailable(&inf);
		LedOn(LED_SOC);
		*/
		//if (count) {
			//ret = CommGetPacket(&inf, &rcvdPacket, 20);
			
			Pkt.target = 2;
			Pkt.length = 1;
			Pkt.data = data;
			Pkt.data[0]='A';
			CommSendPacket(&inf, &Pkt);
			
		//}
	}
}

