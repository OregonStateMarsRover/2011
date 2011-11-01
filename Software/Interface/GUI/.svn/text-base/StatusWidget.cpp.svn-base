/*
 * StatusWidget.cpp
 *
 * Created by Camden Lopez on 11/10/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#include "VirtualRover/RobotController.h"
#include "Wireless/WirelessPacket.h"
#include "StatusWidget.h"
#include "Common/AltitudeCalculator.h"

#include <QDebug>

#include "math.h"

StatusWidget::StatusWidget(QWidget *parent) : QWidget(parent)
{
    setupUi(this);

    //connect(RobotController::tripodController(), SIGNAL(newAccelerometerData(short,short,short)), this, SLOT(newAccelerometerData(short,short,short)));
    //connect(RobotController::tripodController(), SIGNAL(newBarometerData(short,ulong)), this, SLOT(gotRoverBarometerData(short,ulong)));

    connect(AltitudeCalculator::instance(), SIGNAL(newRoverAltitude(double,double)), this, SLOT(gotRoverAltitude(double,double)));
    connect(AltitudeCalculator::instance(), SIGNAL(newRoverPitch(double)), this, SLOT(gotRoverPitch(double)));
    connect(AltitudeCalculator::instance(), SIGNAL(newRoverRoll(double)), this, SLOT(gotRoverRoll(double)));
    connect(AltitudeCalculator::instance(), SIGNAL(newRoverPressure(ulong)), this, SLOT(gotRoverPressure(ulong)));
    connect(AltitudeCalculator::instance(), SIGNAL(newRoverTemperature(short)), this, SLOT(gotRoverTemperature(short)));
    connect(AltitudeCalculator::instance(), SIGNAL(newReferencePressure(ulong)), this, SLOT(gotBasePressure(ulong)));

    baro = new BaseBarometer(this);
    //connect(baro, SIGNAL(gotPressureData(unsigned short,ulong)), this, SLOT(gotBaseBarometerData(unsigned short,ulong)));
    connect(baro, SIGNAL(gotPressureData(unsigned short,ulong)), AltitudeCalculator::instance(), SLOT(setReferencePressure(unsigned short,ulong)));

    baroRequester = new QTimer(this);
    connect(baroRequester, SIGNAL(timeout()), this, SLOT(requestBarometerData()));
    baroRequester->start(1000);
    //baro->requestCoefficients();

    baro->setBaseBarometerOffset(baseOffsetBox->value());
}

void StatusWidget::on_sendButton_clicked()
{
    QByteArray data = QByteArray::fromHex(qPrintable(commandBox->text().remove(' ')));
    WirelessPacket pkt(targetNameToId(devSelectBox->currentText()), data);
    RobotController::instance()->sendWirelessPacket(pkt);
}

int StatusWidget::targetNameToId(QString name) {
    if (name=="Tripod") {
        return TARGET_TRIPOD_CONTROLLER;
    }
    else if (name=="GPS") {
        return TARGET_GPS_CONTROLLER;
    }
    else if (name=="Motor") {
        return TARGET_MOTOR_CONTROLLER;
    }
    else if (name=="Arm") {
        return TARGET_ARM_CONTROLLER;
    }
    else if (name=="Test") {
        return TARGET_TEST_CONTROLLER;
    }
}

/*void StatusWidget::newAccelerometerData(short x, short y, short z) {
    qDebug() << "NEW DATAAA";
    pitchAngleBox->setValue(asin(x/4096.0)*(180.0/M_PI));
    rollAngleBox->setValue(asin(y/4096.0)*(180.0)/M_PI);
}

void StatusWidget::gotRoverBarometerData(short temp, unsigned long pressure) {
    roverPressureBox->setText(QString::number(pressure));
    roverTempBox->setText(QString::number(temp/10.0) + " C");

    double roverAltitude;
    double refAlt = refPressureBox->text().toDouble();
    qDebug() << "refAlt:"<<refAlt;
    roverAltitude = 44330*((1-pow(((double)pressure/refAlt), 1.0/5.255)));
    qDebug() << "ration:"<<((double)pressure/refAlt);
    altitudeChangeBox->setText(QString::number(roverAltitude)+" m");

    absoluteAltitudeBox->setText(QString::number(referenceAltitudeBox->text().toDouble()+roverAltitude));
}*/

void StatusWidget::gotRoverPitch(double pitch) {
    pitchAngleBox->setValue(pitch);
}

void StatusWidget::gotRoverRoll(double roll) {
    rollAngleBox->setValue(roll);
}

void StatusWidget::gotRoverPressure(ulong pressure) {
    roverPressureBox->setText(QString::number(pressure));
}

void StatusWidget::gotRoverTemperature(short temp) {
    roverTempBox->setText(QString::number(temp/10.0) + " C");
}

void StatusWidget::gotRoverAltitude(double absolute, double relative) {
    altitudeChangeBox->setText(QString::number(relative)+" m");
    absoluteAltitudeBox->setText(QString::number(absolute)+" m");
}

void StatusWidget::gotBaseBarometerData(unsigned short temperature, unsigned long pressure)
{
    gotBasePressure(pressure);
}

void StatusWidget::gotBasePressure(unsigned long pressure) {
    refPressureBox->setText(QString::number(pressure));
}

void StatusWidget::requestBarometerData() {
    baro->requestPressureData();
    qDebug() << "sent baro request";
}

void StatusWidget::on_enableGPSBox_clicked()
{
    RobotController::gpsController()->enablePeriodicGPSRequests(enableGPSBox->isChecked());
}

void StatusWidget::on_enableBaroBox_clicked()
{
    RobotController::tripodController()->enablePeriodicBaroRequests(enableBaroBox->isChecked());
}

void StatusWidget::on_enableAccelBox_clicked()
{
    RobotController::tripodController()->enablePeriodicAccelRequests(enableAccelBox->isChecked());
}


void StatusWidget::on_referenceAltitudeBox_editingFinished()
{
    AltitudeCalculator::instance()->setReferenceAltitude(referenceAltitudeBox->text().toDouble());
}

void StatusWidget::on_baseOffsetBox_valueChanged(int val)
{
    baro->setBaseBarometerOffset(val);
}
