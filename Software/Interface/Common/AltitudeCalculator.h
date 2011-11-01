#ifndef ALTITUDECALCULATOR_H
#define ALTITUDECALCULATOR_H

#include <QObject>

class AltitudeCalculator : public QObject
{
    Q_OBJECT
public:
    explicit AltitudeCalculator(QObject *parent = 0);

    static AltitudeCalculator * instance();

signals:
    void newRoverAltitude(double absoluteAltitude, double relativeAltitude);
    void newRoverPressure(unsigned long pressure);
    void newRoverTilt(double degPitch, double degRoll);
    void newRoverPitch(double pitch);
    void newRoverRoll(double tilt);
    void newRoverTemperature(short temp);
    void newReferenceAltitude(double altitude);
    void newReferencePressure(unsigned long pressure);


public slots:
    void setReferencePressure(unsigned long pressure);
    void setReferencePressure(unsigned short temperature, unsigned long pressure);
    void setReferenceAltitude(unsigned long altitude);
    void setRoverPressure(unsigned long pressure);
    void setRoverPressure(unsigned short temperature, unsigned long pressure);
    void setRoverAngle(short x, short y, short z);

private:
    static AltitudeCalculator * m_instance;

    unsigned long refPressure;
    unsigned long refAltitude;
    unsigned long roverPressure;

    void recalculateAltitude();

};

#endif // ALTITUDECALCULATOR_H
