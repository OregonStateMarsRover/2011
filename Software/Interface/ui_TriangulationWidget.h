/********************************************************************************
** Form generated from reading UI file 'TriangulationWidget.ui'
**
** Created: Sun Nov 20 17:15:28 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIANGULATIONWIDGET_H
#define UI_TRIANGULATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TriangulationWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *setToRoverButtonA;
    QPushButton *setToRoverButtonB;
    QLabel *label_7;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *resultOutput;
    QPushButton *saveToLogButton;
    QPushButton *clearLogButton;
    QFrame *line;
    QTextEdit *logTextEdit;

    void setupUi(QWidget *TriangulationWidget)
    {
        if (TriangulationWidget->objectName().isEmpty())
            TriangulationWidget->setObjectName(QString::fromUtf8("TriangulationWidget"));
        TriangulationWidget->resize(630, 392);
        verticalLayout = new QVBoxLayout(TriangulationWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(TriangulationWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(TriangulationWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(TriangulationWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        setToRoverButtonA = new QPushButton(TriangulationWidget);
        setToRoverButtonA->setObjectName(QString::fromUtf8("setToRoverButtonA"));
        setToRoverButtonA->setEnabled(true);

        gridLayout->addWidget(setToRoverButtonA, 4, 1, 1, 1);

        setToRoverButtonB = new QPushButton(TriangulationWidget);
        setToRoverButtonB->setObjectName(QString::fromUtf8("setToRoverButtonB"));
        setToRoverButtonB->setEnabled(true);

        gridLayout->addWidget(setToRoverButtonB, 4, 2, 1, 1);

        label_7 = new QLabel(TriangulationWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 1, 1, 1);

        label_8 = new QLabel(TriangulationWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(TriangulationWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        resultOutput = new QLineEdit(TriangulationWidget);
        resultOutput->setObjectName(QString::fromUtf8("resultOutput"));
        resultOutput->setReadOnly(true);

        horizontalLayout->addWidget(resultOutput);

        saveToLogButton = new QPushButton(TriangulationWidget);
        saveToLogButton->setObjectName(QString::fromUtf8("saveToLogButton"));
        saveToLogButton->setEnabled(false);

        horizontalLayout->addWidget(saveToLogButton);

        clearLogButton = new QPushButton(TriangulationWidget);
        clearLogButton->setObjectName(QString::fromUtf8("clearLogButton"));

        horizontalLayout->addWidget(clearLogButton);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(TriangulationWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        logTextEdit = new QTextEdit(TriangulationWidget);
        logTextEdit->setObjectName(QString::fromUtf8("logTextEdit"));
        QFont font;
        font.setFamily(QString::fromUtf8("Monospace"));
        logTextEdit->setFont(font);
        logTextEdit->setReadOnly(true);

        verticalLayout->addWidget(logTextEdit);


        retranslateUi(TriangulationWidget);

        QMetaObject::connectSlotsByName(TriangulationWidget);
    } // setupUi

    void retranslateUi(QWidget *TriangulationWidget)
    {
        TriangulationWidget->setWindowTitle(QApplication::translate("TriangulationWidget", "Triangulation", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TriangulationWidget", "Latitude", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TriangulationWidget", "Longitude", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TriangulationWidget", "Heading", 0, QApplication::UnicodeUTF8));
        setToRoverButtonA->setText(QApplication::translate("TriangulationWidget", "Set to Rover", 0, QApplication::UnicodeUTF8));
        setToRoverButtonB->setText(QApplication::translate("TriangulationWidget", "Set to Rover", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("TriangulationWidget", "Point A", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("TriangulationWidget", "Point B", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("TriangulationWidget", "Intersection", 0, QApplication::UnicodeUTF8));
        resultOutput->setText(QString());
        saveToLogButton->setText(QApplication::translate("TriangulationWidget", "Save to Log", 0, QApplication::UnicodeUTF8));
        clearLogButton->setText(QApplication::translate("TriangulationWidget", "Clear Log", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TriangulationWidget: public Ui_TriangulationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIANGULATIONWIDGET_H
