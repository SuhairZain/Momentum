/****************************************************************************
** Meta object code from reading C++ file 'MomentumSetterPage.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Pages/MomentumSetterPage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MomentumSetterPage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MomentumSetterPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      46,   19,   19,   19, 0x08,
      63,   19,   19,   19, 0x08,
      96,   19,   19,   19, 0x08,
     114,   19,   19,   19, 0x08,
     147,   19,   19,   19, 0x08,
     168,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MomentumSetterPage[] = {
    "MomentumSetterPage\0\0captureScreenAfterDelay()\0"
    "onDialogOpened()\0onGoalFieldTextChanging(QString)\0"
    "onPreviewTapped()\0onSelectedValueChanged(QVariant)\0"
    "onSetAsWallClicked()\0onThumbTapped(int)\0"
};

void MomentumSetterPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MomentumSetterPage *_t = static_cast<MomentumSetterPage *>(_o);
        switch (_id) {
        case 0: _t->captureScreenAfterDelay(); break;
        case 1: _t->onDialogOpened(); break;
        case 2: _t->onGoalFieldTextChanging((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->onPreviewTapped(); break;
        case 4: _t->onSelectedValueChanged((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 5: _t->onSetAsWallClicked(); break;
        case 6: _t->onThumbTapped((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MomentumSetterPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MomentumSetterPage::staticMetaObject = {
    { &Page::staticMetaObject, qt_meta_stringdata_MomentumSetterPage,
      qt_meta_data_MomentumSetterPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MomentumSetterPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MomentumSetterPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MomentumSetterPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MomentumSetterPage))
        return static_cast<void*>(const_cast< MomentumSetterPage*>(this));
    return Page::qt_metacast(_clname);
}

int MomentumSetterPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Page::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
