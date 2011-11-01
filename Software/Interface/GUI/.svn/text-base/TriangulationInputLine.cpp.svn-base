/*
 * TriangulationInputLine.cpp
 *
 * Created by Camden Lopez on 1/5/11
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#include <QPalette>

#include "TriangulationInputLine.h"

TriangulationInputLine::TriangulationInputLine(int anId, QWidget * parent) : QLineEdit(parent)
{
	id = anId;
	doubleValue = 0;
	valid = false;
	updateAppearance();
	connect(this, SIGNAL(textChanged(QString)), this, SLOT(validateText(QString)));
}

qreal TriangulationInputLine::value()
{
	return doubleValue;
}

void TriangulationInputLine::updateAppearance()
{
	QPalette tempPalette = palette();
	tempPalette.setColor(QPalette::Base, (valid) ? QColor(180, 255, 180) : QColor(255, 180, 180));
	setPalette(tempPalette);
}

void TriangulationInputLine::validateText(const QString & text)
{
	bool oldValid = valid;
	doubleValue = text.toDouble(&valid);
	if (valid != oldValid)
		updateAppearance();
	// Signal an update if value is newly invalid, and always when
	// it is valid so that widget can recalculate result.
	if (valid || valid != oldValid)
		emit hasUpdate(id, valid);
}