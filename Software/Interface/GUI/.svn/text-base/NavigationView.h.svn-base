/*
 * NavigationView.h
 *
 * The graphics view of NavigationWidget.
 *
 * Created by Camden Lopez on 11/10/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#ifndef NAVIGATIONVIEW_H
#define NAVIGATIONVIEW_H

#include <QGraphicsView>

class NavigationPlace;
class NavigationRover;

class NavigationView : public QGraphicsView
{
    Q_OBJECT

public:
	explicit NavigationView(QWidget * parent = 0);
	~NavigationView();
        NavigationPlace * addPlace(const QPointF & scenePos, QColor col = Qt::blue, bool emitSignal = true);
	void deletePlace(NavigationPlace * place);
	qreal sceneXForLongitude(qreal longitude) const;
	qreal sceneYForLatitude(qreal latitude) const;
	qreal longitudeForSceneX(qreal x) const;
	qreal latitudeForSceneY(qreal y) const;
	QPointF mapGeoToScene(const QPointF & geoCoords) const;
	QPointF mapSceneToGeo(const QPointF & scenePos) const;
	void zoomIn();
	void zoomOut();
	
public slots:
	void setRoverPosAndHeading(const QPointF & pos, qreal heading);
	void setRoverPosition(const QPointF & geoCoords);
	void setRoverHeading(qreal heading);
	void updateConfiguration();

        void plotLineForSelected();
        void plotLineForPoints(QPointF point1, QPointF point2);
        void plotLineIntersection();

        void selectPoint(QPointF point, bool clearSelection = false);
        void clearSelectedPoints();

        void selectLines(QList< QPair< QPointF, QPointF > > lines);
        void clearSelectedLines();

        void deleteSelectedPoints();
        void deleteSelectedLines();


signals:
	void mouseAtGeoPos(const QPointF & coords);
        void newPointAdded(const QPointF point);
        void newLineAdded(QPointF point1, QPointF point2);
        void newLandmarkAdded(const QPointF point);
	
protected:
	// Reimplemented from QGraphicsView.
	void keyPressEvent(QKeyEvent * event);
	void keyReleaseEvent(QKeyEvent * event);
	void mouseDoubleClickEvent(QMouseEvent * event);
	void mouseMoveEvent(QMouseEvent * event);
	void wheelEvent(QWheelEvent * event);
	
private:
	QRectF geoRect;
        NavigationRover * rover;
};

#endif // NAVIGATIONVIEW_H
