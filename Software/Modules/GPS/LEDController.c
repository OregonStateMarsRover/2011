/*************************************************
 *
 * Controls LEDs on the Rover GPS XMEGA.
 *
 * Written by Taj Morton.
 * Copyright (C) 2011 OSURC.
 *************************************************/

#include "LEDController.h"

void LedInit() {
	LedGetPort(LED_INT)->DIRSET |= GetLedMask(LED_INT);
	LedGetPort(LED_GPS)->DIRSET |= GetLedMask(LED_GPS);
	LedGetPort(LED_SOC)->DIRSET |= GetLedMask(LED_SOC);
	LedGetPort(LED_STATUS)->DIRSET |= GetLedMask(LED_STATUS);
}

void LedAllOn() {
	LedOn(LED_INT);
	LedOn(LED_GPS);
	LedOn(LED_SOC);
	LedOn(LED_STATUS);
}

void LedAllOff() {
	LedOff(LED_INT);
	LedOff(LED_GPS);
	LedOff(LED_SOC);
	LedOff(LED_STATUS);
}

void LedAllToggle() {
	LedToggle(LED_INT);
	LedToggle(LED_GPS);
	LedToggle(LED_SOC);
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
		case LED_INT:
			return &PORTE;
		case LED_GPS:
			return &PORTF;
		case LED_SOC:
			return &PORTF;
		case LED_STATUS:
		default:
			return &PORTB;
	}
}

char GetLedMask(char which) {
	switch (which) {
		case LED_INT:
			return PIN4_bm;
		case LED_GPS:
			return PIN1_bm;
		case LED_SOC:
			return PIN5_bm;
		case LED_STATUS:
		default:
			return PIN7_bm;
	}
}

