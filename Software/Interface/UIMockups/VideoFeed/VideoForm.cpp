#include "VideoForm.h"
#include "ui_VideoForm.h"

#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QResizeEvent>
#include <BackendCapabilities>
#include <QUrl>

using namespace Phonon;

VideoForm::VideoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoForm),
    //feed1("VideoResources/utah1.png"),
    feed2("VideoResources/utah2.png")
{
    ui->setupUi(this);

    //ui->feed1->play(MediaSource("/home/taj/Movies/RoverCapture/Utah_Test 105.avi"));
    QUrl url;
    url.setScheme("rtp");
    url.setHost("239.192.0.20");
    url.setPort(37004);
    ui->feed1->play(url);
    qDebug("video URL: %s",qPrintable(url.toString()));

    QStringList supported = BackendCapabilities::availableMimeTypes();
    qDebug("supported: %s",qPrintable(supported.join("\n")));

    ui->feed1->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->feed2->setAttribute(Qt::WA_TransparentForMouseEvents);

    populateImages();
    statusWidget = new RoverStatusWidget(this);
}

VideoForm::~VideoForm()
{
    delete ui;
}

void VideoForm::populateImages() {
    /*QGraphicsScene * feed1Scn = new QGraphicsScene(ui->feed1);
    feed1Scn->setBackgroundBrush(Qt::black);
    ui->feed1->setScene(feed1Scn);
    feed1Item = feed1Scn->addPixmap(feed1);*/

    QGraphicsScene * feed2Scn = new QGraphicsScene(ui->feed2);
    feed2Scn->setBackgroundBrush(Qt::black);
    ui->feed2->setScene(feed2Scn);
    feed2Item = feed2Scn->addPixmap(feed2);

    resizeStreams();
}

void VideoForm::resizeEvent(QResizeEvent * event) {
    QRect newSize(statusWidget->geometry());
    newSize.setHeight(event->size().height());
    statusWidget->setGeometry(newSize);

    resizeStreams();
}

void VideoForm::mouseReleaseEvent(QMouseEvent * event) {
    if (ui->feed1->isVisible() && ui->feed2->isVisible()) { // switch to feed1
        ui->feed2->setVisible(false);

        ui->feed1->setVisible(false); // toggle feed1 visibility to force available size to update (for some reason updateGeometry() doesn't resize correctly)
        ui->feed1->setVisible(true);
    }
    else if (ui->feed1->isVisible() && !(ui->feed2->isVisible())) { // switch to feed2
        ui->feed1->setVisible(false);
        ui->feed2->setVisible(true);
    }
    else {
        ui->feed1->setVisible(true);
        ui->feed2->setVisible(true);
    }
    resizeStreams();
}

void VideoForm::resizeStreams() {
    if (ui->feed1->isVisible()) {
    //    feed1Item->setPixmap(feed1.scaledToWidth(ui->feed1->width()-10));
    //    feed1Item->setPos(0, (ui->feed1->height()/2) - feed1Item->boundingRect().height()/2); // re-center
    }

    if (ui->feed2->isVisible()) {
        feed2Item->setPixmap(feed2.scaledToWidth(ui->feed2->width()-10));
        feed2Item->setPos(0, (ui->feed2->height()/2) - feed2Item->boundingRect().height()/2);
    }
}
