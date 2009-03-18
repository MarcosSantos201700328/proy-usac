%{
/** @file ericle.y 
* gramatica libre de contexto para leer el codigo DML */
#define YYDEBUG 1
/*bison -t -v -d -p ericle ericle.y*/
  // usar YYLTYPE para localizacion de lineas
#ifdef __cplusplus
  extern "C"{
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "searchtree.h"
#include "search_node.h"
#include "linkedlist.h"
#include "tipos.h"
#include "dataoperations.h"
#include "r_autor.h"
#include "r_contenido.h"
#include "r_libro.h"
#include "r_prestamo.h"
#include "r_tipousuario.h"
#include "r_usuario.h"
#include "r_titulo.h"

    extern FILE* ericlein;
    extern FILE* ericleout;
    extern int line_num,column,huboErrorSintactico,huboErrorLexico,huboErrorSemantico;    
    int yylex(void);
    /*int yywrap(){
      //borrarTabla(); //elimina registros de la tabla de simbolos
	return 1;
    } 
*/	
	
    int yyparse(void);
    int inputparse(char* filename);
    void yyerror(const char *str) {
      // Redefinir para mi propio manejador de errores
	//errorSintactico((char*)str);
	printf(str);
      //      fprintf(stdout,"Error: %s, linea %d, columna %d\n",str,line_num,column);
    }
#ifdef __cplusplus
  };
#endif

    
%}
%union {
    int intValue;
    char stringValue[255];
    struct linkedlist* list;
    struct node* n;
    struct search_node* treeNode;
    struct r_autor* autorval;
    struct r_libro* libroval;
    struct r_contenido* contenidoval;
    struct r_prestamo* prestamoval;
    struct r_tipousuario* tusuarioval;
    struct r_titulo* tituloval;
    struct r_usuario* usuarioval;    
};


//%type <stringValue> 
%type <n> field val
%type <list> fieldlist 
	//vals
%type <treeNode> eq_op comp cond_or cond_and condition conditions
%type <intValue> table
	
%type <autorval> tbautor_vals;
%type <libroval> tblibro_vals;
%type <contenidoval> tbcontenido_vals;
%type  <prestamoval> tbprestamo_vals;
%type  <tusuarioval> tbtusuario_vals;
%type  <tituloval> tbtitulo_vals;
%type <usuarioval> tbusuario_vals;

%token <stringValue> TK_INTEGER TK_STRING TK_IDENTIFICADOR TK_CADENA
%token <intValue> TK_NUMERO
	
%token INSERT INTO TK_APAREN TK_CPAREN VALUES TK_PUNTOCOMA SELECT FROM WHERE
%token KW_OP_OR KW_OP_AND
%token <intValue> KW_AUTOR KW_CONTENIDO KW_LIBRO KW_PRESTAMO KW_TIPOUSUARIO  KW_TITULO KW_USUARIO
%token TK_OP_EQ TK_OP_LT TK_OP_LET TK_OP_GT TK_OP_GET TK_OP_NOEQ TK_OP_MULT TK_COMA 
%% //gramatica
/*
s :     s stmts
	| stmts;
*/	
stmts:    ins_stmts
	| sel_stmt
	;

ins_stmts: ins_stmts ins_stmt
	| ins_stmt
	;
	
/*ins_stmt: INSERT INTO table TK_APAREN fieldlist TK_CPAREN VALUES TK_APAREN vals TK_CPAREN TK_PUNTOCOMA 
{insertarTupla($9,$3);}
	| INSERT INTO table VALUES TK_APAREN vals TK_CPAREN TK_PUNTOCOMA
		{insertarTupla($6,$3);}
*/
ins_stmt: ins_with_fields
	| ins_without_fields
	;

ins_with_fields: INSERT INTO KW_AUTOR TK_APAREN fieldlist  TK_CPAREN   VALUES TK_APAREN tbautor_vals TK_CPAREN TK_PUNTOCOMA { insertarAutor($9);free($9);}
	|INSERT INTO KW_LIBRO TK_APAREN fieldlist  TK_CPAREN VALUES TK_APAREN tblibro_vals TK_CPAREN TK_PUNTOCOMA { insertarLibro($9);free($9);}
	|INSERT INTO KW_CONTENIDO TK_APAREN fieldlist  TK_CPAREN VALUES TK_APAREN tbcontenido_vals TK_CPAREN TK_PUNTOCOMA { insertarContenido($9);free($9);}
	|INSERT INTO KW_PRESTAMO TK_APAREN fieldlist  TK_CPAREN VALUES TK_APAREN tbprestamo_vals TK_CPAREN TK_PUNTOCOMA { insertarPrestamo($9);free($9);}
	|INSERT INTO KW_TIPOUSUARIO TK_APAREN fieldlist  TK_CPAREN VALUES TK_APAREN tbtusuario_vals TK_CPAREN TK_PUNTOCOMA {insertarTipoUsuario($9);free($9);}
	|INSERT INTO KW_TITULO TK_APAREN fieldlist  TK_CPAREN VALUES TK_APAREN tbtitulo_vals TK_CPAREN TK_PUNTOCOMA { insertarTitulo($9);free($9);}
	|INSERT INTO KW_USUARIO TK_APAREN fieldlist TK_CPAREN VALUES TK_APAREN tbusuario_vals TK_CPAREN TK_PUNTOCOMA { insertarUsuario($9);free($9);}
