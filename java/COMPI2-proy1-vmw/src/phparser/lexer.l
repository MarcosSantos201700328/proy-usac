package phparser;

import java_cup.runtime.*;  // definition of scanner/parser interface
//import errormanager.*; // error manager

class Utility {
  public static String cadenaActual = new String("");
  public static void ASSERT
    (
     boolean expr
     )
      { 
	if (false == expr) {
	  throw (new Error("Error: Assertion failed."));
	}
      }
  
  private static final String errorMsg[] = {
    "Error: Unmatched end-of-comment punctuation.",
    "Error: Unmatched start-of-comment punctuation.",
    "Error: Unclosed string.",
    "Error: Illegal character."
    };
  
  public static final int E_ENDCOMMENT = 0; 
  public static final int E_STARTCOMMENT = 1; 
  public static final int E_UNCLOSEDSTR = 2; 
  public static final int E_UNMATCHED = 3; 

  public static void error
    (
     int code
     )
      {
	System.out.println(errorMsg[code]);
      }
}


/* semantic value of token returned by scanner */
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

%class Lexer
%implements java_cup.runtime.Scanner
%function next_token
%type java_cup.runtime.Symbol



%eofval{
  return new Symbol(sym.EOF, null);
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

%states COMMENT1 COMMENT2 STRING

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

<YYINITIAL> {ID} {
	if (yytext().equalsIgnoreCase("PROCEDURE"))//KW_PROCEDURE
		return new Symbol(sym.KW_PROCEDURE, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	if (yytext().equalsIgnoreCase("FUNCTION"))//KW_FUNCTION
		return new Symbol(sym.KW_FUNCTION, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	if (yytext().equalsIgnoreCase("RETURN"))//KW_RETURN
		return new Symbol(sym.KW_RETURN, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	if (yytext().equalsIgnoreCase("GET"))//KW_GET
		return new Symbol(sym.KW_GET, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	if (yytext().equalsIgnoreCase("ECHO"))//KW_ECHO
		return new Symbol(sym.KW_ECHO, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	if (yytext().equalsIgnoreCase("IF"))//KW_IF
		return new Symbol(sym.KW_IF, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	if (yytext().equalsIgnoreCase("WHILE"))//KW_WHILE
		return new Symbol(sym.KW_WHILE, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	if (yytext().equalsIgnoreCase("ELSE"))//KW_ELSE
		return new Symbol(sym.KW_ELSE, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 	
	return new Symbol(sym.TK_ID, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	}  	

<YYINITIAL> "&&" { //TK_AND
		return new Symbol(sym.TK_AND, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}

<YYINITIAL> {IDVAR} { //TK_IDVAR
		return new Symbol(sym.TK_IDVAR, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}

<YYINITIAL> {FLOAT} { //TK_FLOAT
		return new Symbol(sym.TK_FLOAT, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}

<YYINITIAL> {ENTERO} { //TK_INTEGER
		return new Symbol(sym.TK_INTEGER, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}


<YYINITIAL> "/*" { // Comentario
		yybegin(COMMENT1);
	}

<YYINITIAL> "//" { // Comentario
		yybegin(COMMENT2);
	}

<YYINITIAL> "&" { //TK_AMP
		return new Symbol(sym.TK_AMP, null /* new TokenValue(yytext(), yyline, yychar, sourceFilename)*/);
	}

<YYINITIAL> "+" { //TK_MAS
		return new Symbol(sym.TK_MAS, null/* new TokenValue(yytext(), yyline, yychar, sourceFilename)*/);
	}

<YYINITIAL> "-" { //TK_menos
		return new Symbol(sym.TK_MENOS, null/* new TokenValue(yytext(), yyline, yychar, sourceFilename)*/);
	}

<YYINITIAL> "*" { //TK_STAR
		return new Symbol(sym.TK_STAR, null/* new TokenValue(yytext(), yyline, yychar, sourceFilename)*/);
	}

<YYINITIAL> "/" { //TK_SLASH
		return new Symbol(sym.TK_SLASH, null/* new TokenValue(yytext(), yyline, yychar, sourceFilename)*/);
	}

<YYINITIAL> ";" { //TK_PUNTOCOMA
		return new Symbol(sym.TK_PUNTOCOMA, null/*new TokenValue(yytext(), yyline, yychar, sourceFilename)*/);
	}

<YYINITIAL> "(" { //TK_APAREN
		return new Symbol(sym.TK_APAREN, null/*new TokenValue(yytext(), yyline, yychar, sourceFilename)*/);
	}

<YYINITIAL> ")" { //TK_CPAREN
		return new Symbol(sym.TK_CPAREN, null/* new TokenValue(yytext(), yyline, yychar, sourceFilename)*/);
	}

<YYINITIAL> "{" { //TK_ALLAVE
		return new Symbol(sym.TK_ALLAVE, null/* new TokenValue(yytext(), yyline, yychar, sourceFilename)*/);
	}

<YYINITIAL> "}" { //TK_CLLAVE
		return new Symbol(sym.TK_CLLAVE, null /* new TokenValue(yytext(), yyline, yychar, sourceFilename)*/);
	}

<YYINITIAL> "," { //TK_COMA
		return new Symbol(sym.TK_COMA,null/* new TokenValue(yytext(), yyline, yychar, sourceFilename)*/);
	}

<YYINITIAL> "==" { //TK_EQ
		return new Symbol(sym.TK_EQ, null /* new TokenValue(yytext(), yyline, yychar, sourceFilename)*/);
	}

<YYINITIAL> "=" { //TK_IGUAL
		return new Symbol(sym.TK_IGUAL, null /* new TokenValue(yytext(), yyline, yychar, sourceFilename)*/);
	}

<YYINITIAL> "||" { //TK_OR
		return new Symbol(sym.TK_OR, null /* new TokenValue(yytext(), yyline, yychar, sourceFilename)*/);
	}


<YYINITIAL> "<" { //TK_LT
		return new Symbol(sym.TK_LT, null/* new TokenValue(yytext(), yyline, yychar, sourceFilename)*/);
	}

<YYINITIAL> ">" { //TK_GT
		return new Symbol(sym.TK_GT, null /*new TokenValue(yytext(), yyline, yychar, sourceFilename)*/);
	}


<YYINITIAL> "!=" { //TK_NOTEQ
		return new Symbol(sym.TK_NOTEQ, null/*new TokenValue(yytext(), yyline, yychar, sourceFilename)*/);
	}

<YYINITIAL> \" {
		Utility.cadenaActual = "";
		yybegin(STRING);
	}

<YYINITIAL,COMMENT1> {NEW_LINE} {
		yychar = 0;
	}
<YYINITIAL> . {
	//raise error
	}


	

<STRING> \" {
		yybegin(YYINITIAL);
		return new Symbol(sym.TK_STRING, new TokenValue(Utility.cadenaActual, yyline, yychar, sourceFilename));
	}

<STRING> [\\][\\] {
		Utility.cadenaActual += "\\";
	}

<STRING> "\\\"" {
		Utility.cadenaActual += "\"";
	}

<STRING> "\\$" {
		Utility.cadenaActual += "$";
	}

<STRING> "\\t" {
		Utility.cadenaActual += "\t";
	}


<STRING> "\\n" {
		Utility.cadenaActual += "\n";
	}
<STRING> [^\\\n\"]+ {
		Utility.cadenaActual += yytext();
	}
<STRING> "\n" {
		//raise error
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

