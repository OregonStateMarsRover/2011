/*
 * WirelessPacket.h
 *
 * Encapsulates the unit of communication between the rover
 * and the interface.
 *
 * Created by Camden Lopez on 11/10/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#ifndef WIRELESSPACKET_H
#define WIRELESSPACKET_H

#include <QByteArray>

class WirelessPacket
{
public:
    explicit WirelessPacket(int target, QByteArray data);

    void setTarget(int newTarget);
    void setData(QByteArray newData);

    int target();
    QByteArray data();

private:
    int m_target;
    QByteArray m_data;
};

#endif // WIRELESSPACKET_H
