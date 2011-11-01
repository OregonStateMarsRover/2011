/*
 * Joystick.h
 *
 * Reads from joystick and emits signals when axis/buttons change.
 *
 * Created by Taj Morton on 03/04/2011
 * Copyright © 2011 Oregon State University Robotics Club */

#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <QObject>
#include <QTimer>

#define JOYSTICK_STOP_RANGE 500

/**
 * Reads from a joystick and generates signals on axis and button events.
 * Updates every 10 ms
 */
class Joystick : public QObject
{
    Q_OBJECT
public:
    explicit Joystick(QString filename, QObject *parent = 0);
    ~Joystick();

    /**
     * Returns true if joystick is opened successfully and working.
     */
    bool isOpen();

    /**
     * Returns human readable string of the error encountered
     * opening the joystick (if any).
     */
    QString gerError();

    static QStringList getJoystickNames();

signals:
    void axisChanged(int axis, int value);
    void buttonChanged(int button, bool value);
    void buttonPressed(int button);
    void buttonReleased(int button);

public slots:

private slots:
    /**
     * Checks joystick for new update messages.
     */
    void update();

private:
    QTimer * updateTimer;
    int joystickFd;
    QString m_openError;

    int axisCount;
    int buttonCount;

    static int sign(float a);
};

#endif // JOYSTICK_H
