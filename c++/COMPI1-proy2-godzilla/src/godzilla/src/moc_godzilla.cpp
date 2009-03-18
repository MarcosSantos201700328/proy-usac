/****************************************************************************
** GodZilla meta object code from reading C++ file 'godzilla.h'
**
** Created: Mon May 15 18:51:25 2006
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.4   edited Jan 21 18:14 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "godzilla.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *GodZilla::className() const
{
    return "GodZilla";
}

QMetaObject *GodZilla::metaObj = 0;
static QMetaObjectCleanUp cleanUp_GodZilla( "GodZilla", &GodZilla::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString GodZilla::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "GodZilla", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString GodZilla::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "GodZilla", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* GodZilla::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In },
	{ "col", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"escribirInfoLinea", 2, param_slot_0 };
    static const QUMethod slot_1 = {"leerArchivoError", 0, 0 };
    static const QUMethod slot_2 = {"leerArchivoSalida", 0, 0 };
    static const QUMethod slot_3 = {"leerArchivoTablaSimbolos", 0, 0 };
    static const QUMethod slot_4 = {"newDoc", 0, 0 };
    static const QUMethod slot_5 = {"choose", 0, 0 };
    static const QUParameter param_slot_6[] = {
	{ "fileName", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"load", 1, param_slot_6 };
    static const QUMethod slot_7 = {"save", 0, 0 };
    static const QUMethod slot_8 = {"saveAs", 0, 0 };
    static const QUMethod slot_9 = {"print", 0, 0 };
    static const QUParameter param_slot_10[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out }
    };
    static const QUMethod slot_10 = {"parseInput", 1, param_slot_10 };
    static const QUMethod slot_11 = {"about", 0, 0 };
    static const QUMethod slot_12 = {"aboutQt", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "escribirInfoLinea(int,int)", &slot_0, QMetaData::Private },
	{ "leerArchivoError()", &slot_1, QMetaData::Private },
	{ "leerArchivoSalida()", &slot_2, QMetaData::Private },
	{ "leerArchivoTablaSimbolos()", &slot_3, QMetaData::Private },
	{ "newDoc()", &slot_4, QMetaData::Private },
	{ "choose()", &slot_5, QMetaData::Private },
	{ "load(const QString&)", &slot_6, QMetaData::Private },
	{ "save()", &slot_7, QMetaData::Private },
	{ "saveAs()", &slot_8, QMetaData::Private },
	{ "print()", &slot_9, QMetaData::Private },
	{ "parseInput()", &slot_10, QMetaData::Private },
	{ "about()", &slot_11, QMetaData::Private },
	{ "aboutQt()", &slot_12, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"GodZilla", parentObject,
	slot_tbl, 13,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_GodZilla.setMetaObject( metaObj );
    return metaObj;
}

void* GodZilla::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "GodZilla" ) )
	return this;
    return QMainWindow::qt_cast( clname );
}

bool GodZilla::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: escribirInfoLinea((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 1: leerArchivoError(); break;
    case 2: leerArchivoSalida(); break;
    case 3: leerArchivoTablaSimbolos(); break;
    case 4: newDoc(); break;
    case 5: choose(); break;
    case 6: load((const QString&)static_QUType_QString.get(_o+1)); break;
    case 7: save(); break;
    case 8: saveAs(); break;
    case 9: print(); break;
    case 10: static_QUType_int.set(_o,parseInput()); break;
    case 11: about(); break;
    case 12: aboutQt(); break;
    default:
	return QMainWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool GodZilla::qt_emit( int _id, QUObject* _o )
{
    return QMainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool GodZilla::qt_property( int id, int f, QVariant* v)
{
    return QMainWindow::qt_property( id, f, v);
}

bool GodZilla::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
