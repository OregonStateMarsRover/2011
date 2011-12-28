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
    VideoViewWidget *VideoView = new VideoViewWidget(w);
    RightMainWidget *RightMain = new RightMainWidget(w);
    QGridLayout *layout = new QGridLayout;
         layout->addWidget(LeftMain,0,0);
         layout->addWidget(VideoView,0,1);
         layout->addWidget(RightMain,0,2);
    w->setLayout(layout);
    this->setCentralWidget(w);
}

void MainWindow::createMyMenu()
{

    //label1= new QLabel();
            line=new QLineEdit("Hello");
            setCentralWidget(line);
            //setCentralWidget(label1);
            showAct = new QAction(("&Show"), this);
            connect(showAct, SIGNAL(triggered()),line, SLOT(show()));
            hideAct = new QAction(("&Hide"), this);
            connect(hideAct, SIGNAL(triggered()),line, SLOT(hide()));
            exitAct = new QAction(("&Exit"), this);
            connect(exitAct, SIGNAL(triggered()),qApp, SLOT(quit()));
            cut=new QAction(("&Cut"),this);
            connect(cut,SIGNAL(triggered()),line,SLOT(cut()));
            copy=new QAction(("C&opy"),this);
            connect(copy,SIGNAL(triggered()),line,SLOT(copy()));
            paste=new QAction(("&Paste"),this);
            connect(paste,SIGNAL(triggered()),line,SLOT(paste()));
            QMenuBar *mainBar = this->menuBar();
            //bar = mainBar->addMenu("&File");
            bar = menuBar()->addMenu(tr("&File"));
            bar1= mainBar->addMenu("&Edit");


            bar->setTearOffEnabled(1);
            bar->addAction(showAct);
            bar->addSeparator();
            bar->setSeparatorsCollapsible(true);
            bar->addAction(hideAct);
            bar->addSeparator();
            bar->addAction(exitAct);
            bar1->addAction(cut);
            bar1->addAction(copy);
            bar1->addSeparator();
            bar1->addAction(paste);

}
