/********************************************************************************
** Form generated from reading UI file 'DriveModes.ui'
**
** Created: Wed Jan 25 18:21:06 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRIVEMODES_H
#define UI_DRIVEMODES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DriveModes
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *DriveModes)
    {
        if (DriveModes->objectName().isEmpty())
            DriveModes->setObjectName(QString::fromUtf8("DriveModes"));
        DriveModes->resize(332, 46);
        pushButton = new QPushButton(DriveModes);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 93, 27));
        pushButton_2 = new QPushButton(DriveModes);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 10, 93, 27));
        pushButton_3 = new QPushButton(DriveModes);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(230, 10, 93, 27));

        retranslateUi(DriveModes);

        QMetaObject::connectSlotsByName(DriveModes);
    } // setupUi

    void retranslateUi(QWidget *DriveModes)
    {
        DriveModes->setWindowTitle(QApplication::translate("DriveModes", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("DriveModes", "Vector", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("DriveModes", "0 Degree", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("DriveModes", "Explicit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DriveModes: public Ui_DriveModes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRIVEMODES_H
