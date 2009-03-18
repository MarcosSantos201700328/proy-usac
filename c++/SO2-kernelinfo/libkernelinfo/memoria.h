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
#ifndef LIBKERNELINFOMEMORIA_H
#define LIBKERNELINFOMEMORIA_H

namespace libkernelinfo {

/**
Representa el estado de la memoria actual, con informacion del kernel

	@author Erik Giron, Marlon Manzo, Juan Carlos Lopez, Pedro Domingo <erik_giron@yahoo.com>
*/
class memoria{
    private:
        int total;
        int free;
        int buffers;
        int cached;
        int swapcached;
        int active;
        int inactive;
        int swaptotal;
        int swapfree;
        int dirty;
public:
    memoria();

    ~memoria();
    static memoria* obtenerEstado();

	void setTotal(int theValue)
	{
	        total = theValue;
	}
	

	int getTotal() const
	{
	        return total;
	}

	void setFree(int theValue)
	{
	        free = theValue;
	}
	

	int getFree() const
	{
	        return free;
	}

	void setBuffers(int theValue)
	{
	        buffers = theValue;
	}
	

	int getBuffers() const
	{
	        return buffers;
	}

	void setCached(int theValue)
	{
	        cached = theValue;
	}
	

	int getCached() const
	{
	        return cached;
	}

	void setSwapcached(int theValue)
	{
	        swapcached = theValue;
	}
	

	int getSwapcached() const
	{
	        return swapcached;
	}

	void setActive(int theValue)
	{
	        active = theValue;
	}
	

	int getActive() const
	{
	        return active;
	}

	void setInactive(int theValue)
	{
	        inactive = theValue;
	}
	

	int getInactive() const
	{
	        return inactive;
	}

	void setSwaptotal(int theValue)
	{
	        swaptotal = theValue;
	}
	

	int getSwaptotal() const
	{
	        return swaptotal;
	}

	void setSwapfree(int theValue)
	{
	        swapfree = theValue;
	}
	

	int getSwapfree() const
	{
	        return swapfree;
	}

	void setDirty(int theValue)
	{
	        dirty = theValue;
	}
	

	int getDirty() const
	{
	        return dirty;
	}
	
	
	
	
	
	
	
	
	
	

};

}

#endif
