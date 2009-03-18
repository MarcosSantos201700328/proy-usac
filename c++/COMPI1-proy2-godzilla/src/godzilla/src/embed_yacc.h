/* A Bison parser, made by GNU Bison 1.875d.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TK_COMA = 258,
     TK_OP_ASIGNACION = 259,
     KW_OP_OR = 260,
     KW_OP_AND = 261,
     TK_OP_NOEQ = 262,
     TK_OP_EQ = 263,
     TK_OP_LET = 264,
     TK_OP_LT = 265,
     TK_OP_GET = 266,
     TK_OP_GT = 267,
     TK_OP_RESTA = 268,
     TK_OP_SUMA = 269,
     TK_OP_DIV = 270,
     TK_OP_MULT = 271,
     TK_CPAREN = 272,
     TK_APAREN = 273,
     TK_NUMERO = 274,
     KW_TRUE = 275,
     KW_FALSE = 276,
     TK_IDENTIFICADOR = 277,
     TK_CADENA = 278,
     OPEN_EMBED = 279,
     CLOSE_EMBED = 280,
     KW_VAR = 281,
     TK_DOSPUNTOS = 282,
     KW_INTEGER = 283,
     KW_BOOLEAN = 284,
     KW_STRING = 285,
     TK_PUNTOCOMA = 286,
     KW_THEN = 287,
     KW_IF = 288,
     KW_ELSE = 289,
     KW_WHILE = 290,
     KW_FOR = 291,
     KW_TO = 292,
     KW_BEGIN = 293,
     KW_END = 294,
     KW_PRINT = 295,
     KW_PRINTSYMTAB = 296,
     TK_EOF = 297
   };
#endif
#define TK_COMA 258
#define TK_OP_ASIGNACION 259
#define KW_OP_OR 260
#define KW_OP_AND 261
#define TK_OP_NOEQ 262
#define TK_OP_EQ 263
#define TK_OP_LET 264
#define TK_OP_LT 265
#define TK_OP_GET 266
#define TK_OP_GT 267
#define TK_OP_RESTA 268
#define TK_OP_SUMA 269
#define TK_OP_DIV 270
#define TK_OP_MULT 271
#define TK_CPAREN 272
#define TK_APAREN 273
#define TK_NUMERO 274
#define KW_TRUE 275
#define KW_FALSE 276
#define TK_IDENTIFICADOR 277
#define TK_CADENA 278
#define OPEN_EMBED 279
#define CLOSE_EMBED 280
#define KW_VAR 281
#define TK_DOSPUNTOS 282
#define KW_INTEGER 283
#define KW_BOOLEAN 284
#define KW_STRING 285
#define TK_PUNTOCOMA 286
#define KW_THEN 287
#define KW_IF 288
#define KW_ELSE 289
#define KW_WHILE 290
#define KW_FOR 291
#define KW_TO 292
#define KW_BEGIN 293
#define KW_END 294
#define KW_PRINT 295
#define KW_PRINTSYMTAB 296
#define TK_EOF 297




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 59 "embed.y"
typedef union YYSTYPE {
  int intValue;
  char* stringValue;
  nodo* astNodo;
} YYSTYPE;
/* Line 1285 of yacc.c.  */
#line 127 "embed.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE embedlval;



