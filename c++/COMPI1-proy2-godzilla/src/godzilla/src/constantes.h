/** @file constantes.h 
 * Constantes utilizadas por el arbol de sintaxis abstracta.*/
/* Godzilla
* Proyecto No. 2 de Lenguajes y Compiladores 1
* (c) 2006 Erik Giron C# 200313492
*/
#ifndef CONSTANTES_H
#define CONSTANTES_H

/* Constantes que identificaran a los nodos y a la tabla de simbolos*/
#define T_ERROR -1
#define T_FALSE 0
#define T_TRUE 1
#define T_CONSTANTE 1000
#define T_VARIABLE 1001
#define T_NUMERO 1002
#define T_IDENTIFICADOR  1003
#define T_OPERACION 1004
#define T_EXPR 1005
#define T_ASIGNACION 1006
#define T_SENTENCIA 1007
#define T_DECLARACION 1008
#define T_IF 1009
#define T_WHILE 1010
#define T_FOR 1011
#define T_TOKEN 1012
#define T_CALL 1013
#define T_CADENA 1015 /*no usa*/
#define OP_OR 1016
#define OP_AND 1017
#define OP_LT 1018
#define OP_LET 1019
#define OP_EQ 1020
#define OP_NEQ 1021
#define OP_GT 1022
#define OP_GET 1023
#define OP_SUMA 1024
#define OP_RESTA 1025
#define OP_MULT 1026
#define OP_DIV 1027
#define T_INTEGER 1028
#define T_BOOLEAN 1029
#define T_STRING 1030
#define T_LITERAL 1031

#define T_PRINTCALL 1032
#define T_PRINTSYMCALL 1033
#endif
