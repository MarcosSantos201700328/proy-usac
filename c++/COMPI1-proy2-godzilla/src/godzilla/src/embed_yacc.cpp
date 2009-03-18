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

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* If NAME_PREFIX is specified substitute the variables and functions
   names.  */
#define yyparse embedparse
#define yylex   embedlex
#define yyerror embederror
#define yylval  embedlval
#define yychar  embedchar
#define yydebug embeddebug
#define yynerrs embednerrs


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




/* Copy the first part of user declarations.  */
#line 1 "embed.y"

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


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 59 "embed.y"
typedef union YYSTYPE {
  int intValue;
  char* stringValue;
  nodo* astNodo;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 231 "embed.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 243 "embed.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

# ifndef YYFREE
#  define YYFREE free
# endif
# ifndef YYMALLOC
#  define YYMALLOC malloc
# endif

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   define YYSTACK_ALLOC alloca
#  endif
# else
#  if defined (alloca) || defined (_ALLOCA_H)
#   define YYSTACK_ALLOC alloca
#  else
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   138

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  23
/* YYNRULES -- Number of rules. */
#define YYNRULES  59
/* YYNRULES -- Number of states. */
#define YYNSTATES  116

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned char yyprhs[] =
{
       0,     0,     3,     5,     8,    12,    15,    18,    20,    22,
      25,    27,    29,    31,    33,    35,    37,    43,    49,    55,
      60,    67,    69,    71,    75,    83,    89,    94,    98,   100,
     102,   104,   106,   112,   117,   119,   121,   125,   127,   131,
     133,   137,   141,   143,   147,   151,   155,   159,   161,   165,
     169,   171,   175,   179,   181,   183,   185,   189,   193,   195
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      44,     0,    -1,    45,    -1,    44,    45,    -1,    24,    46,
      25,    -1,     1,    25,    -1,    24,    25,    -1,    47,    -1,
      48,    -1,    47,    48,    -1,    49,    -1,    50,    -1,    51,
      -1,    52,    -1,    55,    -1,     1,    -1,    26,    22,    27,
      28,    31,    -1,    26,    22,    27,    29,    31,    -1,    26,
      22,    27,    30,    31,    -1,    22,     4,    59,    31,    -1,
      33,    59,    32,    58,    34,    58,    -1,    53,    -1,    54,
      -1,    35,    59,    58,    -1,    36,    22,     4,    19,    37,
      19,    58,    -1,    40,    18,    56,    17,    31,    -1,    41,
      18,    17,    31,    -1,    56,     3,    57,    -1,    57,    -1,
      22,    -1,    23,    -1,    19,    -1,    38,    47,    58,    39,
      31,    -1,    38,     1,    39,    31,    -1,    48,    -1,    60,
      -1,    59,     5,    60,    -1,    61,    -1,    60,     6,    61,
      -1,    62,    -1,    61,     8,    62,    -1,    61,     7,    62,
      -1,    63,    -1,    62,    12,    63,    -1,    62,    11,    63,
      -1,    62,    10,    63,    -1,    62,     9,    63,    -1,    64,
      -1,    63,    14,    64,    -1,    63,    13,    64,    -1,    65,
      -1,    64,    16,    65,    -1,    64,    15,    65,    -1,    19,
      -1,    20,    -1,    21,    -1,    18,    59,    17,    -1,    18,
       1,    17,    -1,    22,    -1,    23,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned char yyrline[] =
{
       0,    89,    89,    90,    92,    99,   100,   104,   107,   108,
     114,   115,   116,   117,   118,   119,   124,   125,   126,   130,
     135,   149,   150,   153,   156,   160,   162,   166,   167,   170,
     171,   172,   175,   176,   177,   179,   180,   183,   184,   186,
     187,   188,   190,   191,   192,   193,   194,   196,   197,   198,
     200,   201,   202,   204,   205,   206,   207,   208,   209,   210
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_COMA", "TK_OP_ASIGNACION",
  "KW_OP_OR", "KW_OP_AND", "TK_OP_NOEQ", "TK_OP_EQ", "TK_OP_LET",
  "TK_OP_LT", "TK_OP_GET", "TK_OP_GT", "TK_OP_RESTA", "TK_OP_SUMA",
  "TK_OP_DIV", "TK_OP_MULT", "TK_CPAREN", "TK_APAREN", "TK_NUMERO",
  "KW_TRUE", "KW_FALSE", "TK_IDENTIFICADOR", "TK_CADENA", "OPEN_EMBED",
  "CLOSE_EMBED", "KW_VAR", "TK_DOSPUNTOS", "KW_INTEGER", "KW_BOOLEAN",
  "KW_STRING", "TK_PUNTOCOMA", "KW_THEN", "KW_IF", "KW_ELSE", "KW_WHILE",
  "KW_FOR", "KW_TO", "KW_BEGIN", "KW_END", "KW_PRINT", "KW_PRINTSYMTAB",
  "TK_EOF", "$accept", "inicio", "embed", "codigo", "sentencias",
  "sentencia", "def_var", "asignacion", "condicionales", "ciclos",
  "ciclo_while", "ciclo_for", "llamadas", "lista_tokens", "token",
  "bloque", "expr", "expr_and", "expr_igual", "expr_relacional",
  "expr_suma", "expr_mult", "term", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    43,    44,    44,    45,    45,    45,    46,    47,    47,
      48,    48,    48,    48,    48,    48,    49,    49,    49,    50,
      51,    52,    52,    53,    54,    55,    55,    56,    56,    57,
      57,    57,    58,    58,    58,    59,    59,    60,    60,    61,
      61,    61,    62,    62,    62,    62,    62,    63,    63,    63,
      64,    64,    64,    65,    65,    65,    65,    65,    65,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     2,     3,     2,     2,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     5,     5,     5,     4,
       6,     1,     1,     3,     7,     5,     4,     3,     1,     1,
       1,     1,     5,     4,     1,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     1,     1,     3,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,     0,     0,     2,     5,    15,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     8,    10,    11,
      12,    13,    21,    22,    14,     1,     3,     0,     0,     0,
      53,    54,    55,    58,    59,     0,    35,    37,    39,    42,
      47,    50,     0,     0,     0,     0,     4,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,    23,     0,    31,
      29,    30,     0,    28,     0,    19,     0,     0,     0,    57,
      56,    36,     0,    38,    41,    40,    46,    45,    44,    43,
      49,    48,    52,    51,    15,     0,     0,     0,     0,    26,
      16,    17,    18,     0,     0,     9,     0,     0,    27,    25,
      20,    33,     0,     0,    32,    24
};

/* YYDEFGOTO[NTERM-NUM]. */
static const yysigned_char yydefgoto[] =
{
      -1,     3,     4,    15,    16,    66,    18,    19,    20,    21,
      22,    23,    24,    72,    73,    67,    35,    36,    37,    38,
      39,    40,    41
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -53
static const yysigned_char yypact[] =
{
       4,   -14,    24,     8,   -53,   -53,   -53,     9,   -53,    -4,
      90,    90,    13,    20,    22,    -5,    44,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,    90,     3,    53,
     -53,   -53,   -53,   -53,   -53,    -1,    16,    40,    79,    39,
      52,   -53,     1,    54,    -7,    27,   -53,   -53,     2,    76,
      69,    12,    90,    61,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    81,   -53,   -53,    59,   -53,
     -53,   -53,     7,   -53,    50,   -53,    67,    84,    89,   -53,
     -53,    16,    58,    40,    79,    79,    39,    39,    39,    39,
      52,    52,   -53,   -53,   -13,    61,    63,    -7,    98,   -53,
     -53,   -53,   -53,    61,    99,    56,    92,   113,   -53,   -53,
     -53,   -53,   102,    61,   -53,   -53
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
     -53,   -53,   131,   -53,    70,    -2,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,    41,   -52,    -8,    85,    82,     0,
      66,    57,    64
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -35
static const yysigned_char yytable[] =
{
      17,    82,     6,    42,    52,     1,    52,    52,    25,     1,
      97,     5,    69,    27,    47,    70,    71,    52,    28,    48,
      46,    51,    54,     7,    98,     6,   104,     9,     2,    80,
      49,    53,     2,    75,    10,    43,    11,    12,    44,    65,
      45,    13,    14,   106,    74,     6,     7,    55,    56,     8,
       9,   110,    61,    62,    50,    84,    85,    10,    68,    11,
      12,   115,     6,    17,    13,    14,     7,    63,    64,    -7,
       9,    29,    30,    31,    32,    33,    34,    10,    96,    11,
      12,    99,    94,     7,    13,    14,    79,     9,    57,    58,
      59,    60,   103,   105,    10,   -34,    11,    12,   100,    65,
     107,    13,    14,     7,    76,    77,    78,     9,    29,    30,
      31,    32,    33,    34,    10,   101,    11,    12,    90,    91,
     102,    13,    14,    86,    87,    88,    89,    92,    93,   109,
     111,   112,   113,   114,    26,    95,    83,    81,   108
};

static const unsigned char yycheck[] =
{
       2,    53,     1,    11,     5,     1,     5,     5,     0,     1,
       3,    25,    19,     4,    16,    22,    23,     5,    22,    27,
      25,    29,     6,    22,    17,     1,    39,    26,    24,    17,
      27,    32,    24,    31,    33,    22,    35,    36,    18,    38,
      18,    40,    41,    95,    17,     1,    22,     7,     8,    25,
      26,   103,    13,    14,     1,    55,    56,    33,     4,    35,
      36,   113,     1,    65,    40,    41,    22,    15,    16,    25,
      26,    18,    19,    20,    21,    22,    23,    33,    19,    35,
      36,    31,     1,    22,    40,    41,    17,    26,     9,    10,
      11,    12,    34,    95,    33,    39,    35,    36,    31,    38,
      37,    40,    41,    22,    28,    29,    30,    26,    18,    19,
      20,    21,    22,    23,    33,    31,    35,    36,    61,    62,
      31,    40,    41,    57,    58,    59,    60,    63,    64,    31,
      31,    39,    19,    31,     3,    65,    54,    52,    97
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     1,    24,    44,    45,    25,     1,    22,    25,    26,
      33,    35,    36,    40,    41,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     0,    45,     4,    22,    18,
      19,    20,    21,    22,    23,    59,    60,    61,    62,    63,
      64,    65,    59,    22,    18,    18,    25,    48,    59,    27,
       1,    59,     5,    32,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    38,    48,    58,     4,    19,
      22,    23,    56,    57,    17,    31,    28,    29,    30,    17,
      17,    60,    58,    61,    62,    62,    63,    63,    63,    63,
      64,    64,    65,    65,     1,    47,    19,     3,    17,    31,
      31,    31,    31,    34,    39,    48,    58,    37,    57,    31,
      58,    31,    39,    19,    31,    58
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)		\
   ((Current).first_line   = (Rhs)[1].first_line,	\
    (Current).first_column = (Rhs)[1].first_column,	\
    (Current).last_line    = (Rhs)[N].last_line,	\
    (Current).last_column  = (Rhs)[N].last_column)
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if defined (YYMAXDEPTH) && YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  register short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;


  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
#line 93 "embed.y"
    {
	crearRaiz(yyvsp[-1].astNodo,&astTree);
	// recorre arbol de sintaxis y genera salida   	
	huboErrorSemantico = recorrerArbol(&astTree,NULL); 
	borrarArbol(&astTree);
	}
    break;

  case 5:
#line 99 "embed.y"
    {huboErrorSintactico = -1;}
    break;

  case 7:
#line 104 "embed.y"
    {yyval.astNodo = yyvsp[0].astNodo;}
    break;

  case 8:
#line 107 "embed.y"
    {yyval.astNodo = yyvsp[0].astNodo;}
    break;

  case 9:
#line 108 "embed.y"
    {yyval.astNodo = concatenarSentencia(yyvsp[-1].astNodo,yyvsp[0].astNodo);}
    break;

  case 10:
#line 114 "embed.y"
    { yyval.astNodo = insertarSentencia(T_DECLARACION,yyvsp[0].astNodo,line_num);}
    break;

  case 11:
#line 115 "embed.y"
    {yyval.astNodo = insertarSentencia(T_ASIGNACION,yyvsp[0].astNodo,line_num);}
    break;

  case 12:
#line 116 "embed.y"
    { yyval.astNodo = insertarSentencia(T_IF,yyvsp[0].astNodo,line_num);}
    break;

  case 13:
#line 117 "embed.y"
    {yyval.astNodo=yyvsp[0].astNodo;}
    break;

  case 14:
#line 118 "embed.y"
    {yyval.astNodo = insertarSentencia(T_CALL,yyvsp[0].astNodo,line_num);}
    break;

  case 15:
#line 119 "embed.y"
    {huboErrorSintactico = -1;
	  yyval.astNodo = insertarSentencia(T_ERROR,NULL,line_num);/*yyerrok;yyclearin;YYABORT;*/}
    break;

  case 16:
#line 124 "embed.y"
    {yyval.astNodo=insertarDeclaracion(yyvsp[-3].stringValue,T_INTEGER);}
    break;

  case 17:
#line 125 "embed.y"
    {yyval.astNodo=insertarDeclaracion(yyvsp[-3].stringValue,T_BOOLEAN);}
    break;

  case 18:
#line 126 "embed.y"
    {yyval.astNodo=insertarDeclaracion(yyvsp[-3].stringValue,T_STRING);}
    break;

  case 19:
#line 130 "embed.y"
    {yyval.astNodo=insertarAsignacion(yyvsp[-3].stringValue,yyvsp[-1].astNodo);}
    break;

  case 20:
#line 135 "embed.y"
    {yyval.astNodo=insertarEnunciadoIf(yyvsp[-4].astNodo, yyvsp[-2].astNodo, yyvsp[0].astNodo);}
    break;

  case 21:
#line 149 "embed.y"
    {yyval.astNodo=insertarSentencia(T_WHILE,yyvsp[0].astNodo,line_num);}
    break;

  case 22:
#line 150 "embed.y"
    {yyval.astNodo=insertarSentencia(T_FOR,yyvsp[0].astNodo,line_num);}
    break;

  case 23:
#line 153 "embed.y"
    {yyval.astNodo=insertarCicloWhile(yyvsp[-1].astNodo, yyvsp[0].astNodo);}
    break;

  case 24:
#line 157 "embed.y"
    {yyval.astNodo=insertarCicloFor(yyvsp[-5].stringValue,yyvsp[-3].intValue ,yyvsp[-1].intValue ,yyvsp[0].astNodo);}
    break;

  case 25:
#line 161 "embed.y"
    {yyval.astNodo=insertarLlamada(yyvsp[-2].astNodo);}
    break;

  case 26:
#line 163 "embed.y"
    {yyval.astNodo=insertarLlamadaSymTab(line_num);}
    break;

  case 27:
#line 166 "embed.y"
    {yyval.astNodo = concatenarTokens(yyvsp[-2].astNodo,yyvsp[0].astNodo);}
    break;

  case 28:
#line 167 "embed.y"
    {yyval.astNodo=yyvsp[0].astNodo;}
    break;

  case 29:
#line 170 "embed.y"
    {yyval.astNodo=insertarToken(T_IDENTIFICADOR,yyvsp[0].stringValue);}
    break;

  case 30:
#line 171 "embed.y"
    {yyval.astNodo=insertarToken(T_STRING,yyvsp[0].stringValue);}
    break;

  case 31:
#line 172 "embed.y"
    {yyval.astNodo=insertarToken(T_INTEGER,(void*)(&(yyvsp[0].intValue)));}
    break;

  case 32:
#line 175 "embed.y"
    {yyval.astNodo=concatenarSentencia(yyvsp[-3].astNodo,yyvsp[-2].astNodo)/*$2*/;}
    break;

  case 33:
#line 176 "embed.y"
    {yyval.astNodo=NULL;huboErrorSintactico = -1;}
    break;

  case 34:
#line 177 "embed.y"
    {yyval.astNodo=yyvsp[0].astNodo;}
    break;

  case 35:
#line 179 "embed.y"
    {yyval.astNodo = insertarExpresion(yyvsp[0].astNodo);}
    break;

  case 36:
#line 180 "embed.y"
    {yyval.astNodo=insertarExpresion(insertarOperacion(OP_OR,yyvsp[-2].astNodo,yyvsp[0].astNodo));}
    break;

  case 37:
#line 183 "embed.y"
    {yyval.astNodo = yyvsp[0].astNodo;}
    break;

  case 38:
#line 184 "embed.y"
    {yyval.astNodo=insertarOperacion(OP_AND,yyvsp[-2].astNodo,yyvsp[0].astNodo);}
    break;

  case 39:
#line 186 "embed.y"
    {yyval.astNodo = yyvsp[0].astNodo;}
    break;

  case 40:
#line 187 "embed.y"
    {yyval.astNodo= insertarOperacion(OP_EQ,yyvsp[-2].astNodo,yyvsp[0].astNodo);}
    break;

  case 41:
#line 188 "embed.y"
    {yyval.astNodo= insertarOperacion(OP_NEQ,yyvsp[-2].astNodo,yyvsp[0].astNodo);}
    break;

  case 42:
#line 190 "embed.y"
    {yyval.astNodo = yyvsp[0].astNodo;}
    break;

  case 43:
#line 191 "embed.y"
    {yyval.astNodo= insertarOperacion(OP_GT,yyvsp[-2].astNodo,yyvsp[0].astNodo);}
    break;

  case 44:
#line 192 "embed.y"
    {yyval.astNodo= insertarOperacion(OP_GET,yyvsp[-2].astNodo,yyvsp[0].astNodo);}
    break;

  case 45:
#line 193 "embed.y"
    {yyval.astNodo= insertarOperacion(OP_LT,yyvsp[-2].astNodo,yyvsp[0].astNodo);}
    break;

  case 46:
#line 194 "embed.y"
    {yyval.astNodo= insertarOperacion(OP_LET,yyvsp[-2].astNodo,yyvsp[0].astNodo);}
    break;

  case 47:
#line 196 "embed.y"
    {yyval.astNodo = yyvsp[0].astNodo;}
    break;

  case 48:
#line 197 "embed.y"
    {yyval.astNodo= insertarOperacion(OP_SUMA,yyvsp[-2].astNodo,yyvsp[0].astNodo);}
    break;

  case 49:
#line 198 "embed.y"
    {yyval.astNodo= insertarOperacion(OP_RESTA,yyvsp[-2].astNodo,yyvsp[0].astNodo);}
    break;

  case 50:
#line 200 "embed.y"
    {yyval.astNodo = yyvsp[0].astNodo;}
    break;

  case 51:
#line 201 "embed.y"
    {yyval.astNodo= insertarOperacion(OP_MULT,yyvsp[-2].astNodo,yyvsp[0].astNodo);}
    break;

  case 52:
#line 202 "embed.y"
    {yyval.astNodo= insertarOperacion(OP_DIV,yyvsp[-2].astNodo,yyvsp[0].astNodo);}
    break;

  case 53:
#line 204 "embed.y"
    {yyval.astNodo = insertarConstante(T_NUMERO,yyvsp[0].intValue);}
    break;

  case 54:
#line 205 "embed.y"
    {yyval.astNodo = insertarConstante(T_BOOLEAN,T_TRUE);}
    break;

  case 55:
#line 206 "embed.y"
    {yyval.astNodo = insertarConstante(T_BOOLEAN,T_FALSE);}
    break;

  case 56:
#line 207 "embed.y"
    {yyval.astNodo = yyvsp[-1].astNodo;}
    break;

  case 57:
#line 208 "embed.y"
    {yyval.astNodo = NULL;}
    break;

  case 58:
#line 209 "embed.y"
    {yyval.astNodo = insertarVariable(yyvsp[0].stringValue);}
    break;

  case 59:
#line 210 "embed.y"
    {yyval.astNodo = insertarCadena(yyvsp[0].stringValue);}
    break;


    }

/* Line 1010 of yacc.c.  */
#line 1514 "embed.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* If at end of input, pop the error token,
	     then the rest of the stack, then return failure.  */
	  if (yychar == YYEOF)
	     for (;;)
	       {
		 YYPOPSTACK;
		 if (yyssp == yyss)
		   YYABORT;
		 YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
		 yydestruct (yystos[*yyssp], yyvsp);
	       }
        }
      else
	{
	  YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
	  yydestruct (yytoken, &yylval);
	  yychar = YYEMPTY;

	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

#ifdef __GNUC__
  /* Pacify GCC when the user code never invokes YYERROR and the label
     yyerrorlab therefore never appears in user code.  */
  if (0)
     goto yyerrorlab;
#endif

  yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 250 "embed.y"

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

