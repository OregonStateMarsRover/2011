#include <QtGlobal>

#include "VirtualRover/ArmController.h"

#include "ArmGLWidget.h"

#include "GL/gl.h"
#include "GL/glu.h"

#define SIDES 8

ArmGLWidget::ArmGLWidget(QWidget *parent) :
    QGLWidget(parent), translate(0, 0, -100)
{
    srand(0);
    fieldOfView = 60;
    this->armConfiguration = '?'; // Unknown!
}

void ArmGLWidget::newArmPositions(ArmWristAngles angles) {
    this->wristAngles = angles;
    this->armConfiguration = 'w'; // Wrist configuration
    updateGL();
}

void ArmGLWidget::newArmPositions(ArmAstroAngles angles)
{
    this->astroAngles = angles;
    this->armConfiguration = 'a'; // Astro Configuration
    updateGL();
}

void ArmGLWidget::newArmPositions(ArmShovelAngles angles)
{
    this->shovelAngles = angles;
    this->armConfiguration = 's'; // Shovel configuration
    updateGL();
}

void ArmGLWidget::initializeGL() {
    /* Initial OpenGL Setup */
    glClearColor (0.0f, 0.0f, 0.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    setupLighting();
}

void ArmGLWidget::setupLighting() {
    float lightarray1 [4];
    float lightarray2 [4];
    float lightarray3 [4];

    lightarray1[0] = .1;
    lightarray1[1] = .1;
    lightarray1[2] = .1;
    lightarray1[3] = .1;

    lightarray2[0] = .25;
    lightarray2[1] = .25;
    lightarray2[2] = 0;
    lightarray2[3] = 1;

    lightarray3[0] = .5;
    lightarray3[1] = 0;
    lightarray3[2] = 1;
    lightarray3[3] = 0;

    glEnable (GL_LIGHTING);
    glEnable (GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightarray1);//  ' light thats always there.
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightarray2); // ' light coming from a source.
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightarray2); // ' Shiny light
    glLightfv(GL_LIGHT0, GL_POSITION, lightarray3);//' where the light source is.

    lightarray1[0] = 0;
    lightarray1[1] = 0;
    lightarray1[2] = 0;
    lightarray1[3] = 1;

    lightarray2[0] = 0;
    lightarray2[1] = .75;
    lightarray2[2] = .75;
    lightarray2[3] = 1;

    lightarray3[0] = -0.5f;
    lightarray3[1] = 0;
    lightarray3[2] = 1;
    lightarray3[3] = 1; // 1 for position, 0 for direction?

    glEnable (GL_LIGHT2);
    glLightfv (GL_LIGHT2, GL_AMBIENT, lightarray1);
    glLightfv (GL_LIGHT2, GL_DIFFUSE, lightarray2);
    glLightfv (GL_LIGHT2, GL_POSITION, lightarray3);


    glEnable(GL_NORMALIZE);
    glColorMaterial (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable (GL_COLOR_MATERIAL);
}

void ArmGLWidget::resizeGL(int width, int height) {
    if (height==0)
        height = 1;

    glViewport (0, 0, width, height);

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective (fieldOfView, ((float)width)/height, 1, 3000);
    glMatrixMode (GL_MODELVIEW);
}

