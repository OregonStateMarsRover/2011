#include "rovercontrols.h"
#include "ui_rovercontrols.h"

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
