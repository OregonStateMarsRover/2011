/********************************************************************************
** Form generated from reading UI file 'DriveWidget.ui'
**
** Created: Sun Oct 9 13:50:34 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRIVEWIDGET_H
#define UI_DRIVEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DriveWidget
{
public:
    QPushButton *sendTestMsg;
    QLabel *testLabel;
    QPushButton *sendNumbersButton;
    QLabel *numbersStatusLabel;
    QSpinBox *delayBox;
    QPushButton *stopButton;
    QSpinBox *countBox;
    QTableWidget *motorStatusTable;
    QCheckBox *actuatedBox;
    QCheckBox *watchdogBox;
    QPushButton *startTimingButton;
    QLabel *lagLabel;
    QSpinBox *timingDelayBox;
    QSpinBox *timingCountBox;
    QPlainTextEdit *passThroughReply;
    QCheckBox *enableWatchdogBox;
    QPushButton *sendCmdButton;
    QSpinBox *idBox;
    QComboBox *cmdEdit;
    QLabel *label;
    QComboBox *joystickProfileBox;
    QLabel *label_2;
    QComboBox *joystickDevName;
    QPushButton *rescanJsButton;
    QPushButton *reopenJsButton;
    QPushButton *disableMosfetsButton;
    QCheckBox *pwmModeBox;
    QLabel *label_3;
    QLabel *label_4;
    QDoubleSpinBox *speedScaleBox;
    QDoubleSpinBox *dirScaleBox;
    QCheckBox *useCurveBox;
    QLabel *label_5;
    QDoubleSpinBox *directionDivisorBox;
    QLabel *label_6;
    QDoubleSpinBox *stallCurrentBox;
    QLabel *label_7;
    QLabel *label_8;
    QComboBox *armStickDevName;
    QComboBox *armStickTypeBox;
    QPushButton *getCurrentButton;
    QCheckBox *inStrafeModeBox;
    QGroupBox *groupBox;
    QSlider *maxSpeedSlider;
    QDoubleSpinBox *maxSpeedBox;
    QLabel *label_9;
    QTableWidget *dataErrorWidget;

    void setupUi(QWidget *DriveWidget)
    {
        if (DriveWidget->objectName().isEmpty())
            DriveWidget->setObjectName(QString::fromUtf8("DriveWidget"));
        DriveWidget->resize(1214, 692);
        sendTestMsg = new QPushButton(DriveWidget);
        sendTestMsg->setObjectName(QString::fromUtf8("sendTestMsg"));
        sendTestMsg->setGeometry(QRect(10, 20, 171, 27));
        testLabel = new QLabel(DriveWidget);
        testLabel->setObjectName(QString::fromUtf8("testLabel"));
        testLabel->setGeometry(QRect(20, 60, 161, 17));
        sendNumbersButton = new QPushButton(DriveWidget);
        sendNumbersButton->setObjectName(QString::fromUtf8("sendNumbersButton"));
        sendNumbersButton->setGeometry(QRect(10, 110, 161, 27));
        numbersStatusLabel = new QLabel(DriveWidget);
        numbersStatusLabel->setObjectName(QString::fromUtf8("numbersStatusLabel"));
        numbersStatusLabel->setGeometry(QRect(20, 140, 131, 17));
        delayBox = new QSpinBox(DriveWidget);
        delayBox->setObjectName(QString::fromUtf8("delayBox"));
        delayBox->setGeometry(QRect(210, 110, 131, 25));
        delayBox->setMaximum(1000);
        stopButton = new QPushButton(DriveWidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(10, 180, 91, 27));
        countBox = new QSpinBox(DriveWidget);
        countBox->setObjectName(QString::fromUtf8("countBox"));
        countBox->setGeometry(QRect(210, 150, 131, 25));
        countBox->setMaximum(1000000);
        motorStatusTable = new QTableWidget(DriveWidget);
        if (motorStatusTable->columnCount() < 4)
            motorStatusTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        motorStatusTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        motorStatusTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        motorStatusTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        motorStatusTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (motorStatusTable->rowCount() < 10)
            motorStatusTable->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        motorStatusTable->setItem(0, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        motorStatusTable->setItem(1, 0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        motorStatusTable->setItem(2, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        motorStatusTable->setItem(3, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        motorStatusTable->setItem(4, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        motorStatusTable->setItem(5, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        motorStatusTable->setItem(6, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        motorStatusTable->setItem(7, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        motorStatusTable->setItem(8, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        motorStatusTable->setItem(9, 0, __qtablewidgetitem13);
        motorStatusTable->setObjectName(QString::fromUtf8("motorStatusTable"));
        motorStatusTable->setGeometry(QRect(530, 20, 431, 351));
        motorStatusTable->setRowCount(10);
        actuatedBox = new QCheckBox(DriveWidget);
        actuatedBox->setObjectName(QString::fromUtf8("actuatedBox"));
        actuatedBox->setEnabled(false);
        actuatedBox->setGeometry(QRect(530, 370, 92, 22));
        actuatedBox->setCheckable(true);
        watchdogBox = new QCheckBox(DriveWidget);
        watchdogBox->setObjectName(QString::fromUtf8("watchdogBox"));
        watchdogBox->setEnabled(false);
        watchdogBox->setGeometry(QRect(530, 390, 161, 22));
        watchdogBox->setCheckable(true);
        startTimingButton = new QPushButton(DriveWidget);
        startTimingButton->setObjectName(QString::fromUtf8("startTimingButton"));
        startTimingButton->setGeometry(QRect(10, 240, 161, 27));
        lagLabel = new QLabel(DriveWidget);
        lagLabel->setObjectName(QString::fromUtf8("lagLabel"));
        lagLabel->setGeometry(QRect(10, 290, 62, 17));
        timingDelayBox = new QSpinBox(DriveWidget);
        timingDelayBox->setObjectName(QString::fromUtf8("timingDelayBox"));
        timingDelayBox->setGeometry(QRect(210, 240, 131, 25));
        timingDelayBox->setMaximum(1000);
        timingCountBox = new QSpinBox(DriveWidget);
        timingCountBox->setObjectName(QString::fromUtf8("timingCountBox"));
        timingCountBox->setGeometry(QRect(210, 280, 131, 25));
        timingCountBox->setMaximum(1000000);
        passThroughReply = new QPlainTextEdit(DriveWidget);
        passThroughReply->setObjectName(QString::fromUtf8("passThroughReply"));
        passThroughReply->setGeometry(QRect(10, 360, 351, 86));
        enableWatchdogBox = new QCheckBox(DriveWidget);
        enableWatchdogBox->setObjectName(QString::fromUtf8("enableWatchdogBox"));
        enableWatchdogBox->setGeometry(QRect(10, 320, 151, 22));
        enableWatchdogBox->setChecked(true);
        sendCmdButton = new QPushButton(DriveWidget);
        sendCmdButton->setObjectName(QString::fromUtf8("sendCmdButton"));
        sendCmdButton->setGeometry(QRect(270, 450, 91, 27));
        idBox = new QSpinBox(DriveWidget);
        idBox->setObjectName(QString::fromUtf8("idBox"));
        idBox->setGeometry(QRect(10, 450, 50, 25));
        cmdEdit = new QComboBox(DriveWidget);
        cmdEdit->setObjectName(QString::fromUtf8("cmdEdit"));
        cmdEdit->setGeometry(QRect(70, 450, 191, 29));
        cmdEdit->setEditable(true);
        label = new QLabel(DriveWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 490, 141, 17));
        joystickProfileBox = new QComboBox(DriveWidget);
        joystickProfileBox->setObjectName(QString::fromUtf8("joystickProfileBox"));
        joystickProfileBox->setGeometry(QRect(160, 480, 241, 29));
        label_2 = new QLabel(DriveWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 520, 141, 17));
        joystickDevName = new QComboBox(DriveWidget);
        joystickDevName->setObjectName(QString::fromUtf8("joystickDevName"));
        joystickDevName->setGeometry(QRect(160, 510, 241, 29));
        joystickDevName->setEditable(true);
        rescanJsButton = new QPushButton(DriveWidget);
        rescanJsButton->setObjectName(QString::fromUtf8("rescanJsButton"));
        rescanJsButton->setGeometry(QRect(160, 610, 91, 27));
        reopenJsButton = new QPushButton(DriveWidget);
        reopenJsButton->setObjectName(QString::fromUtf8("reopenJsButton"));
        reopenJsButton->setGeometry(QRect(260, 610, 91, 27));
        disableMosfetsButton = new QPushButton(DriveWidget);
        disableMosfetsButton->setObjectName(QString::fromUtf8("disableMosfetsButton"));
        disableMosfetsButton->setGeometry(QRect(630, 430, 331, 51));
        pwmModeBox = new QCheckBox(DriveWidget);
        pwmModeBox->setObjectName(QString::fromUtf8("pwmModeBox"));
        pwmModeBox->setGeometry(QRect(630, 490, 101, 22));
        label_3 = new QLabel(DriveWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(670, 550, 131, 17));
        label_4 = new QLabel(DriveWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(650, 580, 151, 17));
        speedScaleBox = new QDoubleSpinBox(DriveWidget);
        speedScaleBox->setObjectName(QString::fromUtf8("speedScaleBox"));
        speedScaleBox->setGeometry(QRect(810, 540, 141, 25));
        speedScaleBox->setValue(1);
        dirScaleBox = new QDoubleSpinBox(DriveWidget);
        dirScaleBox->setObjectName(QString::fromUtf8("dirScaleBox"));
        dirScaleBox->setGeometry(QRect(810, 570, 141, 25));
        dirScaleBox->setValue(1);
        useCurveBox = new QCheckBox(DriveWidget);
        useCurveBox->setObjectName(QString::fromUtf8("useCurveBox"));
        useCurveBox->setGeometry(QRect(630, 640, 181, 22));
        useCurveBox->setChecked(true);
        label_5 = new QLabel(DriveWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(620, 610, 181, 20));
        directionDivisorBox = new QDoubleSpinBox(DriveWidget);
        directionDivisorBox->setObjectName(QString::fromUtf8("directionDivisorBox"));
        directionDivisorBox->setGeometry(QRect(810, 600, 141, 25));
        directionDivisorBox->setValue(1);
        label_6 = new QLabel(DriveWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(710, 510, 91, 17));
        stallCurrentBox = new QDoubleSpinBox(DriveWidget);
        stallCurrentBox->setObjectName(QString::fromUtf8("stallCurrentBox"));
        stallCurrentBox->setGeometry(QRect(810, 500, 141, 25));
        stallCurrentBox->setValue(5);
        label_7 = new QLabel(DriveWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 580, 141, 17));
        label_8 = new QLabel(DriveWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 550, 141, 17));
        armStickDevName = new QComboBox(DriveWidget);
        armStickDevName->setObjectName(QString::fromUtf8("armStickDevName"));
        armStickDevName->setGeometry(QRect(160, 570, 241, 29));
        armStickDevName->setEditable(true);
        armStickTypeBox = new QComboBox(DriveWidget);
        armStickTypeBox->setObjectName(QString::fromUtf8("armStickTypeBox"));
        armStickTypeBox->setGeometry(QRect(160, 540, 241, 29));
        getCurrentButton = new QPushButton(DriveWidget);
        getCurrentButton->setObjectName(QString::fromUtf8("getCurrentButton"));
        getCurrentButton->setGeometry(QRect(870, 380, 91, 27));
        inStrafeModeBox = new QCheckBox(DriveWidget);
        inStrafeModeBox->setObjectName(QString::fromUtf8("inStrafeModeBox"));
        inStrafeModeBox->setGeometry(QRect(630, 660, 141, 22));
        groupBox = new QGroupBox(DriveWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(519, 420, 91, 221));
        maxSpeedSlider = new QSlider(groupBox);
        maxSpeedSlider->setObjectName(QString::fromUtf8("maxSpeedSlider"));
        maxSpeedSlider->setGeometry(QRect(30, 20, 19, 160));
        maxSpeedSlider->setMaximum(100);
        maxSpeedSlider->setValue(100);
        maxSpeedSlider->setOrientation(Qt::Vertical);
        maxSpeedSlider->setTickPosition(QSlider::NoTicks);
        maxSpeedSlider->setTickInterval(10);
        maxSpeedBox = new QDoubleSpinBox(groupBox);
        maxSpeedBox->setObjectName(QString::fromUtf8("maxSpeedBox"));
        maxSpeedBox->setGeometry(QRect(0, 190, 81, 25));
        maxSpeedBox->setMaximum(100);
        maxSpeedBox->setValue(100);
        label_9 = new QLabel(DriveWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(1000, 10, 81, 17));
        dataErrorWidget = new QTableWidget(DriveWidget);
        if (dataErrorWidget->columnCount() < 2)
            dataErrorWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        dataErrorWidget->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        dataErrorWidget->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        if (dataErrorWidget->rowCount() < 7)
            dataErrorWidget->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        dataErrorWidget->setVerticalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        dataErrorWidget->setVerticalHeaderItem(1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        dataErrorWidget->setVerticalHeaderItem(2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        dataErrorWidget->setVerticalHeaderItem(3, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        dataErrorWidget->setVerticalHeaderItem(4, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        dataErrorWidget->setVerticalHeaderItem(5, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        dataErrorWidget->setVerticalHeaderItem(6, __qtablewidgetitem22);
        dataErrorWidget->setObjectName(QString::fromUtf8("dataErrorWidget"));
        dataErrorWidget->setGeometry(QRect(990, 30, 391, 291));

        retranslateUi(DriveWidget);

        QMetaObject::connectSlotsByName(DriveWidget);
    } // setupUi

    void retranslateUi(QWidget *DriveWidget)
    {
        DriveWidget->setWindowTitle(QApplication::translate("DriveWidget", "Form", 0, QApplication::UnicodeUTF8));
        sendTestMsg->setText(QApplication::translate("DriveWidget", "Send Test Message", 0, QApplication::UnicodeUTF8));
        testLabel->setText(QApplication::translate("DriveWidget", "N/A", 0, QApplication::UnicodeUTF8));
        sendNumbersButton->setText(QApplication::translate("DriveWidget", "Send Numbers", 0, QApplication::UnicodeUTF8));
        numbersStatusLabel->setText(QApplication::translate("DriveWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
        stopButton->setText(QApplication::translate("DriveWidget", "Stop", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = motorStatusTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DriveWidget", "Motor", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = motorStatusTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DriveWidget", "Status", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = motorStatusTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("DriveWidget", "Failures", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = motorStatusTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("DriveWidget", "Current", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = motorStatusTable->isSortingEnabled();
        motorStatusTable->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem4 = motorStatusTable->item(0, 0);
        ___qtablewidgetitem4->setText(QApplication::translate("DriveWidget", "Left Front", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = motorStatusTable->item(1, 0);
        ___qtablewidgetitem5->setText(QApplication::translate("DriveWidget", "Left Mid", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = motorStatusTable->item(2, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("DriveWidget", "Left Rear", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = motorStatusTable->item(3, 0);
        ___qtablewidgetitem7->setText(QApplication::translate("DriveWidget", "Right Rear", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = motorStatusTable->item(4, 0);
        ___qtablewidgetitem8->setText(QApplication::translate("DriveWidget", "Right Mid", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = motorStatusTable->item(5, 0);
        ___qtablewidgetitem9->setText(QApplication::translate("DriveWidget", "Right Front", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = motorStatusTable->item(6, 0);
        ___qtablewidgetitem10->setText(QApplication::translate("DriveWidget", "Left Front A", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = motorStatusTable->item(7, 0);
        ___qtablewidgetitem11->setText(QApplication::translate("DriveWidget", "Left Rear A", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = motorStatusTable->item(8, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("DriveWidget", "Right Rear A", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = motorStatusTable->item(9, 0);
        ___qtablewidgetitem13->setText(QApplication::translate("DriveWidget", "Right Front A", 0, QApplication::UnicodeUTF8));
        motorStatusTable->setSortingEnabled(__sortingEnabled);

        actuatedBox->setText(QApplication::translate("DriveWidget", "Actuated", 0, QApplication::UnicodeUTF8));
        watchdogBox->setText(QApplication::translate("DriveWidget", "Watchdog Timeout", 0, QApplication::UnicodeUTF8));
        startTimingButton->setText(QApplication::translate("DriveWidget", "Start Timing", 0, QApplication::UnicodeUTF8));
        lagLabel->setText(QApplication::translate("DriveWidget", "Lag", 0, QApplication::UnicodeUTF8));
        enableWatchdogBox->setText(QApplication::translate("DriveWidget", "Enable Watchdog", 0, QApplication::UnicodeUTF8));
        sendCmdButton->setText(QApplication::translate("DriveWidget", "Send Cmd", 0, QApplication::UnicodeUTF8));
        cmdEdit->clear();
        cmdEdit->insertItems(0, QStringList()
         << QApplication::translate("DriveWidget", "73 00 00", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DriveWidget", "73 01 FF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DriveWidget", "73 05 DC", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DriveWidget", "73 FA 24", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DriveWidget", "76", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DriveWidget", "77", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DriveWidget", "78 13 88", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DriveWidget", "78 1F 40", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DriveWidget", "78 27 10", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("DriveWidget", "Driving Joystick Type:", 0, QApplication::UnicodeUTF8));
        joystickProfileBox->clear();
        joystickProfileBox->insertItems(0, QStringList()
         << QApplication::translate("DriveWidget", "Thrustmaster!", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DriveWidget", "PS2 Controller", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("DriveWidget", "Driving Joystick Dev:", 0, QApplication::UnicodeUTF8));
        rescanJsButton->setText(QApplication::translate("DriveWidget", "Rescan", 0, QApplication::UnicodeUTF8));
        reopenJsButton->setText(QApplication::translate("DriveWidget", "Reopen", 0, QApplication::UnicodeUTF8));
        disableMosfetsButton->setText(QApplication::translate("DriveWidget", "Disable MOSFETS", 0, QApplication::UnicodeUTF8));
        pwmModeBox->setText(QApplication::translate("DriveWidget", "PWM Mode", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DriveWidget", "Speed Scale Factor:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DriveWidget", "Direction Scale Factor:", 0, QApplication::UnicodeUTF8));
        useCurveBox->setText(QApplication::translate("DriveWidget", "Use Exponential Curve", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DriveWidget", "Primary Direction Divisor:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DriveWidget", "Stall Current:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("DriveWidget", "Arm Joystick Dev:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("DriveWidget", "Arm Joystick Type:", 0, QApplication::UnicodeUTF8));
        armStickTypeBox->clear();
        armStickTypeBox->insertItems(0, QStringList()
         << QApplication::translate("DriveWidget", "PS2 Controller", 0, QApplication::UnicodeUTF8)
        );
        getCurrentButton->setText(QApplication::translate("DriveWidget", "Get Current", 0, QApplication::UnicodeUTF8));
        inStrafeModeBox->setText(QApplication::translate("DriveWidget", "In Strafe Mode", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DriveWidget", "Max Speed", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("DriveWidget", "Data Errors:", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = dataErrorWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QApplication::translate("DriveWidget", "Rover", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = dataErrorWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QApplication::translate("DriveWidget", "Base", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = dataErrorWidget->verticalHeaderItem(0);
        ___qtablewidgetitem16->setText(QApplication::translate("DriveWidget", "Start Byte Inside Pkt", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = dataErrorWidget->verticalHeaderItem(1);
        ___qtablewidgetitem17->setText(QApplication::translate("DriveWidget", "Unexpected Start Byte", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem18 = dataErrorWidget->verticalHeaderItem(2);
        ___qtablewidgetitem18->setText(QApplication::translate("DriveWidget", "Unknown Escaped", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem19 = dataErrorWidget->verticalHeaderItem(3);
        ___qtablewidgetitem19->setText(QApplication::translate("DriveWidget", "Too Long", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem20 = dataErrorWidget->verticalHeaderItem(4);
        ___qtablewidgetitem20->setText(QApplication::translate("DriveWidget", "Bad Checksum", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem21 = dataErrorWidget->verticalHeaderItem(5);
        ___qtablewidgetitem21->setText(QApplication::translate("DriveWidget", "Bad Buffer", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem22 = dataErrorWidget->verticalHeaderItem(6);
        ___qtablewidgetitem22->setText(QApplication::translate("DriveWidget", "Rcvd Ignore Byte", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DriveWidget: public Ui_DriveWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRIVEWIDGET_H
