#include <stdio.h>
#include <string.h>

#include "GPSController.h"

void GPSInitialize() {
	USART_Open(&gpsInterface.gpsPort, 0, USART_BAUD_38400, 10, 10, true, true);	
	CommInterfaceInit(&gpsInterface.inf, &gpsInterface.gpsPort);
}

void GPSControllerHandleMessage(Rover * rov, CommPacket * pkt) {
	unsigned char i;
	char dat[2];
	/*printf("[GPS Controller]: Got a message for: %d - ",pkt->target);
	for (i=0;i<pkt->length;i++) {
		printf("%d ",pkt->data[i]);
	}
	printf("\n");
	
	CommPacket respPkt;
	respPkt.target = TARGET_GUI;
	respPkt.length = strlen(dat);
	respPkt.data = dat;
	SendMessage(rov,&respPkt);*/
	
	CommPacket reqPkt;
	reqPkt.target = 0x01;
	reqPkt.length = 2;
	reqPkt.data = pkt->data; // send data through
	CommSendPacket(&gpsInterface.inf, &reqPkt);
	
	reqPkt.target = TARGET_GUI;
	//SendMessage(rov, &reqPkt);
}

void GPSControllerTick(Rover * rov) {
	CommPacket datPkt;
	char data[20];
	char ret;
	
	datPkt.data=data;
	if (CommRXPacketsAvailable(&gpsInterface.inf)) { // message waiting on bus
		ret = CommGetPacket(&gpsInterface.inf, &datPkt, 20);
		
		datPkt.target = TARGET_GUI_GPS;//TARGET_GUI;
		if (!ret) {
			datPkt.length = 1;
			datPkt.data[0]=0xFF; // failed to read back
		}
		// else, just send back as-is
		
		/*datPkt.data[0]='A';
		datPkt.data[1]='D';
		datPkt.length=2;*/
		SendMessage(rov, &datPkt);
	}
}

