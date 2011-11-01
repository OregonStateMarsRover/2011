/*
 * DriveController.cpp
 *
 * Created by Camden Lopez on 11/10/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#include <QDebug>
#include <QSettings>
#include <QFile>
#include "MotorController.h"
#include "Tactile/TactileInterface.h"

#include <math.h>

MotorController::MotorController(QObject *parent) : AbstractController(parent)
{
    lastSpeed = lastHeading = 0;
    lastRoverSpeed = lastRoverHeading = 0;
    lastX = lastY = lastRot = 0;

    motorScaler = 1;

    inStopMode = false;
    inStrafeMode = false;
    watchdogEnabled = true;
    mosfetsDisabled = false;
    actuatorState = ActuatorsSendingNothing;
    useExponentialCurve = true;

    watchdogTimer = new QTimer(this);
    watchdogTimer->setInterval(1000);
    connect(watchdogTimer, SIGNAL(timeout()), this, SLOT(sendWatchdogUpdate()));

    actuatorStateRunner = new QTimer(this);
    actuatorStateRunner->setInterval(250);
    connect(actuatorStateRunner, SIGNAL(timeout()), this, SLOT(runActuatorStateRunner()));

    /*int i;
    QFile scaleFile("scaleFile1x.txt");
    scaleFile.open(QIODevice::WriteOnly);

    for (i=-32767; i<=32767; i++) {
        scaleFile.write(qPrintable(QString::number(i)+","+QString::number(scaleMotorValueSigned(i, MOTOR_MAX_SPEED_RANGE, 1.0))+"\n"));
    }
    scaleFile.close();

    QFile scaleFile2x("scaleFile2x.txt");
    scaleFile2x.open(QIODevice::WriteOnly);

    for (i=-(JOYSTICK_MAX_RANGE); i<=JOYSTICK_MAX_RANGE; i++) {
        scaleFile2x.write(qPrintable(QString::number(i)+","+QString::number(scaleMotorValueSigned(i, MOTOR_MAX_SPEED_RANGE, 3.0))+"\n"));
        //scaleToMotorVal(i);
    }
   scaleFile2x.close();*/
}


void MotorController::handleMessage(WirelessPacket msg) {
    if (msg.data().length()<1)
        return;
    if ((unsigned char)msg.data().at(0)==0xFE) {
        qDebug() << "got watchdog timeout:"<<msg.data().toHex();
        emit hadWatchdogTimeout(true);
    }
    else if ((unsigned char)msg.data().at(0)==0xFD) {
        qDebug() << "got status packet"<<msg.data().toHex().constData();
        emit gotStatusPacket(msg.data());
    }
    else if ((unsigned char)msg.data().at(0)==0xFC) {
        qDebug() << "passthrough rx'd";
    }
    else if ((unsigned char)msg.data().at(0)==0xFB) {
        emit gotTimeoutPacket(msg.data());
    }
    else if ((unsigned char)msg.data().at(0)==0xF9) {
        qDebug() << "got current data";
        emit gotCurrentPacket(msg.data());
    }
    else {
        qDebug() << "got message"<<msg.data().toHex().constData();
        emit gotPassThrough(msg.data());
    }
}

int MotorController::guiMessageTarget() {
    return TARGET_GUI_MOTOR;
}

int MotorController::roverMessageTarget() {
    return TARGET_MOTOR_CONTROLLER;
}

void MotorController::setSpeed(short speed, bool forceUpdate) {
    QSettings set;

    double scaleFactor = set.value("speedScaleExponent").toDouble();
    QByteArray speedCmd("\x02");

    if (inStopMode) { // if we're in stop mode, don't send another speed update until we hit the 0 range
        if (abs(speed)<MOTOR_STOP_RANGE)
            inStopMode = false;
        else
            return;
    }

    if (abs(speed-lastSpeed)<MOTOR_DEAD_BAND && forceUpdate==false) {
        lastSpeed=0;
        return;
    }

    lastSpeed = speed;
    short roverSpeed;

    if (useExponentialCurve)
        roverSpeed = scaleMotorValueSigned(speed, MOTOR_MAX_SPEED_RANGE*motorScaler, scaleFactor);
    else
        roverSpeed = scaleToMotorVal(speed/scaleFactor);

    lastRoverSpeed = roverSpeed;
    qDebug()<<"SPEED:"<<speed<<"rover speed:"<<roverSpeed;
    /*speedCmd.append((char)((roverSpeed>>8) & 0xFF));
    speedCmd.append((char)(roverSpeed & 0xFF));
    sendMessage(speedCmd);

    if (roverSpeed==0) { // if we're stopped, resend 2 more times
        sendMessage(speedCmd);
        sendMessage(speedCmd);
    }

    qDebug()<<"sending:"<<speedCmd.toHex();*/
    sendRoverSpeedHeading(lastRoverSpeed, lastRoverHeading);
    if (lastRoverHeading==0 || lastSpeed==0) {
        sendRoverSpeedHeading(lastRoverSpeed, lastRoverHeading);
        sendRoverSpeedHeading(lastRoverSpeed, lastRoverHeading);
    }

    inStrafeMode = false;
    watchdogTimer->start();
    hadWatchdogTimeout(false);
}

