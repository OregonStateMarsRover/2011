#include "VideoViewWidget.h"
#include "ui_VideoViewWidget.h"

VideoViewWidget::VideoViewWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoViewWidget)
{
    ui->setupUi(this);
}

VideoViewWidget::~VideoViewWidget()
{
    delete ui;
}

void VideoViewWidget::changeEvent(QEvent *e)
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
