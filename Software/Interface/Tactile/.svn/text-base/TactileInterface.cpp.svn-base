/*
 * TactileInterface.h
 *
 * Receives joystick action signals and calls functions in the
 * VirtualRover to send updates.
 *
 * Created by Taj Morton on 03/04/2011
 * Copyright © 2011 Oregon State University Robotics Club */

#include <QSettings>
#include <QDebug>
#include <QMessageBox>
#include "TactileInterface.h"

#include "VirtualRover/RobotController.h"

TactileInterface * TactileInterface::m_instance = 0;

TactileInterface::TactileInterface(QObject *parent) :
    QObject(parent)
{
    drivingStick = 0;
    armStick = 0;

    driveMode = RCMode;

    armZ = armZAlt = 0;
}

TactileInterface * TactileInterface::instance() {
    if (TactileInterface::m_instance==0) {
        m_instance = new TactileInterface();
    }

    return m_instance;
}

void TactileInterface::_setDrivingJoystick(QString filename, QString profile) {
    QSettings set;
    qDebug() << "loading driving joystick profile"<<profile;

    if (filename.isNull()) {
        filename = set.value("joystick/defaultDrivingStick", "/dev/input/js0").toString();
    }

    if (profile.isNull()) {
        profile = set.value("defaultProfile", "ps2").toString();
    }

    loadDrivingJoystickProfile(profile);

    if (drivingStick!=0)
        delete drivingStick;

    drivingStick = new Joystick(filename, this);
    connect(drivingStick, SIGNAL(axisChanged(int,int)), this, SLOT(drivingAxisChanged(int,int)));
    connect(drivingStick, SIGNAL(buttonReleased(int)), this, SLOT(drivingButtonReleased(int)));
    connect(drivingStick, SIGNAL(buttonPressed(int)), this, SLOT(drivingButtonPressed(int)));

    if (!drivingStick->isOpen()) {
        QMessageBox::critical(0, "No Joystick Device", "No driving joystick ("+filename+") was found. Check that the joystick is plugged in.",QMessageBox::Ok, 0);
    }
}

void TactileInterface::_setArmJoystick(QString filename, QString profile) {
    QSettings set;
    qDebug() << "loading arm joystick profile"<<profile;

    if (filename.isNull()) {
        filename = set.value("joystick/defaultArmStick", "/dev/input/js1").toString();
    }

    if (profile.isNull()) {
        profile = set.value("defaultProfile", "ps2").toString();
    }

    loadArmJoystickProfile(profile);

    if (armStick!=0)
        delete armStick;

    armStick = new Joystick(filename, this);
    connect(armStick, SIGNAL(axisChanged(int,int)), this, SLOT(armAxisChanged(int,int)));
    connect(armStick, SIGNAL(buttonReleased(int)), this, SLOT(armButtonReleased(int)));
    connect(armStick, SIGNAL(buttonPressed(int)), this, SLOT(armButtonPressed(int)));

    /*if (!armStick->isOpen()) {
        QMessageBox::critical(0, "No Joystick Device", "No driving joystick ("+filename+") was found. Check that the joystick is plugged in.",QMessageBox::Ok, 0);
    }*/
}

void TactileInterface::_loadDrivingJoystickProfile(QString key) {
    QSettings set;

    rcAxisMap.clear();
    strafeAxisMap.clear();
    buttonMap.clear();

    set.beginGroup("joystick");
    set.beginGroup(key);

    set.beginGroup("rc");
    rcAxisMap.insert(set.value("speedAxis", 1).toInt(), SpeedAxis);
    rcAxisMap.insert(set.value("directionAxis", 2).toInt(), DirectionAxis);
    rcAxisMap.insert(set.value("alternateDirectionAxis", -1).toInt(), AlternateDirectionAxis);
    set.endGroup(); //rc

    set.beginGroup("strafe");
    strafeAxisMap.insert(set.value("strafeXAxis", 3).toInt(), StrafeXAxis);
    strafeAxisMap.insert(set.value("strafeYAxis", 1).toInt(), StrafeYAxis);
    strafeAxisMap.insert(set.value("strafeRot", 2).toInt(), StrafeRotAxis);
    set.endGroup(); // strafe

    set.beginGroup("pantilt");
    cameraMap.insert(set.value("panAxis", 4).toInt(), PanAxis);
    cameraMap.insert(set.value("tiltAxis", 5).toInt(), TiltAxis);
    set.endGroup();

    set.beginGroup("buttons");
    buttonMap.insert(set.value("actuatorButton", 4).toInt(), ActuatorButton);
    buttonMap.insert(set.value("eStopButton", 5).toInt(), EStopButton);
    buttonMap.insert(set.value("zoomInButton", 3).toInt(), ZoomInButton);
    buttonMap.insert(set.value("zoomOutButton", 1).toInt(), ZoomOutButton);
    //buttonMap.insert(set.value("doublePanTiltButton", 6).toInt(), DoublePanTiltButton);
    buttonMap.insert(set.value("centerCameraButton", 6).toInt(), CenterCameraButton);
    buttonMap.insert(set.value("newCenterButton", 8).toInt(), NewCenterButton);
    buttonMap.insert(set.value("slowModeButton", 7).toInt(), RoverSlowModeButton);
    set.endGroup(); // buttons

    set.endGroup(); // profile key section
    set.endGroup(); // joystick section
}

