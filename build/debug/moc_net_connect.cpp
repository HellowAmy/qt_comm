/****************************************************************************
** Meta object code from reading C++ file 'net_connect.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../ms_comm/ms_comm_client/net_connect.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'net_connect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_net_connect_t {
    QByteArrayData data[33];
    char stringdata0[385];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_net_connect_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_net_connect_t qt_meta_stringdata_net_connect = {
    {
QT_MOC_LITERAL(0, 0, 11), // "net_connect"
QT_MOC_LITERAL(1, 12, 7), // "fa_open"
QT_MOC_LITERAL(2, 20, 4), // "emit"
QT_MOC_LITERAL(3, 25, 8), // "fa_close"
QT_MOC_LITERAL(4, 34, 16), // "fa_register_back"
QT_MOC_LITERAL(5, 51, 7), // "account"
QT_MOC_LITERAL(6, 59, 6), // "passwd"
QT_MOC_LITERAL(7, 66, 2), // "ok"
QT_MOC_LITERAL(8, 69, 13), // "fa_login_back"
QT_MOC_LITERAL(9, 83, 14), // "fa_logout_back"
QT_MOC_LITERAL(10, 98, 22), // "fa_recover_passwd_back"
QT_MOC_LITERAL(11, 121, 20), // "fa_friends_list_back"
QT_MOC_LITERAL(12, 142, 22), // "QMap<long long,string>"
QT_MOC_LITERAL(13, 165, 3), // "map"
QT_MOC_LITERAL(14, 169, 15), // "fa_add_ret_back"
QT_MOC_LITERAL(15, 185, 4), // "self"
QT_MOC_LITERAL(16, 190, 11), // "fa_swap_txt"
QT_MOC_LITERAL(17, 202, 12), // "account_from"
QT_MOC_LITERAL(18, 215, 3), // "txt"
QT_MOC_LITERAL(19, 219, 18), // "fa_swap_add_friend"
QT_MOC_LITERAL(20, 238, 13), // "fa_swap_build"
QT_MOC_LITERAL(21, 252, 8), // "filename"
QT_MOC_LITERAL(22, 261, 13), // "en_build_file"
QT_MOC_LITERAL(23, 275, 4), // "type"
QT_MOC_LITERAL(24, 280, 19), // "fa_swap_file_finish"
QT_MOC_LITERAL(25, 300, 5), // "is_ok"
QT_MOC_LITERAL(26, 306, 16), // "fa_swap_file_ret"
QT_MOC_LITERAL(27, 323, 13), // "fa_swap_error"
QT_MOC_LITERAL(28, 337, 13), // "en_swap_error"
QT_MOC_LITERAL(29, 351, 3), // "err"
QT_MOC_LITERAL(30, 355, 12), // "fa_prog_send"
QT_MOC_LITERAL(31, 368, 3), // "now"
QT_MOC_LITERAL(32, 372, 12) // "fa_prog_recv"

    },
    "net_connect\0fa_open\0emit\0fa_close\0"
    "fa_register_back\0account\0passwd\0ok\0"
    "fa_login_back\0fa_logout_back\0"
    "fa_recover_passwd_back\0fa_friends_list_back\0"
    "QMap<long long,string>\0map\0fa_add_ret_back\0"
    "self\0fa_swap_txt\0account_from\0txt\0"
    "fa_swap_add_friend\0fa_swap_build\0"
    "filename\0en_build_file\0type\0"
    "fa_swap_file_finish\0is_ok\0fa_swap_file_ret\0"
    "fa_swap_error\0en_swap_error\0err\0"
    "fa_prog_send\0now\0fa_prog_recv"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_net_connect[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      16,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    0,   95,    2, 0x06 /* Public */,
       4,    3,   96,    2, 0x06 /* Public */,
       8,    2,  103,    2, 0x06 /* Public */,
       9,    2,  108,    2, 0x06 /* Public */,
      10,    3,  113,    2, 0x06 /* Public */,
      11,    1,  120,    2, 0x06 /* Public */,
      14,    3,  123,    2, 0x06 /* Public */,
      16,    2,  130,    2, 0x06 /* Public */,
      19,    1,  135,    2, 0x06 /* Public */,
      20,    3,  138,    2, 0x06 /* Public */,
      24,    4,  145,    2, 0x06 /* Public */,
      26,    4,  154,    2, 0x06 /* Public */,
      27,    2,  163,    2, 0x06 /* Public */,
      30,    3,  168,    2, 0x06 /* Public */,
      32,    3,  175,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::QString, QMetaType::Bool,    5,    6,    7,
    QMetaType::Void, QMetaType::LongLong, QMetaType::Bool,    5,    7,
    QMetaType::Void, QMetaType::LongLong, QMetaType::Bool,    5,    7,
    QMetaType::Void, QMetaType::LongLong, QMetaType::QString, QMetaType::Bool,    5,    6,    7,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::LongLong, QMetaType::Bool, QMetaType::Bool,    5,    7,   15,
    QMetaType::Void, QMetaType::LongLong, QMetaType::QString,   17,   18,
    QMetaType::Void, QMetaType::LongLong,   17,
    QMetaType::Void, QMetaType::LongLong, QMetaType::QString, 0x80000000 | 22,   17,   21,   23,
    QMetaType::Void, QMetaType::LongLong, QMetaType::QString, 0x80000000 | 22, QMetaType::Bool,   17,   21,   23,   25,
    QMetaType::Void, QMetaType::LongLong, QMetaType::QString, 0x80000000 | 22, QMetaType::Bool,   17,   21,   23,   25,
    QMetaType::Void, QMetaType::LongLong, 0x80000000 | 28,   17,   29,
    QMetaType::Void, QMetaType::QString, QMetaType::LongLong, QMetaType::Int,   21,   17,   31,
    QMetaType::Void, QMetaType::QString, QMetaType::LongLong, QMetaType::Int,   21,   17,   31,

       0        // eod
};

