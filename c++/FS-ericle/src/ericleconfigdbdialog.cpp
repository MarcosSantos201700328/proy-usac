/**
@file ericleconfigdbdialog.cpp
@brief Implementacion de ericleconfigdbdialog.h
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
#include "ericleconfigdbdialog.h"
#include "qlineedit.h"
#include "qstring.h"
#include "qmessagebox.h"
#include <cstring>
	
EricleConfigDbDialog::EricleConfigDbDialog(QWidget *parent, const char *name)
    :ConfigDialog(parent, name)
{
    
}

void EricleConfigDbDialog::actualizarCampos(){
    fieldTamCre->setText(QString::number(config.tam_crecimiento));
    fieldDbLog->setText(config.path_history);
    fieldDbFiles->setText(config.path_datafile);
    fieldDbTmp->setText(config.path_tmpdir);	
}
void EricleConfigDbDialog::accept()
{
    bool ok;
    config.tam_crecimiento = this->fieldTamCre->text().toInt(&ok,10);///< Tamano de superbloques
    if((fieldDbLog->text().length() < 255) &&  (fieldDbLog->text().length() > 0)
	&& (fieldDbFiles->text().length() < 255 ) && (fieldDbFiles->text().length() > 0 )  
	&& (fieldDbTmp->text().length() < 255 ) &&  (fieldDbTmp->text().length() >0 )
      ){
	strncpy(config.path_history,fieldDbLog->text().ascii(),254);
	strncpy(config.path_datafile,fieldDbFiles->text().ascii(),254);
	strncpy(config.path_tmpdir,fieldDbTmp->text().ascii(),254);
	this->close();
	actualizarCampos();
        emit accepted();
    }
    else{
	QMessageBox::information
		( this, tr("Aviso..."),tr("Ingrese valores con un numero de caracteres > 0 y < 255."), QMessageBox::Ok,0,0);
    }
    //actualizarCampos();
//    emit accepted();
}

metadata* EricleConfigDbDialog::getConfig(){
    return &config;
}

void EricleConfigDbDialog::setConfig(metadata* data){
    if(data != NULL){
	memcpy(&config,data,sizeof(metadata));
        actualizarCampos();	
    }
}