void TactileInterface::_loadArmJoystickProfile(QString key) {
    QSettings set;

    armAxisMap.clear();
    armButtonMap.clear();

    set.beginGroup("armJoystick");
    set.beginGroup(key);

    armAxisMap.insert(set.value("xAxis", 3).toInt(), ArmXAxis);
    armAxisMap.insert(set.value("yAxis", 1).toInt(), ArmYAxis);
    armAxisMap.insert(set.value("zAxis", 0).toInt(), ArmZAxis);
    armAxisMap.insert(set.value("xAlternateAxis", 2).toInt(), ArmAlternateZAxis);

    armAxisMap.insert(set.value("tiltAxis", 5).toInt(), ArmTiltAxis);
    armAxisMap.insert(set.value("panAxis", 4).toInt(), ArmPanAxis);

    armButtonMap.insert(set.value("zoomIn", 4).toInt(), ZoomInButton);
    armButtonMap.insert(set.value("zoomIn", 6).toInt(), ZoomOutButton);

    armButtonMap.insert(set.value("gripperClose", 5).toInt(), ArmGripperCloseButton);
    armButtonMap.insert(set.value("gripperOpen", 7).toInt(), ArmGripperOpenButton);

    armButtonMap.insert(set.value("wristLeft", 0).toInt(), RotateWristLeft);
    armButtonMap.insert(set.value("wristRight", 2).toInt(), RotateWristRight);

    armButtonMap.insert(set.value("tiltCameraUp", 3).toInt(), TiltUpButton);
    armButtonMap.insert(set.value("tiltCameraDown", 1).toInt(), TiltDownButton);

    armButtonMap.insert(set.value("rotateCameraUp", 8).toInt(), RotateCameraUpButton);
    armButtonMap.insert(set.value("rotateCameraDown", 9).toInt(), RotateCameraDownButton);


    set.endGroup(); // end profile
    set.endGroup(); // armJoystick section
}

void TactileInterface::_setInStrafeMode(bool strafeMode) {
    if (strafeMode) {
        driveMode=StrafeMode;
    }
    else {
        driveMode=RCMode;
    }

    emit strafeModeChanged(strafeMode);
}

void TactileInterface::drivingAxisChanged(int axis, int value) {
    if (cameraMap.contains(axis)) { // pan/tilt change
        if (cameraMap.value(axis)==PanAxis) {
            if (value==0) {
                RobotController::tripodController()->startPanning(TripodController::NoPan);
            }
            else if (value>0){
                RobotController::tripodController()->startPanning(TripodController::PanRight);
            }
            else if (value<0) {
                RobotController::tripodController()->startPanning(TripodController::PanLeft);
            }
        }
        else if (cameraMap.value(axis)==TiltAxis) {
            if (value==0) {
                RobotController::tripodController()->startTilting(TripodController::NoTilt);
            }
            else if (value<0){
                RobotController::tripodController()->startTilting(TripodController::TiltDown);
            }
            else if (value>0) {
                RobotController::tripodController()->startTilting(TripodController::TiltUp);
            }
        }
    }
    else { // driving stick change
        if (driveMode==RCMode) {
            if (rcAxisMap.contains(axis)) {                
                if (rcAxisMap.value(axis)==SpeedAxis) {
                    value=value*-1; // invert speed axis (forwards = positive = faster)
                    RobotController::motorController()->setSpeed(value);
                }
                else if (rcAxisMap.value(axis)==DirectionAxis || rcAxisMap.value(axis)==AlternateDirectionAxis) {
                    RobotController::motorController()->setHeading(value);
                }
            }
        }
        else { // strafe mode
            if (strafeAxisMap.contains(axis)) {
                switch(strafeAxisMap.value(axis)) {
                    case StrafeXAxis:
                    RobotController::motorController()->setStrafeX(value);
                    break;

                    case StrafeYAxis:
                    value=value*-1;
                    RobotController::motorController()->setStrafeY(value);
                    break;

                    case StrafeRotAxis:
                    RobotController::motorController()->setStrafeRot(value);
                    break;
                }
            }
        }
    }
}

void TactileInterface::drivingButtonReleased(int button) {
    if (buttonMap.contains(button)) {
        switch (buttonMap.value(button)) {
            case EStopButton:
                RobotController::motorController()->eStop();
                break;

            case ActuatorButton:
                if (RobotController::motorController()->toggleActuators()) {
                    if (driveMode==RCMode) {
                        driveMode=StrafeMode;
                        emit strafeModeChanged(true);
                    }
                    else if (driveMode==StrafeMode) {
                        driveMode=RCMode;
                        emit strafeModeChanged(false);
                    }
                }
                break;

            case ZoomInButton:
                RobotController::tripodController()->startZooming(TripodController::NoZoom);
                break;

            case ZoomOutButton:
                RobotController::tripodController()->startZooming(TripodController::NoZoom);
                break;

            case DoublePanTiltButton:
                RobotController::tripodController()->setPanTiltDouble(false);
                break;

            case CenterCameraButton:
                RobotController::tripodController()->centerPanTilt();
                break;

            case NewCenterButton:
                RobotController::tripodController()->setNewCenter();
                break;

            case RoverSlowModeButton:
                emit slowModeButtonToggled();
                break;

        }
    }
}

