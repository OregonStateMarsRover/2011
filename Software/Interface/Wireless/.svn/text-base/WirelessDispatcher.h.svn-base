/*
 * WirelessDispatcher.h
 *
 * Handles sending and receiving wireless data to and from
 * the rover.
 *
 * Created by Camden Lopez on 11/10/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#ifndef WIRELESSDISPATCHER_H
#define WIRELESSDISPATCHER_H

#include <QObject>
#include <QTimer>
#include <QQueue>
#include "WirelessPacket.h"
#include "SerialProtocol.h"

#include "SerialDevice.h"

class WirelessDispatcher : public QObject
{
    Q_OBJECT
public:
    explicit WirelessDispatcher(QObject *parent = 0);

    /**
      * Opens serial port for wireless dispatcher.
      * \param @device Serial port file name
      *
      */
    void openSerial(QString device);

    /**
     * Closes serial port for wireless dispatcher.
     */
    void closeSerial();

    /**
     * Queues a packet for transmission.
     * \param @pkt Packet to transmit
     */
    void sendMessage(WirelessPacket pkt);

    static WirelessDispatcher * getSystemDispatcher();

    void TransmitPacketComplete();
    void Transmit(SerialData * s, byte data);
    void ReceivePacketComplete (SerialData * s);
    void ReceiveDataError (SerialData * s, byte errCode);

signals:
    /**
     * Emitted when a new wireless packet is received.
     * @param pkt Packet received
     */
    void receivedPacket(WirelessPacket pkt);

public slots:
    void checkSerialData();

private:
    QTimer * serTimer;
    SerialDevice * serDev;

    SerialData serReceiveHandler; // For incomming packets

    // Queue not needed (silly programmers...)
    //QQueue<WirelessPacket> txPktQueue;
    //QTimer * txQueueTimer;

    static WirelessDispatcher * m_instance;

private slots:
    //void sendTxQueue(); // Queue not needed
};

void WirelessDispatch_TransmitPacketComplete(SerialData * s);
void WirelessDispatch_Transmit(SerialData * s, byte data);
void WirelessDispatch_ReceivePacketComplete (SerialData * s);
void WirelessDispatch_ReceiveDataError (SerialData * s, byte errCode);

#endif // WIRELESSDISPATCHER_H
