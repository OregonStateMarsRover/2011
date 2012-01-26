/********************************************************************************
** Form generated from reading UI file 'PanTiltControls.ui'
**
** Created: Wed Jan 25 18:21:06 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANTILTCONTROLS_H
#define UI_PANTILTCONTROLS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PanTiltControls
{
public:
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QLabel *label;
    QSlider *horizontalSlider;
    QPushButton *pushButton_2;
    QCheckBox *checkBox;

    void setupUi(QWidget *PanTiltControls)
    {
        if (PanTiltControls->objectName().isEmpty())
            PanTiltControls->setObjectName(QString::fromUtf8("PanTiltControls"));
        PanTiltControls->resize(423, 171);
        pushButton_5 = new QPushButton(PanTiltControls);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(80, 110, 61, 51));
        pushButton_6 = new QPushButton(PanTiltControls);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(20, 60, 61, 51));
        pushButton_7 = new QPushButton(PanTiltControls);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(80, 10, 61, 51));
        pushButton_8 = new QPushButton(PanTiltControls);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(140, 60, 61, 51));
        pushButton = new QPushButton(PanTiltControls);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(251, 20, 121, 27));
        comboBox = new QComboBox(PanTiltControls);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(211, 80, 201, 31));
        label = new QLabel(PanTiltControls);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(211, 120, 201, 17));
        horizontalSlider = new QSlider(PanTiltControls);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(220, 140, 181, 20));
        horizontalSlider->setOrientation(Qt::Horizontal);
        pushButton_2 = new QPushButton(PanTiltControls);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 50, 161, 27));
        checkBox = new QCheckBox(PanTiltControls);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(160, 20, 71, 31));

        retranslateUi(PanTiltControls);

        QMetaObject::connectSlotsByName(PanTiltControls);
    } // setupUi

    void retranslateUi(QWidget *PanTiltControls)
    {
        PanTiltControls->setWindowTitle(QApplication::translate("PanTiltControls", "Form", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("PanTiltControls", "Back", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("PanTiltControls", "Left", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("PanTiltControls", "Forward", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("PanTiltControls", "Right", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("PanTiltControls", "Center Pan/Tilt", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("PanTiltControls", "Auto White Balance", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PanTiltControls", "Indoor White Balance", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PanTiltControls", "Outdoor White Balance", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PanTiltControls", "One Push White Balance", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PanTiltControls", "Auto Tracing White Balance", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PanTiltControls", "Full Auto Exposure", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PanTiltControls", "Bright Auto Exposure", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("PanTiltControls", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Manual Exposure Brightness</p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("PanTiltControls", "Resend Servo Settings", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("PanTiltControls", "Double\n"
"Speed", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PanTiltControls: public Ui_PanTiltControls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANTILTCONTROLS_H
