/*
 * NavigationWidget.h
 *
 * Displays map(s) and geolocation/heading information from the rover.
 * Provides tools for navigating the rover and locating landmarks via
 * triangulation.
 *
 * Created by Camden Lopez on 1/3/11
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#ifndef NAVIGATIONWIDGET_H
#define NAVIGATIONWIDGET_H

#include "VirtualRover/GPSController.h"
#include "NavigationView.h"

#include "ui_NavigationWidget.h"

class TriangulationWidget;

class NavigationWidget : public QWidget, private Ui::NavigationWidget
{
    Q_OBJECT

public:
    explicit NavigationWidget(QWidget *parent = 0);
	~NavigationWidget();

public slots:
	void displayCoordinates(const QPointF & coords);

private:
	TriangulationWidget * triangulationWidget;
        //NavigationView * navView;

private slots:
        void on_addPointButton_clicked();
        void sendGPSRequest();
        void gotGPSUpdate(GPSPositionData dat);
        void gotGPSHeading(GPSHeadingData dat);

};

#endif // NAVIGATIONWIDGET_H
