/****************************************************************************
** Meta object code from reading C++ file 'SupportPage.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Pages/SupportPage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SupportPage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SupportPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      26,   12,   12,   12, 0x08,
      39,   12,   12,   12, 0x08,
      52,   12,   12,   12, 0x08,
     101,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SupportPage[] = {
    "SupportPage\0\0on1Clicked()\0on2Clicked()\0"
    "on3Clicked()\0"
    "onPurchaseFinished(bb::platform::PurchaseReply*)\0"
    "purchaseWithSKU(QString)\0"
};

void SupportPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SupportPage *_t = static_cast<SupportPage *>(_o);
        switch (_id) {
        case 0: _t->on1Clicked(); break;
        case 1: _t->on2Clicked(); break;
        case 2: _t->on3Clicked(); break;
        case 3: _t->onPurchaseFinished((*reinterpret_cast< bb::platform::PurchaseReply*(*)>(_a[1]))); break;
        case 4: _t->purchaseWithSKU((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SupportPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SupportPage::staticMetaObject = {
    { &Page::staticMetaObject, qt_meta_stringdata_SupportPage,
      qt_meta_data_SupportPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SupportPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SupportPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SupportPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SupportPage))
        return static_cast<void*>(const_cast< SupportPage*>(this));
    return Page::qt_metacast(_clname);
}

int SupportPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Page::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
