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
     OP_CONCAT = 258,
     OP_NCONCAT = 259,
     OP_SHIFTNR = 260,
     OP_SHIFTNL = 261,
     OP_SHIFTR = 262,
     OP_SHIFTL = 263,
     LPAREN = 264,
     RPAREN = 265,
     END = 266,
     CADENA = 267,
     NUMERO = 268,
     FIXRR = 269
   };
#endif
#define OP_CONCAT 258
#define OP_NCONCAT 259
#define OP_SHIFTNR 260
#define OP_SHIFTNL 261
#define OP_SHIFTR 262
#define OP_SHIFTL 263
#define LPAREN 264
#define RPAREN 265
#define END 266
#define CADENA 267
#define NUMERO 268
#define FIXRR 269




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 31 "parser.y"
typedef union YYSTYPE {
  int intValue;
  char* stringValue;
} YYSTYPE;
/* Line 1285 of yacc.c.  */
#line 70 "strim-parser.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

#if ! defined (YYLTYPE) && ! defined (YYLTYPE_IS_DECLARED)
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;


