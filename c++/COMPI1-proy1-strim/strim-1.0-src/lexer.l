%{
  //#define YYLMAX 256
  /*#include "includes.h"*/

#ifdef __cplusplus
extern "C"{
#endif

#include <stdio.h>
#include <string.h>
#include "strim-parser.h"

  int yylex(void);

#ifdef __cplusplus
}
#endif
%}

LETRA [a-zA-Z]
DIGITO [0-9]
/* SIGNOS [\<\>\=\.\^\(\)\#]*/
%%

{LETRA}({LETRA}|{DIGITO}|\ |\t|\n|\r)*({LETRA}|{DIGITO})*    {
                              yylval.stringValue = (char*) malloc(sizeof(char)*512);
                              strcpy(yylval.stringValue,yytext);
                              return CADENA;} /*regexp para cadenas */;
{DIGITO}+        yylval.intValue=atoi(yytext); return NUMERO; /*regexp para numeros */;
"<"             return OP_SHIFTL; /*regexp para operador < */;
">"             return OP_SHIFTR; /*regexp para operador > */;
"<="          return OP_SHIFTNL; /*regexp para operador <= */;
">="          return OP_SHIFTNR; /*regexp para operador >= */;
"\."             return OP_CONCAT; /*regexp para operador  */;
"\^"             return OP_NCONCAT; /*regexp para operador ^ */;
"\("             return LPAREN; /*regexp para ( (agrupacion)*/;
"\)"             return RPAREN; /*regexp para ) (agrupacion) */;
"#"             return END; /*regexp para # (fin de instruccion) */ ;
[\n\r]+                 /* ignorar end of line */;
[\ \t]+                  /* ignorar espacio */;
. { fprintf(yyout,"ERROR LEXICO: Caracter no pertenece al lenguaje\n\n");}; /*Cualquier otro caracter genera error*/
%%
