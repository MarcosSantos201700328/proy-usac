%{
/** @file embed.l
 * Analizador lexico para el codigo embedded en un archivo HTML/XHTML estandar .*/
/* Godzilla
 * Proyecto No. 2 de Lenguajes y Compiladores 1
 * (c) 2006 Erik Giron C# 200313492
 */
  //#define YYLMAX 256
  /*#include "includes.h"*/
#define debug
#ifdef __cplusplus
extern "C"{
#endif

#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "embed_yacc.h"
//#include "symtab.h"
#include "colaerr.h"
#include "symtab.h"

/*#include "colaerr.h"*/
#define yylex embedlex
#define yywrap embedwrap
#define yylval embedlval
  //extern int yywrap();
  
  int yylex(void);
  extern int yywrap();
  /*  extern void yyerror(char*);*/
/*  int yywrap(void){
    return 0;
 }*/
  void count(void);
  void borrarEstructurasSintacticas(void);
  extern ast astTree;

#ifdef __cplusplus
}
#endif
#define MAX_STRLEN 255


 char string_buf[MAX_STRLEN];
 char * string_buf_ptr;
 

%}
/*definicion de condiciones de inicio*/
%s EMBED
%s STRING_EMBED

LETRA [a-zA-Z_]
DIGITO [0-9]
APOSTROFE[\']
CADENA [^\'\n]
CADENATAG [^\%]
WHITESPACE [\ \t]
NEWLINE [\n\r]
%%

                   /*Expresiones regulares para codigo embedded*/
                  /*=============================================*/

<EMBED>{
  
  {LETRA}({LETRA}|{DIGITO})* { /*identificador*/
      printf("texto leido: %s\n",yytext);
      count();
      if (strcasecmp("AND",yytext) == 0)
	 return KW_OP_AND;
      else if (strcasecmp("OR",yytext) == 0)
	 return KW_OP_OR;        
      else if (strcasecmp("TRUE",yytext) == 0)
	 return KW_TRUE; 
      else if (strcasecmp("FALSE",yytext) == 0)
	 return KW_FALSE; 
      else if (strcasecmp("VAR",yytext) == 0){ printf("var leido");
	 return KW_VAR; }
      else if (strcasecmp("INTEGER",yytext) == 0)
	 return KW_INTEGER; 
      else if (strcasecmp("STRING",yytext) == 0)
	 return KW_STRING; 
      else if (strcasecmp("BOOLEAN",yytext) == 0)
	 return KW_BOOLEAN; 
      else if (strcasecmp("IF",yytext) == 0)
	 return KW_IF; 
      else if (strcasecmp("THEN",yytext) == 0)
	 return KW_THEN; 
      else if (strcasecmp("ELSE",yytext) == 0)
	 return KW_ELSE; 
      else if (strcasecmp("WHILE",yytext) == 0)
	 return KW_WHILE; 
      else if (strcasecmp("FOR",yytext) == 0)
	 return KW_FOR; 
      else if (strcasecmp("TO",yytext) == 0)
	 return KW_TO; 
      else if (strcasecmp("BEGIN",yytext) == 0)
	 return KW_BEGIN; 
      else if (strcasecmp("END",yytext) == 0)
	 return KW_END; 
      else if (strcasecmp("PRINT",yytext) == 0)
	 return KW_PRINT; 
      else if (strcasecmp("VERTABLASIMBOLOS",yytext) == 0)
	return KW_PRINTSYMTAB; 
      else{
         yylval.stringValue = (char*) malloc(sizeof(char)*(strlen(yytext) + 1));
         strcpy(yylval.stringValue,yytext);
	 return TK_IDENTIFICADOR;
	 }	 
  }
  
  ({DIGITO})+  {  /*numero*/  
    count();
    printf("Numero %s\n",yytext);
    yylval.intValue = atoi(yytext);
    return TK_NUMERO;
  }
  
  [,] {count();return TK_COMA;}
  \:  {count();return TK_DOSPUNTOS;}
  \;  {count();return TK_PUNTOCOMA;}

  \= {count();return TK_OP_EQ;}
  \:\= {count();return TK_OP_ASIGNACION;}
  \< {count();return TK_OP_LT;}
  \<\= {count();return TK_OP_LET;}
  \> {count();return TK_OP_GT;}
  \>\= {count();return TK_OP_GET;}
  \<\> {count();return TK_OP_NOEQ;}
  \- {count();return TK_OP_RESTA;}
  \+ {count();return TK_OP_SUMA;}
  \/ {count();return TK_OP_DIV;}
  \* {count();return TK_OP_MULT;}
  \( {count();return TK_APAREN;}
  \) {count();return TK_CPAREN;}
  
  {APOSTROFE} { /*Literal de Cadena*/ 
    printf("Leyendo Cadena \n");
    count();
    string_buf_ptr = string_buf;
    BEGIN(STRING_EMBED);
  }

  \%\> /*fin codigo embedded*/    {
    BEGIN(INITIAL);
    count();
    printf("Fin codigo embedded\n");
    return CLOSE_EMBED;
  
  }
  
  <<EOF>> {
    errorLexico("Cadena sin terminar,");
    borrarEstructurasSintacticas();
    yyterminate();    
  }
  
  [\ \t]+   { count(); /*Espacios en Blanco*/   
  }
  
  [\n\r] {count(); printf("Ignorando nueva linea: linea num %d\n",line_num);}
  
  . {errorLexico("CARACTER INVALIDO");}
}
        /*Expresiones para las cadenas encerradas entre apostrofe dentro del codigo embed*/
                      /*=============================================*/
<STRING_EMBED>{
  {APOSTROFE}  { /*fin de cadena*/
    BEGIN(EMBED); //regresa al codigo embed
    count();
    *string_buf_ptr = '\0';
    printf("Cadena leida %s\n",string_buf);
    yylval.stringValue = (char*) malloc(sizeof(string_buf));
    strcpy(yylval.stringValue,string_buf);
    return TK_CADENA;

  }
  <<EOF>> {
    errorLexico("Cadena sin terminar,");
  borrarEstructurasSintacticas();
  yyterminate();
  }
  [^\\\n\r\']+   { /*Cadena entre comillas*/   
    count();
    char *yptr = yytext;
    
    while(*yptr){
      *string_buf_ptr++ = *yptr++;
    }
    
    *string_buf_ptr = '\0';
    printf("Leyendo cadena \n");    
  }
  
}

                          /*Expresiones Regulares para HTML*/
                      /*=============================================*/

    /*Cambio de linea*/
[\n]    { count(); ECHO;}

  /*'<'{CADENATAG}'>' Tags HTML a ignorar*/ 
  /*  printf("Ignorando tags HTML\n");*/
  /* } */


\<\% /*Inicio codigo embedded*/ {
  printf("Inicio codigo Embedded\n");
  count();
  BEGIN(EMBED);
  return OPEN_EMBED;
}
<<EOF>> {  
  yyterminate();
}
. {count(); ECHO; /*iGNORAR TODO*/}

%%
int column = 0;
int line_num = 1;
char error_line_buffer[256];

void count()
{
	int i;
	static char *elb=error_line_buffer;

	for (i = 0; yytext[i] != '\0'; i++)
	{
		if (yytext[i] == '\n')
		{
			column = 0;
			line_num++;
			elb = error_line_buffer;
		}
		else
		{
			*elb++ = yytext[i];
			if (yytext[i] == '\t')
				column += 8 - (column & (8-1));
			else
				column++;
		}
		*elb = 0;
	}
}

void borrarEstructurasSintacticas(){
  //  borrarTabla(); /* borra tabla de simbolos al encontrar fin de archivo*/    
 // borrarArbol(&astTree);
}


