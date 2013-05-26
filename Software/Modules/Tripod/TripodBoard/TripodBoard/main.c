#define F_CPU 8000000UL

#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>

#include "USART.h"
#include "CommInterface.h"

#include "ProtocolDefines.h"
#include "Camera.h"
#include "PanTilt.h"
#include "i2cmaster.h"
#include "Timers.h"
#include "Accelerometer.h"
#include "barometer.h"

#define SETBITS(x,y) ((x) |= (y))
#define CLEARBITS(x,y) ((x) &= (~(y))) 

void setDeviceServo(void)
{
	cli();
	PORTD &= 0b11011111;
	PORTD |= 0b00010000;	
	sei();
}

void setDeviceCamera(void)
{
	cli();
	PORTD &= 0b11101111;
	PORTD |= 0b00100000;	
	sei();
}
/*
int main(void) 
{
	i2c_init();
	DDRA = 1;
	USART roverPort;
	Timer accelTimer;
	Timer timer2;
	
	DDRD |= 0b01000000;
	PORTD |= 0b01000000;
	
	USART_InitPortStructs();
	InitAccelerometer(0);
	InitTimers();
	StartTimer(&accelTimer);
	StartTimer(&timer2);
	
	USART_Open(&roverPort, 0, USART_BAUD_38400,200 , 10, false);
	short accelData[3] = {0,0,0};
	char textBuffer[200];
	int chars;
	_delay_ms(4000);

	while(1)
	{
		if (i2c_start(ACCEL_ADDR+I2C_WRITE) == 0)
		{
			i2c_write(0x0D);
			i2c_rep_start(ACCEL_ADDR+I2C_READ);
			i2c_readNak();
			i2c_stop();
			DDRA = 0b01;
		}			
		_delay_ms(100);
	}
}
*/

ISR (BADISR_vect)
{

}

int main(void)
{
	
	DDRD = 0b01110000;
	DDRA = 0b00000001;
	
	//wdt_reset();
	//wdt_disable();
	i2c_init();
	USART roverPort;
	USART devicePort;
	CommInterface inf;
	CommPacket commPkt;
	char commData[20];
	char commRet;
	Timer accelTimer;
	int sensorError;
	
	//PORTA = 1;
	//_delay_ms(250);
	//PORTA = 0;
	//_delay_ms(250);
	
	USART_InitPortStructs();

	setDeviceCamera();
	USART_Open(&roverPort, 0, USART_BAUD_38400, 20, 32, true);
	CommInterfaceInit(&inf, &roverPort);
	USART_Open(&devicePort, 1, USART_BAUD_9600, 20, 5, false);
	setDeviceServo();
	sensorError = InitAccelerometer(&inf);
	sensorError = InitBarometer(&inf);
	InitServos(&devicePort);
	InitCamera(&devicePort);
	InitTimers();
	//StartTimer(&accelTimer);
	//StartTimer(&dataTimer);

	setDeviceServo();
	PORTA |= 1;
	PanTiltSetPosition(TILT_SERVO, TILT_CENTER);
	PanTiltSetPosition(PAN_SERVO, PAN_CENTER);
    char pingRespond = 0xAA;
	
	commPkt.data = commData;
	
	CommPacket pkt;
	
	char textBuffer[40];
	char length;
	
	//Enable Watchdog
	//wdt_enable(0b111);
	while(1) {
			
		while(CommRXPacketsAvailable(&inf)) {
			commRet = CommGetPacket(&inf, &commPkt, 20);
			
			if (!commRet) // didn't get packet returned, even though it said we had one. give up for now
				break;
			
			if (commPkt.length==0) { // bad 0-length packet, skip to the next one
				continue;
			}
			
			// must at least have a length of 1, check the first byte to see what device this is targeted at
			if (commPkt.data[0]==SYS_PANTILT) {
				PORTA &= ~1;
				setDeviceServo();
				PanTiltHandlePacket(&commPkt);
				PORTA = sensorError;
				
			}
			else if (commPkt.data[0]==SYS_CAMERA) {
				PORTA &= ~1;
				setDeviceCamera();
				CameraHandlePacket(&commPkt);
				PORTA = sensorError;
			}
			else if (commPkt.data[0]==SYS_BAROMETER) {
				PORTA &= ~1;
				BarometerHandlePacket(&commPkt);
				PORTA = sensorError;
			}
			else if (commPkt.data[0]==SYS_ACCEL) {
				PORTA &= ~1;
				AccelHandlePacket(&commPkt);
				PORTA = sensorError;
			}
			else if (commPkt.data[0]==SYS_PING)
			{
				pkt.target = 1;
				pkt.length = 1;
				pkt.data = &pingRespond;
				CommSendPacket(&inf,&pkt);
			}
		}
		/*
		if (GetSpanUs(&dataTimer) > FROM_uS(1000000))
		{
			
			USART_WriteByte(&roverPort,0xFE);
			
			USART_WriteByte(&roverPort,temperatureData>>8);
			USART_WriteByte(&roverPort,temperatureData&0xFF);
			
			USART_WriteByte(&roverPort,barometerData>>16);
			USART_WriteByte(&roverPort,(barometerData>>8)&0xFF);
			USART_WriteByte(&roverPort,barometerData&0xFF);
			AccelGetAverage(aclBuf);
	
			length = sprintf(textBuffer,"X: %d \tY: %d \n\r",(aclBuf[0]<<8)|aclBuf[1], (aclBuf[2]<<8)|aclBuf[3]);
			
			USART_Write(&roverPort,textBuffer,length);
			StartTimer(&dataTimer);
		}
		*/
		/*
		if (GetSpanUs(&accelTimer) > 39)
		{
			sensorError |= AccelAddDataToBuffer();
			StartTimer(&accelTimer);
		}
		
		if (BarometerGetState() == 1)
		{	
			sensorError |= ServiceBarometer(3);
		}*/				
	}
}

