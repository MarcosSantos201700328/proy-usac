/**
@file ericlemainwindow.h
@brief Ventana principal de la aplicacion
@author Erik Giron (C#200313492)
@todo ALL
FIXME Cierre de dialogos de insercion
 * 
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
#ifndef ERICLEMAINWINDOW_H
#define ERICLEMAINWINDOW_H

#include <qfiledialog.h>
	
#include "mainwindow.h"
#include "database.h"
#include "ericleresultsetwidget.h"
#include "qlayout.h"
	/**Ventana principal*/
class EricleMainWindow: public MainWindow {
Q_OBJECT
public:
    EricleMainWindow(QWidget *parent = 0, const char *name = 0);
    ~EricleMainWindow();
public slots:
    virtual void bibliotecaAbrir_ArchivoAction_activated();

public slots:
    virtual void sesion_cambiar_usuario();///<Slot para cambiar usuario
    virtual void opcionesConfigAction_activated();///slot para abrir ventana opciones
    virtual void fileExit();///<slot para salir
    virtual void finalize();///<Finaliza la sesion
    virtual void saveConfig();
    virtual void datosLibrosAction_activated();
    virtual void bibliotecaIngresar_TtuloAction_activated();
    virtual void datosAutoresAction_activated();
    virtual void usuariosCrearAction_activated();
    virtual void addLibro();
    virtual void botonBuscar_released();
    virtual void buscarVer_Ventana_de_ResultadosAction_activated();
    virtual void addTitulo();
    virtual void addAutor();
    virtual void VerTodosLosLibrosAction_9_activated();
    virtual void reportesBitcoraAction_activated();
    virtual void datosEliminar_LibroAction_activated();
    virtual void helpContents();
    virtual void helpAbout();
    protected:
	EricleResultWidget* erw;
	database* db;
	QFileDialog* ofd;
	QFileDialog* cfgfd;
    
    signals:
	void saliendo();

};

#endif
