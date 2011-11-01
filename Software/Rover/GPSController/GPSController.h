#include "../ProcessManager/ProcessManager.h"

#include "USART.h"
#include "Common/CommInterface/CommInterface.h"

struct GPSControllerData {
	CommInterface inf;
	USART gpsPort;
};

struct GPSControllerData gpsInterface;

void GPSInitialize();
void GPSControllerHandleMessage(Rover * rov, CommPacket * pkt);
void GPSControllerTick(Rover * rov);

