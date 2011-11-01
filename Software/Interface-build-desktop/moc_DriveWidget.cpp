/****************************************************************************
** Meta object code from reading C++ file 'DriveWidget.h'
**
** Created: Sun Oct 9 13:53:03 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Interface/GUI/DriveWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DriveWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DriveWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   13,   12,   12, 0x08,
      55,   12,   12,   12, 0x08,
      91,   12,   12,   12, 0x08,
     120,   12,   12,   12, 0x08,
     160,   12,   12,   12, 0x08,
     204,   12,   12,   12, 0x08,
     229,   12,   12,   12, 0x08,
     265,   12,   12,   12, 0x08,
     303,   12,   12,   12, 0x08,
     327,   12,   12,   12, 0x08,
     375,   12,   12,   12, 0x08,
     403,   12,   12,   12, 0x08,
     435,  431,   12,   12, 0x08,
     486,   12,   12,   12, 0x08,
     517,   12,   12,   12, 0x08,
     544,   12,   12,   12, 0x08,
     575,   12,   12,   12, 0x08,
     599,   12,   12,   12, 0x08,
     630,   12,   12,   12, 0x08,
     655,  431,   12,   12, 0x08,
     686,  431,   12,   12, 0x08,
     730,  719,   12,   12, 0x08,
     764,  755,   12,   12, 0x08,
     788,   12,   12,   12, 0x08,
     812,   12,   12,   12, 0x08,
     831,   12,   12,   12, 0x08,
     847,  431,   12,   12, 0x08,
     881,  431,   12,   12, 0x08,
     908,  431,   12,   12, 0x08,
     946,  940,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DriveWidget[] = {
    "DriveWidget\0\0value\0"
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
        case 0: on_maxSpeedSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: on_maxSpeedBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: on_inStrafeModeBox_clicked(); break;
        case 3: on_stallCurrentBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: on_directionDivisorBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: on_useCurveBox_clicked(); break;
        case 6: on_dirScaleBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: on_speedScaleBox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: on_pwmModeBox_clicked(); break;
        case 9: on_joystickDevName_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: on_reopenJsButton_clicked(); break;
        case 11: on_rescanJsButton_clicked(); break;
        case 12: on_joystickProfileBox_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: on_enableWatchdogBox_clicked(); break;
        case 14: on_sendCmdButton_clicked(); break;
        case 15: on_startTimingButton_clicked(); break;
        case 16: on_stopButton_clicked(); break;
        case 17: on_sendNumbersButton_clicked(); break;
        case 18: on_sendTestMsg_clicked(); break;
        case 19: gotWirelessMessage((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 20: gotMotorStatusUpdate((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 21: gotWatchdogTimeout((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: strafeModeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: slowModeButtonToggled(); break;
        case 24: sendMessageTimer(); break;
        case 25: timingTimeout(); break;
        case 26: gotPassthroughMessage((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 27: gotTimeoutData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 28: gotMotorCurrentData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 29: gotRoverDataErrorCount((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 30;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
