/****************************************************************************
** Meta object code from reading C++ file 'mainmenu.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "headers/mainmenu.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainmenu.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainMenu_t {
    QByteArrayData data[13];
    char stringdata0[339];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainMenu_t qt_meta_stringdata_MainMenu = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MainMenu"
QT_MOC_LITERAL(1, 9, 31), // "on_tableWidget_User_cellClicked"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 3), // "row"
QT_MOC_LITERAL(4, 46, 30), // "on_pushButton_set_user_clicked"
QT_MOC_LITERAL(5, 77, 33), // "on_pushButton_delete_user_cli..."
QT_MOC_LITERAL(6, 111, 32), // "on_tableWidget_Topic_cellClicked"
QT_MOC_LITERAL(7, 144, 31), // "on_pushButton_set_topic_clicked"
QT_MOC_LITERAL(8, 176, 34), // "on_pushButton_delete_topic_cl..."
QT_MOC_LITERAL(9, 211, 31), // "on_pushButton_add_topic_clicked"
QT_MOC_LITERAL(10, 243, 32), // "on_pushButton_look_topic_clicked"
QT_MOC_LITERAL(11, 276, 32), // "on_pushButton_disconnect_clicked"
QT_MOC_LITERAL(12, 309, 29) // "on_pushButton_refresh_clicked"

    },
    "MainMenu\0on_tableWidget_User_cellClicked\0"
    "\0row\0on_pushButton_set_user_clicked\0"
    "on_pushButton_delete_user_clicked\0"
    "on_tableWidget_Topic_cellClicked\0"
    "on_pushButton_set_topic_clicked\0"
    "on_pushButton_delete_topic_clicked\0"
    "on_pushButton_add_topic_clicked\0"
    "on_pushButton_look_topic_clicked\0"
    "on_pushButton_disconnect_clicked\0"
    "on_pushButton_refresh_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x08 /* Private */,
       4,    0,   67,    2, 0x08 /* Private */,
       5,    0,   68,    2, 0x08 /* Private */,
       6,    1,   69,    2, 0x08 /* Private */,
       7,    0,   72,    2, 0x08 /* Private */,
       8,    0,   73,    2, 0x08 /* Private */,
       9,    0,   74,    2, 0x08 /* Private */,
      10,    0,   75,    2, 0x08 /* Private */,
      11,    0,   76,    2, 0x08 /* Private */,
      12,    0,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainMenu *_t = static_cast<MainMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_tableWidget_User_cellClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_set_user_clicked(); break;
        case 2: _t->on_pushButton_delete_user_clicked(); break;
        case 3: _t->on_tableWidget_Topic_cellClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_set_topic_clicked(); break;
        case 5: _t->on_pushButton_delete_topic_clicked(); break;
        case 6: _t->on_pushButton_add_topic_clicked(); break;
        case 7: _t->on_pushButton_look_topic_clicked(); break;
        case 8: _t->on_pushButton_disconnect_clicked(); break;
        case 9: _t->on_pushButton_refresh_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainMenu::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MainMenu.data,
      qt_meta_data_MainMenu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainMenu.stringdata0))
        return static_cast<void*>(const_cast< MainMenu*>(this));
    return QDialog::qt_metacast(_clname);
}

int MainMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
