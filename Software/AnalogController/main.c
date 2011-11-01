#include <stdlib.h>
#include <stdbool.h>

#include "USART.h"
#include "Common/CommInterface/CommInterface.h"

#include "adc_driver.h"
/*
 main takes input from pots using code that taj found somewhere
 HandleRoverUpdate decides whether the values changed and, if they changed, sends values 
    to either MotorControllerUpdateMotors or PacketToRover depending on define of USE_MAIN_BOARD
 
 
 
 */
CommInterface inf;
USART port;
USART debugPort;
bool current_actuate_state;
signed short heading, speed;
bool isActuated;

#define JS_DELTA_THRESH 10
#define JS_OFF 300

#define MOTOR_CONTROL_DEV_SETVEL 0x73
#define USE_MAIN_BOARD
void SetupADCs() {
	ADC_CalibrationValues_Load(&ADCA);
	
	ADC_ConvMode_and_Resolution_Config(&ADCB, false, ADC_RESOLUTION_12BIT_gc); // unsigned 12-bit conversion
	ADC_Reference_Config(&ADCA, ADC_REFSEL_AREFA_gc);
	
	ADC_Ch_InputMode_and_Gain_Config(&ADCA.CH0,
	                                 ADC_CH_INPUTMODE_SINGLEENDED_gc,
	                                 ADC_CH_GAIN_1X_gc);
	
	ADC_Ch_InputMode_and_Gain_Config(&ADCA.CH1,
	                                 ADC_CH_INPUTMODE_SINGLEENDED_gc,
	                                 ADC_CH_GAIN_1X_gc);
	                                 
	ADC_Ch_InputMux_Config(&ADCA.CH0, ADC_CH_MUXPOS_PIN3_gc, ADC_CH_MUXNEG_PIN0_gc);
	ADC_Ch_InputMux_Config(&ADCA.CH0, ADC_CH_MUXPOS_PIN4_gc, ADC_CH_MUXNEG_PIN0_gc);
	
	ADC_Enable(&ADCA);
	
	ADC_Wait_8MHz(&ADCA);
}

// This function copied (and updated) from MotorController.c
void MotorControllerUpdateMotors(short speeds[6]) {
	CommPacket cmdPacket;
	unsigned char data[3];
	short max = 0;
	unsigned char i;
	
	cmdPacket.length = 3;
	cmdPacket.data = data;
	data[0] = MOTOR_CONTROL_DEV_SETVEL;
	
	for (i=0;i<6;i++) {
		if (abs(speeds[i])>max)
			max = abs(speeds[i]);
	}
	
	if (max>4800) {
		for (i=0;i<6; i++) {
			speeds[i] = (speeds[i]*1490)/max; // scale between -1490 1490
		}
	}
	
	for (i=0;i<6;i++) { // send speed update
		cmdPacket.target = i+1; // IDs are numbered from 1
		data[1] = (speeds[i] >> 8) & 0xFF;//high byte
		data[2] = speeds[i] & 0xFF;//low byte
		
		CommSendPacket(&inf, &cmdPacket);
	}
}

void ToggleActuatePacket(){
  CommPacket cmdPacket; 
  unsigned char data=0x01;
  cmdPacket.length=1; 
  cmdPacket.data=&data;
  cmdPacket.target=2;
  CommSendPacket(&inf, &cmdPacket);
}
// This function copied from MotorController.c

