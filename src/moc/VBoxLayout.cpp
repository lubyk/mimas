/****************************************************************************
** Meta object code from reading C++ file 'VBoxLayout.h'
**
** Created: Mon Mar 19 15:52:52 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/mimas/VBoxLayout.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VBoxLayout.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VBoxLayout[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_VBoxLayout[] = {
    "VBoxLayout\0"
};

const QMetaObject VBoxLayout::staticMetaObject = {
    { &QVBoxLayout::staticMetaObject, qt_meta_stringdata_VBoxLayout,
      qt_meta_data_VBoxLayout, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VBoxLayout::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VBoxLayout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VBoxLayout::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VBoxLayout))
        return static_cast<void*>(const_cast< VBoxLayout*>(this));
    if (!strcmp(_clname, "dub::Thread"))
        return static_cast< dub::Thread*>(const_cast< VBoxLayout*>(this));
    return QVBoxLayout::qt_metacast(_clname);
}

int VBoxLayout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QVBoxLayout::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
