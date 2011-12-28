#ifndef LEFTMAINWIDGET_H
#define LEFTMAINWIDGET_H

#include <QWidget>

namespace Ui {
    class LeftMainWidget;
}

class LeftMainWidget : public QWidget {
    Q_OBJECT
public:
    LeftMainWidget(QWidget *parent = 0);
    ~LeftMainWidget();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::LeftMainWidget *ui;
};

#endif // LEFTMAINWIDGET_H
