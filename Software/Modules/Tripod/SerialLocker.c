#include "SerialLocker.h"

void SerialLockerInit(USART * port) {
	serLocker.port=port;
	serLocker.currentDevice = DEVICE_PANTILT;
	
	GetLockForDevice(DEVICE_PANTILT); // setup IO for pan/tilt
}

char GetCurrentDevice() {
}

char GetLockForDevice(char device) {
	
}

void SetupDeviceSelection(char device, char asOutput) {
	if (device==DEVICE_PANTILT && asOutput==1) {
		PORTD &= ~(1<<5); // clear PD5
		PORTD |= (1<<4); // set PD4
	}
	else  if (device==DEVICE_CAMERA && asOutput==1) {
		PORT
	}
}

