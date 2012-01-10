/*
 * DriveWidget.h
 *
 * Provides controls for driving the rover.
 *
 * Created by Camden Lopez on 11/23/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#ifndef DRIVEWIDGET_H
#define DRIVEWIDGET_H

#include <QTimer>
#include <QTime>

#include "ui_DriveWidget.h"

class DriveWidget : public QWidget, private Ui::DriveWidget
{
    Q_OBJECT

public:
    explicit DriveWidget(QWidget *parent = 0);
    ~DriveWidget();

private slots:
    void on_maxSpeedSlider_valueChanged(int value);
    void on_maxSpeedBox_valueChanged(double );
    void on_inStrafeModeBox_clicked();
    void on_stallCurrentBox_valueChanged(double );
    void on_directionDivisorBox_valueChanged(double );
    void on_useCurveBox_clicked();
    void on_dirScaleBox_valueChanged(double );
    void on_speedScaleBox_valueChanged(double );
    void on_pwmModeBox_clicked();
    void on_joystickDevName_currentIndexChanged(QString );
    void on_reopenJsButton_clicked();
    void on_rescanJsButton_clicked();
    void on_joystickProfileBox_currentIndexChanged(QString msg);
    void on_enableWatchdogBox_clicked();
    void on_sendCmdButton_clicked();
    void on_startTimingButton_clicked();
    void on_stopButton_clicked();
    void on_sendNumbersButton_clicked();
    void on_sendTestMsg_clicked();

    void gotWirelessMessage(QByteArray msg);
    void gotMotorStatusUpdate(QByteArray msg);
    void gotWatchdogTimeout(bool hadTimeout);

    void strafeModeChanged(bool inStrafe);

    void slowModeButtonToggled();

private slots:
    void sendMessageTimer();
    void timingTimeout();
    void gotPassthroughMessage(QByteArray msg);
    void gotTimeoutData(QByteArray msg);
    void gotMotorCurrentData(QByteArray msg);
    void gotRoverDataErrorCount(QByteArray count);

    void on_getCurrentButton_clicked();

private:
    QString niceProfileNameToActual(QString profile);
    int counter;
    unsigned short currentTimeSend;
    unsigned short minElapsed, maxElapsed, sum, rcvd;
    int * times;
    QTimer * testTimer;
    QTimer * timingTimer;
    QTimer * dataErrorTimer;
    QTime * elapsedTime;
signals:
    void statusChanged(int index, QString status);
};

#endif // DRIVEWIDGET_H
