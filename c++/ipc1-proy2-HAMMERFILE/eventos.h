//Copyright (C) 2005  Erik Giron
//  basandome en las librerias creadas por Clayton Walnum ©1992

//This program is free software; you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation; either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program; if not, write to the Free Software Foundation,
//Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

//

#include <bios.h>
//#include "raton.h"
// NOTA: necesito incluir raton.h en el encabezado del .cpp
// para poder usar esta cabecera
#ifndef _EVENTOS_H
#define _EVENTOS_H
#define MBUTTON 1
#define KEYBD 2
#define CR 13
#define ESC 27
#define BACKSP 8
typedef struct EvntMsg
{
int type, // Tipo de Evento
mx, my, // Coordenadas del mouse.
button; // Boton del mouse presionado.
unsigned key; // Tecla presionada.
};
EvntMsg evntmsg;

int KeyEvent(void)
{
// Espera por tecla a presionar.
int key = bioskey(1);
// Prueba si alguna tecla esta presionada.
    if (key) key = bioskey(0);
return key;
}

// Espera por algun evento. cuando se recibe
// construye un mensaje de evento eventmsg.
void GetEvent(EvntMsg &evntmsg)
{
    while ( ( !BotonPulsado() ) && ( !(evntmsg.key = KeyEvent()) ) ) 
    {}
    evntmsg.button = BotonPulsado();
    if (evntmsg.button)
    {
        evntmsg.type = MBUTTON;
	   evntmsg.mx = PosHoriGraf();
	   evntmsg.my = PosVertGraf();
        
        //mouse.GetXY(evntmsg.mx, evntmsg.my);
    }
    else
    {
        evntmsg.type = KEYBD;
        evntmsg.mx = -1;
        evntmsg.my = -1;
    }
}


#endif
