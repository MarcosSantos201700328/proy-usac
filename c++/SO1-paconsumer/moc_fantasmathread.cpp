/****************************************************************************
** fantasmaThread meta object code from reading C++ file 'fantasmathread.h'
**
** Created: Fri Nov 16 22:21:28 2007
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.7   edited Oct 19 16:22 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "fantasmathread.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *fantasmaThread::className() const
{
    return "fantasmaThread";
}

QMetaObject *fantasmaThread::metaObj = 0;
static QMetaObjectCleanUp cleanUp_fantasmaThread( "fantasmaThread", &fantasmaThread::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString fantasmaThread::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "fantasmaThread", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString fantasmaThread::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "fantasmaThread", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* fantasmaThread::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Fantasma::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "p", &static_QUType_ptr, "pacmanThread", QUParameter::In }
    };
    static const QUMethod slot_0 = {"comer", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "ms", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"setVelocidad", 1, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "comer(pacmanThread*)", &slot_0, QMetaData::Public },
	{ "setVelocidad(int)", &slot_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"fantasmaThread", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_fantasmaThread.setMetaObject( metaObj );
    return metaObj;
}

void* fantasmaThread::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "fantasmaThread" ) )
	return this;
    if ( !qstrcmp( clname, "QThread" ) )
	return (QThread*)this;
    return Fantasma::qt_cast( clname );
}

bool fantasmaThread::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: comer((pacmanThread*)static_QUType_ptr.get(_o+1)); break;
    case 1: setVelocidad((int)static_QUType_int.get(_o+1)); break;
    default:
	return Fantasma::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool fantasmaThread::qt_emit( int _id, QUObject* _o )
{
    return Fantasma::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool fantasmaThread::qt_property( int id, int f, QVariant* v)
{
    return Fantasma::qt_property( id, f, v);
}

bool fantasmaThread::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
