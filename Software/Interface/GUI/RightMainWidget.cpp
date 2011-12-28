#include "RightMainWidget.h"
#include "ui_RightMainWidget.h"

RightMainWidget::RightMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RightMainWidget)
{
    ui->setupUi(this);
}

RightMainWidget::~RightMainWidget()
{
    delete ui;
}

void RightMainWidget::changeEvent(QEvent *e)
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
