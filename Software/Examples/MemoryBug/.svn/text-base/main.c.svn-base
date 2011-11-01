#include <stdlib.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "USART.h"
#include "Timer.h"

#include "Common/CommInterface/CommInterface.h"

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

#define USART_Format_Set(_usart, _charSize, _parityMode, _twoStopBits)         \
	(_usart)->CTRLC = (uint8_t) _charSize | _parityMode |                      \
	                  (_twoStopBits ? USART_SBMODE_bm : 0)

#define USART_Tx_Enable(_usart)	((_usart)->CTRLB |= USART_TXEN_bm)

void ChangeClockFreq() {
	OSC.XOSCCTRL = (uint8_t) OSC_FRQRANGE_12TO16_gc | 0b00001011;

	OSC.CTRL |= OSC_XOSCEN_bm;
	do {} while ( (OSC.STATUS & OSC_XOSCRDY_bm) == 0 ); // wait for clock to stabilize
	
	uint8_t clkCtrl = ( CLK.CTRL & ~CLK_SCLKSEL_gm ) | CLK_SCLKSEL_XOSC_gc;
	CCPWrite( &CLK.CTRL, clkCtrl );
}

#ifdef NOTDEF
char ctr;

int main(void) {
	ChangeClockFreq();
	
	PORTE.DIRSET = PIN7_bm;
	PORTE.DIRCLR = PIN6_bm;
	
	USART_Format_Set(&USARTE1, USART_CHSIZE_8BIT_gc,
			USART_PMODE_DISABLED_gc, false); // 8 bits, no parity, two stop bit
	
	USARTE1.CTRLA = ((USARTE1.CTRLA & ~USART_TXCINTLVL_gm) | USART_TXCINTLVL_LO_gc);
	
	// 2MHz
	//USARTE1.BAUDCTRLA = 11 & 0xFF;
	//USARTE1.BAUDCTRLB = (11 >> 8) & 0xFF;
	
	USARTE1.BAUDCTRLA = 983 & 0xFF;
	USARTE1.BAUDCTRLB = (983 >> 8) & 0xFF;
	
	USARTE1.BAUDCTRLB |= ((-7&0x0F) << USART_BSCALE0_bp);
	
	USART_Tx_Enable(&USARTE1);
	
	PMIC.CTRL |= PMIC_LOLVLEX_bm;
	sei();
	
	ctr=0;
	USARTE1.DATA = 'A';
	while(1) {
	}
}

ISR(USARTE1_TXC_vect)
{
	USARTE1.DATA=0xAA;
	ctr++;
	if (ctr==100) {
		ctr=0;
		_delay_ms(10);
	}
	/*ctr++;
	if (ctr==0)
		USARTE1.DATA=0xFF;
	else if (ctr==1)
		USARTE1.DATA=0x00;
	else if (ctr==2)
	{
		USARTE1.DATA=0xAA;
		ctr=0;
		_delay_ms(10);
	}*/
	//_delay_ms(500);
	//_delay_us(20);
}
#endif

int main(void) {
	CommPacket * commPkt;
	char read;
	PORTF.DIRSET = PIN7_bm;
	PORTE.DIRSET = PIN0_bm;
	PORTE.DIRSET = PIN5_bm;
	PORTD.DIRSET = PIN0_bm;
	PORTD.DIRSET = PIN4_bm;
	
	USART radioPort;
	USART debugPort;
	CommInterface inf;
	CommInterface txInf;
	Timer timer;
	Timer ledTimer;
	
	ChangeClockFreq();
	USART_InitPortStructs();
	InitTimers();
	
	USART_Open(&debugPort, 3, USART_BAUD_115200, 255, 255, true, true);
	USART_Open(&radioPort, 5, USART_BAUD_115200, 255, 255, false, true);
	CommInterfaceInit(&inf, &radioPort);
	CommInterfaceInit(&txInf, &debugPort);
	PORTF.OUTCLR = PIN7_bm;
	PORTE.OUTCLR = PIN5_bm;
	PORTE.OUTCLR = PIN0_bm;
	PORTD.OUTCLR = PIN0_bm;
	PORTD.OUTCLR = PIN4_bm;
	
	StartTimer(&timer);
	StartTimer(&ledTimer);
	unsigned char ctr = 'A';
	//USART_WriteByte(&radioPort, 'A');
	while(1) {
		char dat[8];
			dat[0]='X';
			dat[1]='M';
			dat[2]='E';
			dat[3]='G';
			dat[4]='A';
	
			/**/
	
			CommPacket respPkt;
			respPkt.target = 4;
			respPkt.data = dat;
			
			/*if (!CommSendPacket(&inf, &respPkt)) {
				PORTE.OUTSET = PIN5_bm;
			}*/
		
		if (GetSpanUs(&ledTimer)>FROM_uS(100000)) {
			StartTimer(&ledTimer);
			PORTD.OUT ^= PIN0_bm;
		}
		
		if (GetSpanUs(&timer)>FROM_uS(1000000)) {
			StartTimer(&timer);
			respPkt.length = 6;
			dat[5]=ctr++;
			if (dat[5]=='z')
				ctr='A';
			CommSendPacket(&inf,&respPkt);
			
			
		}
		
		USART_TransmitMode(&debugPort, true);
		if (CommRXPacketsAvailable(&inf)) { // message waiting on bus
			commPkt = CommGetPacket(&inf);
			if (!commPkt) {// failed to get packet, try again later
				PORTE.DIRSET = PIN0_bm;
				break;
			}
			
			respPkt.length = 8;
			dat[5]=commPkt->data[0];
			dat[6]=commPkt->data[1];
			dat[7]=commPkt->data[2];
			CommSendPacket(&txInf,&respPkt);
			//CommSendPacket(&inf,&respPkt);
			
			CommDeletePacket(commPkt);
			free(commPkt);
		}	
	}
	
	return 0;
}

