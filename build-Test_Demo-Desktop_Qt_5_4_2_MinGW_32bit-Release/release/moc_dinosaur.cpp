/****************************************************************************
** Meta object code from reading C++ file 'dinosaur.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dinosaur_running/dinosaur.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dinosaur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_dinosaur_t {
    QByteArrayData data[10];
    char stringdata[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dinosaur_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dinosaur_t qt_meta_stringdata_dinosaur = {
    {
QT_MOC_LITERAL(0, 0, 8), // "dinosaur"
QT_MOC_LITERAL(1, 9, 4), // "dead"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 5), // "upkey"
QT_MOC_LITERAL(4, 21, 7), // "downkey"
QT_MOC_LITERAL(5, 29, 10), // "releasekey"
QT_MOC_LITERAL(6, 40, 4), // "delt"
QT_MOC_LITERAL(7, 45, 9), // "slt_s1_in"
QT_MOC_LITERAL(8, 55, 9), // "slt_s2_in"
QT_MOC_LITERAL(9, 65, 9) // "slt_s3_in"

    },
    "dinosaur\0dead\0\0upkey\0downkey\0releasekey\0"
    "delt\0slt_s1_in\0slt_s2_in\0slt_s3_in"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dinosaur[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,
       6,    0,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   59,    2, 0x09 /* Protected */,
       8,    0,   60,    2, 0x09 /* Protected */,
       9,    0,   61,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void dinosaur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        dinosaur *_t = static_cast<dinosaur *>(_o);
        switch (_id) {
        case 0: _t->dead(); break;
        case 1: _t->upkey(); break;
        case 2: _t->downkey(); break;
        case 3: _t->releasekey(); break;
        case 4: _t->delt(); break;
        case 5: _t->slt_s1_in(); break;
        case 6: _t->slt_s2_in(); break;
        case 7: _t->slt_s3_in(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (dinosaur::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dinosaur::dead)) {
                *result = 0;
            }
        }
        {
            typedef void (dinosaur::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dinosaur::upkey)) {
                *result = 1;
            }
        }
        {
            typedef void (dinosaur::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dinosaur::downkey)) {
                *result = 2;
            }
        }
        {
            typedef void (dinosaur::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dinosaur::releasekey)) {
                *result = 3;
            }
        }
        {
            typedef void (dinosaur::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&dinosaur::delt)) {
                *result = 4;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject dinosaur::staticMetaObject = {
    { &QGraphicsObject::staticMetaObject, qt_meta_stringdata_dinosaur.data,
      qt_meta_data_dinosaur,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *dinosaur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dinosaur::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_dinosaur.stringdata))
        return static_cast<void*>(const_cast< dinosaur*>(this));
    return QGraphicsObject::qt_metacast(_clname);
}

int dinosaur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void dinosaur::dead()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void dinosaur::upkey()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void dinosaur::downkey()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void dinosaur::releasekey()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void dinosaur::delt()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
