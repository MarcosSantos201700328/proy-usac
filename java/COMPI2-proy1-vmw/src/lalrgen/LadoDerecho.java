/*
 * LadoDerecho.java
 *
 * Creada el 13 de febrero de 2007, 09:18 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package lalrgen;
import java.util.*;
/**
 * Provee abstraccion al lado derecho de una gramatica libre de contexto
 * @author Erik Giron (200313492)
 *
 */
public class LadoDerecho implements java.util.Comparator, java.io.Serializable{
    
    private java.util.Vector<Simbolo> simbolos;/**Listado de simbolos que forman el lado derecho*/
    
    private String accion; /**Accion semantica*/

    /** Crea una nueva instancia de LadoDerecho */
    public LadoDerecho() {
        simbolos = new Vector<Simbolo>();
        //lookaheads = new Vector();
        //posPuntito = -1;      
    }
    
    public LadoDerecho(Vector<Simbolo> vSim, String paccion) {        
        if (vSim == null)/**Si el vector es null, entonces insertarmos un epsilon         */{
            simbolos = new Vector<Simbolo>();
            simbolos.add(Vacc.epsilon);
        }
        else/**si no agregamos listado*/
            simbolos = new Vector<Simbolo>(vSim);
            /*
        if (vSim != null)
            simbolos = new Vector<Simbolo>(vSim);
        else
            simbolos = null;
             */
        //posPuntito = -1;      
        this.accion = new String(paccion);
        //lookaheads = new Vector();
    }
    /**Asigna accion correspondiente al lado derecho de la produccion*/
    public void setAccion(String paccion){
        this.accion = new String(paccion);
    }
   /*TODO*/
    public int compare(Object o1, Object o2){
        /*if (o1 != null && o2 != null && o1.getClass() == this.getClass() && o2.getClass() == this.getClass()){
            if((LadoDerecho)o1
            
        }*/
        return -1;
    }
    /*TODO**/
    public boolean equals(Object o1){
        if(o1 != null && o1.getClass().equals(this.getClass())){
            if(((LadoDerecho)o1).getLongitud() == this.getLongitud() &&
                    //((LadoDerecho)o1).getPosPuntito() == this.posPuntito  &&                    
                    ((LadoDerecho)o1).getSimbolos().equals(this.simbolos)// &&
                    //((LadoDerecho)o1).getLookAheads().equals(this.lookaheads)
                    )
                    return true;
                else 
                    return false;
        }
        return false;
    }    
   
    /**Retorna la longitud de simbolos del lado derecho*/
    public int getLongitud(){
        return simbolos.size();
    }
   

    public Vector<Simbolo> getSimbolos() {
        return this.simbolos;
    }
    /**Asigna un vector de simbolos como un lado derecho de produccion*/
    public void setSimbolos(Vector<Simbolo> vls) {
        simbolos = vls;
    }

    /**Devuelve el simbolo con indice i*/
    Simbolo getSimbolo(int i) {
        Simbolo tmp;
        try{
            tmp = this.simbolos.get(i);
            return tmp;
        }
        catch(java.lang.ArrayIndexOutOfBoundsException a){
            return null;
        }
        
    }

    void insertarSimbolo(Simbolo se) {
        this.simbolos.add(se);
    }
    public String toString(){
        Iterator i = simbolos.iterator();
        String ret = new String("");
        while(i.hasNext()){
            ret += (i.next().toString());
            ret += (" ");
        }
        return ret;        
    }
    /**Devuelve la accion semantica de la traduccion dirigida por la sintaxis*/
    public String getAccion() {
        return this.accion;
    }
}
