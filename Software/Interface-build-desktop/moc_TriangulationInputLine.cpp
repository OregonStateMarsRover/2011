/****************************************************************************
** Meta object code from reading C++ file 'TriangulationInputLine.h'
**
** Created: Sun Oct 9 13:53:29 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Interface/GUI/TriangulationInputLine.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TriangulationInputLine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TriangulationInputLine[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      33,   24,   23,   23, 0x05,

 // slots: signature, parameters, type, tag, flags
      58,   53,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TriangulationInputLine[] = {
    "TriangulationInputLine\0\0id,valid\0"
    "hasUpdate(int,bool)\0text\0validateText(QString)\0"
};

const QMetaObject TriangulationInputLine::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_TriangulationInputLine,
      qt_meta_data_TriangulationInputLine, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TriangulationInputLine::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TriangulationInputLine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TriangulationInputLine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TriangulationInputLine))
        return static_cast<void*>(const_cast< TriangulationInputLine*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int TriangulationInputLine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: hasUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: validateText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void TriangulationInputLine::hasUpdate(int _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
