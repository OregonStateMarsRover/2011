#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    AC1 = ui->AC1_SpinBox->text().toShort();
    AC2 = ui->AC2_SpinBox->text().toShort();
    AC3 = ui->AC3_SpinBox->text().toShort();
    AC4 = ui->AC4_SpinBox->text().toUShort();
    AC5 = ui->AC5_SpinBox->text().toUShort();
    AC6 = ui->AC6_SpinBox->text().toUShort();
    B1 = ui->B1_SpinBox->text().toShort();
    B2 = ui->B2_SpinBox->text().toShort();
    MB = ui->MB_SpinBox->text().toShort();
    MC = ui->MC_SpinBox->text().toShort();
    MD = ui->MD_SpinBox->text().toShort();
    OSS = ui->OSS_SpinBox->text().toShort();
    P0 = ui->P0_SpinBox->text().toLong();
    temp = getTemperature(ui->tempData_SpinBox->text().toLong());
    ui->tempOutput->setText(QString().setNum(((double)temp)/10));
    pressure = getPressure(ui->pressureData_SpinBox->text().toLong());
    ui->pressureOutput->setText(QString().setNum(pressure));
    ui->AltitudeOutput->setText(QString().setNum(getAltitude(pressure)));

}

long Widget::getTemperature(long tempData)
{
    int X1 = 0, X2 = 0;
    X1 = (tempData-AC6)*(AC5/pow(2,15));
    X2 = (MC*pow(2,11))/(X1+MD);
    B5 = X1 + X2;
    return (B5+8)/pow(2,4);
}

long Widget::getPressure(long pressureData)
{
    long B6, X1, X2, X3, B3, p;
    unsigned long B4, B7;
    B6 = B5-4000;
    X1 = (B2*(B6*B6/pow(2,12)))/pow(2,11);
    X2 = AC2 * B6/pow(2,11);
    X3 = X1 + X2;
    B3 = (((AC1*4+X3)<<OSS)+2)/4;
    X1 = AC3*B6/pow(2,13);
    X2 = (B1*(B6*B6/pow(2,12)))/pow(2,16);
    X3 = ((X1+X2)+2)/4;
    B4 = AC4*(unsigned long)(X3+32768)/pow(2,15);
    B7 = ((unsigned long)pressureData-B3)*(50000>>OSS);
    if (B7<(unsigned long)0x80000000)
        p = (B7*2)/B4;
    else
        p = (B7/B4)*2;
    X1 = (p/256)*(p/256);
    X1 = (X1*3038)/pow(2,16);
    X2 = (-7357*p)/pow(2,16);
    return p+(X1+X2+3791)/pow(2,4);
}

long Widget::getAltitude(long pressure)
{
    return 44330*(1-pow(((double)pressure/P0),1/(double)(5.255)));
}
