/*************************************************
 *
 * Controls LEDs on the Rover GPS XMEGA.
 *
 * Written by Taj Morton.
 * Copyright (C) 2011 OSURC.
 *************************************************/

#include <avr/io.h>

#define LED_STATUS 0
#define LED_INT 1
#define LED_GPS 2
#define LED_SOC 3

void LedInit();
void LedOn(char which);
void LedOff(char which);
void LedToggle(char which);

void LedAllOn();
void LedAllOff();
void LedAllToggle();

PORT_t * LedGetPort(char which);
char GetLedMask(char which);

