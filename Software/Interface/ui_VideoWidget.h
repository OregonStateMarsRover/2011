/********************************************************************************
** Form generated from reading UI file 'VideoWidget.ui'
**
** Created: Sun Nov 20 17:15:28 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOWIDGET_H
#define UI_VIDEOWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>
#include <phonon/videoplayer.h>

QT_BEGIN_NAMESPACE

class Ui_VideoWidget
{
public:
    QGridLayout *gridLayout;
    Phonon::VideoPlayer *videoPlayer;
    Phonon::VideoPlayer *videoPlayer_2;
    Phonon::VideoPlayer *videoPlayer_3;
    Phonon::VideoPlayer *videoPlayer_4;

    void setupUi(QWidget *VideoWidget)
    {
        if (VideoWidget->objectName().isEmpty())
            VideoWidget->setObjectName(QString::fromUtf8("VideoWidget"));
        VideoWidget->resize(665, 433);
        gridLayout = new QGridLayout(VideoWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        videoPlayer = new Phonon::VideoPlayer(VideoWidget);
        videoPlayer->setObjectName(QString::fromUtf8("videoPlayer"));

        gridLayout->addWidget(videoPlayer, 0, 0, 1, 1);

        videoPlayer_2 = new Phonon::VideoPlayer(VideoWidget);
        videoPlayer_2->setObjectName(QString::fromUtf8("videoPlayer_2"));

        gridLayout->addWidget(videoPlayer_2, 0, 1, 1, 1);

        videoPlayer_3 = new Phonon::VideoPlayer(VideoWidget);
        videoPlayer_3->setObjectName(QString::fromUtf8("videoPlayer_3"));

        gridLayout->addWidget(videoPlayer_3, 1, 0, 1, 1);

        videoPlayer_4 = new Phonon::VideoPlayer(VideoWidget);
        videoPlayer_4->setObjectName(QString::fromUtf8("videoPlayer_4"));

        gridLayout->addWidget(videoPlayer_4, 1, 1, 1, 1);


        retranslateUi(VideoWidget);

        QMetaObject::connectSlotsByName(VideoWidget);
    } // setupUi

    void retranslateUi(QWidget *VideoWidget)
    {
        VideoWidget->setWindowTitle(QApplication::translate("VideoWidget", "Video", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VideoWidget: public Ui_VideoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOWIDGET_H
