/*
 * Utility.java
 *
 * Creada el May 29, 2007, 9:31 AM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package IlGen;
import java.util.*;

/**
 *
 * @author Erik Giron (200313492)
**Utility Class for use in the lexers*/
public class Utility {
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
  /**Devuelve un formato de printf desde una lista de parametros*/
  public static String getPrintFormat(ArrayList l){
      String ret = new String();
      Iterator i = l.iterator();
      ExpAttribute actual;
      while(i.hasNext()){
          actual = (ExpAttribute) i.next();
          switch(actual.getTipo()){
              case SymTab.T_INT:
              case SymTab.T_BOOL:
                  ret += "%d";
                  break;
              case SymTab.T_FLOAT:
                  ret += "%f";
                  break;
              case SymTab.T_CHAR:
              case SymTab.T_STRING:
                  ret += "%s";
                  break;
              default:
                  ret += "%d";
                  break;
          }
      }
      return ret;
  }
  /**Devuelve un formato de scan desde una lista de parametros*/
  public static String getScanFormat(ArrayList l){
      String ret = new String();
      Iterator i = l.iterator();
      ExpAttribute actual;
      while(i.hasNext()){
          actual = (ExpAttribute) i.next();
          ret += "%d";
      }
      return ret;
  }
}
