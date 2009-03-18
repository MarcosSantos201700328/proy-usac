/*
 * EstadoLR0.java
 *
 * Creada el 14 de febrero de 2007, 07:00 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package lalrgen;

import java.util.*;

/**
 * Representa un estado LR0 del conjunto de estados LR0 necesarios para generar las 
 * acciones y los lookaheads
 * @author Erik Giron (200313492)
 *
 */
public class EstadoLR0 {
    private int id_estado;//Numero de estado
    private HashSet<ElementoLR0> kernel;/**Nucleos*/
    private HashSet<ElementoLR0> closure;/**Cerraduras*/
    
    private Gramatica g;
    
    /** Devuelve el numero del estado actual.*/
    public int getNumero(){
        return id_estado;
    }
    
    /** Crea una nueva instancia de EstadoLR0 */
    public EstadoLR0() {   
        id_estado = 0;
        kernel = new HashSet<ElementoLR0>();
        closure = new HashSet<ElementoLR0>();
    }
    
    /** Crea una nueva instancia de EstadoLR0 con estado state*/
    public EstadoLR0(int state) {   
        id_estado = state;
        kernel = new HashSet<ElementoLR0>();
        closure = new HashSet<ElementoLR0>();
    }
    
    /** Crea una nueva instancia de EstadoLR0 con estado state y kernel k*/
    public EstadoLR0(int state, ElementoLR0 k) {   
        id_estado = state;
        kernel = new HashSet<ElementoLR0>();
        kernel.add(k);
        closure = new HashSet<ElementoLR0>();
    }    

    /** Crea una nueva instancia de EstadoLR0 con estado state y kernel k*/
    public EstadoLR0(int state, HashSet<ElementoLR0> k) {   
        id_estado = state;
        kernel = new HashSet<ElementoLR0>();
        kernel.addAll(k);
        closure = new HashSet<ElementoLR0>();
    }    
    /**Devuelve elementos cerradura del Estado*/
    public HashSet<ElementoLR0> getCerradura(){
        return closure;
    }
    
    /**Devuelve elementos cerradura del Estado*/
    public HashSet<ElementoLR0> getNucleos(){
        return kernel;
    }
    
    /**Devuelve tanto elementos nucleares como cerraduras del estado*/
    public HashSet<ElementoLR0> getElementos(){
        HashSet<ElementoLR0> fusion = new HashSet<ElementoLR0>();
        fusion.addAll(kernel);
        fusion.addAll(closure);
        return fusion;
    }
    
    /**Agregamos elementos al estado*/
    public void agregarElementos(HashSet<ElementoLR0> elm){
        if(elm != null){
            HashSet<ElementoLR0> tmp = ConjuntoLR0.unionElementosLR0(closure,elm);
            closure = tmp;
        }
    }
    
    /**Devuelve, si existe, elemento nuclear con las mismas
     * caracteristicas que el dado en el parametro*/
    public ElementoLR0 getNucleo(ElementoLR0 nucleoActual) {
        Iterator i = this.kernel.iterator();
        ElementoLR0 eactual = null;
        while(i.hasNext()){
            eactual = (ElementoLR0)i.next();
            if(nucleoActual.equals(eactual))
                return eactual;
        }
        return null;
    }
    
    /**Inserta un nuevo nucleo en el estado*/
    public void insertarNucleo(ElementoLR0 nucleoActual) {
        this.kernel.add(nucleoActual);
    }
    
    /**Devuelve nucleos que intersectan*/
    public HashSet<ElementoLR0> getNucleos(HashSet<ElementoLR0> nucleoActual) {
        HashSet<ElementoLR0> kernelCopy = new HashSet<ElementoLR0>();
        kernelCopy.addAll(kernel);
        kernelCopy.retainAll(nucleoActual);
        return kernelCopy;
    }
    
    /**Inserta conjunto de nucleos en el estado*/
    public void insertarNucleos(HashSet<ElementoLR0> nucleoActual) {
        this.kernel = nucleoActual;
    }
    
    /**Compara nucleos entre este estado y el nucleo dado como parametro*/
    boolean nucleosIguales(HashSet<ElementoLR0> pkernel) {
        ElementoLR0 elemKernelParam;
        boolean iguales;
        Iterator<ElementoLR0> j;
        if(this.kernel.size() == pkernel.size()){
            j = pkernel.iterator();
            iguales = true;
            //Comparamos los nucleos
            while(j.hasNext()){
                elemKernelParam = (ElementoLR0) j.next();
                //Si no son iguales, nos salimos
                if (this.getNucleo(elemKernelParam) == null){                                                
                    return false;
                }
            }
            return true;
        }
        return false;
        
    }
    
    /**Compara lookaheads entre nucleos*/
    boolean LookAheadsIguales(HashSet<ElementoLR0> nucleoActual) {
        Iterator i = nucleoActual.iterator();
        ElementoLR0 kactual,nactual;
        while(i.hasNext()){
            nactual = (ElementoLR0) i.next();
            kactual = this.getNucleo(nactual);
            /**Si no se encontro nucleo igual, salimos */
            if(kactual == null){
                return false;
            }
            if(!kactual.getLookAheads().containsAll(nactual.getLookAheads())){
                return false;
            }
        }
        return true;
    }
    
    /**Fusiona lookaheads entre nucleos*/
    void fusionarNucleos(HashSet<ElementoLR0> nucleoActual) {
        Iterator i = nucleoActual.iterator();
        ElementoLR0 kactual,nactual;
        while(i.hasNext()){
            nactual = (ElementoLR0) i.next();
            kactual = this.getNucleo(nactual);
            //if(kactual == null){
            //    this.insertarNucleo(nactual);
            // }
            if(kactual != null){ 
                if(!kactual.getLookAheads().containsAll(nactual.getLookAheads())){
                    kactual.getLookAheads().addAll(nactual.getLookAheads());
                }
            }
        }
    }
    
    public String toString(){
        String ret = new String("S" + this.id_estado + " {\n");
        Iterator i = this.kernel.iterator();
        ElementoLR0 actual;
        while(i.hasNext()){
            actual = (ElementoLR0) i.next();
            ret += "\t" + (actual.toString());
            ret += ("\n");
        }
        ret += ("}\n");
        return ret;
    }
    
    
}
