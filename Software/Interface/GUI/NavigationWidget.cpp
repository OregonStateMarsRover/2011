/*
 * NavigationWidget.cpp
 *
 * Created by Camden Lopez on 1/3/11
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#include <QDebug>
#include "NavigationView.h"
#include "TriangulationWidget.h"

#include "NavigationWidget.h"
#include "NavigationPlaceDialog.h"

#include "VirtualRover/RobotController.h"

#define COORD_PRECISION	6	// Precision used for coordinate display.

NavigationWidget::NavigationWidget(QWidget *parent) :
		QWidget(parent)
{
	setupUi(this);

        //navView = new NavigationView(this);
        //verticalLayout->insertWidget(0, navView);
	connect(navView, SIGNAL(mouseAtGeoPos(QPointF)), this, SLOT(displayCoordinates(QPointF)));

	triangulationWidget = new TriangulationWidget();
	connect(triangulationButton, SIGNAL(clicked()), triangulationWidget, SLOT(show()));
        connect(connectLineButton, SIGNAL(clicked()), navView, SLOT(plotLineForSelected()));
        connect(markIsectButton, SIGNAL(clicked()), navView, SLOT(plotLineIntersection()));

        connect(requestGPSButton, SIGNAL(clicked()), this, SLOT(sendGPSRequest()));

        connect(RobotController::gpsController(), SIGNAL(gotPositionUpdate(GPSPositionData)), this, SLOT(gotGPSUpdate(GPSPositionData)));

        connect(navView, SIGNAL(newPointAdded(QPointF)), triangulationSidebar, SLOT(addPoint(QPointF)));
        connect(navView, SIGNAL(newLineAdded(QPointF,QPointF)), triangulationSidebar, SLOT(addLine(QPointF,QPointF)));
        connect(navView, SIGNAL(newLandmarkAdded(QPointF)), triangulationSidebar, SLOT(addLandmark(QPointF)));

        connect(triangulationSidebar, SIGNAL(selectPoint(QPointF, bool)), navView, SLOT(selectPoint(QPointF, bool)));
        connect(triangulationSidebar, SIGNAL(clearSelectedPoints()), navView, SLOT(clearSelectedPoints()));

        connect(triangulationSidebar, SIGNAL(drawLine(QPointF,QPointF)), navView, SLOT(plotLineForPoints(QPointF,QPointF)));
        connect(triangulationSidebar, SIGNAL(selectLines(QList<QPair<QPointF,QPointF> >)), navView, SLOT(selectLines(QList<QPair<QPointF,QPointF> >)));
        connect(triangulationSidebar, SIGNAL(clearSelectedLines()), navView, SLOT(clearSelectedLines()));
        connect(triangulationSidebar, SIGNAL(intersectLines()), navView, SLOT(plotLineIntersection()));

        connect(triangulationSidebar, SIGNAL(deleteLines()), navView, SLOT(deleteSelectedLines()));
        connect(triangulationSidebar, SIGNAL(deletePoints()), navView, SLOT(deleteSelectedPoints()));
	
	// Test rover slots
        /*navView->setRoverPosition(QPointF(-110.791497, 38.406392));
	navView->setRoverPosition(QPointF(-110.790889, 38.406158));
	navView->setRoverPosition(QPointF(-110.790469, 38.405850));
	navView->setRoverPosition(QPointF(-110.790257, 38.405575));
	navView->setRoverPosition(QPointF(-110.790161, 38.405359));
	navView->setRoverPosition(QPointF(-110.790177, 38.405195));
	navView->setRoverPosition(QPointF(-110.790037, 38.404941));
        navView->setRoverPosition(QPointF(-110.789840, 38.404890));
	navView->setRoverPosition(QPointF(-110.789420, 38.404986));
	navView->setRoverPosition(QPointF(-110.789219, 38.404973));
        navView->setRoverHeading(92.334915);*/

        //navView->setRoverPosition(QPointF(-123.212968,44.674917)); // adair
        //navView->setRoverPosition(QPointF(-123.274951,44.567328)); // covell parking lot
}

NavigationWidget::~NavigationWidget()
{
}

void NavigationWidget::displayCoordinates(const QPointF & coords)
{
	latitudeLabel->setText(QString("%1").arg(coords.y(), 0, 'f', COORD_PRECISION));
	longitudeLabel->setText(QString("%1").arg(coords.x(), 0, 'f', COORD_PRECISION));
}

void NavigationWidget::sendGPSRequest() {
    RobotController::gpsController()->sendGPSRequest();
}

void NavigationWidget::gotGPSUpdate(GPSPositionData dat) {
    double latitude = dat.lat_degrees/100;
    latitude = latitude + (double)((dat.lat_degrees-(int)latitude*100) + (double)dat.lat_mins/10000.0)/60.0;

    double longitude = dat.long_degrees/100;
    longitude = longitude + (double)((dat.long_degrees-(int)longitude*100) + (double)dat.long_mins/10000.0)/60.0;

    longitude = -longitude; // make this negative since we're in the western world and are always gonna be
    latitudeLabel->setText(QString::number(latitude, 'g', 10));
    longitudeLabel->setText(QString::number(longitude, 'g', 10));

    navView->setRoverPosition(QPointF(longitude, latitude));
    //navView->setRoverPosition(navView->mapGeoToScene(QPointF(latitude, longitude)));
}

void NavigationWidget::gotGPSHeading(GPSHeadingData dat) {
    navView->setRoverHeading(dat.true_track/10.0);
    headingLabel->setText(QString::number(dat.true_track/10.0, 'g', 1));
}

void NavigationWidget::on_addPointButton_clicked()
{
    NavigationPlaceDialog dlg;
    if (dlg.exec()==QDialog::Accepted) {
        navView->addPlace(navView->mapGeoToScene(dlg.getPoint()));
    }

}
