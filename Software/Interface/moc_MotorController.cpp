/****************************************************************************
** Meta object code from reading C++ file 'MotorController.h'
**
** Created: Tue Jan 24 21:44:06 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "VirtualRover/MotorController.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MotorController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MotorController[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   17,   16,   16, 0x05,
      55,   51,   16,   16, 0x05,
      87,   83,   16,   16, 0x05,
     114,   51,   16,   16, 0x05,
     143,   83,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     172,   16,   16,   16, 0x0a,
     197,  188,   16,   16, 0x0a,
     224,  214,   16,   16, 0x0a,
     250,  241,   16,   16, 0x0a,
     276,   16,   16,   16, 0x0a,
     297,  188,   16,   16, 0x0a,
     329,  320,   16,   16, 0x0a,
     358,  352,   16,   16, 0x0a,
     386,   16,   16,   16, 0x08,
     407,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MotorController[] = {
    "MotorController\0\0timedOut\0"
    "hadWatchdogTimeout(bool)\0msg\0"
    "gotStatusPacket(QByteArray)\0dat\0"
    "gotPassThrough(QByteArray)\0"
    "gotTimeoutPacket(QByteArray)\0"
    "gotCurrentPacket(QByteArray)\0"
    "toggleMosfets()\0disabled\0setMosfets(bool)\0"
    "enablePWM\0setPWMMode(bool)\0useCurve\0"
    "setExponentialCurve(bool)\0"
    "requestCurrentData()\0setCornerMosfets(bool)\0"
    "inStrafe\0setRoverInStrafe(bool)\0scale\0"
    "setGlobalMotorScaler(float)\0"
    "sendWatchdogUpdate()\0runActuatorStateRunner()\0"
};

const QMetaObject MotorController::staticMetaObject = {
    { &AbstractController::staticMetaObject, qt_meta_stringdata_MotorController,
      qt_meta_data_MotorController, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MotorController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MotorController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MotorController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MotorController))
        return static_cast<void*>(const_cast< MotorController*>(this));
    return AbstractController::qt_metacast(_clname);
}

int MotorController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractController::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: hadWatchdogTimeout((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: gotStatusPacket((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: gotPassThrough((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: gotTimeoutPacket((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: gotCurrentPacket((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: toggleMosfets(); break;
        case 6: setMosfets((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: setPWMMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: setExponentialCurve((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: requestCurrentData(); break;
        case 10: setCornerMosfets((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: setRoverInStrafe((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: setGlobalMotorScaler((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 13: sendWatchdogUpdate(); break;
        case 14: runActuatorStateRunner(); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void MotorController::hadWatchdogTimeout(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MotorController::gotStatusPacket(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MotorController::gotPassThrough(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MotorController::gotTimeoutPacket(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MotorController::gotCurrentPacket(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
