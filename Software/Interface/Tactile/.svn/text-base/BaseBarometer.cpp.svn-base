#include <QDebug>
#include "BaseBarometer.h"

BaseBarometer::BaseBarometer(QObject *parent) :
    QObject(parent)
{
    usb = 0;
    usb = new USBDevice(BARO_VENDOR_ID, BARO_DEVICE_ID);
    //usb = new USBDevice("/dev/hidraw1");
    //usb = new USBDevice("/dev/hidraw2", "/dev/hidraw1");
    //usb->openUSB();
    if (usb->deviceOpened()) {
        qDebug() << "OPENED USB";
    }
    else {
        qDebug() << "DID NOT OPEN USB";
    }

    usbTimer = new QTimer(this);
    connect(usbTimer, SIGNAL(timeout()), this, SLOT(processUSBData()));
    usbTimer->setInterval(100);
    usbTimer->start();
    calibData.AC1 = 8052;
    calibData.AC2 = -1027;
    calibData.AC3 = -14636;
    calibData.AC4 = 31844;
    calibData.AC5 = 23970;
    calibData.AC6 = 20116;
    calibData.B1 = 5498;
    calibData.B2 = 52;
    calibData.MB = -32768;
    calibData.MC = -11075;
    calibData.MD = 2432;

    baseBaroOffset = 0;

    baseLogger = new QFile("base-baro.txt", this);
    baseLogger->open(QIODevice::Truncate|QIODevice::WriteOnly);
}

BaseBarometer::~BaseBarometer() {
    if (usb)
        delete usb;
}

void BaseBarometer::requestCoefficients() {
    char uselessData[8];
    uselessData[0] = 0x01;
    //usb->writeChar(0x01);
    usb->writeData(uselessData, 2);
}

void BaseBarometer::requestPressureData() {
    char uselessData[8];
    uselessData[0] = 0x02;
    if (usb->writeData(uselessData, 2)==2)
        qDebug() << "wrote char";
    else
        qDebug() << "failed to write";
}

void BaseBarometer::setBaseBarometerOffset(int offset) {
    baseBaroOffset = offset;
}

void BaseBarometer::processUSBData() {
    char buf[50];
    unsigned char i;
    int avail = usb->readData(buf, 50);
    if (avail>0) {
        //qDebug() << "got"<<avail<<"bytes for unknown packet:";
        qDebug(" ");
        if (avail==23) { // correct length
            if (buf[0]==5) { // pressure + temp update
                unsigned short temperatureCounts = ((buf[1]<<8) & 0xFF00) | (buf[2] & 0xFF);
                unsigned long pressureCounts = ((buf[3]<<16) & 0xFF0000) | ((buf[4] << 8) & 0xFF00) | (buf[5] & 0xFF);
                TripodController::BarometerData data = TripodController::processBarometerData(calibData,temperatureCounts,pressureCounts);

                data.pressure = data.pressure + baseBaroOffset;

                baseLogger->write(qPrintable(QString::number(data.temperature)+","+QString::number(data.pressure)+"\n"));
                baseLogger->flush();

                emit gotPressureData(data.temperature,data.pressure);
                qDebug() << "tempCounts"<<temperatureCounts<<"pressureCounts"<<pressureCounts;
            }
            else if (buf[0]==22) { // calibration coefficient update

            }
        }
    }
}
