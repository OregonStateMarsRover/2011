#ifndef TRIANGULATIONSIDEBAR_H
#define TRIANGULATIONSIDEBAR_H

#include <QWidget>
#include <QMap>
#include <QPair>
#include <QPointF>

#include "ui_TriangulationSidebar.h"

class TriangulationSidebar : public QWidget, private Ui::TriangulationSidebar
{
    Q_OBJECT

public:
    explicit TriangulationSidebar(QWidget *parent = 0);
    ~TriangulationSidebar();

public slots:
    void addPoint(QPointF point);
    void addLine(QPointF point1, QPointF point2);
    void addLandmark(QPointF landmark);

signals:
    void drawLine(QPointF point1, QPointF point2);
    void intersectLines();

    void selectPoint(QPointF point, bool clearSelection);
    void clearSelectedPoints();

    void selectLines(QList< QPair< QPointF, QPointF > > lines);
    void clearSelectedLines();

    void deletePoints();
    void deleteLines();

private slots:
    void on_landmarksListWidget_itemSelectionChanged();
    void on_deleteLines_clicked();
    void on_deletePoints_clicked();
    void on_intersectLinesButton_clicked();
    void on_linesListWidget_itemSelectionChanged();
    void on_drawLinesButton_clicked();
    void on_pointsListWidget_itemSelectionChanged();

    void recalculateDistanceAltitiude();
    void newBarometerData(ushort temp, ulong pressure);
    void newAccelerometerData(short x, short y, short z);

    void newRobotElevation(double absolute, double elevation);

private:
    QMap< QString, QPair<QPointF,QPointF> > * lineMap;
    int lineCounter;

    // computes distance between two map coordinates
    double findMapDistance(QPointF point1, QPointF point2);
    double findRadianDistance(QPointF point1, QPointF point2);
};

#endif // TRIANGULATIONSIDEBAR_H
