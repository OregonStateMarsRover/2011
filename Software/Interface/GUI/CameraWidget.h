/*
 * CameraWidget.h
 *
 * Provides controls for the rover cameras.
 *
 * Created by Camden Lopez on 11/10/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#ifndef CAMERAWIDGET_H
#define CAMERAWIDGET_H

#include "ui_CameraWidget.h"
#include "QDebug"

class CameraWidget : public QWidget, private Ui::CameraWidget
{
    Q_OBJECT

public:
    explicit CameraWidget(QWidget *parent = 0);

private slots:
    void on_sendCameraCommand_clicked();
    void on_ExposureComp_clicked();
    void on_exposureCompenstaion_sliderMoved(int position);
    void on_manualExposureSlider_sliderMoved(int position);
    void on_panSlider_sliderMoved(int position);
    void on_tiltSlider_sliderMoved(int position);
    void on_doublePanTiltRate_clicked();
    void on_panRightButton_released();
    void on_panRightButton_pressed();
    void on_panLeftButton_released();
    void on_panLeftButton_pressed();
    void on_tiltDownButton_released();
    void on_tiltDownButton_pressed();
    void on_tiltUpButton_released();
    void on_tiltUpButton_pressed();
    void on_zoomOutButton_released();
    void on_zoomOutButton_pressed();
    void on_zoomInButton_released();
    void on_zoomInButton_pressed();

    void panPositionChanged(int pos);
    void zoomLevelChanged(int zoom);
    void tiltPositionChanged(int pos);
};

#endif // CAMERAWIDGET_H