//{insertarTupla($9,$3);}
    ;
ins_without_fields:  INSERT INTO KW_AUTOR VALUES TK_APAREN tbautor_vals TK_CPAREN TK_PUNTOCOMA { insertarAutor($6);free($6);}
	|INSERT INTO KW_LIBRO VALUES TK_APAREN tblibro_vals TK_CPAREN TK_PUNTOCOMA { insertarLibro($6);free($6);}
	|INSERT INTO KW_CONTENIDO VALUES TK_APAREN tbcontenido_vals TK_CPAREN TK_PUNTOCOMA { insertarContenido($6);free($6);}
	|INSERT INTO KW_PRESTAMO VALUES TK_APAREN tbprestamo_vals TK_CPAREN TK_PUNTOCOMA { insertarPrestamo($6);free($6);}
	|INSERT INTO KW_TIPOUSUARIO VALUES TK_APAREN tbtusuario_vals TK_CPAREN TK_PUNTOCOMA { insertarTipoUsuario($6);free($6);}
	|INSERT INTO KW_TITULO VALUES TK_APAREN tbtitulo_vals TK_CPAREN TK_PUNTOCOMA { insertarTitulo($6);free($6);}
	|INSERT INTO KW_USUARIO VALUES TK_APAREN tbusuario_vals TK_CPAREN TK_PUNTOCOMA { insertarUsuario($6);free($6);}
		//{insertarTupla($6,$3);}
;
/*
tbautor_fields : KW_AUTOR TK_COMA TK_IDENTIFICADOR TK_COMA TK_IDENTIFICADOR TK_COMA TK_IDENTIFICADOR TK_COMA TK_IDENTIFICADOR
		|TK_IDENTIFICADOR TK_COMA TK_IDENTIFICADOR TK_COMA TK_IDENTIFICADOR TK_COMA TK_IDENTIFICADOR TK_COMA TK_IDENTIFICADOR
		
	;

tbtitulo_fields : KW_TITULO TK_COMA TK_IDENTIFICADOR TK_COMA TK_IDENTIFICADOR
		|TK_IDENTIFICADOR TK_COMA TK_IDENTIFICADOR TK_COMA TK_IDENTIFICADOR  
	;
tbusuario_fields : KW_USUARIO TK_COMA TK_IDENTIFICADOR TK_COMA KW_TIPOUSUARIO TK_COMA TK_IDENTIFICADOR TK_COMA TK_IDENTIFICADOR 
		| TK_IDENTIFICADOR TK_COMA TK_IDENTIFICADOR TK_COMA TK_IDENTIFICADOR TK_COMA TK_IDENTIFICADOR TK_COMA TK_IDENTIFICADOR 
	;
tblibro_fields : KW_LIBRO TK_COMA KW_AUTOR TK_COMA KW_TITULO TK_COMA TK_IDENTIFICADOR TK_COMA TK_IDENTIFICADOR
		| KW_LIBRO TK_COMA KW_AUTOR TK_COMA KW_TITULO TK_COMA TK_IDENTIFICADOR TK_COMA TK_IDENTIFICADOR
	;
tbtusuario_fields : KW_USUARIO TK_COMA TK_IDENTIFICADOR 
		
	;
tbprestamo_fields : KW_LIBRO TK_COMA KW_USUARIO TK_COMA TK_IDENTIFICADOR TK_COMA TK_IDENTIFICADOR 
		
	;
tbcontenido_fields : TK_IDENTIFICADOR TK_COMA TK_IDENTIFICADOR TK_COMA KW_LIBRO
		
	;*/
tbautor_vals: TK_NUMERO TK_COMA TK_STRING TK_COMA TK_STRING TK_COMA TK_STRING TK_COMA TK_STRING
		 {
      r_autor *tmp = (r_autor*) malloc(sizeof(r_autor));
      tmp->id = $1;
      strncpy(tmp->nombre,$3,39);
      strncpy(tmp->fecha_nac,$5,19);
      strncpy(tmp->origen,$7,39);
      strncpy(tmp->direccion,$9,39);
         $$ = tmp;
}
	;
tbtitulo_vals: TK_NUMERO TK_COMA TK_STRING TK_COMA TK_STRING TK_COMA TK_STRING  
		{      
      r_titulo *tmp = (r_titulo*) malloc(sizeof(r_titulo));
      tmp->id = $1;
      strncpy(tmp->nombre,$3,39);
      strncpy(tmp->fecha,$5,19);      
      strncpy(tmp->path_imagen,$7,19);
         $$ = tmp;}
	;