void MotorController::setHeading(short heading){
    QByteArray headingCmd("\x03");
    QSettings set;
    double scaleFactor = set.value("directionScaleExponent").toDouble();

    if (inStopMode) { // if we're in stop mode, don't send another speed update until we hit the 0 range
        if (abs(heading)<MOTOR_STOP_RANGE)
            inStopMode = false;
        else
            return;
    }

    if (abs(heading-lastHeading)<MOTOR_DEAD_BAND) {
        lastHeading=0;
        return;
    }

    heading = heading/set.value("directionPrimaryDivisor", 1.0).toDouble();
    qDebug()<<"HEADING:"<<heading;
    lastHeading = heading;

    short roverHeading;
    if (useExponentialCurve) {
        roverHeading = scaleMotorValueSigned(heading, MOTOR_MAX_SPEED_RANGE*motorScaler, scaleFactor);
    }
    else {
        roverHeading = scaleToMotorVal(heading/scaleFactor);
    }
    lastRoverHeading = roverHeading;
    /*headingCmd.append((char)((roverHeading>>8) & 0xFF));
    headingCmd.append((char)(roverHeading & 0xFF));
    sendMessage(headingCmd);

    if (roverHeading==0) { // if we're stopped, resend 2 more times
        sendMessage(headingCmd);
        sendMessage(headingCmd);
    }*/
    sendRoverSpeedHeading(lastRoverSpeed, lastRoverHeading);
    if (roverHeading==0 || lastSpeed==0) {
        sendRoverSpeedHeading(lastRoverSpeed, lastRoverHeading);
        sendRoverSpeedHeading(lastRoverSpeed, lastRoverHeading);
    }

    inStrafeMode = false;
    watchdogTimer->start();
    hadWatchdogTimeout(false);
}

void MotorController::sendRoverSpeedHeading(short speed, short heading) {
    QByteArray command;
    command.append((char)17);

    command.append((char)(lastRoverSpeed>>8) & 0xFF);
    command.append((char)(lastRoverSpeed & 0xFF));

    command.append((char)(lastRoverHeading>>8) & 0xFF);
    command.append((char)(lastRoverHeading & 0xFF));

    sendMessage(command);
}

bool MotorController::toggleActuators() {
    if ((inStrafeMode && (lastX!=0 || lastY!=0 || lastRot!=0)) || (!inStrafeMode && (lastSpeed!=0 || lastHeading!=0))) {
        qDebug() << "speed not zero! not actuating!"<<lastSpeed<<lastHeading;
        return false;
    }
    if (actuatorStateRunner->isActive()) {
        qDebug() << "actuator command already running";
    }

    QByteArray toggleCmd("\x01");
    actuatorCommand = toggleCmd;

    setCornerMosfets(true);
    actuatorState = ActuatorsSendingDisableMosfets;
    actuatorStateRunner->start();
    return true;
}

void MotorController::setActuators(bool actuated) {
    QByteArray actuatorCmd("\x07");
    actuatorCmd.append(actuated);

    if (actuatorStateRunner->isActive()) {
        qDebug() << "actuator command already running";
    }

    actuatorCommand = actuatorCmd;

    setMosfets(true);
    actuatorState = ActuatorsSendingDisableMosfets;
    actuatorStateRunner->start();
}

void MotorController::setStrafeX(short x) {
    lastX = x;
    setStrafe(lastX, lastY, lastRot);
}

