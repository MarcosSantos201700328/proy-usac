package IlGen;

import java_cup.runtime.*;  // definition of scanner/parser interface
import errormanager.*; // error manager




%%

%class JavaLexer
%implements java_cup.runtime.Scanner
%function next_token
%type java_cup.runtime.Symbol


%eofval{
  return new java_cup.runtime.Symbol(SymJava.EOF, null);
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

ALPHA=[A-Za-z_]
DIGITO=[0-9]
ALPHA_NUMERIC={ALPHA}|{DIGITO}
ID={ALPHA}({ALPHA_NUMERIC})*
IDVAR=("$"){ID}
ENTEROPOS=({DIGITO})+
ENTERO=("-")?{ENTEROPOS}
FLOATPOS={ENTEROPOS}("."{ENTEROPOS})?
FLOAT="-"?{FLOATPOS}
WHITE_SPACE=([\ \t\f])+
NEW_LINE=(\n|\r)+
STRING_TEXT=(\\\"|[^\n\"]|\\{WHITE_SPACE_CHAR}+\\)*
COMMENT_TEXT=([^/*\n]|[^*\n]"/"[^*\n]|[^/\n]"*"[^/\n]|"*"[^/\n]|"/"[^*\n])*
IGNORE_PERCENT=[^%]

%%


<YYINITIAL> "&&" { 
		return new java_cup.runtime.Symbol(SymJava.ANDAND, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "&=" { 
		return new java_cup.runtime.Symbol(SymJava.ANDEQ, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "&" { 
		return new java_cup.runtime.Symbol(SymJava.AND, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "++" { 
		return new java_cup.runtime.Symbol(SymJava.PLUSPLUS, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "+=" { 
		return new java_cup.runtime.Symbol(SymJava.PLUSEQ, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "+" { 
		return new java_cup.runtime.Symbol(SymJava.PLUS, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "--" { 
		return new java_cup.runtime.Symbol(SymJava.MINUSMINUS, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "-=" { 
		return new java_cup.runtime.Symbol(SymJava.MINUSEQ, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "-" { 
		return new java_cup.runtime.Symbol(SymJava.MINUS, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "*=" { 
		return new java_cup.runtime.Symbol(SymJava.MULTEQ, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "*" { 
		return new java_cup.runtime.Symbol(SymJava.MULT, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "/=" { 
		return new java_cup.runtime.Symbol(SymJava.DIVEQ, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "/" { 
		return new java_cup.runtime.Symbol(SymJava.DIV, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "%=" { 
		return new java_cup.runtime.Symbol(SymJava.MODEQ, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "%" { 
		return new java_cup.runtime.Symbol(SymJava.MOD, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> ":" { 
		return new java_cup.runtime.Symbol(SymJava.COLON, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> ";" { 
		return new java_cup.runtime.Symbol(SymJava.SEMICOLON, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "(" { 
		return new java_cup.runtime.Symbol(SymJava.LPAREN, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> ")" { 
		return new java_cup.runtime.Symbol(SymJava.RPAREN, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "{" { 
		return new java_cup.runtime.Symbol(SymJava.LBRACE, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "}" { 
		return new java_cup.runtime.Symbol(SymJava.RBRACE, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "[" { 
		return new java_cup.runtime.Symbol(SymJava.LBRACK, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "]" { 
		return new java_cup.runtime.Symbol(SymJava.RBRACK, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "," { 
		return new java_cup.runtime.Symbol(SymJava.COMMA,new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "..." { 
		return new java_cup.runtime.Symbol(SymJava.ELLIPSIS,new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "." { 
		return new java_cup.runtime.Symbol(SymJava.DOT,new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "==" { 
		return new java_cup.runtime.Symbol(SymJava.EQEQ, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "=" { 
		return new java_cup.runtime.Symbol(SymJava.EQ, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "|=" { 
		return new java_cup.runtime.Symbol(SymJava.OREQ, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "||" { 
		return new java_cup.runtime.Symbol(SymJava.OROR, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "|" { 
		return new java_cup.runtime.Symbol(SymJava.OR, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "?" { 
		return new java_cup.runtime.Symbol(SymJava.QUESTION, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "<<=" { 
		return new java_cup.runtime.Symbol(SymJava.LSHIFTEQ, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "<<" { 
		return new java_cup.runtime.Symbol(SymJava.LSHIFT, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "<=" { 
		return new java_cup.runtime.Symbol(SymJava.LTEQ, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "<" { 
		return new java_cup.runtime.Symbol(SymJava.LT, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> ">>=" { 
		return new java_cup.runtime.Symbol(SymJava.RSHIFTEQ, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> ">>" { 
		return new java_cup.runtime.Symbol(SymJava.RSHIFT, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> ">=" { 
		return new java_cup.runtime.Symbol(SymJava.GTEQ, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> ">" { 
		return new java_cup.runtime.Symbol(SymJava.GT, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "!=" { 
		return new java_cup.runtime.Symbol(SymJava.NOTEQ, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "!" { 
		return new java_cup.runtime.Symbol(SymJava.NOT, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "~" { 
		return new java_cup.runtime.Symbol(SymJava.COMP, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "^=" { 
		return new java_cup.runtime.Symbol(SymJava.XOREQ, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "^" { 
		return new java_cup.runtime.Symbol(SymJava.XOR, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}

<YYINITIAL> "/*" { // Comentario
		yybegin(COMMENT1);
	}
<YYINITIAL> "//" { // Comentario
		yybegin(COMMENT2);
	}

<YYINITIAL> {ID} {
	if (yytext().equals("null"))
		return new java_cup.runtime.Symbol(SymJava.NULL_LITERAL, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	if (yytext().equals("this"))
		return new java_cup.runtime.Symbol(SymJava.THIS, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	if (yytext().equals("case"))
		return new java_cup.runtime.Symbol(SymJava.CASE, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	if (yytext().equals("default"))
		return new java_cup.runtime.Symbol(SymJava.DEFAULT, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	if (yytext().equals("do"))
		return new java_cup.runtime.Symbol(SymJava.DO, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	if (yytext().equals("if"))
		return new java_cup.runtime.Symbol(SymJava.IF, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	if (yytext().equals("while"))
		return new java_cup.runtime.Symbol(SymJava.WHILE, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	if (yytext().equals("else"))
		return new java_cup.runtime.Symbol(SymJava.ELSE, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("switch"))
		return new java_cup.runtime.Symbol(SymJava.SWITCH, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("for"))
		return new java_cup.runtime.Symbol(SymJava.FOR, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("continue"))
		return new java_cup.runtime.Symbol(SymJava.CONTINUE, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("break"))
		return new java_cup.runtime.Symbol(SymJava.BREAK, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("return"))
		return new java_cup.runtime.Symbol(SymJava.RETURN, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("static"))
		return new java_cup.runtime.Symbol(SymJava.STATIC, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("abstract"))
		return new java_cup.runtime.Symbol(SymJava.ABSTRACT, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("register"))
		return new java_cup.runtime.Symbol(SymJava.ELSE, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("public"))
		return new java_cup.runtime.Symbol(SymJava.PUBLIC, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("protected"))
		return new java_cup.runtime.Symbol(SymJava.PROTECTED, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("private"))
		return new java_cup.runtime.Symbol(SymJava.PRIVATE, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("boolean"))
		return new java_cup.runtime.Symbol(SymJava.BOOLEAN, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("char"))
		return new java_cup.runtime.Symbol(SymJava.CHAR, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("int"))
		return new java_cup.runtime.Symbol(SymJava.INT, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("float"))
		return new java_cup.runtime.Symbol(SymJava.FLOAT, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("final"))
		return new java_cup.runtime.Symbol(SymJava.FINAL, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("void"))
		return new java_cup.runtime.Symbol(SymJava.VOID, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("class"))
		return new java_cup.runtime.Symbol(SymJava.CLASS, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("false"))
		return new java_cup.runtime.Symbol(SymJava.BOOLEAN_LITERAL, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("true"))
		return new java_cup.runtime.Symbol(SymJava.BOOLEAN_LITERAL, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("new"))
		return new java_cup.runtime.Symbol(SymJava.NEW, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("String"))
		return new java_cup.runtime.Symbol(SymJava.STRING, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("package"))
		return new java_cup.runtime.Symbol(SymJava.PACKAGE, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("import"))
		return new java_cup.runtime.Symbol(SymJava.IMPORT, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 		return new java_cup.runtime.Symbol(SymJava.IDENTIFIER, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	}  	

<YYINITIAL> {IDVAR} { 
		return new java_cup.runtime.Symbol(SymJava.IDENTIFIER, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}


<YYINITIAL> {ENTERO} { 
		return new java_cup.runtime.Symbol(SymJava.INTEGER_LITERAL, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}

<YYINITIAL> {FLOAT} { 
		return new java_cup.runtime.Symbol(SymJava.FLOATING_POINT_LITERAL, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}

<YYINITIAL> \' {
		Utility.cadenaActual = "";
		yybegin(CHARACTER);
	}
<YYINITIAL> \" {
		Utility.cadenaActual = "";
		yybegin(STRING);
	}
<YYINITIAL,COMMENT1> {NEW_LINE} {
		yychar = 0;
	}

<YYINITIAL> {WHITE_SPACE} { yychar++;
	}


<YYINITIAL> . {
	ErrorManager.agregarErrorLexico(yyline,yychar, "Error lexico: Simbolo " + yytext() + " Invalido");
		System.out.println("Error lexico: Simbolo " + yytext() + " Invalido en " + yyline + ", " +yychar +".");
	}

<CHARACTER> \' {
		yybegin(YYINITIAL);
		return new java_cup.runtime.Symbol(SymJava.CHARACTER_LITERAL, new TokenValue(Utility.cadenaActual, yyline, yychar, sourceFilename));
	}
<CHARACTER> [^\\\n\'] {
		Utility.cadenaActual += yytext();
	}

<STRING> \" {
		yybegin(YYINITIAL);
		return new java_cup.runtime.Symbol(SymJava.STRING_LITERAL, new TokenValue(Utility.cadenaActual, yyline, yychar, sourceFilename));
	}

<STRING> [^\\\n\"]+ {
		Utility.cadenaActual += yytext();
	}

<CHARACTER,STRING> [\\][\\] {
		Utility.cadenaActual += "\\";
	}

<CHARACTER,STRING> "\\\"" {
		Utility.cadenaActual += "\"";
	}
<CHARACTER,STRING> "\\\'" {
		Utility.cadenaActual += "\'";
	}

<CHARACTER,STRING> "\\t" {
		Utility.cadenaActual += "\t";
	}
<CHARACTER,STRING> "\\n" {
		Utility.cadenaActual += "\n";
	}
<CHARACTER,STRING> "\\r" {
		Utility.cadenaActual += "\r";
	}
<CHARACTER,STRING> "\\b" {
		Utility.cadenaActual += "\b";
	}
<CHARACTER,STRING> "\n" {
		//errorLexico()
		//throw new Exception("Error semantico, no puede haber cambio de linea dentro de una literal de cadena");
	}	


<COMMENT1> "*/" { 
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

