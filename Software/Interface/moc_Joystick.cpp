/****************************************************************************
** Meta object code from reading C++ file 'Joystick.h'
**
** Created: Tue Jan 24 21:44:05 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Tactile/Joystick.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Joystick.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Joystick[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   10,    9,    9, 0x05,
      55,   42,    9,    9, 0x05,
      86,   79,    9,    9, 0x05,
     105,   79,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     125,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Joystick[] = {
    "Joystick\0\0axis,value\0axisChanged(int,int)\0"
    "button,value\0buttonChanged(int,bool)\0"
    "button\0buttonPressed(int)\0buttonReleased(int)\0"
    "update()\0"
};

const QMetaObject Joystick::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Joystick,
      qt_meta_data_Joystick, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Joystick::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Joystick::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Joystick::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Joystick))
        return static_cast<void*>(const_cast< Joystick*>(this));
    return QObject::qt_metacast(_clname);
}

int Joystick::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: axisChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: buttonChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: buttonPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: buttonReleased((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: update(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Joystick::axisChanged(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Joystick::buttonChanged(int _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Joystick::buttonPressed(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Joystick::buttonReleased(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
