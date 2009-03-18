/*
 * LALRFilePack.java
 *
 * Creada el 9 de marzo de 2007, 08:07 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package lalrgen;
import java.util.*;
/**
 * Clase que sirve como contenedor de los datos necesarios para serializar
 * una tabla LALR dada.
 * @author Erik Giron (200313492)
 *
 */
public class LALRFilePack implements java.io.Serializable{
    private Gramatica g;/**Gramatica asociada al conjunto de estados*/
    /** Crea una nueva instancia de ConjuntoLR0 */
    private HashMap<String,Terminal> listaT;/**Listado de Terminales*/
    private HashMap<String,NoTerminal> listaNT;/**Listado de no terminales     */    
    
    private HashMap<TuplaLR,AccionLR> tablaAcciones = new HashMap<TuplaLR,AccionLR>();/**Representacion de la tabla de accion*/
    private HashMap<TuplaLR,GoToLR> tablaGoto = new HashMap<TuplaLR,GoToLR>();/**Representacion de la tabla de goto*/
    
    private int numEstados; 
    
    /** Crea una nueva instancia de LALRFilePack */
    public LALRFilePack() {
    }
    

    public Gramatica getG() {
        return g;
    }

    public void setG(Gramatica g) {
        this.g = g;
    }

    public HashMap<String, NoTerminal> getListaNT() {
        return listaNT;
    }

    public void setListaNT(HashMap<String, NoTerminal> listaNT) {
        this.listaNT = listaNT;
    }

    public HashMap<String, Terminal> getListaT() {
        return listaT;
    }

    public void setListaT(HashMap<String, Terminal> listaT) {
        this.listaT = listaT;
    }

    public HashMap<TuplaLR, AccionLR> getTablaAcciones() {
        return tablaAcciones;
    }

    public void setTablaAcciones(HashMap<TuplaLR, AccionLR> tablaAcciones) {
        this.tablaAcciones = tablaAcciones;
    }

    public void setTablaGoto(HashMap<TuplaLR, GoToLR> tablaGoto) {
        this.tablaGoto = tablaGoto;
    }

    public HashMap<TuplaLR, GoToLR> getTablaGoto() {
        return tablaGoto;
    }
    /**Devuelve la cantidad de estados generada*/
    public int getNumEstados() {
        return numEstados;
    }
    
    /**Asigna la cantidad de estados*/
    public void setNumEstados(int numEstados) {
        this.numEstados = numEstados;
    }

    public AccionLR getAccion(int s, Simbolo x) {
        TuplaLR t = new TuplaLR(s,x);
        return this.tablaAcciones.get(t);
    }
    
    /**Obtiene el estado siguiente segun la tabla goto*/
    public int go_to(int i, NoTerminal A) {
        TuplaLR index = new TuplaLR(i, (Simbolo) A);
        GoToLR g = (GoToLR) this.getTablaGoto().get(index);
        return g.getEstadoSiguiente();
    }
    public String toString(){
        String ret = new String();
        
        ret += "Contenido del paquete:\n\n";
        ret += "Terminales: \n";
        Iterator i = this.listaT.values().iterator();
        //Imprimimos terminales
        Terminal tact;
        while(i.hasNext()){
            tact = (Terminal)i.next();
            ret += "\t" + tact.toString() + "\n";            
        }
        //Imprimimos no terminales
        ret += "\nNo Terminales: \n";
        i = this.listaNT.values().iterator();
        NoTerminal ntact;
        while(i.hasNext()){
            ntact = (NoTerminal)i.next();
            ret += "\t" + ntact.toString() + "\n";            
        }
        //Imprimimos gramatica
        ret +="\nGramatica:\n" + this.g.toString();
        
        TuplaLR tlrActual;
        //Imprimimos tabla de acciones
        i = this.tablaAcciones.keySet().iterator();
        AccionLR accActual;
        ret +="\nTabla Accion:\n";
        while(i.hasNext()){            
            tlrActual = (TuplaLR) i.next();
            accActual = this.tablaAcciones.get(tlrActual);
            ret += "\t Con " + tlrActual.toString() + "\t(" + accActual.toString() + ")\n";
        }
        //Imprimimos tabla de goto
        i = this.tablaGoto.keySet().iterator();
        GoToLR gtlrActual;
        ret +="\nTabla Accion:\n";
        while(i.hasNext()){            
            tlrActual = (TuplaLR) i.next();
            gtlrActual = this.tablaGoto.get(tlrActual);
            ret += "\t con:" + tlrActual.toString() +"\t nos movemos a:" + gtlrActual.toString() + "\n";
        }
        return ret;
    }
        
}
