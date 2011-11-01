#include "barometer.h"

int InitBarometer(CommInterface *roverInterface)
{
	memset(barometerPressureBuffer,0,BARO_BUFFERSIZE*4);
	memset(temperatureDataBuffer,0,BARO_BUFFERSIZE*2);
	barometerBufferPosition = 0;
	temperatureBufferPosition = 0;
	temperatureData = 0;
	barometerData = 0;
	
	BarometerRoverInterface = roverInterface;
	BarometerReplyPacket.target = 1;
	BarometerReplyPacket.data = BarometerDataBuffer;
	
	StartTimer(&BarometerReadTimer);
	barometerState = BAROMETER_IDLE;
	return BarometerGetCalibration(BarometerCalibData);
}

void BarometerHandlePacket(CommPacket * pkt) {

	if (pkt->data[0]==SYS_BAROMETER) { // make sure this is a packet that we're supposed to handle
		if (pkt->data[1]==BAROMETER_CALIB1) {
			BarometerDataBuffer[0] = BAROMETER_CALIB1;
			memcpy(&BarometerDataBuffer[1],&BarometerCalibData[0],sizeof(short)*6);
			BarometerReplyPacket.length = 13;
			CommSendPacket(BarometerRoverInterface,&BarometerReplyPacket);
		}
		if (pkt->data[1]==BAROMETER_CALIB2) {
			BarometerDataBuffer[0] = BAROMETER_CALIB2;
			memcpy(&BarometerDataBuffer[1],&BarometerCalibData[6],sizeof(short)*5);
			BarometerReplyPacket.length = 11;
			CommSendPacket(BarometerRoverInterface,&BarometerReplyPacket);
		}
		else if (pkt->data[1]==BAROMETER_DATA)
		{
			BarometerCalculateAverages();
			BarometerDataBuffer[0] = SYS_BAROMETER;
			BarometerDataBuffer[1] = BAROMETER_DATA;
			BarometerDataBuffer[2] = temperatureData>>8;
			BarometerDataBuffer[3] = temperatureData&0xFF;
			BarometerDataBuffer[4] = barometerData>>16;
			BarometerDataBuffer[5] = (barometerData>>8)&0xFF;
			BarometerDataBuffer[6] = (barometerData)&0xFF;
			BarometerReplyPacket.length = 7;
			CommSendPacket(BarometerRoverInterface,&BarometerReplyPacket);
		}
	}
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

void BarometerCalculateAverages(void)
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

char BarometerGetState(void)
{
	if ((barometerState == BAROMETER_IDLE) && (GetSpanUs(&BarometerReadTimer) > 390))
		return 1;
	else if ((barometerState == BAROMETER_TEMP) && (GetSpanUs(&BarometerReadTimer) > 45))
		return 1;
	else if ((barometerState == BAROMETER_PRESSURE) && (GetSpanUs(&BarometerReadTimer) > 205))
		return 1;
	else
		return 0;
		
}
