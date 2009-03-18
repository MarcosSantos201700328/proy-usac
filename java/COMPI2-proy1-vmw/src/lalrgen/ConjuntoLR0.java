/*
 * ConjuntoLR0.java
 *
 * Creada el 5 de marzo de 2007, 04:10 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package lalrgen;
import java.util.*;
/**
 * Representa un conjunto de estados LR0, Incluye funciones para la creacion y
 * manipulacion de estos.
 * @author Erik Giron (200313492)
 *
 */
public class ConjuntoLR0 {
    
    private HashMap<Integer,EstadoLR0> estados;/**Conjunto de estados*/
    private HashMap<String,SymbolSet> first;/**Conjunto Primero sobre el que se trabajara*/
    
    
    private Gramatica g;/**Gramatica asociada al conjunto de estados*/
    /** Crea una nueva instancia de ConjuntoLR0 */
    private HashMap<String,Terminal> listaT;/**Listado de Terminales*/
    private HashMap<String,NoTerminal> listaNT;/**Listado de no terminales     */    
    
    private HashMap<TuplaLR,AccionLR> tablaAcciones = new HashMap<TuplaLR,AccionLR>();/**Representacion de la tabla de accion*/
    private HashMap<TuplaLR,GoToLR> tablaGoto = new HashMap<TuplaLR,GoToLR>();/**Representacion de la tabla de goto*/
    
    private int stateCount = 0;/**Contador de estados*/

    public HashMap<TuplaLR, AccionLR> getTablaAcciones(){
        return this.tablaAcciones;
    }
    
    public ConjuntoLR0() {
        estados = new HashMap<Integer,EstadoLR0>();
    }
    /**Construye un nuevo conjunto desde la gramatica pg*/
    public ConjuntoLR0(Gramatica pg) {
        estados = new HashMap<Integer,EstadoLR0>();
        g = pg;
    }
    /**Construye un nuevo conjunto desde la gramatica pg, con terminales lt y no terminales lnt*/
    public ConjuntoLR0(Gramatica pg,HashMap<String,Terminal> lt, HashMap<String,NoTerminal>lnt) {
        estados = new HashMap<Integer,EstadoLR0>();
        g = pg;
        listaT = lt;
        listaNT = lnt;
    }
    
    /**Asigna conjunto primero a utilizar*/
    public void setFirst(HashMap<String,SymbolSet> fs){
        this.first = fs;
    }
    /**Devuelve la gramatica asociada*/
    public Gramatica getGramatica(){
        return g;
    }
    /**Devuelve el conjunto de estados LR0*/
    public HashMap<Integer,EstadoLR0> getEstados(){
        return estados;
    }
    /**Algoritmo de generacion de estados LALR*/
    private int generarEstados(HashSet<ElementoLR0> nucleoActual,int nEstado){
        HashSet<ElementoLR0> eln;
        EstadoLR0 e1;
        HashSet<ElementoLR0> kern;
        if(estados.get(nEstado) == null){ /** si no existe el estado*/
            /*Vamos a crear el estado 0 si es el caso*/
            if (nEstado == 0){
                nucleoActual = crearNucleoInicial(g.getProduccion(0)); /**Creamos su nucleo*/            
            }
            /**Realizamos cerradura del kernel y calculamos sus LookAheads*/
            eln = cerradura(nucleoActual);
            /**Creamos estado e insertamos nucleos y no nucleos*/
            e1 = crearEstado(nucleoActual,nEstado);
            e1.agregarElementos(eln);
            /**Generamos acciones del estado actual*/
            return generarAcciones(e1);
        }
        else{ /**Si el estado ya existia*/
            e1 = estados.get(nEstado);/// Obtenemos el estado
            if(e1.LookAheadsIguales(nucleoActual) == false){// Si los lookaheads son diferentes
                // Fusionamos lookaheads
                e1.fusionarNucleos(nucleoActual); 
                /**Realizamos cerradura del kernel y calculamos de nuevo sus LookAheads*/
                eln = cerradura(e1.getNucleos());
                e1.agregarElementos(eln);
                /**Generamos acciones del estado actual*/
                return generarAcciones(e1);
            }
            else
                return nEstado;
        }
    }
    
