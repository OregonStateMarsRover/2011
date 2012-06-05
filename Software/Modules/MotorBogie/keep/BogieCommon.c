/*BogieCommon.c
 *Authors: Mike Fortner, Chris Newman
 */

#include "BogieCommon.h"

void usart_send_byte(USART_t *usart, uint8_t data)
{
	uint8_t dreif = 0;
	while(dreif == 0){dreif = (usart->STATUS & 0b00100000) ;}
	usart->DATA = data;
}

uint8_t pid(PIDobject *pid, uint16_t desired, uint16_t actual)
{
	uint16_t p_error = desired - actual;

	uint16_t i_error = pid->sum_error / pid->dt;

	uint16_t d_error = p_error - pid->prev_error;

	pid->sum_error += p_error;
	pid->prev_error = p_error;

	return (uint8_t)(pid->p * p_error + pid->i * i_error + pid->d * d_error);
}

