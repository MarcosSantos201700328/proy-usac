/** @file colaerr.h
 * Definiciones de la cola almacenadora de errores .*/
/* Godzilla
* Proyecto No. 2 de Lenguajes y Compiladores 1
* (c) 2006 Erik Giron C# 200313492
*/
#ifndef COLAERR_H
#define COLAERR_H
#ifdef __cplusplus
extern "C"{
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



extern int line_num;
extern int column;


typedef struct nodoColaErr nodoColaErr;
typedef struct colaErr colaErr;
typedef struct tipoError tipoError;

/**Clase de almacenamiento de error*/
struct tipoError{
  int linea;
  int col;
  char* desc;  
};
/**Nodo de la cola de errores*/
struct nodoColaErr{
  tipoError* err;
  nodoColaErr* siguiente;  
};
/**Cola de errores*/
struct colaErr{
  nodoColaErr* primero;
  nodoColaErr* ultimo;
};


void encolarError(colaErr* cerr, tipoError* err);/**Agrega un error a la cola de errores*/
tipoError* sacarError(colaErr* cerr);/**Devuelve primer error en la cola de erroes*/

void errorLexico(char* msg); /**Agrega mensaje a la cola de errores lexicos */
void errorSintactico(char* msg); /**Agrega mensaje a la cola de errores sintacticos*/
void errorSemantico(char* msg,int numlinea); /**Agrega mensaje a la cola de errores semanticos*/
int escribirErrorLogXML(const char* filename);/**Escribe colas de errores a archivo xml*/

#ifdef __cplusplus
};
#endif

#endif
