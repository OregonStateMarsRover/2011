#include <math.h>
#include <QDebug>

#include "AltitudeCalculator.h"

#include "VirtualRover/RobotController.h"

AltitudeCalculator * AltitudeCalculator::m_instance = 0;

AltitudeCalculator::AltitudeCalculator(QObject *parent) :
    QObject(parent)
{
    connect(RobotController::tripodController(), SIGNAL(newBarometerData(unsigned short,ulong)), this, SLOT(setRoverPressure(unsigned short,ulong)));
    connect(RobotController::tripodController(), SIGNAL(newAccelerometerData(short,short,short)), this, SLOT(setRoverAngle(short,short,short)));
}

AltitudeCalculator * AltitudeCalculator::instance() {
    if (m_instance==0)
        m_instance = new AltitudeCalculator(0);
    return m_instance;
}

void AltitudeCalculator::setReferencePressure(unsigned long pressure) {
    refPressure = pressure;

    emit newReferencePressure(pressure);
    recalculateAltitude();
}

void AltitudeCalculator::setReferencePressure(unsigned short temperature, unsigned long pressure) {
    qDebug() << "got ref pressure"<<pressure;
    setReferencePressure(pressure);
}

void AltitudeCalculator::setReferenceAltitude(unsigned long altitude) {
    refAltitude = altitude;

    recalculateAltitude();
}

void AltitudeCalculator::setRoverPressure(unsigned long pressure) {
    roverPressure = pressure;
    emit newRoverPressure(pressure);

    recalculateAltitude();
}

void AltitudeCalculator::setRoverPressure(unsigned short temperature, unsigned long pressure) {
    setRoverPressure(pressure);
    emit newRoverTemperature(temperature);
}

void AltitudeCalculator::setRoverAngle(short x, short y, short z) {
    double pitch, roll;
    pitch = asin(x/4096.0)*(180.0/M_PI);
    roll = asin(y/4096.0)*(180.0/M_PI);

    emit newRoverTilt(pitch, roll);
    emit newRoverPitch(pitch);
    emit newRoverRoll(roll);
}

void AltitudeCalculator::recalculateAltitude() {
    double roverAltitude;
    roverAltitude = 44330*((1-pow(((double)roverPressure/refPressure), 1.0/5.255)));

    emit newRoverAltitude(refAltitude + roverAltitude , roverAltitude);
}
