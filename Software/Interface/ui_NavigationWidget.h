/********************************************************************************
** Form generated from reading UI file 'NavigationWidget.ui'
**
** Created: Sun Nov 20 17:15:28 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVIGATIONWIDGET_H
#define UI_NAVIGATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "GUI/NavigationView.h"
#include "GUI/TriangulationSidebar.h"

QT_BEGIN_NAMESPACE

class Ui_NavigationWidget
{
public:
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    NavigationView *navView;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *latitudeLabel;
    QLabel *label_4;
    QLabel *longitudeLabel;
    QLabel *label;
    QLabel *headingLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *requestGPSButton;
    QPushButton *markIsectButton;
    QPushButton *connectLineButton;
    QPushButton *triangulationButton;
    QPushButton *addPointButton;
    TriangulationSidebar *triangulationSidebar;

    void setupUi(QWidget *NavigationWidget)
    {
        if (NavigationWidget->objectName().isEmpty())
            NavigationWidget->setObjectName(QString::fromUtf8("NavigationWidget"));
        NavigationWidget->resize(1046, 407);
        horizontalLayout_3 = new QHBoxLayout(NavigationWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        navView = new NavigationView(NavigationWidget);
        navView->setObjectName(QString::fromUtf8("navView"));

        verticalLayout->addWidget(navView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(NavigationWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setFamily(QString::fromUtf8("Monospace"));
        font.setPointSize(12);
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        latitudeLabel = new QLabel(NavigationWidget);
        latitudeLabel->setObjectName(QString::fromUtf8("latitudeLabel"));
        latitudeLabel->setFont(font);

        horizontalLayout->addWidget(latitudeLabel);

        label_4 = new QLabel(NavigationWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout->addWidget(label_4);

        longitudeLabel = new QLabel(NavigationWidget);
        longitudeLabel->setObjectName(QString::fromUtf8("longitudeLabel"));
        longitudeLabel->setFont(font);

        horizontalLayout->addWidget(longitudeLabel);

        label = new QLabel(NavigationWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        headingLabel = new QLabel(NavigationWidget);
        headingLabel->setObjectName(QString::fromUtf8("headingLabel"));

        horizontalLayout->addWidget(headingLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        requestGPSButton = new QPushButton(NavigationWidget);
        requestGPSButton->setObjectName(QString::fromUtf8("requestGPSButton"));

        horizontalLayout->addWidget(requestGPSButton);

        markIsectButton = new QPushButton(NavigationWidget);
        markIsectButton->setObjectName(QString::fromUtf8("markIsectButton"));

        horizontalLayout->addWidget(markIsectButton);

        connectLineButton = new QPushButton(NavigationWidget);
        connectLineButton->setObjectName(QString::fromUtf8("connectLineButton"));

        horizontalLayout->addWidget(connectLineButton);

        triangulationButton = new QPushButton(NavigationWidget);
        triangulationButton->setObjectName(QString::fromUtf8("triangulationButton"));

        horizontalLayout->addWidget(triangulationButton);

        addPointButton = new QPushButton(NavigationWidget);
        addPointButton->setObjectName(QString::fromUtf8("addPointButton"));

        horizontalLayout->addWidget(addPointButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        triangulationSidebar = new TriangulationSidebar(NavigationWidget);
        triangulationSidebar->setObjectName(QString::fromUtf8("triangulationSidebar"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(triangulationSidebar->sizePolicy().hasHeightForWidth());
        triangulationSidebar->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(triangulationSidebar);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(NavigationWidget);

        QMetaObject::connectSlotsByName(NavigationWidget);
    } // setupUi

    void retranslateUi(QWidget *NavigationWidget)
    {
        NavigationWidget->setWindowTitle(QApplication::translate("NavigationWidget", "Form", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NavigationWidget", "Latitude", 0, QApplication::UnicodeUTF8));
        latitudeLabel->setText(QApplication::translate("NavigationWidget", "---", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NavigationWidget", "    Longitude", 0, QApplication::UnicodeUTF8));
        longitudeLabel->setText(QApplication::translate("NavigationWidget", "---", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NavigationWidget", "Heading", 0, QApplication::UnicodeUTF8));
        headingLabel->setText(QApplication::translate("NavigationWidget", "-----", 0, QApplication::UnicodeUTF8));
        requestGPSButton->setText(QApplication::translate("NavigationWidget", "Request GPS", 0, QApplication::UnicodeUTF8));
        markIsectButton->setText(QApplication::translate("NavigationWidget", "Mark Intersection", 0, QApplication::UnicodeUTF8));
        connectLineButton->setText(QApplication::translate("NavigationWidget", "Connect Lines", 0, QApplication::UnicodeUTF8));
        triangulationButton->setText(QApplication::translate("NavigationWidget", "Triangulation", 0, QApplication::UnicodeUTF8));
        addPointButton->setText(QApplication::translate("NavigationWidget", "Add Point", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NavigationWidget: public Ui_NavigationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVIGATIONWIDGET_H
