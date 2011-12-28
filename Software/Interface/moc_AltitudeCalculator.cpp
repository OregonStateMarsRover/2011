/****************************************************************************
** Meta object code from reading C++ file 'AltitudeCalculator.h'
**
** Created: Sun Nov 20 17:16:10 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Common/AltitudeCalculator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AltitudeCalculator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AltitudeCalculator[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      54,   20,   19,   19, 0x05,
      95,   86,   19,   19, 0x05,
     136,  119,   19,   19, 0x05,
     170,  164,   19,   19, 0x05,
     197,  192,   19,   19, 0x05,
     223,  218,   19,   19, 0x05,
     259,  250,   19,   19, 0x05,
     288,   86,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
     316,   86,   19,   19, 0x0a,
     365,  344,   19,   19, 0x0a,
     408,  250,   19,   19, 0x0a,
     436,   86,   19,   19, 0x0a,
     460,  344,   19,   19, 0x0a,
     505,  499,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AltitudeCalculator[] = {
    "AltitudeCalculator\0\0"
    "absoluteAltitude,relativeAltitude\0"
    "newRoverAltitude(double,double)\0"
    "pressure\0newRoverPressure(ulong)\0"
    "degPitch,degRoll\0newRoverTilt(double,double)\0"
    "pitch\0newRoverPitch(double)\0tilt\0"
    "newRoverRoll(double)\0temp\0"
    "newRoverTemperature(short)\0altitude\0"
    "newReferenceAltitude(double)\0"
    "newReferencePressure(ulong)\0"
    "setReferencePressure(ulong)\0"
    "temperature,pressure\0"
    "setReferencePressure(unsigned short,ulong)\0"
    "setReferenceAltitude(ulong)\0"
    "setRoverPressure(ulong)\0"
    "setRoverPressure(unsigned short,ulong)\0"
    "x,y,z\0setRoverAngle(short,short,short)\0"
};

const QMetaObject AltitudeCalculator::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AltitudeCalculator,
      qt_meta_data_AltitudeCalculator, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AltitudeCalculator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AltitudeCalculator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AltitudeCalculator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AltitudeCalculator))
        return static_cast<void*>(const_cast< AltitudeCalculator*>(this));
    return QObject::qt_metacast(_clname);
}

int AltitudeCalculator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newRoverAltitude((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: newRoverPressure((*reinterpret_cast< ulong(*)>(_a[1]))); break;
        case 2: newRoverTilt((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 3: newRoverPitch((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: newRoverRoll((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: newRoverTemperature((*reinterpret_cast< short(*)>(_a[1]))); break;
        case 6: newReferenceAltitude((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: newReferencePressure((*reinterpret_cast< ulong(*)>(_a[1]))); break;
        case 8: setReferencePressure((*reinterpret_cast< ulong(*)>(_a[1]))); break;
        case 9: setReferencePressure((*reinterpret_cast< unsigned short(*)>(_a[1])),(*reinterpret_cast< ulong(*)>(_a[2]))); break;
        case 10: setReferenceAltitude((*reinterpret_cast< ulong(*)>(_a[1]))); break;
        case 11: setRoverPressure((*reinterpret_cast< ulong(*)>(_a[1]))); break;
        case 12: setRoverPressure((*reinterpret_cast< unsigned short(*)>(_a[1])),(*reinterpret_cast< ulong(*)>(_a[2]))); break;
        case 13: setRoverAngle((*reinterpret_cast< short(*)>(_a[1])),(*reinterpret_cast< short(*)>(_a[2])),(*reinterpret_cast< short(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void AltitudeCalculator::newRoverAltitude(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AltitudeCalculator::newRoverPressure(unsigned long _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AltitudeCalculator::newRoverTilt(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AltitudeCalculator::newRoverPitch(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void AltitudeCalculator::newRoverRoll(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void AltitudeCalculator::newRoverTemperature(short _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void AltitudeCalculator::newReferenceAltitude(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void AltitudeCalculator::newReferencePressure(unsigned long _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
