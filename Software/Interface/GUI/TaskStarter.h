#ifndef TASKSTARTER_H
#define TASKSTARTER_H

#include <QWidget>
#include <QLabel>

namespace Ui {
    class TaskStarter;
}

class TaskStarter : public QWidget
{
    Q_OBJECT

public:
    explicit TaskStarter(QWidget *parent = 0);
    ~TaskStarter();
    QLabel *labelX;
    QLabel *labelY;

private:
    Ui::TaskStarter *ui;

public slots:
    void setNewPos(int x, int y);
};

#endif // TASKSTARTER_H
