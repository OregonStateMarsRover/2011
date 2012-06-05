/*BogieController.h
 *Authors: Mike Fortner, Chris Newman
 */

#ifndef BOGIE_CONTROLLER_H
#define BOGIE_CONTROLLER_H

#include "BogieCommon.h"
#include "Sabertooth.h"
#include "Encoders.h"

#include "TC_driver.h"
#include "qdec_driver.h"

struct BogieControllerData {
	CommInterface mainboard_inf;
	USART motor_port;
	USART mainboard_port;
	
	PacketQueue pktQueue;
	CommPacket queuedPackets[6];
	unsigned char queuedData[6 * 20];
};

struct BogieControllerData bogie_controller;

 void bogie_controller_init(void);

 void parse_command();

 int main(void);

#endif