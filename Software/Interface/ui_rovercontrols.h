/********************************************************************************
** Form generated from reading UI file 'rovercontrols.ui'
**
** Created: Wed Jan 25 17:01:57 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROVERCONTROLS_H
#define UI_ROVERCONTROLS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoverControls
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QDial *dial;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *RoverControls)
    {
        if (RoverControls->objectName().isEmpty())
            RoverControls->setObjectName(QString::fromUtf8("RoverControls"));
        RoverControls->resize(271, 172);
        pushButton = new QPushButton(RoverControls);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 10, 61, 51));
        label = new QLabel(RoverControls);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 10, 61, 17));
        spinBox = new QSpinBox(RoverControls);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(200, 30, 61, 27));
        pushButton_2 = new QPushButton(RoverControls);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 110, 61, 51));
        pushButton_3 = new QPushButton(RoverControls);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 60, 61, 51));
        pushButton_4 = new QPushButton(RoverControls);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(130, 60, 61, 51));
        dial = new QDial(RoverControls);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(200, 100, 61, 51));
        label_3 = new QLabel(RoverControls);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 60, 61, 41));
        label_4 = new QLabel(RoverControls);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(200, 150, 61, 17));

        retranslateUi(RoverControls);

        QMetaObject::connectSlotsByName(RoverControls);
    } // setupUi

    void retranslateUi(QWidget *RoverControls)
    {
        RoverControls->setWindowTitle(QApplication::translate("RoverControls", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("RoverControls", "Forward", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RoverControls", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Speed (%)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("RoverControls", "Back", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("RoverControls", "Left", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("RoverControls", "Right", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("RoverControls", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Angle of</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Forward</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Motion</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("RoverControls", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">0</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RoverControls: public Ui_RoverControls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROVERCONTROLS_H
