#include "Accelerometer.h"

int InitAccelerometer(CommInterface *roverInterface)
{
	AccelBufferPosition = 0;
	AccelRoverInterface = roverInterface;
	
	memset(AccelRingBuffer,0,60);
	
	accelReplyPacket.target = 1;
	accelReplyPacket.length = 8;
	accelReplyPacket.data = accelBuffer;
	
	if (i2c_start(ACCEL_ADDR+I2C_WRITE) == 0)
	{
		i2c_write(0x2A);
		i2c_write(0b00000101);
		i2c_write(0b00010010);
		i2c_stop();
	}
	else
		return 1;
		
	if (i2c_start(ACCEL_ADDR+I2C_WRITE) == 0)
	{
		i2c_write(0x13);
		i2c_write(0b0);
		i2c_stop();
	}		
	else
		return 1;
	
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
	data[0] = AccelRingBuffer[0][AccelBufferPosition]>>8;
	data[1] = AccelRingBuffer[0][AccelBufferPosition]&0xFF;
	data[2] = AccelRingBuffer[1][AccelBufferPosition]>>8;
	data[3] = AccelRingBuffer[1][AccelBufferPosition]&0xFF;
	data[4] = AccelRingBuffer[2][AccelBufferPosition]>>8;
	data[5] = AccelRingBuffer[2][AccelBufferPosition]&0xFF;
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
	
	data[0] = (Xavg + Xremain/10)>>8;
	data[1] = (Xavg + Xremain/10);
	data[2] = (Yavg + Yremain/10)>>8;
	data[3] = (Yavg + Yremain/10);
	data[4] = (Zavg + Zremain/10)>>8;
	data[5] = (Zavg + Zremain/10);
}

int AccelAddDataToBuffer(void)
{
	unsigned char MSB = 0, LSB = 0;
	if (i2c_start(ACCEL_ADDR+I2C_WRITE) == 0)	// Try to start a read from the accelerometer
	{
		i2c_write(0x01);
		i2c_rep_start(ACCEL_ADDR+I2C_READ);
		MSB = i2c_readAck();
		LSB = i2c_readAck();
		AccelRingBuffer[0][AccelBufferPosition] = (((short)(MSB))<<6)|((LSB>>2)&0b00111111);
		MSB = i2c_readAck();
		LSB = i2c_readAck();
		AccelRingBuffer[1][AccelBufferPosition] = (((short)(MSB))<<6)|((LSB>>2)&0b00111111);
		MSB = i2c_readAck();
		LSB = i2c_readNak();
		AccelRingBuffer[2][AccelBufferPosition] = (((short)(MSB))<<6)|((LSB>>2)&0b00111111);
		i2c_stop();
	
		if (AccelRingBuffer[0][AccelBufferPosition]&(1<<13))
			AccelRingBuffer[0][AccelBufferPosition]|=0b1100000000000000;
		if (AccelRingBuffer[1][AccelBufferPosition]&(1<<13))
			AccelRingBuffer[1][AccelBufferPosition]|=0b1100000000000000;
		if (AccelRingBuffer[2][AccelBufferPosition]&(1<<13))
			AccelRingBuffer[2][AccelBufferPosition]|=0b1100000000000000;
				
		if (AccelBufferPosition<9)
			AccelBufferPosition++;
		else
			AccelBufferPosition = 0;
		return 1;
	}		
	return 0;

}