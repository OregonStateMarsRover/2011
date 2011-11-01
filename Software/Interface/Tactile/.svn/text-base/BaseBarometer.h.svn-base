#ifndef BASEBAROMETER_H
#define BASEBAROMETER_H

#include <QObject>
#include <QTimer>
#include "Common/USBDevice.h"
#include "VirtualRover/TripodController.h"

#define BARO_VENDOR_ID 0x16c0
#define BARO_DEVICE_ID 0x0480

#define BARO_BASE_OFFSET -48

class BaseBarometer : public QObject
{
    Q_OBJECT
public:
    explicit BaseBarometer(QObject *parent = 0);
    ~BaseBarometer();

signals:
    void gotCoefficients(short ac1, short ac2, short ac3, short ac4, short ac5, short ac6, short b1, short b2, short mb, short mc, short md);
    void gotPressureData(unsigned short temperature, unsigned long pressure);

public slots:
    void requestCoefficients();
    void requestPressureData();

    void setBaseBarometerOffset(int offset);

private slots:
    void processUSBData();

private:
    USBDevice * usb;
    QTimer * usbTimer;
    QFile * baseLogger;
    struct TripodController::BarometerCalibData calibData;

    int baseBaroOffset;

};

#endif // BASEBAROMETER_H
