#include "DriveModes.h"
#include "ui_DriveModes.h"

DriveModes::DriveModes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DriveModes)
{
    ui->setupUi(this);
}

DriveModes::~DriveModes()
{
    delete ui;
}
