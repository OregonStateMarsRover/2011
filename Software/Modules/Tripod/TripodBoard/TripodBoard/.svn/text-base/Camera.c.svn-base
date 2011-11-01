#include "Camera.h"
#include "ProtocolDefines.h"

void InitCamera(USART *device_USART)
{
	cameraUSART= device_USART;
	//char command[4] = {0x88, 0x30, 0x01, 0xFF};
	//USART_Write(cameraUSART,command,4);
}

void CameraHandlePacket(CommPacket * pkt) {
	unsigned short position;
	if (pkt->data[0]==SYS_CAMERA) { // make sure this is a packet that we're supposed to handle
		if (pkt->data[1]==CAMERA_ZOOM)
			CameraSetZoom(((pkt->data[2]<<8)& 0xFF00) | (pkt->data[3]&0xFF));
		if (pkt->data[1]==CAMERA_COMMAND)
			CameraSendCommand(&pkt->data[2],pkt->length-2);
	}
}

void CameraSetZoom(unsigned short zoomLevel)
{
	char zoomCommand[9] = {0x81, 0x01, 0x04, 0x47, (zoomLevel>>9)&0x07, (zoomLevel>>6)&0x07, (zoomLevel>>3)&0x07, (zoomLevel)&0x07, 0xFF};
	USART_Write(cameraUSART,zoomCommand,9);
}

void CameraSendCommand(unsigned char * command, char length)
{
	USART_Write(cameraUSART, command, length);
}
