/****************************************************************************
** Meta object code from reading C++ file 'deriveddisplaysettingsview.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "deriveddisplaysettingsview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deriveddisplaysettingsview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CDerivedDisplaySettingsListView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      50,   33,   32,   32, 0x05,

 // slots: signature, parameters, type, tag, flags
      75,   33,   32,   32, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CDerivedDisplaySettingsListView[] = {
    "CDerivedDisplaySettingsListView\0\0"
    "column,ascending\0sortingChanged(int,bool)\0"
    "setSorting(int,bool)\0"
};

void CDerivedDisplaySettingsListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CDerivedDisplaySettingsListView *_t = static_cast<CDerivedDisplaySettingsListView *>(_o);
        switch (_id) {
        case 0: _t->sortingChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->setSorting((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CDerivedDisplaySettingsListView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CDerivedDisplaySettingsListView::staticMetaObject = {
    { &Q3ListView::staticMetaObject, qt_meta_stringdata_CDerivedDisplaySettingsListView,
      qt_meta_data_CDerivedDisplaySettingsListView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CDerivedDisplaySettingsListView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CDerivedDisplaySettingsListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CDerivedDisplaySettingsListView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CDerivedDisplaySettingsListView))
        return static_cast<void*>(const_cast< CDerivedDisplaySettingsListView*>(this));
    return Q3ListView::qt_metacast(_clname);
}

int CDerivedDisplaySettingsListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Q3ListView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CDerivedDisplaySettingsListView::sortingChanged(int _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
