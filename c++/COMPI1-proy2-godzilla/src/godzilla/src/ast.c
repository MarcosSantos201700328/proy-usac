/** @file ast.c
 * Implementacion del arbol de sintaxis abstracta. Incluye funciones de creacion, recorrido/ejecucion y destruccion del arbol */
/* (c) 2006 Erik Giron 
   para el segundo proyecto de Compiladores 1, USAC */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

extern FILE* yyout;


/**FUNCIONES DE INSERCION**/

/**Crea un nodo que refiere al nodo recien creado para sea utilizado por el nodo anterior a este*/
nodo* refNodoHijo(int tipo, void* dato){
  nodo* nuevo = (nodo*) malloc(sizeof(nodo));
  nuevo->dato = dato;
  nuevo->tipo = tipo;
  return nuevo;
}
/** Agrega una constante al arbol de expresiones*/
nodo* insertarConstante(int tipo, int dato){
  constante* nuevo = (constante*) malloc(sizeof(constante));
  nuevo->tipo = tipo;
  nuevo->dato = dato;
  return (refNodoHijo(T_CONSTANTE,nuevo));  
}
/** Agrega una variable al arbol de expresiones*/
nodo* insertarVariable(char* ident){
  variable* nuevo = (variable*) malloc(sizeof(variable));
  nuevo->identificador = (char*) malloc(sizeof(char)*(strlen(ident)+1));
  strcpy(nuevo->identificador,ident);
  free(ident);
  return (refNodoHijo(T_VARIABLE,nuevo));
}
/** Agrega una cadena al arbol de expresiones*/ 
nodo* insertarCadena(char* cadena){
  expr* nuevo = (expr*) malloc(sizeof(expr));
  nuevo->tipo = T_LITERAL;
  nuevo->hijo.literal = (char*) malloc(sizeof(char)*(strlen(cadena)+1));
  strcpy((nuevo->hijo).literal,cadena);
  free(cadena);
  return (refNodoHijo(T_EXPR,nuevo));
}

/** Inserta una operacion al arbol de expresiones */
nodo* insertarOperacion(int operador, nodo* l, nodo* r){
  operacion* nuevo = (operacion*) malloc(sizeof(operacion));
  nuevo->operador = operador;
  nodo* lexpr = insertarExpresion(l);
  nodo* rexpr = insertarExpresion(r);
  if(lexpr != NULL && rexpr !=NULL){
    nuevo->loper = (expr*) lexpr->dato;
    nuevo->roper = (expr*) rexpr->dato;
  }
  return (refNodoHijo(T_OPERACION,nuevo));
}
/** Agrega un nuevo arbol de expresiones al arbol principal*/
nodo* insertarExpresion(nodo* n){
  expr* nuevo = NULL;
  if(n!=NULL){
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
  }
  return (refNodoHijo(T_EXPR,nuevo));
}

 /** Agrega una asignacion al arbol principal*/
nodo* insertarAsignacion(char* identificador, nodo* expresion){
  asignacion* nuevo = (asignacion*) malloc(sizeof(asignacion));
  nuevo->variable = (char*) malloc(sizeof(char)*(strlen(identificador)+1));
  strcpy(nuevo->variable,identificador);
  if(expresion!=NULL)
    nuevo->hijo = (expr*) expresion->dato;
  else
    nuevo->hijo = NULL;
  return (refNodoHijo(T_ASIGNACION,nuevo));
}

