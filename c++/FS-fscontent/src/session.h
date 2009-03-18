/** @file session.h
Manejador de sesiones, incluye estructuras para mantener datos de la sesion actual 
y funciones para inicio y fin de sesion ademas de almacenamiento a la DB para la tabla
sesion.
@author Erik Giron 
*/
#ifndef SESSION_H
#define SESSION_H
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include "mysqlmanager.h"

/**Estructura de la sesion*/
typedef struct session{
  char* particion;///<dispositivo actual
  time_t inicio;///<hora en formato unix en que inicio la sesion
  time_t fin;///<Hora en formato unix en que finalizo la sesion.
  unsigned int elementos;///<numero de elementos encontrados en la sesion
  unsigned int inserciones;///<numero de inserciones hechas  
} sesion;

//sesion actual; ///< variable global que almacenara la sesion actual

/**Inicializa la sesion con la hora actual*/
int iniciar_sesion(const char* particion, sesion* actual);
/**cierra la sesion con la hora actual, colocandolo en el campo fin*/
int cerrar_sesion(sesion* actual);

/* /\**Almacena una sesion cerrada en la tabla SESION en base de datos*\/ */
/* int guardar_sesion(sesion* actual); */


#endif
