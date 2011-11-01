#ifndef GPSCONTROLLER_H
#define GPSCONTROLLER_H

#include <QTimer>

#include "AbstractController.h"

typedef struct {
   char status __attribute__((__packed__));
   unsigned short lat_degrees __attribute__((__packed__));
   unsigned short lat_mins __attribute__((__packed__));
   unsigned short long_degrees __attribute__((__packed__));
   unsigned short long_mins __attribute__((__packed__));
   unsigned short speed_knots __attribute__((__packed__));
} GPSPositionData;

typedef struct {
        unsigned short true_track __attribute__((__packed__));
        unsigned short magnetic_track __attribute__((__packed__));
        unsigned short speed_knots __attribute__((__packed__));
        unsigned short speed_kmph __attribute__((__packed__));
} GPSHeadingData;

typedef struct {
    char status __attribute__((__packed__));
    unsigned short  lat_degrees __attribute__((__packed__));
    unsigned short  lat_mins __attribute__((__packed__));
    unsigned short  long_degrees __attribute__((__packed__));
    unsigned short  long_mins __attribute__((__packed__));
    unsigned short  speed_kmph __attribute__((__packed__));
    unsigned short  true_track __attribute__((__packed__));
    unsigned short  sat_view __attribute__((__packed__));
}GPSNmeaData;

typedef struct {
        unsigned short  prn __attribute__((__packed__));
   unsigned short  elev __attribute__((__packed__));
   unsigned short  azi __attribute__((__packed__));
        unsigned short  snr __attribute__((__packed__));
}sat;

typedef struct {
        unsigned short  sat_view __attribute__((__packed__));
        sat satellites[8] __attribute__((__packed__));
}GPSSatData;

class GPSController : public AbstractController
{
    Q_OBJECT
public:
    GPSController(QObject * parent = 0);

    virtual void handleMessage(WirelessPacket msg);

    virtual int guiMessageTarget();
    virtual int roverMessageTarget();

public slots:
    void sendGPSRequest();

    void enablePeriodicGPSRequests(bool sendRequests);

signals:
    void gotPositionUpdate(GPSPositionData);
    void gotHeadingUpdate(GPSHeadingData);

private:
    QTimer * gpsReqTimer;
};

#endif // GPSCONTROLLER_H
