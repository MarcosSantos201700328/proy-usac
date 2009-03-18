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


public class Lexer implements java_cup.runtime.Scanner {
	private final int YY_BUFFER_SIZE = 512;
	private final int YY_F = -1;
	private final int YY_NO_STATE = -1;
	private final int YY_NOT_ACCEPT = 0;
	private final int YY_START = 1;
	private final int YY_END = 2;
	private final int YY_NO_ANCHOR = 4;
	private final int YY_BOL = 128;
	private final int YY_EOF = 129;

  public String sourceFilename;
  public void init(){};
  public int getLine(){
	return yyline;
	}
public int getChar(){
	return yychar;
	}
	private java.io.BufferedReader yy_reader;
	private int yy_buffer_index;
	private int yy_buffer_read;
	private int yy_buffer_start;
	private int yy_buffer_end;
	private char yy_buffer[];
	private int yychar;
	private int yyline;
	private boolean yy_at_bol;
	private int yy_lexical_state;

	public Lexer (java.io.Reader reader) {
		this ();
		if (null == reader) {
			throw (new Error("Error: Bad input stream initializer."));
		}
		yy_reader = new java.io.BufferedReader(reader);
	}

	public Lexer (java.io.InputStream instream) {
		this ();
		if (null == instream) {
			throw (new Error("Error: Bad input stream initializer."));
		}
		yy_reader = new java.io.BufferedReader(new java.io.InputStreamReader(instream));
	}

	private Lexer () {
		yy_buffer = new char[YY_BUFFER_SIZE];
		yy_buffer_read = 0;
		yy_buffer_index = 0;
		yy_buffer_start = 0;
		yy_buffer_end = 0;
		yychar = 0;
		yyline = 0;
		yy_at_bol = true;
		yy_lexical_state = YYINITIAL;
	}