/** agrega una sentencia al arbol principal*/
nodo* insertarSentencia(int tipo,nodo* n,int nlinea){
  sentencia* nuevo = (sentencia*) malloc(sizeof(sentencia));
  /*nuevo->tipo = n->tipo;*/
  nuevo->tipo = tipo;
  nuevo->hijo.if_nodo = NULL;
  switch(nuevo->tipo){
  case T_IF:
    if(n!=NULL)
      nuevo->hijo.if_nodo = (enunciadoIf*) n->dato;
    break;
  case T_WHILE:
    if(n!=NULL)
      nuevo->hijo.while_nodo = (enunciadoWhile*) n->dato;
    break;
  case T_FOR:
    if(n!=NULL)
      nuevo->hijo.for_nodo = (enunciadoFor*) n->dato;
    break;
  case T_DECLARACION:
    if(n!=NULL)
      nuevo->hijo.decl = (declaracion*) n->dato;
    break;
  case T_CALL:
    if(n!=NULL)
      nuevo->hijo.call = (printCall*) n->dato;
    break;
  case T_ASIGNACION:
    if(n!=NULL)
      nuevo->hijo.asig = (asignacion*) n->dato;
    break;
  case T_ERROR:
    nuevo->hijo.asig = NULL;
    break;
  }
  nuevo->numLinea = nlinea;
  nuevo->siguiente = 0;
  return (refNodoHijo(T_SENTENCIA,nuevo));  
  
}
/** Concatena sentencias para caminar por estas*/
nodo* concatenarSentencia(nodo* n1, nodo* n2){
  sentencia* s1 = NULL;
  sentencia* s2 = NULL;
//  if(n1!=NULL)
    s1 = (sentencia*) n1->dato;
//  if(n2!=NULL)
    s2 = (sentencia*) n2->dato;
/*   /\*   asigna s2 como siguiente de s1 *\/ */
/*   s1->siguiente = s2; */
/*   /\*   retorna el nodo n1 *\/ */
/*   return n1; */
  /*   asigna s2 como siguiente de s1 */
//  if(s2!=NULL);
    s2->siguiente = s1;
  /*   retorna el nodo n1 */
  return n2;
}
/**agrega una nueva declaracion al arbol principal*/
nodo* insertarDeclaracion(char* identificador, int tipoDato){
  declaracion* nuevo = (declaracion*) malloc(sizeof(declaracion));
  nuevo->tipo = tipoDato;
  nuevo->identificador = (char*) malloc(sizeof(char)*(strlen(identificador)+1));
  strcpy(nuevo->identificador,identificador);
  return (refNodoHijo(T_DECLARACION,nuevo));  
}
/**Agrega un nuevo enunciado if al arbol de sentencias*/
nodo* insertarEnunciadoIf(nodo* expresion, nodo* nthen, nodo* nelse){
  enunciadoIf* nuevo = (enunciadoIf*) malloc(sizeof(enunciadoIf));
  if(expresion!=NULL)
    nuevo->test = (expr*) expresion->dato;
  else
    nuevo->test = NULL;
  if(nthen!=NULL)
    nuevo->then_stmt = (sentencia*) nthen->dato;
  else
    nuevo->then_stmt = NULL;
  if(nelse != NULL)
    nuevo->else_stmt = (sentencia*) nelse->dato;
  else
    nuevo->else_stmt = NULL;
  return (refNodoHijo(T_IF,nuevo));
}
/**Agrega un nuevo ciclo while ar arbol de sentecias*/
nodo* insertarCicloWhile(nodo* expresion, nodo* stmt){
  enunciadoWhile* nuevo = (enunciadoWhile*) malloc(sizeof(enunciadoWhile));
  nuevo->test= NULL;
  nuevo->cuerpo = NULL;
  if(expresion!=NULL)
    nuevo->test = (expr*) expresion->dato;
  if(stmt!=NULL)
    nuevo->cuerpo = (sentencia*) stmt->dato;  
  return (refNodoHijo(T_WHILE,nuevo));
}
/**Agrega un nuevo ciclo for al arbol de sentencias*/
nodo* insertarCicloFor(char* idx, int asig, int lim, nodo* body){
  enunciadoFor* nuevo = (enunciadoFor*) malloc(sizeof(enunciadoFor));
  nuevo->cuerpo = NULL;
  
  nuevo->indice = (char*) malloc(sizeof(char)*(strlen(idx+1)));
  strcpy(nuevo->indice, idx);
  nuevo->asignacion = asig;
  nuevo->limite = lim;
  if(body!=NULL)
    nuevo->cuerpo = (sentencia*) body->dato;
  return (refNodoHijo(T_FOR,nuevo));
}
/**Agrega un nuevo token al arbol de sentencias*/
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
/** Concatena tokens para parametros de llamadas */
nodo* concatenarTokens(nodo* t1, nodo* t2){
  token* tmp1 = NULL;
  token* tmp2 = NULL;
  if(t1 != NULL)
    tmp1 = (token*) t1->dato;
  if(t2 != NULL)
    tmp2 = (token*) t2->dato;
  if(tmp2!=NULL)
    tmp2->siguiente = tmp1;
  return t2;
}
/** Agrega un nueva llamada de print a yyout al arbol de sentencias*/
nodo* insertarLlamada(nodo* n){
  printCall* nuevo = (printCall*) malloc(sizeof(printCall));
  nuevo->tipo = T_PRINTCALL;
  if(n!=NULL)
    nuevo->hijos = (token*) n->dato;
  else 
    nuevo->hijos =NULL;
  return (refNodoHijo(T_CALL,nuevo));  
}

/** evalua instantenamente llamada de impresion de tabla de simbolos, agregando solamente un nodo dummie*/
nodo* insertarLlamadaSymTab(int ln){
  printCall* nuevo = (printCall*) malloc(sizeof(printCall));
  nuevo->tipo = T_PRINTSYMCALL;
  nuevo->hijos = NULL;
  printSymtabFile(ln);/*Llama a imprimir tabla de simbolos instanteneamente*/
  return (refNodoHijo(T_CALL,nuevo));
}

