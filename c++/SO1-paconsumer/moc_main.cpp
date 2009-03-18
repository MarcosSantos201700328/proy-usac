/****************************************************************************
** Main meta object code from reading C++ file 'main.h'
**
** Created: Fri Nov 16 22:21:19 2007
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.7   edited Oct 19 16:22 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "main.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Main::className() const
{
    return "Main";
}

QMetaObject *Main::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Main( "Main", &Main::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Main::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Main", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Main::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Main", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Main::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = MainWindow::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "pActivar", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"Activar", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "pActivar", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"activarSliders", 1, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "Activar(bool)", &slot_0, QMetaData::Public },
	{ "activarSliders(bool)", &slot_1, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"Main", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Main.setMetaObject( metaObj );
    return metaObj;
}

void* Main::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Main" ) )
	return this;
    return MainWindow::qt_cast( clname );
}

bool Main::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: Activar((bool)static_QUType_bool.get(_o+1)); break;
    case 1: activarSliders((bool)static_QUType_bool.get(_o+1)); break;
    default:
	return MainWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Main::qt_emit( int _id, QUObject* _o )
{
    return MainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Main::qt_property( int id, int f, QVariant* v)
{
    return MainWindow::qt_property( id, f, v);
}

bool Main::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
