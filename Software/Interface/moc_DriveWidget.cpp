/****************************************************************************
** Meta object code from reading C++ file 'DriveWidget.h'
**
** Created: Thu Jan 5 14:40:45 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GUI/DriveWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DriveWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DriveWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      59,   53,   12,   12, 0x08,
      95,   12,   12,   12, 0x08,
     131,   12,   12,   12, 0x08,
     160,   12,   12,   12, 0x08,
     200,   12,   12,   12, 0x08,
     244,   12,   12,   12, 0x08,
     269,   12,   12,   12, 0x08,
     305,   12,   12,   12, 0x08,
     343,   12,   12,   12, 0x08,
     367,   12,   12,   12, 0x08,
     415,   12,   12,   12, 0x08,
     443,   12,   12,   12, 0x08,
     475,  471,   12,   12, 0x08,
     526,   12,   12,   12, 0x08,
     557,   12,   12,   12, 0x08,
     584,   12,   12,   12, 0x08,
     615,   12,   12,   12, 0x08,
     639,   12,   12,   12, 0x08,
     670,   12,   12,   12, 0x08,
     695,  471,   12,   12, 0x08,
     726,  471,   12,   12, 0x08,
     770,  759,   12,   12, 0x08,
     804,  795,   12,   12, 0x08,
     828,   12,   12,   12, 0x08,
     852,   12,   12,   12, 0x08,
     871,   12,   12,   12, 0x08,
     887,  471,   12,   12, 0x08,
     921,  471,   12,   12, 0x08,
     948,  471,   12,   12, 0x08,
     986,  980,   12,   12, 0x08,
    1021,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DriveWidget[] = {
    "DriveWidget\0\0index,status\0"
    "statusChanged(int,QString)\0value\0"
    "on_maxSpeedSlider_valueChanged(int)\0"
    "on_maxSpeedBox_valueChanged(double)\0"
    "on_inStrafeModeBox_clicked()\0"
    "on_stallCurrentBox_valueChanged(double)\0"
    "on_directionDivisorBox_valueChanged(double)\0"
    "on_useCurveBox_clicked()\0"
    "on_dirScaleBox_valueChanged(double)\0"
    "on_speedScaleBox_valueChanged(double)\0"
    "on_pwmModeBox_clicked()\0"
    "on_joystickDevName_currentIndexChanged(QString)\0"
    "on_reopenJsButton_clicked()\0"
    "on_rescanJsButton_clicked()\0msg\0"
    "on_joystickProfileBox_currentIndexChanged(QString)\0"
    "on_enableWatchdogBox_clicked()\0"
    "on_sendCmdButton_clicked()\0"
    "on_startTimingButton_clicked()\0"
    "on_stopButton_clicked()\0"
    "on_sendNumbersButton_clicked()\0"
    "on_sendTestMsg_clicked()\0"
    "gotWirelessMessage(QByteArray)\0"
    "gotMotorStatusUpdate(QByteArray)\0"
    "hadTimeout\0gotWatchdogTimeout(bool)\0"
    "inStrafe\0strafeModeChanged(bool)\0"
    "slowModeButtonToggled()\0sendMessageTimer()\0"
    "timingTimeout()\0gotPassthroughMessage(QByteArray)\0"
    "gotTimeoutData(QByteArray)\0"
    "gotMotorCurrentData(QByteArray)\0count\0"
    "gotRoverDataErrorCount(QByteArray)\0"
    "on_getCurrentButton_clicked()\0"
};

const QMetaObject DriveWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DriveWidget,
      qt_meta_data_DriveWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DriveWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DriveWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DriveWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DriveWidget))
        return static_cast<void*>(const_cast< DriveWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int DriveWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: statusChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: on_maxSpeedSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: on_maxSpeedBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: on_inStrafeModeBox_clicked(); break;
        case 4: on_stallCurrentBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: on_directionDivisorBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: on_useCurveBox_clicked(); break;
        case 7: on_dirScaleBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: on_speedScaleBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: on_pwmModeBox_clicked(); break;
        case 10: on_joystickDevName_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: on_reopenJsButton_clicked(); break;
        case 12: on_rescanJsButton_clicked(); break;
        case 13: on_joystickProfileBox_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: on_enableWatchdogBox_clicked(); break;
        case 15: on_sendCmdButton_clicked(); break;
        case 16: on_startTimingButton_clicked(); break;
        case 17: on_stopButton_clicked(); break;
        case 18: on_sendNumbersButton_clicked(); break;
        case 19: on_sendTestMsg_clicked(); break;
        case 20: gotWirelessMessage((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 21: gotMotorStatusUpdate((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 22: gotWatchdogTimeout((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: strafeModeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: slowModeButtonToggled(); break;
        case 25: sendMessageTimer(); break;
        case 26: timingTimeout(); break;
        case 27: gotPassthroughMessage((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 28: gotTimeoutData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 29: gotMotorCurrentData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 30: gotRoverDataErrorCount((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 32;
    }
    return _id;
}

// SIGNAL 0
void DriveWidget::statusChanged(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
