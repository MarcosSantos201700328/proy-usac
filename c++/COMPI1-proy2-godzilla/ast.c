#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

extern FILE* yyout;


/**FUNCIONES DE INSERCION**/
nodo* refNodoHijo(int tipo, void* dato){
  nodo* nuevo = (nodo*) malloc(sizeof(nodo));
  nuevo->dato = dato;
  nuevo->tipo = tipo;
  return nuevo;
}


nodo* insertarConstante(int tipo, int dato){
  constante* nuevo = (constante*) malloc(sizeof(constante));
  nuevo->tipo = tipo;
  nuevo->dato = dato;
  return (refNodoHijo(T_CONSTANTE,nuevo));  
}

nodo* insertarVariable(char* ident){
  variable* nuevo = (variable*) malloc(sizeof(variable));
  nuevo->identificador = (char*) malloc(sizeof(char)*(strlen(ident)+1));
  strcpy(nuevo->identificador,ident);
  free(ident);
  return (refNodoHijo(T_VARIABLE,nuevo));
}

nodo* insertarCadena(char* cadena){
  expr* nuevo = (expr*) malloc(sizeof(expr));
  nuevo->tipo = T_LITERAL;
  nuevo->hijo.literal = (char*) malloc(sizeof(char)*(strlen(cadena)+1));
  strcpy(nuevo->hijo.literal,cadena);
  free(cadena);
  return (refNodoHijo(T_EXPR,nuevo));
}


nodo* insertarOperacion(int operador, nodo* l, nodo* r){
  operacion* nuevo = (operacion*) malloc(sizeof(operacion));
  nuevo->operador = operador;
  nodo* lexpr = insertarExpresion(l);
  nodo* rexpr = insertarExpresion(r);
  nuevo->loper = (expr*) lexpr->dato;
  nuevo->roper = (expr*) rexpr->dato;
  return (refNodoHijo(T_OPERACION,nuevo));
}

nodo* insertarExpresion(nodo* n){
  expr* nuevo;
  if ((n->tipo) != T_EXPR){ /*Si no es expresion asignamos tipo*/
    nuevo = (expr*) malloc(sizeof(expr));
    nuevo->tipo = n->tipo;
    switch(nuevo->tipo){
      /*Asignamos nodo hijo*/
    case T_OPERACION:
      nuevo->hijo.oper = (operacion*) n->dato;
      break;
    case T_CONSTANTE:
      nuevo->hijo.cnst = (constante*) n->dato;
      break;
    case T_VARIABLE:
      nuevo->hijo.var = (variable*) n->dato;
      break;
    }    
  }
  else{ /*si es expresion solo copiamos*/
    nuevo = (expr*) n->dato;
  }
  return (refNodoHijo(T_EXPR,nuevo));
}

nodo* insertarAsignacion(char* identificador, nodo* expresion){
  asignacion* nuevo = (asignacion*) malloc(sizeof(asignacion));
  nuevo->variable = (char*) malloc(sizeof(char)*(strlen(identificador)+1));
  strcpy(nuevo->variable,identificador);
  nuevo->hijo = (expr*) expresion->dato;
  return (refNodoHijo(T_ASIGNACION,nuevo));
}

nodo* insertarSentencia(int tipo,nodo* n,int nlinea){
  sentencia* nuevo = (sentencia*) malloc(sizeof(sentencia));
  nuevo->tipo = n->tipo;
  switch(nuevo->tipo){
  case T_IF:
    nuevo->hijo.if_nodo = (enunciadoIf*) n->dato;
    break;
  case T_WHILE:
    nuevo->hijo.while_nodo = (enunciadoWhile*) n->dato;
    break;
  case T_FOR:
    nuevo->hijo.for_nodo = (enunciadoFor*) n->dato;
    break;
  case T_DECLARACION:
    nuevo->hijo.decl = (declaracion*) n->dato;
    break;
  case T_CALL:
    nuevo->hijo.call = (printCall*) n->dato;
    break;
  case T_ASIGNACION:
    nuevo->hijo.asig = (asignacion*) n->dato;
    break;
  }
  nuevo->numLinea = nlinea;
  nuevo->siguiente = 0;
  return (refNodoHijo(T_SENTENCIA,nuevo));  
  
}
nodo* concatenarSentencia(nodo* n1, nodo* n2){
  sentencia* s1 = (sentencia*) n1->dato;
  sentencia* s2 = (sentencia*) n2->dato;
/*   /\*   asigna s2 como siguiente de s1 *\/ */
/*   s1->siguiente = s2; */
/*   /\*   retorna el nodo n1 *\/ */
/*   return n1; */
  /*   asigna s2 como siguiente de s1 */
  s2->siguiente = s1;
  /*   retorna el nodo n1 */
  return n2;
}

