#include "barometerBase.h"

int InitBarometer()
{
	memset(barometerPressureBuffer,0,BARO_BUFFERSIZE*4);
	memset(temperatureDataBuffer,0,BARO_BUFFERSIZE*2);
	barometerBufferPosition = 0;
	temperatureBufferPosition = 0;
	temperatureData = 0;
	barometerData = 0;

	StartTimer(&BarometerReadTimer);
	barometerState = BAROMETER_IDLE;
	return BarometerGetCalibration(BarometerCalibData);
}

int BarometerGetCalibration(short *dataBuffer)	// dataBuffer must be at least 11 shorts in length
{
	int i = 0;
	if (i2c_start(BAROMETER_ADDR+I2C_WRITE))
	{
		i2c_write(0xAA);
		i2c_rep_start(BAROMETER_ADDR+I2C_READ);
		for (i = 0; i<11; i++)
		{
			dataBuffer[i] = ((short)i2c_readAck());
			dataBuffer[i] = dataBuffer[i]|(((short)i2c_readAck())<<8);
		}
		return 0;
	}
	return 1;
}

void BarometerCalculateAverages()
{
	short TempAvg = 0, TempRemain = 0;
	unsigned long PressAvg = 0, PressRemain = 0;
	int count;
	for (count = 0; count < BARO_BUFFERSIZE; count ++)
	{
		TempAvg += temperatureDataBuffer[count]/BARO_BUFFERSIZE;
		PressAvg += barometerPressureBuffer[count]/BARO_BUFFERSIZE;
		
		TempRemain += temperatureDataBuffer[count]%BARO_BUFFERSIZE;
		PressRemain += barometerPressureBuffer[count]%BARO_BUFFERSIZE;
	}
	
	temperatureData = TempAvg+(TempRemain/BARO_BUFFERSIZE);
	barometerData = PressAvg+(PressRemain/BARO_BUFFERSIZE);
}


int ServiceBarometer(int oss)
{
	if (barometerState == BAROMETER_IDLE)	// If we are not already in the middle of a measurement
	{	// Start a new measurement
		barometerState = BAROMETER_TEMP;
		currentOSS = oss;
		
		//Start the temperature measurement
		if (i2c_start(BAROMETER_ADDR+I2C_WRITE)==0)
		{
			i2c_write(0xF4);
			i2c_write(0x2E);
			i2c_stop();
			StartTimer(&BarometerReadTimer);
		}
		else
		{
			barometerState = BAROMETER_IDLE;
			StartTimer(&BarometerReadTimer);
			return 1;
		}			
	}
	else if (barometerState == BAROMETER_TEMP)
	{
		// Get the temperature and store it
		if (i2c_start(BAROMETER_ADDR+I2C_WRITE) == 0)
		{
			i2c_write(0xF6);
			i2c_rep_start(BAROMETER_ADDR+I2C_READ);
			temperatureDataBuffer[temperatureBufferPosition] = (((short)i2c_readAck())<<8)|i2c_readNak();
			temperatureBufferPosition = (temperatureBufferPosition+1)%BARO_BUFFERSIZE;
			i2c_stop();
		}
		else
		{
			barometerState = BAROMETER_IDLE;
			StartTimer(&BarometerReadTimer);
			return 1;
		}			
		
		// Start the pressure measurement
		if (i2c_start(BAROMETER_ADDR+I2C_WRITE)==0)
		{
			i2c_write(0xF4);
			i2c_write((0x34)+(currentOSS<<6));
			i2c_stop();
			StartTimer(&BarometerReadTimer);
		
			barometerState = BAROMETER_PRESSURE;
		}
		else
		{
			barometerState = BAROMETER_IDLE;
			StartTimer(&BarometerReadTimer);
			return 1;
		}			
	}
	else if (barometerState == BAROMETER_PRESSURE)
	{
		// Get the pressure data and store it
		if (i2c_start(BAROMETER_ADDR+I2C_WRITE)==0)
		{
			i2c_write(0xF6);
			i2c_rep_start(BAROMETER_ADDR+I2C_READ);
			barometerPressureBuffer[barometerBufferPosition] = ((((unsigned long)i2c_readAck())<<16) | (((unsigned long)i2c_readAck())<<8) | (i2c_readNak()))>>(8-currentOSS);
			i2c_stop();
			barometerBufferPosition = (barometerBufferPosition+1)%BARO_BUFFERSIZE;
		}
		else
			return 1;
		barometerState = BAROMETER_IDLE;
		StartTimer(&BarometerReadTimer);
	}
	else
		barometerState = BAROMETER_IDLE;
		StartTimer(&BarometerReadTimer);
	return 0;
}

char BarometerGetState()
{
	if ((barometerState == BAROMETER_IDLE) && (GetSpanUs(&BarometerReadTimer) > FROM_uS(64000)))
		return 1;
	else if ((barometerState == BAROMETER_TEMP) && (GetSpanUs(&BarometerReadTimer) > FROM_uS(5000)))
		return 1;
	else if ((barometerState == BAROMETER_PRESSURE) && (GetSpanUs(&BarometerReadTimer) > FROM_uS(26000)))
		return 1;
	else
		return 0;
		
}
