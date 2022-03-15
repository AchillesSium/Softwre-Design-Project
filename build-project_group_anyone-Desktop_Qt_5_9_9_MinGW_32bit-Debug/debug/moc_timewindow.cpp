/****************************************************************************
** Meta object code from reading C++ file 'timewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../project_group_anyone/timewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TimeWindow_t {
    QByteArrayData data[7];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimeWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimeWindow_t qt_meta_stringdata_TimeWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "TimeWindow"
QT_MOC_LITERAL(1, 11, 9), // "send_pair"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 26), // "std::pair<QString,QString>"
QT_MOC_LITERAL(4, 49, 9), // "time_pair"
QT_MOC_LITERAL(5, 59, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(6, 83, 21) // "on_showButton_clicked"

    },
    "TimeWindow\0send_pair\0\0std::pair<QString,QString>\0"
    "time_pair\0on_cancelButton_clicked\0"
    "on_showButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimeWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   32,    2, 0x08 /* Private */,
       6,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TimeWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TimeWindow *_t = static_cast<TimeWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_pair((*reinterpret_cast< std::pair<QString,QString>(*)>(_a[1]))); break;
        case 1: _t->on_cancelButton_clicked(); break;
        case 2: _t->on_showButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (TimeWindow::*_t)(std::pair<QString,QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TimeWindow::send_pair)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject TimeWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TimeWindow.data,
      qt_meta_data_TimeWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TimeWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimeWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TimeWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int TimeWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void TimeWindow::send_pair(std::pair<QString,QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
