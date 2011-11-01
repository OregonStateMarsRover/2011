#include <avr/io.h>
#include <util/delay.h>

#define u08 unsigned char
#define u16 unsigned short
#define u32 unsigned int

#ifndef F_CPU
#define F_CPU 16000000
#endif

void init(void);
void led_on(u08 addr);
void led_off(u08 addr);
//void sendByte(u08 addr,char byte);
