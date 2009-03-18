/*
 * Scanner.java
 *
 * Created on 5 de marzo de 2007, 07:44 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package lrparser;

/**
 * Interface Scanner  
 * 
 *Declara el metodo next_token() que debe ser implementado
 *por los scanners, el fin de archivo($EOF$) puede ser indicada ya sea retornanto *
 * <code>new Token($EOF$)</code> o
 * <code>null</code>.
 *@author Erik giron basado en la interfaz de Cup por David MacMahon <davidm@smartsc.com> 
 ***************************************************/
public interface Scanner {
    /** Devuelve el siguiente token, o <code>null</code> en fin de archivo. */
    public Token next_token() throws java.lang.Exception;
}