tblibro_vals: TK_NUMERO TK_COMA TK_NUMERO TK_COMA TK_NUMERO TK_COMA TK_NUMERO TK_COMA TK_NUMERO
		{
      r_libro *tmp = (r_libro*) malloc(sizeof(r_libro));
      tmp->id = $1;   
    tmp->autor = $3;
    tmp->titulo = $5;
    tmp->edicion = $7;
    tmp->cantidad = $9;
         $$ = tmp;
}
	;
tbusuario_vals: TK_NUMERO TK_COMA TK_STRING TK_COMA TK_NUMERO TK_COMA TK_STRING TK_COMA TK_STRING
		{ r_usuario *tmp = (r_usuario*) malloc(sizeof(r_usuario));
		   
      tmp->id = $1;
      strncpy(tmp->nombre,$3,39);
      tmp->tipo_usuario =  ($5);
      strncpy(tmp->password,$7,15);
      strncpy(tmp->email,$9,39);
         $$ = tmp;}
	;
tbtusuario_vals: TK_NUMERO TK_COMA TK_STRING
		{    
    r_tipousuario *tmp = (r_tipousuario*) malloc(sizeof(r_tipousuario));
		   
      tmp->id =  ($1);
      strncpy(tmp->descripcion,$3,39);
         $$ = tmp;
}
	;
tbprestamo_vals: TK_NUMERO TK_COMA TK_NUMERO TK_COMA TK_STRING TK_COMA TK_STRING
		{
    r_prestamo *tmp = (r_prestamo*) malloc(sizeof(r_prestamo));
		   
      tmp->libro =  ($1);
      tmp->usuario =  ($3);
      strncpy(tmp->fecha_prestamo,$5,39);      
      strncpy(tmp->fecha_entrega,$7,15);      
         $$ = tmp;}
	;
tbcontenido_vals: TK_NUMERO TK_COMA TK_STRING TK_COMA TK_NUMERO {
	    r_contenido *tmp = (r_contenido*) malloc(sizeof(r_contenido));
	
      tmp->linea =  ($1);   
    strncpy(tmp->texto,$3,99);      
    tmp->libro =  ($5);    
         $$ = tmp;}
	;

sel_stmt: SELECT fieldlist FROM table TK_PUNTOCOMA
	| SELECT fieldlist FROM table WHERE conditions TK_PUNTOCOMA
	;


fieldlist: fieldlist TK_COMA field //{ $$ = enlazar($1,$3); }
	| field //{ $$ = nuevaLista($1);}
	| TK_OP_MULT //{$$ = NULL;}
	;

field: TK_IDENTIFICADOR
		|KW_AUTOR 
		|KW_CONTENIDO
		|KW_LIBRO
		|KW_PRESTAMO
		|KW_TIPOUSUARIO 
		|KW_TITULO
		|KW_USUARIO
	/* {
            char* tmpid = (char*) malloc(sizeof(char)*64);
            strcpy(tmpid,$1);
            $$ = crearNodo((void*)tmpid);
            }*/
	; 
        /*
vals : vals TK_COMA val { $$ = enlazar($1,$3);}
	| val { $$ = nuevaLista($1);}
	;*/
val :   TK_STRING
	          /*        {
            nodo* tmp;
            char* tmpid = (char*) malloc(sizeof(char)*64);
            strcpy(tmpid,$1);
            tmp = crearNodo((void*)tmpid);
	    tmp->tipo = (char)TK_STRING;
            $$ = tmp;
            }*/
        | TK_INTEGER
		/*                {
            nodo* tmp;
            int* tmpid = (int*) malloc(sizeof(int));
            *tmpid = atoi($1);
            tmp = crearNodo((void*)tmpid);
	    tmp->tipo = (char)TK_INTEGER;
            $$ = tmp;
            }*/
	;

table : KW_AUTOR {$$ = T_AUTOR;}
        | KW_CONTENIDO {$$ = T_CONTENIDO;}
        | KW_LIBRO {$$ = T_LIBRO;}
        | KW_PRESTAMO {$$ = T_PRESTAMO;}
        | KW_TIPOUSUARIO {$$ = T_TIPOUSUARIO ;}
        | KW_TITULO {$$ = T_TITULO;}
        | KW_USUARIO {$$ = T_USUARIO ;}
	;
conditions : conditions condition
	| condition
	;
condition : cond_and ;

cond_and : cond_and KW_OP_AND cond_or
	| cond_or
	;
cond_or : cond_or KW_OP_OR comp
	| comp;

comp : field eq_op val;

eq_op : TK_OP_EQ
	|TK_OP_LT
	|TK_OP_LET
	|TK_OP_GT
	|TK_OP_GET
	|TK_OP_NOEQ
	;

%%

int inputparse(const char* filename){
    int ret = -1;
    ericlein = fopen(filename,"rb");
    if(ericlein !=  NULL){
	ret =  yyparse();
	fclose(ericlein);
	return ret;
    }
    return ret;
}