/*
 * ArmController.cpp
 *
 * Created by Camden Lopez on 11/10/10
 * Copyright © 2010-2011 Oregon State University Robotics Club */

#include <QTimer>
#include <QDebug>
#include <math.h>
#include <QList>

#include "ArmController.h"

float ArmController::BASE_OFFSET = 2.38f;
float ArmController::OFFSET = 6.58f;


ArmController::ArmController(QObject *parent) : AbstractController(parent)
{
    heightDirection = NoDirection;
    widthDirection = NoDirection;
    depthDirection = NoDirection;
    tipZDirection = NoDirection;
    panDirection = NoDirection;
    gripperDirection = NoDirection;
    cameraRotateDirection = NoDirection;
    cameraTiltDirection = NoDirection;
    wristDirection = NoDirection;

    depthScale = heightScale = widthScale = 0.0; // default

    wristEndRotationOffset = 0.0;

    origArmValues.x = 75;
    origArmValues.y = 0;
    origArmValues.z = 0;
    origArmValues.endEffectorDirection = vec3 (1, 0, 0); // Straight out

    updateTimer = new QTimer(this);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateTime()));
    updateTimer->setInterval(200);

    //updateTimer->start();

    packetTimer = new QTimer(this);
    connect(packetTimer, SIGNAL(timeout()), this, SLOT(packetTimeoutHandler()));
    packetTimer->setInterval(800);
    this->isTransmitting = false;

    //lastSentPkt.clear();
    isInitialized = false;
    endEffectorConfig = '?';
    //sendReadArmPosition();

    // Probably not necessary...
    pendingPacketCodes.clear();
}

int ArmController::guiMessageTarget() {
    return TARGET_GUI_ARM;
    //return 0x00;
}

int ArmController::roverMessageTarget() {
    return TARGET_ARM_CONTROLLER;
    //return 0x77;
}

void ArmController::sendPassThrough(QByteArray cmd)
{
    QList<unsigned char> packet;
    for (int i = 0; i<cmd.length(); i++)
    {
        packet.append((unsigned char)cmd.at(i));
    }
    if (this->sendPacket(packet) == 0)
    {
        //emit logAppend("Data Sent!");
    }
}

int ArmController::sign(float a) {
    if (a<0)
        return -1;
    else if (a>0)
        return 1;
    else
        return 0;
}

float ArmController::Atand(float input)
{
   return (float)(atan(input) * 180 / M_PI);
}

float ArmController::Cosd(float input)
{
   return (float)(cos(input * M_PI / 180));
}

float ArmController::Sind(float input)
{
   return (float)(sin(input * M_PI / 180));
}

float ArmController::Asind(float input)
{
   return (float)(asin(input) * 180 / M_PI);
}

float ArmController::Tand(float input)
{
   return (float)(tan(input * M_PI / 180));
}

float ArmController::ProjectionToRotation(float projectionAngle, float rotateAngle)
{
    return Atand(Tand(projectionAngle) * Cosd(rotateAngle));
}

unsigned short ArmController::ElbowDegreesToTicks(float degrees)
{
    unsigned short ticks = (unsigned short )(436 + degrees * 8192.0f / 360.0f);
    if (ticks > 4200) { ticks = 4200; }
    if (ticks < 436) { ticks = 436; }
    return ticks;
}

unsigned short ArmController::ShoulderDegreesToTicks(float degrees)
{
    unsigned short ticks = (unsigned short)(555 + degrees * 8192.0f / 360.0f);
    if (ticks > 2800) { ticks = 2800; }
    if (ticks < 500) { ticks = 500; }
    return ticks;
}

unsigned short ArmController::BaseRotationDegreesToTicks(float degrees)
{
    unsigned short ticks = (unsigned short)(500 + ((degrees + 147.5f + 90.0f) * 175.873f));
    if (ticks < 500) { ticks = 500; }
    if (ticks > 52382) { ticks = 52382; }
    return ticks;
}

ArmWristAngles ArmController::SolveAngles(ArmDistances D) {

    vec3 endEffectorDirection = Normalize(D.endEffectorDirection);//vec3 (1, 0, 0);
    //endEffectorDirection = MatrixRotateZ(D.tip) * MatrixRotateY(D.turn) * endEffectorDirection;
    //endEffectorDirection =  endEffectorDirection;
    vec3 toEnd = endEffectorDirection * END_EFFECTOR_END; // From end effector tip to first joint


    ArmWristAngles a;

    vec3 temp1 = vec3 (D.x, D.y, D.z) - toEnd;
    vec3 temp2 (temp1[0], temp1[1],temp1[2]);
    temp1.array[1] = 0;
    float M = Length(temp1);
    float angleD = asind(OFFSET/M);

    a.base.rotation = asind(vec3 (0, 0, -1) * Normalize(temp1)) - angleD;


    // Find a vector for the 2nd to last part of the end effector
    vec3 vecPerp = MatrixRotateY(a.base.rotation) * vec3 (0, 0, 1);
    vec3 part2 = Normalize (toEnd - vecPerp * (toEnd * vecPerp)) * END_EFFECTOR_MID;

    a.writsTip = -asind(vecPerp * Normalize(toEnd));
    a.wristElevation = -asind(vec3 (0, 1, 0) * Normalize(part2));

    temp2 = temp2 - part2;

    temp2 = temp2 + vecPerp * OFFSET + MatrixRotateY(a.base.rotation) * vec3 (BASE_OFFSET, 0, 0);
    float c = Length (temp2);
    float x = asind(Normalize(temp2) * vec3 (0, 1, 0));

    if (c > SEG1_LEN + SEG2_LEN)
    {
        //qDebug()<<"ARM ERROR!";
    }


    // Side view angles (solve via law of cosines)
    a.base.elbow = (float)(acos((pow(SEG2_LEN, 2) + pow(SEG1_LEN, 2) - pow(c, 2)) / (2 * SEG2_LEN * SEG1_LEN)) * 180.0f / M_PI);
    a.base.shoulder = (float)(acos((pow(c, 2) + pow(SEG1_LEN, 2) - pow(SEG2_LEN, 2)) / (2 * c * SEG1_LEN)) * 180.0f / M_PI);
    a.base.shoulder += x;

    a.wristElevation += 180 + a.base.shoulder + a.base.elbow;


    matrix m = MatrixTranslate(0, 0, 0);

    m = MatrixRotateY(a.base.rotation) * m;
    m = MatrixTranslate (-BASE_OFFSET, 0, 0) * m;

    m = MatrixRotateZ(a.base.shoulder) * m;
    m = MatrixTranslate(SEG1_LEN, 0, 0) * m;

    m = MatrixTranslate(0, 0, -OFFSET) * m;
    m = MatrixRotateZ(a.base.elbow - 180) * m;
    m = MatrixTranslate(SEG2_LEN, 0, 0) * m;

    m = MatrixRotateZ(-a.wristElevation) * m;
    m = MatrixTranslate(END_EFFECTOR_MID, 0, 0) * m;

    m = MatrixRotateY(a.writsTip) * m;
    m = MatrixTranslate(END_EFFECTOR_END, 0, 0) * m;

    vec3 test (m.array[2][0], m.array[2][1], m.array[2][2]);



    a.wristRotation = asind(vec3(0, 1, 0) * test);

    return a;
}

