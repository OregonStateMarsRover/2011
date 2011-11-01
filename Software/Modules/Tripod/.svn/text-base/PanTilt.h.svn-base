#ifndef HAVE_PANTILT_H
#define HAVE_PANTILT_H

#include "USART.h"
#include "CommInterface.h"

#define PAN_SERVO 0x01
#define TILT_SERVO 0x02

#define PAN_MIN 380
#define PAN_CENTER 545
#define PAN_MAX 692

#define TILT_MIN 540
#define TILT_CENTER 890
#define TILT_MAX 1000

void InitServos(USART *deviceUSART);
void SendServoCommand(char id, char instruction, char paramCount, char params[]);
void PanTiltHandlePacket(CommPacket * pkt);
void PanTiltSetPosition(char servo, unsigned short position);
void PanTiltSetCompliance(char servo, char CWMargin, char CCWMargin, char CWSlope, char CCWSlope);

USART *servoUSART;

#endif
