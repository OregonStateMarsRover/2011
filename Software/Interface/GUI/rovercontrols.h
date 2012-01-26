#ifndef ROVERCONTROLS_H
#define ROVERCONTROLS_H

#include <QWidget>

namespace Ui {
class RoverControls;
}

class RoverControls : public QWidget
{
    Q_OBJECT
    
public:
    explicit RoverControls(QWidget *parent = 0);
    ~RoverControls();
    
private:
    Ui::RoverControls *ui;
};

#endif // ROVERCONTROLS_H
