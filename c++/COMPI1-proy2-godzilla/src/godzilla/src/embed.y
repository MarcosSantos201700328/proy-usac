%{
/** @file embed.y 
* gramatica libre de contexto para leer el codigo embedded */
#define YYDEBUG 1

  // usar YYLTYPE para localizacion de lineas
#ifdef __cplusplus
  extern "C"{
#endif
#include <stdio.h>
#include <string.h>
#include "ast.h" /* TDA para el arbol de sintaxis abstracta */
#include "symtab.h"
#include "colaerr.h"
#include "parserheader.h"
/*#include "colaerr.h"*/
/**Aliases de yacc en QT*/
#define yylex embedlex
#define yywrap embedwrap
#define yyin embedin
#define yyout embedout
//#define yylex lexerlex
//#define yywrap lexerwrap
    extern FILE* yyin;
    extern FILE* yyout;
    extern int line_num,column,huboErrorSintactico,huboErrorLexico,huboErrorSemantico;    
    int yylex(void);
    int yywrap(){
      //borrarTabla(); //elimina registros de la tabla de simbolos
      return 1;
    } 
	
	
	int yyparse(void);
    void yyerror(const char *str) {
      // Redefinir para mi propio manejador de errores
      errorSintactico((char*)str);
      printf(str);
      //      fprintf(stdout,"Error: %s, linea %d, columna %d\n",str,line_num,column);
    }
    

    
    /*Arbol de sintaxis*/
    ast astTree;

#ifdef __cplusplus
  };
#endif
/*main()
{
        yyparse();
} 
*/
%}



%union {
  int intValue;
  char* stringValue;
  nodo* astNodo;
}
/* Producciones */
%type <astNodo> codigo sentencias def_var sentencia asignacion condicionales ciclos 
%type <astNodo> expr ciclo_while ciclo_for llamadas lista_tokens token bloque
%type <astNodo> expr_and expr_igual expr_relacional expr_suma expr_mult term /*withelse lastelse*/
%error-verbose
/*Operadores*/
%right TK_COMA
%right TK_OP_ASIGNACION
%left KW_OP_OR
%left KW_OP_AND
%left TK_OP_GT TK_OP_GET TK_OP_LT TK_OP_LET TK_OP_EQ TK_OP_NOEQ
%left TK_OP_SUMA TK_OP_RESTA 
%left TK_OP_MULT TK_OP_DIV

/*Literales e identificadores con precedencia mayor*/
%token TK_CPAREN TK_APAREN 
%token<intValue> TK_NUMERO KW_TRUE KW_FALSE
%token<stringValue> TK_IDENTIFICADOR TK_CADENA
%token OPEN_EMBED CLOSE_EMBED KW_VAR 
%token TK_DOSPUNTOS KW_INTEGER KW_BOOLEAN KW_STRING 
%token TK_PUNTOCOMA TK_CADENA
%token KW_THEN KW_IF KW_ELSE KW_WHILE KW_FOR KW_TO KW_BEGIN KW_END KW_PRINT KW_PRINTSYMTAB TK_EOF
%%
/* Gramatica libre de contexto */
    
inicio: embed
    | inicio embed
    ;
embed:   OPEN_EMBED codigo CLOSE_EMBED 
	{
	crearRaiz($2,&astTree);
	// recorre arbol de sintaxis y genera salida   	
	huboErrorSemantico = recorrerArbol(&astTree,NULL); 
	borrarArbol(&astTree);
	}
	| error CLOSE_EMBED{huboErrorSintactico = -1;}
         | OPEN_EMBED CLOSE_EMBED
	    
         ;

codigo: sentencias {$$ = $1;}
;

sentencias:  sentencia {$$ = $1;}
            |  sentencias sentencia {$$ = concatenarSentencia($1,$2);}
	    
//	    | sentencias error{huboErrorSintactico = -1;/*yyerrok;yyclearin;*/YYABORT;}
	    ; 
            ;

sentencia :  def_var { $$ = insertarSentencia(T_DECLARACION,$1,line_num);}
	  | asignacion {$$ = insertarSentencia(T_ASIGNACION,$1,line_num);}
          | condicionales { $$ = insertarSentencia(T_IF,$1,line_num);}
          | ciclos {$$=$1;}
          | llamadas {$$ = insertarSentencia(T_CALL,$1,line_num);}
	  | error{huboErrorSintactico = -1;
	  $$ = insertarSentencia(T_ERROR,NULL,line_num);/*yyerrok;yyclearin;YYABORT;*/}

;

def_var:   KW_VAR TK_IDENTIFICADOR TK_DOSPUNTOS KW_INTEGER TK_PUNTOCOMA {$$=insertarDeclaracion($2,T_INTEGER);}
       | KW_VAR TK_IDENTIFICADOR TK_DOSPUNTOS KW_BOOLEAN TK_PUNTOCOMA {$$=insertarDeclaracion($2,T_BOOLEAN);}
       | KW_VAR TK_IDENTIFICADOR TK_DOSPUNTOS KW_STRING TK_PUNTOCOMA {$$=insertarDeclaracion($2,T_STRING);}
         ;

          ;
