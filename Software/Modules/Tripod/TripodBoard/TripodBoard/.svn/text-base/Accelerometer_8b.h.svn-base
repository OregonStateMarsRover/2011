#ifndef HAVE_ACCELEROMETER_H
#define HAVE_ACCELEROMETER_H

#include "USART.h"
#include "CommInterface.h"
#include "i2cmaster.h"
#include "ProtocolDefines.h"
#include <string.h>

#define ACCEL_ADDR 0b00111000

int InitAccelerometer(CommInterface *roverInterface);
void AccelHandlePacket(CommPacket * pkt);
void AccelGetAverage(unsigned char *data); //Data must point to buffer at least 3 shorts in length
void AccelGetMostRecentSample(unsigned char *data);	//Data must point to buffer at least 3 shorts in length

int AccelAddDataToBuffer();

char AccelRingBuffer[3][10];
unsigned char AccelBufferPosition;
CommInterface *AccelRoverInterface;
unsigned char accelBuffer[8];
CommPacket accelReplyPacket;

#endif
