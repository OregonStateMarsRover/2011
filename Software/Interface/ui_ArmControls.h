/********************************************************************************
** Form generated from reading UI file 'ArmControls.ui'
**
** Created: Wed Jan 25 18:21:06 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARMCONTROLS_H
#define UI_ARMCONTROLS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArmControls
{
public:
    QSpinBox *spinBox;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QLabel *label_2;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label_3;

    void setupUi(QWidget *ArmControls)
    {
        if (ArmControls->objectName().isEmpty())
            ArmControls->setObjectName(QString::fromUtf8("ArmControls"));
        ArmControls->resize(271, 201);
        spinBox = new QSpinBox(ArmControls);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(200, 30, 61, 27));
        pushButton_4 = new QPushButton(ArmControls);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(130, 60, 61, 51));
        pushButton_3 = new QPushButton(ArmControls);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 60, 61, 51));
        label_2 = new QLabel(ArmControls);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 121, 51));
        label = new QLabel(ArmControls);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 10, 61, 17));
        pushButton_2 = new QPushButton(ArmControls);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 60, 61, 51));
        pushButton = new QPushButton(ArmControls);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 10, 61, 51));
        pushButton_5 = new QPushButton(ArmControls);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(40, 140, 61, 51));
        pushButton_6 = new QPushButton(ArmControls);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(100, 140, 61, 51));
        label_3 = new QLabel(ArmControls);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 120, 121, 16));

        retranslateUi(ArmControls);

        QMetaObject::connectSlotsByName(ArmControls);
    } // setupUi

    void retranslateUi(QWidget *ArmControls)
    {
        ArmControls->setWindowTitle(QApplication::translate("ArmControls", "Form", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("ArmControls", "Down", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("ArmControls", "Back", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ArmControls", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">End</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Effector Controls</p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ArmControls", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Speed (%)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ArmControls", "Forward", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ArmControls", "Up", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("ArmControls", "Open", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("ArmControls", "Close", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ArmControls", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Scoop Control</p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ArmControls: public Ui_ArmControls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARMCONTROLS_H
