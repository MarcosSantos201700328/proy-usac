/** @file godzilla.cpp
 * Implementacion de la Widged principal del GUI.*/
/* Godzilla
* Proyecto No. 2 de Lenguajes y Compiladores 1
* (c) 2006 Erik Giron C# 200313492
*/

#include "godzilla.h"

#include <qimage.h>
#include <qpixmap.h>
#include <qtoolbar.h>
#include <qtoolbutton.h>
#include <qpopupmenu.h>
#include <qmenubar.h>
#include <qtextedit.h>
#include <qfile.h>
#include <qfiledialog.h>
#include <qstatusbar.h>
#include <qmessagebox.h>
#include <qprinter.h>
#include <qapplication.h>
#include <qaccel.h>
#include <qtextstream.h>
#include <qpainter.h>
#include <qpaintdevicemetrics.h>
#include <qwhatsthis.h>

#include "filesave.xpm"
#include "fileopen.xpm"
#include "fileprint.xpm"

GodZilla::GodZilla()
    : QMainWindow( 0, "GodZilla", WDestructiveClose )
{
    printer = new QPrinter;
    QPixmap openIcon, saveIcon, printIcon;

    QToolBar * fileTools = new QToolBar( this, "file operations" );
    fileTools->setLabel( tr("Operaciones de Archivo") );



    openIcon = QPixmap( fileopen );
    QToolButton * fileOpen
	= new QToolButton( openIcon, tr("Abrir"), QString::null,
			   this, SLOT(choose()), fileTools, "open file" );

    saveIcon = QPixmap( filesave );
    QToolButton * fileSave
	= new QToolButton( saveIcon, tr("Guardar"), QString::null,
			   this, SLOT(save()), fileTools, "save file" );

    printIcon = QPixmap( fileprint );
    QToolButton * filePrint
	= new QToolButton( printIcon, tr("Imprimir"), QString::null,
			   this, SLOT(print()), fileTools, "print file" );


    (void)QWhatsThis::whatsThisButton( fileTools );

	QToolBar * compile = new QToolBar(this, "compile operations");
	compile->setLabel( tr("Operaciones de compilacion"));

	QToolButton * analizar 
		= new QToolButton(compile,"analizar");
	analizar->setUsesTextLabel(TRUE);
	analizar->setTextLabel(tr("Analizar"));
	 //conectamos eventos
	connect(analizar,SIGNAL(released()),this,SLOT(parseInput()));

	
	/*	= new QToolButton(NULL , tr("Generar Salida"), QString::null,
				NULL, compile, "analizar");			
*/
    QString fileOpenText = tr("<p><img source=\"fileopen\"> "
	         "Presione este boton para abrir un<em> nuevo archivo </em>.<br>"
                 "Usted tambien puede seleccionar el comando <b>abrir</b> "
                 "desde el menu <b>Archivo</b>");

    QWhatsThis::add( fileOpen, fileOpenText );

    QMimeSourceFactory::defaultFactory()->setPixmap( "fileopen", openIcon );

    QString fileSaveText = tr("<p>Presione este boton para salvar el actual "
                 "archivo. Se le preguntara la ruta.\n"
                 "Puede tambien presionar el comando<b> Guardar</b> "
                 "desde el menu <b>Archivo</b>.</p>");

    QWhatsThis::add( fileSave, fileSaveText );

    QString filePrintText = tr("Presione este boton si desea imprimir "
                 "el archivo actual.\n Tambien puede seleccionar el comando Imprimir "
                 "desde el menu Archivo.");
	QWhatsThis::add( filePrint, filePrintText );

    QString fileParseText = tr("Presione este boton si desea interpretar "
                 "el archivo actual.\n Se le preguntara la direccion donde desee "
                 "almacenar el archivo HTML resultante.");

    QWhatsThis::add(analizar,fileParseText);


    QPopupMenu * file = new QPopupMenu( this );
    menuBar()->insertItem( tr("&Archivo"), file );


    file->insertItem( tr("&Nuevo"), this, SLOT(newDoc()), CTRL+Key_N );

    int id;
    id = file->insertItem( openIcon, tr("&Abrir..."),
			   this, SLOT(choose()), CTRL+Key_O );
    file->setWhatsThis( id, fileOpenText );

    id = file->insertItem( saveIcon, tr("&Guardar"),
			   this, SLOT(save()), CTRL+Key_S );
    file->setWhatsThis( id, fileSaveText );

    id = file->insertItem( tr("Guardar &Como..."), this, SLOT(saveAs()) );
    file->setWhatsThis( id, fileSaveText );

    file->insertSeparator();

    id = file->insertItem( printIcon, tr("&Imprimir..."),
			   this, SLOT(print()), CTRL+Key_P );
    file->setWhatsThis( id, filePrintText );

    file->insertSeparator();

    file->insertItem( tr("&Cerrar"), this, SLOT(close()), CTRL+Key_W );

    file->insertItem( tr("&Salir"), qApp, SLOT( closeAllWindows() ), CTRL+Key_Q );

    menuBar()->insertSeparator();

    QPopupMenu * compileMenu = new QPopupMenu( this );
    menuBar()->insertItem( tr("&Interprete"), compileMenu );

    compileMenu->insertItem( tr("&Analizar archivo de Entrada "),this,SLOT(parseInput()),Key_F9);
    compileMenu->insertSeparator();
    
    compileMenu->insertItem( tr("Ver archivo &HTML generado "),this,SLOT(leerArchivoSalida()),CTRL +Key_F9);
    compileMenu->insertItem( tr("Ver archivo &XML de error "),this,SLOT(leerArchivoError()),ALT +Key_F9);
    compileMenu->insertItem( tr("Ver &tabla de simbolos "),this,SLOT(leerArchivoTablaSimbolos()),Key_F10);
    

    
    menuBar()->insertSeparator();

    QPopupMenu * help = new QPopupMenu( this );
    menuBar()->insertItem( tr("&Ayuda"), help );

    help->insertItem( tr("&Acerca"), this, SLOT(about()), Key_F1 );
    help->insertItem( tr("Acerca de &Qt"), this, SLOT(aboutQt()) );
    help->insertSeparator();
    help->insertItem( tr("Que es &Esto"), this, SLOT(whatsThis()), SHIFT+Key_F1 );

    e = new QTextEdit( this, "editor" );
    e->setFocus();
    e->setTextFormat(PlainText);
    e->setWordWrap(QTextEdit::NoWrap);
    setCentralWidget( e );
    statusBar()->message( tr("Listo"), 2000 );
    resize( 640, 480 );

    setDockEnabled(DockBottom,true);
    browser = new BrowserDock(this,"navegador",0);
    browser->setLabel(tr("Browser"));
    addDockWindow ((QDockWindow*) browser, "browserDocked",DockBottom, FALSE);
    /*
    symtabBrowser = new BrowserDock(QDockWindow::OutsideDock,this,"tabla",0);
    symtabBrowser->setLabel(tr("Tabla de simbolos"));
    symtabBrowser->orientacion(Vertical);
    addDockWindow ((QDockWindow*) symtabBrowser, "symtabBrowserDocked",DockRight, FALSE);
    */
    
    lineInfo = new QLabel(statusBar(),"lineinfo",0);
    lineInfo->setText("Linea: , Columna: ");
    lineInfo->setFixedSize(200,16);
    statusBar()->addWidget(lineInfo, 0, true);
    connect(e,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(escribirInfoLinea(int,int)));	
}



