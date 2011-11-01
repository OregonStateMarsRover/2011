/*
 * AbstractController.cpp
 *
 * Created by Camden Lopez on 11/23/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#include "RobotController.h"
#include "AbstractController.h"

AbstractController::AbstractController(QObject *parent) : QObject(parent)
{
}

void AbstractController::sendMessage(QByteArray dat) {
    sendMessage(WirelessPacket(roverMessageTarget(), dat));
}

void AbstractController::sendMessage(WirelessPacket msg) {
   RobotController::instance()->sendWirelessPacket(msg);
}
