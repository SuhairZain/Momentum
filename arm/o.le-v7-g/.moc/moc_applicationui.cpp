/****************************************************************************
** Meta object code from reading C++ file 'applicationui.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/applicationui.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'applicationui.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ApplicationUI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      29,   14,   14,   14, 0x08,
      42,   14,   14,   14, 0x08,
      59,   14,   14,   14, 0x08,
      83,   14,   14,   14, 0x08,
     107,   14,   14,   14, 0x08,
     133,   14,   14,   14, 0x08,
     153,   14,   14,   14, 0x08,
     184,   14,   14,   14, 0x08,
     206,   14,   14,   14, 0x08,
     235,   14,   14,   14, 0x08,
     267,   14,   14,   14, 0x08,
     303,   14,   14,   14, 0x08,
     327,   14,   14,   14, 0x08,
     343,   14,   14,   14, 0x08,
     360,   14,   14,   14, 0x08,
     376,   14,   14,   14, 0x08,
     404,   14,   14,   14, 0x08,
     444,   14,   14,   14, 0x08,
     486,   14,   14,   14, 0x08,
     504,   14,   14,   14, 0x08,
     539,   14,   14,   14, 0x08,
     562,   14,   14,   14, 0x08,
     577,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ApplicationUI[] = {
    "ApplicationUI\0\0addToQuotes()\0addToWords()\0"
    "onClearClicked()\0onHelpActionTriggered()\0"
    "onInfoActionTriggered()\0"
    "onInfoPageSupportTapped()\0onMomentumClicked()\0"
    "onMomentumIntroGoClicked(bool)\0"
    "onNavpaneTopChanged()\0"
    "onNetworkConnectionsTapped()\0"
    "onPopEnded(bb::cascades::Page*)\0"
    "onQuotesListTriggered(QVariantList)\0"
    "onQuotesReplyFinished()\0onQuoteTapped()\0"
    "onRefreshQuote()\0onRefreshWord()\0"
    "onSettingsActionTriggered()\0"
    "onSettingsPageIntroMessageChanged(bool)\0"
    "onSettingsPageSupportMessageChanged(bool)\0"
    "onSupportTapped()\0onWordsListTriggered(QVariantList)\0"
    "onWordsReplyFinished()\0onWordTapped()\0"
    "setupAppView()\0"
};

void ApplicationUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ApplicationUI *_t = static_cast<ApplicationUI *>(_o);
        switch (_id) {
        case 0: _t->addToQuotes(); break;
        case 1: _t->addToWords(); break;
        case 2: _t->onClearClicked(); break;
        case 3: _t->onHelpActionTriggered(); break;
        case 4: _t->onInfoActionTriggered(); break;
        case 5: _t->onInfoPageSupportTapped(); break;
        case 6: _t->onMomentumClicked(); break;
        case 7: _t->onMomentumIntroGoClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->onNavpaneTopChanged(); break;
        case 9: _t->onNetworkConnectionsTapped(); break;
        case 10: _t->onPopEnded((*reinterpret_cast< bb::cascades::Page*(*)>(_a[1]))); break;
        case 11: _t->onQuotesListTriggered((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        case 12: _t->onQuotesReplyFinished(); break;
        case 13: _t->onQuoteTapped(); break;
        case 14: _t->onRefreshQuote(); break;
        case 15: _t->onRefreshWord(); break;
        case 16: _t->onSettingsActionTriggered(); break;
        case 17: _t->onSettingsPageIntroMessageChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->onSettingsPageSupportMessageChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->onSupportTapped(); break;
        case 20: _t->onWordsListTriggered((*reinterpret_cast< QVariantList(*)>(_a[1]))); break;
        case 21: _t->onWordsReplyFinished(); break;
        case 22: _t->onWordTapped(); break;
        case 23: _t->setupAppView(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ApplicationUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ApplicationUI::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ApplicationUI,
      qt_meta_data_ApplicationUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ApplicationUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ApplicationUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ApplicationUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ApplicationUI))
        return static_cast<void*>(const_cast< ApplicationUI*>(this));
    return QObject::qt_metacast(_clname);
}

int ApplicationUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
