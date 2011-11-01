/*************************************************
 *
 * Controls Main XMEGA LEDs on the Rover Mainboard.
 *
 * Written by Taj Morton.
 * Copyright (C) 2011 OSURC.
 *************************************************/

#include "LEDController.h"

void LedInit() {
	LedGetPort(LED_TRIPOD)->DIRSET |= GetLedMask(LED_TRIPOD);
	LedGetPort(LED_RBOG)->DIRSET |= GetLedMask(LED_RBOG);
	LedGetPort(LED_BBOG)->DIRSET |= GetLedMask(LED_BBOG);
	LedGetPort(LED_LBOG)->DIRSET |= GetLedMask(LED_LBOG);
	LedGetPort(LED_DNT)->DIRSET |= GetLedMask(LED_DNT);
	LedGetPort(LED_STATUS)->DIRSET |= GetLedMask(LED_STATUS);
}

void LedAllOn() {
	LedOn(LED_TRIPOD);
	LedOn(LED_RBOG);
	LedOn(LED_BBOG);
	LedOn(LED_LBOG);
	LedOn(LED_DNT);
	LedOn(LED_STATUS);
}

void LedAllOff() {
	LedOff(LED_TRIPOD);
	LedOff(LED_RBOG);
	LedOff(LED_BBOG);
	LedOff(LED_LBOG);
	LedOff(LED_DNT);
	LedOff(LED_STATUS);
}

void LedAllToggle() {
	LedToggle(LED_TRIPOD);
	LedToggle(LED_RBOG);
	LedToggle(LED_BBOG);
	LedToggle(LED_LBOG);
	LedToggle(LED_DNT);
	LedToggle(LED_STATUS);
}

void LedOn(char which) {
	LedGetPort(which)->OUTSET |= GetLedMask(which);
}

void LedOff(char which) {
	LedGetPort(which)->OUTCLR |= GetLedMask(which);
}

void LedToggle(char which) {
	LedGetPort(which)->OUT ^= GetLedMask(which);
}

PORT_t * LedGetPort(char which) {
	switch (which) {
		case LED_TRIPOD:
			return &PORTC;
		case LED_RBOG:
			return &PORTD;
		case LED_BBOG:
			return &PORTD;
		case LED_LBOG:
			return &PORTE;
		case LED_DNT:
			return &PORTE;
		case LED_STATUS:
		default:
			return &PORTF;
	}
}

char GetLedMask(char which) {
	switch (which) {
		case LED_TRIPOD:
			return PIN4_bm;
		case LED_RBOG:
			return PIN0_bm;
		case LED_BBOG:
			return PIN4_bm;
		case LED_LBOG:
			return PIN0_bm;
		case LED_DNT:
			return PIN5_bm;
		case LED_STATUS:
		default:
			return PIN7_bm;
	}
}

