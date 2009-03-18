/**
@file indicewrapper.h
@author Erik Giron (C#200313492)
@todo ALL

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
#ifndef INDICEWRAPPER_H
#define INDICEWRAPPER_H
#include "indice.h"
/**
Wrapper para struct indice, implementandole las caracteristicas necesarias para que este pueda ser almacenado dentro de un hashmap.

	@author Erik Giron <erik_giron@yahoo.com>
*/
class IndiceWrapper{
    private:
	indice idx;
public:
    IndiceWrapper();
    
    IndiceWrapper(const IndiceWrapper&);
    
    IndiceWrapper(indice& idx);

    ~IndiceWrapper();
    
    indice getIndex() const{
        return idx;
    }
    
    void operator=(IndiceWrapper iw);
    bool operator==(IndiceWrapper iw);
	    
};

#endif
