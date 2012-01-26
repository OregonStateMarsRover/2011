/****************************************************************************
** Meta object code from reading C++ file 'TripodController.h'
**
** Created: Tue Jan 24 21:44:04 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "VirtualRover/TripodController.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TripodController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TripodController[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      31,   18,   17,   17, 0x05,
      63,   52,   17,   17, 0x05,
      94,   84,   17,   17, 0x05,
     120,  114,   17,   17, 0x05,
     181,  160,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
     235,  220,   17,   17, 0x0a,
     277,  267,   17,   17, 0x0a,
     305,  298,   17,   17, 0x0a,
     335,  327,   17,   17, 0x0a,
     358,   17,   17,   17, 0x0a,
     378,  374,   17,   17, 0x0a,
     405,  374,   17,   17, 0x0a,
     433,  374,   17,   17, 0x0a,
     473,  461,   17,   17, 0x0a,
     496,   17,   17,   17, 0x0a,
     524,  511,   17,   17, 0x0a,
     562,  511,  557,   17, 0x0a,
     596,   17,   17,   17, 0x08,
     609,   17,   17,   17, 0x08,
     625,   17,   17,   17, 0x08,
     648,   17,   17,   17, 0x08,
     675,  114,   17,   17, 0x08,
     724,  710,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TripodController[] = {
    "TripodController\0\0newZoomLevel\0"
    "newZoomPosition(int)\0newTiltPos\0"
    "newTiltPosition(int)\0newPanPos\0"
    "newPanPosition(int)\0x,y,z\0"
    "newAccelerometerData(short,short,short)\0"
    "temperature,pressure\0"
    "newBarometerData(unsigned short,ulong)\0"
    "panPos,tiltPos\0setPanTiltPosition(short,short)\0"
    "zoomLevel\0setCameraZoom(short)\0panPos\0"
    "setPanPosition(short)\0tiltPos\0"
    "setTiltPosition(short)\0centerPanTilt()\0"
    "dir\0startPanning(PanDirection)\0"
    "startTilting(TiltDirection)\0"
    "startZooming(ZoomDirection)\0doubleSpeed\0"
    "setPanTiltDouble(bool)\0setNewCenter()\0"
    "sendRequests\0enablePeriodicBaroRequests(bool)\0"
    "bool\0enablePeriodicAccelRequests(bool)\0"
    "updateZoom()\0updatePanTilt()\0"
    "requestBarometerData()\0"
    "requestAccelerometerData()\0"
    "recordAccelData(short,short,short)\0"
    "temp,pressure\0recordBaroData(short,ulong)\0"
};

const QMetaObject TripodController::staticMetaObject = {
    { &AbstractController::staticMetaObject, qt_meta_stringdata_TripodController,
      qt_meta_data_TripodController, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TripodController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TripodController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TripodController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TripodController))
        return static_cast<void*>(const_cast< TripodController*>(this));
    return AbstractController::qt_metacast(_clname);
}

int TripodController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractController::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newZoomPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: newTiltPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: newPanPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: newAccelerometerData((*reinterpret_cast< short(*)>(_a[1])),(*reinterpret_cast< short(*)>(_a[2])),(*reinterpret_cast< short(*)>(_a[3]))); break;
        case 4: newBarometerData((*reinterpret_cast< unsigned short(*)>(_a[1])),(*reinterpret_cast< ulong(*)>(_a[2]))); break;
        case 5: setPanTiltPosition((*reinterpret_cast< short(*)>(_a[1])),(*reinterpret_cast< short(*)>(_a[2]))); break;
        case 6: setCameraZoom((*reinterpret_cast< short(*)>(_a[1]))); break;
        case 7: setPanPosition((*reinterpret_cast< short(*)>(_a[1]))); break;
        case 8: setTiltPosition((*reinterpret_cast< short(*)>(_a[1]))); break;
        case 9: centerPanTilt(); break;
        case 10: startPanning((*reinterpret_cast< PanDirection(*)>(_a[1]))); break;
        case 11: startTilting((*reinterpret_cast< TiltDirection(*)>(_a[1]))); break;
        case 12: startZooming((*reinterpret_cast< ZoomDirection(*)>(_a[1]))); break;
        case 13: setPanTiltDouble((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: setNewCenter(); break;
        case 15: enablePeriodicBaroRequests((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: { bool _r = enablePeriodicAccelRequests((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 17: updateZoom(); break;
        case 18: updatePanTilt(); break;
        case 19: requestBarometerData(); break;
        case 20: requestAccelerometerData(); break;
        case 21: recordAccelData((*reinterpret_cast< short(*)>(_a[1])),(*reinterpret_cast< short(*)>(_a[2])),(*reinterpret_cast< short(*)>(_a[3]))); break;
        case 22: recordBaroData((*reinterpret_cast< short(*)>(_a[1])),(*reinterpret_cast< ulong(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void TripodController::newZoomPosition(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TripodController::newTiltPosition(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TripodController::newPanPosition(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TripodController::newAccelerometerData(short _t1, short _t2, short _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TripodController::newBarometerData(unsigned short _t1, unsigned long _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
