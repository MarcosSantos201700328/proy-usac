package IlGen;

import java_cup.runtime.*;  // definition of scanner/parser interface
import errormanager.*; // error manager
/*
{C}{L}{A}{S}{S} { return new java_cup.runtime.Symbol(SymPascal.CLASS, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{P}{R}{I}{V}{A}{T}{E} { return new java_cup.runtime.Symbol(SymPascal.PRIVATE, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{P}{U}{B}{L}{I}{C} { return new java_cup.runtime.Symbol(SymPascal.PUBLIC, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
*/

%%

%class PascalLexer
%implements java_cup.runtime.Scanner
%function next_token
%type java_cup.runtime.Symbol



%eofval{
  return new java_cup.runtime.Symbol(SymPascal.EOF, null);
%eofval}
%{
  public String sourceFilename;
  
  public void init(){};
  public int getLine(){
	return yyline;
	}
public int getChar(){
	return yychar;
	}
%}
%line
%char
%public

%states COMMENT1 COMMENT2 STRING CHARACTER


DIGITO =[0-9]
ENTEROPOS =({DIGITO})+
ENTERO =("-")?{ENTEROPOS}
FLOATPOS ={ENTEROPOS}("."{ENTEROPOS})?
FLOAT ="-"?{FLOATPOS}
NEW_LINE =(\n|\r)+
A =[aA]
B =[bB]
C =[cC]
D =[dD]
E =[eE]
F =[fF]
G =[gG]
H =[hH]
I =[iI]
J =[jJ]
K =[kK]
L =[lL]
M =[mM]
N =[nN]
O =[oO]
P =[pP]
Q =[qQ]
R =[rR]
S =[sS]
T =[tT]
U =[uU]
V =[vV]
W =[wW]
X =[xX]
Y =[yY]
Z =[zZ]
NQUOTE =[^']
COMMENT_TEXT=([^*\n])+

%%

{A}{N}{D}  { return new java_cup.runtime.Symbol(SymPascal.AND);}
{A}{R}{R}{A}{Y}  { return new java_cup.runtime.Symbol(SymPascal.ARRAY, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{C}{A}{S}{E}  { return new java_cup.runtime.Symbol(SymPascal.CASE, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{C}{O}{N}{S}{T}  { return new java_cup.runtime.Symbol(SymPascal.CONST, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{D}{I}{V}  { return new java_cup.runtime.Symbol(SymPascal.DIV, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{D}{O}   { return new java_cup.runtime.Symbol(SymPascal.DO, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{D}{O}{W}{N}{T}{O} { return new java_cup.runtime.Symbol(SymPascal.DOWNTO, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{E}{L}{S}{E}  { return new java_cup.runtime.Symbol(SymPascal.ELSE, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{E}{N}{D}  { return new java_cup.runtime.Symbol(SymPascal.END, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{E}{X}{T}{E}{R}{N}|{E}{X}{T}{E}{R}{N}{A}{L} { return new java_cup.runtime.Symbol(SymPascal.EXTERNAL, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{F}{O}{R}  { return new java_cup.runtime.Symbol(SymPascal.FOR, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{F}{O}{R}{W}{A}{R}{D} { return new java_cup.runtime.Symbol(SymPascal.FORWARD, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{F}{U}{N}{C}{T}{I}{O}{N} { return new java_cup.runtime.Symbol(SymPascal.FUNCTION, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{G}{O}{T}{O}  { return new java_cup.runtime.Symbol(SymPascal.GOTO, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{I}{F}   { return new java_cup.runtime.Symbol(SymPascal.IF, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{I}{N}   { return new java_cup.runtime.Symbol(SymPascal.IN, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{L}{A}{B}{E}{L}  { return new java_cup.runtime.Symbol(SymPascal.LABEL, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{M}{O}{D}  { return new java_cup.runtime.Symbol(SymPascal.MOD, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{N}{I}{L}  { return new java_cup.runtime.Symbol(SymPascal.NIL, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{N}{O}{T}  { return new java_cup.runtime.Symbol(SymPascal.NOT, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{O}{F}   { return new java_cup.runtime.Symbol(SymPascal.OF, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{O}{R}   { return new java_cup.runtime.Symbol(SymPascal.OR, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{O}{T}{H}{E}{R}{W}{I}{S}{E} { return new java_cup.runtime.Symbol(SymPascal.OTHERWISE, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{P}{A}{C}{K}{E}{D} { return new java_cup.runtime.Symbol(SymPascal.PACKED, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{B}{E}{G}{I}{N}  { return new java_cup.runtime.Symbol(SymPascal.PBEGIN, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{F}{I}{L}{E}  { return new java_cup.runtime.Symbol(SymPascal.PFILE, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{P}{R}{O}{C}{E}{D}{U}{R}{E} { return new java_cup.runtime.Symbol(SymPascal.PROCEDURE, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{P}{R}{O}{G}{R}{A}{M} { return new java_cup.runtime.Symbol(SymPascal.PROGRAM, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{R}{E}{C}{O}{R}{D} { return new java_cup.runtime.Symbol(SymPascal.RECORD, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{R}{E}{P}{E}{A}{T} { return new java_cup.runtime.Symbol(SymPascal.REPEAT, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{S}{E}{T}  { return new java_cup.runtime.Symbol(SymPascal.SET, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{T}{H}{E}{N}  { return new java_cup.runtime.Symbol(SymPascal.THEN, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{T}{O}   { return new java_cup.runtime.Symbol(SymPascal.TO, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{T}{Y}{P}{E}  { return new java_cup.runtime.Symbol(SymPascal.TYPE, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{U}{N}{T}{I}{L}  { return new java_cup.runtime.Symbol(SymPascal.UNTIL, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{V}{A}{R}  { return new java_cup.runtime.Symbol(SymPascal.VAR, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{W}{H}{I}{L}{E}  { return new java_cup.runtime.Symbol(SymPascal.WHILE, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{W}{I}{T}{H}  { return new java_cup.runtime.Symbol(SymPascal.WITH, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{I}{N}{T}{E}{G}{E}{R}  { return new java_cup.runtime.Symbol(SymPascal.INTEGER, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{R}{E}{A}{L}  { return new java_cup.runtime.Symbol(SymPascal.REAL, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{C}{H}{A}{R}  { return new java_cup.runtime.Symbol(SymPascal.CHAR, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{S}{T}{R}{I}{N}{G}  { return new java_cup.runtime.Symbol(SymPascal.STRING, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{U}{S}{E}{S}  { return new java_cup.runtime.Symbol(SymPascal.USES, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{W}{R}{I}{T}{E}  { return new java_cup.runtime.Symbol(SymPascal.WRITE, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{W}{R}{I}{T}{E}{L}{N}  { return new java_cup.runtime.Symbol(SymPascal.WRITELN, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{R}{E}{A}{D}  { return new java_cup.runtime.Symbol(SymPascal.READ, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
{R}{E}{A}{D}{L}{N}  { return new java_cup.runtime.Symbol(SymPascal.READLN, new TokenValue(yytext(), yyline, yychar, sourceFilename));}


[a-zA-Z_]([a-zA-Z0-9_])* { return new java_cup.runtime.Symbol(SymPascal.IDENTIFIER, new TokenValue(new String(yytext()), yyline, yychar, sourceFilename));}

<YYINITIAL> {FLOAT} { 
		return new java_cup.runtime.Symbol(SymPascal.REALNUMBER, new TokenValue(new String(yytext()), yyline, yychar, sourceFilename));
	}

<YYINITIAL> {ENTERO} { 
		return new java_cup.runtime.Symbol(SymPascal.DIGSEQ, new TokenValue(new String(yytext()), yyline, yychar, sourceFilename));
	}


":="   { return new java_cup.runtime.Symbol(SymPascal.ASSIGNMENT, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
'({NQUOTE}|'')+' { return new java_cup.runtime.Symbol(SymPascal.CHARACTER_STRING, new TokenValue(new String(yytext()), yyline, yychar, sourceFilename));}
":"   { return new java_cup.runtime.Symbol(SymPascal.COLON, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
","   { return new java_cup.runtime.Symbol(SymPascal.COMMA, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
[0-9]+   { return new java_cup.runtime.Symbol(SymPascal.DIGSEQ, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
"."   { return new java_cup.runtime.Symbol(SymPascal.DOT, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
".."   { return new java_cup.runtime.Symbol(SymPascal.DOTDOT, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
"="   { return new java_cup.runtime.Symbol(SymPascal.EQUAL, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
">="   { return new java_cup.runtime.Symbol(SymPascal.GE, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
">"   { return new java_cup.runtime.Symbol(SymPascal.GT, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
"["   { return new java_cup.runtime.Symbol(SymPascal.LBRAC, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
"<="   { return new java_cup.runtime.Symbol(SymPascal.LE, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
"("   { return new java_cup.runtime.Symbol(SymPascal.LPAREN, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
"<"   { return new java_cup.runtime.Symbol(SymPascal.LT, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
"-"   { return new java_cup.runtime.Symbol(SymPascal.MINUS, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
"<>"   { return new java_cup.runtime.Symbol(SymPascal.NOTEQUAL, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
"+"   { return new java_cup.runtime.Symbol(SymPascal.PLUS, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
"]"   { return new java_cup.runtime.Symbol(SymPascal.RBRAC, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
[0-9]+"."[0-9]+  { return new java_cup.runtime.Symbol(SymPascal.REALNUMBER, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
")"   { return new java_cup.runtime.Symbol(SymPascal.RPAREN, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
";"   { return new java_cup.runtime.Symbol(SymPascal.SEMICOLON, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
"/"   { return new java_cup.runtime.Symbol(SymPascal.SLASH, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
"//" { // Comentario
		yybegin(COMMENT2);
	}
"*"   { return new java_cup.runtime.Symbol(SymPascal.STAR, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
"**"   { return new java_cup.runtime.Symbol(SymPascal.STARSTAR, new TokenValue(yytext(), yyline, yychar, sourceFilename));}
"->"|"^"   { return new java_cup.runtime.Symbol(SymPascal.UPARROW, new TokenValue(yytext(), yyline, yychar, sourceFilename));}

"(*"   {yybegin(COMMENT1);}
"{"    {yybegin(COMMENT2);}


[ \t\f]  {yychar++;}

\n    {yychar = 0;}

.    { ErrorManager.agregarErrorLexico(yyline,yychar, "Error lexico: Simbolo " + yytext() + " Invalido");
		System.out.println("Error lexico: Simbolo " + yytext() + " Invalido en " + yyline + ", " +yychar +".");
    }

<COMMENT1> "*)" { 
                  yybegin(YYINITIAL);   
                }

<COMMENT1> {COMMENT_TEXT} { yychar = 0;
                }

<COMMENT2> {NEW_LINE} { 
                  yybegin(YYINITIAL);   
		yychar = 0;
                }

<COMMENT2> [^\n] { yychar = 0;
                }


