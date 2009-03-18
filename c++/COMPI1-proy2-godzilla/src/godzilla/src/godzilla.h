/** @file godzilla.h
 * defiinicion de la Widged principal del GUI.*/
/* Godzilla
* Proyecto No. 2 de Lenguajes y Compiladores 1
* (c) 2006 Erik Giron C# 200313492
*/

//! @TODO componer bug extranio al analizar por segunda vez un archivo
#ifndef GODZILLA_H
#define GODZILLA_H

#include <qmainwindow.h>
#include <qlabel.h>
#include <cstdlib>
#include <qtextbrowser.h>
#include "browser.h"

extern "C"{
#include "parserheader.h"
//extern FILE* embedout;
//extern FILE* embedin;
//extern int embedparse();

//extern int inputparse(const char*,const char*,const char*);
#include "ast.h"
#include "colaerr.h"
};
class QTextEdit;

class GodZilla: public QMainWindow
{
    Q_OBJECT

public:
    GodZilla();
    ~GodZilla();

protected:
    void closeEvent( QCloseEvent* );
  public slots:
    
    
private slots:
  void escribirInfoLinea(int row,int col);    
  void leerArchivoError();
  void leerArchivoSalida();
  void leerArchivoTablaSimbolos();
    void newDoc();
    void choose();
    void load( const QString &fileName );
    void save();
    void saveAs();
    void print();
    int parseInput();	
    void about();
    void aboutQt();


private:
    QPrinter *printer;
    QTextEdit *e;
    QString filename;
    QString inputfilename;
    QString outputfile;
    QString errorfile;
    QString tabfile;
    QLabel* lineInfo;
    BrowserDock *browser;
    BrowserDock *symtabBrowser;
};


#endif
