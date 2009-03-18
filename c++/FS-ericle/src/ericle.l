%{
/** @file lexer.l
* Analizador lexico para las sentencias DML a usar en el proyecto .*/
/* ercle
* Proyecto No. 2 de Archivos
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
#include "ericle_yacc.h"
#include "searchtree.h"
#include "search_node.h"
#include "tipos.h"
/*#include "colaerr.h"*/
#define yylex ericlelex
#define yywrap ericlewrap
#define yylval ericlelval
//extern int yywrap();

int yylex(void);
//extern int yywrap();
int yywrap(){
    return 1;
}
/*  extern void yyerror(char*);*/
/*  int yywrap(void){
    return 0;
}*/
	void count(void);

#ifdef __cplusplus
}
#endif
#define MAX_STRLEN 255


char string_buf[MAX_STRLEN];
char * string_buf_ptr;
int column = 0;
int line_num = 1;
char error_line_buffer[256];


%}
/*definicion de condiciones de inicio*/
%s DML
%s STRING_DML

LETRA [a-zA-Z_]
DIGITO [0-9]
APOSTROFE [\"]
CADENA [^\'\n]
CADENATAG [^\%]
WHITESPACE [\ \t]
NEWLINE [\n\r]
%%
	/*Expresiones para las cadenas encerradas entre apostrofe dentro del codigo DML*/
	/*=============================================*/
<STRING_DML>{
{APOSTROFE}  { /*fin de cadena*/
	BEGIN(INITIAL); //regresa al codigo embed
	count();
	*string_buf_ptr = '\0';
	printf("Cadena leida %s\n",string_buf);
//	yylval.stringValue = (char*) malloc(sizeof(string_buf));
	strcpy(yylval.stringValue,string_buf);
	return TK_STRING;

}
<<EOF>> {
    printf("Cadena sin terminar,");
		yyterminate();
}
[^\\\n\r\"]+   { /*Cadena entre comillas*/   
	count();
		char *yptr = yytext;
    
		while(*yptr){
		    *string_buf_ptr++ = *yptr++;
            }
    
		*string_buf_ptr = '\0';
		printf("Leyendo cadena \n");    
}

}		
	
	/*Expresiones Regulares para DML*/
	/*=============================================*/

	

{LETRA}({LETRA}|{DIGITO})* { /*identificador*/
	printf("texto leido: %s\n",yytext);
count();
if (strcasecmp("AND",yytext) == 0)
    return KW_OP_AND;
else if (strcasecmp("OR",yytext) == 0)
    return KW_OP_OR;        
else if (strcasecmp("INSERT",yytext) == 0)
    return INSERT; 
else if (strcasecmp("INTO",yytext) == 0)
    return INTO; 
else if (strcasecmp("VALUES",yytext) == 0)
    return VALUES; 
else if (strcasecmp("SELECT",yytext) == 0)
    return SELECT;
else if (strcasecmp("FROM",yytext) == 0)
    return FROM; 
else if (strcasecmp("WHERE",yytext) == 0)
    return WHERE; 
else if (strcasecmp("AUTOR",yytext) == 0)
    return KW_AUTOR; 
else if (strcasecmp("TITULO",yytext) == 0)
    return KW_TITULO; 
else if (strcasecmp("LIBRO",yytext) == 0)
    return KW_LIBRO; 
else if (strcasecmp("USUARIO",yytext) == 0)
    return KW_USUARIO; 
else if (strcasecmp("TIPO_USUARIO",yytext) == 0)
    return KW_TIPOUSUARIO;
else if (strcasecmp("PRESTAMO",yytext) == 0)
    return KW_PRESTAMO; 
else if (strcasecmp("CONTENIDO",yytext) == 0)
    return KW_CONTENIDO; 
    
else{
    //yylval.stringValue = (char*) malloc(sizeof(char)*(strlen(yytext) + 1));
    strcpy(yylval.stringValue,yytext);
    return TK_IDENTIFICADOR;
}	 
}



({DIGITO})+  {  /*numero*/  
	count();
    printf("Numero %s\n",yytext);    
    //strcpy(yylval.stringValue,yytext);
    yylval.intValue = atoi(yytext);
    return TK_NUMERO;
}

[,] {count();printf("Coma\n");    ;return TK_COMA;}
\;  {count();printf("Punto y Coma\n");return TK_PUNTOCOMA;}

\= {count();printf("igual\n");return TK_OP_EQ;}
\< {count();printf("Coma\n");return TK_OP_LT;}
\<\= {count();printf("Menor o Igual\n");return TK_OP_LET;}
\> {count();printf("mayor\n");return TK_OP_GT;}
\>\= {count();printf("mayor o igual\n");return TK_OP_GET;}
\<\> {count();printf("noigual\n");return TK_OP_NOEQ;}
\!\= {count();printf("noigual\n");return TK_OP_NOEQ;}
\* {count();printf("assterisk\n");return TK_OP_MULT;}
\( {count();printf("openparentesis\n");return TK_APAREN;}
\) {count();printf("closeparentesis\n");return TK_CPAREN;}

{APOSTROFE} { /*Literal de Cadena*/ 
	printf("Leyendo Cadena \n");
    count();
    string_buf_ptr = string_buf;
    BEGIN(STRING_DML);
}


<<EOF>> {
    printf("Cadena sin terminar,");
 
    yyterminate();    
}

[\ \t]+   { count(); /*Espacios en Blanco*/   
}

[\n\r] {count(); printf("Ignorando nueva linea: linea num %d\n",line_num);}

. {printf("CARACTER INVALIDO");}





%%

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