asignacion : TK_IDENTIFICADOR TK_OP_ASIGNACION expr TK_PUNTOCOMA {$$=insertarAsignacion($1,$3);}         
	 ; 


	 condicionales :// KW_IF /*TK_APAREN*/ expr /*TK_CPAREN*/ KW_THEN bloque {$$=insertarEnunciadoIf($2, $4, NULL);}
	     /*| */KW_IF /*TK_APAREN*/ expr /*TK_CPAREN*/ KW_THEN bloque KW_ELSE bloque  {$$=insertarEnunciadoIf($2, $4, $6);}
              ;
/*
condicionales : withelse {$$=$1;}
              | lastelse {$$=$1;}
		;
withelse : KW_IF TK_APAREN expr TK_CPAREN KW_THEN withelse KW_ELSE withelse TK_PUNTOCOMA {$$=insertarEnunciadoIf($3, $6, $8);}
         | bloque {$$=$1;}
	 ;

lastelse : KW_IF TK_APAREN expr TK_CPAREN KW_THEN bloque {$$=insertarEnunciadoIf($3, $6, NULL);}// TK_PUNTOCOMA 
         | KW_IF TK_APAREN expr TK_CPAREN KW_THEN withelse KW_ELSE lastelse {$$=insertarEnunciadoIf($3, $6, $8);} // TK_PUNTOCOMA/
	 ;
*/
ciclos : ciclo_while {$$=insertarSentencia(T_WHILE,$1,line_num);}
       | ciclo_for {$$=insertarSentencia(T_FOR,$1,line_num);}
       ;

ciclo_while : KW_WHILE expr bloque {$$=insertarCicloWhile($2, $3);}
	    ;

ciclo_for : KW_FOR TK_IDENTIFICADOR TK_OP_ASIGNACION TK_NUMERO KW_TO TK_NUMERO bloque
            {$$=insertarCicloFor($2,$4 ,$6 ,$7);}
	  ;

llamadas: KW_PRINT TK_APAREN lista_tokens TK_CPAREN TK_PUNTOCOMA 
            {$$=insertarLlamada($3);}
	  |  KW_PRINTSYMTAB TK_APAREN TK_CPAREN TK_PUNTOCOMA 
	     {$$=insertarLlamadaSymTab(line_num);}
	 ;

lista_tokens : lista_tokens TK_COMA token {$$ = concatenarTokens($1,$3);}
	     | token {$$=$1;}
	     ;

token : TK_IDENTIFICADOR {$$=insertarToken(T_IDENTIFICADOR,$1);} 
      | TK_CADENA {$$=insertarToken(T_STRING,$1);}
      | TK_NUMERO {$$=insertarToken(T_INTEGER,(void*)(&($1)));}
      ;

      bloque : KW_BEGIN sentencias bloque KW_END  TK_PUNTOCOMA{$$=concatenarSentencia($2,$3)/*$2*/;}
      |KW_BEGIN error KW_END TK_PUNTOCOMA{$$=NULL;huboErrorSintactico = -1;}
      | sentencia {$$=$1;}
       ;
expr : expr_and {$$ = insertarExpresion($1);}
       | expr KW_OP_OR expr_and {$$=insertarExpresion(insertarOperacion(OP_OR,$1,$3));}/*expr OR expr*/
		;

expr_and: expr_igual {$$ = $1;}
		| expr_and KW_OP_AND expr_igual {$$=insertarOperacion(OP_AND,$1,$3);}/*expr AND expr*/
		;
expr_igual: expr_relacional {$$ = $1;}
		| expr_igual TK_OP_EQ expr_relacional {$$= insertarOperacion(OP_EQ,$1,$3);}/*expr = expr*/
		| expr_igual TK_OP_NOEQ expr_relacional {$$= insertarOperacion(OP_NEQ,$1,$3);}/*expr <> expr*/
		;
expr_relacional:	expr_suma {$$ = $1;}
		| expr_relacional TK_OP_GT expr_suma {$$= insertarOperacion(OP_GT,$1,$3);} /*expr > expr*/
		| expr_relacional TK_OP_GET expr_suma {$$= insertarOperacion(OP_GET,$1,$3);}/*expr >= expr*/
		| expr_relacional TK_OP_LT expr_suma {$$= insertarOperacion(OP_LT,$1,$3);}/*expr < expr*/
		| expr_relacional TK_OP_LET expr_suma {$$= insertarOperacion(OP_LET,$1,$3);}/*expr <= expr*/
				;
