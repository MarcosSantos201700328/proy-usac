/****************************************************************************
** testW meta object code from reading C++ file 'testw.h'
**
** Created: Fri Nov 16 22:21:22 2007
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.7   edited Oct 19 16:22 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "testw.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *testW::className() const
{
    return "testW";
}

QMetaObject *testW::metaObj = 0;
static QMetaObjectCleanUp cleanUp_testW( "testW", &testW::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString testW::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "testW", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString testW::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "testW", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* testW::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = TestWindow::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "pacmanThread", QUParameter::Out }
    };
    static const QUMethod slot_0 = {"remove", 1, param_slot_0 };
    static const QUMethod slot_1 = {"add", 0, 0 };
    static const QUMethod slot_2 = {"end", 0, 0 };
    static const QUMethod slot_3 = {"begin", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "remove()", &slot_0, QMetaData::Public },
	{ "add()", &slot_1, QMetaData::Public },
	{ "end()", &slot_2, QMetaData::Public },
	{ "begin()", &slot_3, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"testW", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_testW.setMetaObject( metaObj );
    return metaObj;
}

void* testW::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "testW" ) )
	return this;
    if ( !qstrcmp( clname, "QThread" ) )
	return (QThread*)this;
    return TestWindow::qt_cast( clname );
}

bool testW::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: static_QUType_ptr.set(_o,remove()); break;
    case 1: add(); break;
    case 2: end(); break;
    case 3: begin(); break;
    default:
	return TestWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool testW::qt_emit( int _id, QUObject* _o )
{
    return TestWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool testW::qt_property( int id, int f, QVariant* v)
{
    return TestWindow::qt_property( id, f, v);
}

bool testW::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
