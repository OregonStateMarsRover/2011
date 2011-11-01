/*
 * WirelessPacket.cpp
 *
 * Created by Camden Lopez on 11/10/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#include "WirelessPacket.h"

WirelessPacket::WirelessPacket(int target, QByteArray data)
{
    m_target=target;
    m_data=data;
}

void WirelessPacket::setTarget(int newTarget) {
    m_target=newTarget;
}

void WirelessPacket::setData(QByteArray newData) {
    m_data = newData;
}

int WirelessPacket::target() {
    return m_target;
}

QByteArray WirelessPacket::data() {
    return m_data;
}