/** Genera el nodo raiz para el arbol dado en el segundo parametro como punto de inicio del arbol y punto de meta del recorrido sintactico*/
void crearRaiz(nodo* n, ast* tree){
  raiz* root = (raiz*) malloc(sizeof(raiz));
  root->hijo=NULL;
  
  if(n!=NULL)
    root->hijo= (sentencia*) n->dato;
  if( tree == NULL){
    tree = (ast*) malloc(sizeof(tree));
  }
  tree->root = root;
  tree->actual = (void*) root->hijo;
  tree->tipoActual = T_SENTENCIA;
}

/**FUNCIONES DE RECORRIDO/EJECUCION*/

/** Escribe error semantico hacia cola de errores semanticos*/
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

/**Recorre el arbol y escribe resultado en archivo salida,NOTA:LA ACTUAL IMPLEMENTACION NO HACE NADA CON EL PARAMETRO FILENAME*/
int recorrerArbol(ast* tree,char* filename){
  //outerr = fopen(filename,"w+b");  
  if(tree!=NULL){
    if(tree->root!=NULL)
      return recorrerSentencia(tree->root->hijo);    
  }
  return -1;
  //fclose(outerr);
}

/**Recorre sentencias recursivamente y devuelve resultado acarreado*/
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

/**Evalua sentencia y selecciona tipo de sentencia a evaluar */
int evaluarSentencia(sentencia* s){
  //  int ret = 0;
  if(s!=NULL){
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
    case(T_ERROR):
      return 0;
      break;
    default:
      return -1;
      break;
    }    
  }
  return 0;
}
/**Evalua declaracion*/
int evaluarDeclaracion(declaracion* d){
  symbol* s = buscarSimbolo(d->identificador);
  if(s==NULL){
    insertarSimbolo(d->identificador,d->tipo);
    return 0;
  }
  error("variable ya existe",T_DECLARACION,d); return -1;    
}
/**Evalua asignacion*/
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
 /**Evalua expresion y selecciona tipo de expresion a evaluar*/
