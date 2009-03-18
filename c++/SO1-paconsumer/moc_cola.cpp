/****************************************************************************
** Cola meta object code from reading C++ file 'cola.h'
**
** Created: Fri Nov 9 22:08:10 2007
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.7   edited Oct 19 16:22 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "cola.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Cola::className() const
{
    return "Cola";
}

QMetaObject *Cola::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Cola( "Cola", &Cola::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Cola::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Cola", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Cola::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Cola", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Cola::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "Pacman", QUParameter::In }
    };
    static const QUMethod slot_0 = {"meter", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "Pacman", QUParameter::Out }
    };
    static const QUMethod slot_1 = {"sacar", 1, param_slot_1 };
    static const QUMethod slot_2 = {"vaciar", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ "pValue", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"setTam", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out }
    };
    static const QUMethod slot_4 = {"getTam", 1, param_slot_4 };
    static const QUMethod slot_5 = {"getBuffer", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "meter(Pacman*)", &slot_0, QMetaData::Public },
	{ "sacar()", &slot_1, QMetaData::Public },
	{ "vaciar()", &slot_2, QMetaData::Public },
	{ "setTam(int)", &slot_3, QMetaData::Public },
	{ "getTam()", &slot_4, QMetaData::Public },
	{ "getBuffer()", &slot_5, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"Cola", parentObject,
	slot_tbl, 6,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Cola.setMetaObject( metaObj );
    return metaObj;
}

void* Cola::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Cola" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool Cola::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: meter((Pacman*)static_QUType_ptr.get(_o+1)); break;
    case 1: static_QUType_ptr.set(_o,sacar()); break;
    case 2: vaciar(); break;
    case 3: setTam((int)static_QUType_int.get(_o+1)); break;
    case 4: static_QUType_int.set(_o,getTam()); break;
    case 5: getBuffer(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Cola::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Cola::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool Cola::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
