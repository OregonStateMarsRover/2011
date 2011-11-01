#ifndef HAVE_PANTILT_H
#define HAVE_PANTILT_H

#include "USART.h"
#include "CommInterface.h"

void InitCamera(USART *deviceUSART);
void CameraHandlePacket(CommPacket * pkt);
void CameraSetZoom(unsigned short zoomLevel);
void CameraSendCommand(unsigned char * command, char length);

USART *cameraUSART;

#endif