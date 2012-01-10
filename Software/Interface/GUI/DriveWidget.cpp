/*
 * DriveWidget.cpp
 *
 * Created by Camden Lopez on 11/23/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#include <QInputDialog>
#include <QByteArray>
#include <QSettings>
#include <QDebug>
#include "DriveWidget.h"

#include "VirtualRover/RobotController.h"
#include "Tactile/TactileInterface.h"

DriveWidget::DriveWidget(QWidget *parent) : QWidget(parent)
{
    QSettings set;
    counter = 0;
    setupUi(this);

    connect(RobotController::statusController(), SIGNAL(gotMessage(QByteArray)), this, SLOT(gotWirelessMessage(QByteArray)));
    connect(RobotController::statusController(), SIGNAL(gotDataErrorCount(QByteArray)), this, SLOT(gotRoverDataErrorCount(QByteArray)));

    connect(RobotController::motorController(), SIGNAL(gotStatusPacket(QByteArray)), this, SLOT(gotMotorStatusUpdate(QByteArray)));
    connect(RobotController::motorController(), SIGNAL(hadWatchdogTimeout(bool)), this, SLOT(gotWatchdogTimeout(bool)));
    connect(RobotController::motorController(), SIGNAL(gotPassThrough(QByteArray)), this, SLOT(gotPassthroughMessage(QByteArray)));
    connect(RobotController::motorController(), SIGNAL(gotTimeoutPacket(QByteArray)), this, SLOT(gotTimeoutData(QByteArray)));
    connect(RobotController::motorController(), SIGNAL(gotCurrentPacket(QByteArray)), this, SLOT(gotMotorCurrentData(QByteArray)));

    connect(TactileInterface::instance(), SIGNAL(strafeModeChanged(bool)), this, SLOT(strafeModeChanged(bool)));
    connect(TactileInterface::instance(), SIGNAL(slowModeButtonToggled()), this, SLOT(slowModeButtonToggled()));

    connect(disableMosfetsButton, SIGNAL(clicked()), RobotController::motorController(), SLOT(toggleMosfets()));
    connect(getCurrentButton, SIGNAL(clicked()), RobotController::motorController(), SLOT(requestCurrentData()));

    testTimer = new QTimer(this);
    connect(testTimer, SIGNAL(timeout()), this, SLOT(sendMessageTimer()));

    timingTimer = new QTimer(this);
    connect(timingTimer, SIGNAL(timeout()), this, SLOT(timingTimeout()));

    elapsedTime = new QTime();

    dataErrorTimer = new QTimer(this);
    connect(dataErrorTimer, SIGNAL(timeout()), RobotController::statusController(), SLOT(requestDataErrorCount()));
    dataErrorTimer->setInterval(5000);
    dataErrorTimer->start();

    QStringList jsNames(Joystick::getJoystickNames());
    joystickDevName->addItems(jsNames);
    armStickDevName->addItems(jsNames);

    if (jsNames.count()>1) {
        armStickDevName->setCurrentIndex(1);
    }

    speedScaleBox->setValue(set.value("speedScaleExponent", 1.0).toDouble());
    dirScaleBox->setValue(set.value("directionScaleExponent", 1.0).toDouble());
    directionDivisorBox->setValue(set.value("directionPrimaryDivisor", 1.0).toDouble());
}

DriveWidget::~DriveWidget() {
    delete elapsedTime;
}

void DriveWidget::gotPassthroughMessage(QByteArray dat) {
    passThroughReply->appendPlainText(dat.toHex());
}

void DriveWidget::on_sendTestMsg_clicked()
{
    QString str = QInputDialog::getText(this, "TX Text", "Enter 3 letters to transmit");
    RobotController::statusController()->sendTestMessage(str);
}

void DriveWidget::gotWirelessMessage(QByteArray msg) {
    if (msg.at(0)=='T') {
        unsigned short val = (((msg.at(1)<<8 & 0xFF00))|(msg.at(2)&0xFF));
        unsigned short elapsed = elapsedTime->elapsed()-times[val];

        if (elapsed<minElapsed)
            minElapsed = elapsed;

        if (elapsed>maxElapsed)
            maxElapsed = elapsed;

        sum += elapsed;
        qDebug() << "got time update"<<val<<", "<<elapsed<<"ms elapsed";
    }
    else {
        QString m(msg);
        testLabel->setText(m);
    }
}

void DriveWidget::gotRoverDataErrorCount(QByteArray count) {
    int i;

    for (i=0;i<count.size();i++) {
        dataErrorWidget->setItem(i,1,new QTableWidgetItem(QString::number((unsigned char)count.at(i))));
    }
}

void DriveWidget::gotMotorStatusUpdate(QByteArray msg) {
    int i;
    for (i=1;i<11;i++) {
        //***Changed here***
        if(QString::number(msg.at(i)).compare(motorStatusTable->itemAt(i-1,1)->text()) == 0)
            emit statusChanged(i, QString::number(msg.at(i)));
        motorStatusTable->setItem(i-1,1,new QTableWidgetItem(QString::number(msg.at(i))));
    }

    if (msg.at(11)==01)
        actuatedBox->setChecked(true);
    else
        actuatedBox->setChecked(false);
}

void DriveWidget::gotWatchdogTimeout(bool hadTimeout) {
    actuatedBox->setChecked(hadTimeout);
}

void DriveWidget::on_sendNumbersButton_clicked()
{
    counter=0;
    testTimer->setInterval(delayBox->value());
    testTimer->start();
}

void DriveWidget::strafeModeChanged(bool inStrafe) {
    inStrafeModeBox->setChecked(inStrafe);
}

void DriveWidget::slowModeButtonToggled() {
    if (maxSpeedBox->value()>75.0) {
        maxSpeedBox->setValue(50.0);
    }
    else {
        maxSpeedBox->setValue(100.0);
    }
}

void DriveWidget::sendMessageTimer() {
    if (counter==countBox->value()) {
        numbersStatusLabel->setText("done");
        testTimer->stop();
    }

    RobotController::statusController()->sendTestMessage(QString::number(counter));
    numbersStatusLabel->setText("sending"+QString::number(counter));
    counter++;
}

void DriveWidget::gotTimeoutData(QByteArray msg) {
    int i;
    for (i=1;i<11;i++) {
         motorStatusTable->setItem(i-1,2,new QTableWidgetItem(QString::number(msg.at(i))));
    }
}

void DriveWidget::gotMotorCurrentData(QByteArray msg) {
    int i;
    for (i=0;i<6;i++) {
         motorStatusTable->setItem(i,3,new QTableWidgetItem(QString::number((unsigned short)((msg.at(1+2*i)<<8) & 0xFF00) | (msg.at(2+2*i) & 0xFF))));
    }
}

void DriveWidget::on_stopButton_clicked()
{
    testTimer->stop();
}

void DriveWidget::timingTimeout() {
    QByteArray msg;
    msg = msg.append(QString("T"));
    msg.append((unsigned char)(currentTimeSend>>8 & 0xFF));
    msg.append((unsigned char)(currentTimeSend& 0xFF));
    times[currentTimeSend++]=elapsedTime->elapsed();
    RobotController::statusController()->sendTestMessage(msg);

    if (currentTimeSend==timingCountBox->value()) {
        timingTimer->stop();

        qDebug() << "Min:"<<minElapsed<<"Max:"<<maxElapsed<<"Avg:"<<(double)sum/currentTimeSend;
    }
    qDebug()<<"sending time"<<currentTimeSend-1;
}

void DriveWidget::on_startTimingButton_clicked()
{
    elapsedTime->start();
    currentTimeSend = 0;
    if (times)
        delete times;

    times = new int[timingCountBox->value()];

    minElapsed = 60000;
    maxElapsed = 0;
    sum=0;
    rcvd=0;
    timingTimer->setInterval(timingDelayBox->value());
    timingTimer->start();
}

void DriveWidget::on_sendCmdButton_clicked()
{
    QByteArray data = QByteArray::fromHex(qPrintable(cmdEdit->currentText().remove(' ')));
    RobotController::motorController()->sendPassThru(idBox->value(), data);
}

void DriveWidget::on_enableWatchdogBox_clicked()
{
    RobotController::motorController()->enableWatchdog(enableWatchdogBox->isChecked());
}

QString DriveWidget::niceProfileNameToActual(QString profile) {
    if (profile=="Thrustmaster!") {
        return "thrustmaster";
    }
    else if (profile=="PS2 Controller") {
        return "ps2";
    }
    else
        return "ps2";
}

void DriveWidget::on_joystickProfileBox_currentIndexChanged(QString profile)
{
    TactileInterface::loadDrivingJoystickProfile(niceProfileNameToActual(profile));
}

void DriveWidget::on_rescanJsButton_clicked()
{
    QStringList devNames(Joystick::getJoystickNames());

    joystickDevName->clear();
    joystickDevName->addItems(devNames);

    armStickDevName->clear();
    armStickDevName->addItems(devNames);
}

void DriveWidget::on_reopenJsButton_clicked()
{
    TactileInterface::setDrivingJoystick(joystickDevName->currentText(), niceProfileNameToActual(joystickProfileBox->currentText()));

    TactileInterface::setArmJoystick(armStickDevName->currentText(), niceProfileNameToActual(armStickTypeBox->currentText()));
}

void DriveWidget::on_joystickDevName_currentIndexChanged(QString devFile)
{
    TactileInterface::setDrivingJoystick(joystickDevName->currentText(), niceProfileNameToActual(joystickProfileBox->currentText()));
}

void DriveWidget::on_pwmModeBox_clicked()
{
    RobotController::motorController()->setPWMMode(pwmModeBox->isChecked());
}

void DriveWidget::on_speedScaleBox_valueChanged(double val)
{
    QSettings set;
    set.setValue("speedScaleExponent", val);
}

void DriveWidget::on_dirScaleBox_valueChanged(double val)
{
    QSettings set;
    set.setValue("directionScaleExponent", val);
}

void DriveWidget::on_useCurveBox_clicked()
{
    RobotController::motorController()->setExponentialCurve(useCurveBox->isChecked());
}

void DriveWidget::on_directionDivisorBox_valueChanged(double val)
{
    QSettings set;
    set.setValue("directionPrimaryDivisor", val);
}

void DriveWidget::on_stallCurrentBox_valueChanged(double val)
{
    RobotController::motorController()->setMotorStallCurrent((int)(val*1000));
}

void DriveWidget::on_inStrafeModeBox_clicked()
{
    RobotController::motorController()->setRoverInStrafe(inStrafeModeBox->isChecked());
}

void DriveWidget::on_maxSpeedBox_valueChanged(double val)
{
    RobotController::motorController()->setGlobalMotorScaler(val/100.0);
    maxSpeedSlider->setValue(val);
}

void DriveWidget::on_maxSpeedSlider_valueChanged(int value)
{
    maxSpeedBox->setValue(value);
}
