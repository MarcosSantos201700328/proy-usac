package IlGen;

import java_cup.runtime.*;  // definition of scanner/parser interface
import errormanager.*; // error manager




%%

%class CppLexer
%implements java_cup.runtime.Scanner
%function next_token
%type java_cup.runtime.Symbol



%eofval{
  return new java_cup.runtime.Symbol(SymCpp.EOF, new TokenValue(yytext(), yyline, yychar, sourceFilename));
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

%states COMMENT1 COMMENT2 STRING CHARACTER PREPROC_DIR

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
		return new java_cup.runtime.Symbol(SymCpp.LOG_AND, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "&=" { 
		return new java_cup.runtime.Symbol(SymCpp.ASS_AND, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "&" { 
		return new java_cup.runtime.Symbol(SymCpp.AMPERSAND, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "++" { 
		return new java_cup.runtime.Symbol(SymCpp.INC, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "+=" { 
		return new java_cup.runtime.Symbol(SymCpp.ASS_ADD, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "+" { 
		return new java_cup.runtime.Symbol(SymCpp.PLUS, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "--" { 
		return new java_cup.runtime.Symbol(SymCpp.DEC, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "-=" { 
		return new java_cup.runtime.Symbol(SymCpp.ASS_SUB, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "->*" { 
		return new java_cup.runtime.Symbol(SymCpp.ARROW_STAR, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "->" { 
		return new java_cup.runtime.Symbol(SymCpp.ARROW, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "-" { 
		return new java_cup.runtime.Symbol(SymCpp.MINUS, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "*=" { 
		return new java_cup.runtime.Symbol(SymCpp.ASS_MUL, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "*" { 
		return new java_cup.runtime.Symbol(SymCpp.ASTERISK, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "/=" { 
		return new java_cup.runtime.Symbol(SymCpp.ASS_DIV, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "/" { 
		return new java_cup.runtime.Symbol(SymCpp.SLASH, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "%=" { 
		return new java_cup.runtime.Symbol(SymCpp.ASS_MOD, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "%" { 
		return new java_cup.runtime.Symbol(SymCpp.PERCENT, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "::" { 
		return new java_cup.runtime.Symbol(SymCpp.SCOPE, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> ":" { 
		return new java_cup.runtime.Symbol(SymCpp.COLON, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> ";" { 
		return new java_cup.runtime.Symbol(SymCpp.SEMICOLON, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "(" { 
		return new java_cup.runtime.Symbol(SymCpp.APAR, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> ")" { 
		return new java_cup.runtime.Symbol(SymCpp.CPAR, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "{" { 
		return new java_cup.runtime.Symbol(SymCpp.ALLAVE, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "}" { 
		return new java_cup.runtime.Symbol(SymCpp.CLLAVE, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "[" { 
		return new java_cup.runtime.Symbol(SymCpp.ACOR, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "]" { 
		return new java_cup.runtime.Symbol(SymCpp.CCOR, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "," { 
		return new java_cup.runtime.Symbol(SymCpp.COMA, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> ".*" { 
		return new java_cup.runtime.Symbol(SymCpp.DOT_STAR, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "..." { 
		return new java_cup.runtime.Symbol(SymCpp.ELLIPSIS, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "." { 
		return new java_cup.runtime.Symbol(SymCpp.PUNTO, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "==" { 
		return new java_cup.runtime.Symbol(SymCpp.EQ, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "=" { 
		return new java_cup.runtime.Symbol(SymCpp.EQUALS, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "|=" { 
		return new java_cup.runtime.Symbol(SymCpp.ASS_OR, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "||" { 
		return new java_cup.runtime.Symbol(SymCpp.LOG_OR, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "|" { 
		return new java_cup.runtime.Symbol(SymCpp.BAR, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "?" { 
		return new java_cup.runtime.Symbol(SymCpp.QUEST, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "<<=" { 
		return new java_cup.runtime.Symbol(SymCpp.ASS_SHL, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "<<" { 
		return new java_cup.runtime.Symbol(SymCpp.SHL, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "<=" { 
		return new java_cup.runtime.Symbol(SymCpp.LE, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "<" { 
		return new java_cup.runtime.Symbol(SymCpp.LT, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> ">>=" { 
		return new java_cup.runtime.Symbol(SymCpp.ASS_SHR, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> ">>" { 
		return new java_cup.runtime.Symbol(SymCpp.SHR, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> ">=" { 
		return new java_cup.runtime.Symbol(SymCpp.GE, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> ">" { 
		return new java_cup.runtime.Symbol(SymCpp.GT, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "!=" { 
		return new java_cup.runtime.Symbol(SymCpp.NE, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "!" { 
		return new java_cup.runtime.Symbol(SymCpp.NOTLOG, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "~" { 
		return new java_cup.runtime.Symbol(SymCpp.NOTBIN, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "^=" { 
		return new java_cup.runtime.Symbol(SymCpp.ASS_XOR, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "^" { 
		return new java_cup.runtime.Symbol(SymCpp.CARET, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}

<YYINITIAL> "/*" { // Comentario
		yybegin(COMMENT1);
	}
<YYINITIAL> "//" { // Comentario
		yybegin(COMMENT2);
	}

<YYINITIAL> "#" { // Comentario
		yybegin(PREPROC_DIR);
	}

<YYINITIAL> {ID} {
	if (yytext().equals("NULL"))
		return new java_cup.runtime.Symbol(SymCpp.NULL_LITERAL, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	if (yytext().equals("sizeof"))
		return new java_cup.runtime.Symbol(SymCpp.SIZEOF, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	if (yytext().equals("this"))
		return new java_cup.runtime.Symbol(SymCpp.THIS, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	if (yytext().equals("case"))
		return new java_cup.runtime.Symbol(SymCpp.CASE, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	if (yytext().equals("default"))
		return new java_cup.runtime.Symbol(SymCpp.DEFAULT, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	if (yytext().equals("do"))
		return new java_cup.runtime.Symbol(SymCpp.DO, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	if (yytext().equals("if"))
		return new java_cup.runtime.Symbol(SymCpp.IF, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	if (yytext().equals("while"))
		return new java_cup.runtime.Symbol(SymCpp.WHILE, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	if (yytext().equals("else"))
		return new java_cup.runtime.Symbol(SymCpp.ELSE, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("switch"))
		return new java_cup.runtime.Symbol(SymCpp.SWITCH, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("for"))
		return new java_cup.runtime.Symbol(SymCpp.FOR, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("continue"))
		return new java_cup.runtime.Symbol(SymCpp.CONTINUE, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("break"))
		return new java_cup.runtime.Symbol(SymCpp.BREAK, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("return"))
		return new java_cup.runtime.Symbol(SymCpp.RETURN, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("typedef"))
		return new java_cup.runtime.Symbol(SymCpp.TYPEDEF, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("extern"))
		return new java_cup.runtime.Symbol(SymCpp.EXTERN, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("static"))
		return new java_cup.runtime.Symbol(SymCpp.STATIC, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("auto"))
		return new java_cup.runtime.Symbol(SymCpp.AUTO, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("register"))
		return new java_cup.runtime.Symbol(SymCpp.ELSE, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("public"))
		return new java_cup.runtime.Symbol(SymCpp.PUBLIC, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("protected"))
		return new java_cup.runtime.Symbol(SymCpp.PROTECTED, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("private"))
		return new java_cup.runtime.Symbol(SymCpp.PRIVATE, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("virtual"))
		return new java_cup.runtime.Symbol(SymCpp.VIRTUAL, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("inline"))
		return new java_cup.runtime.Symbol(SymCpp.INLINE, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("bool"))
		return new java_cup.runtime.Symbol(SymCpp.BOOL, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("char"))
		return new java_cup.runtime.Symbol(SymCpp.CHAR, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("int"))
		return new java_cup.runtime.Symbol(SymCpp.INT, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("float"))
		return new java_cup.runtime.Symbol(SymCpp.FLOAT, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("const"))
		return new java_cup.runtime.Symbol(SymCpp.CONST, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("volatile"))
		return new java_cup.runtime.Symbol(SymCpp.VOLATILE, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("void"))
		return new java_cup.runtime.Symbol(SymCpp.VOID, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("class"))
		return new java_cup.runtime.Symbol(SymCpp.CLASS, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("struct"))
		return new java_cup.runtime.Symbol(SymCpp.STRUCT, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("union"))
		return new java_cup.runtime.Symbol(SymCpp.UNION, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("FALSE"))
		return new java_cup.runtime.Symbol(SymCpp.FALSE, new TokenValue(new String("0"), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("TRUE"))
		return new java_cup.runtime.Symbol(SymCpp.TRUE, new TokenValue(new String("1"), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("new"))
		return new java_cup.runtime.Symbol(SymCpp.NEW, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("delete"))
		return new java_cup.runtime.Symbol(SymCpp.DELETE, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	if (yytext().equals("scanf"))
		return new java_cup.runtime.Symbol(SymCpp.SCANF, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	if (yytext().equals("printf"))
		return new java_cup.runtime.Symbol(SymCpp.PRINTF, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	return new java_cup.runtime.Symbol(SymCpp.IDENTIFIER, new TokenValue(new String(yytext()), yyline, yychar, sourceFilename)); 
	}  	

<YYINITIAL> {IDVAR} { 
		return new java_cup.runtime.Symbol(SymCpp.IDENTIFIER, new TokenValue(new String(yytext()), yyline, yychar, sourceFilename));
	}


<YYINITIAL> {ENTERO} { 
		return new java_cup.runtime.Symbol(SymCpp.INTEGER_LITERAL, new TokenValue(new String(yytext()), yyline, yychar, sourceFilename));
	}

<YYINITIAL> {FLOAT} { 
		return new java_cup.runtime.Symbol(SymCpp.FLOATING_LITERAL, new TokenValue(new String(yytext()), yyline, yychar, sourceFilename));
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
<YYINITIAL> {WHITE_SPACE} {
		yychar++;
	}
<YYINITIAL> . {
		ErrorManager.agregarErrorLexico(yyline,yychar, "Error lexico: Simbolo " + yytext() + " Invalido");
		System.out.println("Error lexico: Simbolo " + yytext() + " Invalido en " + yyline + ", " +yychar +".");
	}

<CHARACTER> \' {
		yybegin(YYINITIAL);
		return new java_cup.runtime.Symbol(SymCpp.CHAR_LITERAL, new TokenValue(Utility.cadenaActual, yyline, yychar, sourceFilename));
	}
<CHARACTER> [^\\\n\'] {
		Utility.cadenaActual += yytext();
	}

<STRING> \" {
		yybegin(YYINITIAL);
		return new java_cup.runtime.Symbol(SymCpp.STRING_LITERAL, new TokenValue(Utility.cadenaActual, yyline, yychar, sourceFilename));
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

<PREPROC_DIR> {NEW_LINE} { 
                  yybegin(YYINITIAL);   
		yychar = 0;
                }

<PREPROC_DIR> [^\n] { yychar = 0;
                }