#include "NavigationPlaceDialog.h"
#include "ui_NavigationPlaceDialog.h"

NavigationPlaceDialog::NavigationPlaceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NavigationPlaceDialog)
{
    ui->setupUi(this);

    connect(this, SIGNAL(accepted()), this, SLOT(dialogAccepted()));
}

NavigationPlaceDialog::~NavigationPlaceDialog()
{
    delete ui;
}

QPointF NavigationPlaceDialog::getPoint() {
    return navPoint;
}

void NavigationPlaceDialog::dialogAccepted() {
    navPoint.setY(ui->latitudeEdit->text().toDouble());
    navPoint.setX(ui->longitudeEdit->text().toDouble());
}
