#include <QDebug>
#include <QMessageBox>
#include "RobotController.h"

RobotController * RobotController::m_instance = 0;

RobotController::RobotController(QObject *parent) :
    QObject(parent)
{
    dispatcher = new WirelessDispatcher(this);
    connect(dispatcher, SIGNAL(receivedPacket(WirelessPacket)), this, SLOT(processWirelessPacket(WirelessPacket)));
    m_gpsController = new GPSController(this);
    m_motorController = new MotorController(this);
    m_statusController = new StatusController(this);
    m_tripodController = new TripodController(this);
    m_armController = new ArmController(this);

    addController(m_gpsController);
    addController(m_motorController);
    addController(m_statusController);
    addController(m_tripodController);
    addController(m_armController);

    QStringList serials = SerialDevice::getSerialPortNames();
    if (serials.count()==0) {
        QMessageBox::critical(0, "No Serial Device", "No USB Serial devices were found on the system. Check that the FTDI is plugged in and called /dev/ttyUSB*.",QMessageBox::Ok, 0);
        qCritical() << "CRITICAL: NO SERIAL DEVICE DETECTED.";
        dispatcher->openSerial("/dev/null");
    }
    else {
        qDebug() << "opening serial device"<<serials.at(0);
        dispatcher->openSerial(serials.at(0));
        qDebug() << "serial device open!";
    }
}

RobotController * RobotController::instance() {
    if (m_instance==0)
        m_instance = new RobotController(0);
    return m_instance;
}

void RobotController::addController(AbstractController * dev) {
    deviceMap[dev->guiMessageTarget()] = dev;
}

void RobotController::processWirelessPacket(WirelessPacket pkt) {
    if (deviceMap.contains(pkt.target()))
        deviceMap.value(pkt.target())->handleMessage(pkt);
    else
        qDebug() << "RX'd a packet with unknown target:"<<pkt.target();
}

void RobotController::sendWirelessPacket(WirelessPacket pkt) {
    dispatcher->sendMessage(pkt);
}

ArmController * RobotController::_armController() {
    return m_armController;
}

MotorController * RobotController::_motorController() {
    return m_motorController;
}

GPSController * RobotController::_gpsController() {
    return m_gpsController;
}

StatusController * RobotController::_statusController() {
    return m_statusController;
}

TripodController * RobotController::_tripodController() {
    return m_tripodController;
}
