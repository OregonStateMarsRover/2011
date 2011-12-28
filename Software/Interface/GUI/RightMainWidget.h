#ifndef RIGHTMAINWIDGET_H
#define RIGHTMAINWIDGET_H

#include <QWidget>

namespace Ui {
    class RightMainWidget;
}

class RightMainWidget : public QWidget {
    Q_OBJECT
public:
    RightMainWidget(QWidget *parent = 0);
    ~RightMainWidget();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::RightMainWidget *ui;
};

#endif // RIGHTMAINWIDGET_H
