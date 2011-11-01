/*
 * CameraController.cpp
 *
 * Created by Camden Lopez on 11/10/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#include <QDebug>
#include "TripodController.h"
#include <math.h>

TripodController::TripodController(QObject *parent) : AbstractController(parent)
{
    centerPan = DEFAULT_CENTER_PAN;
    centerTilt = DEFAULT_CENTER_TILT;

    zoomLevel = 0;
    panPosition = DEFAULT_CENTER_PAN;
    tiltPosition = DEFAULT_CENTER_TILT;

    panDir = NoPan;
    tiltDir = NoTilt;
    zoomDir = NoZoom;

    calibData.AC1 = 8401;
    calibData.AC2 = -1182;
    calibData.AC3 = -14493;
    calibData.AC4 = 35371;
    calibData.AC5 = 24212;
    calibData.AC6 = 19466;
    calibData.B1 = 5498;
    calibData.B2 = 63;
    calibData.MB = -32768;
    calibData.MC = -11075;
    calibData.MD = 2432;

    setPanTiltDouble(false);

    panTiltTimer = new QTimer(this);
    panTiltTimer->setInterval(100);
    connect(panTiltTimer, SIGNAL(timeout()), this, SLOT(updatePanTilt()));

    zoomTimer = new QTimer(this);
    zoomTimer->setInterval(100);
    connect(zoomTimer, SIGNAL(timeout()), this, SLOT(updateZoom()));

    accelTimer = new QTimer(this);
    accelTimer->setInterval(1000);
    connect(accelTimer, SIGNAL(timeout()), this, SLOT(requestAccelerometerData()));
    accelTimer->start();

    baroTimer = new QTimer(this);
    baroTimer->setInterval(1000);
    connect(baroTimer, SIGNAL(timeout()), this, SLOT(requestBarometerData()));
    baroTimer->start();

    baroLogger = new QFile("baro.txt", this);
    accelLogger = new QFile("accel.txt", this);

    baroLogger->open(QIODevice::Truncate|QIODevice::WriteOnly);
    accelLogger->open(QIODevice::Truncate|QIODevice::WriteOnly);

    connect(this, SIGNAL(newAccelerometerData(short,short,short)), this, SLOT(recordAccelData(short,short,short)));
    connect(this, SIGNAL(newBarometerData(unsigned short,ulong)), this, SLOT(recordBaroData(unsigned short,ulong)));
}

short TripodController::bytesToShort(unsigned char msb, unsigned char lsb) {
    return (msb<<8 | lsb);
}

unsigned short TripodController::bytesToUShort(unsigned char msb, unsigned char lsb) {
    return (msb<<8 | lsb);
}

uint32_t TripodController::bytesToLong(unsigned char msb, unsigned char midbit, unsigned char lsb) {
    return (msb<<16 | (midbit<<8) | lsb);
}

void TripodController::recordAccelData(short x, short y, short z) {
    accelLogger->write(qPrintable(QString::number(x)+","+QString::number(y)+","+QString::number(z)+","));
    accelLogger->write(qPrintable(QString::number(asin(x/4096.0))+","+QString::number(asin(y/4096.0))+"\n"));

    accelLogger->flush();
}

void TripodController::recordBaroData(short temp, unsigned long pressure) {
    baroLogger->write(qPrintable(QString::number(temp)+","+QString::number(pressure)+"\n"));
    qDebug() << "got baro data: "<<temp<<pressure;
    baroLogger->flush();
}

struct TripodController::BarometerData TripodController::processBarometerData(TripodController::BarometerCalibData calibration, signed short temperatureCounts, unsigned long pressureCounts)
{
    long X1, X2, X3, B5, B3, B6, p;
    short OSS = 3;

    unsigned long B4, B7;

    X1 = (((long)temperatureCounts - (long)calibration.AC6)*(long)calibration.AC5) >> 15;
    X2 = ((long)calibration.MC << 11)/(X1 + calibration.MD);
    B5 = X1 + X2;


    B6 = B5 - 4000;
      // Calculate B3
    X1 = (calibration.B2 * (B6 * B6)>>12)>>11;
    X2 = (calibration.AC2 * B6)>>11;
    X3 = X1 + X2;
    B3 = (((((int32_t)calibration.AC1)*4 + X3)<<OSS) + 2)>>2;
    //B3 = (((int32_t) AC1 * 4 + X3)<<OSS) > > 2;

    // Calculate B4
    X1 = (calibration.AC3 * B6)>>13;
    X2 = (calibration.B1 * ((B6 * B6)>>12))>>16;
    X3 = ((X1 + X2) + 2)>>2;
    B4 = (calibration.AC4 * (unsigned long)(X3 + 32768))>>15;

    B7 = ((unsigned long)(pressureCounts - B3) * (50000>>OSS));
    if (B7 < 0x80000000)
      p = (B7<<1)/B4;
    else
      p = (B7/B4)<<1;

    X1 = (p>>8) * (p>>8);
    X1 = (X1 * 3038)>>16;
    X2 = (-7357 * p)>>16;
    p += (X1 + X2 + 3791)>>4;

    struct BarometerData data;
    data.pressure = p;
    data.temperature = ((B5 + 8)>>4);
    return data;
}

void TripodController::handleMessage(WirelessPacket msg) {
    qDebug() << "Tripod msg:"<<msg.data().toHex();

    if (msg.data().at(0)==0x03) { // from barometer
        if (msg.data().length()==7 && msg.data().at(1)==1) {
            qDebug() << "got baro data";
            short temperature;
            unsigned long pressure;

            temperature = bytesToUShort(msg.data().at(2), msg.data().at(3));
            pressure = bytesToLong(msg.data().at(4),msg.data().at(5),msg.data().at(6));
            struct BarometerData data = TripodController::processBarometerData(calibData, temperature, pressure);
            emit newBarometerData(data.temperature,data.pressure);
        }
    }
    else if (msg.data().at(0)==0x04) { // from accelerometer
        if (msg.data().length()==8 && msg.data().at(1)==0x01) { // averaged accel data
            qDebug() << "got avg accel data:"<<bytesToShort(msg.data().at(2), msg.data().at(3))<<bytesToShort(msg.data().at(4), msg.data().at(5));
            emit newAccelerometerData(bytesToShort(msg.data().at(2), msg.data().at(3)),
                                 bytesToShort(msg.data().at(4), msg.data().at(5)),
                                 bytesToShort(msg.data().at(6), msg.data().at(7)));
        }
    }
}

int TripodController::guiMessageTarget() {
    return TARGET_GUI_TRIPOD;
    return 1;
}

int TripodController::roverMessageTarget() {
    return TARGET_TRIPOD_CONTROLLER;
    //return 1;
}

unsigned short TripodController::getCurrentPan() {
    return panPosition;
}

unsigned short TripodController::getCurrentTilt() {
    return tiltPosition;
}

unsigned short TripodController::getZoomLevel() {
    return zoomLevel;
}

void TripodController::sendCameraCommand(QByteArray command)
{
    command.prepend("\x02\x02");
    command.append(0xFF);

    sendMessage(command);
}

void TripodController::setCameraZoom(short zoomLevel) {
    QByteArray msg;

    qDebug() << "zooming to"<<zoomLevel<<" rate to "<<log(4100-zoomLevel)-3.5;
    msg.append(0x02);
    msg.append(0x01);
    msg.append((char)((zoomLevel>>8) & 0xFF));
    msg.append((char)(zoomLevel & 0xFF));

    sendMessage(msg);


    panTiltTimer->setInterval((480.0/3990.0)*zoomLevel + 100);

    emit newZoomPosition(zoomLevel);
    this->zoomLevel = zoomLevel;
}

void TripodController::setPanPosition(short panPos) {
    QByteArray msg;

    qDebug() << "panning to"<<panPos;
    msg.append(0x01); // pan-tilt subsyste,
    msg.append(0x01); // change servos
    msg.append(0x01); // pan servo
    msg.append((char)((panPos>>8) & 0xFF));
    msg.append((char)(panPos & 0xFF));

    sendMessage(msg);
    qDebug() << "sending" << msg.toHex();

    emit newPanPosition(panPos);
    this->panPosition = panPos;
}

void TripodController::setTiltPosition(short tiltPos) {
    QByteArray msg;
    qDebug()<<"tilting to"<<tiltPos;

    msg.append(0x01); // pan-tilt subsyste,
    msg.append(0x01); // change servos
    msg.append(0x02); // tilt servo
    msg.append((char)((tiltPos>>8) & 0xFF));
    msg.append((char)(tiltPos & 0xFF));

    sendMessage(msg);

    emit newTiltPosition(tiltPos);

    this->tiltPosition=tiltPos;
}

void TripodController::setPanTiltPosition(short panPos, short tiltPos) {
    this->tiltPosition = tiltPos;
    this->panPosition = panPos;

    QByteArray msg;
    qDebug()<<"pantilting to"<<tiltPos<<panPos;

    msg.append(0x01); // pan-tilt subsystem
    msg.append(0x03); // change servos
    msg.append((char)((panPos>>8) & 0xFF));
    msg.append((char)(panPos & 0xFF));
    msg.append((char)((tiltPos>>8) & 0xFF));
    msg.append((char)(tiltPos & 0xFF));

    sendMessage(msg);

    emit newTiltPosition(tiltPos);
    emit newPanPosition(panPos);

    this->tiltPosition=tiltPos;
    this->panPosition=panPos;
}

void TripodController::centerPanTilt() {
    setCameraZoom(MIN_ZOOM);
    setPanTiltPosition(centerPan, centerTilt);
}

void TripodController::startPanning(PanDirection dir) {
    panDir = dir;
    panTiltTimer->start();
    updatePanTilt(); // force update right away
}

void TripodController::startTilting(TiltDirection dir) {
    tiltDir = dir;
    panTiltTimer->start();
    updatePanTilt();
}

void TripodController::startZooming(ZoomDirection dir) {
    zoomDir = dir;
    if (dir==NoZoom)
        zoomTimer->stop();
    else
        zoomTimer->start();

    updateZoom();
}

void TripodController::setNewCenter() {
    centerPan = panPosition;
    centerTilt = tiltPosition;
    qDebug("recentering camera to %d,%d",panPosition,tiltPosition);
}

void TripodController::setPanTiltDouble(bool doubleSpeed) {
    doublePanTiltSpeed = doubleSpeed;
}

void TripodController::enablePeriodicBaroRequests(bool sendRequests) {
    if (sendRequests) {
        if (!baroTimer->isActive())
            baroTimer->start();
    }
    else {
        baroTimer->stop();
    }
}

bool TripodController::enablePeriodicAccelRequests(bool sendRequests) {
    if (sendRequests) {
        if (!accelTimer->isActive())
            accelTimer->start();
    }
    else {
        accelTimer->stop();
    }
}

void TripodController::updateZoom() {
    if (zoomDir==NoZoom) {
        zoomTimer->stop();
        return; // don't send an update if we're not changing anything
    }
    else if (zoomDir==ZoomOut) {
        if (zoomLevel-ZOOM_RATE < MIN_ZOOM) {
            zoomLevel = MIN_ZOOM;
        }
        else {
            zoomLevel = zoomLevel - ZOOM_RATE;
        }
    }
    else if (zoomDir==ZoomIn) {
        if (zoomLevel+ZOOM_RATE > MAX_ZOOM) {
            zoomLevel = MAX_ZOOM;
        }
        else {
            zoomLevel = zoomLevel + ZOOM_RATE;
        }
    }

    setCameraZoom(zoomLevel);
}

void TripodController::updatePanTilt() {
    char p[25];
    sprintf(p, "%lf", log(4100-zoomLevel)-3.5);
    qDebug(p);
    //short panRate = log(4100-zoomLevel)-3.5;//PAN_RATE;
    //short tiltRate = log(4100-zoomLevel)-3.5;//TILT_RATE;
    short panRate = 5 - (5.0/3990.0)*zoomLevel;
    short tiltRate = 8 - (8.0/3990.0)*zoomLevel;

    panRate *= 0.5f;

    if (tiltRate==0)
        tiltRate = 1;

    if (panRate<1)
        panRate=1;
    //tiltRate *= 2;

    /*if (panRate>2)
        panRate = 2;

    if (tiltRate>2)
        tiltRate = 2;
    */
    if (panRate<1) {
        qDebug() << "I'M AN UNHAPPY PAN LOG!";
        panRate = 1.0;
    }

    if (tiltRate<1) {
        qDebug() << "I'M AN UNHAPPY TILT LOG!";
        tiltRate = 1.0;
    }

    if (doublePanTiltSpeed) {
        panRate *= 2;
        tiltRate *= 2;
    }

    if (panDir!=NoPan) {
        if (panDir==PanLeft) {
            if (panPosition-panRate<MIN_PAN)
                panPosition = MIN_PAN;
            else
                panPosition = panPosition - panRate;
        }
        else if (panDir==PanRight) {
            if (panPosition+panRate>MAX_PAN)
                panPosition = MAX_PAN;
            else
                panPosition = panPosition + panRate;
        }
        setPanPosition(panPosition);
    }

    if (tiltDir!=NoTilt) {
        if (tiltDir==TiltUp) {
            if (tiltPosition-tiltRate<MIN_TILT)
                tiltPosition = MIN_TILT;
            else
                tiltPosition = tiltPosition - tiltRate;
        }
        else if (tiltDir==TiltDown) {
            if (tiltPosition+tiltRate>MAX_TILT)
                tiltPosition = MAX_TILT;
            else
                tiltPosition = tiltPosition + tiltRate;
        }
        setTiltPosition(tiltPosition);
    }

    if (panDir==NoPan && tiltDir==NoTilt) {
        panTiltTimer->stop();
    }
}

void TripodController::requestBarometerData() {
    QByteArray msg;
    msg.append(0x03);
    msg.append(0x01);

    sendMessage(msg);
}

void TripodController::requestAccelerometerData() {
    QByteArray msg;
    msg.append(0x04);
    msg.append(0x01);

    sendMessage(msg);
}
