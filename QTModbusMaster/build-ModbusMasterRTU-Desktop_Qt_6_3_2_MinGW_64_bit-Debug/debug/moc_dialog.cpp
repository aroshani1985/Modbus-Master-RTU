/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ModbusMasterRTU/dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dialog_t {
    uint offsetsAndSizes[26];
    char stringdata0[7];
    char stringdata1[24];
    char stringdata2[1];
    char stringdata3[23];
    char stringdata4[26];
    char stringdata5[31];
    char stringdata6[6];
    char stringdata7[25];
    char stringdata8[14];
    char stringdata9[25];
    char stringdata10[17];
    char stringdata11[25];
    char stringdata12[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Dialog_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_Dialog_t qt_meta_stringdata_Dialog = {
    {
        QT_MOC_LITERAL(0, 6),  // "Dialog"
        QT_MOC_LITERAL(7, 23),  // "on_btn_find_spx_clicked"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 22),  // "on_btn_connect_clicked"
        QT_MOC_LITERAL(55, 25),  // "on_btn_disconnect_clicked"
        QT_MOC_LITERAL(81, 30),  // "on_cbx_spx_currentIndexChanged"
        QT_MOC_LITERAL(112, 5),  // "index"
        QT_MOC_LITERAL(118, 24),  // "on_btn_send_test_clicked"
        QT_MOC_LITERAL(143, 13),  // "on_sp_receive"
        QT_MOC_LITERAL(157, 24),  // "on_btn_clear_txt_clicked"
        QT_MOC_LITERAL(182, 16),  // "on_sp_timer_tick"
        QT_MOC_LITERAL(199, 24),  // "on_checkBox_stateChanged"
        QT_MOC_LITERAL(224, 4)   // "arg1"
    },
    "Dialog",
    "on_btn_find_spx_clicked",
    "",
    "on_btn_connect_clicked",
    "on_btn_disconnect_clicked",
    "on_cbx_spx_currentIndexChanged",
    "index",
    "on_btn_send_test_clicked",
    "on_sp_receive",
    "on_btn_clear_txt_clicked",
    "on_sp_timer_tick",
    "on_checkBox_stateChanged",
    "arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x08,    1 /* Private */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    0,   70,    2, 0x08,    3 /* Private */,
       5,    1,   71,    2, 0x08,    4 /* Private */,
       7,    0,   74,    2, 0x08,    6 /* Private */,
       8,    0,   75,    2, 0x08,    7 /* Private */,
       9,    0,   76,    2, 0x08,    8 /* Private */,
      10,    0,   77,    2, 0x08,    9 /* Private */,
      11,    1,   78,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btn_find_spx_clicked(); break;
        case 1: _t->on_btn_connect_clicked(); break;
        case 2: _t->on_btn_disconnect_clicked(); break;
        case 3: _t->on_cbx_spx_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_btn_send_test_clicked(); break;
        case 5: _t->on_sp_receive(); break;
        case 6: _t->on_btn_clear_txt_clicked(); break;
        case 7: _t->on_sp_timer_tick(); break;
        case 8: _t->on_checkBox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Dialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Dialog.offsetsAndSizes,
    qt_meta_data_Dialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Dialog_t
, QtPrivate::TypeAndForceComplete<Dialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
