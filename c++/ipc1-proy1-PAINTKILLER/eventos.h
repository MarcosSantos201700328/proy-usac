//  basandome en las librerias creadas por Clayton Walnum ©1992

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
