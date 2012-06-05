/*************************************************
 *
 * Controls GPS XMEGA LEDs on the Rover Mainboard.
 *
 * Written by Cody Hyman.
 * Copyright (C) 2011 OSURC.
 *************************************************/

#include <avr/io.h>

#define LED_GPS 0 
#define LED_SOC 1
#define LED_INT 2
#define LED_STATUS 3

void LedInit();
void LedOn(char which);
void LedOff(char which);
void LedToggle(char which);

void LedAllOn(void);
void LedAllOff(void);
void LedAllToggle(void);

PORT_t * LedGetPort(char which);
char GetLedMask(char which);
