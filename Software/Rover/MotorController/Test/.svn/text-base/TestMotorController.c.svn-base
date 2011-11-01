/**********************************************
 * Some (not-quite-unit) tests for the rover
 * motor control module.
 * You can check the results of this by running
 * the filedecoder util located in the CommInterface/Utils
 * directory and runnning it on the serial.* files
 * generated.
 *
 * Designed to be run with the X86 USART stubs.
 ***********************************************/

#include "../MotorController.h"

void TestSetSpeed() {
	CommPacket setSpeedPacket;
	unsigned char data[3];
	setSpeedPacket.length = 3;
	setSpeedPacket.target = TARGET_MOTOR_CONTROLLER;
	setSpeedPacket.data = data;
	
	data[0] = MOTOR_CONTROLLER_SET_SPEED;
	data[1] = (500>>8) & 0xFF;
	data[2] = 500 & 0xFF;
	MotorControllerHandleMessage(0, &setSpeedPacket);
	
	data[1] = (-500>>8) & 0xFF;
	data[2] = -500 & 0xFF;
	MotorControllerHandleMessage(0, &setSpeedPacket);
	
	data[1] = (5200>>8) & 0xFF;
	data[2] = 5200 & 0xFF;
	MotorControllerHandleMessage(0, &setSpeedPacket);
}

void TestSetHeading() {
	CommPacket setSpeedPacket;
	unsigned char data[3];
	setSpeedPacket.length = 3;
	setSpeedPacket.target = TARGET_MOTOR_CONTROLLER;
	setSpeedPacket.data = data;

	motorController.currentSpeed = 4960; // just set this so that we don't have extra garbage in the serial output files to parse through
	
	data[0] = MOTOR_CONTROLLER_SET_HEADING;
	data[1] = (50>>8) & 0xFF;
	data[2] = 50 & 0xFF;
	MotorControllerHandleMessage(0, &setSpeedPacket);
}

int main(int argc, char ** argv) {
	MotorControllerInit();
	TestSetSpeed();
	//TestSetHeading();
	
	// cleanup so Valgrind doesn't say we leaked memory
	USART_Close(&motorController.lbogPort);
	USART_Close(&motorController.rbogPort);
	USART_Close(&motorController.bbogPort);
	return 0;
}