void ArmGLWidget::paintGL() {
    // Render the scene (drawing code goes here!)
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int width = this->width();
    int height= this->height();

    float h = height/2;
    float w = width/2;
    if (h==0)
        h = 1;

    // Whole Screen (cross lines)
    glViewport (0, 0, width, height);
    glMatrixMode (GL_PROJECTION);
        glLoadIdentity ();
        glOrtho (-1, 1, -1, 1, -1, 1);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
    glBegin(GL_LINES);
    glVertex2f (-1, 0);
    glVertex2f (1, 0);
    glVertex2f (0, -1);
    glVertex2f (0, 1);
    glEnd();

    // 3D View
    glViewport (w, h, w, h);
    glMatrixMode (GL_PROJECTION);
        glLoadIdentity ();
        gluPerspective (60, (((float)w)/h), 1, 3000);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(translate[0], translate[1], translate[2]);

    //glRotatef (tip, 1, 0, 0);
    //glRotatef (turn, 0, 1, 0);

    //glPushMatrix();
    //glTranslatef (distances.x, distances.y, distances.z);
    //drawBox(.5, 2, .5);
    //drawBox(.5, .5, 2);
    //drawBox(2, .5, .5);
    //glPopMatrix();
    drawArm();


    // Width for orthographic viewport
    float scale = 75;

    // Top View
    glViewport (0, h, w, h);
    glMatrixMode (GL_PROJECTION);
        glLoadIdentity ();
        //gluPerspective (60, (((float)w)/h), 1, 3000);
        glOrtho(-scale * (((float)w)/h), scale * (((float)w)/h), -scale, scale, -1000, 1000);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-50, 0, -200);
    glRotatef(90, 1, 0, 0);
    drawArm();

    // Side View
    glViewport (0, 0, w, h);
    glMatrixMode (GL_PROJECTION);
        glLoadIdentity ();
        //gluPerspective (60, (((float)w)/h), 1, 3000);
        glOrtho(-scale * (((float)w)/h), scale * (((float)w)/h), -scale, scale, -1000, 1000);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-50, 0, -200);
    drawArm();

    // Front View
    glViewport (w, 0, w, h);
    glMatrixMode (GL_PROJECTION);
        glLoadIdentity ();
        //gluPerspective (60, (((float)w)/h), 1, 3000);
        glOrtho(-scale * (((float)w)/h), scale * (((float)w)/h), -scale, scale, -1000, 1000);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -200);
    glRotatef(-90, 0, 1, 0);
    drawArm();
}

void ArmGLWidget::drawBox(float x, float y, float z)
{
    glPushMatrix();

    glScalef(x, y, z);


    for (int i = 0; i<6; i++)
    {
        if (i==5)
        {
            glRotatef(180, 1, 0, 0);
        }
        else if (i==4)
        {
            glRotatef(90, 1, 0, 0);
        }
        else
        {
            glRotatef(90, 0, 1, 0);
        }
        glBegin(GL_QUADS);
        glNormal3f (0, 0, 1);
        glVertex3f (-0.5, -0.5, 0.5);
        glVertex3f (0.5, -0.5, 0.5);
        glVertex3f (0.5, 0.5, 0.5);
        glVertex3f (-0.5, 0.5, 0.5);
        glEnd();
    }

    glPopMatrix();
}

// Draw a cylinder oriented along the Z axis, centered on the origin
void ArmGLWidget::drawCylinder(float radius, float length)
{
    glPushMatrix();
    glScalef(radius, radius, length);
    glBegin(GL_TRIANGLE_FAN);

    // Front Face
    glNormal3f(0, 0, 1);
    for (int i = 0; i<SIDES; i++)
    {
        glVertex3f(sind((i+.5)*360/SIDES), cosd((i+.5)*360/SIDES), .5);
    }
    glEnd();

    // Back Face
    glBegin(GL_TRIANGLE_FAN);
    glNormal3f(0, 0, -1);
    for (int i = 0; i<SIDES; i++)
    {
        glVertex3f(sind((i+.5)*360/SIDES), cosd((i+.5)*360/SIDES), -.5);

    }
    glEnd();

    // Tube part
    glBegin(GL_QUADS);

    for (int i = 0; i<SIDES; i++)
    {
        glNormal3f(sind((i+.5)*360/SIDES), cosd((i+.5)*360/SIDES), 0);
        glVertex3f(sind((i+.5)*360/SIDES), cosd((i+.5)*360/SIDES), -.5);
        glVertex3f(sind((i+.5)*360/SIDES), cosd((i+.5)*360/SIDES), 0.5);
        i++;
        glVertex3f(sind((i+.5)*360/SIDES), cosd((i+.5)*360/SIDES), 0.5);
        glVertex3f(sind((i+.5)*360/SIDES), cosd((i+.5)*360/SIDES), -.5);
        i--;
    }
    glEnd();

    glPopMatrix();

    return;
}

void ArmGLWidget::drawCylinderX(float radius, float length)
{
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    drawCylinder(radius, length);
    glPopMatrix();
}
void ArmGLWidget::drawCylinderY(float radius, float length)
{
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    drawCylinder(radius, length);
    glPopMatrix();
}
void ArmGLWidget::drawCylinderZ(float radius, float length)
{
    drawCylinder(radius, length);
}

