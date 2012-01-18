/****************************************************************************
** Meta object code from reading C++ file 'TriangulationWidget.h'
**
** Created: Thu Jan 12 09:42:53 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Interface/GUI/TriangulationWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TriangulationWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TriangulationWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      33,   21,   20,   20, 0x0a,
      77,   73,   20,   20, 0x0a,
     114,  106,   20,   20, 0x0a,
     149,  140,   20,   20, 0x08,
     178,   20,   20,   20, 0x08,
     197,   20,   20,   20, 0x08,
     216,   20,   20,   20, 0x08,
     228,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TriangulationWidget[] = {
    "TriangulationWidget\0\0pos,heading\0"
    "updateRoverPosAndHeading(QPointF,qreal)\0"
    "pos\0updateRoverPosition(QPointF)\0"
    "heading\0updateRoverHeading(qreal)\0"
    "id,valid\0receiveInputUpdate(int,bool)\0"
    "setInputAToRover()\0setInputBToRover()\0"
    "saveToLog()\0clearLog()\0"
};

const QMetaObject TriangulationWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TriangulationWidget,
      qt_meta_data_TriangulationWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TriangulationWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TriangulationWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TriangulationWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TriangulationWidget))
        return static_cast<void*>(const_cast< TriangulationWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int TriangulationWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateRoverPosAndHeading((*reinterpret_cast< const QPointF(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 1: updateRoverPosition((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 2: updateRoverHeading((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 3: receiveInputUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: setInputAToRover(); break;
        case 5: setInputBToRover(); break;
        case 6: saveToLog(); break;
        case 7: clearLog(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
