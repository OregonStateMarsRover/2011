#include "PanTilt.h"
#include "ProtocolDefines.h"
#include <util/delay.h>

void InitServos(USART *device_USART)
{
	servoUSART = device_USART;
	PanTiltSetCompliance(1,1,1,8,8);
	_delay_ms(50);
}

void PanTiltHandlePacket(CommPacket * pkt) {
	unsigned short position;
	unsigned short panPosition;
	unsigned short tiltPosition;
	if (pkt->data[0]==SYS_PANTILT) { // make sure this is a packet that we're supposed to handle
		if (pkt->data[1]==PANTILT_MOVE) {
			position = ((pkt->data[3]<<8) & 0xFF00) | (pkt->data[4] & 0xFF);
			
			if (pkt->data[2]==PAN_SERVO) {
				if (position<PAN_MIN)
					position = PAN_MIN;
				else if (position>PAN_MAX) {
					position = PAN_MAX;
				}
			}
			else if (pkt->data[2]==TILT_SERVO) {
				if (position<TILT_MIN)
					position = TILT_MIN;
				else if (position>TILT_MAX) {
					position = TILT_MAX;
				}
			}
			
			PanTiltSetPosition(pkt->data[2], position);
		}
		else if (pkt->data[1]==PANTILT_MOVEALL)
		{
			panPosition = ((pkt->data[2]<<8) & 0xFF00) | (pkt->data[3] & 0xFF);
			tiltPosition = ((pkt->data[4]<<8) & 0xFF00) | (pkt->data[5] & 0xFF);
			
			if (panPosition<PAN_MIN)
				panPosition = PAN_MIN;
			else if (panPosition>PAN_MAX)
				panPosition = PAN_MAX;

			if (tiltPosition<TILT_MIN)
				tiltPosition = TILT_MIN;
			else if (tiltPosition>TILT_MAX)
				tiltPosition = TILT_MAX;
				
			PanTiltSetPosition(1, panPosition);
			while(USART_TXUsed(servoUSART));
			_delay_us(100);
			PanTiltSetPosition(2, tiltPosition);
			
		}
		else if (pkt->data[1]==PANTILT_COMPLIANCE)
		{
			PanTiltSetCompliance(pkt->data[2],pkt->data[3],pkt->data[4],pkt->data[5],pkt->data[6]);
		}
		while(USART_TXUsed(servoUSART));
	}
}

void PanTiltSetPosition(char servo, unsigned short position) {
	char params[3] = { 0x1E, position & 0xFF, (position>>8) };
	SendServoCommand(servo, 0x03, 3, params);
}

void PanTiltSetCompliance(char servo, char CWMargin, char CCWMargin, char CWSlope, char CCWSlope)
{
	char params[5] = {0x1A, CWMargin, CCWMargin, CWSlope, CCWSlope};
	SendServoCommand(servo, 0x03, 5, params);
}

void SendServoCommand(char id, char instruction, char paramCount, char params[])
{      
	USART_WriteByte(servoUSART,0xFF);
	USART_WriteByte(servoUSART,0xFF);
	USART_WriteByte(servoUSART,id); // ID
	char length = paramCount + 2;
	USART_WriteByte(servoUSART,length); // Length

	USART_WriteByte(servoUSART,instruction); // Instruction
	char checksum = 0;
	char i;
	for (i = 0; i<paramCount; i++)
	{
		USART_WriteByte(servoUSART,params[i]); // Params...
		checksum += params[i];
	}

	checksum += id + length + instruction;
	checksum = ~checksum;

	USART_WriteByte(servoUSART,checksum); // Checksum
}

