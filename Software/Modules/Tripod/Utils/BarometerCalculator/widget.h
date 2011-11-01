#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <math.h>
#include <QDebug>

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    long getTemperature(long tempData);
    long getPressure(long pressureData);
    long getAltitude(long pressure);

    short AC1, AC2, AC3, B1, B2, MB, MC, MD;
    unsigned short AC4, AC5, AC6, OSS;
    long pressure, temp, B5, P0;

private slots:
    void on_pushButton_clicked();

};

#endif // WIDGET_H
