/*
 * Gramatica.java
 *
 * Creada el 13 de febrero de 2007, 09:46 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package lalrgen;
import java.util.*;
/**
 * Representa una gramatica libre de contexto.
 * @author Erik Giron (200313492)
 *
 */
public class Gramatica implements java.io.Serializable {
    Vector<Elemento> producciones;/**Producciones gramaticales*/
    
    
    /** Crea una nueva instancia de Gramatica */
    public Gramatica() {
        producciones = new Vector<Elemento>();
        
    }
    
    /**Buscamos un elemento y devolvemos si existe*/
    public Elemento buscarElemento(Elemento e) {        
        if(e!=null && producciones != null){
            Iterator i = producciones.iterator();
            Elemento tmp;
            while(i.hasNext()){
                if (i.next().equals(e))
                    return (Elemento)i.next();                        
            }
        }
        return null;
    }
    /**Insertamos una produccion a nuestra gramatica*/
    void insertarElemento(Elemento e) {
        producciones.add(e);
    }
    /**Insertamos una produccion a nuestra gramatica*/
    public void insertarProduccion(Elemento e){
        insertarElemento(e);
    }
    
    public void insertarProducciones(Vector<Elemento> vp){
        this.producciones.addAll(vp);
    }
    
    /**Devolvemos la produccion especificada por el indice dado*/
    public Elemento getProduccion(int np) {
        return this.producciones.get(np);
    }
//    /**Punto de entrada para calcular conjunto primero*/
//    private void calcularPrimero(){
//        
//    }
//    
    /**Genera conjunto primero para cada no terminal*/
//    
//    public SymbolSet first(NoTerminal nt){
//        Iterator i,j;
//        SymbolSet tmpss = null, primAnt = null;
//        i = producciones.iterator();
//        while(i.hasNext()){
//            if(first.get(nt) != null)
//                return null;        /**Si ya existe primero del simbolo retornamos*/
//            else{
//                tmpss = new SymbolSet(nt);                
//            }
//            /**Recorremos cada simbolo del lado derecho de la gramatica*/
//            j = ((Elemento)i.next()).getLd().getSimbolos().iterator();
//            while(j.hasNext()){
//                /**Si es no terminal y estamos al inicio de la iteracion 
//                 * o si primero calculado anteriormente contiene algun cadena vacia epsilon
//                 * creamos recursivamente primero para el conjunto dado*/
//                if(((((NoTerminal)j.next()).getClass() == nt.getClass()) && primAnt == null) 
//                || ((((NoTerminal)j.next()).getClass() == nt.getClass()) && primAnt.existeTerminal(Terminal.epsilon)) ){                    
//                    primAnt = first((NoTerminal)j.next());
//                }
//                else{/**Si es terminal lo insertamos y nos salimos del ciclo*/
//                    tmpss.insertarTerminal((Terminal)j.next());
//                    return tmpss;
//                }
//            }
//            
//        }
//        return tmpss;
//    }
    
    
//    
//    public SymbolSet first(NoTerminal nt, HashSet<NoTerminal> listaAgregados){
//        
//        Iterator i,j;
//        SymbolSet newSymbolSet;
//        Elemento eactual;
//        NoTerminal ntActual;
//        HashSet<NoTerminal> la;
//        Vector vecLD;
//        /**Paso inicial: Iteramos por todas las producciones obteniendo cada LI*/
//        if(nt == null){            
//            i = this.producciones.iterator();
//            la = new HashSet<NoTerminal>();
//            /**Para cada produccion de la gramatica, sacamos primero del NT a la izquierda*/
//            while(i.hasNext()){
//                /**Creamos un conjunto primero para cada NT del lado izquierdo 
//                 * de la produccion actual para el cual no exista conjunto todavia
//                 * y calculamos su conjunto primero*/                
//                ntActual = ((Elemento)i.next()).getLi();
//                if (first.get(ntActual)==null){/**Si no existe */
//                    la.add(ntActual);/**Agregamos a listaAgregados*/
//                    newSymbolSet = first(ntActual,la)/*Calculamos primero del elemento en cuestion*/;
//                    first.put(ntActual,newSymbolSet);                    
//                }                    
//            }
//        }
//        /**pasos posteriores: Calculamos primero el no terminal dado como parametro*/
//        else{
//            i = this.producciones.iterator();            
//            /**Recorremos las producciones en busqueda del NT dado en el parametro*/
//            while(i.hasNext()){
//                ntActual = ((Elemento)i.next()).getLi();
//                vecLD = ((Elemento)i.next()).getLd().getSimbolos();
//                j = vecLD.iterator();                
//                
//                if(ntActual == nt){
//                    /**Revisamos si el no terminal dado en LD no se encuentre en lista de agregados 
//                    * y que no sea el mismo que fue dado en el parametro para evitar bucles infinitos*/
//                    /**Si el no terminal actual es igual que el primer elemento del lado derecho*/
//                    if(ntActual.equals((NoTerminal) vecLD.get(0)))
//                        return first.get((NoTerminal) vecLD.get(0));
//                    /**Si el lado derecho no contiene no terminal agregado*/
//                    else if(!(listaAgregados.contains((NoTerminal) vecLD.get(0)))){
//                        /**Recorremos los no terminales*/
//                        
//                    //    if(!vecLD.get(0).getClass().equals(nt.getClass()))
//                                                
//                    }
//                    //if(listaAgregados.contains(ntActual)))
//                }
//            }
//        }
//    }

    public Vector<Elemento> getProducciones() {
        return this.producciones;
    }
    
    public String toString(){
        Iterator i = this.producciones.iterator();
        String ret = new String("");
        while (i.hasNext()){
            ret += (i.next().toString() + "\n");
        }
        return ret;
    }
    /**Amplia la gramatica agregando produccion inicial*/
    public void ampliar(){
        /*Seleccionamos no terminal del lado izquierdo*/
        NoTerminal li = new NoTerminal(this.producciones.get(0).getLi());
        li.setSemId("");
        
        /**Creamos nuevo lado derecho con nuestro terminal*/
        LadoDerecho ld = new LadoDerecho();
        ld.insertarSimbolo(li);
        /*Creamos la produccion con simbolo especial Start como lado izquierdo*/
        Elemento newelem = new Elemento(Vacc.start, ld, "");
        /*insertamos produccion en gramatica al inicio*/
        Vector<Elemento> newProducciones = new Vector<Elemento>();
        newProducciones.add(newelem);
        /*Mudamos las producciones del vector viejo al nuvo*/
        Iterator i = producciones.iterator();        
        while (i.hasNext()){
            newProducciones.addElement((Elemento)i.next());
        }
        /*Asignamos nuevo vector de elementos*/
        this.producciones = newProducciones;
    }
    /**Asigna indices a cada produccion en la gramatica, desde 0 hasta el total de producciones*/
    public void asignarIndicesProduccion() {
        Iterator i = producciones.iterator();
        int k = 0;
        Elemento actual;
        while(i.hasNext()){            
            actual = (Elemento) i.next();
            actual.setNumProduccion(k);
            k++;
        }
        
    }
}
