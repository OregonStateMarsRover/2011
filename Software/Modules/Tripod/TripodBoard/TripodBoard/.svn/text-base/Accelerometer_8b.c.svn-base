#include "Accelerometer.h"

int InitAccelerometer(CommInterface *roverInterface)
{
	AccelBufferPosition = 0;
	AccelRoverInterface = roverInterface;
	
	memset(AccelRingBuffer,0,30);
	
	accelReplyPacket.target = 1;
	accelReplyPacket.length = 5;
	accelReplyPacket.data = accelBuffer;
	
	if (i2c_start(ACCEL_ADDR+I2C_WRITE) == 0)	// Try to start a read from the accelerometer
	{
		i2c_write(0x20);
		i2c_write(0b01000111);
		i2c_stop();
	
		if (AccelBufferPosition<9)
			AccelBufferPosition++;
		else
			AccelBufferPosition = 0;
		return 1;
	}		
	return 0;
	
}

void AccelHandlePacket(CommPacket * pkt) {
	
	if (pkt->data[0]==SYS_ACCEL) { // make sure this is a packet that we're supposed to handle
		if (pkt->data[1]==ACCEL_AVERAGE)
		{
			accelBuffer[0]=SYS_ACCEL;
			accelBuffer[1] = ACCEL_AVERAGE;
			AccelGetAverage(&accelBuffer[2]);
			CommSendPacket(AccelRoverInterface,&accelReplyPacket);
			
		}
		else if (pkt->data[1]==ACCEL_CURRENT)
		{
			accelBuffer[0] = SYS_ACCEL;
			accelBuffer[1] = ACCEL_CURRENT;
			AccelGetMostRecentSample(&accelBuffer[2]);
			CommSendPacket(AccelRoverInterface,&accelReplyPacket);
		}			
	}
	
}

void AccelGetMostRecentSample(unsigned char *data)
{
	data[1] = AccelRingBuffer[0][AccelBufferPosition];
	data[3] = AccelRingBuffer[1][AccelBufferPosition];
	data[5] = AccelRingBuffer[2][AccelBufferPosition];
	if ((data[1] & 0b10000000) != 0)
		data[0] = 0xFF;
	if ((data[3] & 0b10000000) != 0)
		data[2] = 0xFF;
	if ((data[5] & 0b10000000) != 0)
		data[4] = 0xFF;
}

void AccelGetAverage(unsigned char *data)
{
	short Xavg = 0, Yavg = 0, Zavg = 0;
	short Xremain = 0, Yremain = 0, Zremain = 0;
	int count;
	for (count = 0; count < 10; count ++)
	{
		Xavg += AccelRingBuffer[0][count]/10;
		Yavg += AccelRingBuffer[1][count]/10;
		Zavg += AccelRingBuffer[2][count]/10;
		
		Xremain += AccelRingBuffer[0][count]%10;
		Yremain += AccelRingBuffer[1][count]%10;
		Zremain += AccelRingBuffer[2][count]%10;
	}
	
	data[1] = (Xavg + Xremain/10);
	data[3] = (Yavg + Yremain/10);
	data[5] = (Zavg + Zremain/10);
	
	if ((data[1] & 0b10000000) != 0)
		data[0] = 0xFF;
	if ((data[3] & 0b10000000) != 0)
		data[2] = 0xFF;
	if ((data[5] & 0b10000000) != 0)
		data[4] = 0xFF;
	
}

int AccelAddDataToBuffer()
{
	if (i2c_start(ACCEL_ADDR+I2C_WRITE) == 0)	// Try to start a read from the accelerometer
	{
		i2c_write((0x29)|(0b10000000));
		i2c_rep_start(ACCEL_ADDR+I2C_READ);
		AccelRingBuffer[0][AccelBufferPosition] = i2c_readAck();
		i2c_readAck();
		AccelRingBuffer[1][AccelBufferPosition] = i2c_readAck();
		i2c_readAck();
		AccelRingBuffer[2][AccelBufferPosition] = i2c_readNak();
		i2c_stop();
	
		if (AccelBufferPosition<9)
			AccelBufferPosition++;
		else
			AccelBufferPosition = 0;
		return 1;
	}		
	return 0;

}
