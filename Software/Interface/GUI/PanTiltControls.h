#ifndef PANTILTCONTROLS_H
#define PANTILTCONTROLS_H

#include <QWidget>

namespace Ui {
class PanTiltControls;
}

class PanTiltControls : public QWidget
{
    Q_OBJECT
    
public:
    explicit PanTiltControls(QWidget *parent = 0);
    ~PanTiltControls();
    
private:
    Ui::PanTiltControls *ui;
};

#endif // PANTILTCONTROLS_H
