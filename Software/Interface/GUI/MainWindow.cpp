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
#include "TaskStarter.h"

#include "RoverControls.h"

#include <QMenuBar>

#include "MainWindow.h"


MainWindow::MainWindow()
{

    QWidget *w = new QWidget(this);
    Task = new TaskStarter(w);
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(Task,0,0);
/*    LeftMainWidget *LeftMain = new LeftMainWidget(w);
    RightMainWidget *RightMain = new RightMainWidget(w);
    //VideoViewWidget *VideoView = new VideoViewWidget(w);

    bool single = false;
    if(single){
        layout->addWidget(LeftMain,0,0);
        //layout->addWidget(VideoView,0,1);
        layout->addWidget(RightMain,0,2);
    }else{
        layout->addWidget(LeftMain,0,0);
        layout->addWidget(RightMain,0,1);
    }*/
    w->setLayout(layout);
    this->setCentralWidget(w);

    showAct = new QAction(tr("&Show"), this);
    hideAct = new QAction(tr("&Hide"), this);
    exitAct = new QAction(tr("&Exit"), this);


    fileMenu = menuBar()->addMenu(tr("&File"));
         fileMenu->addAction(showAct);
         fileMenu->addAction(hideAct);
         fileMenu->addAction(exitAct);
         fileMenu->addSeparator();


    connect(this,SIGNAL(moved(int,int)),Task,SLOT(setNewPos(int,int)));

    QMainWindow *old = new QMainWindow();
    NavigationWidget *navWidget = new NavigationWidget(old);
    old->setCentralWidget(navWidget);
    old->show();
/*
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
*/


    //John's widget
    QMainWindow *John = new QMainWindow();
    RoverControls *rover_control = new RoverControls(John);
    John->setCentralWidget(rover_control);
    John->show();
}

void MainWindow::moveEvent ( QMoveEvent * event ){
    emit moved(this->x(),this->y());
}
