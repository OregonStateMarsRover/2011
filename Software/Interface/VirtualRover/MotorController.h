/*
 * DriveController.h
 *
 * Provides an interface between the wireless communication
 * with the rover and the GUI and tactile devices in regards
 * to driving the rover.
 *
 * Created by Camden Lopez on 11/10/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#ifndef DRIVECONTROLLER_H
#define DRIVECONTROLLER_H

#include <QTimer>

#include "Tactile/Joystick.h"
#include "AbstractController.h"

#define MOTOR_DEAD_BAND 100
#define MOTOR_STOP_RANGE 100

#define JOYSTICK_MAX_RANGE 32768-JOYSTICK_STOP_RANGE
#define MOTOR_MAX_SPEED_RANGE 1500
#define MOTOR_MAX_STRAFE_RANGE 250

class MotorController : public AbstractController
{
    Q_OBJECT
public:
    explicit MotorController(QObject *parent = 0);

    virtual void handleMessage(WirelessPacket msg);

    virtual int guiMessageTarget();
    virtual int roverMessageTarget();

    void setSpeed(short speed, bool forceUpdate = false);
    void setHeading(short heading);

    bool toggleActuators();
    void setActuators(bool actuated);

    void setStrafeX(short x);
    void setStrafeY(short y);
    void setStrafeRot(short rot);
    void setStrafe(short x, short y, short rot);

    void eStop();

    void sendPassThru(unsigned char id, QByteArray data);

    void enableWatchdog(bool enabled);

    void setMotorSpeedDivision(float divisor);
    void setMotorDirectionDivision(float divisor);

    void setMotorStallCurrent(unsigned short milliamps);
signals:
    void hadWatchdogTimeout(bool timedOut);
    void gotStatusPacket(QByteArray msg);
    void gotPassThrough(QByteArray dat);
    void gotTimeoutPacket(QByteArray msg);
    void gotCurrentPacket(QByteArray dat);

public slots:
    void toggleMosfets();
    void setMosfets(bool disabled);
    void setPWMMode(bool enablePWM);
    void setExponentialCurve(bool useCurve);
    void requestCurrentData();
    void setCornerMosfets(bool disabled);

    void setRoverInStrafe(bool inStrafe);

    void setGlobalMotorScaler(float scale);

private slots:
    void sendWatchdogUpdate();
    void runActuatorStateRunner();

private:
    enum ActuatorStateMachineState {
        ActuatorsSendingNothing,
        ActuatorsSendingDisableMosfets,
        ActuatorsSendingActuatorMotion,
        ActuatorsSendingEnableMosfets
    };

    bool inStrafeMode;
    bool inStopMode;
    short lastSpeed, lastHeading;
    short lastX, lastY, lastRot;
    bool watchdogEnabled;
    bool mosfetsDisabled;
    ActuatorStateMachineState actuatorState;
    bool useExponentialCurve;

    short lastRoverSpeed, lastRoverHeading;

    float motorScaler;
    QTimer * watchdogTimer;
    QTimer * actuatorStateRunner;
    QByteArray actuatorCommand;

    /**
     * Scales jsVal to be in the range of the speeds
     * expected by the rover (-1500 - 1500)
     * jsVal is expected to have its min/max between
     * the min/max values of a signed short (-32768 - 32767)
     */
    short scaleToMotorVal(short jsVal);

    signed short scaleMotorValueSigned(short val, short maxVal, double scaleFactor);

    void sendRoverSpeedHeading(short speed, short heading);

};

#endif // DRIVECONTROLLER_H
