/*
 * CameraWidget.cpp
 *
 * Created by Camden Lopez on 11/10/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#include "VirtualRover/RobotController.h"
#include "CameraWidget.h"

CameraWidget::CameraWidget(QWidget *parent) : QWidget(parent)
{
    setupUi(this);

    connect(RobotController::tripodController(), SIGNAL(newZoomPosition(int)), zoomSlider, SLOT(setValue(int)));
    connect(RobotController::tripodController(), SIGNAL(newTiltPosition(int)), tiltSlider, SLOT(setValue(int)));
    connect(RobotController::tripodController(), SIGNAL(newPanPosition(int)), panSlider, SLOT(setValue(int)));


    connect(RobotController::tripodController(), SIGNAL(newTiltPosition(int)), this, SLOT(tiltPositionChanged(int)));
    connect(RobotController::tripodController(), SIGNAL(newPanPosition(int)), this, SLOT(panPositionChanged(int)));

    connect(centerPanTiltButton, SIGNAL(clicked()), RobotController::tripodController(), SLOT(centerPanTilt()));

    panSlider->setMaximum(MAX_PAN);
    panSlider->setMinimum(MIN_PAN);

    tiltSlider->setMaximum(MAX_TILT);
    tiltSlider->setMinimum(MIN_TILT);

    panSlider->setValue(RobotController::tripodController()->getCurrentPan());
    tiltSlider->setValue(RobotController::tripodController()->getCurrentTilt());
}

void CameraWidget::on_zoomInButton_pressed()
{
    RobotController::tripodController()->startZooming(TripodController::ZoomIn);
}

void CameraWidget::on_zoomInButton_released()
{
    RobotController::tripodController()->startZooming(TripodController::NoZoom);
}

void CameraWidget::on_zoomOutButton_pressed()
{
    RobotController::tripodController()->startZooming(TripodController::ZoomOut);
}

void CameraWidget::on_zoomOutButton_released()
{
    RobotController::tripodController()->startZooming(TripodController::NoZoom);
}

void CameraWidget::on_tiltUpButton_pressed()
{
    RobotController::tripodController()->startTilting(TripodController::TiltUp);
}

void CameraWidget::on_tiltUpButton_released()
{
    RobotController::tripodController()->startTilting(TripodController::NoTilt);
}

void CameraWidget::on_tiltDownButton_pressed()
{
    RobotController::tripodController()->startTilting(TripodController::TiltDown);
}

void CameraWidget::on_tiltDownButton_released()
{
    RobotController::tripodController()->startTilting(TripodController::NoTilt);
}

void CameraWidget::on_panLeftButton_pressed()
{
    RobotController::tripodController()->startPanning(TripodController::PanLeft);
}

void CameraWidget::on_panLeftButton_released()
{
    RobotController::tripodController()->startPanning(TripodController::NoPan);
}

void CameraWidget::on_panRightButton_pressed()
{
    RobotController::tripodController()->startPanning(TripodController::PanRight);
}

void CameraWidget::on_panRightButton_released()
{
    RobotController::tripodController()->startPanning(TripodController::NoPan);
}

void CameraWidget::on_doublePanTiltRate_clicked()
{
    RobotController::tripodController()->setPanTiltDouble(doublePanTiltRate->isChecked());
}

void CameraWidget::panPositionChanged(int pos) {
    panLabel->setText(QString::number(pos));
}

void CameraWidget::zoomLevelChanged(int zoom) {

}

void CameraWidget::tiltPositionChanged(int pos) {
    tiltLabel->setText(QString::number(pos));
}

void CameraWidget::on_tiltSlider_sliderMoved(int position)
{
    RobotController::tripodController()->setTiltPosition(position);
}

void CameraWidget::on_panSlider_sliderMoved(int position)
{
    RobotController::tripodController()->setPanPosition(position);
}

void CameraWidget::on_sendCameraCommand_clicked()
{
    qDebug() << "sending camera command";
    switch (cameraCommandDropdown->currentIndex())
    {
        case 1: RobotController::tripodController()->sendCameraCommand(QByteArray("\x81\x01\x04\x35\x00")); break;
        case 2: RobotController::tripodController()->sendCameraCommand(QByteArray("\x81\x01\x04\x35\x01")); break;
        case 3: RobotController::tripodController()->sendCameraCommand(QByteArray("\x81\x01\x04\x35\x02")); break;
        case 4: RobotController::tripodController()->sendCameraCommand(QByteArray("\x81\x01\x04\x35\x03")); break;
        case 5: RobotController::tripodController()->sendCameraCommand(QByteArray("\x81\x01\x04\x35\x04")); break;
        case 7: RobotController::tripodController()->sendCameraCommand(QByteArray("\x81\x01\x04\x39\x00")); break;
        case 8: RobotController::tripodController()->sendCameraCommand(QByteArray("\x81\x01\x04\x39\x0D")); break;
    }
}

void CameraWidget::on_manualExposureSlider_sliderMoved(int position)
{
    QByteArray command = QByteArray("\x81\x01\x04\x4D\x00\x00");
    command.append((char)((position>>4)&0xF));
    command.append((char)(position&0xF));
    RobotController::tripodController()->sendCameraCommand(command);
}

void CameraWidget::on_exposureCompenstaion_sliderMoved(int position)
{
    QByteArray command = QByteArray("\x81\x01\x04\x4E\x00\x00");
    command.append((char)((position>>4)&0xF));
    command.append((char)(position&0xF));
    RobotController::tripodController()->sendCameraCommand(command);
}

void CameraWidget::on_ExposureComp_clicked()
{
    if (ExposureComp->isChecked())
        RobotController::tripodController()->sendCameraCommand(QByteArray("\x81\x01\x04\x3E\x02"));
    else
        RobotController::tripodController()->sendCameraCommand(QByteArray("\x81\x01\x04\x3E\x03"));
}
