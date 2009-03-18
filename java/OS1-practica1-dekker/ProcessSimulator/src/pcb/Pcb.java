/*
 * Pcb.java
 *
 * Creada el August 17, 2007, 5:30 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package pcb;

/**
 * Estructura del PCB a usar
 * @author Erik Giron (200313492)
 *
 */

import java.util.*;
public class Pcb{
    
    int id = new Integer((int)(Math.random()) * 1000).intValue();
    String name = new String();
    float quantum = 1;
    float size = new Integer((int)(Math.random()) * 1000).intValue();

    public int getId() {
        return id;
    }

    public int hashCode(){
        return id;
    }
    
    Pcb(String name){
        this.name = name;
    }
    
    /** Crea una nueva instancia de Pcb */
    public Pcb() {
    }

    public String getName() {
        return name;
    }

    public float getQuantum() {
        return quantum;
    }

    public float getSize() {
        return size;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setQuantum(float quantum) {
        this.quantum = quantum;
    }

    public void setSize(float size) {
        this.size = size;
    }
}
