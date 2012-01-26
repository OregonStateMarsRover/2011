/********************************************************************************
** Form generated from reading UI file 'RightMainWidget.ui'
**
** Created: Tue Jan 24 21:43:25 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RIGHTMAINWIDGET_H
#define UI_RIGHTMAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QScrollArea>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RightMainWidget
{
public:
    QLabel *label_5;
    QDial *compass_placeholder;
    QLabel *label_6;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *RightMainWidget)
    {
        if (RightMainWidget->objectName().isEmpty())
            RightMainWidget->setObjectName(QString::fromUtf8("RightMainWidget"));
        RightMainWidget->resize(291, 441);
        RightMainWidget->setMinimumSize(QSize(291, 441));
        label_5 = new QLabel(RightMainWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 270, 181, 16));
        compass_placeholder = new QDial(RightMainWidget);
        compass_placeholder->setObjectName(QString::fromUtf8("compass_placeholder"));
        compass_placeholder->setGeometry(QRect(0, 10, 271, 251));
        label_6 = new QLabel(RightMainWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 10, 241, 16));
        scrollArea = new QScrollArea(RightMainWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 290, 271, 141));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 269, 139));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(RightMainWidget);

        QMetaObject::connectSlotsByName(RightMainWidget);
    } // setupUi

    void retranslateUi(QWidget *RightMainWidget)
    {
        RightMainWidget->setWindowTitle(QApplication::translate("RightMainWidget", "Form", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("RightMainWidget", "Notifications", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("RightMainWidget", "Compass", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RightMainWidget: public Ui_RightMainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RIGHTMAINWIDGET_H
