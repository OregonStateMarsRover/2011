#include <QDebug>
#include <QTimer>
#include <QByteArray>

#include "GPSController.h"

GPSController::GPSController(QObject * parent) : AbstractController(parent)
{
    gpsReqTimer = new QTimer(this);
    connect(gpsReqTimer, SIGNAL(timeout()), this, SLOT(sendGPSRequest()));
    gpsReqTimer->setInterval(1250);
    gpsReqTimer->start();
}

void GPSController::sendGPSRequest() {
    qDebug("sending gps req");
    QByteArray dat("GA"); // get all
    WirelessPacket pkt(TARGET_GPS_CONTROLLER, dat);

    sendMessage(pkt);
}

void GPSController::enablePeriodicGPSRequests(bool sendRequests) {
    if (sendRequests) {
        if (!gpsReqTimer->isActive()) // only start if not already running (to keep from ruining timing)
            gpsReqTimer->start();
    }
    else {
        gpsReqTimer->stop();
    }
}

void GPSController::handleMessage(WirelessPacket msg) {
    qDebug() << "GPS got a message ("<<msg.data().length()<<"): "<<msg.data().toHex();

    if (msg.data().at(0)=='R') { // got GPRMC/GPSPositionData
        GPSPositionData dat;
        qDebug() << "sizeof(dat):"<<sizeof(dat);
        memcpy(&dat, msg.data().right(sizeof(dat)).constData(), sizeof(dat));
        qDebug() << "status:" <<dat.status<<"lat:"<<dat.lat_degrees<<"."<<dat.lat_mins<<"long:"<<dat.long_degrees<<"."<<dat.long_mins;
        emit gotPositionUpdate(dat);
    }
    else if (msg.data().at(0)=='V') { // got GPVTG/GPSHeadingData
        GPSHeadingData dat;
        memcpy(&dat, msg.data().right(sizeof(dat)).constData(), sizeof(dat));
        qDebug() << "true track:" <<dat.true_track<<"KPH:"<<dat.speed_kmph;
        emit gotHeadingUpdate(dat);
    }
    else if (msg.data().at(0)=='S') { // got GPVTG/GPSHeadingData
        GPSSatData dat;
        memcpy(&dat, msg.data().right(sizeof(dat)).constData(), sizeof(dat));
        qDebug() <<"number of sat:"<<dat.sat_view;
        //emit gotHeadingUpdate(dat);
    }
    else if (msg.data().at(0)=='A') { // got update with all data
        GPSPositionData posDat;
        GPSHeadingData headingDat;
        GPSSatData satDat;
        GPSNmeaData nmeaDat;

        memcpy(&nmeaDat, msg.data().data()+1, sizeof(nmeaDat));

        qDebug() << "status:" <<nmeaDat.status<<"lat:"<<nmeaDat.lat_degrees<<"."<<nmeaDat.lat_mins<<"long:"<<nmeaDat.long_degrees<<"."<<nmeaDat.long_mins<< "true track:" <<nmeaDat.true_track<<"KPH:"<<nmeaDat.speed_kmph<<"number of sat:"<<nmeaDat.sat_view;
        posDat.status = nmeaDat.status;
        posDat.lat_degrees = nmeaDat.lat_degrees;
        posDat.lat_mins = nmeaDat.lat_mins;
        posDat.long_degrees = nmeaDat.long_degrees;
        posDat.long_mins = nmeaDat.long_mins;
        headingDat.speed_kmph = nmeaDat.speed_kmph;
        headingDat.true_track = nmeaDat.true_track;
        satDat.sat_view = nmeaDat.sat_view;

        emit gotPositionUpdate(posDat);
        emit gotHeadingUpdate(headingDat);
        //emit gotHeadingUpdate(dat);
    }
}

int GPSController::guiMessageTarget() {
    return TARGET_GUI_GPS;
}

int GPSController::roverMessageTarget() {
    return TARGET_GPS_CONTROLLER;
    //return TARGET_GUI_GPS;
}

/*void GPSController::sendGPSRequest() {
    qDebug("send gps!");
    QByteArray dat("\x01\x02\x03\x04"); // request all data from GPS
    WirelessPacket reqPkt(roverMessageTarget(), dat);
    sendMessage(reqPkt);
}*/