nodo* insertarDeclaracion(char* identificador, int tipoDato){
  declaracion* nuevo = (declaracion*) malloc(sizeof(declaracion));
  nuevo->tipo = tipoDato;
  nuevo->identificador = (char*) malloc(sizeof(char)*(strlen(identificador)+1));
  strcpy(nuevo->identificador,identificador);
  return (refNodoHijo(T_DECLARACION,nuevo));  
}

nodo* insertarEnunciadoIf(nodo* expresion, nodo* nthen, nodo* nelse){
  enunciadoIf* nuevo = (enunciadoIf*) malloc(sizeof(enunciadoIf));
  nuevo->test = (expr*) expresion->dato;
  nuevo->then_stmt = (sentencia*) nthen->dato;
  if(nelse != NULL)
    nuevo->else_stmt = (sentencia*) nelse->dato;
  else
    nuevo->else_stmt = NULL;
  return (refNodoHijo(T_IF,nuevo));
}

nodo* insertarCicloWhile(nodo* expresion, nodo* stmt){
  enunciadoWhile* nuevo = (enunciadoWhile*) malloc(sizeof(enunciadoWhile));
  nuevo->test = (expr*) expresion->dato;
  nuevo->cuerpo = (sentencia*) stmt->dato;  
  return (refNodoHijo(T_WHILE,nuevo));
}

nodo* insertarCicloFor(char* idx, int asig, int lim, nodo* body){
  enunciadoFor* nuevo = (enunciadoFor*) malloc(sizeof(enunciadoFor));
  nuevo->indice = (char*) malloc(sizeof(char)*(strlen(idx+1)));
  strcpy(nuevo->indice, idx);
  nuevo->asignacion = asig;
  nuevo->limite = lim;
  nuevo->cuerpo = (sentencia*) body->dato;
  return (refNodoHijo(T_FOR,nuevo));
}

nodo* insertarToken(int tipo, void* dato){
  token* nuevo = (token*) malloc(sizeof(token));
  nuevo->siguiente = 0;
  nuevo->tipo = tipo;
  switch(nuevo->tipo){
  case T_CADENA:
  case T_STRING:
    nuevo->hijo.cadena = (char*) malloc(sizeof(char) * (strlen((char*) dato)+1));
    strcpy(nuevo->hijo.cadena,(char*)(dato));
    free(dato);
    break;
  case T_IDENTIFICADOR:
    nuevo->hijo.identificador = (char*) malloc(sizeof(char) * (strlen((char*) dato)+1));
    strcpy(nuevo->hijo.identificador,(char*)(dato));
    free(dato);
    break;
  case T_NUMERO:
  case T_INTEGER:
    nuevo->hijo.numero = *((int*)dato);
    break;
  }
  return (refNodoHijo(T_TOKEN,nuevo));
}

nodo* concatenarTokens(nodo* t1, nodo* t2){
  token* tmp1 = (token*) t1->dato;
  token* tmp2 = (token*) t2->dato;
  tmp2->siguiente = tmp1;
  return t2;
}

nodo* insertarLlamada(nodo* n){
  printCall* nuevo = (printCall*) malloc(sizeof(printCall));
  nuevo->hijos = (token*) n->dato;
  return (refNodoHijo(T_CALL,nuevo));
}

/*Crea raiz para el arbol ast dado como parametro*/
void crearRaiz(nodo* n, ast* tree){
  raiz* root = (raiz*) malloc(sizeof(raiz));
  root->hijo= (sentencia*) n->dato;
  if( tree == NULL){
    tree = (ast*) malloc(sizeof(tree));
  }
  tree->root = root;
  tree->actual = (void*) root->hijo;
  tree->tipoActual = T_SENTENCIA;
}

/**FUNCIONES DE RECORRIDO/EJECUCION*/

void error(char* msg,int tipo,void* dato){
  //transitorio, cambiar por funcion original
  sentencia* tmpStmt;
  if (tipo == T_SENTENCIA){
    tmpStmt = (sentencia*) dato;
    errorSemantico(msg,tmpStmt->numLinea);
  }
  else{
    errorSemantico(msg,0);
  }
  //  printf(msg);
}