void MotorController::setStrafeY(short y) {
    lastY = y;
    setStrafe(lastX, lastY, lastRot);
}

void MotorController::setStrafeRot(short rot) {
    lastRot = rot;
    setStrafe(lastX, lastY, lastRot);
}

void MotorController::setExponentialCurve(bool useCurve) {
    useExponentialCurve = useCurve;
}

void MotorController::setRoverInStrafe(bool inStrafe) {
    inStrafeMode = inStrafe;
    TactileInterface::setInStrafeMode(inStrafe);
}

void MotorController::setGlobalMotorScaler(float scale) {
    if (scale>1) {
        scale=0;
    }
    else if (scale<0) {
        scale=0;
    }
    motorScaler = scale;
}

void MotorController::requestCurrentData() {
    QByteArray dat;
    dat.append(15);
    sendMessage(dat);
    qDebug() << "sending current req";
}

void MotorController::sendPassThru(unsigned char id, QByteArray data) {
    data.prepend((char)id & 0xFF);
    data.prepend("\x08"); // pass-thru
    sendMessage(data);

    qDebug() << "sending"<<data.toHex();
}

void MotorController::toggleMosfets() {
    mosfetsDisabled = !mosfetsDisabled;
    setMosfets(mosfetsDisabled);
}

void MotorController::setMosfets(bool disabled) {
    qDebug() << "setting mosfets disabled:"<<disabled;
    QByteArray msg;
    msg.append("\x0A");
    msg.append((char)disabled);
    sendMessage(msg);
}

void MotorController::setCornerMosfets(bool disabled) {
    qDebug() << "setting corner mosfets disabled:"<<disabled;
    QByteArray msg;
    msg.append(16);
    msg.append((char)disabled);
    sendMessage(msg);
}

void MotorController::setPWMMode(bool enablePWM) {
    qDebug() << "toggling PWM to"<<enablePWM;
    QByteArray msg;
    msg.append("\x0B");
    msg.append((char)enablePWM);
    sendMessage(msg);
}

void MotorController::setMotorStallCurrent(unsigned short milliamps) {
    qDebug() << "setting stall current to"<<milliamps;
    QByteArray msg;
    msg.append(13);
    msg.append((milliamps>>8) & 0xFF);
    msg.append(milliamps & 0xFF);
    sendMessage(msg);
}

void MotorController::enableWatchdog(bool enabled) {
    watchdogEnabled = enabled;
}

void MotorController::setStrafe(short x, short y, short rot) {
    QSettings set;
    short speeds[6];
    int i=0;

    if (inStopMode) {
        if (x<MOTOR_STOP_RANGE && y<MOTOR_STOP_RANGE && rot<MOTOR_STOP_RANGE) {
            inStopMode=false;
        }
        else { // leave stop mode when all axes are zeroed
            return;
        }
    }

    inStrafeMode = true;
    watchdogTimer->start();
    hadWatchdogTimeout(false);

    float L1 = 1;
    float L2 = 0.56699f;
    float L3 = 0.67709;

    // make these rover sized numbers
    //x = scaleToMotorVal(x);
    //y = scaleToMotorVal(y);
    //rot = scaleToMotorVal(rot);
    if (useExponentialCurve) {
        x = scaleMotorValueSigned(x, MOTOR_MAX_SPEED_RANGE, set.value("speedScaleExponent").toDouble()); // scale these by the exponential curve
        y = scaleMotorValueSigned(y, MOTOR_MAX_SPEED_RANGE, set.value("speedScaleExponent").toDouble());
        rot = scaleMotorValueSigned(rot, MOTOR_MAX_SPEED_RANGE, set.value("directionScaleExponent").toDouble());
    }
    else {
        x = scaleToMotorVal(x/set.value("speedScaleExponent").toDouble());
        y = scaleToMotorVal(y/set.value("speedScaleExponent").toDouble());
        rot = scaleToMotorVal(rot/set.value("speedScaleExponent").toDouble());

    }

    qDebug()<<"Strafeing to ("<<x<<","<<y<<","<<rot<<")";

    speeds[0] = y * L1 + x + L1 * rot;
    speeds[1] = y * L2 + 0  + L3 * rot;
    speeds[2] = y * L1 - x + L1 * rot;

    speeds[3] = y * L1 + x - L1 * rot;
    speeds[4] = y * L2 + 0  - L3 * rot;
    speeds[5] = y * L1 - x - L1 * rot;

    // now go through and find the max value. if it's >500 (the max we want to go), rescale
    float max =0;
    for (i=0;i<6;i++) {
        if (fabs(speeds[i])>max)
            max = fabs(speeds[i]);
    }
    if (max>MOTOR_MAX_STRAFE_RANGE*motorScaler) {
        for (i=0;i<6;i++) {
            speeds[i]=speeds[i]*(float)(MOTOR_MAX_STRAFE_RANGE*motorScaler)/max;
        }
    }

    QByteArray strafeCmd("\x07");

    qDebug() << "speeds: ["<<speeds[0]<<speeds[1]<<speeds[2]<<speeds[3]<<speeds[4]<<speeds[5]<<"]";
    for (i=0;i<6;i++) {
        strafeCmd.append((char)(speeds[i]>>8 & 0xFF));
        strafeCmd.append((char)(speeds[i] & 0xFF));
    }
    sendMessage(strafeCmd);
}

