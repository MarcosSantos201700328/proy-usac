/*
 * ElementoLR0.java
 *
 * Creada el 1 de marzo de 2007, 08:25 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor. * 
 */

package lalrgen;

import java.util.*;

/**
 * Provee una abstraccion de un elemento LR0 que contiene una produccion y su respectivo
 * puntito
 * @author Erik Giron (200313492)
 *
 */
public class ElementoLR0 {
    private int numProduccion; ///Produccion a la que pertenece
    private int posPuntito; ///Posicion del puntito    
    private boolean esNucleo = false; // bandera para probar si es nucleo
    private java.util.HashSet<Terminal> lookaheads;/**Listado de lookaheads*/
    //private java.util.TreeSet<Terminal> lookaheads; ///Conjunto de terminales de anticipacion
    
    private Elemento produccion; ///Produccion a la que pertenece el elemento
    
    /** Crea una nueva instancia de ElementoLR0 */    
    public ElementoLR0() {
        lookaheads = new HashSet<Terminal>();
    }    
    /**Construye nuevo elemento LR0 desde produccion e, con el puntito al inicio*/
    public ElementoLR0(Elemento e) {
        lookaheads = new HashSet<Terminal>();
        produccion = e;
        numProduccion = e.getNumProduccion();
        posPuntito = 0;        
    }    
    /**Constructor de copia*/
    public ElementoLR0(ElementoLR0 e){
        this.numProduccion = e.getNumProduccion();
        this.posPuntito = e.getPosPuntito();
        this.produccion = e.getProduccion();
        //this.lookaheads = e.getLookAheads();
        this.lookaheads = new HashSet<Terminal>();
        this.lookaheads.addAll(e.getLookAheads());
        this.esNucleo = false;
    }
    
    /**Desplaza un caracter el puntito en el elemento actual; Retorna un simbolo si fue posible desplazar
     o null si no fue posible*/
    public Simbolo shift(){
        Elemento e = produccion;
        int longs = e.getLd().getLongitud();
        /**Si podemos desplazar el puntito mas alla desplazamos*/
        if(posPuntito < longs && !(produccion.getLd().getSimbolo(0).equals(Vacc.epsilon))){          
            posPuntito ++; //desplazamos puntito
            return e.getLd().getSimbolo(posPuntito - 1); //retornamos simbolo que se desplazo
        }
        else
            return null;
        
    }
    
    /**Obtenemos el numero de produccion que representa al elemento*/
    public int getNumProduccion() {
        return this.numProduccion;
    }
    /**Devuelve la posicion del puntito dentro del estado*/
    public int getPosPuntito() {
        return this.posPuntito;
    }
    /**Asignamos el numero de produccion que representa al elemento*/
    public void setNumProduccion( int np) {
        this.numProduccion = np;
    }
    /**Asignamos la posicion del puntito dentro del estado*/
    public void setPosPuntito(int pp) {
        this.posPuntito = pp;
    }
    /**Devuelve produccion para la que aplica el elemento*/
    public Elemento getProduccion() {
        return produccion;
    }
    /**Devuelve conjunto de lookaheads asociados al elemento*/
    public HashSet<Terminal> getLookAheads() {
        return this.lookaheads;
    }
    /**Agrega un nuevo lookahead al listado de lookaheads*/
    public void insertLookAhead(Terminal ts){
        this.lookaheads.add(ts);
    }

    /**Agrega lookaheads de una lista al listado de lookaheads*/
    public void insertLookAhead(HashSet<Terminal> ts){        
        this.lookaheads.addAll(ts);
    }
    /**Calcula si elemento es nucleo*/
    private void nucleo(){
        if (posPuntito > 0 || (numProduccion == 0 && posPuntito == 0))
            esNucleo = true;
        else
            esNucleo = false;           
    }
    /**Devolvemos TRUE se elemento es nucleo*/
    public boolean esNucleo(){
        if (posPuntito > 0 || (numProduccion == 0 && posPuntito == 0))
            return true;
        else
            return false;        
    }
    /**Devuelve siguiente simbolo segun la produccion*/
    Simbolo nextSimbolo() {
        return produccion.getLd().getSimbolo(this.posPuntito);
    }
    /**Operador general de igual*/
    public boolean equals(Object o){
        ElementoLR0 el1;
        //if(!o.getClass().equals(this.getClass()))
        //    return false;
        el1 = (ElementoLR0) o;
        if((el1.numProduccion == this.numProduccion)&&
                el1.posPuntito == this.posPuntito
                )
            return true;
        return false;
    }

    public boolean equalsWithLA(Object o){
        ElementoLR0 el1;
        //if(!o.getClass().equals(this.getClass()))
        //    return false;
        el1 = (ElementoLR0) o;
        if((el1.numProduccion == this.numProduccion)&&
                el1.posPuntito == this.posPuntito &&
                el1.lookaheads.equals(this.lookaheads)            
                )
            return true;
        return false;
    }
    
    Simbolo getSimbolo(int i) {
        return this.produccion.getLd().getSimbolo(i);
    }
    /**Realiza union de lookaheads entre un elemento y otros*/
    public void unionLookAheads(HashSet<Terminal> s) {
               
        //HashSet<ElementoLR0> ret = new HashSet<ElementoLR0>();
        Terminal elemIActual = null, elemJActual = null;
        boolean existe = false;        
        //ret.addAll(e0);
        Iterator reti = lookaheads.iterator(), i= s.iterator();
        
        // Recorremos todos los elementos de i
        while(i.hasNext()){
            elemIActual = (Terminal)i.next();
            // Buscamos si el elemento e1[i] existe en ret
            while(reti.hasNext()){
                elemJActual =(Terminal) reti.next();                
                // Si existe elemento, se hace union de lookaheads
                if(!elemJActual.equals(elemIActual)){
                    lookaheads.add(elemIActual);
                }                    
            }
        }        
    }
    /**Retorna verdadero si es posible desplazar el puntito un simbolo mas alla*/
    public boolean canShift() {        
        int longs = produccion.getLd().getLongitud();
        /**Si podemos desplazar el puntito mas alla desplazamos*/
        if(posPuntito < longs && !(produccion.getLd().getSimbolo(0).equals(Vacc.epsilon))){     
            return true;
        }
        return false;
    }
    
    public String toString(){
        String ret = new String();
        
        ret += (this.produccion.getLi().toString());
        ret += (" --> ");
        Iterator i = this.produccion.getLd().getSimbolos().iterator();
        Simbolo sactual;
        Terminal tactual;
        int cont = 0;
        while(i.hasNext()){
            sactual = (Simbolo) i.next();
            if(this.posPuntito == cont){
                ret += (".");
            }
            ret += (sactual.toString());
            ret += (" ");
            cont ++;
        }
        ret += (" {");
        i = this.lookaheads.iterator();
        while(i.hasNext()){
            tactual = (Terminal) i.next();
            ret += (tactual.toString() + " ");
        }
        ret += ("}");
        return ret;
    }

}
