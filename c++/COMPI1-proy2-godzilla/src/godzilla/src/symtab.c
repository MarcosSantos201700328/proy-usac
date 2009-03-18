/** @file symtab.c
 * Implementacion de la tabla de simbolos.Incluye la implementacion de rutinas de insercion, busqueda y eliminacion*/
/*    para el 2do proyecto de Compiladores 1
    (c) 2006 Erik Giron*/
#ifdef __cplusplus
extern "C"{
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"
#include "constantes.h"

#ifdef __cplusplus
}
#endif

static symtab tabla;/**Tabla de simbolos*/
static FILE* symtabfile = NULL; /**Archivo de salida de la tabla de simbolos*/

/**Inserta un nuevo simbolo sin comprobar su previa existencia*/
symbol* insertarSimbolo(char* id, int tipo){
  tabla.actual = tabla.primero;
  /*Nos vamos al ultimo registro*/
  if (tabla.actual!=NULL)
    while(((tabla.actual)->siguiente)!=NULL){
      tabla.actual = tabla.actual->siguiente;
    }   
  
  symbol* nuevo = (symbol*) malloc(sizeof(symbol)); /*Creamos nuevo*/

  /*Asignamos campos*/
  nuevo->siguiente = NULL;
  nuevo->id = (char*) malloc(sizeof(char)*(strlen(id)+1));
  strcpy(nuevo->id,id);
  nuevo->tipo = tipo;
  /* asignamos el valor predeterminado al tipo correcto*/
  switch(nuevo->tipo){ 
  case T_INTEGER:    
    nuevo->valor.valorEntero = 0;
    break;
  case T_BOOLEAN:
    nuevo->valor.valorBoolean = 0;
    break;
  case T_STRING:
    nuevo->valor.valorCadena = NULL;
    break;  
  }

  /*encadenamos el nuevo dato con el valor anterior*/
  if (tabla.actual!=NULL)
    (tabla.actual)->siguiente = nuevo; 
  else
    tabla.primero=nuevo;
  /*devolvemos simbolo recien creado*/
  return nuevo;
}
/**Busca y devuelve simbolo segun su identificador dado en el param*/
symbol* buscarSimbolo(char* id){
  tabla.actual = tabla.primero;
  if(tabla.actual!=NULL){
    while(((tabla.actual)->siguiente)!=NULL){
      if(strcasecmp((tabla.actual)->id,id) == 0)
	return tabla.actual;
      tabla.actual = tabla.actual->siguiente;
    }
    if(strcasecmp((tabla.actual)->id,id) == 0)
      return tabla.actual;
  }
  return NULL;
}

void borrarNodos(symbol* s){
  if(s->siguiente !=NULL)
    borrarNodos(s->siguiente);
  free(s->id);
  if(s->tipo == T_STRING)
    /**No usar free() da error SIGABRT*/
    s->valor.valorCadena = 0;
  s->siguiente = NULL;
  free(s);
  s=NULL;
  
}

/**Elimina todos los registros de la tabla de simbolos*/
void borrarTabla(){
  if(tabla.primero !=NULL)
#ifdef Q_OS_WIN
    borrarNodos(tabla.primero);
#endif
  tabla.primero=0;
  tabla.actual = 0;
}

/**Abre archivo hacia donde se imprimira archivo de tabla de simbolos.
@param filename nombre de archivo al que se le adjuntara la extension xml*/
int openSymtabFile(const char* filename){
  char* symtabfilename = (char*) malloc(sizeof(char)*((strlen(filename) + 1) + 8));
  *symtabfilename=0;
  strcat(symtabfilename,filename);
  strcat(symtabfilename,".tab.xml");
  if((symtabfile = fopen(symtabfilename,"w"))!=NULL){/**trunca a cero el archivo xml*/
    fprintf(symtabfile,"<?xml version=\"1.0\"?>\n");
    fprintf(symtabfile,"<symbols>\n");
    freopen(symtabfilename,"a",symtabfile);
  }
  free(symtabfilename);
  return 0;
}
/**Cierra archivo hacia donde se escribio tabla de simbolos.*/
int closeSymtabFile(){
  if(symtabfile !=NULL){
    fprintf(symtabfile,"</symbols>\n");
    fclose(symtabfile);
  }
  return 0;
}
/**Imprime tabla de simbolos a archivo dado.
@param linea linea en donde se leyo el comando vertablasimbolos()*/
int printSymtabFile(int linea){
  int i = 1;
  
  if(symtabfile !=NULL){
    printf("Generando archivo de tabla de simbolos...\n");
    fprintf(symtabfile,"\t<symtab at=\"%d\">\n",linea);
    tabla.actual=tabla.primero;
    while(tabla.actual!=NULL){
      fprintf(symtabfile,"\t\t<symbol entry=\"%d\">\n",i);
      fprintf(symtabfile,"\t\t\t<identificador>%s</identificador>\n",tabla.actual->id);
      switch(tabla.actual->tipo){
	case T_STRING:
	  fprintf(symtabfile,"\t\t\t<tipo> CADENA </tipo>\n");
	  fprintf(symtabfile,"\t\t\t<valor> %s </valor>\n",tabla.actual->valor.valorCadena);
	break;
	case T_INTEGER:
	  fprintf(symtabfile,"\t\t\t<tipo> ENTERO </tipo>\n");
	  fprintf(symtabfile,"\t\t\t<valor> %d </valor>\n",tabla.actual->valor.valorEntero);
	break;
	case T_BOOLEAN:
	  fprintf(symtabfile,"\t\t\t<tipo> BOOLEANO </tipo>\n");
	  if(tabla.actual->valor.valorBoolean == 0)
	    fprintf(symtabfile,"\t\t\t<valor>FALSO </valor>\n");
	  else
	    fprintf(symtabfile,"\t\t\t<valor>TRUE </valor>\n");
        break;  
      }
      fprintf(symtabfile,"\t\t</symbol>\n");      
      tabla.actual = tabla.actual->siguiente;
      i++;      
    }
    fprintf(symtabfile,"\t</symtab>\n");
  }
  return 0;
}
