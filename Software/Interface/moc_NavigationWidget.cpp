/****************************************************************************
** Meta object code from reading C++ file 'NavigationWidget.h'
**
** Created: Sun Nov 20 17:15:59 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GUI/NavigationWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NavigationWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NavigationWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      25,   18,   17,   17, 0x0a,
      53,   17,   17,   17, 0x08,
      81,   17,   17,   17, 0x08,
     102,   98,   17,   17, 0x08,
     132,   98,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NavigationWidget[] = {
    "NavigationWidget\0\0coords\0"
    "displayCoordinates(QPointF)\0"
    "on_addPointButton_clicked()\0"
    "sendGPSRequest()\0dat\0gotGPSUpdate(GPSPositionData)\0"
    "gotGPSHeading(GPSHeadingData)\0"
};

const QMetaObject NavigationWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NavigationWidget,
      qt_meta_data_NavigationWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NavigationWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NavigationWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NavigationWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NavigationWidget))
        return static_cast<void*>(const_cast< NavigationWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int NavigationWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: displayCoordinates((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 1: on_addPointButton_clicked(); break;
        case 2: sendGPSRequest(); break;
        case 3: gotGPSUpdate((*reinterpret_cast< GPSPositionData(*)>(_a[1]))); break;
        case 4: gotGPSHeading((*reinterpret_cast< GPSHeadingData(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
