/****************************************************************************
** Meta object code from reading C++ file 'ArmWidget.h'
**
** Created: Tue Jan 24 21:43:56 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GUI/ArmWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ArmWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ArmWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      28,   11,   10,   10, 0x0a,
      72,   68,   10,   10, 0x0a,
      98,   10,   10,   10, 0x08,
     122,   10,   10,   10, 0x08,
     148,   10,   10,   10, 0x08,
     165,   10,   10,   10, 0x08,
     197,   10,   10,   10, 0x08,
     221,   10,   10,   10, 0x08,
     256,   10,   10,   10, 0x08,
     293,   10,   10,   10, 0x08,
     325,   10,   10,   10, 0x08,
     350,   10,   10,   10, 0x08,
     384,  377,   10,   10, 0x08,
     420,  377,   10,   10, 0x08,
     461,  377,   10,   10, 0x08,
     500,   10,   10,   10, 0x08,
     517,   10,   10,   10, 0x08,
     535,  533,   10,   10, 0x08,
     554,  533,   10,   10, 0x08,
     578,  533,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ArmWidget[] = {
    "ArmWidget\0\0angles,distances\0"
    "newArmPositions(ArmAngles,ArmDistances)\0"
    "dat\0newArmCommand(QByteArray)\0"
    "on_resetServo_clicked()\0"
    "on_zoomInButton_clicked()\0on_Run_clicked()\0"
    "on_getArmConfigButton_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_cameraTiltBox_valueChanged(int)\0"
    "on_cameraRotateBox_valueChanged(int)\0"
    "on_gripperBox_valueChanged(int)\0"
    "on_clearButton_clicked()\0"
    "on_sendCmdButton_clicked()\0newPos\0"
    "setActualGripperPos(unsigned short)\0"
    "setActualCameraRotatePos(unsigned short)\0"
    "setActualCameraTiltPos(unsigned short)\0"
    "gotGlobalError()\0gotSlaveError()\0s\0"
    "logAppend(QString)\0statusBox1Text(QString)\0"
    "statusBox2Text(QString)\0"
};

const QMetaObject ArmWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ArmWidget,
      qt_meta_data_ArmWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ArmWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ArmWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ArmWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ArmWidget))
        return static_cast<void*>(const_cast< ArmWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ArmWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newArmPositions((*reinterpret_cast< ArmAngles(*)>(_a[1])),(*reinterpret_cast< ArmDistances(*)>(_a[2]))); break;
        case 1: newArmCommand((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: on_resetServo_clicked(); break;
        case 3: on_zoomInButton_clicked(); break;
        case 4: on_Run_clicked(); break;
        case 5: on_getArmConfigButton_clicked(); break;
        case 6: on_pushButton_clicked(); break;
        case 7: on_cameraTiltBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: on_cameraRotateBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: on_gripperBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: on_clearButton_clicked(); break;
        case 11: on_sendCmdButton_clicked(); break;
        case 12: setActualGripperPos((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 13: setActualCameraRotatePos((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 14: setActualCameraTiltPos((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 15: gotGlobalError(); break;
        case 16: gotSlaveError(); break;
        case 17: logAppend((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: statusBox1Text((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: statusBox2Text((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
