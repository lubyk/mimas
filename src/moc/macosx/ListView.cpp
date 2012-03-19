/****************************************************************************
** Meta object code from reading C++ file 'ListView.h'
**
** Created: Mon Mar 19 17:15:13 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/mimas/ListView.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ListView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ListView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   10,    9,    9, 0x08,
      45,   10,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ListView[] = {
    "ListView\0\0action\0sliderVActionTriggered(int)\0"
    "sliderHActionTriggered(int)\0"
};

void ListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ListView *_t = static_cast<ListView *>(_o);
        switch (_id) {
        case 0: _t->sliderVActionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sliderHActionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ListView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ListView::staticMetaObject = {
    { &QListView::staticMetaObject, qt_meta_stringdata_ListView,
      qt_meta_data_ListView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ListView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ListView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ListView))
        return static_cast<void*>(const_cast< ListView*>(this));
    if (!strcmp(_clname, "dub::Thread"))
        return static_cast< dub::Thread*>(const_cast< ListView*>(this));
    return QListView::qt_metacast(_clname);
}

int ListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
