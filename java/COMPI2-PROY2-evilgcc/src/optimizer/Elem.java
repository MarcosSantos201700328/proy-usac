/*
 * Elem.java
 *
 * Creada el May 29, 2007, 10:29 AM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package optimizer;

/**
 * Elemento basico de un cuadruplo
 * @author Erik Giron (200313492)
 *
 */
public class Elem {
 
    String id = new String();
    int tipo = -1;    
    
    public static final int E_LABEL = 100;
    public static final int E_GOTO = 101;
    public static final int E_SCALAR = 102;
    public static final int E_VECTOR = 103;
    public static final int E_PROC = 104;
    
    /** Crea una nueva instancia de Elem */
    public Elem() {
    }
    
    /** Crea una nueva instancia de Elem */
    public Elem(String i, int t){
        id = i;
        tipo = t;
    }
    // Constructor de Copia
    public Elem(Elem e){
        if(e != null){
            this.setId(new String(e.getId()));
            this.setTipo(e.getTipo());            
        }   
    }
    
 
    public void setTipo(int tipo) {
        this.tipo = tipo;
    }

    public int getTipo() {
        return tipo;
    }
    

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }
    
    public String toString(){
        if(this.id != null){
            return this.id;
        }
        return new String("");
    }
    
}
