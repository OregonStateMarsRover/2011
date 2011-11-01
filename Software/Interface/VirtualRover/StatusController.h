#ifndef STATUSCONTROLLER_H
#define STATUSCONTROLLER_H

#include <QTimer>

#include "AbstractController.h"

class StatusController : public AbstractController
{
    Q_OBJECT
public:
    StatusController(QObject * parent = 0);

    virtual void handleMessage(WirelessPacket msg);

    virtual int guiMessageTarget();
    virtual int roverMessageTarget();

signals:
    void gotMessage(QByteArray msg);
    void gotDataErrorCount(QByteArray errorCount);

public slots:
    void sendTestMessage(QString str);
    void sendTestMessage(QByteArray str);
    void requestDataErrorCount();


private:
    QTimer * gpsReqTimer;
};

#endif // STATUSCONTROLLER_H
