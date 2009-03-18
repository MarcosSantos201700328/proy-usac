/***************************************************************************
 *   Copyright (C) 2008 by Erik Giron, Marlon Manzo, Juan Carlos Lopez, Pedro Domingo   *
 *   erik_giron@yahoo.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "f_main.h"
#include "../libkernelinfo/proceso.h"
#include "../libkernelinfo/modulo.h"
#include "../libkernelinfo/device.h"
#include "../libkernelinfo/proceso.h"
#include "../libkernelinfo/memoria.h"
#include <qtable.h>
#include <qptrlist.h>
#include <qlineedit.h>
#include <qcheckbox.h>
#include <qfiledialog.h>
#include <qtextbrowser.h>
#include <qmessagebox.h>

using namespace libkernelinfo;
f_main::f_main(QWidget *parent, const char *name)
    :frm_main(parent, name)
{
    //Rellenamos tabla de procesos    
    fillProcessTab();
    fillModuleTab();
    fillDeviceTxt();
    fillMemoryTxt();
}

void f_main::kill()
{
    //Obtenemos listado de procesos seleccionados en el tab
    int sel = tableProcess->currentSelection();
    
    QTableSelection s;
    if(sel!=-1){
        s = tableProcess->selection(sel);
        //matamos el proceso seleccionado
        proceso::matar(tableProcess->item(s.topRow(),0)->text().toInt());
    }
    //actualizamos tabla
    updateProcessTab();
    
    
}


void f_main::fillProcessTab()
{
    
    proceso *p = new proceso();
    //obtenemos listado de procesos
    QPtrList<proceso>* listado = p->obtenerLista();
    // Rellenamos cada elemento de la tabla
    QPtrListIterator<proceso> it(*listado);    
    
    this->tableProcess->insertRows(0,it.count());
    int i = 0;
    while( (p = it.current())!= 0)
    {        
        for ( int col = 0; col < tableProcess->numCols(); col++ ) 
        {
            //para PID
            if(col==0)
                tableProcess->setItem( i, col,
                            new QTableItem( tableProcess, 
                                            QTableItem::Never, 
                                            QString::number( p->getPid() 
                                                           ) ) );
            //para Nombre
            if(col==1)
                tableProcess->setItem( i, col,
                                new QTableItem( 
                                               tableProcess, 
                                               QTableItem::Never,
                                               p->getNombre() ) );
            //para status
            if(col==2)
                tableProcess->setItem( i, col,
                                new QTableItem( tableProcess, 
                                        QTableItem::Never,  
                                        p->getStatus() ) );
            //para memoria
            if(col==3)
                tableProcess->setItem( i, col,
                                new QTableItem( tableProcess, 
                                        QTableItem::Never, 
                                        QString::number(p->getMemoria()) + " bytes") );                        
        }
        i++;
        ++it;
    }
}

void f_main::updateProcessTab()
{
    clearProcessTab();
    fillProcessTab();
}

void f_main::clearProcessTab()
{
    for(int i = 0; i < tableProcess->numRows(); i++){
        tableProcess->removeRow(i);
    }
}

void f_main::fillModuleTab()
{
    modulo *m = new modulo();
    //obtenemos listado de procesos
    QPtrList<modulo>* listado = m->obtenerLista();
    // Rellenamos cada elemento de la tabla
    QPtrListIterator<modulo> it(*listado);    
    
    this->tableModule->insertRows(0,it.count());
    int i = 0;
    while( (m = it.current())!= 0)
    {        
        for ( int col = 0; col < tableModule->numCols(); col++ ) 
        {
            //para nombre
            if(col==0)
                tableModule->setItem( i, col,
                                       new QTableItem( tableProcess, 
                                               QTableItem::Never, 
                                               m->getNombre()
                                                              )  );
            //para tam
            if(col==1)
                tableModule->setItem( i, col,
                                       new QTableItem( 
                                               tableProcess, 
                                               QTableItem::Never,
                                               QString::number( m->getTam() ) + " bytes" ) );
            //para dependencia
            if(col==2)
                tableModule->setItem( i, col,
                                       new QTableItem( tableProcess, 
                                               QTableItem::Never,  
                                               m->getDependencia() ) );
        }
        i++;
        ++it;
    }
}

void f_main::cargarModulo()
{
    modulo * m = new modulo();
    if (!txt_nombremodulo->text().isNull() && !txt_nombremodulo->text().isEmpty()){
        m->setNombre(txt_nombremodulo->text());
        m->cargarAlKernel();
        if(chk_cargaralinicio->isChecked())
        {
            m->agregarAlInicio();            
        }
        updateModuleTab();
    }
    delete m;
}

void f_main::descargarModulo()
{
    int sel = tableModule->currentSelection();
    modulo * m;
    QTableSelection s;
    if(sel!=-1){
        s = tableModule->selection(sel);
        m = new modulo();
        //descargamos del kernel el modulo elegido
        m->setNombre(tableModule->item(s.topRow(),0)->text().latin1());
        m->descargarDelKernel();
        delete m;
        //actualizamos tabla
        updateModuleTab();
    }
}

void f_main::updateModuleTab()
{
    clearModuleTab();
    fillModuleTab();
}

void f_main::clearModuleTab()
{
    for(int i = 0; i < tableModule->numRows(); i++){
        tableModule->removeRow(i);
    }
}



void f_main::exportdev()
{
    //Abrimos dialogo de guardar archivo
    QFileDialog* fd = new QFileDialog( this, "file dialog", TRUE );
    fd->setMode( QFileDialog::AnyFile );
    fd->setFilter( "Texto (*.txt)" );    
    fd->setViewMode( QFileDialog::Detail );
    QString fileName;
    //guardamos archivo
    if ( fd->exec() == QDialog::Accepted ){
        fileName = fd->selectedFile();
        device::exportar(&fileName);
    }
    
}

void f_main::fillDeviceTxt()
{
    QString * devinfo = device::obtenerLista();
    devinfo->replace("<div class=\"indented\">","<hr><div class=\"indented\">",false);
            
    txtbox_dev->setText(*devinfo);
    
}

void f_main::fillMemoryTxt()
{
    memoria* m = memoria::obtenerEstado();
    txt_mem->setText(                   
                     "<b>Total:</b> "  + QString::number(m->getTotal()) + " bytes <br>" + 
            "<b>Libre:</b> "  + QString::number(m->getFree()) + " bytes <br>"+
            "<b>Buffers:</b> "  + QString::number(m->getBuffers()) + " <br>"+
            "<b>en Cache:</b> "  + QString::number(m->getCached()) + " bytes  <br>"+
            "<b>en Cache (swap):</b> "  + QString::number(m->getSwapcached()) + " bytes  <br>"+
            "<b>Activo :</b> "  + QString::number(m->getActive()) + " bytes  <br>"+
            "<b>Inactivo :</b> "  + QString::number(m->getInactive()) + " bytes  <br>"+
            "<b>Total para Swap :</b> "  + QString::number(m->getSwaptotal()) + " bytes  <br>"+
            "<b>Libre para Swap :</b> "  + QString::number(m->getSwapfree()) + " bytes  <br>"+
            "<b>Sucia :</b> "  + QString::number(m->getDirty()) + " bytes  <br>"
                    );
    
    
}

void f_main::fileExit()
{
    exit(EXIT_SUCCESS);
}

void f_main::helpAbout()
{
    QMessageBox::about( this, "Acerca de... KernelInfo",
                        "<b>KernelInfo</b> es un visor de recursos del sistema<br><br>"
                                "Copyright 2008 Erik Giron (200313492), Marlon Manzo, Juan Lopez, Pedro Domingo<br>. "
                                "Desarrollado para la practica 2 del curso <b> Sistemas operativos 2</b>, Ingenieria USAC <br><br>"
                                 );
}

void f_main::helpContents()
{
    system("evince manual.pdf");
}