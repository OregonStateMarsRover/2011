/*
 * Joystick.cpp
 *
 * Reads from joystick and emits signals when axis/buttons change.
 *
 * Created by Taj Morton on 03/04/2011
 * Copyright © 2011 Oregon State University Robotics Club */

#include <QDebug>
#include <QDir>
#include <QStringList>

#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/joystick.h>
#include <unistd.h>
#include <errno.h>

#define MOTOR_DEAD_BAND 100

#include "Joystick.h"

Joystick::Joystick(QString filename, QObject *parent) :
    QObject(parent)
{
    joystickFd = -1;
    updateTimer = new QTimer(this);

    joystickFd = open(qPrintable(filename), O_RDONLY);
    fcntl(joystickFd, F_SETFL, O_NONBLOCK); // don't block/wait until we get a new joystick event

    if (joystickFd>0) { // successfully opened joystick
        ioctl(joystickFd, JSIOCGAXES, &axisCount);
        ioctl(joystickFd, JSIOCGBUTTONS, &buttonCount);
        m_openError = "No error";
    }
    else {
        m_openError = QString(strerror(errno));
    }

    connect(updateTimer, SIGNAL(timeout()), this, SLOT(update()));
    updateTimer->start(50);
}

int Joystick::sign(float a) {
    if (a<0)
        return -1;
    else if (a>0)
        return 1;
    else
        return 0;
}


QStringList Joystick::getJoystickNames() {
        QStringList filter;
        filter.append("js*");
        QDir dir("/dev/input");

        QStringList dirs = dir.entryList(filter,QDir::System);
        QStringList joysticks;

        foreach(QString s, dirs) {
                joysticks.append(dir.absoluteFilePath(s));
        }

        return joysticks;
}


Joystick::~Joystick() {
    close (joystickFd);
}

bool Joystick::isOpen() {
    return (joystickFd>0);
}

void Joystick::update() {
    struct js_event joystickData;
    short val;
    if (isOpen()) { // joystick ready for reading
        while (read(joystickFd, &joystickData, sizeof(struct js_event)) > 0) { // while there are events to read
            if (joystickData.type == JS_EVENT_AXIS) {
                val = joystickData.value;
                qDebug() << "got update"<<val;

                if (abs(val)<JOYSTICK_STOP_RANGE) { // if we're within the joystick stop range, stop
                    val = 0;
                }
                else {
                    val -= JOYSTICK_STOP_RANGE*sign(val); // otherwise, make sure to compensate for the deadzone
                    qDebug() << "mod update"<<val;
                }

                emit axisChanged(joystickData.number, val);
            }
            else if (joystickData.type == JS_EVENT_BUTTON) {
                emit buttonChanged(joystickData.number, joystickData.value==1); // emit true if button pressed down

                if (joystickData.value==1) {
                    emit buttonPressed(joystickData.number);
                }
                else if (joystickData.value==0) {
                    emit buttonReleased(joystickData.number);
                }
                else {
                    qDebug() << "Unknown joystick value:"<<joystickData.value;
                }
            }
        }
    }
}
