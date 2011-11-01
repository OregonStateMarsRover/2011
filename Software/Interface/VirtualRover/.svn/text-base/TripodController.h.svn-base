/*
 * CameraController.h
 *
 * Provides an interface between the wireless communication
 * with the rover and the GUI in regards to controlling the
 * rover cameras.
 *
 * Created by Camden Lopez on 11/10/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

#include <QFile>
#include <QTimer>
#include <stdint.h>
#include "AbstractController.h"

#define MIN_ZOOM 0
#define MAX_ZOOM 3990

#define MIN_PAN 0
//#define MIN_PAN 380
#define DEFAULT_CENTER_PAN 512
//#define MAX_PAN 692
#define MAX_PAN 750

//#define MIN_TILT 1
#define MIN_TILT 502
#define DEFAULT_CENTER_TILT 890
//#define MAX_TILT 976
#define MAX_TILT 1023

#define PAN_RATE 2
#define TILT_RATE 5

#define ZOOM_RATE 50

class TripodController : public AbstractController
{
    Q_OBJECT
public:
    enum PanDirection { PanLeft, PanRight, NoPan };
    enum TiltDirection { TiltUp, TiltDown, NoTilt };
    enum ZoomDirection { ZoomIn, ZoomOut, NoZoom };
    struct BarometerCalibData {
        short AC1;
        short AC2;
        short AC3;
        unsigned short AC4;
        unsigned short AC5;
        unsigned short AC6;
        short B1;
        short B2;
        short MB;
        short MC;
        short MD;
    };

    struct BarometerData {short temperature; unsigned long pressure;};

    explicit TripodController(QObject *parent = 0);

    virtual void handleMessage(WirelessPacket msg);

    virtual int guiMessageTarget();
    virtual int roverMessageTarget();

    unsigned short getCurrentPan();
    unsigned short getCurrentTilt();
    unsigned short getZoomLevel();
    void sendCameraCommand(QByteArray command);

    static struct BarometerData processBarometerData(struct BarometerCalibData calibration, signed short temperatureCounts, unsigned long pressureCounts);

public slots:
    void setPanTiltPosition(short panPos, short tiltPos);
    void setCameraZoom(short zoomLevel);
    void setPanPosition(short panPos);
    void setTiltPosition(short tiltPos);
    void centerPanTilt();

    void startPanning(PanDirection dir);
    void startTilting(TiltDirection dir);
    void startZooming(ZoomDirection dir);
    void setPanTiltDouble(bool doubleSpeed);

    void setNewCenter(); // sets current position as the current center position

    void enablePeriodicBaroRequests(bool sendRequests);
    bool enablePeriodicAccelRequests(bool sendRequests);

signals:
    void newZoomPosition(int newZoomLevel);
    void newTiltPosition(int newTiltPos);
    void newPanPosition(int newPanPos);

    void newAccelerometerData(short x, short y, short z);
    void newBarometerData(unsigned short temperature, unsigned long pressure);

private slots:
    void updateZoom();
    void updatePanTilt();

    void requestBarometerData();
    void requestAccelerometerData();

    void recordAccelData(short x, short y, short z);
    void recordBaroData(short temp, unsigned long pressure);

private:
    QTimer * panTiltTimer;
    QTimer * zoomTimer;
    QTimer * baroTimer;
    QTimer * accelTimer;
    QFile * baroLogger;
    QFile * accelLogger;

    struct BarometerCalibData calibData;

    PanDirection panDir;
    TiltDirection tiltDir;
    ZoomDirection zoomDir;
    bool doublePanTiltSpeed;
    short zoomLevel, panPosition, tiltPosition;

    unsigned short centerPan, centerTilt;

    short bytesToShort(unsigned char msb, unsigned char lsb);
    unsigned short bytesToUShort(unsigned char msb, unsigned char lsb);
    uint32_t bytesToLong(unsigned char msb, unsigned char midbit, unsigned char lsb);


signals:

};

#endif // CAMERACONTROLLER_H
