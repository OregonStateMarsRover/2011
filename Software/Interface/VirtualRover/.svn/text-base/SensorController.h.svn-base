/*
 * SensorController.h
 *
 * Provides an interface between the wireless communication
 * with the rover and the GUI in regards to the rover sensors.
 *
 * Created by Camden Lopez on 11/10/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#ifndef SENSORCONTROLLER_H
#define SENSORCONTROLLER_H

#include "AbstractController.h"

class SensorController : public AbstractController
{
    Q_OBJECT
public:
    explicit SensorController(QObject *parent = 0);

    virtual void handleMessage(WirelessPacket * msg);

    virtual int guiMessageTarget();
    virtual int roverMessageTarget();
signals:

public slots:

};

#endif // SENSORCONTROLLER_H
