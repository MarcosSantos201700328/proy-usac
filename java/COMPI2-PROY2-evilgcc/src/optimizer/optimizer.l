package optimizer;

import java_cup.runtime.*;  // definition of scanner/parser interface
import errormanager.*; // error manager
import IlGen.*;

class TokenValue {          
  public int lineBegin;
  public int charBegin;
  public String text;
  public String filename;   

  TokenValue() {
  }

  TokenValue(String text, int lineBegin, int charBegin, String filename) {
    this.text = new String(text); 
    this.lineBegin = lineBegin; 
    this.charBegin = charBegin;
    this.filename = filename;
     /**Esto solo es para debugear*/
    System.out.println("Linea: " + (lineBegin+1) + ", columna: " + (charBegin+1));
  }

  public String toString() { 
    return text;
  }

  public boolean toBoolean() {
    return Boolean.valueOf(text).booleanValue();  
  }
  
  public int toInt() {
    return Integer.valueOf(text).intValue();
  }

  public double toDouble() {
    return Double.valueOf(text).doubleValue();
  }
  public int getPosLine(){
	return lineBegin;
  }
  public int getPosChar(){
	return charBegin;
  }
}

%%

%class OptLexer
%implements java_cup.runtime.Scanner
%function next_token
%type java_cup.runtime.Symbol



%eofval{
  return new java_cup.runtime.Symbol(SymOpt.EOF, new TokenValue(yytext(), yyline, yychar, sourceFilename));
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

%states COMMENT1 COMMENT2 STRING CHARACTER PREPROC_DIR PRINTFLINE SCANFLINE

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

<YYINITIAL> "+" { 
		return new java_cup.runtime.Symbol(SymOpt.PLUS, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "-" { 
		return new java_cup.runtime.Symbol(SymOpt.MINUS, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "*" { 
		return new java_cup.runtime.Symbol(SymOpt.ASTERISK, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "/" { 
		return new java_cup.runtime.Symbol(SymOpt.SLASH, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "%" { 
		return new java_cup.runtime.Symbol(SymOpt.PERCENT, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> ":" { 
		return new java_cup.runtime.Symbol(SymOpt.COLON, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> ";" { 
		return new java_cup.runtime.Symbol(SymOpt.SEMICOLON, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "(" { 
		return new java_cup.runtime.Symbol(SymOpt.APAR, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> ")" { 
		return new java_cup.runtime.Symbol(SymOpt.CPAR, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "{" { 
		return new java_cup.runtime.Symbol(SymOpt.ALLAVE, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "}" { 
		return new java_cup.runtime.Symbol(SymOpt.CLLAVE, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "[" { 
		return new java_cup.runtime.Symbol(SymOpt.ACOR, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "]" { 
		return new java_cup.runtime.Symbol(SymOpt.CCOR, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "==" { 
		return new java_cup.runtime.Symbol(SymOpt.EQ, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "=" { 
		return new java_cup.runtime.Symbol(SymOpt.EQUALS, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "<=" { 
		return new java_cup.runtime.Symbol(SymOpt.LE, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "<" { 
		return new java_cup.runtime.Symbol(SymOpt.LT, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> ">=" { 
		return new java_cup.runtime.Symbol(SymOpt.GE, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> ">" { 
		return new java_cup.runtime.Symbol(SymOpt.GT, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "!=" { 
		return new java_cup.runtime.Symbol(SymOpt.NE, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}

<YYINITIAL> "/*" { // Comentario
		yybegin(COMMENT1);
	}
<YYINITIAL> "//" { // Comentario
		yybegin(COMMENT2);
	}
<YYINITIAL> "printf" { // Comentario
		yybegin(PRINTFLINE);
	}
<YYINITIAL> "scanf" { // Comentario
		yybegin(SCANFLINE);
	}
<YYINITIAL> "#" { // Comentario
		yybegin(PREPROC_DIR);
	}

<YYINITIAL> {ID} {
	if (yytext().equals("if"))
		return new java_cup.runtime.Symbol(SymOpt.IF, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	if (yytext().equals("goto"))
		return new java_cup.runtime.Symbol(SymOpt.GOTO, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	if (yytext().equals("void"))
		return new java_cup.runtime.Symbol(SymOpt.VOID, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	 				
	return new java_cup.runtime.Symbol(SymOpt.IDENTIFIER, new TokenValue(new String(yytext()), yyline, yychar, sourceFilename)); 
	}  	

<YYINITIAL> {IDVAR} { 
		return new java_cup.runtime.Symbol(SymOpt.IDENTIFIER, new TokenValue(new String(yytext()), yyline, yychar, sourceFilename));
	}


<YYINITIAL> {ENTERO} { 
		return new java_cup.runtime.Symbol(SymOpt.INTEGER_LITERAL, new TokenValue(new String(yytext()), yyline, yychar, sourceFilename));
	}

<YYINITIAL> {FLOAT} { 
		return new java_cup.runtime.Symbol(SymOpt.FLOATING_LITERAL, new TokenValue(new String(yytext()), yyline, yychar, sourceFilename));
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
		return new java_cup.runtime.Symbol(SymOpt.CHAR_LITERAL, new TokenValue(Utility.cadenaActual, yyline, yychar, sourceFilename));
	}
<CHARACTER> [^\\\n\'] {
		Utility.cadenaActual += yytext();
	}

<STRING> \" {
		yybegin(YYINITIAL);
		return new java_cup.runtime.Symbol(SymOpt.STRING_LITERAL, new TokenValue(Utility.cadenaActual, yyline, yychar, sourceFilename));
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

<PRINTFLINE> {NEW_LINE} { 
                  yybegin(YYINITIAL);   
		yychar = 0;
		return new java_cup.runtime.Symbol(SymOpt.PRINTF, new TokenValue(new String("printf" + yytext()), yyline, yychar, sourceFilename)); 
                }

<PRINTFLINE> [^\n] { yychar = 0;
                }
<SCANFLINE> {NEW_LINE} { 
                  yybegin(YYINITIAL);   
		yychar = 0;
		return new java_cup.runtime.Symbol(SymOpt.PRINTF, new TokenValue(new String("scanf" + yytext()), yyline, yychar, sourceFilename)); 
                }

<SCANFLINE> [^\n] { yychar = 0;
                }


<PREPROC_DIR> {NEW_LINE} { 
                  yybegin(YYINITIAL);   
		yychar = 0;
                }

<PREPROC_DIR> [^\n] { yychar = 0;
                }