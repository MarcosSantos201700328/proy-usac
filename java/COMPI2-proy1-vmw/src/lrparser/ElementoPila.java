/*
 * ElementoPila.java
 *
 * Creada el 12 de marzo de 2007, 09:58 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package lrparser;

import lalrgen.*;
/**
 * Define un elemento que se va a ingresar a la pila de analisis sintactico
 * @author Erik Giron (200313492)
 *
 */
public class ElementoPila {
    int numEstado = -1;
    Simbolo simbolo;
    
    /** Crea una nueva instancia de ElementoPila */
    public ElementoPila() {
    }
    
    public ElementoPila(int estado, Simbolo actual) {
        numEstado = estado;
        simbolo = actual;
    }

    public int getNumEstado() {
        return numEstado;
    }

    public Simbolo getSimbolo() {
        return simbolo;
    }

    public void setNumEstado(int numEstado) {
        this.numEstado = numEstado;
    }

    public void setSimbolo(Simbolo simbolo) {
        this.simbolo = simbolo;
    }
    
}
