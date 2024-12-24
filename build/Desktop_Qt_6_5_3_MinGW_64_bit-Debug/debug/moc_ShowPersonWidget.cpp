/****************************************************************************
** Meta object code from reading C++ file 'ShowPersonWidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ShowPersonWidget.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ShowPersonWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSShowPersonWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSShowPersonWidgetENDCLASS = QtMocHelpers::stringData(
    "ShowPersonWidget",
    "on_pushButton_released",
    "",
    "on_pushButton_2_released",
    "on_ItemButton_released",
    "on_returnButton_released"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSShowPersonWidgetENDCLASS_t {
    uint offsetsAndSizes[12];
    char stringdata0[17];
    char stringdata1[23];
    char stringdata2[1];
    char stringdata3[25];
    char stringdata4[23];
    char stringdata5[25];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSShowPersonWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSShowPersonWidgetENDCLASS_t qt_meta_stringdata_CLASSShowPersonWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "ShowPersonWidget"
        QT_MOC_LITERAL(17, 22),  // "on_pushButton_released"
        QT_MOC_LITERAL(40, 0),  // ""
        QT_MOC_LITERAL(41, 24),  // "on_pushButton_2_released"
        QT_MOC_LITERAL(66, 22),  // "on_ItemButton_released"
        QT_MOC_LITERAL(89, 24)   // "on_returnButton_released"
    },
    "ShowPersonWidget",
    "on_pushButton_released",
    "",
    "on_pushButton_2_released",
    "on_ItemButton_released",
    "on_returnButton_released"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSShowPersonWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x08,    1 /* Private */,
       3,    0,   39,    2, 0x08,    2 /* Private */,
       4,    0,   40,    2, 0x08,    3 /* Private */,
       5,    0,   41,    2, 0x08,    4 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ShowPersonWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSShowPersonWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSShowPersonWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSShowPersonWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ShowPersonWidget, std::true_type>,
        // method 'on_pushButton_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_2_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ItemButton_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_returnButton_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ShowPersonWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ShowPersonWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_released(); break;
        case 1: _t->on_pushButton_2_released(); break;
        case 2: _t->on_ItemButton_released(); break;
        case 3: _t->on_returnButton_released(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *ShowPersonWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShowPersonWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSShowPersonWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ShowPersonWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