/*Recorre el arbol y escribe resultado en archivo salida*/
int recorrerArbol(ast* tree,char* filename){
  //outerr = fopen(filename,"w+b");  
  if(tree!=NULL){
    if(tree->root!=NULL)
      return recorrerSentencia(tree->root->hijo);    
  }
  return -1;
  //fclose(outerr);
}

int recorrerSentencia(sentencia* s){
  if(s!=NULL){
    recorrerSentencia(s->siguiente); /*recursion del ultimo hacia el primero*/
    if(evaluarSentencia(s) != 0){
      error("El error ocurrio dentro de esta sentencia",T_SENTENCIA,s);
      return -1;
    }    
  } 
  return 0;
}

int evaluarSentencia(sentencia* s){
  //  int ret = 0;
  switch(s->tipo){
  case(T_DECLARACION):
    return evaluarDeclaracion(s->hijo.decl);    
    break;
  case(T_ASIGNACION):
    return evaluarAsignacion(s->hijo.asig);
    break;
  case(T_IF):
    return evaluarIf(s->hijo.if_nodo);
    break;
  case(T_WHILE):
    return evaluarWhile(s->hijo.while_nodo);
    break;
  case(T_FOR):
    return evaluarFor(s->hijo.for_nodo);
    break;
  case(T_CALL):
    return evaluarPrintCall(s->hijo.call);
    break;
  default:
    return -1;
    break;
  }
}

int evaluarDeclaracion(declaracion* d){
  symbol* s = buscarSimbolo(d->identificador);
  if(s==NULL){
    insertarSimbolo(d->identificador,d->tipo);
    return 0;
  }
  error("variable ya existe",T_DECLARACION,d); return -1;    
}

int evaluarAsignacion(asignacion* a){
  int ret = -1;
  symbol* tmp = buscarSimbolo(a->variable);
  nodo* n = NULL;
  if(tmp!=NULL){
    n = evaluarExpresion(a->hijo);
    if(n!=NULL){
      if(n->tipo == tmp->tipo){ /* resultado debe ser del mismo tipo */
	if((n->tipo == T_NUMERO) || (n->tipo == T_BOOLEAN) || (n->tipo == T_INTEGER)) /* si es valor numerico copiamos directamente hacia el simbolo*/
	  tmp->valor.valorEntero= *((int*)(n->dato)); /*actualizamos la tabla de simbolos*/
	else{ /* Actualizamos la tabla de simbolos con una cadena*/
	  if (tmp->valor.valorCadena == NULL) // si el simbolo no ha sido asignado
	    tmp->valor.valorCadena = (char*) malloc(sizeof(char) * (strlen((char*)(n->dato))));	   
	  strcpy(tmp->valor.valorCadena,n->dato);
	}
	ret = 0;
      }
      else{
	error("Imposible asginar, tipos no concuerdan",T_ASIGNACION,a);
	ret = -1;
      }
    }
    else{
      error("Imposible asignar, hubo un error en la evaluacion",T_ASIGNACION,a);
      ret = -1;
    }
    return ret;
  }
  error("Imposible asignar, variable no existe",T_ASIGNACION,a);
  return ret;
}

nodo* evaluarExpresion(expr* e){
  nodo* nuevo = NULL;
  symbol* tmp = NULL;
  switch(e->tipo){
  case T_OPERACION:
    return evaluarOperacion(e->hijo.oper);
    break;
  case T_CONSTANTE:
    nuevo = (nodo*) malloc(sizeof(nodo));
    /*Sustituye tipo de dato NUMERO a INTEGER para fines de evaluacion*/
    if(e->hijo.cnst->tipo == T_NUMERO)
      nuevo->tipo = T_INTEGER;
    else
      nuevo->tipo = e->hijo.cnst->tipo;
    nuevo->dato = malloc(sizeof(int));
    memcpy(nuevo->dato,(void*)(&(e->hijo.cnst->dato)),sizeof(int));
    break;
  case T_VARIABLE:/*Sustituimos la variable y la convertimos a literal*/
    nuevo = (nodo*) malloc(sizeof(nodo));
    tmp = buscarSimbolo(e->hijo.var->identificador);
    if(tmp != NULL){
      nuevo->tipo = tmp->tipo;
      switch(tmp->tipo){
      case T_BOOLEAN:
      case T_INTEGER:
	nuevo->dato = malloc(sizeof(int));
	memcpy(nuevo->dato,(void*)(&(tmp->valor.valorEntero)),sizeof(int));
	break;
      case T_STRING:
	nuevo->dato = malloc(sizeof(char)*(strlen(tmp->valor.valorCadena)+1));
	strcpy((char*)(nuevo->dato),(tmp->valor.valorCadena));
	break;
      }
    }
    else{
      error("Variable no declarada",T_EXPR,e);
      free(nuevo);
      return NULL;
    }
    break;
  case T_LITERAL:
    nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->tipo = T_STRING;
    nuevo->dato = malloc(sizeof(char)*(strlen(e->hijo.literal)+1));
    strcpy((char*)nuevo->dato,(e->hijo.literal));
    break;
  }
  return nuevo;    
}

