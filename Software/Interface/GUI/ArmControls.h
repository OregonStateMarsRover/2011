#ifndef ARMCONTROLS_H
#define ARMCONTROLS_H

#include <QWidget>

namespace Ui {
class ArmControls;
}

class ArmControls : public QWidget
{
    Q_OBJECT
    
public:
    explicit ArmControls(QWidget *parent = 0);
    ~ArmControls();
    
private:
    Ui::ArmControls *ui;
};

#endif // ARMCONTROLS_H
