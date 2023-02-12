/****************************************************************************
** Meta object code from reading C++ file 'wid_friends_list.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../wid_friends_list.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wid_friends_list.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_wid_friends_list_t {
    QByteArrayData data[8];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_wid_friends_list_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_wid_friends_list_t qt_meta_stringdata_wid_friends_list = {
    {
QT_MOC_LITERAL(0, 0, 16), // "wid_friends_list"
QT_MOC_LITERAL(1, 17, 12), // "fa_send_news"
QT_MOC_LITERAL(2, 30, 4), // "emit"
QT_MOC_LITERAL(3, 35, 7), // "en_info"
QT_MOC_LITERAL(4, 43, 2), // "en"
QT_MOC_LITERAL(5, 46, 7), // "account"
QT_MOC_LITERAL(6, 54, 6), // "string"
QT_MOC_LITERAL(7, 61, 3) // "txt"

    },
    "wid_friends_list\0fa_send_news\0emit\0"
    "en_info\0en\0account\0string\0txt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_wid_friends_list[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::LongLong, 0x80000000 | 6,    4,    5,    7,

       0        // eod
};

void wid_friends_list::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<wid_friends_list *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fa_send_news((*reinterpret_cast< en_info(*)>(_a[1])),(*reinterpret_cast< long long(*)>(_a[2])),(*reinterpret_cast< string(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (wid_friends_list::*)(en_info , long long , string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&wid_friends_list::fa_send_news)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject wid_friends_list::staticMetaObject = { {
    QMetaObject::SuperData::link<wid_change::staticMetaObject>(),
    qt_meta_stringdata_wid_friends_list.data,
    qt_meta_data_wid_friends_list,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *wid_friends_list::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *wid_friends_list::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_wid_friends_list.stringdata0))
        return static_cast<void*>(this);
    return wid_change::qt_metacast(_clname);
}

int wid_friends_list::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = wid_change::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void wid_friends_list::fa_send_news(en_info _t1, long long _t2, string _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