nodo* evaluarOperacion(operacion* o){
  nodo* n1 = NULL ;
  nodo* n2 = NULL ;
  n1 = evaluarExpresion(o->loper);
  n2 = evaluarExpresion(o->roper);
  if( n1!=NULL && n2!=NULL)
    switch(o->operador){
    case OP_AND:
      return evaluarAnd(n1,n2);
      break;
    case OP_OR:
      return evaluarOr(n1,n2);
      break;
    case OP_EQ:
      return evaluarEQ(n1,n2);
      break;
    case OP_NEQ:
      return evaluarNEQ(n1,n2);
      break;
    case OP_GT:
      return evaluarGT(n1,n2);
      break;
    case OP_GET:
      return evaluarGET(n1,n2);
      break;
    case OP_LT:
      return evaluarLT(n1,n2);
      break;
    case OP_LET:
      return evaluarLET(n1,n2);
      break;
    case OP_SUMA:
      return evaluarSuma(n1,n2);
      break;
    case OP_RESTA:
      return evaluarResta(n1,n2);
      break;
    case OP_MULT:
      return evaluarMult(n1,n2);
      break;
    case OP_DIV:
      return evaluarDiv(n1,n2);
      break;
    }
  return NULL;
}

nodo* evaluarAnd(nodo* n1, nodo* n2){
  int* valor = 0;
  if((n1->tipo == T_BOOLEAN) && (n1->tipo== n2->tipo)){
    valor = (int*) malloc(sizeof(int));
    if(((*(int*)(n1->dato)) == T_TRUE)
       && (*(int*)(n2->dato) == T_TRUE))
      *valor = T_TRUE;
    else
      *valor = T_FALSE;
    //borramos nodos del arbol de expresion que ya no se van a usar
    free(n1->dato); free(n2->dato); free(n1); free(n2);
    /*retornamos referencia a nuevo nodo*/
    return refNodoHijo(T_BOOLEAN,(char*)valor);
  }
  else{
    error("Evaluacion logica se debe realizar con tipos boolean",T_OPERACION,NULL);
    //borramos nodos del arbol de expresion que ya no se van a usar
    free(n1->dato); free(n2->dato); free(n1); free(n2);
    return NULL;
  }
}

nodo* evaluarOr(nodo* n1, nodo* n2){
  int* valor = 0;
  if((n1->tipo == T_BOOLEAN) && (n1->tipo== n2->tipo)){
    valor = (int*) malloc(sizeof(int));
    if(((*(int*)(n1->dato)) == T_TRUE)
       || (*(int*)(n2->dato) == T_TRUE))
      *valor = T_TRUE;
    else
      *valor = T_FALSE;
    //borramos nodos del arbol de expresion que ya no se van a usar
    free(n1->dato); free(n2->dato); free(n1); free(n2);
    /*retornamos referencia a nuevo nodo*/
    return refNodoHijo(T_BOOLEAN,(char*)valor);
  }
  else{
    error("Evaluacion logica se debe realizar con tipos boolean",T_OPERACION,NULL);
    //borramos nodos del arbol de expresion que ya no se van a usar
    free(n1->dato); free(n2->dato); free(n1); free(n2);
    return NULL;
  }
}

