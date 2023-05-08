/****************************************************************************
** Meta object code from reading C++ file 'wid_login.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../wid_login.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wid_login.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_wid_login_t {
    QByteArrayData data[8];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_wid_login_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_wid_login_t qt_meta_stringdata_wid_login = {
    {
QT_MOC_LITERAL(0, 0, 9), // "wid_login"
QT_MOC_LITERAL(1, 10, 8), // "fa_login"
QT_MOC_LITERAL(2, 19, 4), // "emit"
QT_MOC_LITERAL(3, 24, 7), // "account"
QT_MOC_LITERAL(4, 32, 6), // "passwd"
QT_MOC_LITERAL(5, 39, 11), // "fa_register"
QT_MOC_LITERAL(6, 51, 4), // "name"
QT_MOC_LITERAL(7, 56, 7) // "fa_back"

    },
    "wid_login\0fa_login\0emit\0account\0passwd\0"
    "fa_register\0name\0fa_back"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_wid_login[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       5,    2,   34,    2, 0x06 /* Public */,
       7,    0,   39,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    4,
    QMetaType::Void,

       0        // eod
};

void wid_login::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<wid_login *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fa_login((*reinterpret_cast< long long(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->fa_register((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->fa_back(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (wid_login::*)(long long , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&wid_login::fa_login)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (wid_login::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&wid_login::fa_register)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (wid_login::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&wid_login::fa_back)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject wid_login::staticMetaObject = { {
    QMetaObject::SuperData::link<wid_change::staticMetaObject>(),
    qt_meta_stringdata_wid_login.data,
    qt_meta_data_wid_login,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *wid_login::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *wid_login::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_wid_login.stringdata0))
        return static_cast<void*>(this);
    return wid_change::qt_metacast(_clname);
}

int wid_login::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = wid_change::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void wid_login::fa_login(long long _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void wid_login::fa_register(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void wid_login::fa_back()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
