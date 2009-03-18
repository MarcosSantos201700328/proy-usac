/*
 * Token.java
 *
 * Creada el 11 de marzo de 2007, 02:54 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package lrparser;

/**
 * Clase que define a los tokens retornados por el lexer
 * @author Erik Giron (200313492)
 *
 */
public class Token {
    private String token = new String();                                        //El nombre de la ER
    private String valor = new String();                                        //Lo que tiene escrito la ER
    
    /** Crea una nueva instancia de Token */
    public Token() {
    }
    /**Devuelve el nombre del token( nombre de la expresion regular)     */
    public String getToken() {
        return token;
    }
    /**Devuelve la cadena leida de la entrada por la expresion regular que define al token*/
    public String getValor() {
        return valor;
    }
    /**Asigna el nombre del token( nombre de la expresion regular)     */
    public void setToken(String lexema) {
        this.token = lexema;
    }
    /**Asigna la cadena leida de la entrada por la expresion regular que define al token*/
    public void setValor(String valor) {
        this.valor = valor;
    }
    
}