nodo* evaluarEQ(nodo* n1, nodo* n2){
  char* ret = NULL;
  if(n1->tipo == n2->tipo){
    ret = (char*) malloc(sizeof(char));
    switch(n1->tipo){
    case T_STRING:
      if(strcasecmp((char*)(n1->dato),(char*)(n2->dato)) == 0)
	*ret = T_TRUE;
      else
	*ret = T_FALSE;
      break;
    case T_BOOLEAN:      
    case T_INTEGER:
      if(*((int*)(n1->dato)) == *((int*)(n2->dato)))
	*ret = T_TRUE;
      else
	*ret = T_FALSE;
      break;
    }
    //borramos nodos del arbol de expresion que ya no se van a usar
    free(n1->dato); free(n2->dato); free(n1); free(n2);
    return refNodoHijo(T_BOOLEAN,ret);
  }
  //borramos nodos del arbol de expresion que ya no se van a usar
  free(n1->dato); free(n2->dato); free(n1); free(n2);
  return NULL;    
}

nodo* evaluarNEQ(nodo* n1, nodo* n2){
  char* ret = NULL;
  if(n1->tipo == n2->tipo){
    ret = (char*) malloc(sizeof(char));
    switch(n1->tipo){
    case T_STRING:
      if(strcasecmp((char*)(n1->dato),(char*)(n2->dato)) == 0)
	*ret = T_FALSE;
      else
	*ret = T_TRUE;
      break;
    case T_BOOLEAN:      
    case T_INTEGER:
      if(*((int*)(n1->dato)) == *((int*)(n2->dato)))
	*ret = T_FALSE;
      else
	*ret = T_TRUE;
      break;
    }
    //borramos nodos del arbol de expresion que ya no se van a usar
    free(n1->dato); free(n2->dato); free(n1); free(n2);
    return refNodoHijo(T_BOOLEAN,ret);
  }
  //borramos nodos del arbol de expresion que ya no se van a usar
  free(n1->dato); free(n2->dato); free(n1); free(n2);
  return NULL;    
}

nodo* evaluarGT(nodo* n1, nodo* n2){
  char* ret = NULL;
  if(((n1->tipo) == T_INTEGER) && ((n2->tipo) == T_INTEGER)){
    ret = (char*) malloc(sizeof(char));
    if(*((int*)(n1->dato)) > *((int*)(n2->dato)))
      *ret = T_TRUE;
    else
      *ret = T_FALSE;    
    //borramos nodos del arbol de expresion que ya no se van a usar
    free(n1->dato); free(n2->dato); free(n1); free(n2);
    return refNodoHijo(T_BOOLEAN,ret);
  }
  else{
    error("Valores de comparacion aritmetica deben de ser estrictamente numericos",T_OPERACION,NULL);
    //borramos nodos del arbol de expresion que ya no se van a usar
    free(n1->dato); free(n2->dato); free(n1); free(n2);
    return NULL;
  }
}

nodo* evaluarGET(nodo* n1, nodo* n2){
  char* ret = NULL;
  if(((n1->tipo) == T_INTEGER) && ((n2->tipo) == T_INTEGER)){
    ret = (char*) malloc(sizeof(char));
    if((*((int*)(n1->dato))) >= (*((int*)(n2->dato))))
      *ret = T_TRUE;
    else
      *ret = T_FALSE;    
    //borramos nodos del arbol de expresion que ya no se van a usar
    free(n1->dato); free(n2->dato); free(n1); free(n2);
    return refNodoHijo(T_BOOLEAN,ret);
  }
  else{
    error("Valores de comparacion aritmetica deben de ser estrictamente numericos",T_OPERACION,NULL);
    //borramos nodos del arbol de expresion que ya no se van a usar
    free(n1->dato); free(n2->dato); free(n1); free(n2);
    return NULL;
  }
}

nodo* evaluarLT(nodo* n1, nodo* n2){
  char* ret = NULL;
  if(((n1->tipo) == T_INTEGER) && ((n2->tipo) == T_INTEGER)){
    ret = (char*) malloc(sizeof(char));
    if(*((int*)(n1->dato)) < *((int*)(n2->dato)))
      *ret = T_TRUE;
    else
      *ret = T_FALSE;    
    //borramos nodos del arbol de expresion que ya no se van a usar
    free(n1->dato); free(n2->dato); free(n1); free(n2);
    return refNodoHijo(T_BOOLEAN,ret);
  }
  else{
    error("Valores de comparacion aritmetica deben de ser estrictamente numericos",T_OPERACION,NULL);
    //borramos nodos del arbol de expresion que ya no se van a usar
    free(n1->dato); free(n2->dato); free(n1); free(n2);
    return NULL;
  }
}

