#include "ArmControls.h"
#include "ui_ArmControls.h"

ArmControls::ArmControls(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ArmControls)
{
    ui->setupUi(this);
}

ArmControls::~ArmControls()
{
    delete ui;
}