expr_suma:	expr_mult {$$ = $1;}
                      | expr_suma TK_OP_SUMA expr_mult {$$= insertarOperacion(OP_SUMA,$1,$3);}/*expr + expr*/
			| expr_suma TK_OP_RESTA expr_mult {$$= insertarOperacion(OP_RESTA,$1,$3);} /*expr - expr*/
		;	;
expr_mult:	term {$$ = $1;}
		| expr_mult TK_OP_MULT term {$$= insertarOperacion(OP_MULT,$1,$3);}/*expr * expr*/
		| expr_mult TK_OP_DIV term {$$= insertarOperacion(OP_DIV,$1,$3);} /*expr / expr*/
			;
term:	TK_NUMERO  {$$ = insertarConstante(T_NUMERO,$1);} /*0..9*/
                | KW_TRUE {$$ = insertarConstante(T_BOOLEAN,T_TRUE);}/* TRUE */
		| KW_FALSE {$$ = insertarConstante(T_BOOLEAN,T_FALSE);} /* FALSE */
		| TK_APAREN expr TK_CPAREN {$$ = $2;}/*(expr)*/
		| TK_APAREN error TK_CPAREN {$$ = NULL;}/**/
		| TK_IDENTIFICADOR {$$ = insertarVariable($1);} /* abb1, bbacc, etc, */
		| TK_CADENA {$$ = insertarCadena($1);} /* 'cadena' */
		;


/*
expresion : expr_bool
	  | expr_arit
	  | expr_rel
	  | TK_CADENA
	  ;

expr_rel  : expr_rel TK_OP_GT expr_rel
	  | expr_rel TK_OP_GET expr_rel
	  | expr_rel TK_OP_LT expr_rel
	  | expr_rel TK_OP_LET expr_rel
	  | expr_rel TK_OP_EQ expr_rel
	  | expr_rel TK_OP_NOEQ expr_rel
	  | TK_IDENTIFICADOR
	  | TK_NUMERO
	  | TK_APAREN expr_rel TK_CPAREN
	  | expr_arit
	  ;

expr_bool : expr_bool KW_OP_AND expr_bool
	  | expr_bool KW_OP_OR expr_bool
	  | TK_IDENTIFICADOR
	  | KW_TRUE
	  | KW_FALSE
	  | TK_APAREN expr_bool TK_CPAREN
	  | expr_rel
	  ;
expr_arit : expr_arit TK_OP_SUMA expr_arit
	  | expr_arit TK_OP_RESTA expr_arit
	  | expr_arit TK_OP_MULT expr_arit
	  | expr_arit TK_OP_DIV expr_arit
	  | TK_NUMERO
	  ;

	      ;
*/
%%
/**Interfaz para parser y lexer*/
int inputparse(const char* filein,const char* fileout){
	int ret = 0;
	//(astTree.root)->hijo = NULL;
	huboErrorSintactico = huboErrorSemantico = huboErrorLexico = 0;
	
	yyin = fopen(filein,"r");
	yyout = fopen(fileout,"w+");
	
	openSymtabFile(fileout);
	yyparse();
	
	borrarTabla();
	/*
	if(huboErrorSintactico!=0){
	  borrarTabla(); //elimina registros de la tabla de simbolos
	  borrarArbol(&astTree); //elimina arbol sintactico luego de que el analisis se completo
	}*/
	fclose(yyin);
	fclose(yyout);
	closeSymtabFile();
	line_num = 1;
	//retorna <>0 si hubo algun error lexico, sintactico y/o semantico
	return huboErrorSintactico + huboErrorSemantico+huboErrorLexico; 
	//ret += retTree;
		//recorrerArbol(&astTree,NULL); // recorre arbol de sintaxis y genera salida   	
	
}


/**Interfaz para ast y symtab*/
/*int generarSalidaHTML(const char* fileout){
	yyout = fopen(fileout,"w+");
	return recorrerArbol(&astTree,NULL); // recorre arbol de sintaxis y genera salida   	
}
*/
/**Interfaz para colaerr*/
int generarSalidaError(const char* fileerr){
	return escribirErrorLogXML(fileerr);
}

/**Analiza archvo filein y genera salida en fileout*/
// int inputparse(const char* filein,const char* fileout,const char* fileerr){
// 	yyin = fopen(filein,"r");
// 	yyout = fopen(fileout,"w+");
// 	if( yyparse() ==0)
// 		if(recorrerArbol(&astTree,NULL) != 0) // recorre arbol de sintaxis y genera salida 
//   			return escribirErrorLogXML(fileerr); //escribe errores si hubieron
// 	return -1;
// 
// }


/*
int main(int argc, char * argv[]){
  yyin = fopen(argv[1],"r");
  yydebug = 1;
  //  yylex();
  //  fclose(yyin);
  if( yyparse() == 0)
    recorrerArbol(&astTree,NULL) != 0;
  return escribirErrorLogXML("/tmp/tmp.xml");
}
*/

	       /*	       int main(){
		 return yyparse();
	       }
	       */