    /* Actualizamos elementos del estado actual, simplemente llamando a generarEstados();*/
    private int actualizarEstado(HashSet<ElementoLR0> nucleoActual,int nEstado){
        return generarEstados(nucleoActual,nEstado);
    }

    /**Genera acciones respecto un estado dado, y se desplaza entre estados*/
    private int generarAcciones(EstadoLR0 e1) {
        int nEstado = e1.getNumero();
        HashSet<ElementoLR0> e1elem = e1.getElementos();
        HashSet<ElementoLR0> lelemdesp;
        
        HashMap<String,HashSet<ElementoLR0>> desplazables
                = new HashMap<String,HashSet<ElementoLR0>>(); //lista de elementos desplazables
        ArrayList<Simbolo> simbolosDesplazables = new ArrayList<Simbolo>(); //lista de simbolos a desplazar
        HashSet<ElementoLR0> reducibles
                = new HashSet<ElementoLR0>(); //lista de elementos reducibles        
        Iterator i = e1elem.iterator();        
        ElementoLR0 elemActual,elemNuevo;
        int eSiguiente,eNext = nEstado + 1;       
        Simbolo x;
        
        //rellenamos listado de elementos desplazables y reducibles
        while(i.hasNext()){
            elemActual = (ElementoLR0) i.next();            
            if(elemActual.canShift()){///Si logramos desplazar un caracter                {
                elemNuevo = new ElementoLR0(elemActual);///Creamos nuevo elemento copia
                x = elemNuevo.shift();/**Desplazamos un caracter*/
                //si no existe creamos listado y agregamos
                if(desplazables.get(x.getIdGram()) == null){
                    lelemdesp = new HashSet<ElementoLR0>();
                    lelemdesp.add(elemNuevo);
                    desplazables.put(x.getIdGram(),lelemdesp);
                    simbolosDesplazables.add((Simbolo)x);
                }
                else{/**sino solo actualizamos listado*/
                    lelemdesp = desplazables.get(x.getIdGram());
                    lelemdesp.add(elemNuevo);
                }
            }
            else{ // si no, son elementos reducibles
                reducibles.add(elemActual);
            }
        }
        
        //Recorremos listado de elementos reducibles
        i = reducibles.iterator();
        while(i.hasNext()){ //Agregamos reducciones pertinentes
            elemActual = (ElementoLR0) i.next();
            insertReduce(elemActual,nEstado);
        }
        
        //Recorremos listado de elementos desplazables
        i = simbolosDesplazables.iterator();
        while(i.hasNext()){
            x = (Simbolo) i.next();
            if(x.esTerminal()){
                if(((eSiguiente = getEstadoFromKernel(desplazables.get(x.getIdGram()))))!=-1){///Si existe estado con el mismo kernel
                    ///Agregamos accion de Desplazamiento y Actualizamos Estado existente
                    insertShift(x,nEstado,eSiguiente);
                    actualizarEstado(desplazables.get(x.getIdGram()),eSiguiente);
                }
                else{///Sino, creamos nuevo estado recursivamente
                    insertShift(x,nEstado,/*eNext*/estados.size());
                    eNext = generarEstados(desplazables.get(x.getIdGram()),/*eNext*/estados.size());
                }
            }
            else { ///Si se desplaza no terminal
                if(((eSiguiente = getEstadoFromKernel(desplazables.get(x.getIdGram()))))!=-1){///Si existe estado con el mismo kernel
                    ///Agregamos accion de Desplazamiento y Actualizamos Estado existente
                    insertGoto(x,nEstado,eSiguiente);
                    actualizarEstado(desplazables.get(x.getIdGram()),eSiguiente);
                }
                else{///Sino, creamos nuevo estado recursivamente
                    insertGoto(x,nEstado,/*eNext*/estados.size());
                    eNext = generarEstados(desplazables.get(x.getIdGram()),estados.size());
                }
            }
        }
        return eNext;
    }
    
    /**Punto de entrada para el calculo de estados LR0*/
    public void calcularEstados() {
        generarEstados(null,0);
        this.stateCount = this.estados.size();
    }
    
    /**Crea un nucleo desde el elemento LR0 actual*/
    private HashSet<ElementoLR0> crearNucleoInicial(Elemento elemento) {
        HashSet<ElementoLR0> ret = new HashSet<ElementoLR0>();
        ElementoLR0 e = new ElementoLR0(g.getProduccion(0));
        e.setPosPuntito(0);/**Asignamos posicion del puntito*/
        e.setNumProduccion(0);/**Asingamos numero de produccion*/
        e.insertLookAhead(Vacc.dolar);/**Insertamos dolar como LookAhead*/
        ret.add(e);
        return ret;
    }
    
    /**Calcula la cerradura de un conjunto de elementos @return Vector de elementos LR1*/
    private HashSet<ElementoLR0> cerradura(HashSet<ElementoLR0> nucleo) {
        ElementoLR0 actual;
        HashSet<ElementoLR0> n;
        HashSet<ElementoLR0> ret = new HashSet<ElementoLR0>();
        if(nucleo != null){
            Iterator i = nucleo.iterator();
            while(i.hasNext()){
                actual = (ElementoLR0) i.next();
                n = cerradura(actual, new HashSet<Integer>());
                ret = unionElementosLR0(ret,n);
            }
        }
        return ret;
    }
    /**Calcula la cerradura del elemento actual @return Vector de elementos LR1*/
    private HashSet<ElementoLR0> cerradura(ElementoLR0 eactual,HashSet<Integer> listaAgregados) {
        HashSet<ElementoLR0> ret = null, rt1;
        Simbolo sig = eactual.nextSimbolo();
        listaAgregados.add(eactual.getNumProduccion());/**Agregamos produccion a lista de agregados*/
        if(sig != null){
            /**Si el simbolo dado es no terminal, lo expandimos y
             * obtenemos listado de elementos lr1
             */
            if(sig.esNoTerminal()){
                ret = expandir(eactual);
                Iterator i = ret.iterator();
                ElementoLR0 elact;
                /**Recorremos todos los elementos que produjo la cerradura de expandir()
                 * y calculamos lookaheads
                 */
                while(i.hasNext()){
                    elact =  (ElementoLR0)i.next();
                    sig = elact.nextSimbolo();                    
                    if(sig.esNoTerminal()){/**Si es no terminal*/
                        updateLookAheads(elact,eactual);/**Actualizamos lookaheads lookaheads*/
                        //Si no ha sido agregado, hacermos cerradura sobre el elemento
                        if(!(listaAgregados.contains(elact.getNumProduccion()))){
                            rt1 = cerradura(elact,listaAgregados);/**Hacemos nueva cerradura*/
                            if (rt1!=null){
                                ret = unionElementosLR0(ret,rt1);
                                i = ret.iterator();/**Actualizamos iterador*/
                            }                            
                        }
                        //}
                    }
                    else{/**Si es terminal el simbolo del puntero, solo actualizamos sus lookaheads*/
                        updateLookAheads(elact,eactual);/**Actualizamos lookaheads solamente*/
                    }
                }
            }            
        }
        return ret;
    }
    
    /**Une conjuntos de elementos LR0*/
    public static HashSet<ElementoLR0> unionElementosLR0  (HashSet<ElementoLR0> e0,
            HashSet<ElementoLR0> e1){        
        if(e0== null){
            return e1;
        }
        if(e1 == null){
            return e0;
        }
        if(e0 == null && e1 == null){
            return new HashSet<ElementoLR0>();
        }
               
        HashSet<ElementoLR0> ret = new HashSet<ElementoLR0>();
        ElementoLR0 elemIActual = null, elemJActual = null;
        boolean existe = false;                
        Iterator j = e0.iterator(), i= e1.iterator();        

        /**Buscamos en e0 simbolos repetidos en e1 y los fusionamos
         luego, los simbolos en e1 a ret*/
        while(i.hasNext()){
            elemIActual =(ElementoLR0) i.next();  
            j = e0.iterator();
            while(j.hasNext()){
                elemJActual =(ElementoLR0) j.next();
                //try{
                if(elemJActual.equals(elemIActual)){
                    /**Fusionamos lookaheads*/
                    elemJActual.getLookAheads().addAll(elemIActual.getLookAheads());
                }
                //}
                //catch(Exception e){
                //    System.out.println(e);
                //}
                 
            }
            ret.add(elemIActual);
        }
        
        j = e0.iterator(); i= e1.iterator();        
        /**Buscamos en e1 simbolos unicos, y losa gregamos a ret*/
        while(i.hasNext()){
            elemIActual =(ElementoLR0) i.next();        
            existe = false;
            j = e0.iterator();
            while(j.hasNext()){
                elemJActual =(ElementoLR0) j.next();
                if(elemJActual.equals(elemIActual)){
                    /**Fusionamos lookaheads*/                    
                    existe = true;
                    break;
                }
            }
            if(!existe && elemJActual!= null)
                ret.add(elemJActual);
        }
        return ret;
    }
    
