/****************************************************************************
** Meta object code from reading C++ file 'StatusWidget.h'
**
** Created: Thu Jan 5 08:30:36 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GUI/StatusWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StatusWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StatusWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      49,   13,   13,   13, 0x08,
      91,   13,   13,   13, 0x08,
     119,   13,   13,   13, 0x08,
     146,   13,   13,   13, 0x08,
     172,   13,   13,   13, 0x08,
     196,   13,   13,   13, 0x08,
     240,  219,   13,   13, 0x08,
     292,  283,   13,   13, 0x08,
     321,  315,   13,   13, 0x08,
     348,  343,   13,   13, 0x08,
     369,  283,   13,   13, 0x08,
     398,  393,   13,   13, 0x08,
     443,  425,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_StatusWidget[] = {
    "StatusWidget\0\0on_baseOffsetBox_valueChanged(int)\0"
    "on_referenceAltitudeBox_editingFinished()\0"
    "on_enableAccelBox_clicked()\0"
    "on_enableBaroBox_clicked()\0"
    "on_enableGPSBox_clicked()\0"
    "on_sendButton_clicked()\0requestBarometerData()\0"
    "temperature,pressure\0"
    "gotBaseBarometerData(unsigned short,ulong)\0"
    "pressure\0gotBasePressure(ulong)\0pitch\0"
    "gotRoverPitch(double)\0roll\0"
    "gotRoverRoll(double)\0gotRoverPressure(ulong)\0"
    "temp\0gotRoverTemperature(short)\0"
    "absolute,relative\0gotRoverAltitude(double,double)\0"
};

const QMetaObject StatusWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_StatusWidget,
      qt_meta_data_StatusWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StatusWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StatusWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StatusWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StatusWidget))
        return static_cast<void*>(const_cast< StatusWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int StatusWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_baseOffsetBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: on_referenceAltitudeBox_editingFinished(); break;
        case 2: on_enableAccelBox_clicked(); break;
        case 3: on_enableBaroBox_clicked(); break;
        case 4: on_enableGPSBox_clicked(); break;
        case 5: on_sendButton_clicked(); break;
        case 6: requestBarometerData(); break;
        case 7: gotBaseBarometerData((*reinterpret_cast< unsigned short(*)>(_a[1])),(*reinterpret_cast< ulong(*)>(_a[2]))); break;
        case 8: gotBasePressure((*reinterpret_cast< ulong(*)>(_a[1]))); break;
        case 9: gotRoverPitch((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: gotRoverRoll((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: gotRoverPressure((*reinterpret_cast< ulong(*)>(_a[1]))); break;
        case 12: gotRoverTemperature((*reinterpret_cast< short(*)>(_a[1]))); break;
        case 13: gotRoverAltitude((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
