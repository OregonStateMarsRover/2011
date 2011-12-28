/****************************************************************************
** Meta object code from reading C++ file 'CameraWidget.h'
**
** Created: Sun Nov 20 17:15:58 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GUI/CameraWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CameraWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CameraWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      45,   13,   13,   13, 0x08,
      80,   71,   13,   13, 0x08,
     121,   71,   13,   13, 0x08,
     162,   71,   13,   13, 0x08,
     192,   71,   13,   13, 0x08,
     223,   13,   13,   13, 0x08,
     254,   13,   13,   13, 0x08,
     283,   13,   13,   13, 0x08,
     311,   13,   13,   13, 0x08,
     339,   13,   13,   13, 0x08,
     366,   13,   13,   13, 0x08,
     395,   13,   13,   13, 0x08,
     423,   13,   13,   13, 0x08,
     450,   13,   13,   13, 0x08,
     476,   13,   13,   13, 0x08,
     504,   13,   13,   13, 0x08,
     531,   13,   13,   13, 0x08,
     558,   13,   13,   13, 0x08,
     588,  584,   13,   13, 0x08,
     617,  612,   13,   13, 0x08,
     639,  584,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CameraWidget[] = {
    "CameraWidget\0\0on_sendCameraCommand_clicked()\0"
    "on_ExposureComp_clicked()\0position\0"
    "on_exposureCompenstaion_sliderMoved(int)\0"
    "on_manualExposureSlider_sliderMoved(int)\0"
    "on_panSlider_sliderMoved(int)\0"
    "on_tiltSlider_sliderMoved(int)\0"
    "on_doublePanTiltRate_clicked()\0"
    "on_panRightButton_released()\0"
    "on_panRightButton_pressed()\0"
    "on_panLeftButton_released()\0"
    "on_panLeftButton_pressed()\0"
    "on_tiltDownButton_released()\0"
    "on_tiltDownButton_pressed()\0"
    "on_tiltUpButton_released()\0"
    "on_tiltUpButton_pressed()\0"
    "on_zoomOutButton_released()\0"
    "on_zoomOutButton_pressed()\0"
    "on_zoomInButton_released()\0"
    "on_zoomInButton_pressed()\0pos\0"
    "panPositionChanged(int)\0zoom\0"
    "zoomLevelChanged(int)\0tiltPositionChanged(int)\0"
};

const QMetaObject CameraWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CameraWidget,
      qt_meta_data_CameraWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CameraWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CameraWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CameraWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CameraWidget))
        return static_cast<void*>(const_cast< CameraWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CameraWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_sendCameraCommand_clicked(); break;
        case 1: on_ExposureComp_clicked(); break;
        case 2: on_exposureCompenstaion_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: on_manualExposureSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: on_panSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: on_tiltSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: on_doublePanTiltRate_clicked(); break;
        case 7: on_panRightButton_released(); break;
        case 8: on_panRightButton_pressed(); break;
        case 9: on_panLeftButton_released(); break;
        case 10: on_panLeftButton_pressed(); break;
        case 11: on_tiltDownButton_released(); break;
        case 12: on_tiltDownButton_pressed(); break;
        case 13: on_tiltUpButton_released(); break;
        case 14: on_tiltUpButton_pressed(); break;
        case 15: on_zoomOutButton_released(); break;
        case 16: on_zoomOutButton_pressed(); break;
        case 17: on_zoomInButton_released(); break;
        case 18: on_zoomInButton_pressed(); break;
        case 19: panPositionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: zoomLevelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: tiltPositionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
