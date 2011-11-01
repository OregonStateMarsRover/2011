/*
 * NavigationRover.h
 *
 * Represents the rover in the graphics scene
 * of NavigationView.
 *
 * Created by Camden Lopez on 11/25/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#ifndef NAVIGATIONROVER_H
#define NAVIGATIONROVER_H

#include <QGraphicsItem>

class NavigationView;

class NavigationRover : public QGraphicsItem
{	
public:
	NavigationRover(NavigationView * navWidget, QGraphicsItem * parent = 0);
	~NavigationRover();
	void updatePos(const QPointF & scenePos);
	void resetTrack(const QPointF & start);
	void showLabel();
	void hideLabel();
	
	// Reimplemented from QGraphicsItem.
	QRectF boundingRect() const;
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
	QPainterPath shape() const;
	
protected:
	// Reimplemented from QGraphicsItem.
	void contextMenuEvent(QGraphicsSceneContextMenuEvent * event);
	QVariant itemChange(GraphicsItemChange change, const QVariant & value);
	
private:
	NavigationView * widget;
	QGraphicsPathItem * track;
	QGraphicsSimpleTextItem * label;
};

#endif // NAVIGATIONROVER_H
