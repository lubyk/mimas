/****************************************************************************
** Meta object code from reading C++ file 'Callback.h'
**
** Created: Mon Mar 19 17:15:13 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/mimas/Callback.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Callback.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Callback[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      27,   21,    9,    9, 0x0a,
      44,   21,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Callback[] = {
    "Callback\0\0callback()\0value\0callback(double)\0"
    "callback(int)\0"
};

void Callback::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Callback *_t = static_cast<Callback *>(_o);
        switch (_id) {
        case 0: _t->callback(); break;
        case 1: _t->callback((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->callback((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Callback::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Callback::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Callback,
      qt_meta_data_Callback, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Callback::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Callback::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Callback::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Callback))
        return static_cast<void*>(const_cast< Callback*>(this));
    if (!strcmp(_clname, "dub::Thread"))
        return static_cast< dub::Thread*>(const_cast< Callback*>(this));
    return QObject::qt_metacast(_clname);
}

int Callback::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
