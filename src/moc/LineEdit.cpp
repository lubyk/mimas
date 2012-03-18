/****************************************************************************
** Meta object code from reading C++ file 'LineEdit.h'
**
** Created: Sun Mar 18 14:21:56 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/mimas/LineEdit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LineEdit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LineEdit[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      37,   32,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LineEdit[] = {
    "LineEdit\0\0editingFinishedSlot()\0text\0"
    "textEditedSlot(QString)\0"
};

const QMetaObject LineEdit::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_LineEdit,
      qt_meta_data_LineEdit, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LineEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LineEdit))
        return static_cast<void*>(const_cast< LineEdit*>(this));
    if (!strcmp(_clname, "dub::Thread"))
        return static_cast< dub::Thread*>(const_cast< LineEdit*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int LineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: editingFinishedSlot(); break;
        case 1: textEditedSlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
