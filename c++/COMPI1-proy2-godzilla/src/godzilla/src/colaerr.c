/** @file colaerr.c
 * Implementacion de la cola almacenadora de errores .
  Contiene rutinas de impresion hacia archivo XML*/
/* Godzilla
* Proyecto No. 2 de Lenguajes y Compiladores 1
* (c) 2006 Erik Giron C# 200313492
*/
#ifdef __cplusplus
extern "C"{
#endif
#include "colaerr.h"
#ifdef __cplusplus
}
#endif

static colaErr erroresLexicos, erroresSintacticos, erroresSemanticos;
static FILE* errfile;


int huboErrorSintactico = 0; /*Es 0 si no ha habido error Sintactico*/
int huboErrorSemantico = 0; /*Es 0 si no ha habido error Semantico*/
int huboErrorLexico = 0; /*Es 0 si no ha habido error Semantico*/
/**Agrega un error a la cola de errores*/
void encolarError(colaErr* cerr, tipoError* err){
  nodoColaErr* nuevo;
  nuevo = (nodoColaErr*) malloc(sizeof(nodoColaErr));
  nuevo->err = err;
  nuevo->siguiente=NULL;
  
  if(cerr->ultimo) cerr->ultimo->siguiente = nuevo;  
  cerr->ultimo = nuevo;
  
  if(!(cerr->primero)) cerr->primero= nuevo;  
}
/**Devuelve primer error en la cola de erroes*/
tipoError* sacarError(colaErr* cerr){
  nodoColaErr* nodo;
  tipoError* v;
  
  nodo = cerr->primero;
  if(!nodo) return NULL;
  
  cerr->primero = nodo->siguiente;
  
  v = nodo->err;
  
  free(nodo);
  
  if(!(cerr->primero)) cerr->ultimo = NULL;
  return v; 
}
 /**Agrega mensaje a la cola de errores lexicos */
void errorLexico(char* msg){
  huboErrorLexico = -1;
  tipoError* nuevo = (tipoError*) malloc(sizeof(tipoError));
  nuevo->desc = (char*) malloc(sizeof(char*) * ( strlen(msg) + 1));
  nuevo->linea = line_num;
  nuevo->col = column;
  strcpy(nuevo->desc,msg);    
  encolarError(&erroresLexicos,nuevo);
} 
/**Agrega mensaje a la cola de errores sintacticos*/
void errorSintactico(char* msg){
  huboErrorSintactico = -1;
  tipoError* nuevo = (tipoError*) malloc(sizeof(tipoError));
  nuevo->desc = (char*) malloc(sizeof(char*) * ( strlen(msg) + 1));
  nuevo->linea = line_num;
  nuevo->col = column;
  strcpy(nuevo->desc,msg);    
  encolarError(&erroresSintacticos,nuevo);

}
 /**Agrega mensaje a la cola de errores*/
void errorSemantico(char* msg,int numLinea){
  huboErrorSemantico = -1;
  tipoError* nuevo = (tipoError*) malloc(sizeof(tipoError));
  nuevo->desc = (char*) malloc(sizeof(char*) * ( strlen(msg) + 1));
  nuevo->linea = numLinea;
  nuevo->col = 0;
  strcpy(nuevo->desc,msg);    
  encolarError(&erroresSemanticos,nuevo);
}
/**Escribe colas de errores a archivo xml*/
int escribirErrorLogXML(const char* filename){
  tipoError* tmp= NULL;
  int i;
  if((errfile=fopen(filename,"w")) != NULL){
    printf("Generando archivo de errores ...\n");
    fprintf(errfile,"<?xml version=\"1.0\"?>\n");
    fprintf(errfile,"<errores>\n");
    if(erroresLexicos.primero != NULL){
      fprintf(errfile,"\t<lexicos>\n");
      i = 1;
      while (erroresLexicos.primero!=NULL){
	tmp = sacarError(&erroresLexicos);
	fprintf(errfile,"\t\t<error numero=\"%d\">\n",++i);
	fprintf(errfile,"\t\t\t<linea>%d</linea>\n",tmp->linea);
	fprintf(errfile,"\t\t\t<columna>%d</columna>\n",tmp->col);
	fprintf(errfile,"\t\t\t<descripcion>%s</descripcion>\n",tmp->desc);
	fprintf(errfile,"\t\t</error>\n");	
      }
      fprintf(errfile,"\t</lexicos>\n");     
      free(tmp->desc);
      free(tmp);
    }
    if(erroresSintacticos.primero != NULL){
      fprintf(errfile,"\t<sintacticos>\n");
      i = 1;
      while (erroresSintacticos.primero!=NULL){
	tmp = sacarError(&erroresSintacticos);
	fprintf(errfile,"\t\t<error numero=\"%d\">\n",++i);
	fprintf(errfile,"\t\t\t<linea>%d</linea>\n",tmp->linea);
	fprintf(errfile,"\t\t\t<columna>%d</columna>\n",tmp->col);
	fprintf(errfile,"\t\t\t<descripcion>%s</descripcion>\n",tmp->desc);
	fprintf(errfile,"\t\t</error>\n");	
      }
      fprintf(errfile,"\t</sintacticos>\n");     
      free(tmp->desc);
      free(tmp);
    }
    if(erroresSemanticos.primero != NULL){
      fprintf(errfile,"\t<semanticos>\n");
      i = 1;
      while (erroresSemanticos.primero!=NULL){
	tmp = sacarError(&erroresSemanticos);
	fprintf(errfile,"\t\t<error numero=\"%d\">\n",++i);
	fprintf(errfile,"\t\t\t<linea>%d</linea>\n",tmp->linea);
	fprintf(errfile,"\t\t\t<descripcion>%s</descripcion>\n",tmp->desc);
	fprintf(errfile,"\t\t</error>\n");	
      }
      fprintf(errfile,"\t</semanticos>\n");     
      free(tmp->desc);
      free(tmp);
    }
    fprintf(errfile,"</errores>\n");
    fclose(errfile);
    return 0;
  }  
  return -1;
}
