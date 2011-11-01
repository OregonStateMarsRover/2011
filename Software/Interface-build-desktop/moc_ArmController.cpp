/****************************************************************************
** Meta object code from reading C++ file 'ArmController.h'
**
** Created: Sun Oct 9 13:53:39 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Interface/VirtualRover/ArmController.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ArmController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ArmController[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      51,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   15,   14,   14, 0x05,
      54,   15,   14,   14, 0x05,
      86,   15,   14,   14, 0x05,
     123,  119,   14,   14, 0x05,
     161,  154,   14,   14, 0x05,
     191,  154,   14,   14, 0x05,
     226,  154,   14,   14, 0x05,
     259,   14,   14,   14, 0x05,
     276,   14,   14,   14, 0x05,
     294,  292,   14,   14, 0x05,
     313,  292,   14,   14, 0x05,
     337,  292,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     361,   14,   14,   14, 0x0a,
     375,   14,   14,   14, 0x0a,
     391,   14,   14,   14, 0x0a,
     407,   14,   14,   14, 0x0a,
     422,   14,   14,   14, 0x0a,
     437,   14,   14,   14, 0x0a,
     453,   14,   14,   14, 0x0a,
     466,   14,   14,   14, 0x0a,
     481,   14,   14,   14, 0x0a,
     495,   14,   14,   14, 0x0a,
     506,   14,   14,   14, 0x0a,
     519,   14,   14,   14, 0x0a,
     532,   14,   14,   14, 0x0a,
     545,   14,   14,   14, 0x0a,
     558,   14,   14,   14, 0x0a,
     572,   14,   14,   14, 0x0a,
     584,   14,   14,   14, 0x0a,
     597,   14,   14,   14, 0x0a,
     611,   14,   14,   14, 0x0a,
     628,   14,   14,   14, 0x0a,
     646,   14,   14,   14, 0x0a,
     663,   14,   14,   14, 0x0a,
     681,   14,   14,   14, 0x0a,
     701,   14,   14,   14, 0x0a,
     721,   14,   14,   14, 0x0a,
     741,   14,   14,   14, 0x0a,
     763,   14,   14,   14, 0x0a,
     785,   14,   14,   14, 0x0a,
     806,   14,   14,   14, 0x0a,
     828,   14,   14,   14, 0x0a,
     855,  849,   14,   14, 0x0a,
     877,  849,   14,   14, 0x0a,
     898,  849,   14,   14, 0x0a,
     923,  919,   14,   14, 0x0a,
     965,  958,   14,   14, 0x0a,
    1012,  119,   14,   14, 0x0a,
    1040,   14,   14,   14, 0x08,
    1053,   14,   14,   14, 0x08,
    1076,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ArmController[] = {
    "ArmController\0\0angles\0"
    "newArmPositions(ArmWristAngles)\0"
    "newArmPositions(ArmAstroAngles)\0"
    "newArmPositions(ArmShovelAngles)\0cmd\0"
    "newCommandReceived(QByteArray)\0newPos\0"
    "newGripperPos(unsigned short)\0"
    "newCameraRotatePos(unsigned short)\0"
    "newCameraTiltPos(unsigned short)\0"
    "hadGlobalError()\0hadSlaveError()\0s\0"
    "logAppend(QString)\0statusBox1Text(QString)\0"
    "statusBox2Text(QString)\0setHeightUp()\0"
    "setHeightStop()\0setHeightDown()\0"
    "setWidthLeft()\0setWidthStop()\0"
    "setWidthRight()\0setDepthIn()\0"
    "setDepthStop()\0setDepthOut()\0setTipUp()\0"
    "setTipStop()\0setTipDown()\0setPanLeft()\0"
    "setPanStop()\0setPanRight()\0setZoomIn()\0"
    "setZoomOut()\0setZoomStop()\0setGripperOpen()\0"
    "setGripperClose()\0setGripperStop()\0"
    "setCameraTiltUp()\0setCameraTiltDown()\0"
    "setCameraTiltStop()\0setCameraRotateUp()\0"
    "setCameraRotateDown()\0setCameraRotateStop()\0"
    "setWristRotateLeft()\0setWristRotateRight()\0"
    "setWristRotateStop()\0speed\0"
    "setHeightSpeed(float)\0setWidthSpeed(float)\0"
    "setDepthSpeed(float)\0pos\0"
    "setGripperPosition(unsigned short)\0"
    "id,pos\0setServoPosition(unsigned char,unsigned short)\0"
    "sendPassThrough(QByteArray)\0updateTime()\0"
    "packetTimeoutHandler()\0sendReadArmPosition()\0"
};

const QMetaObject ArmController::staticMetaObject = {
    { &AbstractController::staticMetaObject, qt_meta_stringdata_ArmController,
      qt_meta_data_ArmController, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ArmController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ArmController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ArmController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ArmController))
        return static_cast<void*>(const_cast< ArmController*>(this));
    return AbstractController::qt_metacast(_clname);
}

int ArmController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractController::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newArmPositions((*reinterpret_cast< ArmWristAngles(*)>(_a[1]))); break;
        case 1: newArmPositions((*reinterpret_cast< ArmAstroAngles(*)>(_a[1]))); break;
        case 2: newArmPositions((*reinterpret_cast< ArmShovelAngles(*)>(_a[1]))); break;
        case 3: newCommandReceived((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: newGripperPos((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 5: newCameraRotatePos((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 6: newCameraTiltPos((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 7: hadGlobalError(); break;
        case 8: hadSlaveError(); break;
        case 9: logAppend((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: statusBox1Text((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: statusBox2Text((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: setHeightUp(); break;
        case 13: setHeightStop(); break;
        case 14: setHeightDown(); break;
        case 15: setWidthLeft(); break;
        case 16: setWidthStop(); break;
        case 17: setWidthRight(); break;
        case 18: setDepthIn(); break;
        case 19: setDepthStop(); break;
        case 20: setDepthOut(); break;
        case 21: setTipUp(); break;
        case 22: setTipStop(); break;
        case 23: setTipDown(); break;
        case 24: setPanLeft(); break;
        case 25: setPanStop(); break;
        case 26: setPanRight(); break;
        case 27: setZoomIn(); break;
        case 28: setZoomOut(); break;
        case 29: setZoomStop(); break;
        case 30: setGripperOpen(); break;
        case 31: setGripperClose(); break;
        case 32: setGripperStop(); break;
        case 33: setCameraTiltUp(); break;
        case 34: setCameraTiltDown(); break;
        case 35: setCameraTiltStop(); break;
        case 36: setCameraRotateUp(); break;
        case 37: setCameraRotateDown(); break;
        case 38: setCameraRotateStop(); break;
        case 39: setWristRotateLeft(); break;
        case 40: setWristRotateRight(); break;
        case 41: setWristRotateStop(); break;
        case 42: setHeightSpeed((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 43: setWidthSpeed((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 44: setDepthSpeed((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 45: setGripperPosition((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 46: setServoPosition((*reinterpret_cast< unsigned char(*)>(_a[1])),(*reinterpret_cast< unsigned short(*)>(_a[2]))); break;
        case 47: sendPassThrough((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 48: updateTime(); break;
        case 49: packetTimeoutHandler(); break;
        case 50: sendReadArmPosition(); break;
        default: ;
        }
        _id -= 51;
    }
    return _id;
}

// SIGNAL 0
void ArmController::newArmPositions(ArmWristAngles _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ArmController::newArmPositions(ArmAstroAngles _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ArmController::newArmPositions(ArmShovelAngles _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ArmController::newCommandReceived(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ArmController::newGripperPos(unsigned short _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ArmController::newCameraRotatePos(unsigned short _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ArmController::newCameraTiltPos(unsigned short _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ArmController::hadGlobalError()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void ArmController::hadSlaveError()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void ArmController::logAppend(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void ArmController::statusBox1Text(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void ArmController::statusBox2Text(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_END_MOC_NAMESPACE
