/****************************************************************************
** Meta object code from reading C++ file 'ManageWidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../ManageWidget.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ManageWidget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSManageWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSManageWidgetENDCLASS = QtMocHelpers::stringData(
    "ManageWidget",
    "on_CancleButton_released",
    "",
    "on_AddButton_released",
    "on_SaveButton_released",
    "on_DeleteButton_released",
    "on_SearchPersonButton_released"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSManageWidgetENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[13];
    char stringdata1[25];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[23];
    char stringdata5[25];
    char stringdata6[31];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSManageWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSManageWidgetENDCLASS_t qt_meta_stringdata_CLASSManageWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "ManageWidget"
        QT_MOC_LITERAL(13, 24),  // "on_CancleButton_released"
        QT_MOC_LITERAL(38, 0),  // ""
        QT_MOC_LITERAL(39, 21),  // "on_AddButton_released"
        QT_MOC_LITERAL(61, 22),  // "on_SaveButton_released"
        QT_MOC_LITERAL(84, 24),  // "on_DeleteButton_released"
        QT_MOC_LITERAL(109, 30)   // "on_SearchPersonButton_released"
    },
    "ManageWidget",
    "on_CancleButton_released",
    "",
    "on_AddButton_released",
    "on_SaveButton_released",
    "on_DeleteButton_released",
    "on_SearchPersonButton_released"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSManageWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    0,   47,    2, 0x08,    4 /* Private */,
       6,    0,   48,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ManageWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSManageWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSManageWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSManageWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ManageWidget, std::true_type>,
        // method 'on_CancleButton_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_AddButton_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SaveButton_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_DeleteButton_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SearchPersonButton_released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ManageWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ManageWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_CancleButton_released(); break;
        case 1: _t->on_AddButton_released(); break;
        case 2: _t->on_SaveButton_released(); break;
        case 3: _t->on_DeleteButton_released(); break;
        case 4: _t->on_SearchPersonButton_released(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *ManageWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ManageWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSManageWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ManageWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP