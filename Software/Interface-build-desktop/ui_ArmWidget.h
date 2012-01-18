/********************************************************************************
** Form generated from reading UI file 'ArmWidget.ui'
**
** Created: Thu Jan 12 09:42:20 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARMWIDGET_H
#define UI_ARMWIDGET_H

#include <GUI/ArmGLWidget.h>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArmWidget
{
public:
    QPushButton *upButton;
    QPushButton *downButton;
    QPushButton *leftButton;
    QPushButton *rightButton;
    QPushButton *inButton;
    QPushButton *outButton;
    QSlider *heightSlider;
    QSlider *widthSliuder;
    QSlider *depthSlider;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *shoulderAngleBox;
    QLineEdit *elbowAngleBox;
    QLineEdit *baseRotationBox;
    QLineEdit *rotationServoBox;
    QLineEdit *elevationServoBox;
    QPushButton *tipUpButton;
    QPushButton *tipDown;
    QPushButton *tipLeft;
    QPushButton *tipRight;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QDoubleSpinBox *widthBox;
    QDoubleSpinBox *heightBox;
    QDoubleSpinBox *depthBox;
    ArmGLWidget *armGLWidget;
    QPushButton *getArmConfigButton;
    QPlainTextEdit *passThroughReply;
    QComboBox *cmdEdit;
    QPushButton *sendCmdButton;
    QPushButton *clearButton;
    QPushButton *zoomInButton;
    QPushButton *zoomOutButton;
    QPushButton *zoomStopButton;
    QSpinBox *gripperBox;
    QSpinBox *cameraRotateBox;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QSpinBox *cameraTiltBox;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *globalErrLabel;
    QLabel *slaveErrLabel;
    QPushButton *Run;
    QPlainTextEdit *logBox;
    QPushButton *resetServo;
    QSpinBox *servoIdBox;
    QPlainTextEdit *statusBox1;
    QPlainTextEdit *statusBox2;

    void setupUi(QWidget *ArmWidget)
    {
        if (ArmWidget->objectName().isEmpty())
            ArmWidget->setObjectName(QString::fromUtf8("ArmWidget"));
        ArmWidget->resize(1123, 861);
        upButton = new QPushButton(ArmWidget);
        upButton->setObjectName(QString::fromUtf8("upButton"));
        upButton->setGeometry(QRect(80, 10, 41, 31));
        downButton = new QPushButton(ArmWidget);
        downButton->setObjectName(QString::fromUtf8("downButton"));
        downButton->setGeometry(QRect(80, 70, 41, 31));
        leftButton = new QPushButton(ArmWidget);
        leftButton->setObjectName(QString::fromUtf8("leftButton"));
        leftButton->setGeometry(QRect(40, 40, 41, 31));
        rightButton = new QPushButton(ArmWidget);
        rightButton->setObjectName(QString::fromUtf8("rightButton"));
        rightButton->setGeometry(QRect(120, 40, 41, 31));
        inButton = new QPushButton(ArmWidget);
        inButton->setObjectName(QString::fromUtf8("inButton"));
        inButton->setGeometry(QRect(360, 30, 91, 91));
        outButton = new QPushButton(ArmWidget);
        outButton->setObjectName(QString::fromUtf8("outButton"));
        outButton->setGeometry(QRect(360, 210, 91, 91));
        heightSlider = new QSlider(ArmWidget);
        heightSlider->setObjectName(QString::fromUtf8("heightSlider"));
        heightSlider->setGeometry(QRect(10, 19, 20, 281));
        heightSlider->setOrientation(Qt::Vertical);
        widthSliuder = new QSlider(ArmWidget);
        widthSliuder->setObjectName(QString::fromUtf8("widthSliuder"));
        widthSliuder->setGeometry(QRect(10, 330, 311, 19));
        widthSliuder->setOrientation(Qt::Horizontal);
        depthSlider = new QSlider(ArmWidget);
        depthSlider->setObjectName(QString::fromUtf8("depthSlider"));
        depthSlider->setGeometry(QRect(490, 20, 20, 281));
        depthSlider->setOrientation(Qt::Vertical);
        label = new QLabel(ArmWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 360, 111, 17));
        label_2 = new QLabel(ArmWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 390, 111, 17));
        label_3 = new QLabel(ArmWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 420, 111, 17));
        label_4 = new QLabel(ArmWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 450, 111, 17));
        label_5 = new QLabel(ArmWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 480, 111, 17));
        shoulderAngleBox = new QLineEdit(ArmWidget);
        shoulderAngleBox->setObjectName(QString::fromUtf8("shoulderAngleBox"));
        shoulderAngleBox->setGeometry(QRect(140, 350, 113, 25));
        elbowAngleBox = new QLineEdit(ArmWidget);
        elbowAngleBox->setObjectName(QString::fromUtf8("elbowAngleBox"));
        elbowAngleBox->setGeometry(QRect(140, 380, 113, 25));
        baseRotationBox = new QLineEdit(ArmWidget);
        baseRotationBox->setObjectName(QString::fromUtf8("baseRotationBox"));
        baseRotationBox->setGeometry(QRect(140, 410, 113, 25));
        rotationServoBox = new QLineEdit(ArmWidget);
        rotationServoBox->setObjectName(QString::fromUtf8("rotationServoBox"));
        rotationServoBox->setGeometry(QRect(140, 440, 113, 25));
        elevationServoBox = new QLineEdit(ArmWidget);
        elevationServoBox->setObjectName(QString::fromUtf8("elevationServoBox"));
        elevationServoBox->setGeometry(QRect(140, 470, 113, 25));
        tipUpButton = new QPushButton(ArmWidget);
        tipUpButton->setObjectName(QString::fromUtf8("tipUpButton"));
        tipUpButton->setGeometry(QRect(100, 610, 91, 27));
        tipDown = new QPushButton(ArmWidget);
        tipDown->setObjectName(QString::fromUtf8("tipDown"));
        tipDown->setGeometry(QRect(100, 670, 91, 27));
        tipLeft = new QPushButton(ArmWidget);
        tipLeft->setObjectName(QString::fromUtf8("tipLeft"));
        tipLeft->setGeometry(QRect(10, 640, 91, 27));
        tipRight = new QPushButton(ArmWidget);
        tipRight->setObjectName(QString::fromUtf8("tipRight"));
        tipRight->setGeometry(QRect(190, 640, 91, 27));
        label_6 = new QLabel(ArmWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(90, 510, 51, 17));
        label_7 = new QLabel(ArmWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(90, 570, 51, 17));
        label_8 = new QLabel(ArmWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(90, 540, 51, 17));
        widthBox = new QDoubleSpinBox(ArmWidget);
        widthBox->setObjectName(QString::fromUtf8("widthBox"));
        widthBox->setGeometry(QRect(140, 500, 111, 25));
        heightBox = new QDoubleSpinBox(ArmWidget);
        heightBox->setObjectName(QString::fromUtf8("heightBox"));
        heightBox->setGeometry(QRect(140, 530, 111, 25));
        depthBox = new QDoubleSpinBox(ArmWidget);
        depthBox->setObjectName(QString::fromUtf8("depthBox"));
        depthBox->setGeometry(QRect(140, 560, 111, 25));
        armGLWidget = new ArmGLWidget(ArmWidget);
        armGLWidget->setObjectName(QString::fromUtf8("armGLWidget"));
        armGLWidget->setGeometry(QRect(530, 20, 700, 700));
        getArmConfigButton = new QPushButton(ArmWidget);
        getArmConfigButton->setObjectName(QString::fromUtf8("getArmConfigButton"));
        getArmConfigButton->setEnabled(true);
        getArmConfigButton->setGeometry(QRect(330, 360, 91, 27));
        passThroughReply = new QPlainTextEdit(ArmWidget);
        passThroughReply->setObjectName(QString::fromUtf8("passThroughReply"));
        passThroughReply->setGeometry(QRect(10, 710, 351, 86));
        cmdEdit = new QComboBox(ArmWidget);
        cmdEdit->setObjectName(QString::fromUtf8("cmdEdit"));
        cmdEdit->setGeometry(QRect(10, 800, 191, 29));
        cmdEdit->setEditable(true);
        sendCmdButton = new QPushButton(ArmWidget);
        sendCmdButton->setObjectName(QString::fromUtf8("sendCmdButton"));
        sendCmdButton->setGeometry(QRect(210, 800, 71, 27));
        clearButton = new QPushButton(ArmWidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setGeometry(QRect(290, 800, 71, 27));
        zoomInButton = new QPushButton(ArmWidget);
        zoomInButton->setObjectName(QString::fromUtf8("zoomInButton"));
        zoomInButton->setGeometry(QRect(330, 400, 91, 27));
        zoomOutButton = new QPushButton(ArmWidget);
        zoomOutButton->setObjectName(QString::fromUtf8("zoomOutButton"));
        zoomOutButton->setGeometry(QRect(330, 440, 91, 27));
        zoomStopButton = new QPushButton(ArmWidget);
        zoomStopButton->setObjectName(QString::fromUtf8("zoomStopButton"));
        zoomStopButton->setGeometry(QRect(330, 480, 91, 27));
        gripperBox = new QSpinBox(ArmWidget);
        gripperBox->setObjectName(QString::fromUtf8("gripperBox"));
        gripperBox->setGeometry(QRect(420, 520, 91, 25));
        gripperBox->setMinimum(300);
        gripperBox->setMaximum(900);
        gripperBox->setSingleStep(20);
        cameraRotateBox = new QSpinBox(ArmWidget);
        cameraRotateBox->setObjectName(QString::fromUtf8("cameraRotateBox"));
        cameraRotateBox->setGeometry(QRect(420, 550, 91, 25));
        cameraRotateBox->setMaximum(1023);
        cameraRotateBox->setSingleStep(10);
        label_9 = new QLabel(ArmWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(330, 520, 62, 17));
        label_10 = new QLabel(ArmWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(330, 550, 71, 17));
        label_11 = new QLabel(ArmWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(330, 580, 71, 17));
        cameraTiltBox = new QSpinBox(ArmWidget);
        cameraTiltBox->setObjectName(QString::fromUtf8("cameraTiltBox"));
        cameraTiltBox->setGeometry(QRect(420, 580, 91, 25));
        cameraTiltBox->setMaximum(1023);
        cameraTiltBox->setSingleStep(10);
        label_12 = new QLabel(ArmWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(330, 620, 81, 17));
        label_13 = new QLabel(ArmWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(330, 640, 62, 17));
        globalErrLabel = new QLabel(ArmWidget);
        globalErrLabel->setObjectName(QString::fromUtf8("globalErrLabel"));
        globalErrLabel->setGeometry(QRect(420, 620, 62, 17));
        slaveErrLabel = new QLabel(ArmWidget);
        slaveErrLabel->setObjectName(QString::fromUtf8("slaveErrLabel"));
        slaveErrLabel->setGeometry(QRect(420, 640, 62, 17));
        Run = new QPushButton(ArmWidget);
        Run->setObjectName(QString::fromUtf8("Run"));
        Run->setGeometry(QRect(440, 360, 71, 27));
        logBox = new QPlainTextEdit(ArmWidget);
        logBox->setObjectName(QString::fromUtf8("logBox"));
        logBox->setGeometry(QRect(40, 120, 301, 201));
        QFont font;
        font.setPointSize(6);
        logBox->setFont(font);
        resetServo = new QPushButton(ArmWidget);
        resetServo->setObjectName(QString::fromUtf8("resetServo"));
        resetServo->setGeometry(QRect(370, 800, 121, 27));
        servoIdBox = new QSpinBox(ArmWidget);
        servoIdBox->setObjectName(QString::fromUtf8("servoIdBox"));
        servoIdBox->setGeometry(QRect(500, 800, 51, 25));
        servoIdBox->setMinimum(1);
        servoIdBox->setMaximum(15);
        servoIdBox->setSingleStep(20);
        servoIdBox->setValue(7);
        statusBox1 = new QPlainTextEdit(ArmWidget);
        statusBox1->setObjectName(QString::fromUtf8("statusBox1"));
        statusBox1->setGeometry(QRect(560, 730, 551, 51));
        statusBox1->setFont(font);
        statusBox1->setTabStopWidth(50);
        statusBox2 = new QPlainTextEdit(ArmWidget);
        statusBox2->setObjectName(QString::fromUtf8("statusBox2"));
        statusBox2->setGeometry(QRect(560, 800, 551, 51));
        statusBox2->setFont(font);
        statusBox2->setTabStopWidth(50);

        retranslateUi(ArmWidget);

        QMetaObject::connectSlotsByName(ArmWidget);
    } // setupUi

    void retranslateUi(QWidget *ArmWidget)
    {
        ArmWidget->setWindowTitle(QApplication::translate("ArmWidget", "Form", 0, QApplication::UnicodeUTF8));
        upButton->setText(QApplication::translate("ArmWidget", "Up", 0, QApplication::UnicodeUTF8));
        downButton->setText(QApplication::translate("ArmWidget", "Down", 0, QApplication::UnicodeUTF8));
        leftButton->setText(QApplication::translate("ArmWidget", "Left", 0, QApplication::UnicodeUTF8));
        rightButton->setText(QApplication::translate("ArmWidget", "Right", 0, QApplication::UnicodeUTF8));
        inButton->setText(QApplication::translate("ArmWidget", "In", 0, QApplication::UnicodeUTF8));
        outButton->setText(QApplication::translate("ArmWidget", "Out", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ArmWidget", "Shoulder Angle", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ArmWidget", "Elbow Angle", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ArmWidget", "Base Rotation", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ArmWidget", "Rotation Servo", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ArmWidget", "Elevation Servo", 0, QApplication::UnicodeUTF8));
        rotationServoBox->setText(QString());
        elevationServoBox->setText(QString());
        tipUpButton->setText(QApplication::translate("ArmWidget", "Tip Up", 0, QApplication::UnicodeUTF8));
        tipDown->setText(QApplication::translate("ArmWidget", "Tip Down", 0, QApplication::UnicodeUTF8));
        tipLeft->setText(QApplication::translate("ArmWidget", "Tip Left", 0, QApplication::UnicodeUTF8));
        tipRight->setText(QApplication::translate("ArmWidget", "Tip Right", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ArmWidget", "Width", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ArmWidget", "Depth", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ArmWidget", "Height", 0, QApplication::UnicodeUTF8));
        getArmConfigButton->setText(QApplication::translate("ArmWidget", "Get Config", 0, QApplication::UnicodeUTF8));
        cmdEdit->clear();
        cmdEdit->insertItems(0, QStringList()
         << QApplication::translate("ArmWidget", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ArmWidget", "40 21 FA 07 03 19 00", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ArmWidget", "40 21 FA 07 03 19 01", 0, QApplication::UnicodeUTF8)
         << QString()
        );
        sendCmdButton->setText(QApplication::translate("ArmWidget", "Send Cmd", 0, QApplication::UnicodeUTF8));
        clearButton->setText(QApplication::translate("ArmWidget", "Clear", 0, QApplication::UnicodeUTF8));
        zoomInButton->setText(QApplication::translate("ArmWidget", "Zoom In", 0, QApplication::UnicodeUTF8));
        zoomOutButton->setText(QApplication::translate("ArmWidget", "Zoom Out", 0, QApplication::UnicodeUTF8));
        zoomStopButton->setText(QApplication::translate("ArmWidget", "Stop", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("ArmWidget", "Gripper:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("ArmWidget", "Cam Rot:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("ArmWidget", "Cam Tilt:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("ArmWidget", "Global Err:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("ArmWidget", "Slave Err:", 0, QApplication::UnicodeUTF8));
        globalErrLabel->setText(QApplication::translate("ArmWidget", "0", 0, QApplication::UnicodeUTF8));
        slaveErrLabel->setText(QApplication::translate("ArmWidget", "0", 0, QApplication::UnicodeUTF8));
        Run->setText(QApplication::translate("ArmWidget", "Run", 0, QApplication::UnicodeUTF8));
        resetServo->setText(QApplication::translate("ArmWidget", "Reset Servo ID:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ArmWidget: public Ui_ArmWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARMWIDGET_H
