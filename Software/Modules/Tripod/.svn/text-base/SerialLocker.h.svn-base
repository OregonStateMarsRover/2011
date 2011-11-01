/**********************************************
 * Manages the UART for the servos and camera.
 * Allows a device to request usage, setup
 * I/O, transmit data, and not switch devices
 * until transmission has completed.
 **********************************************/

#ifndef HAVE_SERIALLOCKER_H
#define HAVE_SERIALLOCKER_H

#define DEVICE_PANTILT 0x01
#define DEVICE_CAMERA 0x02

struct SerialLocker {
	char currentDevice;
	USART * port;
};

struct SerialLocker serLocker;

void SerialLockerInit(USART * port);

/**
 * Returns device currently owning the USART.
 */
char GetCurrentDevice();

/**
 * Obtains a lock for the device specified.
 * If a transmission is currently in progress for a different
 * device, this function will block until the TX buffer empties.
 * Once the lock is obtained, the device selection I/O lines
 * will be configured to transmit to the specified device.
 *
 * If the device already has a lock, this function returns immediately.
 */
char GetLockForDevice(char device);

#endif

