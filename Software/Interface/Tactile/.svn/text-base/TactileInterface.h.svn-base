/*
 * TactileInterface.h
 *
 * Receives joystick action signals and calls functions in the
 * VirtualRover to send updates.
 *
 * Created by Taj Morton on 03/04/2011
 * Copyright © 2011 Oregon State University Robotics Club */

#ifndef TACTILEINTERFACE_H
#define TACTILEINTERFACE_H

#include <QObject>
#include <QMap>

#include "Joystick.h"

class TactileInterface : public QObject
{
    Q_OBJECT
public:
    //! Types of axes for mapping to motion
    enum AxisType {
        SpeedAxis, //!< Axis for speed (Y)
        DirectionAxis, //!< Axis for turning/direction (X)
        PanAxis, //!< Axis for panning
        TiltAxis, //!< Axis for tilting
        StrafeXAxis, //!< Axis for strafeing left/right
        StrafeYAxis, //!< Axis for strafeing forwards/back
        StrafeRotAxis, //!< Axis for rotation of strafeing
        AlternateDirectionAxis,
        ArmXAxis,
        ArmYAxis,
        ArmZAxis,
        ArmTiltAxis,
        ArmPanAxis,
        ArmAlternateZAxis
    };

    //! Modes of controlling motion with rover
    enum DriveMode {
        RCMode, //!< Drive with a speed and direction (like an RC car)
        StrafeMode //!< Drive by strafeing
    };

    enum ButtonType {
        ActuatorButton,
        PanLeftButton,
        PanRightButton,
        TiltUpButton,
        TiltDownButton,
        CenterCameraButton,
        EStopButton,
        FastPanButton,
        ZoomInButton,
        ZoomOutButton,
        FocusCameraButton,
        SwitchCameraButon,
        DoublePanTiltButton,
        NewCenterButton,
        ArmGripperCloseButton,
        ArmGripperOpenButton,
        RotateCameraUpButton,
        RotateCameraDownButton,
        RotateWristLeft,
        RotateWristRight,
        RoverSlowModeButton
    };

    explicit TactileInterface(QObject *parent = 0);
    static TactileInterface * instance();

    void _loadDrivingJoystickProfile(QString key);
    static void loadDrivingJoystickProfile(QString key) {
        instance()->_loadDrivingJoystickProfile(key);
    }

    void _setDrivingJoystick(QString filename = QString(), QString profile = QString());
    static void setDrivingJoystick(QString filename = QString(), QString profile = QString()) {
        instance()->_setDrivingJoystick(filename, profile);
    }

    void _setArmJoystick(QString filename = QString(), QString profile = QString());
    static void setArmJoystick(QString filename = QString(), QString profile = QString()) {
        instance()->_setArmJoystick(filename, profile);
    }

    void _loadArmJoystickProfile(QString key);
    static void loadArmJoystickProfile(QString key) {
        instance()->_loadArmJoystickProfile(key);
    }

    void _setInStrafeMode(bool strafeMode);
    static void setInStrafeMode(bool strafeMode) {
        instance()->_setInStrafeMode(strafeMode);
    }

signals:
    void strafeModeChanged(bool inStrafeMode);
    void slowModeButtonToggled();

private:
    static TactileInterface * m_instance; // we only want one TactileInterface! (singleton)

    Joystick * drivingStick;
    Joystick * armStick;

    DriveMode driveMode;

    short armZ, armZAlt;

    QMap<int, AxisType> rcAxisMap;
    QMap<int, AxisType> strafeAxisMap;
    QMap<int, AxisType> cameraMap;
    QMap<int, ButtonType> buttonMap;

    QMap<int, AxisType> armAxisMap;
    QMap<int, ButtonType> armButtonMap;

private slots:
    void drivingAxisChanged(int axis, int value);
    void drivingButtonReleased(int button);
    void drivingButtonPressed(int button);

    void armAxisChanged(int axis, int value);
    void armButtonPressed(int button);
    void armButtonReleased(int button);
};

#endif // TACTILEINTERFACE_H
