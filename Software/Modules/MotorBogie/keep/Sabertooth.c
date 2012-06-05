/* Sabertooth.c
*  Authors: Mike Fortner, Chris Newman
*/

#include "Sabertooth.h"

#define MAX 127

#define SABERTOOTH_ADDRESS 128
#define DRIVE_FORWARD_CMD 0
#define DRIVE_REVERSE_CMD 1
#define ACTUATOR_FORWARD_CMD 4
#define ACTUATOR_REVERSE_CMD 5
#define TIMEOUT_CMD 14

USART *port;

void sabertooth_init(USART *p)
{
	port = p;
	//uint8_t opcode = TIMEOUT_CMD;
	//uint8_t timeout = 10; //10 * 100ms = 1s

	//send_command(opcode, timeout);
}

void send_command(uint8_t opcode, uint8_t data)
{
	uint8_t address = SABERTOOTH_ADDRESS;
	USART_WriteByte(port, address);
	USART_WriteByte(port, opcode);
	USART_WriteByte(port, data);
	USART_WriteByte(port, (address + opcode + data) & 0x7F);
}

void motor_set(int8_t speed, uint8_t forward_cmd, uint8_t reverse_cmd)
{
	uint8_t opcode;

	if (speed >= 0)
	{
		if (speed > MAX) speed = MAX;
		opcode = forward_cmd;
	}
	else
	{
		speed = -speed;  //flip speed and use 'reverse' command
		if (speed > MAX) speed = MAX;
		opcode = reverse_cmd;
	}

	send_command(opcode, speed);
}

void actuator_set(int8_t speed)
{
	motor_set(speed, ACTUATOR_FORWARD_CMD, ACTUATOR_REVERSE_CMD);
}

void drive_set(int8_t speed)
{
	motor_set(speed, DRIVE_FORWARD_CMD, DRIVE_REVERSE_CMD);
}