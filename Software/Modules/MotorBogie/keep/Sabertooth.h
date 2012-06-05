/* Sabertooth.h
*  Authors: Mike Fortner, Chris Newman
*/

#ifndef sabertooth_h
#define sabertooth_h

#include "BogieCommon.h"

//send initialization commands to motor driver.  timeout(watchdog timer) is set.  Could set deadband or ramping as well.
void sabertooth_init(USART *p);

//calculates checksum and sends the command over USART to the sabertooth
void send_command(uint8_t opcode, uint8_t data);

//send drive motor forward/backwards command, 'speed' represents a percentage between -100% and 100%, format to be determined. Note: actually has 7 bit resolution
void drive_set(int8_t speed);
void actuator_set(int8_t speed);

#endif
