#ifndef F_CPU
#define F_CPU 2000000
#endif


#include <avr/io.h>
#include <util/delay.h>

#include "USART/usart_driver.h"

#define u08 unsigned char
#define u16 unsigned short
#define u32 unsigned int

USART_data_t USART_data;

void init(void);
void init_uart(char addr);
void led_on(u08 addr);
void led_off(u08 addr);
void sendByte(u08 addr,char byte);
void enable485(u08 addr, char enabled);
USART_t * getUSART(u08 addr);
