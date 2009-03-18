package lrparser;

import java_cup.runtime.*;  // definition of scanner/parser interface
//import errormanager.*; // error manager

%%

%class TestLexer
%implements lrparser.Scanner
%function next_token
%type lrparser.Token



%eofval{
	Token ret = new Token();
	ret.setToken(new String("$EOF$"));
	ret.setValor(new String("$EOF$"));
	return ret;
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

<YYINITIAL> ({ENTEROPOS})+ {
	Token ret = new Token();
	ret.setToken(new String("digito"));
	ret.setValor(new String(yytext()));
	return ret;
}

<YYINITIAL> "+" {
	Token ret = new Token();
	ret.setToken(new String("mas"));
	ret.setValor(new String(yytext()));
	return ret;
}

<YYINITIAL> "-" {
	Token ret = new Token();
	ret.setToken(new String("menos"));
	ret.setValor(new String(yytext()));
	return ret;
}

<YYINITIAL> "*" {
	Token ret = new Token();
	ret.setToken(new String("por"));
	ret.setValor(new String(yytext()));	
	return ret;
}

<YYINITIAL> "/" {
	Token ret = new Token();
	ret.setToken(new String("div"));
	ret.setValor(new String(yytext()));
	return ret;
}

<YYINITIAL> "(" {
	Token ret = new Token();
	ret.setToken(new String("pa"));
	ret.setValor(new String(yytext()));
	return ret;
}

<YYINITIAL> ")" {
	Token ret = new Token();
	ret.setToken(new String("pc"));
	ret.setValor(new String(yytext()));
	return ret;
}

<YYINITIAL> (({WHITE_SPACE})|({NEW_LINE}))* {

}
<YYINITIAL> . {
	Token ret = new Token();
	ret.setToken(new String("@error"));
	ret.setValor(new String(yytext()));
	return ret;
}