ArmDistances ArmController::SolveDistances(ArmWristAngles A) {
    ArmDistances d;



    matrix m = MatrixTranslate(0, 0, 0);

    m = MatrixRotateY(A.base.rotation) * m;
    m = MatrixTranslate (-BASE_OFFSET, 0, 0) * m;

    m = MatrixRotateZ(A.base.shoulder) * m;
    m = MatrixTranslate(SEG1_LEN, 0, 0) * m;

    m = MatrixTranslate(0, 0, -OFFSET) * m;
    m = MatrixRotateZ(A.base.elbow - 180) * m;
    m = MatrixTranslate(SEG2_LEN, 0, 0) * m;

    m = MatrixRotateZ(-A.wristElevation) * m;
    m = MatrixTranslate(END_EFFECTOR_MID, 0, 0) * m;

    m = MatrixRotateY(A.writsTip) * m;
    m = MatrixTranslate(END_EFFECTOR_END, 0, 0) * m;



    vec3 endPoint = m * vec3(0, 0, 0);
    d.x = endPoint[0];
    d.y = endPoint[1];
    d.z = endPoint[2];




    vec3 end = vec3 (m.array[0][0], m.array[0][1], m.array[0][2]);


    d.endEffectorDirection = Normalize(end);

    return d;
}

void ArmController::setHeightSpeed(float speed) {
    heightScale = speed;
}

void ArmController::setWidthSpeed(float speed) {
    widthScale = speed;
}

void ArmController::setDepthSpeed(float speed) {
    depthScale = speed;
}

bool ArmController::areAnglesValid(ArmAstroAngles a)
{
    if ((a.base.rotation > 45) ||
        (a.base.rotation < -220) ||
        (a.base.shoulder > 95) ||
        (a.base.shoulder < 0) ||
        ((a.base.elbow) > 160) ||
        ((a.base.elbow) < 15))
    {
        return false;
    }
    return true;
}

bool ArmController::areAnglesValid(ArmWristAngles a)
{
    if ((a.base.rotation > 45) ||
        (a.base.rotation < -80) ||
        (a.base.shoulder > 95) ||
        (a.base.shoulder < 0) ||
        ((13.12f + a.base.elbow) > 170) ||
        ((13.12f + a.base.elbow) < 15) ||
        ((a.wristElevation - 270 + 13.12f) > 250) ||
        ((a.wristElevation - 270 + 13.12f) < 0) ||
        (a.writsTip > 75) ||
        (a.writsTip < -75))
    {
        return false;
    }
    return true;
}

bool ArmController::areAnglesValid(ArmShovelAngles a)
{
    if ((a.base.rotation > 45) ||
        (a.base.rotation < -220) ||
        (a.base.shoulder > 95) ||
        (a.base.shoulder < 0) ||
        (a.base.elbow > 150) ||
        (a.base.elbow < 15))
    {
        return false;
    }
    return true;
}

float absFloat(float input)
{
    if (input < 0)
        return -input;

    return input;
}
float maxFloat (float a, float b)
{
    if (a > b)
        return a;

    return b;
}
float clamp (float input, float min, float max)
{
    if (input > max)
        return max;
    if (input < min)
        return min;
    return input;
}

float ArmController::compareAngles(ArmWristAngles a, ArmWristAngles b)
{
    float max = maxFloat (0, absFloat(a.base.rotation - b.base.rotation));
    max = maxFloat(max, absFloat(a.base.elbow - b.base.elbow));
    max = maxFloat(max, absFloat(a.base.shoulder - b.base.shoulder));
    max = maxFloat(max, absFloat(a.wristElevation - b.wristElevation));
    //max = maxFloat(max, absFloat(a.wristRotation - b.wristRotation));
    return max;
}

void ArmController::run()
{
    this->isInitialized = false;
    this->updateTimer->start();
}

void ArmController::stop()
{
    this->updateTimer->stop();
}

// Call every 200ms!
void ArmController::updateTime()
{
    if (this->pendingPacketCodes.length()> 0)
    {
        emit logAppend("Called updateTime Too Soon!  Ignoring update...");
        return;
    }

    // Send new positions and a request to get positions (or servo status, etc).
    // There's 200ms for sending and receiving, and each transmission should take between 25ms and 75ms.

    QList<QList<unsigned char> > packets;
    QList<unsigned char> p;

    // Get a movement packet, if possible
    p = this->getMovementPacket();
    if (p.length()> 0)
    {
        packets.append(p);
    }

    // Ask for actual position
    p.clear();
    p.append(0x4A);
    packets.append(p);

    // Ask for motor currents
    p.clear();
    p.append(0x4C);
    packets.append(p);

    // Pass through for servo status
    p.clear();
    p.append(0x40);
    p.append(0x21);
    p.append(0xF8);
    packets.append(p);

    // Send out the packets
    this->sendArmPackets(packets);
}