nodo* evaluarExpresion(expr* e){
  nodo* nuevo = NULL;
  symbol* tmp = NULL;
  if(e!=NULL){
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
  }
  return nuevo;    
}
/**Selecciona operacion binaria a evaluar*/
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
/**Evalua operacion logica AND */
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
/**Evalua operacion logica OR */
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
/**Evalua operacion comparativa Igual*/ 
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
/**Evalua operacion comparativa Desigual*/
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
/**Evalua operacion comparativa Mayor Que*/
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
/**Evalua operacion comparativa Mayor o igual Que*/
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
/**Evalua operacion comparativa Menor Que*/
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
/**Evalua operacion comparativa Menor o Igual Que*/
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
/**Evalua operacion aritmetica Division*/
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
/**Evalua operacion aritmetica Multiplicacion*/
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
/**Evalua operacion aritmetica Resta*/
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
/**Evalua operacion aritmetica Suma, y la concatenacion de cadenas*/
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
    *retStr = 0;
    strcat(retStr,(char*)n1->dato);
    strcat(retStr,(char*)n2->dato);
    free(n1->dato); free(n2->dato); free(n1); free(n2);
    return refNodoHijo(T_STRING,retStr);    
  }
  free(n1->dato); free(n2->dato); free(n1); free(n2);
  error("Valores para operacion aritmetica deben de ser estrictamente numericos",T_OPERACION,NULL);
  return NULL;
}
/**Evalua bifurcacion If*/
int evaluarIf(enunciadoIf* eif){
  int ret = -1;
  nodo* test = NULL;
  if(eif!=NULL){
    test = evaluarExpresion(eif->test);
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
  return -1;
}
/**Evalua bucle While */
int evaluarWhile(enunciadoWhile* ew){
  int testVal = T_TRUE;
  int err = 0;
  nodo* test = NULL;
  if(ew!=NULL){
    while(testVal == T_TRUE && !err){
      test = evaluarExpresion(ew->test);
      if(test->tipo == T_BOOLEAN){
	testVal = *((char*) (test->dato));
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
  return -1;
}
/**Evalua bucle For*/
int evaluarFor(enunciadoFor* ef){
  symbol* s =NULL;
  int err = 0;
  if( ef!=NULL){
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
  return -1;
}
/**Evalua llamada a imprimir en archivo*/ 
int evaluarPrintCall(printCall* pc){
  if(pc!=NULL){
    if ((pc->tipo) == T_PRINTCALL){
      if(pc->hijos!=NULL){
	return imprimirTokens(pc->hijos);
      }
    }
    else
      return 0;
    error("Llamada a print invalida",T_CALL,pc);
    return -1;
    }
  return -1;
}

/**Evalua recursivamente lista de tokens a imprimir*/
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



/**ELIMINACION**/
/*********************************************************************************/
/** Funcion de eliminacion logica, llama a todas las demas para podar el arbol*/
void borrarArbol(ast* tree){
	/*borrar nodos antes de borrar la raiz para asegurar liberacion de memoria*/

	/*borra la raiz*/
  if((tree->root->hijo)!=NULL){   
#ifdef Q_OS_WIN                                    
	borrarSentencias(tree->root->hijo);
#endif
    tree->root->hijo = 0;
      
  }	
  //*free(tree->root);
  tree->root = NULL;
  tree->actual = NULL;
  tree->tipoActual=0;
}
/**Borra nodo sentencia*/  
void borrarSentencias(sentencia* s){
  if(s!=NULL){
    borrarSentencias(s->siguiente); /*recursion del ultimo hacia el primero*/
    switch(s->tipo){
    case(T_DECLARACION):
        borrarDeclaracion(s->hijo.decl);    
      break;
    case(T_ASIGNACION):
        borrarAsignacion(s->hijo.asig);
      break;
    case(T_IF):
	borrarIf(s->hijo.if_nodo);
      break;
    case(T_WHILE):  
	borrarWhile(s->hijo.while_nodo);
      break;
    case(T_FOR):
	borrarFor(s->hijo.for_nodo);
	break;
    case(T_CALL):
	borrarPrintCall(s->hijo.call);
	break;
    }  
    free(s);	
    s= NULL;
  }     
}

/**Borra nodo declaracion*/
void borrarDeclaracion(declaracion* d){
  if(d!=NULL){
    free(d->identificador);
    free(d);  
    d = NULL;
  }
}

/**Borrar Asignacion*/
void borrarAsignacion(asignacion* a){
  if(a!=NULL){
    borrarExpresion(a->hijo);
    free(a->variable);  
    free(a);
    a= NULL;
  }
}

 /**Elimina de memoria arbol de expresiones*/
void borrarExpresion(expr* e){
  if(e!=NULL){
    switch(e->tipo){
      case T_OPERACION:
	borrarOperacion(e->hijo.oper);
	break;
      case T_CONSTANTE:
	free(e->hijo.cnst);
	break;
      case T_VARIABLE:/*Sustituimos la variable y la convertimos a literal*/
	free(e->hijo.var->identificador);	
	free(e->hijo.var);
	break;
      case T_LITERAL:
	free(e->hijo.literal);      
	break;
    }  
    free(e);
    e= NULL;
  }
}

/**borra nodo operacion de mem*/
void borrarOperacion(operacion* o){  
  if(o!=NULL){
    borrarExpresion(o->loper);
    borrarExpresion(o->roper);
    free(o);
    o = NULL;
  }
}

/**borra nodo if*/
void borrarIf(enunciadoIf* eif){
  if(eif!=NULL){
    borrarExpresion(eif->test);
    if(eif->then_stmt!=NULL)
      borrarSentencias(eif->then_stmt);	
    if(eif->else_stmt!=NULL)
      borrarSentencias(eif->else_stmt);	
    free(eif);
    eif = NULL;
  }
}

/**borra nodo While */
void borrarWhile(enunciadoWhile* ew){
  if(ew!=NULL){
    borrarExpresion(ew->test);
    borrarSentencias(ew->cuerpo);
    free(ew);
    ew = NULL;
  }
}
/**borra nodo for*/
void borrarFor(enunciadoFor* ef){
  if(ef!=NULL){
    free(ef->indice);
    borrarSentencias(ef->cuerpo);
    free(ef);
    ef = NULL;
  }
}
/**borra nodo de llamada a imprimir en archivo*/ 
void borrarPrintCall(printCall* pc){
  if(pc!=NULL){
    if(pc->hijos !=NULL)
      borrarTokens(pc->hijos);
    free(pc);
    pc = NULL;
  }
}

/**borra recursivamente listado de tokens*/
void borrarTokens(token* t){  
    if(t->siguiente!=NULL) //recorre todos los tokens hasta llegar al primero
      borrarTokens(t->siguiente);    
    if(t->tipo == T_STRING || t->tipo == T_CADENA){    
	free(t->hijo.cadena);    
    }    
    else if (t->tipo == T_STRING){    
	free(t->hijo.identificador);
    }
    free(t);  
    t = NULL;
}
