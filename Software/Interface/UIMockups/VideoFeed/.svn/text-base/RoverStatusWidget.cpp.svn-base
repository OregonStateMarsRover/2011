#include "RoverStatusWidget.h"
#include "ui_RoverStatusWidget.h"

#include <QGraphicsPixmapItem>
#include <QPaintEvent>
#include <QBrush>
#include <QLineF>

RoverStatusWidget::RoverStatusWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RoverStatusWidget)
{
   // setPalette(Qt::transparent);
    ui->setupUi(this);

    QPalette p(palette());
    p.setColor(QPalette::Background, QColor( 0xFF, 0xFF, 0xFF, 70));
    setPalette( p );

    populateImages();
}

RoverStatusWidget::~RoverStatusWidget()
{
    delete ui;
}

void RoverStatusWidget::populateImages() {
    QPixmap cameraRotate("VideoResources/camera.png");
    QPixmap roverRotate("VideoResources/rover-cube.png");

    QGraphicsScene * roverScn = new QGraphicsScene(ui->roverTiltView);
    ui->roverTiltView->setScene(roverScn);
    roverScn->addPixmap(roverRotate.scaled(90,90, Qt::IgnoreAspectRatio));

    ui->roverTiltView->setAttribute(Qt::WA_TranslucentBackground);
    ui->roverTiltView->viewport()->setAutoFillBackground(false);

    QGraphicsScene * cameraScn = new QGraphicsScene(ui->cameraTiltView);
    ui->cameraTiltView->setScene(cameraScn);
    ui->cameraTiltView->setAttribute(Qt::WA_TranslucentBackground);
    ui->cameraTiltView->viewport()->setAutoFillBackground(false);

    QPen circlePen(Qt::black);
    circlePen.setBrush(QBrush(Qt::black));
    circlePen.setWidth(2);
    cameraScn->addEllipse(5,5,ui->cameraTiltView->width()-10, ui->cameraTiltView->height()-10, circlePen);

    QPointF centerPoint(5+(ui->cameraTiltView->width()-10)/2, 5+(ui->cameraTiltView->height()-10)/2);
    QPointF edgePoint(ui->cameraTiltView->width()-7, 5+(ui->cameraTiltView->height()-10)/2);
    cameraScn->addLine(QLineF(centerPoint, edgePoint), circlePen);

    QPen posPen(Qt::red);
    posPen.setBrush(QBrush(Qt::red));
    posPen.setWidth(4);

    QLineF posLine(centerPoint, edgePoint);
    posLine.setAngle(34);
    cameraScn->addLine(posLine, posPen);

    cameraScn->addText(trUtf8("34°"))->setPos(centerPoint);
}

void RoverStatusWidget::enterEvent(QEvent * event) {
    QPalette p(palette());
    p.setColor(QPalette::Background, QColor( 0xFF, 0xFF, 0xFF, 255));
    setPalette( p );
}

void RoverStatusWidget::leaveEvent(QEvent * event) {
    QPalette p(palette());
    p.setColor(QPalette::Background, QColor( 0xFF, 0xFF, 0xFF, 70));
    setPalette( p );
}
