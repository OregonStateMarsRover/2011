
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>

#include "USART.h"
#include "CommInterface.h"


int main(void){
	USART roverPort;
	CommInterface inf;
	CommPacket commPkt;
	char commRet;

	USART_InitPortStructs();
	USART_Open(&roverPort, 0, USART_BAUD_38400, 20, 32, true);
	CommInterfaceInit(&inf, &roverPort);

	while(1) {
			
		while(CommRXPacketsAvailable(&inf)) {
			commRet = CommGetPacket(&inf, &commPkt, 20);
			// didn't get packet returned, even though it said we had one. give up for now
			if (!commRet){
				break;	
			}

			// bad 0-length packet, skip to the next one
			if (commPkt.length==0) { 
				continue;
			}




		}

	}