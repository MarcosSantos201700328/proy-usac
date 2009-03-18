/****************************************************************************
** Form implementation generated from reading ui file 'wdg_procesos.ui'
**
** Created: Wed Mar 26 22:06:32 2008
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.7   edited Aug 31 2005 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "wdg_procesos.h"

#include <qvariant.h>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qtable.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a frm_procesos as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
frm_procesos::frm_procesos( QWidget* parent, const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "frm_procesos" );
    frm_procesosLayout = new QVBoxLayout( this, 11, 6, "frm_procesosLayout"); 

    groupBox1 = new QGroupBox( this, "groupBox1" );
    groupBox1->setColumnLayout(0, Qt::Vertical );
    groupBox1->layout()->setSpacing( 6 );
    groupBox1->layout()->setMargin( 11 );
    groupBox1Layout = new QVBoxLayout( groupBox1->layout() );
    groupBox1Layout->setAlignment( Qt::AlignTop );

    table1 = new QTable( groupBox1, "table1" );
    table1->setNumRows( 3 );
    table1->setNumCols( 3 );
    groupBox1Layout->addWidget( table1 );

    pushButton1 = new QPushButton( groupBox1, "pushButton1" );
    groupBox1Layout->addWidget( pushButton1 );
    frm_procesosLayout->addWidget( groupBox1 );
    languageChange();
    resize( QSize(512, 445).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
frm_procesos::~frm_procesos()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void frm_procesos::languageChange()
{
    setCaption( tr( "Form1" ) );
    groupBox1->setTitle( tr( "Listado de Procesos" ) );
    pushButton1->setText( tr( "M&atar Proceso(s) seleccionado(s)" ) );
    pushButton1->setAccel( QKeySequence( tr( "Alt+A" ) ) );
}

