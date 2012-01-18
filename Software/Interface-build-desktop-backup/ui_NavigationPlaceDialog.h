/********************************************************************************
** Form generated from reading UI file 'NavigationPlaceDialog.ui'
**
** Created: Sun Oct 9 13:50:35 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVIGATIONPLACEDIALOG_H
#define UI_NAVIGATIONPLACEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_NavigationPlaceDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *latitudeEdit;
    QLineEdit *longitudeEdit;

    void setupUi(QDialog *NavigationPlaceDialog)
    {
        if (NavigationPlaceDialog->objectName().isEmpty())
            NavigationPlaceDialog->setObjectName(QString::fromUtf8("NavigationPlaceDialog"));
        NavigationPlaceDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(NavigationPlaceDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(NavigationPlaceDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 62, 17));
        label_2 = new QLabel(NavigationPlaceDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 40, 71, 17));
        latitudeEdit = new QLineEdit(NavigationPlaceDialog);
        latitudeEdit->setObjectName(QString::fromUtf8("latitudeEdit"));
        latitudeEdit->setGeometry(QRect(90, 10, 181, 25));
        longitudeEdit = new QLineEdit(NavigationPlaceDialog);
        longitudeEdit->setObjectName(QString::fromUtf8("longitudeEdit"));
        longitudeEdit->setGeometry(QRect(90, 40, 181, 25));

        retranslateUi(NavigationPlaceDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NavigationPlaceDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NavigationPlaceDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NavigationPlaceDialog);
    } // setupUi

    void retranslateUi(QDialog *NavigationPlaceDialog)
    {
        NavigationPlaceDialog->setWindowTitle(QApplication::translate("NavigationPlaceDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NavigationPlaceDialog", "Latitude:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NavigationPlaceDialog", "Longitude:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NavigationPlaceDialog: public Ui_NavigationPlaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVIGATIONPLACEDIALOG_H
