/****************************************************************************
** Meta object code from reading C++ file 'questionsmenu.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "headers/questionsmenu.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'questionsmenu.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QuestionsMenu_t {
    QByteArrayData data[10];
    char stringdata0[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QuestionsMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QuestionsMenu_t qt_meta_stringdata_QuestionsMenu = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QuestionsMenu"
QT_MOC_LITERAL(1, 14, 35), // "on_tableWidget_Question_cellC..."
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 3), // "row"
QT_MOC_LITERAL(4, 55, 28), // "on_pushButton_delete_clicked"
QT_MOC_LITERAL(5, 84, 25), // "on_pushButton_set_clicked"
QT_MOC_LITERAL(6, 110, 25), // "on_pushButton_add_clicked"
QT_MOC_LITERAL(7, 136, 26), // "on_pushButton_look_clicked"
QT_MOC_LITERAL(8, 163, 29), // "on_pushButton_disable_clicked"
QT_MOC_LITERAL(9, 193, 28) // "on_pushButton_return_clicked"

    },
    "QuestionsMenu\0on_tableWidget_Question_cellClicked\0"
    "\0row\0on_pushButton_delete_clicked\0"
    "on_pushButton_set_clicked\0"
    "on_pushButton_add_clicked\0"
    "on_pushButton_look_clicked\0"
    "on_pushButton_disable_clicked\0"
    "on_pushButton_return_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QuestionsMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       4,    0,   52,    2, 0x08 /* Private */,
       5,    0,   53,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QuestionsMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QuestionsMenu *_t = static_cast<QuestionsMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_tableWidget_Question_cellClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_delete_clicked(); break;
        case 2: _t->on_pushButton_set_clicked(); break;
        case 3: _t->on_pushButton_add_clicked(); break;
        case 4: _t->on_pushButton_look_clicked(); break;
        case 5: _t->on_pushButton_disable_clicked(); break;
        case 6: _t->on_pushButton_return_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject QuestionsMenu::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QuestionsMenu.data,
      qt_meta_data_QuestionsMenu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QuestionsMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QuestionsMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QuestionsMenu.stringdata0))
        return static_cast<void*>(const_cast< QuestionsMenu*>(this));
    return QDialog::qt_metacast(_clname);
}

int QuestionsMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