void ArmGLWidget::drawArm(ArmWristAngles A)
{
    // Rover!
    glColor3f (.5, .5, .5);
    glTranslatef (-35, 5, 15);
    drawBox(45, 15, 45);
    glTranslatef (35, -5, -15);

    glColor3f (1, 1, 1);

    // Testing
    matrix m = MatrixTranslate(0, 0, 0);

    float val = -(ArmController::BASE_OFFSET);
    m = MatrixRotateY(A.base.rotation) * m;
    m = MatrixTranslate(-ArmController::BASE_OFFSET, 0, 0) * m;

    m = MatrixRotateZ(A.base.shoulder) * m;
    m = MatrixTranslate(ArmController::SEG1_LEN, 0, 0) * m;

    m = MatrixTranslate(0, 0, -ArmController::OFFSET) * m;
    m = MatrixRotateZ(A.base.elbow - 180) * m;
    m = MatrixTranslate(ArmController::SEG2_LEN, 0, 0) * m;

    m = MatrixRotateZ(-A.wristElevation) * m;
    m = MatrixTranslate(ArmController::END_EFFECTOR_MID, 0, 0) * m;

    m = MatrixRotateY(A.wristRotation) * m;
    m = MatrixTranslate(ArmController::END_EFFECTOR_END, 0, 0) * m;


    glPushMatrix();
        glMultMatrixf (*(m.array));
        drawBox(1, 1, 1);
    glPopMatrix();

    glColor3f (1, 0, 0);

    // Draw arm box
    drawBox(15, 5, 15);

    glRotatef(A.base.rotation, 0, 1, 0);
    glTranslatef(0, 3.5, 0);
    drawCylinderY(3, 2);
    glTranslatef(-ArmController::BASE_OFFSET, 2, 0);
    drawCylinderZ(2, 6);


    glColor3f (0, 1, 0);

    glRotatef (A.base.shoulder, 0, 0, 1);//g.RotateTransform(-A.thetaS, System..Drawing2D.MatrixOrder.Prepend);
    glTranslatef(ArmController::SEG1_LEN/2, 0, 0);
    drawCylinderX(2, ArmController::SEG1_LEN);
    glTranslatef(ArmController::SEG1_LEN/2, 0, -ArmController::OFFSET/2);
    drawCylinderZ(2, ArmController::OFFSET + 4);
    glTranslatef(0, 0, -ArmController::OFFSET/2);

    glColor3f (1, 1, 0);

    // Elbow to wrist elevation
    glRotatef (A.base.elbow - 180, 0, 0, 1);//g.RotateTransform(180 - A.thetaE, System.Drawing.Drawing2D.MatrixOrder.Prepend);
    glTranslatef (ArmController::SEG2_LEN/2, 0, 0);
    drawCylinderX(2, ArmController::SEG2_LEN);
    glTranslatef (ArmController::SEG2_LEN/2, 0, 0);
    drawCylinderZ(2, 4);


    glColor3f (0, 0, 1);
    // Wirst elevation to wrist rotate
    glRotatef(-A.wristElevation, 0, 0, 1);//g.RotateTransform(A.thetaW, System.Drawing.Drawing2D.MatrixOrder.Prepend);

    glTranslatef(ArmController::END_EFFECTOR_MID/2, 0, 0);
    drawCylinderX(2, ArmController::END_EFFECTOR_MID);
    glTranslatef(ArmController::END_EFFECTOR_MID/2, 0, 0);
    drawCylinderY(2, 4);

    glColor3f (1, 0, 1);

    float GRIPPER_ARM_LEN = 8;
    float HALF = ArmController::END_EFFECTOR_END - GRIPPER_ARM_LEN; // Point of rotation servo
    glRotatef(A.writsTip, 0, 1, 0);
    glTranslatef(HALF/2, 0, 0);
    drawCylinderX(2, HALF);
    glTranslatef(HALF/2, 0, 0);

    glColor3f (0, 1, 1);

    static float r = 0;
    r += 7;

    glRotatef (A.wristRotation, 1, 0, 0);

    // CLAMPY CLAMPY!
    static float a = 0;
    a = sind(r) * 15;
    drawCylinderX(4, 1);
    glPushMatrix();
    glTranslatef(0, 0, -4);
    drawCylinderY(1, 2);
    glRotatef(a, 0, 1, 0);
    glTranslatef (GRIPPER_ARM_LEN/2, 0, 0);
    drawCylinderX(1, GRIPPER_ARM_LEN);
    glTranslatef (GRIPPER_ARM_LEN/2, 0, 0);
    glRotatef(-a - 90, 0, 1, 0);
    drawCylinderY(1, 2);
    glTranslatef(1, 0, 0);
    drawCylinderX(1, 2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 4);
    drawCylinderY(1, 2);
    glRotatef(-a, 0, 1, 0);
    glTranslatef (GRIPPER_ARM_LEN/2, 0, 0);
    drawCylinderX(1, GRIPPER_ARM_LEN);
    glTranslatef (GRIPPER_ARM_LEN/2, 0, 0);
    glRotatef(a + 90, 0, 1, 0);
    drawCylinderY(1, 2);
    glTranslatef(1, 0, 0);
    drawCylinderX(1, 2);
    glPopMatrix();
}

