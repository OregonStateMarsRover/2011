/******************************************************
 * Implements a packet-based communication interface
 * for sending/receiving serial data.
 *
 * Copyright (C) OSURC 2010-2011.
 ******************************************************/

#include <string.h>
#include <stdlib.h>

#ifndef X86GCC
#include <avr/interrupt.h>
#endif

#include "CommInterface.h"

void CommInterfaceInit(CommInterface * inf, USART * serPort) {
	inf->port = serPort;
	
	SerialDataInitialize(&(inf->serData));
	
	inf->serData.TransmitPacketComplete = NULL; // no need to know when a packet has been en-queued
	inf->serData.Transmit = &CommQueueForTx;
	inf->serData.ReceivePacketComplete = &CommPacketReceived;
	inf->serData.ReceiveDataError = &CommReceiveDataError;
	inf->serData.ref = inf;
	
	inf->ReceivePacketComplete = NULL;
	inf->rx_pkts_queued = 0;
	inf->firstRX = 0;
	inf->lastRX = 0;
	
	inf->rcvdPacket.data=inf->rcvdData;
	inf->hasRcvdPacket = 0;
	
	#ifndef X86GCC
	inf->port->CharacterReceived = &CommByteReceived;
	inf->port->ref = inf;
	#endif
}

void CommInterfaceSetRXCallback(CommInterface * inf, void (*func)()) {
	inf->ReceivePacketComplete = func;
}

bool CommSendPacket(CommInterface * inf, CommPacket * pkt) {
	unsigned char length = pkt->length;
	
	if (SerialTransferInProgress(&inf->serData))
		return false;
	//while(SerialTransferInProgress(&inf->serData)); // wait until any previous packet has finished being queued for transmission
	
	if (length > SERIAL_TRANSMIT_BUFFER_SIZE) // TODO: Dynamically size SerialProtocol.transmit_data so we don't have this mysterious 20 byte max packet size
		length = SERIAL_TRANSMIT_BUFFER_SIZE;
	memcpy(inf->serData.transmit_data, pkt->data, length);

	if (SerialTransmit(&inf->serData, pkt->target, length)==0)
		return true;
	else
		return false;
}

char CommGetPacket(CommInterface * inf, CommPacket * pkt, unsigned char maxbuflen) {
	char ret;
	CommPacket * newFirst;
	
	#ifndef X86GCC
	//cli();
	#endif
	
	if (!inf->hasRcvdPacket) { // no packet in buffer to transmit
		return 0;
	}
	
	pkt->target = inf->rcvdPacket.target;
	
	if (inf->rcvdPacket.length > maxbuflen) {
		pkt->length = maxbuflen;
	}
	else {
		pkt->length = inf->rcvdPacket.length;
	}
	
	memcpy(pkt->data, inf->rcvdPacket.data, pkt->length);

	inf->hasRcvdPacket = 0;
	
	//sei();
	return 1;
}

char CommPeekPacket(CommInterface * inf, CommPacket * pkt, unsigned char maxbuflen) {
	CommPacket * newFirst;
	
	if (inf->firstRX==0)
		return 0;
	
	//pkt = (CommPacket*)malloc(sizeof(CommPacket));
	
	/*if (!pkt) { // failed to alloc memory for this copy of the packet - bail
		return 0;
	}*/
	
	pkt->target = inf->firstRX->target;
	
	if (inf->firstRX->length > maxbuflen) {
		inf->firstRX->length = maxbuflen;
	}
	else {
		pkt->length = inf->firstRX->length;
	}
	
	//pkt->data = (unsigned char*)malloc(sizeof(unsigned char)*pkt->length);
	
	/*if (pkt->data==0) {
		free(pkt);
		return 0;
	}*/
	
	memcpy(pkt->data, inf->firstRX->data, pkt->length);
	
	return 1;
}

unsigned int CommRXPacketsAvailable(CommInterface * inf) {
return inf->hasRcvdPacket;
	return inf->rx_pkts_queued;
}

void CommDeletePacket(CommPacket * pkt) {
	if (!pkt)
		return;
	
	pkt->target = 0;
	pkt->length = 0;

	if (pkt->data)
		free(pkt->data);
	
	pkt->data = 0;
}

void CommDeleteInterface(CommInterface * inf) {
	CommPacket *nextPkt;
	CommPacket * cur;
	nextPkt = inf->firstRX;
	while(nextPkt) {
		cur = nextPkt;
		nextPkt = nextPkt->next;
		CommDeletePacket(cur);
		free(cur);
	}
}

void CommByteReceived(USART * port) {
	ProcessDataChar(&(((CommInterface*)(port->ref))->serData), USART_ReadByte(port));
}

void CommQueueForTx(SerialData * ser, unsigned char data) {
	#ifdef X86GCC
	ProcessDataChar(ser, data);
	#else
	USART_WriteByte(((CommInterface*)(ser->ref))->port, data);
	#endif
	SerialByteTransmitComplete(ser); // byte successfully queued for transmission - get the next one
}

void CommPacketReceived(SerialData * ser) {
	CommPacket * pkt;
	CommInterface* inf;
	
	inf = (CommInterface*)ser->ref;
	if (inf->hasRcvdPacket) { // if there's already a packet in the queue, drop this new one
		return;
	}
	
	inf->rcvdPacket.target = ser->receive_address;
	inf->rcvdPacket.length = ser->receive_data_count;
	memcpy(inf->rcvdPacket.data, ser->receive_data, inf->rcvdPacket.length);
	
	inf->hasRcvdPacket = 1;
	
	if (inf->ReceivePacketComplete) {
		inf->ReceivePacketComplete(inf);
	}
	return;
}

void CommReceiveDataError(SerialData * ser, unsigned char errCode) {
//	printf("Comm err %d\n", errCode);
}


