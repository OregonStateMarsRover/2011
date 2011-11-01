/*
 * ArmWidget.h
 *
 * Provides controls for the rover arm.
 *
 * Created by Camden Lopez on 11/23/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#ifndef ARMWIDGET_H
#define ARMWIDGET_H

#include "ui_ArmWidget.h"

#include "QGraphicsScene"

#include "VirtualRover/ArmController.h"

class ArmWidget : public QWidget, private Ui::ArmWidget
{
    Q_OBJECT

public:
    explicit ArmWidget(QWidget *parent = 0);


public slots:
    void newArmPositions(ArmAngles angles, ArmDistances distances);
    void newArmCommand(QByteArray dat);

private:
    QGraphicsScene * armScene;
    int slaveErrorCount, globalErrorCount;

private slots:
    void on_resetServo_clicked();
    void on_zoomInButton_clicked();
    void on_Run_clicked();
    void on_getArmConfigButton_clicked();
    void on_pushButton_clicked();
    void on_cameraTiltBox_valueChanged(int );
    void on_cameraRotateBox_valueChanged(int );
    void on_gripperBox_valueChanged(int );
    void on_clearButton_clicked();
    void on_sendCmdButton_clicked();

    void setActualGripperPos(unsigned short newPos);
    void setActualCameraRotatePos(unsigned short newPos);
    void setActualCameraTiltPos(unsigned short newPos);

    void gotGlobalError();
    void gotSlaveError();
    void logAppend(QString s);
    void statusBox1Text (QString s);
    void statusBox2Text (QString s);
};
#endif // ARMWIDGET_H