void ArmGLWidget::drawArm(ArmAstroAngles A)
{
    // Rover!
    glColor3f (.5, .5, .5);
    glTranslatef (-35, 5, 15);
    drawBox(45, 15, 45);
    glTranslatef (35, -5, -15);

    glColor3f (1, 1, 1);

    // Testing
    matrix m = MatrixTranslate(0, 0, 0);

    //m = MatrixRotateY(A.base.rotation) * m;
    m = MatrixTranslate (-ArmController::BASE_OFFSET, 0, 0) * m;

    m = MatrixRotateZ(A.base.shoulder) * m;
    m = MatrixTranslate(ArmController::SEG1_LEN, 0, 0) * m;

    //m = MatrixTranslate(0, 0, -OFFSET) * m;
    m = MatrixRotateZ(A.base.elbow - 180) * m;
    m = MatrixTranslate(40, 0, 0) * m;


    glPushMatrix();
        glMultMatrixf (*(m.array));
        drawBox(1, 1, 1);
    glPopMatrix();

    glColor3f (1, 0, 0);

    // Draw arm box
    drawBox(15, 5, 15);

    glRotatef(A.base.rotation, 0, 1, 0);
    glTranslatef(0, 3.5, 0);
    drawCylinderY(3, 2);
    glTranslatef(-ArmController::BASE_OFFSET, 2, 0);
    drawCylinderZ(2, 6);


    glColor3f (0, 1, 0);

    glRotatef (A.base.shoulder, 0, 0, 1);//g.RotateTransform(-A.thetaS, System..Drawing2D.MatrixOrder.Prepend);
    glTranslatef(ArmController::SEG1_LEN/2, 0, 0);
    drawCylinderX(2, ArmController::SEG1_LEN);
    glTranslatef(ArmController::SEG1_LEN/2, 0, -ArmController::OFFSET/2);
    drawCylinderZ(2, ArmController::OFFSET + 4);
    glTranslatef(0, 0, -ArmController::OFFSET/2);

    glColor3f (1, 1, 0);

    // Elbow to wrist elevation
    glRotatef (A.base.elbow - 180, 0, 0, 1);//g.RotateTransform(180 - A.thetaE, System.Drawing.Drawing2D.MatrixOrder.Prepend);
    float elbowToEnd = 20;
    glTranslatef (elbowToEnd/2, 0, 0);
    drawCylinderX(2, elbowToEnd);
    glTranslatef (elbowToEnd/2, 0, 0);
    drawCylinderZ(2, 4);


    //glColor3f (0, 0, 1);
    // Wirst elevation to wrist rotate
    //glRotatef(-A.wristElevation, 0, 0, 1);//g.RotateTransform(A.thetaW, System.Drawing.Drawing2D.MatrixOrder.Prepend);

    //glTranslatef(ArmController::END_EFFECTOR_MID/2, 0, 0);
    //drawCylinderX(2, ArmController::END_EFFECTOR_MID);
    //glTranslatef(ArmController::END_EFFECTOR_MID/2, 0, 0);
    //drawCylinderY(2, 4);

    glColor3f (1, 0, 1);

    float GRIPPER_ARM_LEN = 8;
    //float HALF = ArmController::END_EFFECTOR_END - GRIPPER_ARM_LEN; // Point of rotation servo
    //glRotatef(A.writsTip, 0, 1, 0);
    //glTranslatef(HALF/2, 0, 0);
    //drawCylinderX(2, HALF);
    //glTranslatef(HALF/2, 0, 0);

    //glColor3f (0, 1, 1);

    static float r = 0;
    r += 7;

    //glRotatef (A.wristRotation, 1, 0, 0);

    // CLAMPY CLAMPY!
    static float a = 0;
    a = sind(r) * 15;
    drawCylinderX(4, 1);
    glPushMatrix();
    glTranslatef(0, 0, -4);
    drawCylinderY(1, 2);
    glRotatef(a, 0, 1, 0);
    glTranslatef (GRIPPER_ARM_LEN/2, 0, 0);
    drawCylinderX(1, GRIPPER_ARM_LEN);
    glTranslatef (GRIPPER_ARM_LEN/2, 0, 0);
    glRotatef(-a - 90, 0, 1, 0);
    drawCylinderY(1, 2);
    glTranslatef(1, 0, 0);
    drawCylinderX(1, 2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 4);
    drawCylinderY(1, 2);
    glRotatef(-a, 0, 1, 0);
    glTranslatef (GRIPPER_ARM_LEN/2, 0, 0);
    drawCylinderX(1, GRIPPER_ARM_LEN);
    glTranslatef (GRIPPER_ARM_LEN/2, 0, 0);
    glRotatef(a + 90, 0, 1, 0);
    drawCylinderY(1, 2);
    glTranslatef(1, 0, 0);
    drawCylinderX(1, 2);
    glPopMatrix();
}

