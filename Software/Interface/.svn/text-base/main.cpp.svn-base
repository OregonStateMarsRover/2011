/*
 * main.cpp
 *
 * The main function for the rover interface application.
 *
 * Created by Camden Lopez on 11/10/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#include <QtGui/QApplication>
#include "GUI/MainWindow.h"

#include "Tactile/TactileInterface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("OSURC");
    QCoreApplication::setApplicationName("2011Rover");

    TactileInterface::setDrivingJoystick(); // load with default settings
    TactileInterface::setArmJoystick();

    MainWindow w;
    w.show();
//	VideoWidget v;
//	v.show();

    return a.exec();
}
