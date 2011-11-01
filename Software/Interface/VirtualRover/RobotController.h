/*
 * Author: Taj Morton
 * Date: March 18, 2011
 * Desc: Singleton class for all rover devices the GUI controls.
 *
 * Copyright (c) 2011 OSURC.
 */

#ifndef ROBOTCONTROLLER_H
#define ROBOTCONTROLLER_H

#include <QObject>
#include <QMap>

#include "ArmController.h"
#include "TripodController.h"
#include "MotorController.h"
#include "SensorController.h"
#include "GPSController.h"
#include "StatusController.h"

#include "Wireless/WirelessDispatcher.h"

#define MOTOR_COUNT_TO_AMPS_FACTOR 0.01220703 // multiply ADC count by this value

class RobotController : public QObject
{
    Q_OBJECT
public:
    explicit RobotController(QObject *parent = 0);

    static RobotController * instance();

    void _sendMessage(WirelessPacket & pkt);
    static void sendMessage(WirelessPacket & pkt) {
        instance()->_sendMessage(pkt);
    }

    ArmController * _armController();
    static ArmController * armController() {
        return instance()->_armController();
    }

    MotorController * _motorController();
    static MotorController * motorController() {
        return instance()->_motorController();
    }

    GPSController * _gpsController();
    static GPSController * gpsController() {
        return instance()->_gpsController();
    }

    StatusController * _statusController();
    static StatusController * statusController() {
        return instance()->_statusController();
    }

    TripodController * _tripodController();
    static TripodController * tripodController() {
        return instance()->_tripodController();
    }

signals:

public slots:
    void sendWirelessPacket(WirelessPacket pkt);

private slots:
    void processWirelessPacket(WirelessPacket pkt);

private:
    static RobotController * m_instance;

    WirelessDispatcher * dispatcher;
    GPSController * m_gpsController;
    ArmController * m_armController;
    MotorController * m_motorController;
    TripodController * m_tripodController;
    StatusController * m_statusController;

    QMap<int, AbstractController*> deviceMap;

    void addController(AbstractController * dev);

};

#endif // ROBOTCONTROLLER_H
