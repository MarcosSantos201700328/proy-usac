#include "registro.h"
#include "tipos.h"
#include <stdlib.h>
#include <string.h>
/**Crea un registro basado en los parametros.*/
registro* crearRegistro (void* dato,int tipo){
    registro* nuevo = (registro*) malloc(sizeof (registro));
    	switch(tipo){
	    case T_AUTOR:
		memcpy(&(nuevo->dato.rAutor),dato,sizeof(r_autor));
		break;		
	    case T_CONTENIDO:
		memcpy(&(nuevo->dato.rContenido),dato,sizeof(r_contenido));
		break;
	    case T_LIBRO:
		memcpy(&(nuevo->dato.rLibro),dato,sizeof(r_libro));
		break;
	    case T_PRESTAMO:
		memcpy(&(nuevo->dato.rPrestamo),dato,sizeof(r_prestamo));
		break;
	    case T_TIPOUSUARIO:
		memcpy(&(nuevo->dato.rTipoUsuario),dato,sizeof(r_tipousuario));
		break;
	    case T_TITULO:
		memcpy(&(nuevo->dato.rTitulo),dato,sizeof(r_titulo));
		break;
	    case T_USUARIO:
		memcpy(&(nuevo->dato.rUsuario),dato,sizeof(r_usuario));
		break;	
	}    
    nuevo->tipo = tipo;
    nuevo->borrado = 0;
    return nuevo;
}
