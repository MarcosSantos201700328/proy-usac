/****************************************************************************
** f_main meta object code from reading C++ file 'f_main.h'
**
** Created: Wed Mar 26 22:06:42 2008
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.7   edited Oct 19 16:22 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "f_main.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *f_main::className() const
{
    return "f_main";
}

QMetaObject *f_main::metaObj = 0;
static QMetaObjectCleanUp cleanUp_f_main( "f_main", &f_main::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString f_main::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "f_main", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString f_main::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "f_main", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* f_main::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = frm_main::staticMetaObject();
    static const QUMethod slot_0 = {"kill", 0, 0 };
    static const QUMethod slot_1 = {"cargarModulo", 0, 0 };
    static const QUMethod slot_2 = {"descargarModulo", 0, 0 };
    static const QUMethod slot_3 = {"exportdev", 0, 0 };
    static const QUMethod slot_4 = {"fileExit", 0, 0 };
    static const QUMethod slot_5 = {"helpAbout", 0, 0 };
    static const QUMethod slot_6 = {"helpContents", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "kill()", &slot_0, QMetaData::Public },
	{ "cargarModulo()", &slot_1, QMetaData::Public },
	{ "descargarModulo()", &slot_2, QMetaData::Public },
	{ "exportdev()", &slot_3, QMetaData::Public },
	{ "fileExit()", &slot_4, QMetaData::Public },
	{ "helpAbout()", &slot_5, QMetaData::Public },
	{ "helpContents()", &slot_6, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"f_main", parentObject,
	slot_tbl, 7,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_f_main.setMetaObject( metaObj );
    return metaObj;
}

void* f_main::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "f_main" ) )
	return this;
    return frm_main::qt_cast( clname );
}

bool f_main::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: kill(); break;
    case 1: cargarModulo(); break;
    case 2: descargarModulo(); break;
    case 3: exportdev(); break;
    case 4: fileExit(); break;
    case 5: helpAbout(); break;
    case 6: helpContents(); break;
    default:
	return frm_main::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool f_main::qt_emit( int _id, QUObject* _o )
{
    return frm_main::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool f_main::qt_property( int id, int f, QVariant* v)
{
    return frm_main::qt_property( id, f, v);
}

bool f_main::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
