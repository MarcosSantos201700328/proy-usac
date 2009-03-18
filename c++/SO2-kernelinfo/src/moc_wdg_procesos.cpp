/****************************************************************************
** frm_procesos meta object code from reading C++ file 'wdg_procesos.h'
**
** Created: Wed Mar 26 22:06:51 2008
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.7   edited Oct 19 16:22 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "wdg_procesos.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *frm_procesos::className() const
{
    return "frm_procesos";
}

QMetaObject *frm_procesos::metaObj = 0;
static QMetaObjectCleanUp cleanUp_frm_procesos( "frm_procesos", &frm_procesos::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString frm_procesos::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "frm_procesos", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString frm_procesos::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "frm_procesos", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* frm_procesos::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "languageChange()", &slot_0, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"frm_procesos", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_frm_procesos.setMetaObject( metaObj );
    return metaObj;
}

void* frm_procesos::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "frm_procesos" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool frm_procesos::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: languageChange(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool frm_procesos::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool frm_procesos::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool frm_procesos::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
