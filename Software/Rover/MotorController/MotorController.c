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

/*BogieData Bogies[6];*/

void MotorControllerInit(){
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


    char dat[10];
    
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
    	dat[0] = 'M';

    	dat[1]=pkt->data[1];
    	dat[2]=pkt->data[2];
		CommPacket respPkt;
        respPkt.target = TARGET_GUI;
        respPkt.length = 3;
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
void MotorControllerTick(Rover * rov){

    /*Send message to each wheel (one at a time) to ask for wheel position and speed
    if message sent back wheel still okay*/
}