void ArmGLWidget::drawArm(ArmShovelAngles A)
{
    // Rover!
    glColor3f (.5, .5, .5);
    glTranslatef (-35, 5, 15);
    drawBox(45, 15, 45);
    glTranslatef (35, -5, -15);

    glColor3f (1, 1, 1);

    // Testing
    matrix m = MatrixTranslate(0, 0, 0);

    //m = MatrixRotateY(A.base.rotation) * m;
    m = MatrixTranslate (-ArmController::BASE_OFFSET, 0, 0) * m;

    m = MatrixRotateZ(A.base.shoulder) * m;
    m = MatrixTranslate(ArmController::SEG1_LEN, 0, 0) * m;

    //m = MatrixTranslate(0, 0, -OFFSET) * m;
    m = MatrixRotateZ(A.base.elbow - 180) * m;
    m = MatrixTranslate(40, 0, 0) * m;


    glPushMatrix();
        glMultMatrixf (*(m.array));
        drawBox(1, 1, 1);
    glPopMatrix();

    glColor3f (1, 0, 0);

    // Draw arm box
    drawBox(15, 5, 15);

    // Draw box to drop samples into
    glPushMatrix();
    // x = front to back, y = up and down, z = side to side
    glTranslatef(0, - 2.5 + (4 + 5 - 2) * 2.54 , (23) * 2.54);
    drawBox(7.25 * 2.54, 4 * 2.54, 6.5 * 2.54);
    glPopMatrix();

    glRotatef(A.base.rotation, 0, 1, 0);
    glTranslatef(0, 3.5, 0);
    drawCylinderY(3, 2);
    glTranslatef(-ArmController::BASE_OFFSET, 2, 0);
    drawCylinderZ(2, 6);


    glColor3f (0, 1, 0);

    glRotatef (A.base.shoulder, 0, 0, 1);//g.RotateTransform(-A.thetaS, System..Drawing2D.MatrixOrder.Prepend);
    glTranslatef(ArmController::SEG1_LEN/2, 0, 0);
    drawCylinderX(2, ArmController::SEG1_LEN);
    glTranslatef(ArmController::SEG1_LEN/2, 0, -ArmController::OFFSET/2);
    drawCylinderZ(2, ArmController::OFFSET + 4);
    glTranslatef(0, 0, -ArmController::OFFSET/2);

    glColor3f (1, 1, 0);

    // Elbow to wrist elevation
    glRotatef (A.base.elbow - 180, 0, 0, 1);//g.RotateTransform(180 - A.thetaE, System.Drawing.Drawing2D.MatrixOrder.Prepend);
    float elbowToEnd = 35;
    glTranslatef (elbowToEnd/2, 0, 0);
    drawCylinderX(2, elbowToEnd);
    glTranslatef (elbowToEnd/2, 0, 0);
    drawCylinderZ(2, 4);


    glColor3f (1, 0, 1);

    glPushMatrix();
    glRotatef(((float)A.head - 1000.0f) * 160.0f / 1024.0f, 0, 0, 1);

    glPushMatrix();
    glRotatef(((float)A.lid - 600.0f) * 300.0f / 1024.0f, 0, 0, 1);
    this->drawBox(4, 1, 6);
    glPopMatrix();


    glRotatef(90, 0, 0, 1);
    glTranslatef(2, 0, 0);
    this->drawBox(4, 1, 8);
    glTranslatef(2, 0, 0);

    glRotatef(-90, 0, 0, 1);
    glTranslatef(4, 0, 0);
    this->drawBox(7, 1, 8);
    glTranslatef(4, 0, 0);

    glRotatef(-70, 0, 0, 1);
    glTranslatef(2.5, 0, 0);
    this->drawBox(5, 1, 8);
    glPopMatrix();



   /* float GRIPPER_ARM_LEN = 8;

    static float r = 0;
    r += 7;

    //glRotatef (A.wristRotation, 1, 0, 0);

    // CLAMPY CLAMPY!
    static float a = 0;
    a = sind(r) * 15;
    drawCylinderX(4, 1);
    glPushMatrix();
    glTranslatef(0, 0, -4);
    drawCylinderY(1, 2);
    glRotatef(a, 0, 1, 0);
    glTranslatef (GRIPPER_ARM_LEN/2, 0, 0);
    drawCylinderX(1, GRIPPER_ARM_LEN);
    glTranslatef (GRIPPER_ARM_LEN/2, 0, 0);
    glRotatef(-a - 90, 0, 1, 0);
    drawCylinderY(1, 2);
    glTranslatef(1, 0, 0);
    drawCylinderX(1, 2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 4);
    drawCylinderY(1, 2);
    glRotatef(-a, 0, 1, 0);
    glTranslatef (GRIPPER_ARM_LEN/2, 0, 0);
    drawCylinderX(1, GRIPPER_ARM_LEN);
    glTranslatef (GRIPPER_ARM_LEN/2, 0, 0);
    glRotatef(a + 90, 0, 1, 0);
    drawCylinderY(1, 2);
    glTranslatef(1, 0, 0);
    drawCylinderX(1, 2);
    glPopMatrix();*/
}

