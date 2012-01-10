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
#include "LeftMainWidget.h"
#include "VideoViewWidget.h"
#include "RightMainWidget.h"

#include "MainWindow.h"


MainWindow::MainWindow()
{
        /*
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
        */
    QWidget *w = new QWidget(this);
    LeftMainWidget *LeftMain = new LeftMainWidget(w);
    RightMainWidget *RightMain = new RightMainWidget(w);
    VideoViewWidget *VideoView = new VideoViewWidget(w);

    QGridLayout *layout = new QGridLayout;
    bool single = false;
    if(single){
        layout->addWidget(LeftMain,0,0);
        layout->addWidget(VideoView,0,1);
        layout->addWidget(RightMain,0,2);
    }else{
        layout->addWidget(LeftMain,0,0);
        layout->addWidget(RightMain,0,1);
        QMainWindow *videoWindow = new QMainWindow();
        videoWindow->setCentralWidget(VideoView);
        videoWindow->show();
    }
    w->setLayout(layout);
    this->setCentralWidget(w);


    QMainWindow *old = new QMainWindow();
    QTabWidget *tabWidget = new QTabWidget(old);
    DriveWidget *driveWidget = new DriveWidget(old);
    tabWidget->addTab(driveWidget, "Drive");
    ArmWidget *armWidget = new ArmWidget(old);
    tabWidget->addTab(armWidget, "Arm");
    CameraWidget *camWidget = new CameraWidget(old);
    tabWidget->addTab(camWidget, "Cameras");
    StatusWidget *statWidget = new StatusWidget(old);
    tabWidget->addTab(statWidget, "Status");
    NavigationWidget *navWidget = new NavigationWidget(old);
    tabWidget->addTab(navWidget, "Navigation");
    ScienceWidget *sciWidget = new ScienceWidget(old);
    tabWidget->addTab(sciWidget, "Science");
    old->setCentralWidget(tabWidget);
    old->show();
}
