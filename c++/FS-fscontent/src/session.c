/**@file session.c
   @author Erik Giron
   @brief definiciones de funciones de session.h
*/
#include "session.h"
#include <string.h>
int iniciar_sesion(const char* particion, sesion* actual){
  if(particion!=NULL && actual != NULL){
    actual->inicio = time (NULL);
    actual->fin = 0;
    actual->particion = (char*) particion;
    actual->elementos = 0;
    actual->inserciones = 0;
    return 0;
  }
  return -1;
}

int cerrar_sesion(sesion* actual){
  actual->fin = time(NULL);
  return 0;
}

