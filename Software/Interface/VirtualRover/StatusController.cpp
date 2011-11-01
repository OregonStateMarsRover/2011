/**
 * This controller is the general GUI message controller.
 * All messages targeted to TARGET_GUI are handled by this controller.
 * Messages transmitted are sent to the TARGET_TEST_CONTROLLER.
 */

#include <QDebug>
#include "StatusController.h"

StatusController::StatusController(QObject * parent) : AbstractController(parent)
{

}

void StatusController::handleMessage(WirelessPacket msg) {
    if (msg.data().at(0)=='R')
        qDebug() << "got GPS"<<msg.data().toHex();

    if (msg.data().at(0)==0x01) { // got error count
        QByteArray errors = msg.data().right(7);
        emit gotDataErrorCount(errors);
    }
    else {
        emit gotMessage(msg.data());
    }
}

int StatusController::guiMessageTarget() {
    return TARGET_GUI;
}

int StatusController::roverMessageTarget() {
    return TARGET_TEST_CONTROLLER;
    //return TARGET_GUI;
}

void StatusController::sendTestMessage(QString str) {
    QByteArray msg = str.toAscii();
    sendMessage(msg);
}

void StatusController::sendTestMessage(QByteArray msg) {
    sendMessage(msg);
}

void StatusController::requestDataErrorCount() {
    QByteArray msg;
    msg.append(0x01);
    sendMessage(msg);
}
