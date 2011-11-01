#include <stdlib.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "USART.h"

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

void ChangeClockFreq() {
	OSC.XOSCCTRL = (uint8_t) OSC_FRQRANGE_12TO16_gc | 0b00001011;

	OSC.CTRL |= OSC_XOSCEN_bm;
	do {} while ( (OSC.STATUS & OSC_XOSCRDY_bm) == 0 ); // wait for clock to stabilize
	
	uint8_t clkCtrl = ( CLK.CTRL & ~CLK_SCLKSEL_gm ) | CLK_SCLKSEL_XOSC_gc;
	CCPWrite( &CLK.CTRL, clkCtrl );
}

int main(void) {
	char read;
	
	USART debugPort;
	USART radioPort;
	
	ChangeClockFreq();
	
	USART_InitPortStructs();
	
	USART_Open(&debugPort, 3, USART_BAUD_9600, 255, 255, false, false);
	USART_Open(&radioPort, 5, USART_BAUD_115200, 255, 255, false, false);
	
	while(1) {
		if (USART_RXUsed(&radioPort)) {
			read = USART_ReadByte(&radioPort);
			USART_WriteByte(&radioPort, read);
			USART_WriteByte(&debugPort, read);
		}
		/*
		if (USART_RXUsed(&debugPort)) {
			read = USART_ReadByte(&debugPort);
			USART_WriteByte(&radioPort, read);
		}*/
	}
}

