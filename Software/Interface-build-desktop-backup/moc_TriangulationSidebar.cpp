/****************************************************************************
** Meta object code from reading C++ file 'TriangulationSidebar.h'
**
** Created: Sun Oct 9 13:53:58 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Interface/GUI/TriangulationSidebar.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TriangulationSidebar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TriangulationSidebar[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      36,   22,   21,   21, 0x05,
      62,   21,   21,   21, 0x05,
     100,   79,   21,   21, 0x05,
     126,   21,   21,   21, 0x05,
     154,  148,   21,   21, 0x05,
     198,   21,   21,   21, 0x05,
     219,   21,   21,   21, 0x05,
     234,   21,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
     254,  248,   21,   21, 0x0a,
     272,   22,   21,   21, 0x0a,
     306,  297,   21,   21, 0x0a,
     327,   21,   21,   21, 0x08,
     373,   21,   21,   21, 0x08,
     398,   21,   21,   21, 0x08,
     424,   21,   21,   21, 0x08,
     458,   21,   21,   21, 0x08,
     500,   21,   21,   21, 0x08,
     529,   21,   21,   21, 0x08,
     572,   21,   21,   21, 0x08,
     617,  603,   21,   21, 0x08,
     654,  648,   21,   21, 0x08,
     713,  694,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TriangulationSidebar[] = {
    "TriangulationSidebar\0\0point1,point2\0"
    "drawLine(QPointF,QPointF)\0intersectLines()\0"
    "point,clearSelection\0selectPoint(QPointF,bool)\0"
    "clearSelectedPoints()\0lines\0"
    "selectLines(QList<QPair<QPointF,QPointF> >)\0"
    "clearSelectedLines()\0deletePoints()\0"
    "deleteLines()\0point\0addPoint(QPointF)\0"
    "addLine(QPointF,QPointF)\0landmark\0"
    "addLandmark(QPointF)\0"
    "on_landmarksListWidget_itemSelectionChanged()\0"
    "on_deleteLines_clicked()\0"
    "on_deletePoints_clicked()\0"
    "on_intersectLinesButton_clicked()\0"
    "on_linesListWidget_itemSelectionChanged()\0"
    "on_drawLinesButton_clicked()\0"
    "on_pointsListWidget_itemSelectionChanged()\0"
    "recalculateDistanceAltitiude()\0"
    "temp,pressure\0newBarometerData(ushort,ulong)\0"
    "x,y,z\0newAccelerometerData(short,short,short)\0"
    "absolute,elevation\0newRobotElevation(double,double)\0"
};

const QMetaObject TriangulationSidebar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TriangulationSidebar,
      qt_meta_data_TriangulationSidebar, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TriangulationSidebar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TriangulationSidebar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TriangulationSidebar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TriangulationSidebar))
        return static_cast<void*>(const_cast< TriangulationSidebar*>(this));
    return QWidget::qt_metacast(_clname);
}

int TriangulationSidebar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: drawLine((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2]))); break;
        case 1: intersectLines(); break;
        case 2: selectPoint((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: clearSelectedPoints(); break;
        case 4: selectLines((*reinterpret_cast< QList<QPair<QPointF,QPointF> >(*)>(_a[1]))); break;
        case 5: clearSelectedLines(); break;
        case 6: deletePoints(); break;
        case 7: deleteLines(); break;
        case 8: addPoint((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 9: addLine((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2]))); break;
        case 10: addLandmark((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 11: on_landmarksListWidget_itemSelectionChanged(); break;
        case 12: on_deleteLines_clicked(); break;
        case 13: on_deletePoints_clicked(); break;
        case 14: on_intersectLinesButton_clicked(); break;
        case 15: on_linesListWidget_itemSelectionChanged(); break;
        case 16: on_drawLinesButton_clicked(); break;
        case 17: on_pointsListWidget_itemSelectionChanged(); break;
        case 18: recalculateDistanceAltitiude(); break;
        case 19: newBarometerData((*reinterpret_cast< ushort(*)>(_a[1])),(*reinterpret_cast< ulong(*)>(_a[2]))); break;
        case 20: newAccelerometerData((*reinterpret_cast< short(*)>(_a[1])),(*reinterpret_cast< short(*)>(_a[2])),(*reinterpret_cast< short(*)>(_a[3]))); break;
        case 21: newRobotElevation((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void TriangulationSidebar::drawLine(QPointF _t1, QPointF _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TriangulationSidebar::intersectLines()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void TriangulationSidebar::selectPoint(QPointF _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TriangulationSidebar::clearSelectedPoints()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void TriangulationSidebar::selectLines(QList<QPair<QPointF,QPointF> > _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TriangulationSidebar::clearSelectedLines()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void TriangulationSidebar::deletePoints()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void TriangulationSidebar::deleteLines()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}
QT_END_MOC_NAMESPACE