GodZilla::~GodZilla()
{
    delete printer;
}


void GodZilla::newDoc()
{
    GodZilla *ed = new GodZilla;
    ed->setCaption(tr("Godzilla - Nuevo"));
    ed->show();
}

void GodZilla::choose()
{
    QString fn = QFileDialog::getOpenFileName( QString::null, QString::null,
					       this);
    if ( !fn.isEmpty() )
	load( fn );
    else
	statusBar()->message( tr("Carga abortada"), 2000 );
}


void GodZilla::load( const QString &fileName )
{
	QFile f( fileName );
	if ( !f.open( IO_ReadOnly ) )
		return;	
	QTextStream ts( &f );
	ts.setEncoding(QTextStream::Latin1); //para que funcione con texto ascii	
	e->setText( ts.read() );    
	e->setModified( FALSE );
	setCaption( fileName );
	statusBar()->message( tr("Cargado documento %1").arg(fileName), 2000 );
	inputfilename = fileName; //copiamos texto
	filename = fileName;
	
	//f.close();
}


void GodZilla::save()
{
    if ( filename.isEmpty() ) {
	saveAs();
	return;
    }

    QString text = e->text();
    QFile f( filename );
    if ( !f.open( IO_WriteOnly ) ) {
	statusBar()->message( tr("Imposible escribir hacia %1").arg(filename),
			      2000 );
	return;
    }

    QTextStream t( &f );
    t << text;
    f.close();

    e->setModified( FALSE );

    setCaption( filename );
	inputfilename = filename;
    statusBar()->message( tr( "Archivo %1 guardado." ).arg( filename ), 2000 );
}


void GodZilla::saveAs()
{
    QString fn = QFileDialog::getSaveFileName( QString::null, QString::null,
					       this );
    if ( !fn.isEmpty() ) {
	filename = fn;
	save();
	inputfilename = filename;
    } else {
	statusBar()->message( tr("Guardar abortado."), 2000 );
    }
    
	
}

/**
 * Slot para el boton de analisis del archivo de entrada
 */
