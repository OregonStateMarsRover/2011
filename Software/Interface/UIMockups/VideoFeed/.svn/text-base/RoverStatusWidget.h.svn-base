#ifndef ROVERSTATUSWIDGET_H
#define ROVERSTATUSWIDGET_H

#include <QWidget>

namespace Ui {
    class RoverStatusWidget;
}

class RoverStatusWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RoverStatusWidget(QWidget *parent = 0);
    ~RoverStatusWidget();

private:
    Ui::RoverStatusWidget *ui;

    void populateImages();
    void enterEvent(QEvent * event);
    void leaveEvent(QEvent * event);
};

#endif // ROVERSTATUSWIDGET_H
