#ifndef VIDEOFORM_H
#define VIDEOFORM_H

#include <QWidget>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <Phonon/MediaObject>

#include "RoverStatusWidget.h"

namespace Ui {
    class VideoForm;
}

class VideoForm : public QWidget
{
    Q_OBJECT

public:
    explicit VideoForm(QWidget *parent = 0);
    ~VideoForm();

private:
    Ui::VideoForm *ui;
    RoverStatusWidget *statusWidget;
    QPixmap feed2;
    QGraphicsPixmapItem * feed1Item;
    QGraphicsPixmapItem * feed2Item;

    Phonon::MediaObject * media;

    void populateImages();
    void resizeEvent(QResizeEvent * event);
    void mouseReleaseEvent(QMouseEvent *);

    void resizeStreams();
};

#endif // VIDEOFORM_H