nodo* evaluarLET(nodo* n1, nodo* n2){
  char* ret = NULL;
  if(((n1->tipo) == T_INTEGER) && ((n2->tipo) == T_INTEGER)){
    ret = (char*) malloc(sizeof(char));
    if((*((int*)(n1->dato))) <= (*((int*)(n2->dato))))
      *ret = T_TRUE;
    else
      *ret = T_FALSE;    
    //borramos nodos del arbol de expresion que ya no se van a usar
    free(n1->dato); free(n2->dato); free(n1); free(n2);
    return refNodoHijo(T_BOOLEAN,ret);
  }
  else{
    error("Valores de comparacion aritmetica deben de ser estrictamente numericos",T_OPERACION,NULL);
    //borramos nodos del arbol de expresion que ya no se van a usar
    free(n1->dato); free(n2->dato); free(n1); free(n2);
    return NULL;
  }
}

nodo* evaluarDiv(nodo* n1,nodo* n2){
  int* ret = NULL;
  if(((n1->tipo)==T_INTEGER) && ((n2->tipo)==T_INTEGER)){
    ret = (int*) malloc(sizeof(int));
    if(*((int*)(n2->dato))!=0){
      *ret = (*(int*)(n1->dato))/(*(int*)(n2->dato));
      //borramos nodos del arbol de expresion que ya no se van a usar
      free(n1->dato); free(n2->dato); free(n1); free(n2);
      return refNodoHijo(T_INTEGER,ret);
    }
    else{
      //borramos nodos del arbol de expresion que ya no se van a usar
      free(ret);free(n1->dato); free(n2->dato); free(n1); free(n2);
      error("Division entre 0",T_OPERACION,NULL);
      return NULL;
    }    
  }
  free(n1->dato); free(n2->dato); free(n1); free(n2);
  error("Valores para operacion aritmetica deben de ser estrictamente numericos",T_OPERACION,NULL);
  return NULL;
}

nodo* evaluarMult(nodo* n1,nodo* n2){
  int* ret = NULL;
  if(((n1->tipo)==T_INTEGER) && ((n2->tipo)==T_INTEGER)){
    ret = (int*) malloc(sizeof(int));
    *ret = (*(int*)(n1->dato))*(*(int*)(n2->dato));
    //borramos nodos del arbol de expresion que ya no se van a usar
    free(n1->dato); free(n2->dato); free(n1); free(n2);
    return refNodoHijo(T_INTEGER,ret);
  }
  free(n1->dato); free(n2->dato); free(n1); free(n2);
  error("Valores para operacion aritmetica deben de ser estrictamente numericos",T_OPERACION,NULL);
  return NULL;
}

nodo* evaluarResta(nodo* n1,nodo* n2){
  int* ret = NULL;
  if(((n1->tipo)==T_INTEGER) && ((n2->tipo)==T_INTEGER)){
    ret = (int*) malloc(sizeof(int));
    *ret = (*(int*)(n1->dato)) - (*(int*)(n2->dato));
    //borramos nodos del arbol de expresion que ya no se van a usar
    free(n1->dato); free(n2->dato); free(n1); free(n2);
    return refNodoHijo(T_INTEGER,ret);
  }
  free(n1->dato); free(n2->dato); free(n1); free(n2);
  error("Valores para operacion aritmetica deben de ser estrictamente numericos",T_OPERACION,NULL);
  return NULL;
}

nodo* evaluarSuma(nodo* n1,nodo* n2){
  int* ret = NULL;
  char* retStr = NULL;
  if(((n1->tipo)==T_INTEGER) && ((n2->tipo)==T_INTEGER)){
    ret = (int*) malloc(sizeof(int));
    *ret = (*(int*)(n1->dato)) + (*(int*)(n2->dato));
    //borramos nodos del arbol de expresion que ya no se van a usar
    free(n1->dato); free(n2->dato); free(n1); free(n2);
    return refNodoHijo(T_INTEGER,ret);
  }
  else if(((n1->tipo)==T_STRING) && ((n2->tipo)==T_STRING)){ /*concatenacion de cadenas*/
    retStr = (char*) malloc(sizeof(char) 
			       * (strlen((char*)n1->dato) + 
				  strlen((char*)n2->dato) + 1));
    strcat(retStr,(char*)n1->dato);
    strcat(retStr,(char*)n2->dato);
    free(n1->dato); free(n2->dato); free(n1); free(n2);
    return refNodoHijo(T_STRING,retStr);    
  }
  free(n1->dato); free(n2->dato); free(n1); free(n2);
  error("Valores para operacion aritmetica deben de ser estrictamente numericos",T_OPERACION,NULL);
  return NULL;
}

