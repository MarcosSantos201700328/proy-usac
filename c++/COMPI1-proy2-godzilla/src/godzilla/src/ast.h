/** @file ast.h 
 * Definiciones y estructura del arbol de sintaxis abstracta */
/* (c) 2006 Erik Giron 
   para el segundo proyecto de Compiladores 1, USAC */
/*TODO implementar funcion borrarArbol para que en realidad borre memoria*/

#ifndef AST_H
#define AST_H

/**Aliases de yacc en QT, cambiar a nombre de parser a utilizar*/
#define yyout embedout

#ifdef __cplusplus
extern "C"{
#endif
#include "constantes.h" // tabla de constantes
#include "symtab.h" // referencia al TDA de tabla de simbolos
#include "colaerr.h"  // manejador  de colas de errores


/*declaraciones primarias para recursividad*/

typedef struct sentencia sentencia;
typedef struct variable variable;
typedef struct constante constante;
typedef struct operacion operacion;
typedef struct enunciadoIf enunciadoIf;
typedef struct enunciadoWhile enunciadoWhile;
typedef struct enunciadoFor enunciadoFor;
typedef struct expr expr;
typedef struct asignacion asignacion;
typedef struct printCall printCall;
typedef struct token token;
typedef struct declaracion declaracion;
typedef struct enunciado enunciado;
typedef struct nodoHijo nodo;
typedef struct raiz raiz;
typedef struct ast ast;


//FILE* outerr; /*Archivo hacia donde se almacenaran los resultados*/ 

/*Prototipos de funciones:*/

/* FUNCIONES DE INSERCION
  Todas a exceptcion de crearRaiz devuelven referencia al nodo recien 
  creado para que sea usado en las producciones*/
 /** Agrega una constante al arbol de expresiones*/
nodo* insertarConstante(int,int);
/** Agrega una variable al arbol de expresiones*/
nodo* insertarVariable(char*);
/** Agrega una cadena al arbol de expresiones*/ 
nodo* insertarCadena(char*); 
/** Inserta una operacion al arbol de expresiones */
nodo* insertarOperacion(int, nodo*, nodo*); 
/** Agrega un nuevo arbol de expresiones al arbol principal*/
nodo* insertarExpresion(nodo*); 
 /** Agrega una asignacion al arbol principal*/
nodo* insertarAsignacion(char*,nodo*);
/** agrega una sentencia al arbol principal*/
nodo* insertarSentencia(int,nodo*,int); 
/**agrega una nuva declaracion al arbol principal*/
nodo* insertarDeclaracion(char*,int); 
/**Agrega un nuevo enunciado if al arbol de sentencias*/
nodo* insertarEnunciadoIf(nodo*,nodo*,nodo*); 
 /**Agrega un nuevo ciclo while ar arbol de sentecias*/
nodo* insertarCicloWhile(nodo*,nodo*);
 /**Agrega un nuevo ciclo for al arbol de sentencias*/
nodo* insertarCicloFor(char*,int,int,nodo*);
/**Agrega un nuevo token al arbol de sentencias*/
nodo* insertarToken(int,void*); 
/** Agrega un nueva llamada de impresion a yyout al arbol de sentencias*/
nodo* insertarLlamada(nodo*); 
/** Agrega un nueva llamada de impresion de tabla de simbolos al arbol de sentencias*/
nodo* insertarLlamadaSymTab(int);
 /** Concatena tokens para parametros de llamadas */
nodo* concatenarTokens(nodo*,nodo*);
/** Concatena sentencias para caminar por estas*/
nodo* concatenarSentencia(nodo *,nodo *);
 /** Genera el nodo raiz para el arbol dado en el segundo parametro como punto de inicio del arbol y punto de meta del recorrido sintactico*/
void crearRaiz(nodo*,ast*);
 /**Crea un nodo que refiere al nodo recien creado para sea utilizado por el nodo anterior a este*/
nodo* refNodoHijo(int tipo, void* dato);

/* FUNCIONES DE RECORRIDO/EJECUCION*/

/**Recorre el arbol y escribe resultado en archivo salida*/
int recorrerArbol(ast* tree,char* filename);
/**Recorre sentencias recursivamente y devuelve resultado acarreado*/
int recorrerSentencia(sentencia* s);
/**Evalua sentencia y selecciona tipo de sentencia a evaluar */
int evaluarSentencia(sentencia* s); 
/**Evalua declaracion*/
int evaluarDeclaracion(declaracion* d); 
/**Evalua asignacion*/
int evaluarAsignacion(asignacion* a); 
 /**Evalua expresion y selecciona tipo de expresion a evaluar*/
nodo* evaluarExpresion(expr* e);
/**Selecciona operacion binaria a evaluar*/
nodo* evaluarOperacion(operacion* o); 
/**Evalua operacion logica OR */
nodo* evaluarOr(nodo* n1,nodo* n2); 
/**Evalua operacion logica AND */
nodo* evaluarAnd(nodo* n1,nodo* n2);
/**Evalua operacion comparativa Mayor Que*/
nodo* evaluarGT(nodo* n1,nodo* n2); 
 /**Evalua operacion comparativa Mayor o igual Que*/
nodo* evaluarGET(nodo* n1,nodo* n2);
 /**Evalua operacion comparativa Menor Que*/
nodo* evaluarLT(nodo* n1,nodo* n2);
/**Evalua operacion comparativa Menor o Igual Que*/
nodo* evaluarLET(nodo* n1,nodo* n2);
/**Evalua operacion comparativa Igual*/ 
nodo* evaluarEQ(nodo* n1,nodo* n2); 
 /**Evalua operacion comparativa Desigual*/
nodo* evaluarNEQ(nodo* n1,nodo* n2);
 /**Evalua operacion aritmetica Suma, y la concatenacion de cadenas*/
nodo* evaluarSuma(nodo* n1,nodo* n2);
 /**Evalua operacion aritmetica Resta*/
nodo* evaluarResta(nodo* n1,nodo* n2);
/**Evalua operacion aritmetica Multiplicacion*/
nodo* evaluarMult(nodo* n1,nodo* n2); 
 /**Evalua operacion aritmetica Division*/
nodo* evaluarDiv(nodo* n1,nodo* n2);
 /**Evalua bifurcacion If*/
int evaluarIf(enunciadoIf* eif);
 /**Evalua bucle While */
int evaluarWhile(enunciadoWhile* ew);
/**Evalua bucle For*/
int evaluarFor(enunciadoFor* ef);
 /**Evalua llamada a imprimir en archivo*/ 
int evaluarPrintCall(printCall* pc);
 /**Evalua recursivamente lista de tokens a imprimir*/
int imprimirTokens(token * t);

/** Escribe error semantico hacia cola de errores semanticos*/
void error(char* err,int tipo, void* dato); 

/** Funciones de eliminacion logica*/
void borrarArbol(ast* tree);
/**Borra nodo sentencia*/  
void borrarSentencias(sentencia* s);
/**Borra nodo declaracion*/
void borrarDeclaracion(declaracion* d);
/**Borrar Asignacion*/
void borrarAsignacion(asignacion* a);
 /**Elimina de memoria arbol de expresiones*/
void borrarExpresion(expr* e);
/**borra nodo operacion de mem*/
void borrarOperacion(operacion* o);
/**borra nodo if*/
void borrarIf(enunciadoIf* eif);
/**borra nodo While */
void borrarWhile(enunciadoWhile* ew);
/**borra nodo for*/
void borrarFor(enunciadoFor* ef);
/**borra nodo de llamada a imprimir en archivo*/ 
void borrarPrintCall(printCall* pc);
/**borra recursivamente listado de tokens*/
void borrarTokens(token* t);
    


/*permitir que la funcion error reciba como parametro un puntero a null y un int para identificar el puntero*/

/*declaraciones formales*/

/**Clase de almacenamiento de variables en el AST*/
struct variable{
  int tipoPrimitivo;/**<Tipo de dato*/
  char* identificador;/**<identificador*/
};
/**Clase de almacenamiento de constantes en el AST*/
struct constante{
  int tipo;/**<Tipo de constante*/
  int dato;/**<Valor*/
};

/**Clase de almacenamiento de operaciones en el AST*/
struct operacion{
  int operador;/**<Operador*/
  expr* loper;/**<Expresion a la izquierda del operador*/
  expr* roper;/**<Expresion a la derecha del operador*/
};
/**Clase de almacenamiento de enunciados If en el AST*/
struct enunciadoIf{
  expr* test;/**<Expresion booleana a evaluar (if(expr))*/
  sentencia* then_stmt;/**<Sentencia o sentencias a evaluar en then*/
  sentencia* else_stmt;/**<Sentencia o sentencias a evaluar en else*/
};
/**Clase de almacenamiento de enunciados while en el AST*/
struct enunciadoWhile{
  expr* test;/**<Expresion booleana a evaluar (if(expr))*/
  sentencia* cuerpo;/**<Cuerpo de sentencias a evaluar*/
};
/**Clase de almacenamiento de enunciados for en el AST*/
struct enunciadoFor{
  char* indice;/**<Identificador indice que apunta a variable entera*/
  int asignacion;/**<Entero a asignar a variable*/
  int limite;/**<Entero limite del ciclo*/
  sentencia* cuerpo;  /**<Cuerpo de sentencias a evaluar*/
};

/**Clase de almacenamiento de raiz de un arbol de expresiones en el AST*/
struct expr{
  int tipo;/**<Tipo de expresion*/
  union{
    operacion* oper;
    constante* cnst;
    variable* var;
    char* literal;    
  }hijo;/**<Puntero a dato correspondiente*/
};

/**Clase de almacenamiento de una asignacion en el AST*/
struct asignacion{
  char* variable;/**<Identificador de variable a asignar*/
  expr* hijo;/**<Expresion a evaluar para asignar valor*/
};
/**Clase de almacenamiento de una llamada a Print o a vartablasimbolos en el AST*/
struct printCall{
  int tipo;
  token* hijos;/**<Lista de tokens a imprimir*/
};

/**Clase de almacenamiento de raiz de un arbol de sentencias en el AST, siendo a su vez una lista*/
struct sentencia{
  sentencia* siguiente; /**<Sentencia siguiente a evaluar*/
  int tipo;/**<Tipo de sentencia*/
  int numLinea;/**<Numero de linea en donde se encontraba la sentecia, esto es para escribir a archivo de error*/
  union{
    /*    enunciado* enunciado;*/
    enunciadoIf* if_nodo;
    enunciadoWhile* while_nodo;
    enunciadoFor* for_nodo;
    declaracion* decl;
    printCall* call;
    asignacion* asig;    
  }hijo;/**<Nodos hijos del arbol de sentencias*/
  
};
/**Clase de almacenamiento de raiz de una lista enlazada de Tokens a imprimir con el comando Print  en el AST*/
struct token{
  int tipo;/**<Tipo de token a evaluar*/
  token* siguiente;/**<puntero a token siguiente en la lista*/
  union{
    char * cadena;
    char * identificador;
    int numero;
  }hijo; /**<puntero a token*/
};
/**Clase de almacenamiento de raiz de una declaracion en el AST*/
struct declaracion{
  char* identificador; /**<Identificador de variable a declarar*/
  int tipo;  /**<Tipo de dato de la variable*/
};

/**Nodo a usar para pasar entre producciones de la sintaxis, y paso de expresiones al recorrer un arbol de expresiones*/
struct nodoHijo{
  int tipo;/**<Tipo de nodo*/
  void * dato;/**<Dato del nodo*/
};
/**punto de entrada del AST*/
struct raiz{
  sentencia* hijo;/**<Primer sentencia del arbol de sintaxis abstracto*/
};
/**Estructura del arbol abstracto de sintaxis (AST), basico para poder evaluar construcciones iterativas del lenguaje*/
struct ast{
  raiz* root; /**<apuntador a raiz*/
  void* actual;/**<puntero auzliiar*/
  int tipoActual;/**<tipo del nodo actual*/
};
#ifdef __cplusplus
}
#endif

#endif