void SendSpeedPacket(short speed){
  CommPacket cmdPacket;
  unsigned char data[3];
  cmdPacket.target=2;
  cmdPacket.length = 3;
  cmdPacket.data = data;
  data[0] = 0x02;
  data[1] = (speed >> 8) & 0xFF;//high byte
  data[2] = speed & 0xFF;//low byte
  CommSendPacket(&inf, &cmdPacket);
}
void SendHeadingPacket(short heading){
    CommPacket cmdPacket;
  unsigned char data[3];
  cmdPacket.target=2;
  cmdPacket.length = 3;
  cmdPacket.data = data;
  data[0] = 0x03;
  data[1] = (heading >> 8) & 0xFF;//high byte
  data[2] = heading & 0xFF;//low byte
  CommSendPacket(&inf, &cmdPacket);
  
}
void MotorControllerSetMotors(short speed, short heading) {
	short speeds[6];
	
	// FRONT
	// 1   6
	// 2   5
	// 3   4
	// BACK
	
	/*
	swap 4/6 [3/5]
	 OLD:
	// 1  4
	// 2  5
	// 3  6
	*/
	
	speeds[0] = speed + heading;
	speeds[1] = speed + heading;
	speeds[2] = speed + heading;
	
	speeds[5] = speed - heading;
	speeds[4] = speed - heading;
	speeds[3] = speed - heading;
	
	MotorControllerUpdateMotors(speeds);
}
void HandleRoverUpdate(short newSpeed, short newHeading, bool actuate) {
	char linebuf[45];
	int linelen;
	bool sendUpdate = false;
	if(actuate != current_actuate_state){
	  current_actuate_state=actuate;
#ifdef USE_MAIN_BOARD
	  ToggleActuatePacket();
#endif
	}
	if (abs(newSpeed)<JS_OFF) { // stop mode
		speed = 0;
		heading = 0;
#ifdef USE_MAIN_BOARD
		SendSpeedPacket(speed);
#else		
		sendUpdate = true; 
#endif
	}	
	else {
		if (abs(speed - newSpeed) > JS_DELTA_THRESH) {
			speed = newSpeed;
#ifdef USE_MAIN_BOARD
		SendSpeedPacket(speed);
#else		
		sendUpdate = true; 
#endif
		}
		
		if (abs(heading - newHeading) > JS_DELTA_THRESH) {
			heading = newHeading;
#ifdef USE_MAIN_BOARD
		SendHeadingPacket(heading);
#else		
		sendUpdate = true; 
#endif
		}
	}
	
	if (sendUpdate) {
#ifndef USE_MAIN_BOARD

		MotorControllerSetMotors(speed, heading);
		linelen = sprintf(linebuf, "S: %d, H: %d, A: %d\n",speed, heading, isActuated);
		USART_Write(&debugPort, linebuf, linelen);
#endif
	}
}


int main(void) {
	char linebuf[45];
	int linelen;
	volatile uint16_t ADC_result;
	signed short newHeading, newSpeed;
	
	SetupADCs(); // ADC will have settled by the time all the other inits happen
	
	USART_InitPortStructs();
	
	USART_Open(&port, 0, USART_BAUD_38400, 128, 128, true);
	USART_Open(&debugPort, 6, USART_BAUD_38400, 128, 128, true);
	CommInterfaceInit(&inf, &port);
	
	heading = speed = 0;
	newHeading = newSpeed = 0;
	isActuated = false;
	
	while(1) {
		ADC_Ch_Conversion_Start(&ADCA.CH0);
		ADC_Ch_Conversion_Start(&ADCA.CH1);

		while(!ADC_Ch_Conversion_Complete(&ADCA.CH0));
		newHeading = ADC_ResultCh_GetWord_Unsigned(&ADCA.CH0, 0);
		
		while(!ADC_Ch_Conversion_Complete(&ADCA.CH1));
		newSpeed = ADC_ResultCh_GetWord_Unsigned(&ADCA.CH1, 0);
		
		//newSpeed = newHeading;
		//linelen = sprintf(linebuf,"0: %u\n",newHeading);
		//USART_Write(&debugPort, linebuf, linelen);
		
		newSpeed -= 2048;
		newHeading -= 2048;

		newHeading = 0;
		HandleRoverUpdate(newSpeed, newHeading);
		
		_delay_ms(50);
	}
	
	CommDeleteInterface(&inf);
}

