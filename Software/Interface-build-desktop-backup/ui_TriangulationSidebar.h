/********************************************************************************
** Form generated from reading UI file 'TriangulationSidebar.ui'
**
** Created: Sun Oct 9 13:50:35 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIANGULATIONSIDEBAR_H
#define UI_TRIANGULATIONSIDEBAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TriangulationSidebar
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QListWidget *pointsListWidget;
    QListWidget *linesListWidget;
    QListWidget *landmarksListWidget;
    QPushButton *drawLinesButton;
    QPushButton *intersectLinesButton;
    QPushButton *deletePoints;
    QPushButton *deleteLines;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *elevationEdit;
    QLineEdit *cameraAngleEdit;
    QLabel *label_6;
    QLineEdit *latitudeEdit;
    QLineEdit *longitudeEdit;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton;
    QLabel *label_9;
    QLabel *label_10;
    QFrame *line;
    QLineEdit *pointDistanceEdit;
    QLineEdit *landmarkElevation;

    void setupUi(QWidget *TriangulationSidebar)
    {
        if (TriangulationSidebar->objectName().isEmpty())
            TriangulationSidebar->setObjectName(QString::fromUtf8("TriangulationSidebar"));
        TriangulationSidebar->resize(400, 703);
        TriangulationSidebar->setMinimumSize(QSize(400, 462));
        label = new QLabel(TriangulationSidebar);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 62, 17));
        label_2 = new QLabel(TriangulationSidebar);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 170, 62, 17));
        label_3 = new QLabel(TriangulationSidebar);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 330, 81, 17));
        pointsListWidget = new QListWidget(TriangulationSidebar);
        pointsListWidget->setObjectName(QString::fromUtf8("pointsListWidget"));
        pointsListWidget->setGeometry(QRect(10, 30, 381, 91));
        pointsListWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        linesListWidget = new QListWidget(TriangulationSidebar);
        linesListWidget->setObjectName(QString::fromUtf8("linesListWidget"));
        linesListWidget->setGeometry(QRect(10, 190, 381, 91));
        linesListWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        landmarksListWidget = new QListWidget(TriangulationSidebar);
        landmarksListWidget->setObjectName(QString::fromUtf8("landmarksListWidget"));
        landmarksListWidget->setGeometry(QRect(10, 360, 381, 91));
        landmarksListWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        drawLinesButton = new QPushButton(TriangulationSidebar);
        drawLinesButton->setObjectName(QString::fromUtf8("drawLinesButton"));
        drawLinesButton->setGeometry(QRect(10, 130, 91, 27));
        intersectLinesButton = new QPushButton(TriangulationSidebar);
        intersectLinesButton->setObjectName(QString::fromUtf8("intersectLinesButton"));
        intersectLinesButton->setGeometry(QRect(10, 290, 121, 27));
        deletePoints = new QPushButton(TriangulationSidebar);
        deletePoints->setObjectName(QString::fromUtf8("deletePoints"));
        deletePoints->setGeometry(QRect(110, 130, 161, 27));
        deleteLines = new QPushButton(TriangulationSidebar);
        deleteLines->setObjectName(QString::fromUtf8("deleteLines"));
        deleteLines->setGeometry(QRect(140, 290, 161, 27));
        label_4 = new QLabel(TriangulationSidebar);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 470, 71, 20));
        label_5 = new QLabel(TriangulationSidebar);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 500, 101, 17));
        elevationEdit = new QLineEdit(TriangulationSidebar);
        elevationEdit->setObjectName(QString::fromUtf8("elevationEdit"));
        elevationEdit->setGeometry(QRect(110, 470, 141, 25));
        cameraAngleEdit = new QLineEdit(TriangulationSidebar);
        cameraAngleEdit->setObjectName(QString::fromUtf8("cameraAngleEdit"));
        cameraAngleEdit->setGeometry(QRect(110, 500, 141, 25));
        label_6 = new QLabel(TriangulationSidebar);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 540, 101, 17));
        latitudeEdit = new QLineEdit(TriangulationSidebar);
        latitudeEdit->setObjectName(QString::fromUtf8("latitudeEdit"));
        latitudeEdit->setGeometry(QRect(110, 530, 113, 25));
        longitudeEdit = new QLineEdit(TriangulationSidebar);
        longitudeEdit->setObjectName(QString::fromUtf8("longitudeEdit"));
        longitudeEdit->setGeometry(QRect(230, 530, 113, 25));
        label_7 = new QLabel(TriangulationSidebar);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(110, 560, 62, 17));
        label_8 = new QLabel(TriangulationSidebar);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(230, 560, 71, 17));
        pushButton = new QPushButton(TriangulationSidebar);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 560, 91, 27));
        label_9 = new QLabel(TriangulationSidebar);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 620, 101, 17));
        label_10 = new QLabel(TriangulationSidebar);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 650, 101, 17));
        line = new QFrame(TriangulationSidebar);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 590, 391, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        pointDistanceEdit = new QLineEdit(TriangulationSidebar);
        pointDistanceEdit->setObjectName(QString::fromUtf8("pointDistanceEdit"));
        pointDistanceEdit->setGeometry(QRect(120, 610, 151, 25));
        landmarkElevation = new QLineEdit(TriangulationSidebar);
        landmarkElevation->setObjectName(QString::fromUtf8("landmarkElevation"));
        landmarkElevation->setGeometry(QRect(120, 640, 151, 25));

        retranslateUi(TriangulationSidebar);

        QMetaObject::connectSlotsByName(TriangulationSidebar);
    } // setupUi

    void retranslateUi(QWidget *TriangulationSidebar)
    {
        TriangulationSidebar->setWindowTitle(QApplication::translate("TriangulationSidebar", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TriangulationSidebar", "Points:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TriangulationSidebar", "Lines:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TriangulationSidebar", "Landmarks:", 0, QApplication::UnicodeUTF8));
        drawLinesButton->setText(QApplication::translate("TriangulationSidebar", "Draw Lines", 0, QApplication::UnicodeUTF8));
        intersectLinesButton->setText(QApplication::translate("TriangulationSidebar", "Intersect Lines", 0, QApplication::UnicodeUTF8));
        deletePoints->setText(QApplication::translate("TriangulationSidebar", "Delete Selected Points", 0, QApplication::UnicodeUTF8));
        deleteLines->setText(QApplication::translate("TriangulationSidebar", "Delete Selected Lines", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("TriangulationSidebar", "Elevation:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("TriangulationSidebar", "Camera Angle:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("TriangulationSidebar", "Measure From:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("TriangulationSidebar", "Latitude", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("TriangulationSidebar", "Longitude", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("TriangulationSidebar", "From Rover", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("TriangulationSidebar", "Point Distance:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("TriangulationSidebar", "Point Elevation:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TriangulationSidebar: public Ui_TriangulationSidebar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIANGULATIONSIDEBAR_H
