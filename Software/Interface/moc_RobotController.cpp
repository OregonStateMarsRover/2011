/****************************************************************************
** Meta object code from reading C++ file 'RobotController.h'
**
** Created: Sun Nov 20 17:16:04 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "VirtualRover/RobotController.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RobotController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RobotController[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   17,   16,   16, 0x0a,
      56,   17,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RobotController[] = {
    "RobotController\0\0pkt\0"
    "sendWirelessPacket(WirelessPacket)\0"
    "processWirelessPacket(WirelessPacket)\0"
};

const QMetaObject RobotController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RobotController,
      qt_meta_data_RobotController, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RobotController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RobotController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RobotController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RobotController))
        return static_cast<void*>(const_cast< RobotController*>(this));
    return QObject::qt_metacast(_clname);
}

int RobotController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendWirelessPacket((*reinterpret_cast< WirelessPacket(*)>(_a[1]))); break;
        case 1: processWirelessPacket((*reinterpret_cast< WirelessPacket(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
