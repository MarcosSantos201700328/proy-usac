/*
 * Elemento.java
 *
 * Creada el 13 de febrero de 2007, 09:39 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package lalrgen;
import java.util.*;
/**
 * Representa una produccion sencilla (sin operador "|") de una sola linea
 * @author Erik Giron (200313492)
 *
 */
public class Elemento implements Comparator, java.io.Serializable{
    
    private int numProduccion;/**Numero de la produccion en orden descendente segun la entrada*/
    private NoTerminal li;/**Lado izquierdo de la produccion gramatical*/
    private LadoDerecho ld;/**Lado derecho de la produccion*/
    
    
    /** Crea una nueva instancia de Elemento */
    public Elemento() {
    }
    /** Crea una nueva instancia de Elemento */
    public Elemento(Simbolo pli, String paccion) {
        li = new NoTerminal(pli);        
        ld = new LadoDerecho(null,paccion);
    }    
    public Elemento(Simbolo pli, LadoDerecho pld, String paccion) {
        li = /*(NoTerminal) pli;*/new NoTerminal(pli);        
        /**Si tenemos lado derecho vacio quiere decir que debemos insertar epsilon*/
        if (pld == null){
            ld = new LadoDerecho();
            ld.insertarSimbolo(Vacc.epsilon);
        }
        else{
            ld = pld;
        }
            
            
           
        ld.setAccion(paccion);
    }  
    public int compare(Object o1, Object o2){
        return -1;
    }
    
    public boolean equals(Object o){
        if (o != null && o.getClass().equals(this.getClass()))
            if(((Elemento)o).getLi().equals(this.li) &&
                ((Elemento)o).getLd().equals(this.ld))
                return true;                
        return false;
    }
    /**Devuelve el lado derecho de una produccion*/
    public LadoDerecho getLd() {
        return this.ld;
    }
    /**Devuelve el no terminal del lado izquierdo de una produccion*/
    public NoTerminal getLi() {
        return this.li;
    }
    
    public String toString(){
        return new String(li.toString() + " --> " + ld.toString());
    }
    /**Asigna numero de produccion*/
    public void setNumProduccion(int k) {
        this.numProduccion = k;
    }
    /**Devuelve numero de produccion*/
    public int getNumProduccion() {
        return this.numProduccion;
    }
    
}
