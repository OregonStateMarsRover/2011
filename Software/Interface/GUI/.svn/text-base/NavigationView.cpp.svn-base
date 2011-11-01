/*
 * NavigationView.cpp
 *
 * Created by Camden Lopez on 11/10/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#include <QKeyEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QWheelEvent>
#include <QDebug>

#include "../Common/Configuration.h"
#include "NavigationPlace.h"
#include "NavigationRover.h"
#include "IntersectionLineItem.h"

#include "NavigationView.h"
#include "stdio.h"

NavigationView::NavigationView(QWidget * parent) :
		QGraphicsView(parent),
		geoRect(-1, 1, 2, 2)	// Arbitrary default.
{
	rover = NULL;
        printf("1");
        QGraphicsScene s(0, 0, 1300, 1300, this);
        //QPixmap g(":/home/francis/marsrover2011/Software/Interface/GUI/Resources/Maps/Utah.jpg");
        //QPixmap g(":Interface/GUI/Resources/Maps/Utah.jpg");
        //s.addPixmap(g);
        //setScene(&s);
        setScene(new QGraphicsScene(0, 0, 1000, 1000, this));	// Arbitrary default.
	updateConfiguration();		// Override defaults using config file.
	
	setMouseTracking(true);		// Generate mouse move events for coordinate display.
	setCursor(Qt::CrossCursor);
}

NavigationView::~NavigationView()
{
}

NavigationPlace * NavigationView::addPlace(const QPointF & scenePos, QColor col, bool emitSignal)
{
        NavigationPlace * newPlace = new NavigationPlace(this, col);
	newPlace->setPos(scenePos);
	scene()->addItem(newPlace);

        if (emitSignal)
        emit newPointAdded(mapSceneToGeo(scenePos));
	return newPlace;
}

void NavigationView::deletePlace(NavigationPlace * place)
{
	scene()->removeItem(place);
	delete place;
}

qreal NavigationView::sceneXForLongitude(qreal longitude) const
{
	return (longitude - geoRect.left()) * scene()->width() / geoRect.width();
}

qreal NavigationView::sceneYForLatitude(qreal latitude) const
{
	return (geoRect.top() - latitude) * scene()->height() / geoRect.height();
}

qreal NavigationView::longitudeForSceneX(qreal x) const
{
	return geoRect.left() + x * geoRect.width() / scene()->width();
}

qreal NavigationView::latitudeForSceneY(qreal y) const
{
	return geoRect.top() - y * geoRect.height() / scene()->height();
}

QPointF NavigationView::mapGeoToScene(const QPointF & geoCoords) const
{
	return QPointF(sceneXForLongitude(geoCoords.x()),
				   sceneYForLatitude(geoCoords.y()));
}

QPointF NavigationView::mapSceneToGeo(const QPointF & scenePos) const
{
	return QPointF(longitudeForSceneX(scenePos.x()),
				   latitudeForSceneY(scenePos.y()));
}

#define ZOOMFACTOR	1.1
#define MAXZOOM		5.0

void NavigationView::zoomIn()
{
	if (transform().m11() * ZOOMFACTOR <= MAXZOOM)	// m11 = horizontal scaling factor
		scale(ZOOMFACTOR, ZOOMFACTOR);				// of the scene.
}

void NavigationView::zoomOut()
{
	if (scene()->width() * transform().m11() / ZOOMFACTOR >= width() &&
		scene()->height() * transform().m11() / ZOOMFACTOR >= height())
		scale(1.0 / ZOOMFACTOR, 1.0 / ZOOMFACTOR);
}

void NavigationView::setRoverPosAndHeading(const QPointF & pos, qreal heading)
{
	setRoverPosition(pos);
	setRoverHeading(heading);
}

void NavigationView::setRoverPosition(const QPointF & geoCoords)
{
	if (!rover) {
		rover = new NavigationRover(this);
		scene()->addItem(rover);
	}
	rover->updatePos(mapGeoToScene(geoCoords));
}

void NavigationView::setRoverHeading(qreal heading)
{
	if (rover)
		rover->setRotation(heading);
}

void NavigationView::updateConfiguration()
{
	Configuration config("GUI/NavigationView.config");
        if (config.contains("img-path")) {
            qDebug() << "painting"<<config["img-path"];
		scene()->setBackgroundBrush(QBrush(QPixmap(config["img-path"])));
            }
	if (config.contains("img-width") && config.contains("img-height")) {
		bool widthOk, heightOk;
		qreal width = config["img-width"].toDouble(&widthOk);
		qreal height = config["img-height"].toDouble(&heightOk);
		if (widthOk && heightOk)
                        scene()->setSceneRect(0, 0, width, height);
	}
	if (config.contains("map-top") && config.contains("map-left") &&
		config.contains("map-width") && config.contains("map-height")) {
		bool topOk, leftOk, widthOk, heightOk;
		qreal top = config["map-top"].toDouble(&topOk);
		qreal left = config["map-left"].toDouble(&leftOk);
		qreal width = config["map-width"].toDouble(&widthOk);
		qreal height = config["map-height"].toDouble(&heightOk);
		if (topOk && leftOk && widthOk && heightOk)
			geoRect = QRectF(left, top, width, height);
	}
}

void NavigationView::plotLineForPoints(QPointF point1, QPointF point2) {
    plotLineForSelected();
}

void NavigationView::plotLineForSelected() {
    if (scene()->selectedItems().count()<2)
        return;

    QLineF vectorLine(scene()->selectedItems().at(0)->pos(), scene()->selectedItems().at(1)->pos());

    QLineF sides[4] = {
        QLineF(0, 0, 0, scene()->height()),
        QLineF(scene()->width(), 0, scene()->width(), scene()->height()),
        QLineF(0, 0, scene()->width(), 0),
        QLineF(0, scene()->height(), scene()->width(), scene()->height())
    };

    QPointF yStart;
    QPointF xStart;
    int i=0;

    while(yStart.isNull()) {
        if (vectorLine.intersect(sides[i++], &yStart)!=QLineF::BoundedIntersection) {
            qDebug("could not intersect y");
        }
        i++;
    }

    i=1;

    while(xStart.isNull()) {
        if (vectorLine.intersect(sides[i++], &xStart)!=QLineF::BoundedIntersection) {
            qDebug("could not intersect x");
        }
    }

    //IntersectionLineItem lineItem(QLineF(yStart, xStart);

    QPen linePen(Qt::black);
    linePen.setWidth(3);
    QGraphicsLineItem * line = scene()->addLine(QLineF(yStart, xStart));
    line->setPen(linePen);
    line->setFlag(QGraphicsItem::ItemIsSelectable, true);

    emit newLineAdded(mapSceneToGeo(scene()->selectedItems().at(0)->pos()), mapSceneToGeo(scene()->selectedItems().at(1)->pos()));
}

void NavigationView::plotLineIntersection() {
    if (scene()->selectedItems().count()<2)
        return;

    QPointF intersectPoint;
    QLineF line1, line2;

    line1 = ((QGraphicsLineItem*)(scene()->selectedItems().at(0)))->line();
    line2 = ((QGraphicsLineItem*)(scene()->selectedItems().at(1)))->line();

    if (line1.intersect(line2, &intersectPoint)!=QLineF::BoundedIntersection) {
        qDebug("lines did not intersect");
        return;
    }

    addPlace(intersectPoint, Qt::red, false);
    newLandmarkAdded(mapSceneToGeo(intersectPoint));
}

void NavigationView::clearSelectedPoints() {
    QList<QGraphicsItem*> items = scene()->selectedItems();
    foreach(QGraphicsItem * item, items) {
        if (item->type()==QGraphicsItem::UserType) {
            item->setSelected(false);
        }
    }
}

void NavigationView::selectLines(QList< QPair< QPointF, QPointF > > lines) {
    QPair<QPointF, QPointF> lst;
    foreach (lst, lines) {
        QList<QGraphicsItem*> itemsOne = scene()->items(mapGeoToScene(lst.first),Qt::IntersectsItemBoundingRect, Qt::AscendingOrder);
        QList<QGraphicsItem*> itemsTwo = scene()->items(mapGeoToScene(lst.second),Qt::IntersectsItemBoundingRect, Qt::AscendingOrder);

        foreach (QGraphicsItem * lineItem, itemsOne) {
            if (lineItem->type()==QGraphicsLineItem::Type && itemsTwo.contains(lineItem)) { // found what we need to add!
                lineItem->setSelected(true);
                int idx = itemsTwo.indexOf(lineItem);
                if (idx>-1) {
                    itemsTwo.at(idx)->setSelected(true);
                }
                break;
            }
        }
    }
}

void NavigationView::clearSelectedLines() {
    QList<QGraphicsItem*> items = scene()->selectedItems();
    foreach(QGraphicsItem * item, items) {
        if (item->type()==QGraphicsLineItem::Type) {
            item->setSelected(false);
        }
    }
}

void NavigationView::selectPoint(QPointF point, bool clearSelection) {
    QList<QGraphicsItem*> items;

    if (clearSelection) {
        items = scene()->selectedItems();
        foreach(QGraphicsItem * item, items) {
            item->setSelected(false);
        }
    }
    items = scene()->items(mapGeoToScene(point),Qt::IntersectsItemBoundingRect, Qt::AscendingOrder);
    foreach(QGraphicsItem * item, items) {
        if (item->type()==QGraphicsItem::UserType) {
            item->setSelected(true);
        }
    }

}

void NavigationView::deleteSelectedPoints() {
    QList<QGraphicsItem*> items = scene()->selectedItems();
    foreach(QGraphicsItem * item, items) {
        if (item->type()==QGraphicsItem::UserType) {
            scene()->removeItem(item);
        }
    }
}

void NavigationView::deleteSelectedLines() {
    QList<QGraphicsItem*> items = scene()->selectedItems();
    foreach(QGraphicsItem * item, items) {
        if (item->type()==QGraphicsLineItem::Type) {
            scene()->removeItem(item);
        }
    }
}

void NavigationView::keyPressEvent(QKeyEvent * event)
{
	if (event->key() == Qt::Key_Control)
		setDragMode(QGraphicsView::ScrollHandDrag);

        if (event->key() == Qt::Key_Return)
            plotLineForSelected();
}

void NavigationView::keyReleaseEvent(QKeyEvent * event)
{
	if (event->key() == Qt::Key_Control)
		setDragMode(QGraphicsView::NoDrag);
}

void NavigationView::mouseDoubleClickEvent(QMouseEvent * event)
{
    event->ignore();

    if (event->button() == Qt::LeftButton)
        addPlace(mapToScene(event->pos()));
}

void NavigationView::mouseMoveEvent(QMouseEvent * event)
{
	emit mouseAtGeoPos(mapSceneToGeo(mapToScene(event->pos())));
	QGraphicsView::mouseMoveEvent(event);
}

void NavigationView::wheelEvent(QWheelEvent * event)
{
	if (event->delta() >= 0)
		zoomIn();
	else
		zoomOut();


}
