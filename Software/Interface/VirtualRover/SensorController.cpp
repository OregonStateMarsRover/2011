/*
 * SensorController.cpp
 *
 * Created by Camden Lopez on 11/10/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#include "SensorController.h"

SensorController::SensorController(QObject *parent) : AbstractController(parent)
{
}

void SensorController::handleMessage(WirelessPacket * msg) {
}

int SensorController::guiMessageTarget() {

}

int SensorController::roverMessageTarget() {

}
