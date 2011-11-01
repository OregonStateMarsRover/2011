/********************************************************************************
** Form generated from reading UI file 'CameraWidget.ui'
**
** Created: Sun Oct 9 13:50:35 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERAWIDGET_H
#define UI_CAMERAWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraWidget
{
public:
    QGridLayout *gridLayout_3;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *longRangeButton;
    QToolButton *armButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QSlider *zoomSlider;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QToolButton *tiltUpButton;
    QToolButton *panLeftButton;
    QToolButton *tiltDownButton;
    QToolButton *panRightButton;
    QVBoxLayout *verticalLayout;
    QSlider *tiltSlider;
    QLabel *tiltLabel;
    QHBoxLayout *horizontalLayout;
    QSlider *panSlider;
    QLabel *panLabel;
    QVBoxLayout *verticalLayout_2;
    QToolButton *zoomInButton;
    QToolButton *zoomOutButton;
    QVBoxLayout *verticalLayout_3;
    QToolButton *presetButton1;
    QToolButton *presetButton2;
    QToolButton *presetButton3;
    QToolButton *presetButton4;
    QToolButton *presetButton5;
    QCheckBox *doublePanTiltRate;
    QPushButton *centerPanTiltButton;
    QPushButton *resetServoButton;
    QComboBox *cameraCommandDropdown;
    QSlider *manualExposureSlider;
    QLabel *label;
    QSlider *exposureCompenstaion;
    QLabel *label_2;
    QCheckBox *ExposureComp;
    QPushButton *sendCameraCommand;

    void setupUi(QWidget *CameraWidget)
    {
        if (CameraWidget->objectName().isEmpty())
            CameraWidget->setObjectName(QString::fromUtf8("CameraWidget"));
        CameraWidget->resize(832, 592);
        gridLayout_3 = new QGridLayout(CameraWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        frame = new QFrame(CameraWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        longRangeButton = new QToolButton(frame);
        longRangeButton->setObjectName(QString::fromUtf8("longRangeButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(longRangeButton->sizePolicy().hasHeightForWidth());
        longRangeButton->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(16);
        longRangeButton->setFont(font);
        longRangeButton->setCheckable(true);
        longRangeButton->setChecked(true);
        longRangeButton->setAutoExclusive(true);

        horizontalLayout_2->addWidget(longRangeButton);

        armButton = new QToolButton(frame);
        armButton->setObjectName(QString::fromUtf8("armButton"));
        sizePolicy.setHeightForWidth(armButton->sizePolicy().hasHeightForWidth());
        armButton->setSizePolicy(sizePolicy);
        armButton->setFont(font);
        armButton->setCheckable(true);
        armButton->setAutoExclusive(true);

        horizontalLayout_2->addWidget(armButton);


        gridLayout_3->addWidget(frame, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(99, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(99, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 85, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 2, 1, 1, 1);

        zoomSlider = new QSlider(CameraWidget);
        zoomSlider->setObjectName(QString::fromUtf8("zoomSlider"));
        zoomSlider->setMaximum(3990);
        zoomSlider->setOrientation(Qt::Vertical);

        gridLayout_3->addWidget(zoomSlider, 1, 3, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        tiltUpButton = new QToolButton(CameraWidget);
        tiltUpButton->setObjectName(QString::fromUtf8("tiltUpButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/arrow-up.png"), QSize(), QIcon::Normal, QIcon::Off);
        tiltUpButton->setIcon(icon);
        tiltUpButton->setIconSize(QSize(128, 128));

        gridLayout->addWidget(tiltUpButton, 0, 1, 1, 1);

        panLeftButton = new QToolButton(CameraWidget);
        panLeftButton->setObjectName(QString::fromUtf8("panLeftButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/arrow-left.png"), QSize(), QIcon::Normal, QIcon::Off);
        panLeftButton->setIcon(icon1);
        panLeftButton->setIconSize(QSize(128, 128));

        gridLayout->addWidget(panLeftButton, 1, 0, 1, 1);

        tiltDownButton = new QToolButton(CameraWidget);
        tiltDownButton->setObjectName(QString::fromUtf8("tiltDownButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/arrow-down.png"), QSize(), QIcon::Normal, QIcon::Off);
        tiltDownButton->setIcon(icon2);
        tiltDownButton->setIconSize(QSize(128, 128));

        gridLayout->addWidget(tiltDownButton, 1, 1, 1, 1);

        panRightButton = new QToolButton(CameraWidget);
        panRightButton->setObjectName(QString::fromUtf8("panRightButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icons/arrow-right.png"), QSize(), QIcon::Normal, QIcon::Off);
        panRightButton->setIcon(icon3);
        panRightButton->setIconSize(QSize(128, 128));

        gridLayout->addWidget(panRightButton, 1, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tiltSlider = new QSlider(CameraWidget);
        tiltSlider->setObjectName(QString::fromUtf8("tiltSlider"));
        tiltSlider->setMinimum(0);
        tiltSlider->setMaximum(1023);
        tiltSlider->setSingleStep(35);
        tiltSlider->setOrientation(Qt::Vertical);
        tiltSlider->setTickPosition(QSlider::TicksBelow);
        tiltSlider->setTickInterval(1500);

        verticalLayout->addWidget(tiltSlider);

        tiltLabel = new QLabel(CameraWidget);
        tiltLabel->setObjectName(QString::fromUtf8("tiltLabel"));

        verticalLayout->addWidget(tiltLabel);


        gridLayout_2->addLayout(verticalLayout, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        panSlider = new QSlider(CameraWidget);
        panSlider->setObjectName(QString::fromUtf8("panSlider"));
        panSlider->setMinimum(0);
        panSlider->setMaximum(1023);
        panSlider->setSingleStep(35);
        panSlider->setOrientation(Qt::Horizontal);
        panSlider->setTickPosition(QSlider::TicksBelow);
        panSlider->setTickInterval(1500);

        horizontalLayout->addWidget(panSlider);

        panLabel = new QLabel(CameraWidget);
        panLabel->setObjectName(QString::fromUtf8("panLabel"));

        horizontalLayout->addWidget(panLabel);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        zoomInButton = new QToolButton(CameraWidget);
        zoomInButton->setObjectName(QString::fromUtf8("zoomInButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Icons/button-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        zoomInButton->setIcon(icon4);
        zoomInButton->setIconSize(QSize(128, 128));

        verticalLayout_2->addWidget(zoomInButton);

        zoomOutButton = new QToolButton(CameraWidget);
        zoomOutButton->setObjectName(QString::fromUtf8("zoomOutButton"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Icons/button-delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        zoomOutButton->setIcon(icon5);
        zoomOutButton->setIconSize(QSize(128, 128));

        verticalLayout_2->addWidget(zoomOutButton);


        gridLayout_2->addLayout(verticalLayout_2, 0, 2, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        presetButton1 = new QToolButton(CameraWidget);
        presetButton1->setObjectName(QString::fromUtf8("presetButton1"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(presetButton1->sizePolicy().hasHeightForWidth());
        presetButton1->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(18);
        presetButton1->setFont(font1);

        verticalLayout_3->addWidget(presetButton1);

        presetButton2 = new QToolButton(CameraWidget);
        presetButton2->setObjectName(QString::fromUtf8("presetButton2"));
        sizePolicy1.setHeightForWidth(presetButton2->sizePolicy().hasHeightForWidth());
        presetButton2->setSizePolicy(sizePolicy1);
        presetButton2->setFont(font1);

        verticalLayout_3->addWidget(presetButton2);

        presetButton3 = new QToolButton(CameraWidget);
        presetButton3->setObjectName(QString::fromUtf8("presetButton3"));
        sizePolicy1.setHeightForWidth(presetButton3->sizePolicy().hasHeightForWidth());
        presetButton3->setSizePolicy(sizePolicy1);
        presetButton3->setFont(font1);

        verticalLayout_3->addWidget(presetButton3);

        presetButton4 = new QToolButton(CameraWidget);
        presetButton4->setObjectName(QString::fromUtf8("presetButton4"));
        sizePolicy1.setHeightForWidth(presetButton4->sizePolicy().hasHeightForWidth());
        presetButton4->setSizePolicy(sizePolicy1);
        presetButton4->setFont(font1);

        verticalLayout_3->addWidget(presetButton4);

        presetButton5 = new QToolButton(CameraWidget);
        presetButton5->setObjectName(QString::fromUtf8("presetButton5"));
        sizePolicy1.setHeightForWidth(presetButton5->sizePolicy().hasHeightForWidth());
        presetButton5->setSizePolicy(sizePolicy1);
        presetButton5->setFont(font1);

        verticalLayout_3->addWidget(presetButton5);


        gridLayout_2->addLayout(verticalLayout_3, 0, 3, 1, 1);

        doublePanTiltRate = new QCheckBox(CameraWidget);
        doublePanTiltRate->setObjectName(QString::fromUtf8("doublePanTiltRate"));

        gridLayout_2->addWidget(doublePanTiltRate, 2, 0, 1, 1);

        centerPanTiltButton = new QPushButton(CameraWidget);
        centerPanTiltButton->setObjectName(QString::fromUtf8("centerPanTiltButton"));

        gridLayout_2->addWidget(centerPanTiltButton, 3, 0, 1, 1);

        resetServoButton = new QPushButton(CameraWidget);
        resetServoButton->setObjectName(QString::fromUtf8("resetServoButton"));

        gridLayout_2->addWidget(resetServoButton, 4, 0, 1, 1);

        cameraCommandDropdown = new QComboBox(CameraWidget);
        cameraCommandDropdown->setObjectName(QString::fromUtf8("cameraCommandDropdown"));

        gridLayout_2->addWidget(cameraCommandDropdown, 5, 0, 1, 1);

        manualExposureSlider = new QSlider(CameraWidget);
        manualExposureSlider->setObjectName(QString::fromUtf8("manualExposureSlider"));
        manualExposureSlider->setMinimum(0);
        manualExposureSlider->setMaximum(256);
        manualExposureSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(manualExposureSlider, 8, 0, 1, 1);

        label = new QLabel(CameraWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 7, 0, 1, 1);

        exposureCompenstaion = new QSlider(CameraWidget);
        exposureCompenstaion->setObjectName(QString::fromUtf8("exposureCompenstaion"));
        exposureCompenstaion->setMinimum(-7);
        exposureCompenstaion->setMaximum(7);
        exposureCompenstaion->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(exposureCompenstaion, 8, 2, 1, 2);

        label_2 = new QLabel(CameraWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 7, 2, 1, 2);

        ExposureComp = new QCheckBox(CameraWidget);
        ExposureComp->setObjectName(QString::fromUtf8("ExposureComp"));

        gridLayout_2->addWidget(ExposureComp, 5, 3, 1, 1);

        sendCameraCommand = new QPushButton(CameraWidget);
        sendCameraCommand->setObjectName(QString::fromUtf8("sendCameraCommand"));

        gridLayout_2->addWidget(sendCameraCommand, 5, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 1, 1, 1);


        retranslateUi(CameraWidget);

        QMetaObject::connectSlotsByName(CameraWidget);
    } // setupUi

    void retranslateUi(QWidget *CameraWidget)
    {
        CameraWidget->setWindowTitle(QApplication::translate("CameraWidget", "Form", 0, QApplication::UnicodeUTF8));
        longRangeButton->setText(QApplication::translate("CameraWidget", "Long Range", 0, QApplication::UnicodeUTF8));
        armButton->setText(QApplication::translate("CameraWidget", "Arm", 0, QApplication::UnicodeUTF8));
        tiltUpButton->setText(QApplication::translate("CameraWidget", "Tilt Up", 0, QApplication::UnicodeUTF8));
        panLeftButton->setText(QApplication::translate("CameraWidget", "Pan Left", 0, QApplication::UnicodeUTF8));
        tiltDownButton->setText(QApplication::translate("CameraWidget", "Tilt Down", 0, QApplication::UnicodeUTF8));
        panRightButton->setText(QApplication::translate("CameraWidget", "Pan Right", 0, QApplication::UnicodeUTF8));
        tiltLabel->setText(QApplication::translate("CameraWidget", "+000.00", 0, QApplication::UnicodeUTF8));
        panLabel->setText(QApplication::translate("CameraWidget", "+000.00", 0, QApplication::UnicodeUTF8));
        zoomInButton->setText(QApplication::translate("CameraWidget", "Zoom In", 0, QApplication::UnicodeUTF8));
        zoomOutButton->setText(QApplication::translate("CameraWidget", "Zoom Out", 0, QApplication::UnicodeUTF8));
        presetButton1->setText(QApplication::translate("CameraWidget", "Preset 1", 0, QApplication::UnicodeUTF8));
        presetButton2->setText(QApplication::translate("CameraWidget", "Preset 2", 0, QApplication::UnicodeUTF8));
        presetButton3->setText(QApplication::translate("CameraWidget", "Preset 3", 0, QApplication::UnicodeUTF8));
        presetButton4->setText(QApplication::translate("CameraWidget", "Preset 4", 0, QApplication::UnicodeUTF8));
        presetButton5->setText(QApplication::translate("CameraWidget", "Preset 5", 0, QApplication::UnicodeUTF8));
        doublePanTiltRate->setText(QApplication::translate("CameraWidget", "Double Pan/Tilt Speed", 0, QApplication::UnicodeUTF8));
        centerPanTiltButton->setText(QApplication::translate("CameraWidget", "Center Pan/Tilt", 0, QApplication::UnicodeUTF8));
        resetServoButton->setText(QApplication::translate("CameraWidget", "Resend Servo Settings", 0, QApplication::UnicodeUTF8));
        cameraCommandDropdown->clear();
        cameraCommandDropdown->insertItems(0, QStringList()
         << QApplication::translate("CameraWidget", "Auto White Balance", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CameraWidget", "Indoor White Balance", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CameraWidget", "Outdoor White Balance", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CameraWidget", "One Push White Balance", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CameraWidget", "Auto Tracing White Balance", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CameraWidget", "Full Auto Exposure", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CameraWidget", "Bright Auto Exposure", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("CameraWidget", "Manual Exposure Brightness", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CameraWidget", "Exposure Compensation", 0, QApplication::UnicodeUTF8));
        ExposureComp->setText(QApplication::translate("CameraWidget", "Exposure Comp.", 0, QApplication::UnicodeUTF8));
        sendCameraCommand->setText(QApplication::translate("CameraWidget", "Send Command", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CameraWidget: public Ui_CameraWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAWIDGET_H
