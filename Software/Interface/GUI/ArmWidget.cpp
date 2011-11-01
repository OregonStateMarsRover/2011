/*
 * ArmWidget.cpp
 *
 * Created by Camden Lopez on 11/23/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#include <QDebug>
#include <QGraphicsTextItem>
#include "ArmWidget.h"
#include "VirtualRover/RobotController.h"
#include "VirtualRover/ArmController.h"

ArmWidget::ArmWidget(QWidget *parent) : QWidget(parent)
{
    setupUi(this);

    slaveErrorCount = globalErrorCount = 0;

    connect(upButton, SIGNAL(pressed()), RobotController::armController(), SLOT(setHeightUp()));
    connect(upButton, SIGNAL(released()), RobotController::armController(), SLOT(setHeightStop()));
    connect(downButton, SIGNAL(pressed()), RobotController::armController(), SLOT(setHeightDown()));
    connect(downButton, SIGNAL(released()), RobotController::armController(), SLOT(setHeightStop()));

    connect(leftButton, SIGNAL(pressed()), RobotController::armController(), SLOT(setWidthLeft()));
    connect(leftButton, SIGNAL(released()), RobotController::armController(), SLOT(setWidthStop()));
    connect(rightButton, SIGNAL(pressed()), RobotController::armController(), SLOT(setWidthRight()));
    connect(rightButton, SIGNAL(released()), RobotController::armController(), SLOT(setWidthStop()));

    connect(inButton, SIGNAL(pressed()), RobotController::armController(), SLOT(setDepthIn()));
    connect(inButton, SIGNAL(released()), RobotController::armController(), SLOT(setDepthStop()));
    connect(outButton, SIGNAL(pressed()), RobotController::armController(), SLOT(setDepthOut()));
    connect(outButton, SIGNAL(released()), RobotController::armController(), SLOT(setDepthStop()));

    connect(tipDown, SIGNAL(pressed()), RobotController::armController(), SLOT(setTipDown()));
    connect(tipDown, SIGNAL(released()), RobotController::armController(), SLOT(setTipStop()));

    connect(tipUpButton, SIGNAL(pressed()), RobotController::armController(), SLOT(setTipUp()));
    connect(tipUpButton, SIGNAL(released()), RobotController::armController(), SLOT(setTipStop()));

    connect(tipLeft, SIGNAL(pressed()), RobotController::armController(), SLOT(setPanLeft()));
    connect(tipLeft, SIGNAL(released()), RobotController::armController(), SLOT(setPanStop()));

    connect(tipRight, SIGNAL(pressed()), RobotController::armController(), SLOT(setPanRight()));
    connect(tipRight, SIGNAL(released()), RobotController::armController(), SLOT(setPanStop()));

    connect(RobotController::armController(), SIGNAL(newArmPositions(ArmWristAngles)), armGLWidget, SLOT(newArmPositions(ArmWristAngles)));
    connect(RobotController::armController(), SIGNAL(newArmPositions(ArmShovelAngles)), armGLWidget, SLOT(newArmPositions(ArmShovelAngles)));
    connect(RobotController::armController(), SIGNAL(newArmPositions(ArmAstroAngles)), armGLWidget, SLOT(newArmPositions(ArmAstroAngles)));
    connect(RobotController::armController(), SIGNAL(newArmPositions(ArmAngles,ArmDistances)), this, SLOT(newArmPositions(ArmAngles,ArmDistances)));
    connect(RobotController::armController(), SIGNAL(newCommandReceived(QByteArray)), this, SLOT(newArmCommand(QByteArray)));
    connect(RobotController::armController(), SIGNAL(newGripperPos(unsigned short)), this, SLOT(setActualGripperPos(unsigned short)));
    connect(RobotController::armController(), SIGNAL(newCameraRotatePos(unsigned short)), this, SLOT(setActualCameraRotatePos(unsigned short)));
    connect(RobotController::armController(), SIGNAL(newCameraTiltPos(unsigned short)), this, SLOT(setActualCameraTiltPos(unsigned short)));
    connect(RobotController::armController(), SIGNAL(hadGlobalError()), this, SLOT(gotGlobalError()));
    connect(RobotController::armController(), SIGNAL(hadSlaveError()), this, SLOT(gotSlaveError()));

    connect(getArmConfigButton, SIGNAL(clicked()), RobotController::armController(), SLOT(sendReadArmPosition()));
    connect(RobotController::armController(), SIGNAL(logAppend(QString)), this, SLOT(logAppend(QString)));
    connect(RobotController::armController(), SIGNAL(statusBox1Text(QString)), this, SLOT(statusBox1Text(QString)));
    connect(RobotController::armController(), SIGNAL(statusBox2Text(QString)), this, SLOT(statusBox2Text(QString)));
}

void ArmWidget::logAppend(QString s)
{
    this->logBox->appendPlainText(s);
}

void ArmWidget::statusBox1Text(QString s)
{
    this->statusBox1->clear();
    this->statusBox1->appendPlainText(s);
}

void ArmWidget::statusBox2Text(QString s)
{
    this->statusBox2->clear();
    this->statusBox2->appendPlainText(s);
}

void ArmWidget::newArmCommand(QByteArray dat) {
    passThroughReply->appendPlainText(dat.toHex());
}

void ArmWidget::newArmPositions(ArmAngles angles, ArmDistances distances) {
//    shoulderAngleBox->setText(QString::number(angles.thetaS));
//    elbowAngleBox->setText(QString::number(angles.thetaE));
//    baseRotationBox->setText(QString::number(angles.thetaW) );
}

void ArmWidget::setActualGripperPos(unsigned short newPos) {
    gripperBox->setValue(newPos);
}

void ArmWidget::setActualCameraRotatePos(unsigned short newPos) {
    cameraRotateBox->setValue(newPos);
}

void ArmWidget::setActualCameraTiltPos(unsigned short newPos) {
    cameraTiltBox->setValue(newPos);
}

void ArmWidget::gotGlobalError() {
    globalErrorCount++;

    globalErrLabel->setText(QString::number(globalErrorCount));
}

void ArmWidget::gotSlaveError() {
    slaveErrorCount;

    slaveErrLabel->setText(QString::number(slaveErrorCount));
}

void ArmWidget::on_sendCmdButton_clicked()
{
    QByteArray data = QByteArray::fromHex(qPrintable(cmdEdit->currentText().remove(' ')));
    RobotController::armController()->sendPassThrough(data);
}

void ArmWidget::on_clearButton_clicked()
{
    passThroughReply->clear();
}

void ArmWidget::on_gripperBox_valueChanged(int val)
{
    RobotController::armController()->setGripperPosition(val);
}

void ArmWidget::on_cameraRotateBox_valueChanged(int val)
{
    //RobotController::armController()->setCameraRotatePosition(val);
}

void ArmWidget::on_cameraTiltBox_valueChanged(int val)
{
    //RobotController::armController()->setCameraTiltPosition(val);
}

void ArmWidget::on_pushButton_clicked()
{
    this->logBox->appendPlainText(("Here's another line!"));
    qDebug(("TAJ TOLD ME TO DO IT!"));

    qDebug()<<"BLAH!!!";

}

void ArmWidget::on_getArmConfigButton_clicked()
{

}

void ArmWidget::on_Run_clicked()
{
    if (QString::compare(this->Run->text(), "Run", Qt::CaseInsensitive) == 0)
    {
        this->Run->setText("Stop");
        RobotController::armController()->run();
    }
    else
    {
        this->Run->setText("Run");
        RobotController::armController()->stop();
    }
}

void ArmWidget::on_zoomInButton_clicked()
{

}

void ArmWidget::on_resetServo_clicked()
{
    unsigned char servoId = (unsigned char)this->servoIdBox->value();
    QList< QList<unsigned char> > packets;
    QList< unsigned char > packet;
    //packet.append(0x40);
    //packet.append(0x21);
    //packet.append(0xFA);
    //packet.append(servoId);
    //packet.append(0x03); // Write to control table
    //packet.append(0x12); // Alarm shutdown address
    //packet.append(0x00); // Clear error flags
    //packets.append(packet); 0xff 0xff 0x07 0x04 0x03 0xff 0x03 <checksum>
    //packet.clear();  40 21 FA 07 03 22 ff 03
    packet.append(0x40);
    packet.append(0x21);
    packet.append(0xFA);
    packet.append(servoId);
    packet.append(0x03); // Write to control table
    packet.append(0x22); // Set Torque
    packet.append(0xff); // Combined with next byte...
    packet.append(0x03); // Full Torque
    packets.append(packet);
    //40 21 FA 07 03 19 00
    RobotController::armController()->sendArmPackets(packets);
}
