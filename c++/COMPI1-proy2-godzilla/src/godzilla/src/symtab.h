/** @file symtab.h
 * Estructuras de la tabla de simbolos.Incluyendo rutinas de insercion, busqueda y eliminacion*/
/*    para el 2do proyecto de Compiladores 1
    (c) 2006 Erik Giron*/
#ifndef SYMTAB_H
#define SYMTAB_H
#include "constantes.h"

/**ESTRUCTURA**/
typedef struct symtab symtab;
typedef struct symbol symbol;
/**Nodo de la tabla de simbolos*/
struct symbol{
  char* id;
  int tipo;
  union {
    char* valorCadena;
    int valorEntero;
    char valorBoolean;
  }valor;
  symbol* siguiente;  
};
/**Tabla de simbolos usando modelo de lista simple*/
struct symtab{
  symbol* primero;
  symbol* actual;  
};

/**METODOS**/

/**Inserta un nuevo simbolo sin comprobar su previa existencia.
@param id identificador de la nueva var.
@param tipo tipo de datos de la var.*/
symbol* insertarSimbolo(char* id, int tipo);
/**Busca y devuelve simbolo segun su identificador dado en el param.
@param id identificador de la variable a buscar*/
symbol* buscarSimbolo(char* id);
/**Elimina todos los registros de la tabla de simbolos*/
void borrarTabla(void);
/**Abre archivo hacia donde se imprimira archivo de tabla de simbolos.
@param filename nombre de archivo al que se le adjuntara la extension xml*/
int openSymtabFile(const char* filename);
/**Cierra archivo hacia donde se escribio tabla de simbolos.*/
int closeSymtabFile(void);
/**Imprime tabla de simbolos a archivo dado.
@param linea linea en donde se leyo el comando vertablasimbolos()*/
int printSymtabFile(int linea);

#endif