QList<unsigned char> ArmController::getMovementPacket(void)
{
    // Controls Updating
    float dirScale = 1.5;
    float rotChange = 1;
    bool hadChange = false;

    float yRotate = 0;
    float zRotate = 0;

    ArmDistances newArmValues;
    newArmValues.x=0;
    newArmValues.y=0;
    newArmValues.z=0;
    QList<unsigned char> packet;

    // Get end effector move packet (if needed)
    if (this->endEffectorConfig == 'w')
    {
        if (heightDirection==UpDirection) {
            newArmValues.y = newArmValues.y + heightScale*dirScale;
            hadChange = true;
            qDebug() << "going up";
        }
        else if (heightDirection==DownDirection) {
            qDebug() << "going down";
            newArmValues.y = newArmValues.y - heightScale*dirScale;
            hadChange = true;
        }

        if (widthDirection==LeftDirection) {
            newArmValues.z = newArmValues.z + widthScale*dirScale;
            hadChange = true;
            qDebug() << "going left";
        }
        else if (widthDirection==RightDirection) {
            newArmValues.z = newArmValues.z - widthScale*dirScale;
            hadChange = true;
            qDebug() << "going right";
        }

        if (depthDirection==InDirection) {
            newArmValues.x = newArmValues.x+ depthScale*dirScale;
            hadChange = true;
        }
        else if (depthDirection==OutDirection) {
            newArmValues.x = newArmValues.x - depthScale*dirScale;
            hadChange = true;
        }

        if (tipZDirection==UpDirection) {
            zRotate = rotChange;
            hadChange = true;
            qDebug() << "moving tip up";
        }
        else if (tipZDirection==DownDirection) {
            zRotate = -rotChange;
            hadChange = true;
            qDebug() << "moving tip down";
        }

        if (panDirection==LeftDirection) {
            yRotate = rotChange;
            hadChange=true;
            qDebug() << "moving tip left";
        }
        else if (panDirection==RightDirection) {
            yRotate = -rotChange;
            qDebug() << "moving tip right";
            hadChange=true;
        }

        if (wristDirection != NoDirection)
        {
            hadChange = true;
        }

        if (this->cameraRotateDirection != NoDirection)
        {
            hadChange = true;
        }

        if (this->cameraTiltDirection != NoDirection)
        {
            hadChange = true;
        }

        ArmDistances oldDistances = SolveDistances(this->desiredAngles);
        ArmWristAngles calcFromAngles = SolveAngles(oldDistances);
        bool anglesOk = (compareAngles (calcFromAngles, actualAngles) < 20); // desired angles are close to actual angles

        emit logAppend("Compared Angles = " + QString::number(compareAngles(calcFromAngles, actualAngles)));
        if (!anglesOk)
        {
            this->isInitialized = false; // Un-initialize the arm
            emit logAppend("Angles not good....!");
        }
        if (gripperDirection != this->NoDirection)
            hadChange = true;


        if (!hadChange)
        {
            emit logAppend("Had No Change!");
        }
        if (anglesOk && hadChange && this->isInitialized)
        {
            emit logAppend("Angles are good!");

            // Shoot for this speed (min 0, max 1)
            float speed = 0.80;

            ArmDistances temp;

            // Binary search to match speedPercent to the actual maximum velocity change
            float c = 0.25f, scale = 0.5f;
            for (int i = 0; i < 10; i++)
            {
                temp.x = oldDistances.x + newArmValues.x * scale;
                temp.y = oldDistances.y + newArmValues.y * scale;
                temp.z = oldDistances.z + newArmValues.z * scale;
                temp.endEffectorDirection = MatrixRotateZ (zRotate*scale) *MatrixRotateY (yRotate*scale) *  oldDistances.endEffectorDirection;

                ArmWristAngles originalAngles = SolveAngles(oldDistances);
                ArmWristAngles newAngles = SolveAngles(temp);

                //// Divide by maximum degree movement per the 200mS time
                float d1 = abs(originalAngles.base.rotation - newAngles.base.rotation) / 1.12f;
                float d2 = abs(originalAngles.base.elbow - newAngles.base.elbow) / 1.52f;
                float d3 = abs(originalAngles.base.shoulder - newAngles.base.shoulder) / 1.12f;
                float percentOfMax = qMax(d1, qMax(d2, d3));

                //float percentOfMax =  this->compareAngles(originalAngles, newAngles);

                if (percentOfMax > speed)
                {
                    scale -= c;
                }
                else
                {
                    scale += c;
                }
                c = c / 2.0f;
            }
            qDebug("Scale = %.2f", scale); // Scale should be between .5 and 1.0 when control input is maximum.

            temp.x = oldDistances.x + newArmValues.x * scale;
            temp.y = oldDistances.y + newArmValues.y * scale;
            temp.z = oldDistances.z + newArmValues.z * scale;
            temp.endEffectorDirection = MatrixRotateY (yRotate*scale) * MatrixRotateZ (zRotate*scale) * oldDistances.endEffectorDirection;




            ArmWristAngles newAngles = SolveAngles(temp);
            newAngles.base.cameraBase = this->desiredAngles.base.cameraBase;
            newAngles.base.cameraTip = this->desiredAngles.base.cameraTip;
            newAngles.gripper = this->desiredAngles.gripper;

            if (cameraTiltDirection==UpDirection)
            {
                newAngles.base.cameraBase += 5; // limit is here
            }
            else if (cameraTiltDirection==DownDirection)
            {
                newAngles.base.cameraBase -= 5;
            }
            newAngles.base.cameraBase = clamp (newAngles.base.cameraBase, CAMERA_ROTATE_MIN, CAMERA_ROTATE_MAX);

            if (cameraRotateDirection==UpDirection)
            {
                newAngles.base.cameraTip += 15;
            }
            else if (cameraRotateDirection==DownDirection)
            {
                newAngles.base.cameraTip -= 15;
            }
            newAngles.base.cameraTip = clamp(newAngles.base.cameraTip, CAMERA_TILT_MIN, CAMERA_TILT_MAX);

            // also send a gripper update
            if (gripperDirection==OpenDirection)
            {
                 newAngles.gripper -= 25;
            }
            else if (gripperDirection==CloseDirection)
            {
                newAngles.gripper += 25;
            }
            newAngles.gripper = clamp(newAngles.gripper, GRIPPER_MIN, GRIPPER_MAX);

            if (wristDirection==LeftDirection)
            {
                wristEndRotationOffset += 5.0f;
            }
            else if (wristDirection==RightDirection)
            {
                wristEndRotationOffset -= 5.0f;
            }

            newAngles.wristRotation += wristEndRotationOffset;

            if ((!this->areAnglesValid(newAngles)) || (compareAngles (newAngles, actualAngles) > 20))
            {
                emit logAppend("Invalid Angles!");
            }
            else
            {
                desiredAngles = newAngles;
                packet = GetPositionPacket(newAngles);

                //emit newArmPositions(newAngles); // Desired Arm Position
            }
        }
        else
        {
            emit logAppend("Angles no good!");
        }
    }
    else if (this->endEffectorConfig == 'a')
    {
        ArmAstroAngles a = this->desiredAstroAngles;
        matrix m = MatrixTranslate(0, 0, 0);

        //m = MatrixRotateY(A.base.rotation) * m;
        //m = MatrixTranslate (-BASE_OFFSET, 0, 0) * m;

        m = MatrixRotateZ(a.base.shoulder) * m;
        m = MatrixTranslate(SEG1_LEN, 0, 0) * m;

        m = MatrixTranslate(0, 0, -OFFSET) * m;
        m = MatrixRotateZ(a.base.elbow - 180) * m;
        m = MatrixTranslate(40, 0, 0) * m;

        vec3 endPoint = m * vec3(0, 0, 0);
        //d.x = endPoint[0];
        float height = endPoint[1];
        float length = endPoint[0];

        float rotate = desiredAstroAngles.base.rotation;

        if (heightDirection==UpDirection)
        {
            height += heightScale*dirScale * .5;
            hadChange = true;
        }
        else if (heightDirection==DownDirection)
        {
            height -= heightScale*dirScale * .5;
            hadChange = true;
        }

        if (widthDirection==LeftDirection)
        {
            rotate -= widthScale*dirScale * 0.5f;
            hadChange = true;
        }
        else if (widthDirection==RightDirection)
        {
            rotate += widthScale*dirScale * 0.5f;
            hadChange = true;
        }

        if (depthDirection==InDirection)
        {
            length += depthScale*dirScale * .5;
            hadChange = true;
        }
        else if (depthDirection==OutDirection)
        {
            length -= depthScale*dirScale * .5;
            hadChange = true;
        }

        float c = sqrt(height * height + length * length);
        float x = this->Atand(height/length);

        // Side view angles (solve via law of cosines)
        float SEG2_LEN = 40;
        a.base.elbow = (float)(acos((pow(SEG2_LEN, 2) + pow(SEG1_LEN, 2) - pow(c, 2)) / (2 * SEG2_LEN * SEG1_LEN)) * 180.0f / M_PI);
        a.base.shoulder = (float)(acos((pow(c, 2) + pow(SEG1_LEN, 2) - pow(SEG2_LEN, 2)) / (2 * c * SEG1_LEN)) * 180.0f / M_PI);
        a.base.shoulder += x;
        a.base.rotation = rotate;

        // also send a gripper update
        if (gripperDirection==OpenDirection)
        {
             a.gripper -= 50;
        }
        else if (gripperDirection==CloseDirection)
        {
            a.gripper += 50;
        }
        a.gripper = clamp(a.gripper, 50, 700);

        if (cameraTiltDirection==UpDirection)
        {
            a.base.cameraBase += 5;
        }
        else if (cameraTiltDirection==DownDirection)
        {
            a.base.cameraBase -= 5;
        }
        a.base.cameraBase = clamp (a.base.cameraBase, CAMERA_ROTATE_MIN, CAMERA_ROTATE_MAX);

        if (cameraRotateDirection==UpDirection)
        {
            a.base.cameraTip += 5;
        }
        else if (cameraRotateDirection==DownDirection)
        {
            a.base.cameraTip -= 5;
        }
        a.base.cameraTip = clamp(a.base.cameraTip, CAMERA_TILT_MIN, CAMERA_TILT_MAX);

        if ((absFloat(a.base.rotation - this->actualAstroAngles.base.rotation) < 25) &&
            (absFloat(a.base.shoulder - this->actualAstroAngles.base.shoulder) < 25 &&
            (absFloat(a.base.elbow - this->actualAstroAngles.base.elbow) < 25)) &&
            areAnglesValid(a))
        {
            desiredAstroAngles = a;
            packet = this->GetPositionPacket(desiredAstroAngles);
        }
        else
        {
            emit logAppend("Angles are no good!");
        }
        emit newArmPositions(desiredAstroAngles);

    }
    else if (this->endEffectorConfig == 's') // Shovel End Effector
    {
        ArmShovelAngles s = this->desiredShovelAngles;
        matrix m = MatrixTranslate(0, 0, 0);

        //m = MatrixRotateY(A.base.rotation) * m;
        //m = MatrixTranslate (-BASE_OFFSET, 0, 0) * m;

        m = MatrixRotateZ(s.base.shoulder) * m;
        m = MatrixTranslate(SEG1_LEN, 0, 0) * m;

        m = MatrixTranslate(0, 0, -OFFSET) * m;
        m = MatrixRotateZ(s.base.elbow - 180) * m;
        m = MatrixTranslate(40, 0, 0) * m;

        vec3 endPoint = m * vec3(0, 0, 0);
        //d.x = endPoint[0];
        float height = endPoint[1];
        float length = endPoint[0];

        if (heightDirection == UpDirection)
        {
            height += heightScale * dirScale * .5;
            hadChange = true;
        }
        else if (heightDirection == DownDirection)
        {
            height -= heightScale * dirScale * .5;
            hadChange = true;
        }

        if (widthDirection==LeftDirection)
        {
            s.base.rotation -= widthScale*dirScale * .6;
            hadChange = true;
        }
        else if (widthDirection==RightDirection)
        {
            s.base.rotation += widthScale*dirScale * .6;
            hadChange = true;
        }

        if (depthDirection==InDirection)
        {
            length += depthScale*dirScale * .5;
            hadChange = true;
        }
        else if (depthDirection==OutDirection)
        {
            length -= depthScale*dirScale * .5;
            hadChange = true;
        }

        float c = sqrt(height * height + length * length);
        float x = this->Atand(height/length);

        // Side view angles (solve via law of cosines)
        float SEG2_LEN = 40;
        s.base.elbow = (float)(acos((pow(SEG2_LEN, 2) + pow(SEG1_LEN, 2) - pow(c, 2)) / (2 * SEG2_LEN * SEG1_LEN)) * 180.0f / M_PI);
        s.base.shoulder = (float)(acos((pow(c, 2) + pow(SEG1_LEN, 2) - pow(SEG2_LEN, 2)) / (2 * c * SEG1_LEN)) * 180.0f / M_PI);
        s.base.shoulder += x;

        // also send a gripper update
        if (gripperDirection==OpenDirection)
        {
             s.head -= 50;
        }
        else if (gripperDirection==CloseDirection)
        {
            s.head += 50;
        }
        s.head = clamp(s.head, 600, 1000);

        if (wristDirection==LeftDirection)
        {
            s.lid += 50;
        }
        else if (wristDirection==RightDirection)
        {
            s.lid -= 50;
        }
        s.lid = clamp (s.lid, 75, 500);

        if (cameraTiltDirection==UpDirection)
        {
            s.base.cameraBase += 5;
        }
        else if (cameraTiltDirection==DownDirection)
        {
            s.base.cameraBase -= 5;
        }
        s.base.cameraBase = clamp (s.base.cameraBase, CAMERA_ROTATE_MIN, CAMERA_ROTATE_MAX);

        if (cameraRotateDirection==UpDirection)
        {
            s.base.cameraTip += 5;
        }
        else if (cameraRotateDirection==DownDirection)
        {
            s.base.cameraTip -= 5;
        }
        s.base.cameraTip = clamp(s.base.cameraTip, CAMERA_TILT_MIN, CAMERA_TILT_MAX);

        if ((absFloat(s.base.rotation - this->desiredShovelAngles.base.rotation) < 25) &&
            (absFloat(s.base.shoulder - this->desiredShovelAngles.base.shoulder) < 25 &&
            (absFloat(s.base.elbow - this->desiredShovelAngles.base.elbow) < 25)) &&
            areAnglesValid(s))
        {
            desiredShovelAngles = s;
            packet = this->GetPositionPacket(this->desiredShovelAngles);
        }
        else
        {
            emit logAppend("Angles are no good!");
        }
        //emit newArmPositions(this->desiredShovelAngles);
    }
    return packet;
}

float ArmController::BaseRotationTicksToDegrees(unsigned short ticks)
{
    float degrees = (float)(ticks - 500) / 175.873f - 147.5f - 90.0f;
    return degrees;
}

float ArmController::ShoulderTicksToDegrees(unsigned short ticks)
{
    float angle = 360.0f / 8192.0f * (ticks - 555);
    return angle;
}

float ArmController::ElbowTicksToDegrees(unsigned short ticks)
{
    float angle = 360.0f / 8192.0f * (ticks - 436);
    return angle;
}

unsigned short ArmController::bytesToUShort(unsigned char msb, unsigned char lsb) {
    return (msb<<8 | lsb);
}

// For interpreting received packets in a human readable way
// Note: Many parts of this method need work!
QString ArmController::messageToString(WirelessPacket msg)
{
    //QByteArray data = msg.data();

    QList<unsigned char> data;
    for (int i = 0; i<msg.data().length(); i++)
    {
        data.push_back(msg.data().at(i));
    }

    if (data.length() == 0)
    {
        return "No Data!";
    }

    QString s = "";

    if (data.length() > 0 && data.at(0) == PASS_THROUGH)
    {
        s = s + "(Pass Through) ";
        QList<unsigned char> d2;
        for (int i = 1; i<data.length();i++)
        {
            d2.push_back(data[i]);
        }
        data = d2;
    }


    switch ((unsigned char)data.at(0))
    {
        case ERROR:
            s += "Error: ";
            for (int i = 1; i < data.length(); i++)
            {
                s += QString::number(data.at(i)) + " ";
            }
            break;

        case DATA_NOT_AVAILABLE:
            s += "Data Not Yet Available";
            break;

        case ACK:
            s += "Command Acknowleged";
            break;

        case UNKNOWN_COMMAND:
            s += "Unknown Command!";
            break;

        case PING:
            s += "Ping Received";
            break;

        case GET_SPI_ADC:
            {
                // Data [1] is high byte, Data[2] is low byte
                unsigned short d = (unsigned short)(data[1] * 256 + data[2]);
                s += "SPI ADC = " + QString::number(d) + ", = " + QString::number(d * .0061, 'f', 2) + " amps";
            }
            break;

        case GET_TEMP_ADC:
            {
                unsigned short ADC = (unsigned short)(data[1] * 256 + data[2]);
                if (ADC == 0) ADC = 1;
                int resistance = 10223616 / ADC - 10000;
                double temperature = 25.0 + (10000.0 - resistance) / 100.0;
                s += "TEMP ADC = " + QString::number(ADC) + ", " + QString::number(resistance) + " ohms, " + QString::number(temperature, 'f', 2) + " degrees C";
            }
            break;

        case GET_POSITION:
            s += "Position = " + QString::number((unsigned short)((data[1] << 8) | data[2]));
            break;

        case GET_VELOCITY:
            {
                unsigned short speed = (unsigned short)((data[1] << 8) | data[2]);
                double RPM = 60 * speed / (22.722);
                s += "Velocity = " + QString::number(speed) + " = " + QString::number(RPM) + " RPM (motor)";
            }
            break;

        case SET_POSITION:
            s += "Position Set";
            break;

        case SET_VELOCITY:
            s += "Velocity Set";
            break;

        case SET_CURRENT:
            s += "Current Set";
            break;

        case SET_DUTY_CYCLE:
            s += "Duty Cycle Set";
            break;

        case ENABLE_MOSFET_DRIVER:
            s += "Mosfet Driver Enabled";
            break;

        case DISABLE_MOSFET_DRIVER:
            s += "Mosfet Driver Disabled";
            break;

        case GET_MAGNETIC_DISK_POS:
            {
                if (data.length() >= 3)
                {
                    QString sensor1 = "[Inner, Middle, Outer] = [";
                    if ((data[1] & (1 << 2)) != 0)
                        sensor1 += "_";
                    else
                        sensor1 += "+";

                    if ((data[1] & (1 << 1)) != 0)
                        sensor1 += "_";
                    else
                        sensor1 += "+";

                    if ((data[1] & (1 << 0)) != 0)
                        sensor1 += "_";
                    else
                        sensor1 += "+";

                    sensor1 += ", ";

                    if ((data[1] & (1 << 4)) != 0)
                        sensor1 += "_";
                    else
                        sensor1 += "+";

                    if ((data[1] & (1 << 5)) != 0)
                        sensor1 += "_";
                    else
                        sensor1 += "+";

                    if ((data[1] & (1 << 6)) != 0)
                        sensor1 += "_";
                    else
                        sensor1 += "+";

                    sensor1 += ", ";

                    if ((data[2] & (1 << 2)) != 0)
                        sensor1 += "_";
                    else
                        sensor1 += "+";

                    if ((data[2] & (1 << 1)) != 0)
                        sensor1 += "_";
                    else
                        sensor1 += "+";

                    if ((data[2] & (1 << 0)) != 0)
                        sensor1 += "_";
                    else
                        sensor1 += "+";

                    sensor1 += "]";


                    s = "Magnetic Encoder Data = " + sensor1;// data[1] + ", " + data[2];
                }
                else
                {
                    if (data.length() >= 2)
                    {
                        s += "Disc Position = " + data.at(1);
                    }
                }
            }
            break;

        case FIX_OFFSET:
            if (data.length() >= 3)
            {
                unsigned short pos = (unsigned short)(data[1] << 8 | data[2]);
                s += "Position After Offset = " + pos;
            }
            break;


        case SET_SERVO_POSITION:
            s += "Servo Position Set";
            break;

        case GET_SERVO_POSITION:
            s += "Servo Position = " + QString::number((unsigned short)(((data.at(1) & 0x03) << 8) | (data.at(2) & 0xFF)));
            break;

        case GET_SERVO_DATA: // Get Servo Data
            s += "Pos = " + QString::number((unsigned short)(data[1] << 8 | data[2]));
            s += ", Speed = " + QString::number(data[3]);
            s += ", Load = " + QString::number(data[4]);
            s += ", Voltage = " + QString::number(data[5]);
            s += ", Temp = " + QString::number(data[6]);
            s += ", Status = " + QString::number(data[7]);
            break;


        case 0xC1: // Read ADC value
            {
                unsigned short rawValue = (unsigned short)(data[1] << 8 | data[2]);
                s += "ADC Value = " + QString::number(rawValue) + ", voltage = " + QString::number((5.0f * rawValue / 16384), 'f', 2);

                double vRef = 16384;
                double vMeas = rawValue;
                double rBot = 1000000.0;
                double rTop = ((vRef - vMeas) * rBot / vMeas) / 1000000.0;
                s += " R = " + QString::number(rTop,'f', 3) + " Mohms";
            }
            break;

        case 0xC3:
            s += "Counter = " + (unsigned short)(data[1] << 8 | data[2]);
            break;

        case 0x4A:
            s += "Read All Positions";
            break;

        case 0x4B:
            s += "Set All Positions";
            break;

        case 0x4C:
            s += "Read All Currents";
            break;

        case 0x5A:
            s += "Zoom Set";
            break;

        default:
            s += "Unknown Command [";
            for (int i = 0; i<data.length(); i++)
            {

                s += QString::number((unsigned char)data.at(i));
                if (i < (data.length()-1))
                    s+= ", ";
            }
            s += "]";
            break;

    }
    return s;

}



