/*
 * NavigationPlace.cpp
 *
 * Created by Camden Lopez on 11/25/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#include <QApplication>
#include <QClipboard>
#include <QColorDialog>
#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QPainter>
#include <QVariant>

#include "NavigationView.h"

#include "NavigationPlace.h"

#define COORD_PRECISION	6	// Precision used for coordinate label.
#define NAV_PLACESIZE	10	// Half the width of the placemarker (pixels).

NavigationPlace::NavigationPlace(NavigationView * navWidget, QColor col, QGraphicsItem * parent) :
		QGraphicsItem(parent),
                color(col)
{
	widget = navWidget;
	label = NULL;

	setCursor(Qt::ArrowCursor);
	setFlag(ItemIsSelectable, true);
	setFlag(ItemIgnoresTransformations, true);
	setZValue(20);
}

NavigationPlace::~NavigationPlace()
{
}

void NavigationPlace::setColor(const QColor & newColor)
{
	color = newColor;
	update();
}

void NavigationPlace::showLabel()
{
	if (!label) {
		label = new QGraphicsSimpleTextItem(this);
		label->setFlag(ItemIgnoresTransformations, true);
		label->setFont(QFont("Monospace", 12));
		QPointF geoCoords = widget->mapSceneToGeo(pos());
		QString labelStr = QString("%1\n%2");
		labelStr = labelStr.arg(geoCoords.x(), 11, 'f', COORD_PRECISION);
		labelStr = labelStr.arg(geoCoords.y(), 11, 'f', COORD_PRECISION);
		label->setText(labelStr);
		label->setPos(QPointF(-label->boundingRect().width() / 2, 0));
	}
	label->show();
}

void NavigationPlace::hideLabel()
{
	if (label)
		label->hide();
}

QRectF NavigationPlace::boundingRect() const
{
	return QRectF(-NAV_PLACESIZE - 0.5, -4 * NAV_PLACESIZE - 0.5,
				  2 * NAV_PLACESIZE + 1, 4 * NAV_PLACESIZE + 1);
}

void NavigationPlace::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	QColor colorCopy(color);
	painter->setPen(colorCopy);

	// Make the 'body' of the placemarker slightly transparent
	colorCopy.setAlpha(100);
	painter->setBrush(colorCopy);
	painter->setRenderHint(QPainter::Antialiasing, true);

        if (isSelected())
            painter->setPen(Qt::black);

	painter->drawPath(outline());
}

QPainterPath NavigationPlace::shape() const
{
	return outline();
}

void NavigationPlace::contextMenuEvent(QGraphicsSceneContextMenuEvent * event)
{
	QMenu menu;
	QAction * selectColorAction = menu.addAction("Select Color");
	QAction * copyLatitudeAction = menu.addAction("Copy Latitude");
	QAction * copyLongitudeAction = menu.addAction("Copy Longitude");
	QAction * deleteAction = menu.addAction("Delete");
        QAction * gotoAction = menu.addAction("Open Data");
	QAction * execAction = menu.exec(event->screenPos());
	if (execAction == selectColorAction) {
		QColorDialog colorDialog(color);
		if (colorDialog.exec() == QDialog::Accepted)
			setColor(colorDialog.currentColor());
	} else if (execAction == copyLatitudeAction)
		QApplication::clipboard()->setText(QString().setNum(widget->mapSceneToGeo(pos()).y(),
															'f', COORD_PRECISION));
	else if (execAction == copyLongitudeAction)
		QApplication::clipboard()->setText(QString().setNum(widget->mapSceneToGeo(pos()).x(),
															'f', COORD_PRECISION));
	else if (execAction == deleteAction)
		widget->deletePlace(this);
        else if (execAction == gotoAction) {
            qDebug("goto science!");
            //signal(openScienceTab(this->pos()));
        }
}

QVariant NavigationPlace::itemChange(GraphicsItemChange change, const QVariant & value)
{
	if (change == ItemSelectedHasChanged) {
		if (value.toBool())
			showLabel();
		else
			hideLabel();
	}
	return QGraphicsItem::itemChange(change, value);
}

QPainterPath NavigationPlace::outline() const
{
	QPainterPath path;
	// Draw curve from base point to left side of 'bulb'
	path.cubicTo(0, -2 * NAV_PLACESIZE,					// Control point 1
				 -NAV_PLACESIZE, -2 * NAV_PLACESIZE,	// Control point 2
				 -NAV_PLACESIZE, -3 * NAV_PLACESIZE);	// End point
	// Draw top of 'bulb'
	path.arcTo(-NAV_PLACESIZE, -4 * NAV_PLACESIZE,		// Upper-left corner of bounding rectangle
			   2 * NAV_PLACESIZE, 2 * NAV_PLACESIZE,	// Width, height
			   180, -180);								// Start, sweep angles
	// Draw curve from right side of 'bulb' back to base point
	path.cubicTo(NAV_PLACESIZE, -2 * NAV_PLACESIZE,
				 0, -2 * NAV_PLACESIZE, 0, 0);
	return path;
}

/*void NavigationPlace::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event) {
    qDebug("double clicked");

}*/

void NavigationPlace::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    qDebug("click %d!", event->type());
}
