/*
 * TuplaLR.java
 *
 * Creada el 7 de marzo de 2007, 06:52 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package lalrgen;

/**
 * Representa una celda de la tabla LR
 * @author Erik Giron (200313492)
 *
 */
public class TuplaLR implements java.io.Serializable{
    
    private int estadoActual;
    private Simbolo simboloActual;
    /** Crea una nueva instancia de TuplaLR */
    public TuplaLR() {
    }
    /**Construimos nueva tupla desde el estado e con el simbolo s*/
    public TuplaLR(int estado, Simbolo sim) {
        estadoActual = estado;
        simboloActual = sim;
    }
    /**Devuelve estado actual*/
    public int getEstadoActual(){
        return this.estadoActual;
    }
    /**Asigna estado actual*/
    public void setEstadoActual(int e){
        this.estadoActual = e;       
    }
    /**Devuelve simbolo actual*/
    public Simbolo getSimboloActual(){
        return this.simboloActual;
    }
    /**Asigna simbolo actual*/
    public void setSimboloActual(Simbolo s){
        this.simboloActual = s;
    }
    
    public boolean equals(Object o){        
        if(!o.getClass().equals(this.getClass()))
            return false;
        TuplaLR tmp = (TuplaLR)o;
        if(tmp.getEstadoActual() == this.getEstadoActual() &&
                tmp.getSimboloActual().getIdGram().equals(this.simboloActual.getIdGram())        )    
            return true;
        return false;
    }
    
    public int hashCode(){
        return estadoActual + simboloActual.getIdGram().charAt(0);
    }
    public String toString(){
        return new String("Estado:" + this.estadoActual + ", Simbolo:" + this.simboloActual + "\n");
    }
}
