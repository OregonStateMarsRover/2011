/*
 * WirelessDispatch.cpp
 *
 * Created by Camden Lopez on 11/10/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#include <QDebug>
#include "SerialProtocol.h"
#include "WirelessDispatcher.h"

WirelessDispatcher * WirelessDispatcher::m_instance = 0;

WirelessDispatcher::WirelessDispatcher(QObject *parent) : QObject(parent)
{
    m_instance = this;
    serDev = 0;

    serTimer = new QTimer(this);
    serTimer->setInterval(10);
    connect(serTimer, SIGNAL(timeout()), this, SLOT(checkSerialData()));

    // Setup the receive serial structure
    SerialDataInitialize(&serReceiveHandler);
    // Don't need the transmission related function pointers
    //serDataHandler.TransmitPacketComplete = &WirelessDispatch_TransmitPacketComplete;
    //serDataHandler.Transmit = &WirelessDispatch_Transmit;
    serReceiveHandler.ReceivePacketComplete = &WirelessDispatch_ReceivePacketComplete;
    serReceiveHandler.ReceiveDataError = &WirelessDispatch_ReceiveDataError;
}

WirelessDispatcher * WirelessDispatcher::getSystemDispatcher()
{
    return m_instance;
}

void WirelessDispatcher::openSerial(QString device)
{
    if (serDev!=0)
    {
        // have a serial device already open, close it first
    }

    serDev = new SerialDevice(device, 115200);
    //serDev = new SerialDevice(device, 38400);
    serTimer->start();
}

// Called from time to time to read data from the serial port
// TODO: Move to a blocking read on another thread.
void WirelessDispatcher::checkSerialData()
{
    serTimer->stop();
    if (serDev->numBytesAvailable()>0) {
        char data[100]; // read at most 100 bytes at a time
        int len = serDev->readData(data, 100);
        while (len>0) {
            int i;
            for (i=0;i<len;i++) {
                ProcessDataChar(&serReceiveHandler, data[i]);
            }

            len = serDev->numBytesAvailable();
            if (len>0) {
                len = serDev->readData(data, 100); // try to read more if there's more data available
                qDebug()<<len<<"bytes more available";
            }
        }
    }
    serTimer->start();
}

// Send a packet out over the wireless interface
void WirelessDispatcher::sendMessage(WirelessPacket pkt)
{
    // Setup the serial transfer structure
    SerialData txData;
    SerialDataInitialize(&txData);
    txData.Transmit = &WirelessDispatch_Transmit;
    // Could hook up to transmit complete callback, but there's no need right now.
    //txData.TransmitPacketComplete = &WirelessDispatch_TransmitPacketComplete;
    memcpy(txData.transmit_data, pkt.data().data(), pkt.data().length());

    if (SerialTransmit(&txData, pkt.target(), pkt.data().length())!=0)
    {
        qWarning() << "failed to queue packet for transmission";
    }

    // Keep transmitting - the serial port will store the data in a buffer.
    while (SerialTransferInProgress(&txData))
    {
        SerialByteTransmitComplete(&txData);
    }
}

// Whee, a packet is transferred!
// (but only if it's hooked up - see comment in sendMessage(WirelessPacket pkt)
void WirelessDispatcher::TransmitPacketComplete()
{
}

// Write the byte to the serial port
void WirelessDispatcher::Transmit(SerialData * s, byte data)
{
    serDev->writeChar(data);
}

// We've got a packet from the rover - pass it to whoever's interested.
void WirelessDispatcher::ReceivePacketComplete (SerialData * s)
{
    QByteArray dat((const char *)s->receive_data, s->receive_data_count);
    WirelessPacket pkt(s->receive_address, dat);
    emit receivedPacket(pkt);
}

// Ah junk...
void WirelessDispatcher::ReceiveDataError (SerialData * s, byte errCode)
{
    qWarning() << "had error"<<errCode<<"during RX";
}

// These guys allow for easy function pointers and direct the call to the proper instance of WirelessDispatch.
void WirelessDispatch_TransmitPacketComplete(SerialData * s)
{
    WirelessDispatcher::getSystemDispatcher()->TransmitPacketComplete();
}

void WirelessDispatch_Transmit(SerialData * s, byte data)
{
    WirelessDispatcher::getSystemDispatcher()->Transmit(s, data);
}

void WirelessDispatch_ReceivePacketComplete (SerialData * s)
{
    WirelessDispatcher::getSystemDispatcher()->ReceivePacketComplete(s);
}

void WirelessDispatch_ReceiveDataError (SerialData * s, byte errCode)
{
    WirelessDispatcher::getSystemDispatcher()->ReceiveDataError(s, errCode);
}
