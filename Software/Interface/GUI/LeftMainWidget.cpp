#include "LeftMainWidget.h"
#include "ui_LeftMainWidget.h"

LeftMainWidget::LeftMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LeftMainWidget)
{
    ui->setupUi(this);
}

LeftMainWidget::~LeftMainWidget()
{
    delete ui;
}

void LeftMainWidget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
