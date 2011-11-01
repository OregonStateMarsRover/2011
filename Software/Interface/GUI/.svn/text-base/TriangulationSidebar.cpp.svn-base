#include <QDebug>
#include <QMessageBox>
#include <math.h>

#include "TriangulationSidebar.h"
#include "ui_TriangulationSidebar.h"

#include "VirtualRover/RobotController.h"
#include "Common/AltitudeCalculator.h"

TriangulationSidebar::TriangulationSidebar(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    lineMap = new QMap< QString, QPair<QPointF, QPointF> >();

    lineCounter = 0;

    connect(longitudeEdit, SIGNAL(textChanged(QString)), this, SLOT(recalculateDistanceAltitiude()));
    connect(latitudeEdit, SIGNAL(textChanged(QString)), this, SLOT(recalculateDistanceAltitiude()));

    connect(RobotController::tripodController(), SIGNAL(newBarometerData(short,ulong)), this, SLOT(newBarometerData(ushort,ulong)));
    connect(RobotController::tripodController(), SIGNAL(newAccelerometerData(short,short,short)), this, SLOT(newAccelerometerData(short,short,short)));

    connect(AltitudeCalculator::instance(), SIGNAL(newRoverAltitude(double,double)), this, SLOT(newRobotElevation(double,double)));
}

TriangulationSidebar::~TriangulationSidebar()
{
    delete lineMap;
}

void TriangulationSidebar::newBarometerData(ushort temp, ulong pressure) {

}

void TriangulationSidebar::newAccelerometerData(short x, short y, short z) {

}

void TriangulationSidebar::newRobotElevation(double absolute, double relative) {
    elevationEdit->setText(QString::number(absolute));
}

void TriangulationSidebar::addPoint(QPointF point) {
    QString str=QString::number(point.y())+", "+QString::number(point.x());
    QListWidgetItem *item = new QListWidgetItem(str);
    item->setData(Qt::UserRole, QVariant(point));
    pointsListWidget->addItem(item);
}

void TriangulationSidebar::addLine(const QPointF point1, const QPointF point2) {
    QString str = "Line "+QString::number(++lineCounter);
    QListWidgetItem *item = new QListWidgetItem(str);
    lineMap->insert(str, QPair<QPointF,QPointF>(point1, point2));
    linesListWidget->addItem(item);
}

void TriangulationSidebar::addLandmark(QPointF line) {
    QString str = "Landmark "+QString::number(landmarksListWidget->count()+1);
    QListWidgetItem *item = new QListWidgetItem(str);
    item->setData(Qt::UserRole, line);
    landmarksListWidget->addItem(item);
}

void TriangulationSidebar::on_pointsListWidget_itemSelectionChanged()
{
    QList<QListWidgetItem*> items = pointsListWidget->selectedItems();
    emit clearSelectedPoints();

    foreach(QListWidgetItem * item, items) {
        qDebug("emitting");
        emit selectPoint(item->data(Qt::UserRole).toPointF(), false);
    }
}

void TriangulationSidebar::on_drawLinesButton_clicked()
{
    QList<QListWidgetItem*> items = pointsListWidget->selectedItems();
    if (items.count()>1) {
        emit drawLine(items.at(0)->data(Qt::UserRole).toPointF(), items.at(0)->data(Qt::UserRole).toPointF());
    }
}

void TriangulationSidebar::on_linesListWidget_itemSelectionChanged()
{
    QList<QListWidgetItem*> items = linesListWidget->selectedItems();
    emit clearSelectedLines();
    QList< QPair<QPointF, QPointF> > lines;

    foreach(QListWidgetItem * item, items) {
        qDebug() << "getting selected line" << item->text();
        lines.append(lineMap->value(item->text()));
    }
    if (lines.count()>0)
        emit selectLines(lines);
}

void TriangulationSidebar::on_intersectLinesButton_clicked()
{
    emit intersectLines();
}

void TriangulationSidebar::on_deletePoints_clicked()
{
    if (QMessageBox::question(this, "Delete Points","Are you sure you want to delete the selected points?",QMessageBox::Yes,QMessageBox::No)==QMessageBox::No) {
        return;
    }
    emit deletePoints();

    QList<QListWidgetItem*> items = pointsListWidget->selectedItems();
    foreach(QListWidgetItem * item, items) {
       qDebug() << "removing a point";
       pointsListWidget->takeItem(pointsListWidget->row(item));
    }
}

void TriangulationSidebar::on_deleteLines_clicked()
{
    if (QMessageBox::question(this, "Delete Lines","Are you sure you want to delete the selected lines?",QMessageBox::No,QMessageBox::Yes)==QMessageBox::No) {
        return;
    }
    emit deleteLines();

    QList<QListWidgetItem*> items = linesListWidget->selectedItems();
    foreach(QListWidgetItem * item, items) {
       linesListWidget->takeItem(linesListWidget->row(item));
    }
}

// this code borrows heavily from the Javascript http://grapevine.abe.msstate.edu/~fto/calculator/converte.html
double TriangulationSidebar::findMapDistance(QPointF point1, QPointF point2) {
    double rad_dist = findRadianDistance(point1, point2);

    double nautical_miles = rad_dist * 3437.73877;
    return nautical_miles*1852;
}

void TriangulationSidebar::recalculateDistanceAltitiude() {
    QPointF point1, point2;

    if (landmarksListWidget->selectedItems().count()==1)
        point1 = landmarksListWidget->selectedItems().at(0)->data(Qt::UserRole).toPointF();

    point2.setY(latitudeEdit->text().toDouble());
    point2.setX(longitudeEdit->text().toDouble());

    double landmarkDistance = findMapDistance(point1, point2);
    pointDistanceEdit->setText(QString::number(landmarkDistance));

    landmarkElevation->setText(QString::number(landmarkDistance * tan(cameraAngleEdit->text().toDouble()*M_PI/180.0)));
}

// this code borrows heavily from the Javascript http://grapevine.abe.msstate.edu/~fto/calculator/converte.html (calcraddistance())
double TriangulationSidebar::findRadianDistance(QPointF point1, QPointF point2) {
    // latitiude = y
    // longitude = x
    double t1, t2, t3, t4, t5;

    double a = M_PI / 180.0;
    long double lat1, long1, lat2, long2;

    point1.setY(fabs(point1.y())*a);
    point2.setY(fabs(point2.y())*a);

    point1.setX(fabs(point1.x())*a);
    point2.setX(fabs(point2.x())*a);

    t1 = sin(point1.y()) * sin(point2.y());
    t2 = cos(point1.y()) * cos(point2.y());
    t3 = cos(point1.x() - point2.x());
    t4 = t2 * t3;
    t5 = t1 + t4;
    double rad_dist = atan(-t5/sqrt(-t5 * t5 +1)) + 2 * atan(1);
    return rad_dist;
}

void TriangulationSidebar::on_landmarksListWidget_itemSelectionChanged()
{
    // todo, highlight this landmark
    recalculateDistanceAltitiude();
}
