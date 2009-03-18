/*
 * SymbolSet.java
 *
 * Creada el 1 de marzo de 2007, 09:55 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package lalrgen;

import java.util.*;

/**
 * Clase base para el conjunto de elementos primero y siguiente.
 * @author Erik Giron (200313492)
 *
 */
public class SymbolSet {
    
    private NoTerminal nt; /**No terminal*/    
    private HashSet<Terminal> t;/**Terminal*/
    
    /** Crea una nueva instancia de SymbolSet */
    public SymbolSet() {        
        nt = new NoTerminal();
        t = new HashSet<Terminal>();
    }
    /***Constructor de oficio 1*/
    public SymbolSet(NoTerminal nts){
        nt = nts;
        t = new HashSet<Terminal>();
    }
    /***Constructor de oficio 2*/
    public SymbolSet(NoTerminal nts, SymbolSet ss1){
        nt = nts;
        t = ss1.getTerminales();
        
    }
    /**Comprueba existencia de terminal dentro del conjunto*/
    public boolean existeTerminal(Terminal pt){
        return t.contains(pt);
    }
    /**Inserta un terminal al conjunto de terminales*/
    public void insertarTerminal(Terminal pt) {
        t.add(pt);
    }
    /**Asigna no terminal*/
    public void setNT(NoTerminal ntActual) {
        throw new UnsupportedOperationException("Not yet implemented");
    }

    public HashSet<Terminal> getTerminales() {
        return this.t;
    }
    /**Une elementos terminales de un conjunto de simbolos en el actual*/
    public void union(SymbolSet primAnt) {
        this.t.addAll(primAnt.getTerminales());
    }
    /**Construye y devuelve todo el conjunto de caracteres Primero en un vector*/
    public Vector<Terminal>getSimbolos(){
        Vector<Terminal> ret = new Vector<Terminal>();
        Iterator i = t.iterator();
        while(i.hasNext()){
            ret.add((Terminal)i.next());
        }
        return ret;
    }
}
