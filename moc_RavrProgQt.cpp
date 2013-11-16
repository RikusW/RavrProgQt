/****************************************************************************
** Meta object code from reading C++ file 'RavrProgQt.h'
**
** Created: Sun Nov 3 04:26:06 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "RavrProgQt.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RavrProgQt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RavrProgQt[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      29,   11,   11,   11, 0x0a,
      46,   44,   11,   11, 0x0a,
      65,   44,   11,   11, 0x0a,
      84,   11,   11,   11, 0x0a,
      93,   11,   11,   11, 0x0a,
     102,   11,   11,   11, 0x0a,
     112,   11,   11,   11, 0x0a,
     122,   11,   11,   11, 0x0a,
     135,   11,   11,   11, 0x0a,
     154,   11,   11,   11, 0x0a,
     166,   11,   11,   11, 0x0a,
     178,   11,   11,   11, 0x0a,
     191,   11,   11,   11, 0x0a,
     205,   11,   11,   11, 0x0a,
     219,   11,   11,   11, 0x0a,
     232,   11,   11,   11, 0x0a,
     246,   11,   11,   11, 0x0a,
     261,   11,   11,   11, 0x0a,
     276,   11,   11,   11, 0x0a,
     292,   11,   11,   11, 0x0a,
     309,   11,   11,   11, 0x0a,
     327,   11,   11,   11, 0x0a,
     347,   11,   11,   11, 0x0a,
     366,   11,   11,   11, 0x0a,
     377,   11,   11,   11, 0x0a,
     389,   11,   11,   11, 0x0a,
     402,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RavrProgQt[] = {
    "RavrProgQt\0\0ProgChanged(int)\0"
    "IfChanged(int)\0i\0PClockChanged(int)\0"
    "EClockChanged(int)\0ApplyP()\0ApplyE()\0"
    "Refresh()\0Connect()\0RefreshAVR()\0"
    "DeviceChanged(int)\0ChipErase()\0"
    "ReadFlash()\0WriteFlash()\0VerifyFlash()\0"
    "SelectFlash()\0ReadEeprom()\0WriteEeprom()\0"
    "VerifyEeprom()\0SelectEeprom()\0"
    "TabChanged(int)\0FuseChecked(int)\0"
    "FuseSelected(int)\0FuseEdited(QString)\0"
    "FuseEditFinished()\0ReadFuse()\0WriteFuse()\0"
    "VerifyFuse()\0DefaultFuse()\0"
};

void RavrProgQt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RavrProgQt *_t = static_cast<RavrProgQt *>(_o);
        switch (_id) {
        case 0: _t->ProgChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->IfChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->PClockChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->EClockChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->ApplyP(); break;
        case 5: _t->ApplyE(); break;
        case 6: _t->Refresh(); break;
        case 7: _t->Connect(); break;
        case 8: _t->RefreshAVR(); break;
        case 9: _t->DeviceChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->ChipErase(); break;
        case 11: _t->ReadFlash(); break;
        case 12: _t->WriteFlash(); break;
        case 13: _t->VerifyFlash(); break;
        case 14: _t->SelectFlash(); break;
        case 15: _t->ReadEeprom(); break;
        case 16: _t->WriteEeprom(); break;
        case 17: _t->VerifyEeprom(); break;
        case 18: _t->SelectEeprom(); break;
        case 19: _t->TabChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->FuseChecked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->FuseSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->FuseEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 23: _t->FuseEditFinished(); break;
        case 24: _t->ReadFuse(); break;
        case 25: _t->WriteFuse(); break;
        case 26: _t->VerifyFuse(); break;
        case 27: _t->DefaultFuse(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RavrProgQt::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RavrProgQt::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RavrProgQt,
      qt_meta_data_RavrProgQt, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RavrProgQt::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RavrProgQt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RavrProgQt::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RavrProgQt))
        return static_cast<void*>(const_cast< RavrProgQt*>(this));
    return QDialog::qt_metacast(_clname);
}

int RavrProgQt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
