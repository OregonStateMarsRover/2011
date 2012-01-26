/****************************************************************************
** Meta object code from reading C++ file 'ArmGLWidget.h'
**
** Created: Tue Jan 24 21:44:07 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GUI/ArmGLWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ArmGLWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ArmGLWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   13,   12,   12, 0x0a,
      52,   13,   12,   12, 0x0a,
      84,   13,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ArmGLWidget[] = {
    "ArmGLWidget\0\0angles\0newArmPositions(ArmWristAngles)\0"
    "newArmPositions(ArmAstroAngles)\0"
    "newArmPositions(ArmShovelAngles)\0"
};

const QMetaObject ArmGLWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_ArmGLWidget,
      qt_meta_data_ArmGLWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ArmGLWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ArmGLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ArmGLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ArmGLWidget))
        return static_cast<void*>(const_cast< ArmGLWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int ArmGLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: newArmPositions((*reinterpret_cast< ArmWristAngles(*)>(_a[1]))); break;
        case 1: newArmPositions((*reinterpret_cast< ArmAstroAngles(*)>(_a[1]))); break;
        case 2: newArmPositions((*reinterpret_cast< ArmShovelAngles(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
