/*
Process Flow
Bold indicates your part

Movement

	Message will be created at base station (1 byte for wheel position, 1 byte for velocity, so 2 bytes for each wheel)
	Message will be send to rover mainboard
	Message will be rerouted to MotorController.c
	Message parsed in HandleMessage and created into 6 messages of 2 bytes (1 byte for wheel position, 1 byte for velocity)
	Messages will be sent 1 at a time, each time waiting for an ack message
	Message will parsed by daugtherboard and wheels set to the settings

Status update

	Every tick, message will be sent to each board requesting status update
	Daugther board will send message back of position and velocity
	Message will be recieved by mainboard and rerouted MotorController.c
	Message will be parsed and results stored.
	Base station will request motor status by message
	Message will be recieved by mainboard and rerouted MotorController.c
	Message will be parsed
	Message created of all saved status and sent back to base station


Functions
*/

#include <stdio.h>
#include <string.h>

#include "MotorController.h"
#include "../ProcessManager/ProcessManager.h"
#include "Timer.h"

//6 Bogie structs that hold 2 bytes each (pos, vel)
BogieData Bogies[6]; //One Position, One Velocity
int currentBogie;
int waitingForReply;
unsigned short timeoutCounter;
Timer pingTimer;

void MotorControllerInit(){

	currentBogie = 0;
	timeoutCounter = 0;

	for(int i = 0; i < 6; i++){
		Bogies[i].position = 0;
		Bogies[i].velocity = 0;
		Bogies[i].currentPosition = 0;
		Bogies[i].currentVelocity = 0;
	}
	StartTimer(&pingTimer);

	USART_Open(&motorController.rbogPort, 2, MOTOR_CONTROLLER_BAUD, 10, 10, true, true);
	USART_Open(&motorController.lbogPort, 4, MOTOR_CONTROLLER_BAUD, 10, 10, true, true);
	USART_Open(&motorController.bbogPort, 3, MOTOR_CONTROLLER_BAUD, 10, 10, true, true);
	
	CommInterfaceInit(&motorController.rbog, &motorController.rbogPort);
	CommInterfaceInit(&motorController.lbog, &motorController.lbogPort);
	CommInterfaceInit(&motorController.bbog, &motorController.bbogPort);

	//PacketQueueInit2()
}
void MotorControllerHandleMessage(Rover * rov, CommPacket * pkt){

	/*Determine (parse) message type
	Preform action depending on message type
		Movement - Split message into 6 message to send to each daugtherboard
		Request status - Send message of motor status to base station
		status report - Save status data from wheel*/


	char dat[20];
	
	if (pkt->data[0]=='T') { // timing packet
		dat[0]='T';
		dat[1]=pkt->data[1];
		dat[2]=pkt->data[2];
		
		CommPacket respPkt;
		respPkt.target = TARGET_GUI;
		respPkt.length = 3;
		respPkt.data = dat;
		SendMessage(rov,&respPkt);
	}else if(pkt->data[0]=='M'){ //movement packet
		
		//just packaging
		int c = 1; //Counts so that you increment through the pkt->data array
		for(int i = 0; i < 6; i++){
			Bogies[i].position = pkt->data[c];
			c++;
			Bogies[i].velocity = pkt->data[c];
			c++;
		}
		
	}else if(pkt->data[0]=='D'){ // request data
		dat[0] = 'D'
		c = 1;
		for(int i = 0; i < 6; i++){
			dat[c] = Bogies[i].currentPosition;
			c++;
			dat[c] = Bogies[i].currentVelocity;
			c++;
		}
		
		CommPacket respPkt;
		respPkt.target = TARGET_GUI;
		respPkt.length = 13;
		respPkt.data = dat;
		SendMessage(rov,&respPkt);

	}else{
		dat[0]='M';
		dat[1]='O';
		dat[2]='T';
		dat[3]='O';
		dat[4]='R';
	
		dat[5]=pkt->data[0];
		dat[6]=pkt->data[1];
		dat[7]=pkt->data[2];
	
		CommPacket respPkt;
		respPkt.target = TARGET_GUI;
		respPkt.length = 8;
		respPkt.data = dat;
		SendMessage(rov,&respPkt);
	}
}

void SendBogieData(bogie_index){
	char dat[3];
	dat[0] = 'D';
	dat[1] = Bogies[bogie_index].position;
	dat[2] = Bogies[bogie_index].velocity;

	CommPacket respPkt;
	respPkt.target = bogie_index;
	respPkt.length = 3;
	respPkt.data = dat;

	/* testing */
	SendMessage(rov,&respPkt);

	/*
	CommSendPacket(&motorController.rbogPort, &respPkt);
	CommSendPacket(&motorController.lbogPort, &respPkt);
	CommSendPacket(&motorController.bbogPort, &respPkt);
	*/
}


void MotorControllerTick(Rover * rov){

	if(waitingForReply == 0){ // not waiting for bogie reply so send message
		SendBogieData(currentBogie);
	}else if(waitingForReply == 1){ //waiting
		if (GetSpanUs(&pingTimer) > FROM_uS(1000000)) { //passed timeout
			//currentBogie not working
			
			char dat[2];
			dat[0] = 'Z';
			dat[1] = currentBogie;

			CommPacket respPkt;
			respPkt.target = TARGET_GUI;
			respPkt.length = 2;
			respPkt.data = dat;
			SendMessage(rov,&respPkt);

			//set data so next message will be sent
			waitingForReply = 0;
			currentBogie++;
			if (currentBogie >= 6) {
				currentBogie = 0;
			}
		}
	}

	recieveMessage(); // see if message is ready to recieve	
}

void recieveMessage(){
	
	CommPacket commPkt;
	unsigned char data[20];
	commPkt.data=data;
	char ret;

	if (CommRXPacketsAvailable(&motorController.rbogPort)) { // got message
		CommGetPacket(&motorController.rbogPort, &commPkt, 20);


		Bogies[currentBogie].currentPosition = commPkt.data[0];
		Bogies[currentBogie].currentVelocity = commPkt.data[1];

		waitingForReply = 0;
		currentBogie++;
		if (currentBogie >= 6) {
			currentBogie = 0;
		}
		
	}

}