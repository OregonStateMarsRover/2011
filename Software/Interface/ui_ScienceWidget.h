/********************************************************************************
** Form generated from reading UI file 'ScienceWidget.ui'
**
** Created: Sun Nov 20 17:15:28 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCIENCEWIDGET_H
#define UI_SCIENCEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScienceWidget
{
public:
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *chooseSiteComboBox;
    QSpacerItem *horizontalSpacer;
    QToolButton *exportPlainTextButton;
    QToolButton *exportPdfButton;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *sensorDataTable;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPlainTextEdit *notesTextEdit;

    void setupUi(QWidget *ScienceWidget)
    {
        if (ScienceWidget->objectName().isEmpty())
            ScienceWidget->setObjectName(QString::fromUtf8("ScienceWidget"));
        ScienceWidget->resize(813, 515);
        verticalLayout_5 = new QVBoxLayout(ScienceWidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        chooseSiteComboBox = new QComboBox(ScienceWidget);
        chooseSiteComboBox->setObjectName(QString::fromUtf8("chooseSiteComboBox"));
        QFont font;
        font.setPointSize(16);
        chooseSiteComboBox->setFont(font);

        horizontalLayout_2->addWidget(chooseSiteComboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        exportPlainTextButton = new QToolButton(ScienceWidget);
        exportPlainTextButton->setObjectName(QString::fromUtf8("exportPlainTextButton"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(exportPlainTextButton->sizePolicy().hasHeightForWidth());
        exportPlainTextButton->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/text-document.png"), QSize(), QIcon::Normal, QIcon::Off);
        exportPlainTextButton->setIcon(icon);
        exportPlainTextButton->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(exportPlainTextButton);

        exportPdfButton = new QToolButton(ScienceWidget);
        exportPdfButton->setObjectName(QString::fromUtf8("exportPdfButton"));
        sizePolicy.setHeightForWidth(exportPdfButton->sizePolicy().hasHeightForWidth());
        exportPdfButton->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/pdf.png"), QSize(), QIcon::Normal, QIcon::Off);
        exportPdfButton->setIcon(icon1);
        exportPdfButton->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(exportPdfButton);


        verticalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox_2 = new QGroupBox(ScienceWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        sensorDataTable = new QTableWidget(groupBox_2);
        if (sensorDataTable->columnCount() < 2)
            sensorDataTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        sensorDataTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        sensorDataTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (sensorDataTable->rowCount() < 4)
            sensorDataTable->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        sensorDataTable->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        sensorDataTable->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        sensorDataTable->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        sensorDataTable->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        sensorDataTable->setItem(0, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        sensorDataTable->setItem(0, 1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        sensorDataTable->setItem(1, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        sensorDataTable->setItem(1, 1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        sensorDataTable->setItem(2, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        sensorDataTable->setItem(2, 1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        sensorDataTable->setItem(3, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        sensorDataTable->setItem(3, 1, __qtablewidgetitem13);
        sensorDataTable->setObjectName(QString::fromUtf8("sensorDataTable"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sensorDataTable->sizePolicy().hasHeightForWidth());
        sensorDataTable->setSizePolicy(sizePolicy2);
        sensorDataTable->setMinimumSize(QSize(256, 0));

        verticalLayout_2->addWidget(sensorDataTable);


        verticalLayout_4->addWidget(groupBox_2);


        horizontalLayout_3->addLayout(verticalLayout_4);

        groupBox = new QGroupBox(ScienceWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        notesTextEdit = new QPlainTextEdit(groupBox);
        notesTextEdit->setObjectName(QString::fromUtf8("notesTextEdit"));

        verticalLayout->addWidget(notesTextEdit);


        horizontalLayout_3->addWidget(groupBox);


        verticalLayout_5->addLayout(horizontalLayout_3);


        retranslateUi(ScienceWidget);

        QMetaObject::connectSlotsByName(ScienceWidget);
    } // setupUi

    void retranslateUi(QWidget *ScienceWidget)
    {
        ScienceWidget->setWindowTitle(QApplication::translate("ScienceWidget", "Form", 0, QApplication::UnicodeUTF8));
        chooseSiteComboBox->clear();
        chooseSiteComboBox->insertItems(0, QStringList()
         << QApplication::translate("ScienceWidget", "Drainage Site", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ScienceWidget", "Shaded Area", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ScienceWidget", "Silt Deposit", 0, QApplication::UnicodeUTF8)
        );
        exportPlainTextButton->setText(QApplication::translate("ScienceWidget", "Export to Plain Text", 0, QApplication::UnicodeUTF8));
        exportPdfButton->setText(QApplication::translate("ScienceWidget", "Export to PDF", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("ScienceWidget", "Sensors", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = sensorDataTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ScienceWidget", "Sensor", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = sensorDataTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ScienceWidget", "Value", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = sensorDataTable->isSortingEnabled();
        sensorDataTable->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem2 = sensorDataTable->item(0, 0);
        ___qtablewidgetitem2->setText(QApplication::translate("ScienceWidget", "Temperature", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = sensorDataTable->item(0, 1);
        ___qtablewidgetitem3->setText(QApplication::translate("ScienceWidget", "30C", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = sensorDataTable->item(1, 0);
        ___qtablewidgetitem4->setText(QApplication::translate("ScienceWidget", "Conductivity", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = sensorDataTable->item(1, 1);
        ___qtablewidgetitem5->setText(QApplication::translate("ScienceWidget", "6e-8 S/m", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = sensorDataTable->item(2, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("ScienceWidget", "pH", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = sensorDataTable->item(2, 1);
        ___qtablewidgetitem7->setText(QApplication::translate("ScienceWidget", "6.6", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = sensorDataTable->item(3, 0);
        ___qtablewidgetitem8->setText(QApplication::translate("ScienceWidget", "Elevation", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = sensorDataTable->item(3, 1);
        ___qtablewidgetitem9->setText(QApplication::translate("ScienceWidget", "1219m", 0, QApplication::UnicodeUTF8));
        sensorDataTable->setSortingEnabled(__sortingEnabled);

        groupBox->setTitle(QApplication::translate("ScienceWidget", "Notes", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ScienceWidget", "Site Name:", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("ScienceWidget", "Drainage Site", 0, QApplication::UnicodeUTF8));
        notesTextEdit->setPlainText(QString());
    } // retranslateUi

};

namespace Ui {
    class ScienceWidget: public Ui_ScienceWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCIENCEWIDGET_H
