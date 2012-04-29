#ifndef HAVE_MOTORCONTROLLER_H
#define HAVE_MOTORCONTROLLER_H

#include "../ProcessManager/ProcessManager.h"

#include "USART.h"
#include "Common/CommInterface/CommInterface.h"
#include "Timer.h"

#define MOTOR_UNTEST

#define MOTOR_CONTROLLER_BAUD USART_BAUD_38400

#define MOTOR_CONTROLLER_ATOGGLE 1
#define MOTOR_CONTROLLER_SET_SPEED 2
#define MOTOR_CONTROLLER_SET_HEADING 3
#define MOTOR_CONTROLLER_SET_STRAFE 4
#define MOTOR_CONTROLLER_ESTOP 5
#define MOTOR_CONTROLLER_STATUS 6
#define MOTOR_CONTROLLER_SET_MOTORS 7
#define MOTOR_CONTROLLER_PASS_THRU 8
#define MOTOR_CONTROLLER_DISABLE_MOSFETS 10
#define MOTOR_CONTROLLER_PWM_MODE 11
#define MOTOR_CONTROLLER_RESET_WATCHDOG 12
#define MOTOR_CONTROLLER_SET_STALL_CURRENT 13
#define MOTOR_CONTROLLER_GET_TEMP 14
#define MOTOR_CONTROLLER_GET_CURRENT 15
#define MOTOR_CONTROLLER_DISABLE_CORNER_MOSFETS 16
#define MOTOR_CONTROLLER_SET_SPEED_HEADING 17

#define MOTOR_CONTROL_DEV_GETCURRENT 0x68
#define MOTOR_CONTROL_DEV_GETTEMP 0x79
#define MOTOR_CONTROL_DEV_SETVEL 0x73
#define MOTOR_CONTROL_DEV_SETPWM 0x75
#define MOTOR_CONTROL_DEV_DISABLE_MOSFETS 0x77
#define MOTOR_CONTROL_DEV_SETMAXCURRENT 0x78

#define MOTOR_STATE_NOTHING 0
#define MOTOR_STATE_TRANSMIT 1
#define MOTOR_STATE_WAITING_REPLY 2

#define MOTOR_COUNT 10
#define UPDATE_MOTOR_ID(x) (x->motorIds[x->updateMotorIndex])

#define BUS_MAX_ARGLENGTH 3
#define BUS_MAX_MOTORS 4

#define MOTOR_CONTROL_GETDATA_TIMEOUT 7000000

// state machine/CommInterface combo for sending updates out to motor controllers on a bus
struct SMotorBus {
	CommInterface * inf;
	
	short motorSpeeds[BUS_MAX_MOTORS]; // the last speed set for the motor that received a valid reply - each bus has at most 4 devices (2 motors +  1 or 2 actuators)
	short targetMotorSpeeds[BUS_MAX_MOTORS]; // the motor speed we want to achieve
	short newMotorSpeeds[BUS_MAX_MOTORS]; // motor speed update
	
	char motorCommand[BUS_MAX_MOTORS];
	char targetMotorCommand[BUS_MAX_MOTORS];
	char newMotorCommand[BUS_MAX_MOTORS];
	
	unsigned char motorArguments[BUS_MAX_MOTORS][BUS_MAX_ARGLENGTH];
	unsigned char targetMotorArguments[BUS_MAX_MOTORS][BUS_MAX_ARGLENGTH];
	unsigned char newMotorArguments[BUS_MAX_MOTORS][BUS_MAX_ARGLENGTH];
	
	char motorArgumentLength[BUS_MAX_MOTORS];
	char targetMotorArgumentLength[BUS_MAX_MOTORS];
	char newMotorArgumentLength[BUS_MAX_MOTORS];
	
	unsigned char transmitState, updateMotorIndex, updateMotorStop;
	unsigned char motorIds[BUS_MAX_MOTORS]; // device ID association with motor index for this bus
	unsigned char motorStatus[BUS_MAX_MOTORS];
	unsigned short motorCurrent[BUS_MAX_MOTORS];
	unsigned short motorTemperature[BUS_MAX_MOTORS];
	Timer replyTimer; // used to catch timeouts
	
	char motorUpdateTimeouts[BUS_MAX_MOTORS];
	
	char restartTransmitIndex; // if this is NOT -1, tell the state machine to restart the transmission sequence at the specified restartTransmitIndex after the current one finishes or times out
	
	char doDisableMosfets;
};
typedef struct SMotorBus MotorBus;
/*
struct MotorControllerData {
	CommInterface rbog, lbog, bbog;
	USART rbogPort, lbogPort, bbogPort;
	
	short currentSpeed, currentHeading;
	short strafeX, strafeY, strafeRot;
	bool inStrafeMode;
	
	bool wantTempReport, wantCurrentReport;
	bool tempReportReady, currentReportReady;
	
	short motorSpeeds[10];
	unsigned char transmitState, updateMotorIndex, updateMotorStop;
	unsigned char motorIds[10]; // ID association for motor index

	Timer motorTimer;
	Timer watchdogTimer; // used to track time since last speed update
	Timer statusTimer; // used to send status updates every second
	Timer tempSendTimer;
	Timer currentSendTimer;
	
	MotorBus *busIdMap[10];
	MotorBus lbogBus, rbogBus, bbogBus;
	char doPwmMode;
};
*/

typedef struct sBogieData{
	char position;
	char velocity;
}BogieData;

/*
typedef struct MotorControllerData{
	BogieData Bogies[6];
}MotorController;
*/

/*
struct MotorControllerData motorController;
*/
void RunMotorBus(MotorBus * bus, Rover * rov);

void MotorControllerInit();
void MotorControllerHandleMessage(Rover * rov, CommPacket * pkt);
void MotorControllerTick(Rover * rov);

void MotorControllerToggleActuators();
void MotorControllerSetSpeed(short speed);
void MotorControllerSetHeading(short heading);
void MotorControllerEStop();
void MotorControllerSendStatus();
void MotorControllerSetStallCurrent(short stallCurrent);
void MotorControllerSetSpeedHeading(short speed, short heading);

void MotorControllerGetTemperatures();
void MotorControllerGetCurrent();

void MotorControllerUpdateActuators();
void MotorControllerPassThru(CommPacket * pkt, Rover * rov);

void MotorControllerSetMotors(short speed, short heading);
void MotorControllerDisableMosfets(char disableMosfets);
void MotorControllerPWMMode(char enablePWM);
void MotorControllerDisableCornerMosfets(char disableMosfets);

void MotorControllerUpdateMotors(short speeds[6], unsigned char startMotor, unsigned char stopMotor);

void MotorControllerInitBus(MotorBus * bus);

CommInterface * MotorControllerInfForDevice(char device);
MotorBus * MotorControllerBusForId(char device);
char MotorControllerBusPosForId(char device);
void MotorControllerSendCommand(char device, char cmd, char length, char * dat);
void MotorControllerSendShort(char device, char cmd, short dat);

short MotorControllerBufToShort(char * buf);
unsigned short MotorControllerBufToUShort(char * buf);

#endif

