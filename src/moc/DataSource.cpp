/****************************************************************************
** Meta object code from reading C++ file 'DataSource.h'
**
** Created: Mon Mar 19 15:52:51 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/mimas/DataSource.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DataSource.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DataSource[] = {

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

static const char qt_meta_stringdata_DataSource[] = {
    "DataSource\0"
};

const QMetaObject DataSource::staticMetaObject = {
    { &QAbstractItemModel::staticMetaObject, qt_meta_stringdata_DataSource,
      qt_meta_data_DataSource, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DataSource::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DataSource::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DataSource::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DataSource))
        return static_cast<void*>(const_cast< DataSource*>(this));
    if (!strcmp(_clname, "dub::Thread"))
        return static_cast< dub::Thread*>(const_cast< DataSource*>(this));
    return QAbstractItemModel::qt_metacast(_clname);
}

int DataSource::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
