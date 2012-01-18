/********************************************************************************
** Form generated from reading UI file 'TaskStarter.ui'
**
** Created: Tue Jan 17 11:03:39 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKSTARTER_H
#define UI_TASKSTARTER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskStarter
{
public:
    QGroupBox *TaskGroup;
    QPushButton *taskbutton_1;
    QPushButton *taskbutton_2;
    QPushButton *taskbutton_3;
    QPushButton *taskbutton_4;
    QLabel *label_x;
    QLabel *label_y;

    void setupUi(QWidget *TaskStarter)
    {
        if (TaskStarter->objectName().isEmpty())
            TaskStarter->setObjectName(QString::fromUtf8("TaskStarter"));
        TaskStarter->resize(486, 137);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TaskStarter->sizePolicy().hasHeightForWidth());
        TaskStarter->setSizePolicy(sizePolicy);
        TaskStarter->setMinimumSize(QSize(486, 137));
        TaskGroup = new QGroupBox(TaskStarter);
        TaskGroup->setObjectName(QString::fromUtf8("TaskGroup"));
        TaskGroup->setGeometry(QRect(20, 20, 461, 71));
        taskbutton_1 = new QPushButton(TaskGroup);
        taskbutton_1->setObjectName(QString::fromUtf8("taskbutton_1"));
        taskbutton_1->setGeometry(QRect(10, 30, 98, 27));
        taskbutton_2 = new QPushButton(TaskGroup);
        taskbutton_2->setObjectName(QString::fromUtf8("taskbutton_2"));
        taskbutton_2->setGeometry(QRect(120, 30, 98, 27));
        taskbutton_3 = new QPushButton(TaskGroup);
        taskbutton_3->setObjectName(QString::fromUtf8("taskbutton_3"));
        taskbutton_3->setGeometry(QRect(230, 30, 98, 27));
        taskbutton_4 = new QPushButton(TaskGroup);
        taskbutton_4->setObjectName(QString::fromUtf8("taskbutton_4"));
        taskbutton_4->setGeometry(QRect(340, 30, 98, 27));
        label_x = new QLabel(TaskStarter);
        label_x->setObjectName(QString::fromUtf8("label_x"));
        label_x->setGeometry(QRect(40, 100, 67, 17));
        label_y = new QLabel(TaskStarter);
        label_y->setObjectName(QString::fromUtf8("label_y"));
        label_y->setGeometry(QRect(140, 100, 67, 17));

        retranslateUi(TaskStarter);

        QMetaObject::connectSlotsByName(TaskStarter);
    } // setupUi

    void retranslateUi(QWidget *TaskStarter)
    {
        TaskStarter->setWindowTitle(QApplication::translate("TaskStarter", "Form", 0, QApplication::UnicodeUTF8));
        TaskGroup->setTitle(QApplication::translate("TaskStarter", "Tasks", 0, QApplication::UnicodeUTF8));
        taskbutton_1->setText(QApplication::translate("TaskStarter", "Task 1", 0, QApplication::UnicodeUTF8));
        taskbutton_2->setText(QApplication::translate("TaskStarter", "Task 2", 0, QApplication::UnicodeUTF8));
        taskbutton_3->setText(QApplication::translate("TaskStarter", "Task 3", 0, QApplication::UnicodeUTF8));
        taskbutton_4->setText(QApplication::translate("TaskStarter", "Task 4", 0, QApplication::UnicodeUTF8));
        label_x->setText(QApplication::translate("TaskStarter", "X", 0, QApplication::UnicodeUTF8));
        label_y->setText(QApplication::translate("TaskStarter", "Y", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TaskStarter: public Ui_TaskStarter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKSTARTER_H