ArmWristAngles ArmController::AnglesFromPositions(unsigned short baseRotation, unsigned short shoulderPosition, unsigned short elbowPosition,
                              unsigned short servo1, unsigned short servo2,
                              unsigned short servo7, unsigned short servo8, unsigned short servo9, unsigned short servo10)
{
    ArmWristAngles a;

    a.base.rotation = BaseRotationTicksToDegrees(baseRotation);

    a.base.shoulder = ShoulderTicksToDegrees(shoulderPosition);
    a.base.elbow = ElbowTicksToDegrees(elbowPosition) - 13.12;
    a.wristElevation = servo7 / 4.0f + 270 - 13.12f; // TODO: explain conversion...
    a.writsTip = (servo8 - 512) / 4.0f;
    a.wristRotation = (servo9 - 512) / 1.036111f;

    a.base.cameraBase = servo1;
    a.base.cameraTip = servo2;
    a.gripper = servo10;

    return a;
}

ArmAstroAngles ArmController::AnglesFromPositions(unsigned short baseRotation, unsigned short shoulderPosition, unsigned short elbowPosition,
                                                  unsigned short servo1, unsigned short servo2, unsigned short servo3)
{
    ArmAstroAngles a;
    a.base.rotation = BaseRotationTicksToDegrees(baseRotation);

    a.base.shoulder = ShoulderTicksToDegrees(shoulderPosition);
    a.base.elbow = ElbowTicksToDegrees(elbowPosition);

    a.base.cameraBase = servo1;
    a.base.cameraTip = servo2;
    a.gripper = servo3;

    return a;
}

ArmShovelAngles ArmController::AnglesFromPositions(unsigned short baseRotation, unsigned short shoulderPosition, unsigned short elbowPosition,
                                                  unsigned short servo1, unsigned short servo2,
                                                  unsigned short servo4, unsigned short servo5)
{
    ArmShovelAngles a;
    a.base.rotation = BaseRotationTicksToDegrees(baseRotation);

    a.base.shoulder = ShoulderTicksToDegrees(shoulderPosition);
    a.base.elbow = ElbowTicksToDegrees(elbowPosition);

    a.base.cameraBase = servo1;
    a.base.cameraTip = servo2;
    a.head = servo4;
    a.lid = servo5;

    return a;
}