void net_connect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<net_connect *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fa_open(); break;
        case 1: _t->fa_close(); break;
        case 2: _t->fa_register_back((*reinterpret_cast< long long(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 3: _t->fa_login_back((*reinterpret_cast< long long(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->fa_logout_back((*reinterpret_cast< long long(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->fa_recover_passwd_back((*reinterpret_cast< long long(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 6: _t->fa_friends_list_back((*reinterpret_cast< QMap<long long,string>(*)>(_a[1]))); break;
        case 7: _t->fa_add_ret_back((*reinterpret_cast< long long(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 8: _t->fa_swap_txt((*reinterpret_cast< long long(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->fa_swap_add_friend((*reinterpret_cast< long long(*)>(_a[1]))); break;
        case 10: _t->fa_swap_build((*reinterpret_cast< long long(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< en_build_file(*)>(_a[3]))); break;
        case 11: _t->fa_swap_file_finish((*reinterpret_cast< long long(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< en_build_file(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 12: _t->fa_swap_file_ret((*reinterpret_cast< long long(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< en_build_file(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 13: _t->fa_swap_error((*reinterpret_cast< long long(*)>(_a[1])),(*reinterpret_cast< en_swap_error(*)>(_a[2]))); break;
        case 14: _t->fa_prog_send((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< long long(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 15: _t->fa_prog_recv((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< long long(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (net_connect::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&net_connect::fa_open)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (net_connect::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&net_connect::fa_close)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (net_connect::*)(long long , QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&net_connect::fa_register_back)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (net_connect::*)(long long , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&net_connect::fa_login_back)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (net_connect::*)(long long , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&net_connect::fa_logout_back)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (net_connect::*)(long long , QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&net_connect::fa_recover_passwd_back)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (net_connect::*)(QMap<long long,string> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&net_connect::fa_friends_list_back)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (net_connect::*)(long long , bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&net_connect::fa_add_ret_back)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (net_connect::*)(long long , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&net_connect::fa_swap_txt)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (net_connect::*)(long long );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&net_connect::fa_swap_add_friend)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (net_connect::*)(long long , QString , en_build_file );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&net_connect::fa_swap_build)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (net_connect::*)(long long , QString , en_build_file , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&net_connect::fa_swap_file_finish)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (net_connect::*)(long long , QString , en_build_file , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&net_connect::fa_swap_file_ret)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (net_connect::*)(long long , en_swap_error );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&net_connect::fa_swap_error)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (net_connect::*)(QString , long long , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&net_connect::fa_prog_send)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (net_connect::*)(QString , long long , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&net_connect::fa_prog_recv)) {
                *result = 15;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject net_connect::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_net_connect.data,
    qt_meta_data_net_connect,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *net_connect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *net_connect::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_net_connect.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int net_connect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void net_connect::fa_open()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void net_connect::fa_close()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void net_connect::fa_register_back(long long _t1, QString _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void net_connect::fa_login_back(long long _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void net_connect::fa_logout_back(long long _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void net_connect::fa_recover_passwd_back(long long _t1, QString _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void net_connect::fa_friends_list_back(QMap<long long,string> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void net_connect::fa_add_ret_back(long long _t1, bool _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void net_connect::fa_swap_txt(long long _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void net_connect::fa_swap_add_friend(long long _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void net_connect::fa_swap_build(long long _t1, QString _t2, en_build_file _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void net_connect::fa_swap_file_finish(long long _t1, QString _t2, en_build_file _t3, bool _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void net_connect::fa_swap_file_ret(long long _t1, QString _t2, en_build_file _t3, bool _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void net_connect::fa_swap_error(long long _t1, en_swap_error _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void net_connect::fa_prog_send(QString _t1, long long _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void net_connect::fa_prog_recv(QString _t1, long long _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
