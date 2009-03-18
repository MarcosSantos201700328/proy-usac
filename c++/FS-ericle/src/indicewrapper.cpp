/**
@file indicewrapper.cpp
@brief Implementacion de indicewrapper.h
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
#include "indicewrapper.h"

IndiceWrapper::IndiceWrapper()
{
}


IndiceWrapper::IndiceWrapper(const IndiceWrapper& iw )
{
        idx.id = iw.getIndex().id;
	idx.tipoclave= iw.getIndex().tipoclave;
	idx.num_registro = iw.getIndex().num_registro;
	
	idx.bloque_indice_indir = iw.getIndex().bloque_indice_indir ;
	idx.siguiente = iw.getIndex().siguiente;
	idx.anterior = iw.getIndex().anterior;
	
	idx.borrado = iw.getIndex().borrado;

	idx.esInicio = iw.getIndex().esInicio;
}

IndiceWrapper::~IndiceWrapper(){
}
IndiceWrapper::IndiceWrapper(indice& pidx)
{
	idx.id = pidx.id;
	idx.tipoclave= pidx.tipoclave;
	idx.num_registro = pidx.num_registro;
	
	idx.bloque_indice_indir = pidx.bloque_indice_indir ;
	idx.siguiente = pidx.siguiente;
	idx.anterior = pidx.anterior;
	
	idx.borrado = pidx.borrado;

	idx.esInicio = pidx.esInicio;
}

void IndiceWrapper::operator=(IndiceWrapper iw){
    idx.id = iw.getIndex().id;
	idx.tipoclave= iw.getIndex().tipoclave;
	idx.num_registro = iw.getIndex().num_registro;
	
	idx.bloque_indice_indir = iw.getIndex().bloque_indice_indir ;
	idx.siguiente = iw.getIndex().siguiente;
	idx.anterior = iw.getIndex().anterior;
	
	idx.borrado = iw.getIndex().borrado;

	idx.esInicio = iw.getIndex().esInicio;
}

bool IndiceWrapper::operator==(IndiceWrapper iw){
    if((idx.id == (iw.getIndex().id)) && (idx.tipoclave == (iw.getIndex().tipoclave)))
        return true;
    return false;
}

