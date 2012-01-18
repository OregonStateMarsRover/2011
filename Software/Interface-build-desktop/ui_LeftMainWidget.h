/********************************************************************************
** Form generated from reading UI file 'LeftMainWidget.ui'
**
** Created: Mon Jan 16 15:14:16 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEFTMAINWIDGET_H
#define UI_LEFTMAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LeftMainWidget
{
public:
    QLabel *label_3;
    QListView *GPS_coords;
    QLabel *label_2;
    QSlider *Max_speed;
    QListView *Motor_status;
    QLabel *label_4;
    QLabel *label;

    void setupUi(QWidget *LeftMainWidget)
    {
        if (LeftMainWidget->objectName().isEmpty())
            LeftMainWidget->setObjectName(QString::fromUtf8("LeftMainWidget"));
        LeftMainWidget->resize(281, 587);
        LeftMainWidget->setMinimumSize(QSize(281, 587));
        label_3 = new QLabel(LeftMainWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 250, 111, 16));
        GPS_coords = new QListView(LeftMainWidget);
        GPS_coords->setObjectName(QString::fromUtf8("GPS_coords"));
        GPS_coords->setGeometry(QRect(10, 270, 201, 291));
        label_2 = new QLabel(LeftMainWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(230, 280, 41, 16));
        Max_speed = new QSlider(LeftMainWidget);
        Max_speed->setObjectName(QString::fromUtf8("Max_speed"));
        Max_speed->setGeometry(QRect(230, 300, 31, 261));
        Max_speed->setOrientation(Qt::Vertical);
        Motor_status = new QListView(LeftMainWidget);
        Motor_status->setObjectName(QString::fromUtf8("Motor_status"));
        Motor_status->setGeometry(QRect(10, 30, 261, 201));
        Motor_status->setStyleSheet(QString::fromUtf8("background-color: rgb(195, 255, 194);\n"
"alternate-background-color: rgb(252, 156, 158);"));
        label_4 = new QLabel(LeftMainWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 10, 121, 16));
        label = new QLabel(LeftMainWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 260, 31, 21));

        retranslateUi(LeftMainWidget);

        QMetaObject::connectSlotsByName(LeftMainWidget);
    } // setupUi

    void retranslateUi(QWidget *LeftMainWidget)
    {
        LeftMainWidget->setWindowTitle(QApplication::translate("LeftMainWidget", "Form", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("LeftMainWidget", "Location", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LeftMainWidget", "speed", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("LeftMainWidget", "Motor Status", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LeftMainWidget", "max", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LeftMainWidget: public Ui_LeftMainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEFTMAINWIDGET_H
