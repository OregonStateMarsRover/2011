#include "RoverControls.h"
#include "ui_RoverControls.h"

RoverControls::RoverControls(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RoverControls)
{
    ui->setupUi(this);
}

RoverControls::~RoverControls()
{
    delete ui;
}
