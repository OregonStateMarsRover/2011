#ifndef ARMGLWIDGET_H
#define ARMGLWIDGET_H

#include <QGLWidget>

#include "VirtualRover/ArmController.h"
#include "Common/Matrix.h"

class ArmGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit ArmGLWidget(QWidget *parent = 0);

signals:

public slots:
    void newArmPositions(ArmWristAngles angles);
    void newArmPositions(ArmAstroAngles angles);
    void newArmPositions(ArmShovelAngles angles);

private:
    void initializeGL();
    void setupLighting();

    void resizeGL(int w, int h);
    void paintGL();

    void drawArm(ArmWristAngles w);
    void drawArm(ArmAstroAngles a);
    void drawArm(ArmShovelAngles s);
    void drawArm(void);

    void drawBox(float x, float y, float z);
    void drawCylinder(float radius, float length);
    void drawCylinderX(float radius, float length);
    void drawCylinderY(float radius, float length);
    void drawCylinderZ(float radius, float length);
    void drawRandomTube(float scale);

    int fieldOfView;

    ArmWristAngles wristAngles;
    ArmAstroAngles astroAngles;
    ArmShovelAngles shovelAngles;

    // w, s, a: wrist, shovel, astro
    char armConfiguration;

    //ArmDistances distances;
    vec3 translate;

};

#endif // ARMGLWIDGET_H
