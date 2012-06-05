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
	LedGetPort(LED_SOC)->DIRSET |= GetLedMask(LED_SOC);
}

void LedAllOn() {
	LedOn(LED_INT);
	LedOn(LED_SOC);
}

void LedAllOff() {
	LedOff(LED_INT);
	LedOff(LED_SOC);
}

void LedAllToggle() {
	LedToggle(LED_INT);
	LedToggle(LED_SOC);
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
			return &PORTD;
		case LED_SOC:
		default:
			return &PORTD;
	}
}

char GetLedMask(char which) {
	switch (which) {
		case LED_INT:
			return PIN4_bm;
		case LED_SOC:
		default:
			return PIN5_bm;
	}
}