void ArmController::handleMessage(WirelessPacket msg)
{
    if (msg.data().length() <= 0)
    {
        // Holy Crap! There's some junk going on here!
        emit logAppend("Got zero length packet!");
    }

    QString message = messageToString(msg);
    emit logAppend("From Arm: " + message);

    char packetCode = msg.data().at(0);
    int index = pendingPacketCodes.indexOf(packetCode);
    if (index == -1)
    {
        // Unexpected packet!  Might be something sent back after a timeout occured or an error.
        if (msg.data().at(0) == 0)
        {
            // Error
            QString s;
            for (int i = 0; i<msg.data().length(); i++)
            {
                s += QString::number(msg.data().at(i));
                if (i<(msg.data().length()-1))
                {
                    s += ", ";
                }
            }
            emit logAppend ("Error: bytes = " + s);
        }
        else
        {
             emit logAppend("Unexpected Packet!");
        }
    }
    else
    {
        pendingPacketCodes.removeAt(index); // Not pending anymore!
        if (pendingPacketCodes.length() == 0)
        {
            packetTimer->stop();
        }

        switch (msg.data().at(0))
        {
            case 0x4A: // positions
            {
                QList<unsigned char> data;
                for (int i = 0; i<msg.data().length(); i++)
                {
                    data.append(msg.data().at(i));
                }
                QString s;
                unsigned char dataIndex = 8; // Start of data
                unsigned short baseC = GetBits(data, dataIndex, 16); dataIndex += 16;
                unsigned short shoulder = GetBits(data, dataIndex, 13); dataIndex += 13;
                unsigned short elbow = GetBits(data, dataIndex, 13); dataIndex += 13;

                s += "Positions \t" + QString::number(baseC) + "\t" + QString::number(shoulder) + "\t" + QString::number(elbow) + "\t";

                unsigned char configCode = (unsigned char)GetBits(data, dataIndex, 8); dataIndex += 8;
                if (configCode == 'w') // Wrist Configuration Code - The wrist end effector is on there!
                {
                    endEffectorConfig = configCode;
                    unsigned short servo1 = GetBits(data, dataIndex, 10); dataIndex += 10;
                    unsigned short servo2 = GetBits(data, dataIndex, 10); dataIndex += 10;
                    unsigned short servo7 = GetBits(data, dataIndex, 10); dataIndex += 10;
                    unsigned short servo8 = GetBits(data, dataIndex, 10); dataIndex += 10;
                    unsigned short servo9 = GetBits(data, dataIndex, 10); dataIndex += 10;
                    unsigned short servo10 = GetBits(data, dataIndex, 10); dataIndex += 10;

                    s += QString::number(servo1) + "\t" + QString::number(servo2) + "\t" + QString::number(servo7) + "\t" + QString::number(servo8) + "\t" + QString::number(servo9) + "\t" + QString::number(servo10) + "\t";
                    this->actualAngles = AnglesFromPositions(baseC, shoulder, elbow, servo1, servo2, servo7, servo8, servo9, servo10);

                    // Update the arm drawing
                    emit newArmPositions(actualAngles);


                    if (!this->isInitialized)
                    {
                        emit logAppend("Setup for Wrist End Effector");
                        this->isInitialized = true;
                        this->desiredAngles = this->actualAngles;
                    }

                }
                else
                {
                    if (configCode == 's') // Shovel Configuration Code
                    {
                        endEffectorConfig = configCode;
                        unsigned short servo1 = GetBits(data, dataIndex, 10); dataIndex += 10;
                        unsigned short servo2 = GetBits(data, dataIndex, 10); dataIndex += 10;
                        unsigned short servo4 = GetBits(data, dataIndex, 10); dataIndex += 10;
                        unsigned short servo5 = GetBits(data, dataIndex, 10); dataIndex += 10;

                        s += QString::number(servo1) + "\t" + QString::number(servo2) + "\t" + QString::number(servo4) + "\t" + QString::number(servo5) + "\t";
                        this->actualShovelAngles = AnglesFromPositions(baseC, shoulder, elbow, servo1, servo2, servo4, servo5);


                        //emit logAppend(s);
                        // Update the arm drawing
                        emit newArmPositions(actualShovelAngles);

                        if (!this->isInitialized)
                        {
                            this->isInitialized = true;
                            this->desiredShovelAngles = this->actualShovelAngles;
                        }
                    }
                    else
                    {
                        if (configCode == 'a') // Astronaut gripper: Let's grab some astronauts!
                        {

                            unsigned short servo1 = GetBits(data, dataIndex, 10); dataIndex += 10;
                            unsigned short servo2 = GetBits(data, dataIndex, 10); dataIndex += 10;
                            unsigned short servo3 = GetBits(data, dataIndex, 10); dataIndex += 10;
                            s += QString::number(servo1) + "\t" + QString::number(servo2) + "\t" + QString::number(servo3);
                            this->actualAstroAngles = AnglesFromPositions(baseC, shoulder, elbow, servo1, servo2, servo3);

                            if (endEffectorConfig != configCode)
                            {
                                endEffectorConfig = configCode;
                                this->desiredAstroAngles = this->actualAstroAngles;
                                emit logAppend("Astronaut Gripper Detected: Rotate = " + QString::number(desiredAstroAngles.base.rotation));
                            }
                            //emit newArmPositions(actualAstroAngles);

                        }
                        else
                        {
                            s += QString("Unexpected Configuration Code!") + QString(configCode);
                        }
                    }

                }
                //emit logAppend(s);
            }
            break;

            case 0x4C:
            {
                QList<unsigned char> data;
                for (int i = 0; i<msg.data().length(); i++)
                {
                    data.append(msg.data().at(i));
                }

                unsigned char dataIndex = 8; // Start of data
                signed short baseCurrent = GetBits(data, dataIndex, 16); dataIndex += 16;
                signed short shoulderCurrent = GetBits(data, dataIndex, 16); dataIndex += 16;
                signed short elbowCurrent = GetBits(data, dataIndex, 16); dataIndex += 16;

                unsigned char configCode = (unsigned char)GetBits(data, dataIndex, 8); dataIndex += 8;
                unsigned short servo1 = GetBits(data, dataIndex, 8); dataIndex += 8;
                unsigned short servo2 = GetBits(data, dataIndex, 8); dataIndex += 8;

                QString line1 = "Base\tShoulder\tElbow\tServo 1\tServo 2";
                QString line2 = QString::number(baseCurrent) + "\t" + QString::number(shoulderCurrent) + "\t" + QString::number(elbowCurrent) +
                                "\t" + QString::number(servo1) + "\t" + QString::number(servo2);


                if (configCode == 'w') // Wrist Configuration Code - The wrist end effector is on there!
                {
                    unsigned short servo7 = GetBits(data, dataIndex, 8); dataIndex += 8;
                    unsigned short servo8 = GetBits(data, dataIndex, 8); dataIndex += 8;
                    unsigned short servo9 = GetBits(data, dataIndex, 8); dataIndex += 8;
                    unsigned short servo10 = GetBits(data, dataIndex, 8); dataIndex += 8;
                    line1 += "\tServo 7\tServo 8\tServo 9\tServo 10";
                    line2 += "\t" + QString::number(servo7) + "\t" + QString::number(servo8) + "\t" + QString::number(servo9) + "\t" + QString::number(servo10);
                }
                else if (configCode == 's') // Shovel Configuration Code
                {
                    unsigned short servo4 = GetBits(data, dataIndex, 8); dataIndex += 8;
                    unsigned short servo5 = GetBits(data, dataIndex, 8); dataIndex += 8;
                    line1 += "\tServo 4\tServo 5";
                    line2 += "\t" + QString::number(servo4) + "\t" + QString::number(servo5);
                }
                else if (configCode == 'a') // Astronaut gripper: Let's grab some astronauts!
                {
                    unsigned short servo3 = GetBits(data, dataIndex, 8); dataIndex += 8;
                    line1 += "\tServo 3";
                    line2 += "\t" + QString::number(servo3);
                }
                else
                {
                    line2 += QString("Unexpected Configuration Code!") + QString(configCode);
                }

                emit statusBox2Text("Arm Currents: Not to any reasonable scale, but too big a number is not good!\n" + line1 + "\n" + line2);
            }
            break;

            case 0x40: // Pass Through
            {
                if (msg.data().length() < 2)
                    break;

                switch ((unsigned char)(msg.data().at(1)))
                {
                    case 0x20:
                    {
                        emit logAppend("Ping Reply!");
                    }
                    break;

                    case 0xF8: // Servo Status
                    {
                        QList<unsigned char> data;
                        for (int i = 2; i<msg.data().length(); i++)
                        {
                            data.append(msg.data().at(i));
                        }

                        unsigned char dataIndex = 0;
                        unsigned char configCode = (unsigned char)GetBits(data, dataIndex, 8); dataIndex += 8;
                        unsigned short servo1 = GetBits(data, dataIndex, 8); dataIndex += 8;
                        unsigned short servo2 = GetBits(data, dataIndex, 8); dataIndex += 8;
                        QString line1 = "Servo 1\tServo 2";
                        QString line2 = QString::number(servo1) + "\t" + QString::number(servo2);


                        if (configCode == 'w') // Wrist Configuration Code - The wrist end effector is on there!
                        {
                            unsigned short servo7 = GetBits(data, dataIndex, 8); dataIndex += 8;
                            unsigned short servo8 = GetBits(data, dataIndex, 8); dataIndex += 8;
                            unsigned short servo9 = GetBits(data, dataIndex, 8); dataIndex += 8;
                            unsigned short servo10 = GetBits(data, dataIndex, 8); dataIndex += 8;
                            line1 += "\tServo 7\tServo 8\tServo 9\t Servo 10";
                            line2 += "\t" + QString::number(servo7) + "\t" + QString::number(servo8) + "\t" + QString::number(servo9) + "\t" + QString::number(servo10);

                        }
                        else if (configCode == 's') // Shovel Configuration Code
                        {
                            unsigned short servo4 = GetBits(data, dataIndex, 8); dataIndex += 8;
                            unsigned short servo5 = GetBits(data, dataIndex, 8); dataIndex += 8;
                            line1 += "\tServo 4\tServo 5";
                            line2 += "\t" + QString::number(servo4) + "\t" + QString::number(servo5) + "\t";
                        }
                        else if (configCode == 'a') // Astronaut gripper: Let's grab some astronauts!
                        {
                            unsigned short servo3 = GetBits(data, dataIndex, 8); dataIndex += 8;
                            line1 += "\tServo 3\t";
                            line2 += "\t" + QString::number(servo3) + "\t";
                        }
                        else
                        {
                            line1 += QString("Unexpected Configuration Code!") + QString(configCode);
                        }
                        emit statusBox1Text("Servo Status (Should all be zero!)\n" + line1 + "\n" + line2);

                    }
                    default:
                    break;
                }

            }
            break;
        }
    }
}

