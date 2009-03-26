package ui;

import java_cup.runtime.*;  // definition of scanner/parser interface
//import IlGen.TokenValue;

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

%class ConsoleLexer
%implements java_cup.runtime.Scanner
%function next_token
%type java_cup.runtime.Symbol



%eofval{
  return new java_cup.runtime.Symbol(SymConsole.EOF, new TokenValue(yytext(), yyline, yychar, sourceFilename));
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
WHITE_SPACE=([\ \t\f])+
NEW_LINE=(\n|\r)+
ID=({ALPHA})({ALPHA}|{DIGITO})*
DIR_SEP=[/\\]
DRIVE_OR_ROOT=((({ALPHA})(":")({DIR_SEP}))|({DIR_SEP}))
FILE_OR_DIR=([0-9A-Za-z.-?~(){}\ #_])+
FILENAME=({DRIVE_OR_ROOT})|(({DRIVE_OR_ROOT})({FILE_OR_DIR})({DIR_SEP}{FILE_OR_DIR})*({DIR_SEP})?)
%%



<YYINITIAL> "cd" { 
		return new java_cup.runtime.Symbol(SymConsole.CD, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "exit" { 
		return new java_cup.runtime.Symbol(SymConsole.EXIT, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "close" { 
		return new java_cup.runtime.Symbol(SymConsole.CLOSE, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "clrscr" { 
		return new java_cup.runtime.Symbol(SymConsole.CLEAR, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "new" { 
		return new java_cup.runtime.Symbol(SymConsole.NEW, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}
<YYINITIAL> "@" { 
		return new java_cup.runtime.Symbol(SymConsole.ARROBA, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}

<YYINITIAL> "show" { 
		return new java_cup.runtime.Symbol(SymConsole.SHOW, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}

<YYINITIAL> "mvc" { 
		return new java_cup.runtime.Symbol(SymConsole.MVC, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}

<YYINITIAL> "mv" { 
		return new java_cup.runtime.Symbol(SymConsole.MV, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}

<YYINITIAL> ".." { 
		return new java_cup.runtime.Symbol(SymConsole.DOTDOT, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}

<YYINITIAL> "-h" { 
		return new java_cup.runtime.Symbol(SymConsole.HELP, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}

<YYINITIAL> "-so" { 
		return new java_cup.runtime.Symbol(SymConsole.SO, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}

<YYINITIAL> "sr" { 
		return new java_cup.runtime.Symbol(SymConsole.SR, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}

<YYINITIAL> "sp" { 
		return new java_cup.runtime.Symbol(SymConsole.SP, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}

<YYINITIAL> "st" { 
		return new java_cup.runtime.Symbol(SymConsole.ST, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}

<YYINITIAL> "si" { 
		return new java_cup.runtime.Symbol(SymConsole.SI, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}

<YYINITIAL> "-s" { 
		return new java_cup.runtime.Symbol(SymConsole.SS, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}

<YYINITIAL> "lx" { 
		return new java_cup.runtime.Symbol(SymConsole.LX, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}

<YYINITIAL> "sx" { 
		return new java_cup.runtime.Symbol(SymConsole.SX, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}

<YYINITIAL> "se" { 
		return new java_cup.runtime.Symbol(SymConsole.SE, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}

<YYINITIAL> {FILENAME} { 
		return new java_cup.runtime.Symbol(SymConsole.FILENAME, new TokenValue(yytext(), yyline, yychar, sourceFilename));
	}

<YYINITIAL> {NEW_LINE} {
		yychar = 0;
	}
<YYINITIAL> {WHITE_SPACE} {
		yychar++;
	}
<YYINITIAL> [a-zA-Z]+ {		
		MainWindow.getConsolaActual().writeLn("Error: Simbolo " + yytext() + " Invalido en " + yyline + ", " +yychar +", verifique que no este en mayusculas y que sea un comando valido.");
	}
<YYINITIAL> . {		
		MainWindow.getConsolaActual().writeLn("Error: Simbolo " + yytext() + " Invalido en " + yyline + ", " +yychar +", verifique que no este en mayusculas y que sea un comando valido.");
	}
