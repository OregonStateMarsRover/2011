/*
 * MainWindow.cpp
 *
 * Created by Camden Lopez on 11/10/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#include "ArmWidget.h"
#include "CameraWidget.h"
#include "DriveWidget.h"
#include "NavigationWidget.h"
#include "ScienceWidget.h"
#include "StatusWidget.h"

#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	QTabWidget *tabWidget = new QTabWidget(this);
	DriveWidget *driveWidget = new DriveWidget(this);
	tabWidget->addTab(driveWidget, "Drive");
	ArmWidget *armWidget = new ArmWidget(this);
	tabWidget->addTab(armWidget, "Arm");
	CameraWidget *camWidget = new CameraWidget(this);
	tabWidget->addTab(camWidget, "Cameras");
	StatusWidget *statWidget = new StatusWidget(this);
	tabWidget->addTab(statWidget, "Status");
	NavigationWidget *navWidget = new NavigationWidget(this);
	tabWidget->addTab(navWidget, "Navigation");
	ScienceWidget *sciWidget = new ScienceWidget(this);
	tabWidget->addTab(sciWidget, "Science");
	setCentralWidget(tabWidget);
}
