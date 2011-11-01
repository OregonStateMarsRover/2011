/*
 * NavigationPlace.h
 *
 * Represents a place of interest in the graphics scene
 * of NavigationView.
 *
 * Created by Camden Lopez on 11/25/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#ifndef NAVIGATIONPLACE_H
#define NAVIGATIONPLACE_H

#include <QGraphicsItem>

class NavigationView;

class NavigationPlace : public QGraphicsItem
{	
public:
    NavigationPlace(NavigationView * navWidget, QColor col = Qt::blue, QGraphicsItem * parent = 0);
	~NavigationPlace();
	void setColor(const QColor & newColor);
	void showLabel();
	void hideLabel();
	
	// Reimplemented from QGraphicsItem.
	QRectF boundingRect() const;
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
	QPainterPath shape() const;

    public slots:
        void openScienceTab(QPointF mapPos);

protected:
	// Reimplemented from QGraphicsItem.
	void contextMenuEvent(QGraphicsSceneContextMenuEvent * event);
	QVariant itemChange(GraphicsItemChange change, const QVariant & value);

       virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
	NavigationView * widget;
	QGraphicsSimpleTextItem * label;
	QColor color;
	QPainterPath outline() const;
};

#endif // NAVIGATIONPLACE_H
