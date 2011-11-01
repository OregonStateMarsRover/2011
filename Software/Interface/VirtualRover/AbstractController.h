/*
 * AbstractController.h
 *
 * Abstract class for components of the virtual rover.
 *
 * Created by Camden Lopez on 11/23/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#ifndef ABSTRACTCONTROLLER_H
#define ABSTRACTCONTROLLER_H

#include <QObject>

#include "Wireless/WirelessPacket.h"

// this list should be kept in sync with the one in Rover/ProcessManager/ProcessManager.h
#define TARGET_GPS_CONTROLLER 1
#define TARGET_MOTOR_CONTROLLER 2
#define TARGET_TRIPOD_CONTROLLER 3
#define TARGET_ARM_CONTROLLER 10

#define TARGET_GUI 4 // use for generic GUI messages. Use a more specific TARGET_GUI_* module if possible
#define TARGET_TEST_CONTROLLER 5
#define TARGET_GUI_MOTOR 6
#define TARGET_GUI_TRIPOD 7
#define TARGET_GUI_ARM 8
#define TARGET_GUI_GPS 9


class AbstractController : public QObject
{
    Q_OBJECT
public:
    explicit AbstractController(QObject *parent = 0);

    /**
     * Convenience function that sends a wireless packet to the
     * controller's robot device target.
     * @param dat Data to send
     */
    void sendMessage(QByteArray dat);

    /**
     * Sends a wireless message out the serial port.
     * @param msg Wireless message to transmit
     */
    void sendMessage(WirelessPacket msg);

    /**
     * Function called when a wireless message is received
     * for this target device (as defined by return value of guiMessageTarget()).
     * @param msg Message received
     */
    virtual void handleMessage(WirelessPacket msg) = 0;

    virtual int guiMessageTarget() = 0;
    virtual int roverMessageTarget() = 0;

signals:

public slots:


};

#endif // ABSTRACTCONTROLLER_H