void MotorController::eStop() {
    QByteArray eStopCmd("\x05");

    inStopMode = true; // once we have entered stop mode, do not send another speed update until the joystick has been zeroed
    lastSpeed = 0;
    lastHeading = 0;
    lastX = lastY = lastRot = 0;

    sendMessage(eStopCmd); // send this 3 times just for good measure
    sendMessage(eStopCmd);
    sendMessage(eStopCmd);

    qDebug() << "ESTOP!!!";
}

short MotorController::scaleToMotorVal(short jsVal) {
    int scaleVal = (JOYSTICK_MAX_RANGE)/MOTOR_MAX_SPEED_RANGE;

    int scaled= jsVal/scaleVal;

    qDebug("linscaled: %d",scaled);
    if (scaled>1499)
        scaled=1499;
    if(scaled<-1499)
        scaled=-1499;
    return scaled;
}

signed short MotorController::scaleMotorValueSigned(short val, short maxOutVal, double scaleFactor) {
        signed short scaledVal;
        double translatedVal;

        if (scaleFactor>-0.00001&&scaleFactor<0.00001) { // no value, default to 1.0 so we don't just not move
            scaleFactor = 1.0;
        }
        double scaleVal = pow(JOYSTICK_MAX_RANGE,scaleFactor)/(double)maxOutVal;
        //qDebug() << "scaleVal"<<scaleVal<<"max pow factor"<<pow(JOYSTICK_MAX_RANGE,scaleFactor);

        if (val>0) {
                translatedVal = pow(val,scaleFactor);
        }
        else {
                translatedVal = pow(val*-1,scaleFactor);
                translatedVal=translatedVal*-1;
        }

        translatedVal = (translatedVal/scaleVal);
        qDebug("Translaaated val: %f",translatedVal);
        if (translatedVal<-maxOutVal)
                scaledVal = -maxOutVal;
        else if (translatedVal>maxOutVal)
                scaledVal = maxOutVal;
        else
                scaledVal = translatedVal;

        qDebug("Scaled: %d",scaledVal);
        return scaledVal;
}

void MotorController::runActuatorStateRunner() {
    if (actuatorState==ActuatorsSendingDisableMosfets) { // send actuator command
        actuatorState=ActuatorsSendingActuatorMotion;
        qDebug() << "sending actuator msg";
        sendMessage(actuatorCommand);
    }
    else if (actuatorState==ActuatorsSendingActuatorMotion) { // send re-enable mosfets, disable timer
        actuatorState = ActuatorsSendingDisableMosfets;
        setCornerMosfets(false);
        actuatorStateRunner->stop();
        qDebug() << "sending corner mosfet enable";
    }
}

void MotorController::sendWatchdogUpdate() {
    //qDebug("sending watchdog update");

    if (watchdogEnabled) {
        //if (actuatorStateRunner->isActive()) {
            QByteArray resetWd("\x0c"); // reset wd timer
            sendMessage(resetWd);
            qDebug() << "sent ping cmd";
            return;
//        /}

        if (inStopMode) {
            eStop(); // stop!
            return;
        }

        if (inStrafeMode) {
            setStrafe(lastX, lastY, lastRot);
        }
        else {
            setSpeed(lastSpeed, true);
        }
    }
}
