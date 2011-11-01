#ifndef NAVIGATIONPLACEDIALOG_H
#define NAVIGATIONPLACEDIALOG_H

#include <QDialog>

namespace Ui {
    class NavigationPlaceDialog;
}

class NavigationPlaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NavigationPlaceDialog(QWidget *parent = 0);
    ~NavigationPlaceDialog();
    QPointF getPoint();

private:
    Ui::NavigationPlaceDialog *ui;
    QPointF navPoint;

private slots:
    void dialogAccepted();
};

#endif // NAVIGATIONPLACEDIALOG_H
