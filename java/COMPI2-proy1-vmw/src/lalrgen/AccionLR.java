/*
 * AccionLR.java
 *
 * Creada el 7 de marzo de 2007, 07:01 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package lalrgen;

/**
 * Clase derivada de TuplaLr que representa una accion en la tabla accion[]
 * de los analizadores LR
 * @author Erik Giron (200313492)
 *
 */
public class AccionLR extends TuplaLR implements java.io.Serializable {
    private int reducePor = -1;// Entero que representa por que produccion se va a reducir
    private int reducePor2 = -1;// Entero que representa por que produccion se va a reducir, cuando hay reduccion/reduccion
    private int desplazaA = -1;// Entero que representa a que estado se va a desplazar
    private boolean aceptar = false; //Especifica si la accion es aceptar
    /** Crea una nueva instancia de AccionLR */
    public AccionLR() {
    }
    /**Constructor de oficio*/
    public AccionLR(int estado, Simbolo sim,int reducirPor,int desplazarA) {
        super(estado,sim);
        reducePor = reducirPor;
        desplazaA = desplazarA;
    }

    public int getReducePor2() {
        return reducePor2;
    }
    
    /**Si desplazar es true, crea accion desplazar, sino crea accion reducir
     @param accion Si corresponde a reducir, indica la produccion por la que se hara
      Si corresponde a desplazar, corresponde al siguiente estado*/
    public AccionLR(int estado, Simbolo sim,int accion, boolean desplazar) {
        super(estado,sim);
        if(desplazar)
            desplazaA = accion;
        else
            reducePor = accion;
    }
    /**Retorna verdadero si es una tupla vacia*/
    public boolean esError(){
        if(reducePor == -1 && desplazaA == -1){
            return true;
        }
        return false;
    }
    
    /**Retorna verdadero si existe conflicto de Shift/Reduce*/
    public boolean existeConflicto(){
        if(reducePor > -1 && desplazaA > -1){
            return true;
        }
        return false;
    }
    public int getDesplazaA() {
        return desplazaA;
    }

    public int getReducePor() {
        return reducePor;
    }

    public void setDesplazaA(int desplazaA) {
        this.desplazaA = desplazaA;
    }

    public void setReducePor(int reducePor) {
        this.reducePor = reducePor;
    }
    
    public boolean equals(Object o){        
        if(!o.getClass().equals(this.getClass()))
            return false;
        AccionLR tmp = (AccionLR)o;
        if(tmp.getEstadoActual() == this.getEstadoActual() &&
                tmp.getSimboloActual().getIdGram().equals(this.getSimboloActual().getIdGram())
                /* &&
                tmp.reducePor == this.reducePor &&
                tmp.reducePor2 == this.reducePor2 &&
                tmp.desplazaA == this.desplazaA*/ )    
            return true;
        return false;
    }

    public void setReducePor2(int reducePor2) {
        this.reducePor2 = reducePor2;
    }
    public String toString(){
        String ret = new String();
        if(desplazaA != -1 && reducePor != -1){
            ret += ("S" + this.desplazaA + "/R" + this.reducePor);
            return ret;
        }
        else{
            if(reducePor == 0){
                ret += ("aceptar");
                return ret;
            }
            if(desplazaA != -1){
                ret += ("S" + this.desplazaA);
                return ret;
            }
            if(reducePor != -1){
                ret += ("R" + this.reducePor);
                return ret;
            }
        }
        ret += ("e");
        return ret;
    }
}
