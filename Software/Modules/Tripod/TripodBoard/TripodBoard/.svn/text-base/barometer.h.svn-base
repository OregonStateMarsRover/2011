#ifndef HAVE_BAROMETER_H
#define HAVE_BAROMETER_H

#include "USART.h"
#include "CommInterface.h"
#include "i2cmaster.h"
#include "ProtocolDefines.h"
#include "Timers.h"
#include <string.h>
#include <util/delay.h>

#define BAROMETER_ADDR 0b11101110
#define BAROMETER_IDLE 0
#define BAROMETER_TEMP 1
#define BAROMETER_PRESSURE 2

#define BARO_BUFFERSIZE 64

int InitBarometer(CommInterface *roverInterface);
void BarometerHandlePacket(CommPacket * pkt);
int BarometerGetCalibration(short *dataBuffer); 	// dataBuffer must be at least 11 shorts in length
void BarometerCalculateAverages(void);
int ServiceBarometer(int oss);
char BarometerGetState(void);	// 0 if barometer is busy
							// 1 if barometer needs to be serviced

char currentOSS;
char barometerState;
unsigned long barometerPressureBuffer[BARO_BUFFERSIZE];
short temperatureDataBuffer[BARO_BUFFERSIZE];
short temperatureData;
unsigned long barometerData;
char barometerBufferPosition;
char temperatureBufferPosition;
Timer BarometerReadTimer;
short BarometerCalibData[11];

CommInterface *BarometerRoverInterface;
CommPacket BarometerReplyPacket;
unsigned char BarometerDataBuffer[20];

#endif
