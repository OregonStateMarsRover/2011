#ifndef DRIVEMODES_H
#define DRIVEMODES_H

#include <QWidget>

namespace Ui {
class DriveModes;
}

class DriveModes : public QWidget
{
    Q_OBJECT
    
public:
    explicit DriveModes(QWidget *parent = 0);
    ~DriveModes();
    
private:
    Ui::DriveModes *ui;
};

#endif // DRIVEMODES_H
