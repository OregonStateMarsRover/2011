/*
 * TriangulationInputLine.h
 *
 * Customized QLineEdit for input fields in TriangulationWidget.
 *
 * Created by Camden Lopez on 1/5/11
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#ifndef TRIANGULATIONINPUTLINE_H
#define TRIANGULATIONINPUTLINE_H

#include <QLineEdit>

class TriangulationInputLine : public QLineEdit
{
	Q_OBJECT
	
public:
	TriangulationInputLine(int anId, QWidget * parent = 0);
	qreal value();
	
signals:
	void hasUpdate(int id, bool valid);
	
private:
	int id;
	qreal doubleValue;
	bool valid;
	void updateAppearance();
	
private slots:
	void validateText(const QString & text);
};

#endif	// TRIANGULATIONINPUTLINE_H