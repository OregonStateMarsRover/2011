/*
 * ArmController.h
 *
 * Provides an interface between the wireless communication
 * with the rover and the GUI and tactile devices in regards
 * to controlling the rover arm.
 *
 * Created by Camden Lopez on 11/10/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#ifndef ARMCONTROLLER_H
#define ARMCONTROLLER_H


// Generic
#define ERROR 0x00
#define DATA_NOT_AVAILABLE 0x01
#define ACK 0x02
#define UNKNOWN_COMMAND 0x03
#define PING 0x20

// Motor Controller
#define GET_SPI_ADC 0x68
#define GET_TEMP_ADC 0x69
#define GET_POSITION 0x70
#define GET_VELOCITY 0x71
#define SET_POSITION 0x72
#define SET_VELOCITY 0x73
#define SET_CURRENT 0x74
#define SET_DUTY_CYCLE 0x75
#define ENABLE_MOSFET_DRIVER 0x76
#define DISABLE_MOSFET_DRIVER 0x77

// Main Controller Commands
#define PASS_THROUGH 0x40
#define PROGRAM_POINT 0x41
#define PROGRAM_VERIFY 0x42
#define PROGRAM_RUN 0x43
#define PROGRAM_ERASE 0x44
#define PROGRAM_READ 0x45
#define PING_DEVICES 0x46 // Ping all connected devices and return thier ID's
#define GET_ARM_POSITION 0x47 // Get the position for all actuators on the arm
#define GET_ARM_VELOCITY 0x48 // Get the current velocity of all actuators on the arm
#define GET_MAGNETIC_DISK_POS 0x50
#define FIX_OFFSET 0x51

// Servo Controller Commands
// Request to Servo Controller
#define SET_SERVO_POSITION 0xF0
#define GET_SERVO_POSITION 0xF1
#define SET_SERVO_SPEED 0xF2
#define SET_SERVO_TORQUE_ENABLE 0xF3
#define SET_SERVO_POSITIONS 0xF4
#define GET_SERVO_DATA 0xF5


#include <QTimer>
#include <QQueue>

#include "AbstractController.h"
#include "Common/Matrix.h"
#include "Wireless/WirelessDispatcher.h"

struct ArmDistances {
    float x, y, z;
    vec3 endEffectorDirection;
};

struct ArmCylinderical {
    float height, length;
    float angle;
    float gripper;
};

// Arm angles in degrees (these ones are always there)
struct ArmAngles
{
    float rotation;
    float shoulder;
    float elbow;

    float cameraBase;
    float cameraTip;
    //float thetaW;
    //float wristRotation;
    //float endRotation;
};

// Arm angles in degrees (these ones exist with the gripper end effector)
struct ArmWristAngles
{
    ArmAngles base;
    float wristElevation;
    float writsTip;
    float wristRotation;
    float gripper;
};

struct ArmAstroAngles
{
    ArmAngles base;
    float gripper;
};

struct ArmShovelAngles
{
    ArmAngles base;
    float head;
    float lid;
};

class ArmController : public AbstractController
{
    Q_OBJECT
public:
    enum Direction {
        NoDirection,
        UpDirection,
        DownDirection,
        LeftDirection,
        RightDirection,
        InDirection,
        OutDirection,
        OpenDirection,
        CloseDirection
    };


    int sendArmPackets(QList<QList <unsigned char> > packets);
    void run();
    void stop();


    explicit ArmController(QObject *parent = 0);

    virtual void handleMessage(WirelessPacket msg);

    virtual int guiMessageTarget();
    virtual int roverMessageTarget();

    static int sign(float a);
    static float Atand(float input);
    static float Cosd(float input);
    static float Sind(float input);
    static float Asind(float input);
    static float Tand(float input);
    static float ProjectionToRotation(float projectionAngle, float rotateAngle);
    static ArmWristAngles SolveAngles(ArmDistances D);
    static ArmDistances SolveDistances(ArmWristAngles A);
    bool areAnglesValid(ArmWristAngles a);
    bool areAnglesValid(ArmAstroAngles a);
    bool areAnglesValid(ArmShovelAngles s);
    float compareAngles (ArmWristAngles a, ArmWristAngles b);
    unsigned short GetBits(QList<unsigned char> buffer, unsigned char bitStartIndex, unsigned char bitCount);
    unsigned char AddData(QList<unsigned char> * buffer, unsigned char bitsInBuffer, unsigned short data, unsigned char bitsToAdd);

    ArmWristAngles AnglesFromPositions(unsigned short baseRotation, unsigned short shoulderPosition, unsigned short elbowPosition,
                                  unsigned short servo1, unsigned short servo2,
                                  unsigned short servo7, unsigned short servo8, unsigned short servo9, unsigned short servo10);

    ArmAstroAngles AnglesFromPositions(unsigned short baseRotation, unsigned short shoulderPosition, unsigned short elbowPosition,
                                                      unsigned short servo1, unsigned short servo2,
                                                      unsigned short servo3);

    ArmShovelAngles AnglesFromPositions(unsigned short baseRotation, unsigned short shoulderPosition, unsigned short elbowPosition,
                                                      unsigned short servo1, unsigned short servo2,
                                                      unsigned short servo4, unsigned short servo5);

    static const float SEG2_LEN = 39.9f;//43.0f; // Between elbow and end effector, in CM
    static const float SEG1_LEN = 37.9f; // Between shoulder and elbow, in CM
    static const float END_EFFECTOR_END = 20.0f;
    static float OFFSET;
    static float BASE_OFFSET;
    static const float END_EFFECTOR_MID = 11.5f;

    static const unsigned short GRIPPER_MIN = 300;
    static const unsigned short GRIPPER_MAX = 850;

    static const unsigned short CAMERA_TILT_MIN = 0;
    static const unsigned short CAMERA_TILT_MAX = 1000;

    static const unsigned short CAMERA_ROTATE_MIN = 157;
    static const unsigned short CAMERA_ROTATE_MAX = 1000;

public slots:
    void setHeightUp();
    void setHeightStop();
    void setHeightDown();

    void setWidthLeft();
    void setWidthStop();
    void setWidthRight();

    void setDepthIn();
    void setDepthStop();
    void setDepthOut();

    void setTipUp();
    void setTipStop();
    void setTipDown();

    void setPanLeft();
    void setPanStop();
    void setPanRight();

    void setZoomIn();
    void setZoomOut();
    void setZoomStop();

    void setGripperOpen();
    void setGripperClose();
    void setGripperStop();

    void setCameraTiltUp();
    void setCameraTiltDown();
    void setCameraTiltStop();

    void setCameraRotateUp();
    void setCameraRotateDown();
    void setCameraRotateStop();

    void setWristRotateLeft();
    void setWristRotateRight();
    void setWristRotateStop();

    void setHeightSpeed(float speed);
    void setWidthSpeed(float speed);
    void setDepthSpeed(float speed);

    void setGripperPosition(unsigned short pos);
    //void setCameraRotatePosition(unsigned short camTilt);
    //void setCameraTiltPosition(unsigned short camTilt);
    void setServoPosition(unsigned char id, unsigned short pos);

    void sendPassThrough(QByteArray cmd);

signals:
    void newArmPositions(ArmWristAngles angles);
    void newArmPositions(ArmAstroAngles angles);
    void newArmPositions(ArmShovelAngles angles);
    void newCommandReceived(QByteArray cmd);
    void newGripperPos(unsigned short newPos);
    void newCameraRotatePos(unsigned short newPos);
    void newCameraTiltPos(unsigned short newPos);

    void hadGlobalError();
    void hadSlaveError();

    // Function pointer for logging output
    void logAppend(QString s);
    void statusBox1Text (QString s);
    void statusBox2Text (QString s);


private slots:
    void updateTime();
    void packetTimeoutHandler();
    void sendReadArmPosition();

private:
    Direction heightDirection;
    Direction widthDirection;
    Direction depthDirection;
    Direction tipZDirection;
    Direction tipYDirection;
    Direction panDirection;
    Direction gripperDirection;
    Direction cameraRotateDirection;
    Direction cameraTiltDirection;
    Direction wristDirection;

    char endEffectorConfig;
    ArmWristAngles actualAngles;
    ArmWristAngles desiredAngles;
    ArmDistances origArmValues;

    ArmAstroAngles actualAstroAngles;
    ArmAstroAngles desiredAstroAngles;

    ArmShovelAngles actualShovelAngles;
    ArmShovelAngles desiredShovelAngles;
    QTimer * updateTimer;
    QTimer * packetTimer;
    bool isInitialized;


    QList<unsigned char> pendingPacketCodes;

    //QQueue<QByteArray> pktQueue;
    bool isTransmitting;
    bool autoQuery;
    //QByteArray lastSentPkt;

    unsigned short gripperPos, camRotate, camTilt;

    float depthScale, heightScale, widthScale;
    float wristEndRotationOffset;

    void sendUpdate(ArmAngles newAngles);

    static unsigned short ElbowDegreesToTicks(float degrees);
    static unsigned short ShoulderDegreesToTicks(float degrees);
    static unsigned short BaseRotationDegreesToTicks(float degrees);
    static float BaseRotationTicksToDegrees(unsigned short ticks);
    static float ShoulderTicksToDegrees(unsigned short ticks);
    static float ElbowTicksToDegrees(unsigned short ticks);
    unsigned short bytesToUShort(unsigned char msb, unsigned char lsb);
    QString messageToString(WirelessPacket p);
    QList<unsigned char> getMovementPacket(void);

    void sendZoom(char zoom);

    QList<unsigned char> GetPositionPacket(ArmWristAngles angles);
    QList<unsigned char> GetPositionPacket(ArmAstroAngles angles);
    QList<unsigned char> GetPositionPacket(ArmShovelAngles angles);


    int sendPacket(QList<unsigned char> packet);
};

#endif // ARMCONTROLLER_H
