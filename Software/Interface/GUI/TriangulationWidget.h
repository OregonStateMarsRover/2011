/*
 * TriangulationWidget.h
 *
 * Calculates the location of a point via triangulation.
 *
 * Created by Camden Lopez on 1/4/11
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#ifndef TRIANGULATIONWIDGET_H
#define TRIANGULATIONWIDGET_H

#include "ui_TriangulationWidget.h"

class TriangulationInputLine;

class TriangulationWidget : public QWidget, private Ui::TriangulationWidget
{
    Q_OBJECT

public:
    explicit TriangulationWidget(QWidget *parent = 0);
	~TriangulationWidget();
	
public slots:
	void updateRoverPosAndHeading(const QPointF & pos, qreal heading);
	void updateRoverPosition(const QPointF & pos);
	void updateRoverHeading(qreal heading);

private:
	QPointF lastRoverPos;
	qreal lastRoverHeading;
	int validBitmap;
	TriangulationInputLine
			* latitudeInputA, * longitudeInputA, * headingInputA,
			* latitudeInputB, * longitudeInputB, * headingInputB;
	void calculateResult();
	void clearResult();
	void setupInputs();
	
private slots:
	void receiveInputUpdate(int id, bool valid);
	void setInputAToRover();
	void setInputBToRover();
	void saveToLog();
	void clearLog();
};

#endif // TRIANGULATIONWIDGET_H