    /**Encuentra las cerraduras SLR del elemento actual que apunta a un no terminal*/
    private HashSet<ElementoLR0> expandir(ElementoLR0 eactual) {
        /**Obtenemos simbolo que continua al puntito*/
        HashSet<ElementoLR0> ret = new HashSet<ElementoLR0>();
        ElementoLR0 newelr0;
        Simbolo sig = eactual.nextSimbolo();
        /**Iteramos sobre la gramatica para obtener todos aquellos
         * elementos que coincidan en el lado izquierdo con el simbolo actual
         */
        Iterator i = g.getProducciones().iterator();
        Elemento egact;
        while(i.hasNext()){
            egact = (Elemento)i.next();
            if(egact.getLi().getIdGram().equals(sig.getIdGram())){
                newelr0 = new ElementoLR0(egact);
                ret.add(newelr0);
            }
        }
        return ret;
    }
    /**Funcion de generacion de lookaheas sobre el elemento etarget, usando*/
    private void updateLookAheads(ElementoLR0 etarget, ElementoLR0 eant) {
        Simbolo s = eant.getSimbolo(eant.getPosPuntito() + 1);
        //Terminal s = (Terminal) eant.getSimbolo(eant.getPosPuntito() + 1);
        SymbolSet firstterm;
        /**Si existe simbolo A tal que s -> s.bA y A no es nulo*/
        if(s != null){                  
            if(s.esNoTerminal()){                
                firstterm = first.get(s.getIdGram());
                etarget.insertLookAhead(eant.getLookAheads()); /**Insertamos lookaheads anteriores*/
                /**Si existe no temrminal que tenga en su conjunto primero Epsilon
                 * insertamos todos los lookaheads del elemento anterior y los unimos
                 * con el conjunto primero del simbolo s excepto Epsilon
                 */            
                if(firstterm.existeTerminal(Vacc.epsilon)){
                    etarget.insertLookAhead(firstterm.getTerminales()); /**Insertamos LA del conjunto primero*/
                    etarget.getLookAheads().remove(Vacc.epsilon);/**Quitamos epsilon*/
                }
            }   
            /**Si es terminal, insertamos solamente el mismo terminal*/
            else if(s.esTerminal()){
                etarget.insertLookAhead(listaT.get(s.getIdGram())); /**Insertamos LA del conjunto primero*/
            }
        }
        else{ /** Si S -> .B{epsilon}, solamente agregamos lookaheads del elemento anterior*/
            etarget.insertLookAhead(eant.getLookAheads()); /**Insertamos lookaheads anteriores*/
        }
    }
    /**Inserta los lookaheads de un elemento a otro*/
    private void copyLookAheads(ElementoLR0 to, ElementoLR0 from) {
        to.insertLookAhead(from.getLookAheads());
    }
    
    /**Devuelve un nuevo estado LALR con el nucleo dado y su numero*/
    private EstadoLR0 crearEstado(HashSet<ElementoLR0> nucleoActual, int nEstado) {
        EstadoLR0 ret = new EstadoLR0(nEstado,nucleoActual);
        estados.put(nEstado,ret);
        return ret;
    }
    
//    /**Devuelve un nuevo estado LALR con el nucleo dado y su numero*/
//    private EstadoLR0 crearEstado(ElementoLR0 nucleoActual, int nEstado) {
//        EstadoLR0 ret = new EstadoLR0(nEstado,nucleoActual);
//        estados.put(nEstado,ret);
//        return ret;
//    }
    /**Busca y devuelve numero de estado siguiente en la tabla de acciones,
     * Si tupla no existe, devuelve -1
     */
    private int getEstadoFromAccion(Simbolo x, int nEstado) {
        TuplaLR clave = new TuplaLR(nEstado,x);
        AccionLR get = this.tablaAcciones.get(clave);
        if(get != null)
            return get.getDesplazaA();
        else
            return -1;
    }

