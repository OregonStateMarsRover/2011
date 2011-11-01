#ifndef HAVE_BAROMETER_H
#define HAVE_BAROMETER_H

#include "i2cmaster.h"
#include "Timers.h"
#include <string.h>
#include <avr/delay.h>

#define BAROMETER_ADDR 0b11101110
#define BAROMETER_IDLE 0
#define BAROMETER_TEMP 1
#define BAROMETER_PRESSURE 2

#define BARO_BUFFERSIZE 64

int InitBarometer();
int BarometerGetCalibration(short *dataBuffer); 	// dataBuffer must be at least 11 shorts in length
void BarometerCalculateAverages();
int ServiceBarometer(int oss);
char BarometerGetState();	// 0 if barometer is busy
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

#endif
