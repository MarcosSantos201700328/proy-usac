/*
 * GoToLR.java
 *
 * Creada el 7 de marzo de 2007, 07:25 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package lalrgen;

/**
 * Clase derivada de TuplaLr que representa una transicion de estados en la tabla goto[]
 * de los analizadores LR
 * @author Erik Giron (200313492)
 *
 */
public class GoToLR extends TuplaLR implements java.io.Serializable{
    private int estadoSiguiente = -1;
    /** Crea una nueva instancia de GoToLR */
    public GoToLR() {
    }
    /** Constructor de oficio*/
    public GoToLR(int estado, Simbolo sim,int eSiguiente) {
        super(estado,sim);
        estadoSiguiente = eSiguiente;
    }
    

    public int getEstadoSiguiente() {
        return estadoSiguiente;
    }

    public void setEstadoSiguiente(int estadoSiguiente) {
        this.estadoSiguiente = estadoSiguiente;
    }
    
    public boolean equals(Object o){
        if(!o.getClass().equals(this.getClass()))
            return false;
        GoToLR tmp = (GoToLR)o;
        if(tmp.getEstadoActual() == this.getEstadoActual() &&
                tmp.getSimboloActual().getIdGram().equals(this.getSimboloActual().getIdGram()) &&
                tmp.getEstadoSiguiente() == this.estadoSiguiente)    
            return true;
        return false;
    }
    public String toString(){
        return new String().valueOf(this.estadoSiguiente);
    }
}