     /**Busca y devuelve numero de estado siguiente en la tabla de transiciones goto,
     * Si tupla no existe, devuelve -1
     */
    private int getEstadoFromGoto(Simbolo x, int nEstado) {
        TuplaLR clave = new TuplaLR(nEstado,x);
        GoToLR get = this.tablaGoto.get(clave);
        if(get != null)
            return get.getEstadoSiguiente();
        else
            return -1;
    }
    /**Agrega una nueva accion de desplazamiento a la tabla accion,
     * si el elemento ya existia, se agrega nuevo
     */
    private void insertShift(Simbolo x, int nEstado, int eSiguiente) {
        TuplaLR clave = new TuplaLR(nEstado,x);
        AccionLR get = this.tablaAcciones.get(clave);
        //Si no existe tupla, agregamos nuevo
        if (get == null){
            get = new AccionLR(nEstado,x,eSiguiente,true);
            tablaAcciones.put(clave,get);
        }
        else{//sino solo actualizamos
            get.setDesplazaA(eSiguiente);
        }
    }

    private void insertGoto(Simbolo x, int nEstado, int eSiguiente) {
        TuplaLR clave = new TuplaLR(nEstado,x);
        GoToLR get = this.tablaGoto.get(clave);
        TuplaLR clave2 = new TuplaLR(nEstado,x);
        boolean s = clave.equals(clave2);
        s = tablaGoto.containsKey(clave);
        //Si no existe tupla, agregamos nuevo
        if (get == null){
            get = new GoToLR(nEstado,x,eSiguiente);
            tablaGoto.put(clave,get);
        }
        else{//sino solo actualizamos
            get.setEstadoSiguiente(eSiguiente);
        }    
    }
    /**Inserta una accion de reducir por la produccion
     * para cada lookahead del elemento actual
      en el estado nEstado de la tabla Accion*/
    private void insertReduce(ElementoLR0 elemActual, int nEstado) {
        //TODO: Hacer un iterador para cada simbolo
        Iterator i = elemActual.getLookAheads().iterator();
        Simbolo x;
        while(i.hasNext()){
            x = (Simbolo) i.next();
            TuplaLR clave = new TuplaLR(nEstado,x);
            AccionLR get = this.tablaAcciones.get(clave);
            //Si no existe tupla, agregamos nuevo
            if (get == null){
                get = new AccionLR(nEstado,x,elemActual.getNumProduccion(),false);
                tablaAcciones.put(clave,get);
            }
            else{//sino solo actualizamos
                // Si ya existe una reduccion, creamos un nuevo conflicto reduce/reduce
                if(get.getReducePor() != -1)
                    get.setReducePor2(elemActual.getNumProduccion());
                else // sino agregamos reduccion, sin importar que exista un desplazamiento
                    get.setReducePor(elemActual.getNumProduccion());
            }        
        }
    }
    /**Busca entre los estados, algun estado en el que su kernel sea igual
     * al kernel dado como parametro
     */
    private int getEstadoFromKernel(HashSet<ElementoLR0> kernel) {
        Iterator i, j;
        Collection<EstadoLR0> e = estados.values();
        ElementoLR0 elemKernelParam;
        i = e.iterator();
        j = kernel.iterator();
        EstadoLR0 eactual;
        //Iteramos en cada estado existene
        boolean iguales;
        while(i.hasNext()){
            eactual =(EstadoLR0) i.next();
            /*Devolvemos el estado con el kernel igual, si existe*/
            if(eactual.nucleosIguales(kernel) == true)
                return eactual.getNumero();
        }
        return -1;
    }
    /**Devuelve la tabla Goto*/
    public HashMap<TuplaLR, GoToLR> getTablaGoto() {
        return this.tablaGoto;
    }

    public String toString(){
        String ret = new String();
        
        ret += ("Gramatica:\n" + this.g.toString() + "\n");
        ret += ("Estados:\n");
        Iterator i = this.estados.keySet().iterator();
        int ns;
        while(i.hasNext()){
            ns = ((Integer)i.next()).intValue();
            ret += (estados.get(ns).toString() + "\n");
        }
        return ret;
    }
    /**Devuelve el numero de estados*/
    public int getNumEstados(){
        return estados.size();
    }
}