void ArmGLWidget::drawRandomTube(float scale)
{

    float length = scale * ((rand() % 1000) / 1000.0f) * 3;
    float radius = scale * .25 * ((rand() % 1000) / 1000.0f);
    float xAngle = rand () % 360;
    float yAngle = rand () % 360;
    float zAngle = rand () % 360;

    glPushMatrix();
    glColor3f (.5 + (rand () % 50) / 100.0f, .5 + (rand () % 50) / 100.0f, .5 + (rand () % 50) / 100.0f);
    glTranslatef ((rand() % 1000) / 1000.0f * scale * 2, (rand() % 1000) / 1000.0f * scale * 2, (rand() % 1000) / 1000.0f * scale * 2);

    glRotatef (xAngle, 1, 0, 0);
    glRotatef (yAngle, 0, 1, 0);
    glRotatef (zAngle, 0, 0, 1);
    this->drawCylinder(radius, length);
    glPopMatrix();

}

void ArmGLWidget::drawArm()
{
    if (this->armConfiguration == 'w')
    {
        drawArm(wristAngles);
    }
    else if (this->armConfiguration == 'a')
    {
        drawArm (astroAngles);
    }
    else if (this->armConfiguration == 's')
    {
        drawArm(shovelAngles);
    }
    else
    {
        // Something interesting...
        for (int i = 0; i < 25; i++)
        {
            this->drawRandomTube(50);
        }
    }
}
