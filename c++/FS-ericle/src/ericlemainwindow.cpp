/**
@file archivo.cpp
@brief Implementacion de [archivo].h
@author Erik Giron (C#200313492)

Copyright (C) 2006 Erik Giron

http://www.itforcegt.org/200313492

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/
#include <qmessagebox.h>
#include "ericlemainwindow.h"
#include "qlabel.h"
#include "qlineedit.h"
#include "qstring.h"
#include "metadata.h"

	
EricleMainWindow::EricleMainWindow(QWidget *parent, const char *name)
    :MainWindow(parent, name)
{
    
    
    db = new database();
    /***/
    
    /**Inicializamos qfiledialog de archivo de entrada*/
    ofd = new QFileDialog( this, "open file dialog", TRUE );
    ofd->setCaption(tr("Seleccione archivo de entrada..."));
    ofd->setMode( QFileDialog::ExistingFile );
    ofd->setFilter( "Texto (*.txt)" );
    ofd->addFilter( "Todos los Archivos (*.*)" );
    ofd->setViewMode( QFileDialog::List );
    
    /**Iniicializamos widget de resultados*/
//FIXME Agregacion de widget de resultados
    erw = new EricleResultWidget();
//    Form1Layout->addWidget(erw);
    erw->show();
    db->setResultWidget(erw);
    
    /**Inicializamos qfiledialog de archivo de config*/
    cfgfd = new QFileDialog( this, "config file dialog", TRUE );
    cfgfd->setCaption(tr("Seleccione directorio donde almacenara la configuracion..."));
    cfgfd->setMode( QFileDialog::Directory );
    //cfgfd->setFilter( "Archivo de Configuracion (*.config)" );
    cfgfd->setFilter( "Todos los Archivos (*.*)" );
    cfgfd->setViewMode( QFileDialog::List );
    
    connect( &ecdbd, SIGNAL(accepted()), this, SLOT(saveConfig()) );
    connect( &eildlg, SIGNAL(added()), this, SLOT(addLibro()) );
    connect( &eiadlg, SIGNAL(added()), this, SLOT(addAutor()) );
    connect( &eitdlg, SIGNAL(added()), this, SLOT(addTitulo()) );
    
    /**Abrimos dialogo para apertura de archivo de config*/
    if(db->leerConfig() == false){
//	QMessageBox::warning
 //		    ( this, tr("Aviso..."),tr("Archivo de configuracion no existe, debera crear uno nuevo."), QMessageBox::Ok,0,0);
//	//mostrar dialogo y guardar datos.
	ecdbd.exec(); 	
    }
    else{
	ecdbd.setConfig(db->getConfig());
	ecdbd.actualizarCampos();
	QMessageBox::information
 		    ( this, tr("Hecho..."),tr("Se han cargado satisfactoriamente los datos de configuracion."), QMessageBox::Ok,0,0);
    }
    
}

void EricleMainWindow::sesion_cambiar_usuario()
{
}

void EricleMainWindow::bibliotecaAbrir_ArchivoAction_activated()
{
    
    QString fileName;
    if ( ofd->exec() == QDialog::Accepted ){
        fileName = ofd->selectedFile();
        if(db->parse((char*)fileName.ascii()) != 0){
	    QMessageBox::warning
 		    ( this, tr("Error..."),tr("Imposible leer.  El<b> archivo</b> dado no es valido."), QMessageBox::Ok,0,0);	
	}
	else{
	    QMessageBox::information
 		    ( this, tr("Hecho..."),tr("Se han cargado satisfactoriamente los datos del archivo de entrada <i>" + fileName + "</i> a la base de datos"), QMessageBox::Ok,0,0);
	}
    }
}

void EricleMainWindow::opcionesConfigAction_activated()
{
    
    ecdbd.setConfig(db->getConfig());/**Asignamos configuracion a dialogo*/
    ecdbd.show();/**mostramos dialogo*/;
    db->setConfig(ecdbd.getConfig());/**Si se guardaron los nuevos datos los recargamos a la informacion de la base de datos*/;
}
void EricleMainWindow::fileExit(){
    close();
}
/**Slot de almacenamiento de configuracion de la base de datos*/
void EricleMainWindow::saveConfig(){
    db->setConfig(ecdbd.getConfig());
    if(db->guardarConfig() == false){
	    QMessageBox::warning
 		    ( this, tr("Error..."),tr("Imposible guardar archivo, verifique que tiene permisos de escritura."), QMessageBox::Ok,0,0);
    };
}

void EricleMainWindow::finalize(){
    db->finalizar();
    
}

EricleMainWindow::~EricleMainWindow(){
    delete(db);
    delete(ofd);    
    delete(cfgfd);
}

void EricleMainWindow::addTitulo()
{
    db->insertarRegistro(eitdlg.getRegistro());
    
}


void EricleMainWindow::addAutor()
{
    db->insertarRegistro(eiadlg.getRegistro());
}

void EricleMainWindow::addLibro()
{
    db->insertarRegistro(eildlg.getRegistro());
}

void EricleMainWindow::usuariosCrearAction_activated()
{
    //eiudlg.exec();
}

void EricleMainWindow::datosAutoresAction_activated()
{
	eiadlg.show();
}

void EricleMainWindow::bibliotecaIngresar_TtuloAction_activated()
{
    eitdlg.show();
}

void EricleMainWindow::datosLibrosAction_activated()
{
    eildlg.show();
}

void EricleMainWindow::VerTodosLosLibrosAction_9_activated()
{
    db->mostrarLibros();
}

void EricleMainWindow::buscarVer_Ventana_de_ResultadosAction_activated()
{
    erw->show();
}

void EricleMainWindow::botonBuscar_released()
{
    int id;
    if(fieldBuscar->text().length() > 0){
        id = fieldBuscar->text().toInt(NULL);    
        if (id >= 0){
            db->buscarLibroIsbn(id);
	}
    }
}

void EricleMainWindow::datosEliminar_LibroAction_activated()
{
    edldlg.show();
}

void EricleMainWindow::helpContents(){
    QMessageBox::information
 		    ( this, tr("Manual de Usuario..."),tr("Podra revisar el manual de usuario ubicado en el directorio <b>doc</b> de la distribucion del software."), QMessageBox::Ok,0,0);
}

void EricleMainWindow::helpAbout(){
    QMessageBox::information
 		    ( this, tr("Acerca De Ericle..."),tr("Ericle V. 0.5.<br> Por <b>(c) 2006 Erik Giron</b> (C#200313492)<br>Para el Segundo proyecto de Manejo e Implementacion de Archivos.<br> Ingenieria, USAC Guatemala<br> Este programa esta distribuido bajo la licencia GPL v2"), QMessageBox::Ok,0,0);
}

void EricleMainWindow::reportesBitcoraAction_activated()
{
    QMessageBox::information
 		    ( this, tr("Bitacora..."),tr("Revisar archivo generado en " + QString::fromAscii(db->getConfig()->path_history)), QMessageBox::Ok,0,0);
}







