/*BogieCommon.h
 *Authors: Mike Fortner, Chris Newman
 */

#ifndef BOGIE_COMMON_H
#define BOGIE_COMMON_H

//CPU frequency for delay.h
//# define F_CPU 2000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdint.h>

#include "USART.h"
#include "PacketQueuer.h"
#include "Common/CommInterface/CommInterface.h"


struct PIDobject 
{
	uint16_t p;			//proportional constant
	uint16_t i;			//integral constant
	uint16_t d;			//derivative constant
	uint16_t prev_error;//most recent error
	uint16_t sum_error; //sum of previous errors
	uint16_t dt;		//delta time between calculations
};

typedef struct PIDobject PIDobject;

void usart_send_byte(USART_t *usart, uint8_t data);

uint8_t pid(PIDobject *pid, uint16_t desired, uint16_t actual);

#endif
