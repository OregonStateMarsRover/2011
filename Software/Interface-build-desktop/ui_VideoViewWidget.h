/********************************************************************************
** Form generated from reading UI file 'VideoViewWidget.ui'
**
** Created: Thu Jan 12 09:42:20 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOVIEWWIDGET_H
#define UI_VIDEOVIEWWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoViewWidget
{
public:
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QWidget *Driving_viewport;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QWidget *VideoViewWidget)
    {
        if (VideoViewWidget->objectName().isEmpty())
            VideoViewWidget->setObjectName(QString::fromUtf8("VideoViewWidget"));
        VideoViewWidget->resize(936, 692);
        pushButton_2 = new QPushButton(VideoViewWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 10, 121, 27));
        pushButton = new QPushButton(VideoViewWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 91, 27));
        pushButton_3 = new QPushButton(VideoViewWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(220, 10, 91, 27));
        Driving_viewport = new QWidget(VideoViewWidget);
        Driving_viewport->setObjectName(QString::fromUtf8("Driving_viewport"));
        Driving_viewport->setGeometry(QRect(10, 40, 911, 641));
        pushButton_4 = new QPushButton(VideoViewWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(310, 10, 101, 27));
        pushButton_5 = new QPushButton(VideoViewWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(410, 10, 131, 27));

        retranslateUi(VideoViewWidget);

        QMetaObject::connectSlotsByName(VideoViewWidget);
    } // setupUi

    void retranslateUi(QWidget *VideoViewWidget)
    {
        VideoViewWidget->setWindowTitle(QApplication::translate("VideoViewWidget", "Form", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("VideoViewWidget", "rear view mirror", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("VideoViewWidget", "Windshield", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("VideoViewWidget", "Hubble", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("VideoViewWidget", "Satellite View", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("VideoViewWidget", "over the shoulder", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VideoViewWidget: public Ui_VideoViewWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOVIEWWIDGET_H
