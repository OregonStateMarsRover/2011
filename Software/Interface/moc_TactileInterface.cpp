/****************************************************************************
** Meta object code from reading C++ file 'TactileInterface.h'
**
** Created: Tue Jan 24 21:44:05 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Tactile/TactileInterface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TactileInterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TactileInterface[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      31,   18,   17,   17, 0x05,
      55,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      90,   79,   17,   17, 0x08,
     125,  118,   17,   17, 0x08,
     152,  118,   17,   17, 0x08,
     178,   79,   17,   17, 0x08,
     202,  118,   17,   17, 0x08,
     224,  118,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TactileInterface[] = {
    "TactileInterface\0\0inStrafeMode\0"
    "strafeModeChanged(bool)\0slowModeButtonToggled()\0"
    "axis,value\0drivingAxisChanged(int,int)\0"
    "button\0drivingButtonReleased(int)\0"
    "drivingButtonPressed(int)\0"
    "armAxisChanged(int,int)\0armButtonPressed(int)\0"
    "armButtonReleased(int)\0"
};

const QMetaObject TactileInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TactileInterface,
      qt_meta_data_TactileInterface, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TactileInterface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TactileInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TactileInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TactileInterface))
        return static_cast<void*>(const_cast< TactileInterface*>(this));
    return QObject::qt_metacast(_clname);
}

int TactileInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: strafeModeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: slowModeButtonToggled(); break;
        case 2: drivingAxisChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: drivingButtonReleased((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: drivingButtonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: armAxisChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: armButtonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: armButtonReleased((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void TactileInterface::strafeModeChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TactileInterface::slowModeButtonToggled()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
