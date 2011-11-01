/*
 * NavigationRover.cpp
 *
 * Created by Camden Lopez on 11/25/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#include <QApplication>
#include <QClipboard>
#include <QCursor>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QPainter>

#include "NavigationView.h"

#include "NavigationRover.h"

#define COORD_PRECISION	6	// Precision used for coordinate label.
#define ROVERSIZE		15	// Radius of rover 'body' (pixels).

NavigationRover::NavigationRover(NavigationView * navWidget, QGraphicsItem * parent) :
		QGraphicsItem(parent)
{
	widget = navWidget;
	track = NULL;
	label = NULL;

	setCursor(Qt::ArrowCursor);
	setFlag(ItemIsSelectable, true);
	setFlag(ItemIgnoresTransformations, true);
	setZValue(10);
}

NavigationRover::~NavigationRover()
{
}

void NavigationRover::updatePos(const QPointF & scenePos)
{
	setPos(scenePos);
	if (!track) {
		track = new QGraphicsPathItem();
		QPen pen(Qt::red);
		pen.setStyle(Qt::DashLine);
		track->setPen(pen);
		resetTrack(scenePos);
		scene()->addItem(track);
	} else {
		QPainterPath newTrack = track->path();
		newTrack.lineTo(scenePos);
		track->setPath(newTrack);
	}
}

void NavigationRover::resetTrack(const QPointF & start)
{
	track->setPath(QPainterPath(start));
}

void NavigationRover::showLabel()
{
	if (!label) {
		label = new QGraphicsSimpleTextItem(this);
		label->setFont(QFont("Monospace", 12));
	}
	QPointF geoCoords = widget->mapSceneToGeo(pos());
	QString labelStr = QString("%1\n%2");
	labelStr = labelStr.arg(geoCoords.x(), 11, 'f', COORD_PRECISION);
	labelStr = labelStr.arg(geoCoords.y(), 11, 'f', COORD_PRECISION);
	label->setText(labelStr);
	qreal halfWidth = label->boundingRect().width() / 2;
	label->setPos(-halfWidth, ROVERSIZE);
	// Rotate the label about the center of the rover
	// to 'undo' the rover's rotation
	label->setTransformOriginPoint(halfWidth, -ROVERSIZE);
	label->setRotation(-rotation());
	label->show();
}

void NavigationRover::hideLabel()
{
	if (label)
		label->hide();
}

QRectF NavigationRover::boundingRect() const
{
	return QRectF(-ROVERSIZE - 0.5, -4 * ROVERSIZE - 0.5,
				  2 * ROVERSIZE + 1, 6 * ROVERSIZE + 1);
}

void NavigationRover::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	painter->setPen(Qt::red);
	painter->setBrush(QColor(255, 0, 0, 50));
	painter->setRenderHint(QPainter::Antialiasing, true);
	painter->drawEllipse(-ROVERSIZE, -ROVERSIZE, 2 * ROVERSIZE, 2 * ROVERSIZE);
	painter->drawLine(QPointF(0, ROVERSIZE / 3.0), QPointF(0, -ROVERSIZE / 3.0));
	painter->drawLine(QPointF(-ROVERSIZE / 3.0, 0), QPointF(ROVERSIZE / 3.0, 0));
	painter->drawLine(QPointF(0, -ROVERSIZE), QPointF(0, -5 * ROVERSIZE));
}

QPainterPath NavigationRover::shape() const
{
	QPainterPath path;
	path.addEllipse(-ROVERSIZE - 0.5, -ROVERSIZE - 0.5,
					2 * ROVERSIZE + 1, 2 * ROVERSIZE + 1);
	return path;
}

void NavigationRover::contextMenuEvent(QGraphicsSceneContextMenuEvent * event)
{
	QMenu menu;
	QAction * createPlaceAction = menu.addAction("Create Place Here");
	QAction * clearTrackAction = menu.addAction("Clear Track");
	QAction * copyLatitudeAction = menu.addAction("Copy Latitude");
	QAction * copyLongitudeAction = menu.addAction("Copy Longitude");
	QAction * copyHeading = menu.addAction("Copy Heading");
	QAction * execAction = menu.exec(event->screenPos());
	if (execAction == createPlaceAction)
			widget->addPlace(pos());
	else if (execAction == clearTrackAction)
		resetTrack(pos());
	else if (execAction == copyLatitudeAction)
		QApplication::clipboard()->setText(QString().setNum(widget->mapSceneToGeo(pos()).y(),
															'f', COORD_PRECISION));
	else if (execAction == copyLongitudeAction)
		QApplication::clipboard()->setText(QString().setNum(widget->mapSceneToGeo(pos()).x(),
															'f', COORD_PRECISION));
	else if (execAction == copyHeading)
		QApplication::clipboard()->setText(QString().setNum(rotation(),
															'f', COORD_PRECISION));
}

QVariant NavigationRover::itemChange(GraphicsItemChange change, const QVariant & value)
{
	if (change == ItemSelectedHasChanged) {
		if (value.toBool())
			showLabel();
		else
			hideLabel();
	}
	return QGraphicsItem::itemChange(change, value);
}
