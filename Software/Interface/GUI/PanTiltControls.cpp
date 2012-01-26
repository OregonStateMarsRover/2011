#include "PanTiltControls.h"
#include "ui_PanTiltControls.h"

PanTiltControls::PanTiltControls(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PanTiltControls)
{
    ui->setupUi(this);
}

PanTiltControls::~PanTiltControls()
{
    delete ui;
}
