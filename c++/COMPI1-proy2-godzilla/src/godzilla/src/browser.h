/** @file browser.h 
 * Definiciones de la clase browserDock */

/* Godzilla
* Proyecto No. 2 de Lenguajes y Compiladores 1
* (c) 2006 Erik Giron C# 200313492
*/
#ifndef BROWSER_H
#define BROWSER_H
#include <qdockwindow.h>
#include <qtextbrowser.h>
/**DockWindow del browser empotrable en la ventana principal, heredando de QDockWindow*/
class BrowserDock : QDockWindow{
public:
	BrowserDock(QWidget * parent, const char * name = 0, WFlags f = 0);
	BrowserDock(Place p, QWidget * parent, const char * name, WFlags f);
	~BrowserDock();
	void setSource(QString filename);
	void setLabel(QString label);
	void BrowserDock::orientacion(Orientation o);
private:
	QTextBrowser* b;
};
#endif
