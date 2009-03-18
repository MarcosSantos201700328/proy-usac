/** @file browser.cpp 
 * Implementacion de la clase browserDock */
/* Godzilla
* Proyecto No. 2 de Lenguajes y Compiladores 1
* (c) 2006 Erik Giron C# 200313492
*/
#include "browser.h"
#include <qfile.h>
#include <qtextstream.h>
/**Constructor, llama al constructor padre con los mismos parametros*/
BrowserDock::BrowserDock(QWidget * parent, const char * name, WFlags f)
						:QDockWindow(parent,name,f)	
{
	b = new QTextBrowser( this/*, "browser",WStyle_Customize | Qt::WStyle_SysMenu | WStyle_Dialog |*/);	
	b->setWordWrap(QTextBrowser::NoWrap);
	
	setResizeEnabled(TRUE);/*Hacemos que la ventana pueda ser cambiada de tamano*/
	this->setOrientation (Horizontal);/*Asignamos orientacion predeteerminada*/
	setWidget(b);/*le zampamos el textbrowser*/
	
}
/**Constructor, llama al constructor padre con los mismos parametros*/
BrowserDock::BrowserDock(Place p, QWidget * parent, const char * name, WFlags f)
  :QDockWindow(p,parent,name,f)	
{
  b = new QTextBrowser( this/*, "browser",WStyle_Customize | Qt::WStyle_SysMenu | WStyle_Dialog |*/);	
  b->setWordWrap(QTextBrowser::NoWrap);
	
  setResizeEnabled(TRUE);/*Hacemos que la ventana pueda ser cambiada de tamano*/
  this->setOrientation (Horizontal);/*Asignamos orientacion predeteerminada*/
  setWidget(b);/*le zampamos el textbrowser*/
	
}
BrowserDock::~BrowserDock(){
	delete(b);
}
/**Abre el archivo dado en el browser
 @param fileName nombre de archivo a mostrar en el QtextBrowser*/
void BrowserDock::setSource(QString fileName){
	QFile f( fileName );
	if ( !f.open( IO_ReadOnly ) )
		return;	
	QTextStream ts( &f );
	b->setText( ts.read() );    
	b->setModified( FALSE );	
	//b->setSource(filename);
//	f.close();
}

/**Asigna titulo de ventana
@param label cadena de nombre*/
void BrowserDock::setLabel(QString label){
	setCaption(label);
}
/**establece orientacion para el browserdock*/
void BrowserDock::orientacion(Orientation o){
  this->setOrientation (o);  
}
