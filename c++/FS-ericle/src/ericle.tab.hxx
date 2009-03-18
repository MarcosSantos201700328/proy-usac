/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

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
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     TK_INTEGER = 258,
     TK_STRING = 259,
     TK_IDENTIFICADOR = 260,
     INSERT = 261,
     INTO = 262,
     TK_APAREN = 263,
     TK_CPAREN = 264,
     VALUES = 265,
     TK_PUNTOCOMA = 266,
     SELECT = 267,
     FROM = 268,
     WHERE = 269,
     KW_OP_OR = 270,
     KW_OP_AND = 271,
     TK_OP_EQ = 272,
     TK_OP_LT = 273,
     TK_OP_LET = 274,
     TK_OP_GT = 275,
     TK_OP_GET = 276,
     TK_OP_NOEQ = 277,
     TK_OP_MULT = 278,
     TK_COMA = 279,
     TK_CADENA = 280,
     TK_NUMERO = 281
   };
#endif
/* Tokens.  */
#define TK_INTEGER 258
#define TK_STRING 259
#define TK_IDENTIFICADOR 260
#define INSERT 261
#define INTO 262
#define TK_APAREN 263
#define TK_CPAREN 264
#define VALUES 265
#define TK_PUNTOCOMA 266
#define SELECT 267
#define FROM 268
#define WHERE 269
#define KW_OP_OR 270
#define KW_OP_AND 271
#define TK_OP_EQ 272
#define TK_OP_LT 273
#define TK_OP_LET 274
#define TK_OP_GT 275
#define TK_OP_GET 276
#define TK_OP_NOEQ 277
#define TK_OP_MULT 278
#define TK_COMA 279
#define TK_CADENA 280
#define TK_NUMERO 281




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 38 "ericle.yxx"
typedef union YYSTYPE {
    int intValue;
    char stringValue[64];
    char ** arrStr;
    search_node* treeNode;
} YYSTYPE;
/* Line 1447 of yacc.c.  */
#line 97 "ericle.tab.hxx"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE ericlelval;