	private boolean yy_eof_done = false;
	private final int ACTION_CODE = 4;
	private final int ERPART = 2;
	private final int CODEPART = 1;
	private final int YYINITIAL = 0;
	private final int COMMENT2 = 6;
	private final int COMMENT1 = 5;
	private final int VACC = 3;
	private final int yy_state_dtrans[] = {
		0,
		30,
		36,
		38,
		20,
		22,
		43
	};
	private void yybegin (int state) {
		yy_lexical_state = state;
	}
	private int yy_advance ()
		throws java.io.IOException {
		int next_read;
		int i;
		int j;

		if (yy_buffer_index < yy_buffer_read) {
			return yy_buffer[yy_buffer_index++];
		}

		if (0 != yy_buffer_start) {
			i = yy_buffer_start;
			j = 0;
			while (i < yy_buffer_read) {
				yy_buffer[j] = yy_buffer[i];
				++i;
				++j;
			}
			yy_buffer_end = yy_buffer_end - yy_buffer_start;
			yy_buffer_start = 0;
			yy_buffer_read = j;
			yy_buffer_index = j;
			next_read = yy_reader.read(yy_buffer,
					yy_buffer_read,
					yy_buffer.length - yy_buffer_read);
			if (-1 == next_read) {
				return YY_EOF;
			}
			yy_buffer_read = yy_buffer_read + next_read;
		}

		while (yy_buffer_index >= yy_buffer_read) {
			if (yy_buffer_index >= yy_buffer.length) {
				yy_buffer = yy_double(yy_buffer);
			}
			next_read = yy_reader.read(yy_buffer,
					yy_buffer_read,
					yy_buffer.length - yy_buffer_read);
			if (-1 == next_read) {
				return YY_EOF;
			}
			yy_buffer_read = yy_buffer_read + next_read;
		}
		return yy_buffer[yy_buffer_index++];
	}
	private void yy_move_end () {
		if (yy_buffer_end > yy_buffer_start &&
		    '\n' == yy_buffer[yy_buffer_end-1])
			yy_buffer_end--;
		if (yy_buffer_end > yy_buffer_start &&
		    '\r' == yy_buffer[yy_buffer_end-1])
			yy_buffer_end--;
	}
	private boolean yy_last_was_cr=false;
	private void yy_mark_start () {
		int i;
		for (i = yy_buffer_start; i < yy_buffer_index; ++i) {
			if ('\n' == yy_buffer[i] && !yy_last_was_cr) {
				++yyline;
			}
			if ('\r' == yy_buffer[i]) {
				++yyline;
				yy_last_was_cr=true;
			} else yy_last_was_cr=false;
		}
		yychar = yychar
			+ yy_buffer_index - yy_buffer_start;
		yy_buffer_start = yy_buffer_index;
	}
	private void yy_mark_end () {
		yy_buffer_end = yy_buffer_index;
	}
	private void yy_to_mark () {
		yy_buffer_index = yy_buffer_end;
		yy_at_bol = (yy_buffer_end > yy_buffer_start) &&
		            ('\r' == yy_buffer[yy_buffer_end-1] ||
		             '\n' == yy_buffer[yy_buffer_end-1] ||
		             2028/*LS*/ == yy_buffer[yy_buffer_end-1] ||
		             2029/*PS*/ == yy_buffer[yy_buffer_end-1]);
	}
	private java.lang.String yytext () {
		return (new java.lang.String(yy_buffer,
			yy_buffer_start,
			yy_buffer_end - yy_buffer_start));
	}
	private int yylength () {
		return yy_buffer_end - yy_buffer_start;
	}
	private char[] yy_double (char buf[]) {
		int i;
		char newbuf[];
		newbuf = new char[2*buf.length];
		for (i = 0; i < buf.length; ++i) {
			newbuf[i] = buf[i];
		}
		return newbuf;
	}
	private final int YY_E_INTERNAL = 0;
	private final int YY_E_MATCH = 1;
	private java.lang.String yy_error_string[] = {
		"Error: Internal error.\n",
		"Error: Unmatched input.\n"
	};
	private void yy_error (int code,boolean fatal) {
		java.lang.System.out.print(yy_error_string[code]);
		java.lang.System.out.flush();
		if (fatal) {
			throw new Error("Fatal Error.\n");
		}
	}
	private int[][] unpackFromString(int size1, int size2, String st) {
		int colonIndex = -1;
		String lengthString;
		int sequenceLength = 0;
		int sequenceInteger = 0;

		int commaIndex;
		String workString;

		int res[][] = new int[size1][size2];
		for (int i= 0; i < size1; i++) {
			for (int j= 0; j < size2; j++) {
				if (sequenceLength != 0) {
					res[i][j] = sequenceInteger;
					sequenceLength--;
					continue;
				}
				commaIndex = st.indexOf(',');
				workString = (commaIndex==-1) ? st :
					st.substring(0, commaIndex);
				st = st.substring(commaIndex+1);
				colonIndex = workString.indexOf(':');
				if (colonIndex == -1) {
					res[i][j]=Integer.parseInt(workString);
					continue;
				}
				lengthString =
					workString.substring(colonIndex+1);
				sequenceLength=Integer.parseInt(lengthString);
				workString=workString.substring(0,colonIndex);
				sequenceInteger=Integer.parseInt(workString);
				res[i][j] = sequenceInteger;
				sequenceLength--;
			}
		}
		return res;
	}
	private int yy_acpt[] = {
		/* 0 */ YY_NOT_ACCEPT,
		/* 1 */ YY_NO_ANCHOR,
		/* 2 */ YY_NO_ANCHOR,
		/* 3 */ YY_NO_ANCHOR,
		/* 4 */ YY_NO_ANCHOR,
		/* 5 */ YY_NO_ANCHOR,
		/* 6 */ YY_NO_ANCHOR,
		/* 7 */ YY_NO_ANCHOR,
		/* 8 */ YY_NO_ANCHOR,
		/* 9 */ YY_NO_ANCHOR,
		/* 10 */ YY_NO_ANCHOR,
		/* 11 */ YY_NO_ANCHOR,
		/* 12 */ YY_NO_ANCHOR,
		/* 13 */ YY_NO_ANCHOR,
		/* 14 */ YY_NO_ANCHOR,
		/* 15 */ YY_NO_ANCHOR,
		/* 16 */ YY_NO_ANCHOR,
		/* 17 */ YY_NO_ANCHOR,
		/* 18 */ YY_NO_ANCHOR,
		/* 19 */ YY_NO_ANCHOR,
		/* 20 */ YY_NO_ANCHOR,
		/* 21 */ YY_NO_ANCHOR,
		/* 22 */ YY_NO_ANCHOR,
		/* 23 */ YY_NO_ANCHOR,
		/* 24 */ YY_NO_ANCHOR,
		/* 25 */ YY_NO_ANCHOR,
		/* 26 */ YY_NOT_ACCEPT,
		/* 27 */ YY_NO_ANCHOR,
		/* 28 */ YY_NO_ANCHOR,
		/* 29 */ YY_NO_ANCHOR,
		/* 30 */ YY_NOT_ACCEPT,
		/* 31 */ YY_NO_ANCHOR,
		/* 32 */ YY_NO_ANCHOR,
		/* 33 */ YY_NOT_ACCEPT,
		/* 34 */ YY_NO_ANCHOR,
		/* 35 */ YY_NO_ANCHOR,
		/* 36 */ YY_NOT_ACCEPT,
		/* 37 */ YY_NOT_ACCEPT,
		/* 38 */ YY_NOT_ACCEPT,
		/* 39 */ YY_NOT_ACCEPT,
		/* 40 */ YY_NOT_ACCEPT,
		/* 41 */ YY_NOT_ACCEPT,
		/* 42 */ YY_NOT_ACCEPT,
		/* 43 */ YY_NOT_ACCEPT
	};
	private int yy_cmap[] = unpackFromString(1,130,
"2:9,10,11,2,10,12,2:18,10,2:4,1,2:4,13,2,7,2:2,9,4:10,5,6,2:5,3:26,2:4,3,2," +
"3:26,8,2,14,2:2,0:2")[0];

