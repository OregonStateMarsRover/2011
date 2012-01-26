/********************************************************************************
** Form generated from reading UI file 'StatusWidget.ui'
**
** Created: Tue Jan 24 21:43:25 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATUSWIDGET_H
#define UI_STATUSWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatusWidget
{
public:
    QComboBox *devSelectBox;
    QTextEdit *textEdit;
    QLineEdit *commandBox;
    QPushButton *sendButton;
    QCheckBox *enableGPSBox;
    QCheckBox *enableBaroBox;
    QCheckBox *enableAccelBox;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *rollAngleBox;
    QDoubleSpinBox *pitchAngleBox;
    QLineEdit *refPressureBox;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *roverPressureBox;
    QLabel *label_5;
    QLineEdit *altitudeChangeBox;
    QPushButton *setAltRefButton;
    QLabel *label_6;
    QLineEdit *roverTempBox;
    QCheckBox *checkBox;
    QLabel *label_7;
    QLineEdit *referenceAltitudeBox;
    QLabel *label_8;
    QLineEdit *absoluteAltitudeBox;
    QLabel *label_9;
    QSpinBox *baseOffsetBox;

    void setupUi(QWidget *StatusWidget)
    {
        if (StatusWidget->objectName().isEmpty())
            StatusWidget->setObjectName(QString::fromUtf8("StatusWidget"));
        StatusWidget->resize(893, 518);
        devSelectBox = new QComboBox(StatusWidget);
        devSelectBox->setObjectName(QString::fromUtf8("devSelectBox"));
        devSelectBox->setGeometry(QRect(10, 150, 87, 29));
        textEdit = new QTextEdit(StatusWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 10, 391, 131));
        commandBox = new QLineEdit(StatusWidget);
        commandBox->setObjectName(QString::fromUtf8("commandBox"));
        commandBox->setGeometry(QRect(100, 150, 201, 25));
        sendButton = new QPushButton(StatusWidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(310, 150, 91, 27));
        enableGPSBox = new QCheckBox(StatusWidget);
        enableGPSBox->setObjectName(QString::fromUtf8("enableGPSBox"));
        enableGPSBox->setGeometry(QRect(10, 210, 111, 22));
        enableGPSBox->setChecked(true);
        enableBaroBox = new QCheckBox(StatusWidget);
        enableBaroBox->setObjectName(QString::fromUtf8("enableBaroBox"));
        enableBaroBox->setGeometry(QRect(10, 230, 141, 22));
        enableBaroBox->setChecked(true);
        enableAccelBox = new QCheckBox(StatusWidget);
        enableAccelBox->setObjectName(QString::fromUtf8("enableAccelBox"));
        enableAccelBox->setGeometry(QRect(10, 250, 171, 22));
        enableAccelBox->setChecked(true);
        label = new QLabel(StatusWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(600, 20, 91, 20));
        label_2 = new QLabel(StatusWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(590, 50, 101, 20));
        rollAngleBox = new QDoubleSpinBox(StatusWidget);
        rollAngleBox->setObjectName(QString::fromUtf8("rollAngleBox"));
        rollAngleBox->setGeometry(QRect(700, 20, 91, 25));
        rollAngleBox->setMinimum(-180);
        rollAngleBox->setMaximum(180);
        pitchAngleBox = new QDoubleSpinBox(StatusWidget);
        pitchAngleBox->setObjectName(QString::fromUtf8("pitchAngleBox"));
        pitchAngleBox->setGeometry(QRect(700, 50, 91, 25));
        pitchAngleBox->setMinimum(-180);
        pitchAngleBox->setMaximum(180);
        refPressureBox = new QLineEdit(StatusWidget);
        refPressureBox->setObjectName(QString::fromUtf8("refPressureBox"));
        refPressureBox->setGeometry(QRect(700, 150, 151, 25));
        label_3 = new QLabel(StatusWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(560, 150, 131, 20));
        label_4 = new QLabel(StatusWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(590, 180, 101, 17));
        roverPressureBox = new QLineEdit(StatusWidget);
        roverPressureBox->setObjectName(QString::fromUtf8("roverPressureBox"));
        roverPressureBox->setGeometry(QRect(700, 180, 151, 25));
        label_5 = new QLabel(StatusWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(580, 240, 111, 20));
        altitudeChangeBox = new QLineEdit(StatusWidget);
        altitudeChangeBox->setObjectName(QString::fromUtf8("altitudeChangeBox"));
        altitudeChangeBox->setGeometry(QRect(700, 240, 151, 25));
        setAltRefButton = new QPushButton(StatusWidget);
        setAltRefButton->setObjectName(QString::fromUtf8("setAltRefButton"));
        setAltRefButton->setGeometry(QRect(710, 310, 151, 27));
        label_6 = new QLabel(StatusWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(580, 210, 111, 20));
        roverTempBox = new QLineEdit(StatusWidget);
        roverTempBox->setObjectName(QString::fromUtf8("roverTempBox"));
        roverTempBox->setGeometry(QRect(700, 210, 151, 25));
        checkBox = new QCheckBox(StatusWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(10, 270, 161, 22));
        label_7 = new QLabel(StatusWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(560, 120, 131, 20));
        referenceAltitudeBox = new QLineEdit(StatusWidget);
        referenceAltitudeBox->setObjectName(QString::fromUtf8("referenceAltitudeBox"));
        referenceAltitudeBox->setGeometry(QRect(700, 120, 151, 25));
        label_8 = new QLabel(StatusWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(570, 270, 121, 17));
        absoluteAltitudeBox = new QLineEdit(StatusWidget);
        absoluteAltitudeBox->setObjectName(QString::fromUtf8("absoluteAltitudeBox"));
        absoluteAltitudeBox->setGeometry(QRect(700, 270, 151, 25));
        label_9 = new QLabel(StatusWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(600, 90, 81, 17));
        baseOffsetBox = new QSpinBox(StatusWidget);
        baseOffsetBox->setObjectName(QString::fromUtf8("baseOffsetBox"));
        baseOffsetBox->setGeometry(QRect(700, 90, 151, 25));
        baseOffsetBox->setMinimum(-1000);
        baseOffsetBox->setMaximum(1000);
        baseOffsetBox->setValue(-28);

        retranslateUi(StatusWidget);

        QMetaObject::connectSlotsByName(StatusWidget);
    } // setupUi

    void retranslateUi(QWidget *StatusWidget)
    {
        StatusWidget->setWindowTitle(QApplication::translate("StatusWidget", "Form", 0, QApplication::UnicodeUTF8));
        devSelectBox->clear();
        devSelectBox->insertItems(0, QStringList()
         << QApplication::translate("StatusWidget", "Tripod", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("StatusWidget", "GPS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("StatusWidget", "Motor", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("StatusWidget", "Arm", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("StatusWidget", "Test", 0, QApplication::UnicodeUTF8)
        );
        sendButton->setText(QApplication::translate("StatusWidget", "Send", 0, QApplication::UnicodeUTF8));
        enableGPSBox->setText(QApplication::translate("StatusWidget", "Enable GPS", 0, QApplication::UnicodeUTF8));
        enableBaroBox->setText(QApplication::translate("StatusWidget", "Enable Barometer", 0, QApplication::UnicodeUTF8));
        enableAccelBox->setText(QApplication::translate("StatusWidget", "Enable Accelerometer", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("StatusWidget", "Camera Roll:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("StatusWidget", "Camera Pitch:", 0, QApplication::UnicodeUTF8));
        refPressureBox->setText(QApplication::translate("StatusWidget", "1.0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("StatusWidget", "Reference Pressure:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("StatusWidget", "Rover Pressure:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("StatusWidget", "Altitude Change:", 0, QApplication::UnicodeUTF8));
        setAltRefButton->setText(QApplication::translate("StatusWidget", "Set Reference", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("StatusWidget", "Rover Air Temp:", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("StatusWidget", "Read USB Barometer", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("StatusWidget", "Reference Altitude:", 0, QApplication::UnicodeUTF8));
        referenceAltitudeBox->setText(QApplication::translate("StatusWidget", "0.0", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("StatusWidget", "Absolute Altitude:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("StatusWidget", "Base Offset:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StatusWidget: public Ui_StatusWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATUSWIDGET_H
