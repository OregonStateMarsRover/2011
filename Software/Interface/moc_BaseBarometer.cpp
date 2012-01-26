/****************************************************************************
** Meta object code from reading C++ file 'BaseBarometer.h'
**
** Created: Tue Jan 24 21:44:09 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Tactile/BaseBarometer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BaseBarometer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BaseBarometer[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      54,   15,   14,   14, 0x05,
     158,  137,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     196,   14,   14,   14, 0x0a,
     218,   14,   14,   14, 0x0a,
     247,  240,   14,   14, 0x0a,
     275,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BaseBarometer[] = {
    "BaseBarometer\0\0ac1,ac2,ac3,ac4,ac5,ac6,b1,b2,mb,mc,md\0"
    "gotCoefficients(short,short,short,short,short,short,short,short,short,"
    "short,short)\0"
    "temperature,pressure\0"
    "gotPressureData(unsigned short,ulong)\0"
    "requestCoefficients()\0requestPressureData()\0"
    "offset\0setBaseBarometerOffset(int)\0"
    "processUSBData()\0"
};

const QMetaObject BaseBarometer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BaseBarometer,
      qt_meta_data_BaseBarometer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BaseBarometer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BaseBarometer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BaseBarometer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BaseBarometer))
        return static_cast<void*>(const_cast< BaseBarometer*>(this));
    return QObject::qt_metacast(_clname);
}

int BaseBarometer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: gotCoefficients((*reinterpret_cast< short(*)>(_a[1])),(*reinterpret_cast< short(*)>(_a[2])),(*reinterpret_cast< short(*)>(_a[3])),(*reinterpret_cast< short(*)>(_a[4])),(*reinterpret_cast< short(*)>(_a[5])),(*reinterpret_cast< short(*)>(_a[6])),(*reinterpret_cast< short(*)>(_a[7])),(*reinterpret_cast< short(*)>(_a[8])),(*reinterpret_cast< short(*)>(_a[9])),(*reinterpret_cast< short(*)>(_a[10])),(*reinterpret_cast< short(*)>(_a[11]))); break;
        case 1: gotPressureData((*reinterpret_cast< unsigned short(*)>(_a[1])),(*reinterpret_cast< ulong(*)>(_a[2]))); break;
        case 2: requestCoefficients(); break;
        case 3: requestPressureData(); break;
        case 4: setBaseBarometerOffset((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: processUSBData(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void BaseBarometer::gotCoefficients(short _t1, short _t2, short _t3, short _t4, short _t5, short _t6, short _t7, short _t8, short _t9, short _t10, short _t11)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)), const_cast<void*>(reinterpret_cast<const void*>(&_t9)), const_cast<void*>(reinterpret_cast<const void*>(&_t10)), const_cast<void*>(reinterpret_cast<const void*>(&_t11)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BaseBarometer::gotPressureData(unsigned short _t1, unsigned long _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
