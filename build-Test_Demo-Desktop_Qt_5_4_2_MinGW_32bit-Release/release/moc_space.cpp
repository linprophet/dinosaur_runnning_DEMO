/****************************************************************************
** Meta object code from reading C++ file 'space.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dinosaur_running/space.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'space.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Space_t {
    QByteArrayData data[6];
    char stringdata[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Space_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Space_t qt_meta_stringdata_Space = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Space"
QT_MOC_LITERAL(1, 6, 11), // "slt_newGame"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 14), // "slt_playerDead"
QT_MOC_LITERAL(4, 34, 10), // "slt_updata"
QT_MOC_LITERAL(5, 45, 7) // "slt_del"

    },
    "Space\0slt_newGame\0\0slt_playerDead\0"
    "slt_updata\0slt_del"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Space[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x09 /* Protected */,
       3,    0,   35,    2, 0x09 /* Protected */,
       4,    0,   36,    2, 0x09 /* Protected */,
       5,    0,   37,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Space::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Space *_t = static_cast<Space *>(_o);
        switch (_id) {
        case 0: _t->slt_newGame(); break;
        case 1: _t->slt_playerDead(); break;
        case 2: _t->slt_updata(); break;
        case 3: _t->slt_del(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Space::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_Space.data,
      qt_meta_data_Space,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Space::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Space::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Space.stringdata))
        return static_cast<void*>(const_cast< Space*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int Space::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
