/*
 * TriangulationWidget.cpp
 *
 * Created by Camden Lopez on 1/4/11
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#include <QLineF>
#include <QTime>

#include "TriangulationInputLine.h"

#include "TriangulationWidget.h"

#define N_INPUTS	6		// Used for bitmap operations to determine
							// whether all the inputs are valid.
#define LEG_LENGTH	1000	// See calculateResult(). Use a larger number for
							// calculating intersections at a greater distance
							// from the two known points.

TriangulationWidget::TriangulationWidget(QWidget *parent) :
		QWidget(parent),
		lastRoverPos(0, 0),
		lastRoverHeading(0),
		validBitmap(0)
{
    setupUi(this);
	setupInputs();

	connect(setToRoverButtonA, SIGNAL(clicked()), this, SLOT(setInputAToRover()));
	connect(setToRoverButtonB, SIGNAL(clicked()), this, SLOT(setInputBToRover()));
	connect(saveToLogButton, SIGNAL(clicked()), this, SLOT(saveToLog()));
	connect(clearLogButton, SIGNAL(clicked()), this, SLOT(clearLog()));
}

TriangulationWidget::~TriangulationWidget()
{
}

void TriangulationWidget::updateRoverPosAndHeading(const QPointF & pos, qreal heading)
{
	updateRoverPosition(pos);
	updateRoverHeading(heading);
}

void TriangulationWidget::updateRoverPosition(const QPointF & pos)
{
	lastRoverPos = pos;
}

void TriangulationWidget::updateRoverHeading(qreal heading)
{
	lastRoverHeading = heading;
}

void TriangulationWidget::calculateResult()
{
	// Convert heading (North = 0, positive = clockwise) to
	// angle (3 o'clock = 0, positive = counterclockwise)
	qreal angleA = 90 - headingInputA->value(), angleB = 90 - headingInputB->value();
	// Create two lines of length LEG_LENGTH starting at points A and B,
	// given by the latitude and longitude inputs, and with initial angle
	// of 0. Then set the angle to the one calculated above.
	QLineF lineA, lineB;
	QPointF pointC;
	lineA.setP1(QPointF(longitudeInputA->value(), -latitudeInputA->value()));
	lineA.setP2(QPointF(lineA.x1() + LEG_LENGTH, lineA.y1()));
	lineA.setAngle(angleA);
	lineB.setP1(QPointF(longitudeInputB->value(), -latitudeInputB->value()));
	lineB.setP2(QPointF(lineB.x1() + LEG_LENGTH, lineB.y1()));
	lineB.setAngle(angleB);
	// See Qt documentation of QLineF::intersect() for an explanation of
	// BoundedIntersection vs. UnboundedIntersection.
	if (lineA.intersect(lineB, &pointC) == QLineF::BoundedIntersection) {
		resultOutput->setText(QString("%1, %2").arg(-pointC.y(), 0, 'f', 6).arg(pointC.x(), 0, 'f', 6));
		saveToLogButton->setEnabled(true);
	} else {
		resultOutput->setText("No intersection");
		saveToLogButton->setEnabled(false);
	}
}

void TriangulationWidget::clearResult()
{
	resultOutput->setText("");
	saveToLogButton->setEnabled(false);
}

void TriangulationWidget::setupInputs()
{
	int nextId = 0;
	latitudeInputA = new TriangulationInputLine(nextId++, this);
	gridLayout->addWidget(latitudeInputA, 1, 1);
	connect(latitudeInputA, SIGNAL(hasUpdate(int, bool)),
			this, SLOT(receiveInputUpdate(int, bool)));
	longitudeInputA = new TriangulationInputLine(nextId++, this);
	gridLayout->addWidget(longitudeInputA, 2, 1);
	connect(longitudeInputA, SIGNAL(hasUpdate(int, bool)),
			this, SLOT(receiveInputUpdate(int, bool)));
	headingInputA = new TriangulationInputLine(nextId++, this);
	gridLayout->addWidget(headingInputA, 3, 1);
	connect(headingInputA, SIGNAL(hasUpdate(int, bool)),
			this, SLOT(receiveInputUpdate(int, bool)));
	latitudeInputB = new TriangulationInputLine(nextId++, this);
	gridLayout->addWidget(latitudeInputB, 1, 2);
	connect(latitudeInputB, SIGNAL(hasUpdate(int, bool)),
			this, SLOT(receiveInputUpdate(int, bool)));
	longitudeInputB = new TriangulationInputLine(nextId++, this);
	gridLayout->addWidget(longitudeInputB, 2, 2);
	connect(longitudeInputB, SIGNAL(hasUpdate(int, bool)),
			this, SLOT(receiveInputUpdate(int, bool)));
	headingInputB = new TriangulationInputLine(nextId++, this);
	gridLayout->addWidget(headingInputB, 3, 2);
	connect(headingInputB, SIGNAL(hasUpdate(int, bool)),
			this, SLOT(receiveInputUpdate(int, bool)));
}

void TriangulationWidget::receiveInputUpdate(int id, bool valid)
{
	if (valid)
		validBitmap |= (1 << id);
	else
		validBitmap &= ~(1 << id);
	if (validBitmap + 1 == (1 << N_INPUTS))
		calculateResult();
	else
		clearResult();
}

void TriangulationWidget::setInputAToRover()
{
	latitudeInputA->setText(QString("%1").arg(lastRoverPos.y(), 0, 'f', 6));
	longitudeInputA->setText(QString("%1").arg(lastRoverPos.x(), 0, 'f', 6));
	headingInputA->setText(QString("%1").arg(lastRoverHeading, 0, 'f', 6));
}

void TriangulationWidget::setInputBToRover()
{
	latitudeInputB->setText(QString("%1").arg(lastRoverPos.y(), 0, 'f', 6));
	longitudeInputB->setText(QString("%1").arg(lastRoverPos.x(), 0, 'f', 6));
	headingInputB->setText(QString("%1").arg(lastRoverHeading, 0, 'f', 6));
}

void TriangulationWidget::saveToLog()
{
	QString logEntry;
	logEntry += "Logged at " + QTime::currentTime().toString() + "\n";
	logEntry += "Point A: " +
		latitudeInputA->text() + ", " +
		longitudeInputA->text() + " (" +
		headingInputA->text() + ")\n";
	logEntry += "Point B: " +
		latitudeInputB->text() + ", " +
		longitudeInputB->text() + " (" +
		headingInputB->text() + ")\n";
	logEntry += "Intersection: " + resultOutput->text() + "\n";
	logTextEdit->append(logEntry);
}

void TriangulationWidget::clearLog()
{
	logTextEdit->setText("");
}