	private int yy_rmap[] = unpackFromString(1,44,
"0,1,2,1,3,1,4,1,5,6,7,1:2,8,1:6,9,1,10,1:3,11,1,12,13,14,15,16,17,18,19,20," +
"21,22,23,24,25,26,27")[0];

	private int yy_nxt[][] = unpackFromString(28,15,
"1,26,2:13,-1:17,2:13,-1:2,4:13,-1:2,6:13,-1,15,-1:16,9:2,-1:15,16,-1:19,13," +
"-1:4,1,28:4,39,28:9,1,29:8,40,29,-1,29,41,29,-1,3,-1:14,28:4,-1,28:9,-1,29:" +
"8,40,29,-1,29,42,29,1,33,4:13,-1:5,17,-1:10,29:8,32,29,-1,29,42,29,-1,5,-1:" +
"22,18,-1:3,19,-1:2,29:8,40,29,-1,29,35,29,1,37,6:13,-1,7,-1:13,1,8,27,9,27," +
"10,11,12,31,34,13,14:2,27:2,-1:14,21,-1,29:8,32,29,-1,29,-1,29,-1,29:8,23,2" +
"9,-1,29,35,29,-1,29:8,-1,29,-1,29,35,29,1,24:10,25:2,24:2");

	public java_cup.runtime.Symbol next_token ()
		throws java.io.IOException {
		int yy_lookahead;
		int yy_anchor = YY_NO_ANCHOR;
		int yy_state = yy_state_dtrans[yy_lexical_state];
		int yy_next_state = YY_NO_STATE;
		int yy_last_accept_state = YY_NO_STATE;
		boolean yy_initial = true;
		int yy_this_accept;

		yy_mark_start();
		yy_this_accept = yy_acpt[yy_state];
		if (YY_NOT_ACCEPT != yy_this_accept) {
			yy_last_accept_state = yy_state;
			yy_mark_end();
		}
		while (true) {
			if (yy_initial && yy_at_bol) yy_lookahead = YY_BOL;
			else yy_lookahead = yy_advance();
			yy_next_state = YY_F;
			yy_next_state = yy_nxt[yy_rmap[yy_state]][yy_cmap[yy_lookahead]];
			if (YY_EOF == yy_lookahead && true == yy_initial) {

  return new Symbol(sym.EOF, null);
			}
			if (YY_F != yy_next_state) {
				yy_state = yy_next_state;
				yy_initial = false;
				yy_this_accept = yy_acpt[yy_state];
				if (YY_NOT_ACCEPT != yy_this_accept) {
					yy_last_accept_state = yy_state;
					yy_mark_end();
				}
			}
			else {
				if (YY_NO_STATE == yy_last_accept_state) {
					throw (new Error("Lexical Error: Unmatched Input."));
				}
				else {
					yy_anchor = yy_acpt[yy_last_accept_state];
					if (0 != (YY_END & yy_anchor)) {
						yy_move_end();
					}
					yy_to_mark();
					switch (yy_last_accept_state) {
					case 1:
						
					case -2:
						break;
					case 2:
						{
}
					case -3:
						break;
					case 3:
						{
		yybegin(CODEPART);
	}
					case -4:
						break;
					case 4:
						{
}
					case -5:
						break;
					case 5:
						{
		yybegin(ERPART);
	}
					case -6:
						break;
					case 6:
						{
}
					case -7:
						break;
					case 7:
						{
		yybegin(VACC);
	}
					case -8:
						break;
					case 8:
						{
		ErrorManager.agregarErrorLexico(yyline,yychar,new String("Caracter Invalido: " + yychar));
  return new Symbol(sym.error, null);
	}
					case -9:
						break;
					case 9:
						{
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
					case -10:
						break;
					case 10:
						{
  return new Symbol(sym.TK_DOSPUNTOS, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	}
					case -11:
						break;
					case 11:
						{
  return new Symbol(sym.TK_PUNCOMA, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	}
					case -12:
						break;
					case 12:
						{
  return new Symbol(sym.TK_COMA, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	}
					case -13:
						break;
					case 13:
						{ }
					case -14:
						break;
					case 14:
						{yychar = 0;}
					case -15:
						break;
					case 15:
						{
	return new Symbol(sym.TK_SEPARATOR, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	}
					case -16:
						break;
					case 16:
						{
  return new Symbol(sym.TK_PRODUCE, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	}
					case -17:
						break;
					case 17:
						{
  yybegin(ACTION_CODE);
  return new Symbol(sym.TK_APARPUN, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	}
					case -18:
						break;
					case 18:
						{ // Comentario
		yybegin(COMMENT2);
	}
					case -19:
						break;
					case 19:
						{ 
            yybegin(COMMENT1);
            }
					case -20:
						break;
					case 20:
						{
	//String str =  yytext().substring(1,yytext().length() - 1);	
	return new Symbol(sym.STR_SENTENCIAS, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	}
					case -21:
						break;
					case 21:
						{
  yybegin(VACC);
  return new Symbol(sym.TK_CPARPUN, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	}
					case -22:
						break;
					case 22:
						{ yychar = 0;
                }
					case -23:
						break;
					case 23:
						{ 
                  yybegin(VACC);   
                }
					case -24:
						break;
					case 24:
						{ yychar = 0;
                }
					case -25:
						break;
					case 25:
						{ 
                  yybegin(VACC);   
		yychar = 0;
                }
					case -26:
						break;
					case 27:
						{
		ErrorManager.agregarErrorLexico(yyline,yychar,new String("Caracter Invalido: " + yychar));
  return new Symbol(sym.error, null);
	}
					case -27:
						break;
					case 28:
						{
	//String str =  yytext().substring(1,yytext().length() - 1);	
	return new Symbol(sym.STR_SENTENCIAS, new TokenValue(yytext(), yyline, yychar, sourceFilename)); 
	}
					case -28:
						break;
					case 29:
						{ yychar = 0;
                }
					case -29:
						break;
					case 31:
						{
		ErrorManager.agregarErrorLexico(yyline,yychar,new String("Caracter Invalido: " + yychar));
  return new Symbol(sym.error, null);
	}
					case -30:
						break;
					case 32:
						{ yychar = 0;
                }
					case -31:
						break;
					case 34:
						{
		ErrorManager.agregarErrorLexico(yyline,yychar,new String("Caracter Invalido: " + yychar));
  return new Symbol(sym.error, null);
	}
					case -32:
						break;
					case 35:
						{ yychar = 0;
                }
					case -33:
						break;
					default:
						yy_error(YY_E_INTERNAL,false);
					case -1:
					}
					yy_initial = true;
					yy_state = yy_state_dtrans[yy_lexical_state];
					yy_next_state = YY_NO_STATE;
					yy_last_accept_state = YY_NO_STATE;
					yy_mark_start();
					yy_this_accept = yy_acpt[yy_state];
					if (YY_NOT_ACCEPT != yy_this_accept) {
						yy_last_accept_state = yy_state;
						yy_mark_end();
					}
				}
			}
		}
	}
}
