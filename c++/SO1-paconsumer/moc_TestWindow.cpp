/****************************************************************************
** TestWindow meta object code from reading C++ file 'TestWindow.h'
**
** Created: Fri Nov 16 22:21:30 2007
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.7   edited Oct 19 16:22 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "TestWindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *TestWindow::className() const
{
    return "TestWindow";
}

QMetaObject *TestWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_TestWindow( "TestWindow", &TestWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString TestWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TestWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString TestWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TestWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* TestWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
    static const QUMethod slot_0 = {"fileNew", 0, 0 };
    static const QUMethod slot_1 = {"fileOpen", 0, 0 };
    static const QUMethod slot_2 = {"fileSave", 0, 0 };
    static const QUMethod slot_3 = {"fileSaveAs", 0, 0 };
    static const QUMethod slot_4 = {"filePrint", 0, 0 };
    static const QUMethod slot_5 = {"fileExit", 0, 0 };
    static const QUMethod slot_6 = {"editUndo", 0, 0 };
    static const QUMethod slot_7 = {"editRedo", 0, 0 };
    static const QUMethod slot_8 = {"editCut", 0, 0 };
    static const QUMethod slot_9 = {"add", 0, 0 };
    static const QUMethod slot_10 = {"editPaste", 0, 0 };
    static const QUMethod slot_11 = {"editFind", 0, 0 };
    static const QUMethod slot_12 = {"helpIndex", 0, 0 };
    static const QUMethod slot_13 = {"helpContents", 0, 0 };
    static const QUMethod slot_14 = {"helpAbout", 0, 0 };
    static const QUParameter param_slot_15[] = {
	{ 0, &static_QUType_ptr, "pacmanThread", QUParameter::Out }
    };
    static const QUMethod slot_15 = {"remove", 1, param_slot_15 };
    static const QUMethod slot_16 = {"begin", 0, 0 };
    static const QUMethod slot_17 = {"end", 0, 0 };
    static const QUMethod slot_18 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "fileNew()", &slot_0, QMetaData::Public },
	{ "fileOpen()", &slot_1, QMetaData::Public },
	{ "fileSave()", &slot_2, QMetaData::Public },
	{ "fileSaveAs()", &slot_3, QMetaData::Public },
	{ "filePrint()", &slot_4, QMetaData::Public },
	{ "fileExit()", &slot_5, QMetaData::Public },
	{ "editUndo()", &slot_6, QMetaData::Public },
	{ "editRedo()", &slot_7, QMetaData::Public },
	{ "editCut()", &slot_8, QMetaData::Public },
	{ "add()", &slot_9, QMetaData::Public },
	{ "editPaste()", &slot_10, QMetaData::Public },
	{ "editFind()", &slot_11, QMetaData::Public },
	{ "helpIndex()", &slot_12, QMetaData::Public },
	{ "helpContents()", &slot_13, QMetaData::Public },
	{ "helpAbout()", &slot_14, QMetaData::Public },
	{ "remove()", &slot_15, QMetaData::Public },
	{ "begin()", &slot_16, QMetaData::Public },
	{ "end()", &slot_17, QMetaData::Public },
	{ "languageChange()", &slot_18, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"TestWindow", parentObject,
	slot_tbl, 19,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_TestWindow.setMetaObject( metaObj );
    return metaObj;
}

void* TestWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "TestWindow" ) )
	return this;
    return QMainWindow::qt_cast( clname );
}

bool TestWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: fileNew(); break;
    case 1: fileOpen(); break;
    case 2: fileSave(); break;
    case 3: fileSaveAs(); break;
    case 4: filePrint(); break;
    case 5: fileExit(); break;
    case 6: editUndo(); break;
    case 7: editRedo(); break;
    case 8: editCut(); break;
    case 9: add(); break;
    case 10: editPaste(); break;
    case 11: editFind(); break;
    case 12: helpIndex(); break;
    case 13: helpContents(); break;
    case 14: helpAbout(); break;
    case 15: static_QUType_ptr.set(_o,remove()); break;
    case 16: begin(); break;
    case 17: end(); break;
    case 18: languageChange(); break;
    default:
	return QMainWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool TestWindow::qt_emit( int _id, QUObject* _o )
{
    return QMainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool TestWindow::qt_property( int id, int f, QVariant* v)
{
    return QMainWindow::qt_property( id, f, v);
}

bool TestWindow::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
