#include <stdlib.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "USART.h"
#include "Common/CommInterface/CommInterface.h"

#include "ProtocolDefines.h"
#include "PanTilt.h"

int main(void) {
	USART roverPort;
	USART devicePort;
	CommInterface inf;
	CommPacket * commPkt;
	
	USART_InitPortStructs();
	USART_Open(&roverPort, 0, USART_BAUD_38400, 20, 20, true);
	CommInterfaceInit(&inf, &port0);
	
	USART_Open(&devicePort, 1, USART_BAUD_38400, 20, 20, true);
	
	while(1) {
		while(CommRXPacketsAvailable(&inf)) {
			commPkt = CommGetPacket(&inf);
			
			if (!commPkt) // didn't get packet returned, even though it said we had one. give up for now
				break;
			
			if (commPkt->length==0) { // bad 0-length packet, skip to the next one
				CommDeletePacket(commPkt);
				free(commPkt);
				continue;
			}
			
			// must at least have a length of 1, check the first byte to see what device this is targeted at
			if (commPkt->data[0]==SYS_PANTILT) {
				
			}
			else if (commPkt->data[0]==SYS_CAMERA) {
			}
			else if (commPkt->data[0]==SYS_BAROMETER) {
			}
			else if (commPkt->data[0]==SYS_ACCEL) {
			}
			
			CommDeletePacket(commPkt);
			free(commPkt);
		}
	}
}