int GodZilla::parseInput()
{
    QString fn;
    int respuesta = 0;
    fn = QFileDialog::getSaveFileName( QString::null, QString::null,
					       this );
	if(!(inputfilename.isEmpty())){ //si hay actualmente un archivo abierto
		if ( !fn.isEmpty()) {	
			errorfile = fn + ".err.xml"; // path para archivo de error
			tabfile = fn + ".tab.xml";
			outputfile = fn; // asignamos path a campo outputfile
			if(inputparse(inputfilename.ascii(), outputfile.ascii()) == 0){ /*Codigo para cuando todo salio bien*/
				respuesta = QMessageBox::question ( this, tr("Godzilla"), tr("Desea ver el archivo generado?"),QMessageBox::Yes,
							QMessageBox::No,
							QMessageBox::Cancel);
				if (respuesta==QMessageBox::Yes){
					browser->setSource(fn);		
					//symtabBrowser->setSource(tabfile);
				}
				statusBar()->message( tr("Analisis completo y sin errores."), 2000); 				
				return 0;
			}
			else{ /*si hubieron errores lexicos o sintacticos*/				
				generarSalidaError(errorfile.ascii());
				respuesta = QMessageBox::warning ( this, tr("Godzilla"),
							tr("Se encontraron errores al leer o interpretar el archivo."
								"Desea ver el archivo de error"),
							QMessageBox::Yes,
							QMessageBox::No,
				    QMessageBox::Cancel);
				if (respuesta==QMessageBox::Yes)
					browser->setSource(errorfile);					
				statusBar()->message( tr("Hubieron errores en el analisis, revise archivo de errores."), 2000 );
				return -1;
			}
		} 
		else {
			statusBar()->message( tr("Analisis cancelado."), 2000 );
			return 0;
		}
		return 0;
	}
	return 0;
}
    

/**slot para escribir linea de archivo al widget lineInfo contenido en la barra de estados*/
void GodZilla::escribirInfoLinea(int row,int col){
  lineInfo->setText("Linea: " + QString::number(row + 1,10) + ", Columna: " + QString::number(col,10));
}
/**Abre en el browser el archivo de error*/
void GodZilla::leerArchivoError(){
  if(errorfile.isEmpty() == FALSE)
    browser->setSource(errorfile);					
  else
    statusBar()->message( tr("No han habido errores para la salida actual."), 2000 );
}
/**Abre en el browser el archivo de tabla de simbolos*/
void GodZilla::leerArchivoTablaSimbolos(){
  if(outputfile.isEmpty() == FALSE)
    browser->setSource(outputfile + ".tab.xml");					
  else
    statusBar()->message( tr("No se ha generado salida, presione Analizar para generarla."), 2000 );
}
/**Abre en el browser el archivo de salida*/
void GodZilla::leerArchivoSalida(){
  if(outputfile.isEmpty() == FALSE)
    browser->setSource(outputfile);		
  else
    statusBar()->message( tr("No se ha generado salida, presione Analizar para generarla."), 2000 );
    			
}

/**Llama al modulo de impresion del shell*/
void GodZilla::print()
{
    // ###### Rewrite to use QSimpleRichText to print here as well
    const int Margin = 10;
    int pageNo = 1;

    if ( printer->setup(this) ) {		// printer dialog
	statusBar()->message( tr("Imprimiendo...") );
	QPainter p;
	if( !p.begin( printer ) )               // paint on printer
	    return;

	p.setFont( e->font() );
	int yPos	= 0;			// y-position for each line
	QFontMetrics fm = p.fontMetrics();
	QPaintDeviceMetrics metrics( printer ); // need width/height
						// of printer surface
	for( int i = 0 ; i < e->lines() ; i++ ) {
	    if ( Margin + yPos > metrics.height() - Margin ) {
		QString msg( "Imprimiendo (Pagina " );
		msg += QString::number( ++pageNo );
		msg += ")...";
		statusBar()->message( msg );
		printer->newPage();		// no more room on this page
		yPos = 0;			// back to top of page
	    }
	    p.drawText( Margin, Margin + yPos,
			metrics.width(), fm.lineSpacing(),
			ExpandTabs | DontClip,
			e->text( i ) );
	    yPos = yPos + fm.lineSpacing();
	}
	p.end();				// send job to printer
	statusBar()->message( tr("Impresion completa"), 2000 );
    } else {
	statusBar()->message( tr("Impresion abortada"), 2000 );
    }
}

void GodZilla::closeEvent( QCloseEvent* ce )
{
    if ( !e->isModified() ) {
	ce->accept();
	return;
    }

    switch( QMessageBox::information( this, tr("GodZilla"),
				      tr("Desea guardar cambios realizados"
				      " al documento?"),
				      tr("Si"), tr("No"), tr("Cancel"),
				      0, 1 ) ) {
    case 0:
	save();
	ce->accept();
	break;
    case 1:
	ce->accept();
	break;
    case 2:
    default: // just for sanity
	ce->ignore();
	break;
    }
}

/**Muestra dialogo*/
void GodZilla::about()
{
    QMessageBox::about( this, tr("GodZilla v 0.5"),
			tr("Para el 2do Proyecto de Compiladores 1"
			"<center><b>Ingenieria USAC</b></center>"
			"(c) 2006 Erik Giron (C# 200313492)."));
}


void GodZilla::aboutQt()
{
    QMessageBox::aboutQt( this, tr("Acerca de QT") );
}