void TactileInterface::drivingButtonPressed(int button) {
    if (buttonMap.contains(button)) {
        switch(buttonMap.value(button)) {
            case ZoomInButton:
                qDebug() << "zoom in pressed";
                RobotController::tripodController()->startZooming(TripodController::ZoomIn);
                break;

            case ZoomOutButton:
                RobotController::tripodController()->startZooming(TripodController::ZoomOut);
                break;

            case DoublePanTiltButton:
                RobotController::tripodController()->setPanTiltDouble(false);
                break;
        }
    }
}

void TactileInterface::armAxisChanged(int axis, int val) {
    if (armAxisMap.contains(axis)) {
        switch (armAxisMap.value(axis)) {
            case ArmXAxis:
                RobotController::armController()->setDepthSpeed(fabsf(val/32768.0));
                if (val>0) {
                    RobotController::armController()->setDepthOut();
                }
                else if (val<0) {
                    RobotController::armController()->setDepthIn();
                }
                else {
                    RobotController::armController()->setDepthStop();
                }

                break;

            case ArmYAxis:
                RobotController::armController()->setHeightSpeed(fabsf(val/32768.0));
                if (val<0) { // stupid backwards joysticks
                    RobotController::armController()->setHeightUp();
                }
                else if (val>0) {
                    RobotController::armController()->setHeightDown();
                }
                else {
                    RobotController::armController()->setHeightStop();
                }

            break;

            case ArmZAxis:
                armZ = val;
            case ArmAlternateZAxis:
                if (armAxisMap.value(axis)==ArmAlternateZAxis)
                    armZAlt = val;

                if(abs(armZ)>abs(armZAlt)) {
                    val = armZ;
                }
                else {
                    val = armZAlt;
                }

                RobotController::armController()->setWidthSpeed(fabsf(val/32768.0));
                if (val<0) {
                    RobotController::armController()->setWidthRight();
                }
                else if (val>0) {
                    RobotController::armController()->setWidthLeft();
                }
                else {
                    RobotController::armController()->setWidthStop();
                }
            break;

            case ArmTiltAxis:
                if (val<0) {
                    RobotController::armController()->setTipUp();
                }
                else if (val>0) {
                    RobotController::armController()->setTipDown();
                }
                else {
                    RobotController::armController()->setTipStop();
                }
            break;

            case ArmPanAxis:
                if (val<0) {
                    RobotController::armController()->setPanLeft();
                }
                else if (val>0) {
                    RobotController::armController()->setPanRight();
                }
                else {
                    RobotController::armController()->setPanStop();
                }
            break;
        }
    }
}

void TactileInterface::armButtonPressed(int button) {
    if (armButtonMap.contains(button)) {
        switch (armButtonMap.value(button)) {
            case ZoomInButton:
                RobotController::armController()->setZoomIn();
                break;

            case ZoomOutButton:
                RobotController::armController()->setZoomOut();
            break;

            case ArmGripperCloseButton:
                RobotController::armController()->setGripperClose();
            break;

            case ArmGripperOpenButton:
                RobotController::armController()->setGripperOpen();
            break;

            case TiltUpButton:
                RobotController::armController()->setCameraTiltUp();
            break;

            case TiltDownButton:
                RobotController::armController()->setCameraTiltDown();
            break;

            case RotateCameraUpButton:
                RobotController::armController()->setCameraRotateUp();
            break;

            case RotateCameraDownButton:
                RobotController::armController()->setCameraRotateDown();
            break;

            case RotateWristLeft:
                RobotController::armController()->setWristRotateLeft();
                break;
            case RotateWristRight:
                RobotController::armController()->setWristRotateRight();
                break;
        }
    }
}

void TactileInterface::armButtonReleased(int button) {
    if (armButtonMap.contains(button)) {
        switch (armButtonMap.value(button)) {
            case ZoomInButton:
            case ZoomOutButton:
                RobotController::armController()->setZoomStop();
                break;

            case ArmGripperCloseButton:
            case ArmGripperOpenButton:
                RobotController::armController()->setGripperStop();
                break;

            case TiltUpButton:
            case TiltDownButton:
                RobotController::armController()->setCameraTiltStop();
                break;

            case RotateCameraUpButton:
            case RotateCameraDownButton:
                RobotController::armController()->setCameraRotateStop();
                break;

            case RotateWristLeft:
            case RotateWristRight:
                RobotController::armController()->setWristRotateStop();
                break;
        }
    }
}
