/*
 * StatusWidget.h
 *
 * Displays detailed status information from the rover.
 *
 * Created by Camden Lopez on 11/10/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#ifndef STATUSWIDGET_H
#define STATUSWIDGET_H

#include "Tactile/BaseBarometer.h"

#include "ui_StatusWidget.h"

class StatusWidget : public QWidget, private Ui::StatusWidget
{
    Q_OBJECT

public:
    explicit StatusWidget(QWidget *parent = 0);

private slots:
    void on_baseOffsetBox_valueChanged(int );
    void on_referenceAltitudeBox_editingFinished();
    void on_enableAccelBox_clicked();
    void on_enableBaroBox_clicked();
    void on_enableGPSBox_clicked();
    void on_sendButton_clicked();

    //void newAccelerometerData(short x, short y, short z);

private slots:
    void requestBarometerData();
    //void gotRoverBarometerData(short temperature, unsigned long pressure);
    void gotBaseBarometerData(unsigned short temperature, unsigned long pressure);
    void gotBasePressure(unsigned long pressure);

    void gotRoverPitch(double pitch);
    void gotRoverRoll(double roll);
    void gotRoverPressure(ulong pressure);
    void gotRoverTemperature(short temp);
    void gotRoverAltitude(double absolute, double relative);

private:
    int targetNameToId(QString dat);

    QTimer * baroRequester;
    BaseBarometer * baro;
};

#endif // STATUSWIDGET_H
