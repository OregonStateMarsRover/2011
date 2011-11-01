/*
 * BaseBarometer.c
 *
 * Created: 5/6/2011 11:42:29 PM
 *  Author: Scylla
 */ 

#define F_CPU 16000000UL
#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))
#define CPU_16MHz       0x00

#define GET_CALIB 1
#define GET_DATA 2

#include <avr/io.h>
#include <util/delay.h>
#include "i2cmaster.h"
#include "Timers.h"
#include "barometerBase.h"
#include "usb_rawhid_debug.h"

int main(void)
{
	CPU_PRESCALE(CPU_16MHz);
	i2c_init();
	usb_init();
	InitTimers();
	Timer dataTimer;
	InitBarometer();
	
	char buffer[23];
	_delay_ms(3000);
	
	StartTimer(&dataTimer);
	ServiceBarometer(3);
	
    while(1)
    {
		if (usb_rawhid_recv(buffer,1) > 0)
		{
			if (buffer[0] == GET_CALIB)
			{
				buffer[0] = 22;
				memcpy(&(buffer[1]),BarometerCalibData,22);
				usb_rawhid_send(buffer,50);
			}
			else if (buffer[0] == GET_DATA)
			{
				buffer[0] = 5;
				BarometerCalculateAverages();
				buffer[1] = temperatureData>>8;
				buffer[2] = temperatureData&0xFF;
				buffer[3] = (barometerData>>16) & 0xFF;
				buffer[4] = (barometerData>>8)&0xFF;
				buffer[5] = barometerData&0xFF;
				usb_rawhid_send(buffer,50);
			}
		}			
			/*
			if (GetSpanUs(&dataTimer) == FROM_uS(500000))
			{
				buffer[0] = 5;
				BarometerCalculateAverages();
				buffer[1] = temperatureData>>8;
				buffer[2] = temperatureData&0xFF;
				buffer[3] = (barometerData>>16) & 0xFF;
				buffer[4] = (barometerData>>8)&0xFF;
				buffer[5] = barometerData&0xFF;
				usb_rawhid_send(buffer,50);
			}	*/		
		
			if (BarometerGetState() == 1)
			{
				if (ServiceBarometer(3) ==1)
					barometerPressureBuffer[barometerBufferPosition] = 0;
			}
    }
}