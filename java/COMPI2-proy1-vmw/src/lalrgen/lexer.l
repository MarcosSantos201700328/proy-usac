//import sym.*;               // definition of terminals returned by scanner
package lalrgen;

import java_cup.runtime.*;  // definition of scanner/parser interface
import errormanager.*; // error manager
/* semantic value of token returned by scanner */
class TokenValue {          
  public int lineBegin;
  public int charBegin;
  public String text;
  public String filename;   

  TokenValue() {
  }

  TokenValue(String text, int lineBegin, int charBegin, String filename) {
    this.text = text; 
    this.lineBegin = lineBegin; 
    this.charBegin = charBegin;
    this.filename = filename;
     /**Esto solo es para debugear*/
    System.out.println("Linea: " + lineBegin + ", columna: " + charBegin);
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

%states CODEPART ERPART VACC ACTION_CODE COMMENT1 COMMENT2

ALPHA=[A-Za-z_]
DIGITO=[0-9]
ALPHA_NUMERIC={ALPHA}|{DIGITO}
ID={ALPHA}({ALPHA_NUMERIC})*
ENTEROPOS=({DIGITO})+
WHITE_SPACE=([\ \t\f])+
NEW_LINE=(\n|\r)
STRING_TEXT=(\\\"|[^\n\"]|\\{WHITE_SPACE_CHAR}+\\)*
COMMENT_TEXT=([^/*\n]|[^*\n]"/"[^*\n]|[^/\n]"*"[^/\n]|"*"[^/\n]|"/"[^*\n])*
IGNORE_PERCENT=[^%]+

%%
<YYINITIAL> ("%%") {
		yybegin(CODEPART);
	}
<YYINITIAL> {IGNORE_PERCENT} {
}

<CODEPART> ("%%") {
		yybegin(ERPART);
	}
<CODEPART> {IGNORE_PERCENT} {
}
<ERPART> ("%%") {
		yybegin(VACC);
	}
<ERPART> {IGNORE_PERCENT} {
}

<VACC> "%%" {
	return new Symbol(sym.TK_SEPARATOR, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	}
<VACC> {ID} {
	if (yytext().equalsIgnoreCase("terminal"))//KW_TERM
		return new Symbol(sym.KW_TERM, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	if (yytext().equalsIgnoreCase("no"))//KW_NO
		return new Symbol(sym.KW_NO, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	if (yytext().equalsIgnoreCase("entero"))//KW_NO
		return new Symbol(sym.KW_INT, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	if (yytext().equalsIgnoreCase("real"))//KW_NO
		return new Symbol(sym.KW_REAL, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	if (yytext().equalsIgnoreCase("string"))//KW_NO
		return new Symbol(sym.KW_STR, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	return new Symbol(sym.TK_ID, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	}  	

<VACC> "::" {
  return new Symbol(sym.TK_PRODUCE, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	}  	

<VACC> ":" {
  return new Symbol(sym.TK_DOSPUNTOS, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	}  
<VACC> ";" {
  return new Symbol(sym.TK_PUNCOMA, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	}  

<VACC> "," {
  return new Symbol(sym.TK_COMA, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	}  	


<VACC> "{:" {
  yybegin(ACTION_CODE);
  return new Symbol(sym.TK_APARPUN, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	}  	


<VACC> "//" { // Comentario
		yybegin(COMMENT2);
	}


<VACC> {WHITE_SPACE} { }
<VACC> {NEW_LINE} {yychar = 0;}



<VACC> "/*" { 
            yybegin(COMMENT1);
            }



<VACC> . {
		ErrorManager.agregarErrorLexico(yyline,yychar,new String("Caracter Invalido: " + yychar));
  return new Symbol(sym.error, null);
	}

<COMMENT1> "*/" { 
                  yybegin(VACC);   
                }

<COMMENT1> {COMMENT_TEXT} { yychar = 0;
                }

<COMMENT2> {NEW_LINE} { 
                  yybegin(VACC);   
		yychar = 0;
                }

<COMMENT2> [^\n] { yychar = 0;
                }


<ACTION_CODE> ([^:])* {
	//String str =  yytext().substring(1,yytext().length() - 1);	
	return new Symbol(sym.STR_SENTENCIAS, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	}

<ACTION_CODE> ":}" {
  yybegin(VACC);
  return new Symbol(sym.TK_CPARPUN, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	}

