/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../EASCC/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   12,   11,   11, 0x08,
      39,   31,   11,   11, 0x08,
      74,   58,   11,   11, 0x08,
     111,  103,   11,   11, 0x08,
     143,  131,   11,   11, 0x08,
     177,   31,   11,   11, 0x08,
     193,   31,   11,   11, 0x08,
     209,   31,   11,   11, 0x08,
     225,   31,   11,   11, 0x08,
     243,   31,   11,   11, 0x08,
     267,  259,   11,   11, 0x08,
     288,   31,   11,   11, 0x08,
     303,   31,   11,   11, 0x08,
     320,   31,   11,   11, 0x08,
     338,   11,   11,   11, 0x08,
     353,  131,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0checked\0isel(bool)\0clicked\0"
    "connectToEas(bool)\0commandId,error\0"
    "ftpCommandFinished(int,bool)\0urlInfo\0"
    "addToList(QUrlInfo)\0item,column\0"
    "processItem(QTreeWidgetItem*,int)\0"
    "renameMsg(bool)\0deleteMsg(bool)\0"
    "uploadMsg(bool)\0downloadMsg(bool)\0"
    "newFolder(bool)\0blicked\0descriptionMsg(bool)\0"
    "eventMsg(bool)\0easGetTime(bool)\0"
    "easSyncTime(bool)\0tcpReadyRead()\0"
    "itemClicked(QTreeWidgetItem*,int)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->isel((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->connectToEas((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->ftpCommandFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->addToList((*reinterpret_cast< const QUrlInfo(*)>(_a[1]))); break;
        case 4: _t->processItem((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->renameMsg((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->deleteMsg((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->uploadMsg((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->downloadMsg((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->newFolder((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->descriptionMsg((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->eventMsg((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->easGetTime((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->easSyncTime((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->tcpReadyRead(); break;
        case 15: _t->itemClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
