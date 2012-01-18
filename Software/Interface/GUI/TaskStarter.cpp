#include "TaskStarter.h"
#include "ui_TaskStarter.h"

TaskStarter::TaskStarter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskStarter)
{
    ui->setupUi(this);
    labelX = ui->label_x;
    labelY = ui->label_y;
}

TaskStarter::~TaskStarter()
{
    delete ui;
}

void TaskStarter::setNewPos(int x, int y){
    QString str;
    labelX->setText(str.append(QString("%1").arg(x)));
    str.clear();
    labelY->setText(str.append(QString("%1").arg(y)));
}