void ArmController::packetTimeoutHandler()
{
    emit logAppend("Query Timeout!");
    packetTimer->stop();
    this->pendingPacketCodes.clear();
}

int ArmController::sendArmPackets(QList<QList<unsigned char> > packets)
{
    if (this->pendingPacketCodes.length() > 0)
    {
        // Can't send new data until old data has timed out or been received.
        emit logAppend("Cannot send new data: old data is pending!");
        return -1;
    }

    if (packets.length() == 0 || packets.length() > 4)
    {
        // Too many packets to send or not enough to send.
        emit logAppend("Wrong number of packets to send: " + QString::number(packets.length()));
        return -1;
    }

    // OK to send
   // emit logAppend("Packet Count = " + QString::number(packets.length()));
    for (int i = 0; i<packets.length(); i++)
    {
        QList<unsigned char> packet = packets.at(i);
        unsigned char packetCode = packet.at(0);
        pendingPacketCodes.append(packetCode);
        //emit logAppend("Sending " + QString::number(packetCode));
        // Convert to a stupid QByteArray for the sendMessage function

        QByteArray arr;
        QString s;
        s+= " Length = " + QString::number(packet.length());
        for (int j = 0; j < packet.length(); j++)
        {
            s+= ", " + QString::number(packet.at(j));
            arr.append(packet.at(j));
        }
        //emit logAppend("Sending = " + s);
        sendMessage(arr);
    }

    packetTimer->start();
    return 0;
}

unsigned short ArmController::GetBits(QList<unsigned char> buffer, unsigned char bitStartIndex, unsigned char bitCount)
{
    unsigned short dataToBuild = 0;
    unsigned char i;

    unsigned char index = (unsigned char)(bitStartIndex / 8);
    unsigned char bitIndex = (unsigned char)(bitStartIndex - index * 8);


    for (i = 0; i < bitCount; i++)
    {
        if ((buffer[index] & (1 << bitIndex)) != 0)
        {
            dataToBuild |= (unsigned short)(1 << i);
        }

        bitIndex++;
        if (bitIndex == 8)
        {
            index++;
            bitIndex = 0;
        }
    }
    return dataToBuild;
}

unsigned char ArmController::AddData(QList<unsigned char> * buffer, unsigned char bitsInBuffer, unsigned short data, unsigned char bitsToAdd)
{
    unsigned char index = (unsigned char)(bitsInBuffer / 8);
    unsigned char bitIndex = (unsigned char)(bitsInBuffer - index * 8);
    while (index >= buffer->length())
    {
        buffer->append(0);
    }



    unsigned char i;
    for (i = 0; i < bitsToAdd; i++)
    {
        if ((data & (1 << i)) != 0)
        {
            (*buffer)[index] = buffer->at(index) | (unsigned char)(1 << bitIndex);
        }
        else
        {
            (*buffer)[index] = buffer->at(index) & (unsigned char)(~(1 << bitIndex));
        }
        bitIndex++;
        if (bitIndex == 8)
        {
            index++;
            bitIndex = 0;
            while (index >= buffer->length())
            {
                buffer->push_back(0);
            }
        }
    }
    return (unsigned char)(bitsInBuffer + bitsToAdd);
}


void ArmController::sendReadArmPosition()
{
    // Initialize send/receive setup
    //this->autoQuery = true;
}

QList<unsigned char> ArmController::GetPositionPacket (ArmAstroAngles a)
{
    unsigned short baseRotation = BaseRotationDegreesToTicks(a.base.rotation);

    unsigned short shoulder = ShoulderDegreesToTicks(a.base.shoulder);

    unsigned short elbow = ElbowDegreesToTicks(a.base.elbow); // Modified to real arm from model

    unsigned short gripper = (unsigned short)a.gripper;

    unsigned short cameraBase = (unsigned short)a.base.cameraBase;
    unsigned short cameraTip = (unsigned short)a.base.cameraTip;

    QList<unsigned char> piled;
    unsigned char bitCount = 0;

    bitCount = AddData(&piled, bitCount, 0x4B, 8); // Send Positions Command
    bitCount = AddData(&piled, bitCount, baseRotation, 16);
    bitCount = AddData(&piled, bitCount, shoulder, 13);
    bitCount = AddData(&piled, bitCount, elbow, 13);
    bitCount = AddData(&piled, bitCount, 'a', 8); // Wrist End Effector
    bitCount = AddData(&piled, bitCount, cameraBase, 10); // Camera Base
    bitCount = AddData(&piled, bitCount, cameraTip, 10);
    bitCount = AddData(&piled, bitCount, gripper, 10);

    return piled;
}

QList<unsigned char> ArmController::GetPositionPacket (ArmWristAngles a)
{
    unsigned short baseRotation = BaseRotationDegreesToTicks(a.base.rotation);

    unsigned short shoulder = ShoulderDegreesToTicks(a.base.shoulder);

    unsigned short elbow = ElbowDegreesToTicks(13.12f + a.base.elbow); // Modified to real arm from model

    float valueFloat = (a.wristElevation - 270 + 13.12f); // Modified to real arm from model
    unsigned short wristElevation = (unsigned short)(valueFloat * 4.0f);

    valueFloat = a.writsTip;// float.Parse(this.rotationServoBox.Text);
    unsigned short wristTip = (unsigned short)(valueFloat * 4.0f + 512);

    unsigned short wristRotation = (unsigned short)(1.036111f * (-a.wristRotation) + 512);

    unsigned short gripper = (unsigned short)a.gripper;

    unsigned short cameraBase = (unsigned short)a.base.cameraBase;
    unsigned short cameraTip = (unsigned short)a.base.cameraTip;

    QList<unsigned char> piled;
    unsigned char bitCount = 0;

    bitCount = AddData(&piled, bitCount, 0x4B, 8); // Send Positions Command
    bitCount = AddData(&piled, bitCount, baseRotation, 16);
    bitCount = AddData(&piled, bitCount, shoulder, 13);
    bitCount = AddData(&piled, bitCount, elbow, 13);
    bitCount = AddData(&piled, bitCount, 'w', 8); // Wrist End Effector
    bitCount = AddData(&piled, bitCount, cameraBase, 10); // Camera Base
    bitCount = AddData(&piled, bitCount, cameraTip, 10);
    bitCount = AddData(&piled, bitCount, wristElevation, 10);
    bitCount = AddData(&piled, bitCount, wristTip, 10);
    bitCount = AddData(&piled, bitCount, wristRotation, 10);
    bitCount = AddData(&piled, bitCount, gripper, 10);

    return piled;
}

QList<unsigned char> ArmController::GetPositionPacket (ArmShovelAngles s)
{

    unsigned short baseRotation = BaseRotationDegreesToTicks(s.base.rotation);

    unsigned short shoulder = ShoulderDegreesToTicks(s.base.shoulder);

    unsigned short elbow = ElbowDegreesToTicks(s.base.elbow); // Modified to real arm from model

    unsigned short lid = (unsigned short)(s.lid);
    unsigned short head = (unsigned short)(s.head);

    unsigned short cameraBase = (unsigned short)s.base.cameraBase;
    unsigned short cameraTip = (unsigned short)s.base.cameraTip;

    QList<unsigned char> piled;
    unsigned char bitCount = 0;

    bitCount = AddData(&piled, bitCount, 0x4B, 8); // Send Positions Command
    bitCount = AddData(&piled, bitCount, baseRotation, 16);
    bitCount = AddData(&piled, bitCount, shoulder, 13);
    bitCount = AddData(&piled, bitCount, elbow, 13);
    bitCount = AddData(&piled, bitCount, 's', 8); // Wrist End Effector
    bitCount = AddData(&piled, bitCount, cameraBase, 10); // Camera Base
    bitCount = AddData(&piled, bitCount, cameraTip, 10);
    bitCount = AddData(&piled, bitCount, head, 10);
    bitCount = AddData(&piled, bitCount, lid, 10);

    return piled;
}

void ArmController::setHeightUp() {
    heightDirection = UpDirection;
}

void ArmController::setHeightDown() {
    heightDirection = DownDirection;
}

void ArmController::setHeightStop() {
    heightDirection = NoDirection;
}

void ArmController::setWidthLeft() {
    widthDirection = LeftDirection;
}

void ArmController::setWidthRight() {
    widthDirection = RightDirection;
}

void ArmController::setWidthStop() {
    widthDirection = NoDirection;
}

void ArmController::setDepthIn() {
    depthDirection = InDirection;
}

void ArmController::setDepthOut() {
    depthDirection = OutDirection;
}

void ArmController::setDepthStop() {
    depthDirection = NoDirection;
}

void ArmController::setTipUp() {
    tipZDirection = UpDirection;
}

void ArmController::setTipDown() {
    tipZDirection = DownDirection;
}

void ArmController::setTipStop() {
    tipZDirection = NoDirection;
}

void ArmController::setPanLeft() {
    panDirection = LeftDirection;
}

void ArmController::setPanRight() {
    panDirection = RightDirection;
}

void ArmController::setPanStop() {
    panDirection = NoDirection;
}

int ArmController::sendPacket(QList<unsigned char> packet)
{
    QList<QList<unsigned char> > packets;
    packets.append(packet);

    return this->sendArmPackets(packets);
}

void ArmController::sendZoom(char zoom)
{
    QList<unsigned char> p;
    p.append(0x5A);
    p.append(zoom);
    if (this->sendPacket(p) == 0)
    {
        emit logAppend("Zoom Set to " + QString::number(zoom));
    }
}

void ArmController::setZoomIn() {
    sendZoom(1);
}

void ArmController::setZoomOut() {
    sendZoom(2);
}

void ArmController::setZoomStop() {
    sendZoom(0);
}

void ArmController::setGripperOpen() {
    gripperDirection=OpenDirection;
}

void ArmController::setGripperClose() {
    gripperDirection=CloseDirection;
}

void ArmController::setGripperStop() {
    gripperDirection=NoDirection;
}

void ArmController::setCameraTiltUp() {
    cameraTiltDirection = UpDirection;
}

void ArmController::setCameraTiltDown() {
    cameraTiltDirection = DownDirection;
}

void ArmController::setCameraTiltStop() {
    cameraTiltDirection = NoDirection;
}

void ArmController::setCameraRotateUp() {
    cameraRotateDirection = UpDirection;
}

void ArmController::setCameraRotateDown() {
    cameraRotateDirection = DownDirection;
}

void ArmController::setCameraRotateStop() {
    cameraRotateDirection = NoDirection;
}

void ArmController::setWristRotateLeft() {
    wristDirection = LeftDirection;
}

void ArmController::setWristRotateRight() {
    wristDirection = RightDirection;
}

void ArmController::setWristRotateStop() {
    wristDirection = NoDirection;
}

void ArmController::setGripperPosition(unsigned short pos) {
    gripperPos = pos;
    setServoPosition(0x0A, pos);
}


void ArmController::setServoPosition(unsigned char id, unsigned short pos) {

/*    QByteArray pkt;

    pkt.append(0x40);
    pkt.append(0x21);
    pkt.append(0xF0);
    pkt.append(id);
    pkt.append((pos >> 8) & 0xFF);
    pkt.append(pos & 0xFF);

    //pktQueue.append(pkt);
    //if (lastSentPkt.size()==0) {
    //    sendArmPacket(pktQueue.dequeue());
    //}
    */
}