int evaluarIf(enunciadoIf* eif){
  int ret = -1;
  nodo* test = evaluarExpresion(eif->test);
  if(test!=NULL){
    if(test->tipo == T_BOOLEAN){
      if(*((char*)(test->dato))== T_TRUE){ /*Evalua el then*/
	ret = recorrerSentencia(eif->then_stmt);	
      }
      else if(*((char*)(test->dato))== T_FALSE){ /*Evalua el else*/
	ret = recorrerSentencia(eif->else_stmt);	
      }
      else{ 
	ret = -1;
	error("Valor booleano devuelto por TEST debe ser true o false",T_IF,eif);	
      }
    }
    else{
      ret = -1;
      error("Valor de prueba debe ser expresion booleana",T_IF,eif);	
    }
  }
  else{
    ret = -1;
    error("Imposible evaluar enunciado if, expresion es invalida",T_IF,eif);	
  }
  return ret;
}

int evaluarWhile(enunciadoWhile* ew){
  int testVal = T_TRUE;
  int err = 0;
  nodo* test = NULL;
  while(testVal == T_TRUE && !err){
    test = evaluarExpresion(ew->test);
    if(test->tipo == T_BOOLEAN){
      testVal = *((int*) (test->dato));
      if(testVal == T_TRUE)
	err += recorrerSentencia(ew->cuerpo);
      else if(testVal == T_FALSE);
      else{
	err = -1;
	error("Resultado de expresion invalida, debe ser true o false",T_WHILE,ew);
	return err;
      }
    }
    else{
      err = -1;
      error("Expresion debe ser condicional",T_WHILE,ew);
      return err;
    }   
  }
  return err;
}

int evaluarFor(enunciadoFor* ef){
  symbol* s ;
  int err = 0;
  if((ef->asignacion) <= (ef->limite)){
    s = buscarSimbolo(ef->indice);    
    if ((s!=NULL) && ((s->tipo) == T_INTEGER))  {
      s->valor.valorEntero = ef->asignacion; /*Asignamos valor a simbolo*/
      while(((s->valor.valorEntero)<= (ef->limite))
	    && !err){
      err += recorrerSentencia(ef->cuerpo);
      (s->valor.valorEntero) += 1;
      }
    }
    else{
      error("tipo de datos para indice debe ser numerico, o variable no existe",T_FOR,ef);
      err = -1;
	
    }    
  }
  else{
    error("asignacion a indice debe ser menor o igual que el limite del ciclo for",T_FOR,ef);
    err = -1;      
  }
  return err;
}

int evaluarPrintCall(printCall* pc){
  if(pc->hijos!=NULL){
    return imprimirTokens(pc->hijos);
  }
  error("Llamada a print debe tener al menos un argumento",T_CALL,pc);
  return -1;
}


int imprimirTokens(token* t){
  symbol* tmp = NULL;  
  int ret = 0;  
  if(t->siguiente!=NULL) //recorre todos los tokens hasta llegar al primero
    ret = imprimirTokens(t->siguiente);
  /*************************/
  switch(t->tipo){
  case T_STRING:
  case T_CADENA:
    fprintf(yyout,"%s",(t->hijo.cadena));    
    ret = 0;    
    break;    
  case T_INTEGER:
  case T_NUMERO:    
    fprintf(yyout,"%d",(t->hijo.numero)); 
    ret=0;    
    break;
  case T_IDENTIFICADOR:    
    tmp = buscarSimbolo(t->hijo.identificador);
    if(tmp!=NULL){
      switch(tmp->tipo){
      case T_STRING:
	fprintf(yyout,"%s",(tmp->valor.valorCadena));    
	break;    
      case T_INTEGER:
      case T_BOOLEAN:
	fprintf(yyout,"%d",(tmp->valor.valorEntero)); 
	break;
      }
      ret = 0;      
    }
    else{
      error("Variable no ha sido declarada",T_TOKEN,t);      
      ret = -1;      
    }
    break;
  }
  return ret;      
}

void borrarArbol(ast* tree){
	/*borrar nodos antes de borrar la raiz para asegurar liberacion de memoria*/

	/*borra la raiz*/
	free(tree->root);
}
  
