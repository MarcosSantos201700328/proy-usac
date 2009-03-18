/****************************************************************************
** pacmanThread meta object code from reading C++ file 'pacmanthread.h'
**
** Created: Fri Nov 16 22:21:25 2007
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.7   edited Oct 19 16:22 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "pacmanthread.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *pacmanThread::className() const
{
    return "pacmanThread";
}

QMetaObject *pacmanThread::metaObj = 0;
static QMetaObjectCleanUp cleanUp_pacmanThread( "pacmanThread", &pacmanThread::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString pacmanThread::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "pacmanThread", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString pacmanThread::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "pacmanThread", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* pacmanThread::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = Pacman::staticMetaObject();
    static const QUMethod slot_0 = {"run", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ "pValue1", &static_QUType_ptr, "Fantasma", QUParameter::In },
	{ "pValue2", &static_QUType_ptr, "Fantasma", QUParameter::In }
    };
    static const QUMethod slot_1 = {"setEnemigos", 2, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "Fantasma", QUParameter::Out }
    };
    static const QUMethod slot_2 = {"getEnemigo", 1, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "run()", &slot_0, QMetaData::Public },
	{ "setEnemigos(Fantasma*,Fantasma*)", &slot_1, QMetaData::Public },
	{ "getEnemigo()", &slot_2, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"pacmanThread", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_pacmanThread.setMetaObject( metaObj );
    return metaObj;
}

void* pacmanThread::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "pacmanThread" ) )
	return this;
    if ( !qstrcmp( clname, "QThread" ) )
	return (QThread*)this;
    return Pacman::qt_cast( clname );
}

bool pacmanThread::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: run(); break;
    case 1: setEnemigos((Fantasma*)static_QUType_ptr.get(_o+1),(Fantasma*)static_QUType_ptr.get(_o+2)); break;
    case 2: static_QUType_ptr.set(_o,getEnemigo()); break;
    default:
	return Pacman::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool pacmanThread::qt_emit( int _id, QUObject* _o )
{
    return Pacman::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool pacmanThread::qt_property( int id, int f, QVariant* v)
{
    return Pacman::qt_property( id, f, v);
}

bool pacmanThread::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
