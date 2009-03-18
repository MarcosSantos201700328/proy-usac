%{
#define YYDEBUG 1
  // usar YYLTYPE para localizacion de lineas
#ifdef __cplusplus
  extern "C"{
#endif
#include <stdio.h>
#include <string.h>
#include "funciones.h"
    
    extern FILE* yyout;
    int yyparse(void);
    int yylex(void);
    void yyerror(const char *str) {
      // Redefinir para mi propio manejador de errores
      fprintf(stdin,"mi error: %s\n",str);
    }
    
    int yywrap(){
      return 1;
    } 
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
}
/*  ** No Terminales ** */
%type <stringValue> opbinaria opunaria
%type <stringValue> operacion sentencia instruccion// entreparen
%start instruccion
/*  ** Terminales ** */

/* Operadores con asociatividad izquierda */
%left OP_CONCAT; // precedencia 0
/* Operadores con asociatividad derecha */
%right OP_NCONCAT // precedencia 1
%right OP_SHIFTL OP_SHIFTR OP_SHIFTNL OP_SHIFTNR // precedencia 2
/* parentesis  */
%token LPAREN RPAREN END // precedencia 3
%token <stringValue> CADENA /* cadenas */
%token <intValue> NUMERO /* numeros */
%token FIXRR /*Token para componer problemas de reduccion/reduccion*/

/* Gramatica libre de contexto */
%%
instruccion:    sentencia 
                 {
		   fprintf(yyout,"Instruccion finalizada. \n================================================================================\n\n" );
		   printf("Instruccion finalizada. \n================================================================================\n\n" );
		 }

                | instruccion sentencia 
                 {
		   fprintf(yyout,"Instruccion finalizada. \n================================================================================\n\n");
		   printf("Instruccion finalizada. \n================================================================================\n\n");
		 }

;

sentencia: 	 END  {/*fprintf(yyout,"fin\n");*/}
                | operacion END {$$ = $1;/* fprintf(yyout,"operacion fin\n")*/
		printf("(->) RESULTADO DE OPERACIONES HASTA FINAL DE SENTENCIA:\n\t\t \"%s\"\n",$1);
		fprintf(yyout,"(->) RESULTADO DE OPERACIONES HASTA FINAL DE SENTENCIA:\n\t\t \"%s\"\n",$1);}
                | error END { fprintf(yyout,"(!!) Se ha encontrado un error, por favor, corrija el archivo de entrada y\n   reinicie la aplicacion\n"); printf("(!) Error en instruccion\n");YYACCEPT;}
		;

operacion:       CADENA  { $$ = $1; @$.first_line = @$.last_line = @1.first_line;
                           fprintf(yyout,"(<) Cadena leida: \"%s\" \n",$1);printf("(<) Cadena leida: \"%s\"\n",$1);}
               | opunaria {$$ = $1;fprintf(yyout,"(>) Resultado operacion unaria:\n\t\"%s\"\n",$1);}
               | opbinaria {$$ = $1;fprintf(yyout,"(>) Resultado operacion binaria:\n\t\"%s\"\n",$1);}
               ;

opunaria:        operacion OP_SHIFTL {
                 $$ = shiftnleft($1,1); printf("(*) Rotacion a la izquierda\n");}
               | operacion OP_SHIFTR {
                 $$ = shiftnright($1,1); printf("(*) Rotacion a la derecha\n");}
               | LPAREN operacion RPAREN {$$ = $2;printf("(>) Resultado operacion:%s\n",$2);}
               ;

opbinaria:       operacion OP_CONCAT operacion {
		 $$ = strcat($1,$3); free($3); printf("(*) Concatenacion\n"); fprintf(yyout,"(*) Concatenacion\n");}
               | operacion OP_NCONCAT NUMERO { 
		 $$ = repeat($1,$3); printf("(*) Concatenacion %d veces\n",$3); fprintf(yyout,"(*) Concatenacion %d veces\n",$3);}
               | operacion OP_SHIFTNL NUMERO {
		 $$ = shiftnleft($1,$3); printf("(*) Rotacion a la izquierda %d caracteres\n ",$3);fprintf(yyout,"(*) Rotacion a la izquierda %d caracteres\n ",$3);}
               | operacion OP_SHIFTNR NUMERO {
		 $$ = shiftnright($1,$3); printf("(*) Rotacion a la derecha %d caracteres\n",$3);fprintf(yyout,"(*) Rotacion a la derecha %d caracteres\n",$3);}

%%
	       /*	       int main(){
		 return yyparse();
	       }
	       */
