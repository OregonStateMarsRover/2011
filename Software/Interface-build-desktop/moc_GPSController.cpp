/****************************************************************************
** Meta object code from reading C++ file 'GPSController.h'
**
** Created: Sun Oct 9 13:53:50 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Interface/VirtualRover/GPSController.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GPSController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GPSController[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      50,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      83,   14,   14,   14, 0x0a,
     113,  100,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GPSController[] = {
    "GPSController\0\0gotPositionUpdate(GPSPositionData)\0"
    "gotHeadingUpdate(GPSHeadingData)\0"
    "sendGPSRequest()\0sendRequests\0"
    "enablePeriodicGPSRequests(bool)\0"
};

const QMetaObject GPSController::staticMetaObject = {
    { &AbstractController::staticMetaObject, qt_meta_stringdata_GPSController,
      qt_meta_data_GPSController, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GPSController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GPSController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GPSController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GPSController))
        return static_cast<void*>(const_cast< GPSController*>(this));
    return AbstractController::qt_metacast(_clname);
}

int GPSController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractController::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: gotPositionUpdate((*reinterpret_cast< GPSPositionData(*)>(_a[1]))); break;
        case 1: gotHeadingUpdate((*reinterpret_cast< GPSHeadingData(*)>(_a[1]))); break;
        case 2: sendGPSRequest(); break;
        case 3: enablePeriodicGPSRequests((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void GPSController::gotPositionUpdate(GPSPositionData _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GPSController::gotHeadingUpdate(GPSHeadingData _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
