/*************************************************
 *
 * Controls Main XMEGA LEDs on the Rover Mainboard.
 *
 * Written by Taj Morton.
 * Copyright (C) 2011 OSURC.
 *************************************************/

#include <avr/io.h>

#define LED_TRIPOD 0
#define LED_RBOG 1
#define LED_BBOG 2
#define LED_LBOG 3
#define LED_DNT 4
#define LED_STATUS 5

void LedInit();
void LedOn(char which);
void LedOff(char which);
void LedToggle(char which);

void LedAllOn();
void LedAllOff();
void LedAllToggle();

PORT_t * LedGetPort(char which);
char GetLedMask(char which);

