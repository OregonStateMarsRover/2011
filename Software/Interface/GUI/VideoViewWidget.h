#ifndef VIDEOVIEWWIDGET_H
#define VIDEOVIEWWIDGET_H

#include <QWidget>

namespace Ui {
    class VideoViewWidget;
}

class VideoViewWidget : public QWidget {
    Q_OBJECT
public:
    VideoViewWidget(QWidget *parent = 0);
    ~VideoViewWidget();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::VideoViewWidget *ui;
};

#endif // VIDEOVIEWWIDGET_H
