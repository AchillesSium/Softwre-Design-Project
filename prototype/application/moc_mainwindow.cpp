/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../prototype/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[418];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 27), // "on_exit_main_button_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 30), // "on_default_main_button_clicked"
QT_MOC_LITERAL(4, 71, 31), // "on_settings_main_button_clicked"
QT_MOC_LITERAL(5, 103, 25), // "on_compare_button_clicked"
QT_MOC_LITERAL(6, 129, 30), // "on_date_to_main_button_clicked"
QT_MOC_LITERAL(7, 160, 26), // "on_day_main_button_clicked"
QT_MOC_LITERAL(8, 187, 27), // "on_week_main_button_clicked"
QT_MOC_LITERAL(9, 215, 28), // "on_month_main_button_clicked"
QT_MOC_LITERAL(10, 244, 27), // "on_year_main_button_clicked"
QT_MOC_LITERAL(11, 272, 37), // "on_data_main_combo_currentTex..."
QT_MOC_LITERAL(12, 310, 4), // "arg1"
QT_MOC_LITERAL(13, 315, 30), // "on_co2_main_check_stateChanged"
QT_MOC_LITERAL(14, 346, 30), // "on_so2_main_check_stateChanged"
QT_MOC_LITERAL(15, 377, 4), // "arg2"
QT_MOC_LITERAL(16, 382, 30), // "on_nox_main_check_stateChanged"
QT_MOC_LITERAL(17, 413, 4) // "arg3"

    },
    "MainWindow\0on_exit_main_button_clicked\0"
    "\0on_default_main_button_clicked\0"
    "on_settings_main_button_clicked\0"
    "on_compare_button_clicked\0"
    "on_date_to_main_button_clicked\0"
    "on_day_main_button_clicked\0"
    "on_week_main_button_clicked\0"
    "on_month_main_button_clicked\0"
    "on_year_main_button_clicked\0"
    "on_data_main_combo_currentTextChanged\0"
    "arg1\0on_co2_main_check_stateChanged\0"
    "on_so2_main_check_stateChanged\0arg2\0"
    "on_nox_main_check_stateChanged\0arg3"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    1,   88,    2, 0x08 /* Private */,
      13,    1,   91,    2, 0x08 /* Private */,
      14,    1,   94,    2, 0x08 /* Private */,
      16,    1,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   17,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_exit_main_button_clicked(); break;
        case 1: _t->on_default_main_button_clicked(); break;
        case 2: _t->on_settings_main_button_clicked(); break;
        case 3: _t->on_compare_button_clicked(); break;
        case 4: _t->on_date_to_main_button_clicked(); break;
        case 5: _t->on_day_main_button_clicked(); break;
        case 6: _t->on_week_main_button_clicked(); break;
        case 7: _t->on_month_main_button_clicked(); break;
        case 8: _t->on_year_main_button_clicked(); break;
        case 9: _t->on_data_main_combo_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_co2_main_check_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_so2_main_check_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_nox_main_check_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
