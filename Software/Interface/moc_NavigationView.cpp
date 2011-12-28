/****************************************************************************
** Meta object code from reading C++ file 'NavigationView.h'
**
** Created: Sun Nov 20 17:16:00 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GUI/NavigationView.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NavigationView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NavigationView[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   16,   15,   15, 0x05,
      52,   46,   15,   15, 0x05,
      89,   75,   15,   15, 0x05,
     119,   46,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     157,  145,   15,   15, 0x0a,
     204,  194,   15,   15, 0x0a,
     238,  230,   15,   15, 0x0a,
     261,   15,   15,   15, 0x0a,
     283,   15,   15,   15, 0x0a,
     305,   75,   15,   15, 0x0a,
     340,   15,   15,   15, 0x0a,
     384,  363,   15,   15, 0x0a,
     410,   46,   15,   15, 0x2a,
     431,   15,   15,   15, 0x0a,
     459,  453,   15,   15, 0x0a,
     503,   15,   15,   15, 0x0a,
     524,   15,   15,   15, 0x0a,
     547,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_NavigationView[] = {
    "NavigationView\0\0coords\0mouseAtGeoPos(QPointF)\0"
    "point\0newPointAdded(QPointF)\0point1,point2\0"
    "newLineAdded(QPointF,QPointF)\0"
    "newLandmarkAdded(QPointF)\0pos,heading\0"
    "setRoverPosAndHeading(QPointF,qreal)\0"
    "geoCoords\0setRoverPosition(QPointF)\0"
    "heading\0setRoverHeading(qreal)\0"
    "updateConfiguration()\0plotLineForSelected()\0"
    "plotLineForPoints(QPointF,QPointF)\0"
    "plotLineIntersection()\0point,clearSelection\0"
    "selectPoint(QPointF,bool)\0"
    "selectPoint(QPointF)\0clearSelectedPoints()\0"
    "lines\0selectLines(QList<QPair<QPointF,QPointF> >)\0"
    "clearSelectedLines()\0deleteSelectedPoints()\0"
    "deleteSelectedLines()\0"
};

const QMetaObject NavigationView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_NavigationView,
      qt_meta_data_NavigationView, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NavigationView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NavigationView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NavigationView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NavigationView))
        return static_cast<void*>(const_cast< NavigationView*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int NavigationView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: mouseAtGeoPos((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 1: newPointAdded((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 2: newLineAdded((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2]))); break;
        case 3: newLandmarkAdded((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 4: setRoverPosAndHeading((*reinterpret_cast< const QPointF(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 5: setRoverPosition((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 6: setRoverHeading((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 7: updateConfiguration(); break;
        case 8: plotLineForSelected(); break;
        case 9: plotLineForPoints((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2]))); break;
        case 10: plotLineIntersection(); break;
        case 11: selectPoint((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 12: selectPoint((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 13: clearSelectedPoints(); break;
        case 14: selectLines((*reinterpret_cast< QList<QPair<QPointF,QPointF> >(*)>(_a[1]))); break;
        case 15: clearSelectedLines(); break;
        case 16: deleteSelectedPoints(); break;
        case 17: deleteSelectedLines(); break;
        default: ;
        }
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void NavigationView::mouseAtGeoPos(const QPointF & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NavigationView::newPointAdded(const QPointF _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NavigationView::newLineAdded(QPointF _t1, QPointF _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NavigationView::newLandmarkAdded(const QPointF _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
