/*
 * LRParser.java
 *
 * Creada el 12 de marzo de 2007, 09:41 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package lrparser;


import lalrgen.*;
import phparser.*;
import java.io.*;
import java.util.*;

/**
 * Clase que carga e interpreta un paquete que contiene una tabla LALR generada
 * previamente, utilizando un scanner que use la interfaz Scanner y que tenga implementada
 * la funcion next_token() que devuelva un token, para poder realizar un analisis
 * sintactico LR.
 * @author Erik Giron (200313492)
 *
 */
public class LRParser {
    
    private LALRFilePack paquete; 
    private Scanner lexer;
    
    private Stack<ElementoPila> pila = new Stack<ElementoPila>();
    
    private PhParser miParser = new PhParser();
    
    /**devuelve el paquete LALR abierto actualmente*/
    public LALRFilePack getPaquete() {
        return paquete;
    }
    
    
    
    public LRParser(){
        
    }
    
    /** Crea una nueva instancia de LRParser */
    public LRParser(Scanner s, String path, String filenamePaquete) {
        try{
            lexer = s;
            cargarPaquete(path + filenamePaquete);
            cargarPaqueteCodigo(path + filenamePaquete + ".cod");
            
        }
        catch(Exception e){
            System.out.println("Imposible leer paquete, verifique que exista paquete:" + e + "\n");
        }
    }
    
    /**Carga un paquete dado en el path*/
    public void cargarPaquete(String filenamePaquete) throws Exception {
        FileInputStream in = new FileInputStream(filenamePaquete + ".lalr");
        ObjectInputStream s = new ObjectInputStream(in);
        paquete = (LALRFilePack)s.readObject();    
    }
    
    /**Muestra la tabla LALR contenida en el paquete cargado*/
    public void verTablaLALR() throws Exception{
        if(paquete == null){
            throw new Exception("Imposible ver tabla, no se ha abierto ningun paquete aun.\n");            
        }
        else{
            TablaLRFrame tlr = new lrparser.TablaLRFrame(paquete);
            tlr.setVisible(true);
        }
    }
    
    
    /**Metodo para recorrer la tabla LALR en paquete y hacer el analisis sintactico usando
      el scanner dado.@return -2 si error lexico, -1 si hubo error sintactico, 0 si la lectura fue exitosa
     @throws Excepcion si no se ha cargado ningun paquete ni lexer*/
    public int parse() throws Exception{
        Token next;
        Simbolo x;
        AccionLR alr_actual;
        int s = 0, s1 = 0, r1 = -1 , ultimaReduccion = 0;
        if(lexer == null || paquete == null){
            throw new Exception("No se ha definido ningun scanner y/o paquete aun\n");
        }
        //next = lexer.next_token();
        ElementoPila ep0 = new ElementoPila(0,new Simbolo()), ep1; //definimos elemento inicial en la pila
        pila.push(ep0); //metemos en la pila el elemento inicial
        /**Ciclo infinito de parsing*/
        next = lexer.next_token(); // obtenemos siguiente token
        while(true){
            s = pila.peek().getNumEstado(); //revisamos estado actual
            //next = lexer.next_token(); // obtenemos siguiente token
            x = new Terminal(next.getToken(),next.getValor()); // creamos nuevo simbolo respecto token
            alr_actual = paquete.getAccion(s,x); //obtenemos accion;
            if(alr_actual == null){ // Si no existe accion actual para el terminal dado, quiere decir que hay error sintactico
                throw new Exception("Error de sintaxis, al leer caracter " + x.getIdGram() + " El caracter no va aqui\n");
                //return -1;
            }
            else{
                if(!alr_actual.existeConflicto()){ // si no existe accion de R/R o S/R, evaluamos sin aplicar reglas de precedencia
                    if((s1 = alr_actual.getDesplazaA()) > 0){ /**Si es accion de desplazamiento*/
                        ep1 = new ElementoPila(s1,x);
                        pila.push(ep1);
                        next = lexer.next_token(); // obtenemos siguiente token
                    }
                    else if((r1 = alr_actual.getReducePor() ) > 0){ // sino reducimos
                        s1 = reduce(r1); // obtenemos nuevo estado;
                        ultimaReduccion = r1; // asignamos reduccion actual como ultima reduccion hecha, esto se hace para poder aplicar reglas de asociatividad
                    }
                    else if((r1 = alr_actual.getReducePor() ) == 0){
                        return 0; // si es accion aceptar, nos salimos y retornamos valor correcto
                    }
                }
                else{ //aplicamos reglas de asociatividad
                    // si precedencia de la produccion actual de la pila es menor o igual que la del simbolo, desplazamos
                    if(prec(pila) <= prec(x)){
                        s1 = alr_actual.getDesplazaA();
                        ep1 = new ElementoPila(s1,x);
                        pila.push(ep1);
                        next = lexer.next_token(); // obtenemos siguiente token
                    }                    
                    else{ //sino reducimos
                        r1 = alr_actual.getReducePor();
                        if(r1 > 0){
                            s1 = reduce(r1); // obtenemos nuevo estado;
                            ultimaReduccion = r1; // asignamos reduccion actual como ultima reduccion hecha, esto se hace para poder aplicar reglas de asociatividad
                        }
                        else{ // si es simbolo de aceptacion, nos salimos
                            return 0;
                        }
                    }
                }
            }
            
        }
    }
    /**Realiza una reduccion por la produccion numero r1 en la pila y ejecuta la accion asociada a esta produccion*/
    private int reduce(int r1) throws Exception {
        //obtenemos tamano de produccion
        int r = paquete.getG().getProduccion(r1).getLd().getLongitud();
        ElementoPila ac;
        LinkedList<Simbolo> simbolosSacados = new LinkedList<Simbolo>();
        /**Sacamos 'r' elementos de la pila*/
        for(int i=0; i<r; i++){ 
            ac = (ElementoPila)pila.pop();
            simbolosSacados.addFirst(ac.getSimbolo());            
        }
        /**Ejecutamos accion semantica */
        NoTerminal A = ejecutarAccion(simbolosSacados, paquete.getG().getProduccion(r1));
        /**Obtenemos elemento de que esta actualmente en la cima de la pila*/
        ElementoPila cima = pila.peek();
        /**Obtenemos el lado izquierdo de la produccion por la que vamos a reducir*/       
        //NoTerminal A = paquete.getG().getProduccion(r1).getLi();
        /**Obtenemos estado siguiente segun la tabla goto*/
        int estadoNuevo = paquete.go_to(cima.getNumEstado(),A);
        /**Obtenemos nuevo elemento de la pila*/
        ElementoPila newElement = new ElementoPila(estadoNuevo,A);
        /**Los sambutimos a la pila*/
        pila.push(newElement);
        return estadoNuevo;
    }
    
//    /**Ejecuta accion semantica, not yet implemented*/
//    private void ejecutarAccion(String accion) {
//        System.out.println(accion);
//    }
//    /**Obtiene precedencia de la produccion dada*/
//    private int prec(int numProd) {
//        LadoDerecho actual = this.paquete.getG().getProduccion(numProd).getLd();
//        ListIterator i = actual.getSimbolos().listIterator();
//        int precedencia;
//        Simbolo sactual;
//        Terminal tget;
//        while(i.hasPrevious()){
//            sactual = (Simbolo) i.previous();
//            if (sactual.esTerminal()){
//                /**Obtenemos terminal*/
//                tget = paquete.getListaT().get(sactual.getIdGram());
//                return tget.getPrecedencia();
//            }
//        }
//        return 0;
//    }
    
      /**Obtiene precedencia de la produccion dada*/
    private int prec(Stack<ElementoPila> pPila) {
        Simbolo sactual;
        Terminal tget;
        if(pila!= null)
            if(pila.size() > 0){
                ListIterator i = pPila.listIterator(pPila.size() - 1);
                //recorremos la pila en busqueda del no terminal mas cercano
                while(i.hasPrevious()){
                    sactual = (Simbolo) ((ElementoPila)i.previous()).getSimbolo();
                    if (sactual.esTerminal()){
                        /**Obtenemos terminal*/
                        tget = paquete.getListaT().get(sactual.getIdGram());
                        return tget.getPrecedencia();
                    }
                }
                return 0;
            }
        return 0;
    }
    
    /**Obtiene precedencia de la pila*/
    
    
    /**Obtiene precedencia de un simbolo dado*/
    private int prec(Simbolo x) {
        Terminal tget;
        tget = paquete.getListaT().get(x.getIdGram());
        if(tget != null)
            return tget.getPrecedencia();
        return 0;
    }
    /**Ejecuta accion semantica de la produccion elemento, con el vector de simbolos simbolosSacados*/
    private NoTerminal ejecutarAccion(LinkedList<Simbolo> simbolosSacados, Elemento elemento) {
        Simbolo sactual2;
        SymTab st = PhParser.getTablaSimbolos();
        Iterator i = simbolosSacados.iterator(), j = elemento.getLd().getSimbolos().iterator();
        boolean insertado = false;
        Simbolo sactual;
        Terminal tActual;
        NoTerminal ntActual;
        NoTerminal nuevo = new NoTerminal(elemento.getLi());
        ///agregamos atributos a la tabla de simbolos
        while(i.hasNext() && j.hasNext()){
            sactual = (Simbolo) i.next();
            sactual2 = (Simbolo) j.next();
            if(sactual.esTerminal()){
                tActual = this.getPaquete().getListaT().get(sactual.getIdGram());
                if(sactual2.getSemId() != null && sactual2.getSemId().length() > 0){
                    st.insertarAtributo(sactual2.getSemId(),tActual.getTipo(),sactual.getValor());
                    insertado = true;
                }
            }
            else{
                ntActual = this.getPaquete().getListaNT().get(sactual.getIdGram());
                if(sactual2.getSemId() != null && sactual2.getSemId().length() > 0){
                    st.insertarAtributo(sactual2.getSemId(),ntActual.getTipo(),sactual.getValor());
                    insertado = true;
                }
            }
        }
        /*si se inserto por lo menos un atributo, ejecutamos*/
        if(insertado){
            st.insertarAtributo(nuevo.getSemId(),nuevo.getTipo(),nuevo.getValor());
            //Ejecutamos codigo
            try{
                miParser.ejecutar(new StringReader(elemento.getLd().getAccion()));
                //Asignamos atributo al simbolo dado
                Object valor = st.get("$" + nuevo.getSemId()).getValor();
                /**Si el objeto es un float, y nuestro tipo es integer, hacemos un downcasting*/
                //if(valor.getClass().equals(new Float().getClass()) && nuevo.getTipo() == 1)
                nuevo.setValor(valor);
                if(valor.getClass().equals(new Float(0).getClass())){
                    nuevo.setTipo(2);
                }
            }
            catch(Exception e){
                System.out.println(e);
            }
            //quitamos atributos de la tabla de simbolos
            i = elemento.getLd().getSimbolos().iterator();
            
            while(i.hasNext()){
                sactual = (Simbolo) i.next();
                if(sactual.getSemId() != null)
                    st.borrarEntrada(sactual.getSemId());
            }
            st.borrarEntrada("$" + nuevo.getSemId());
        }
        
        return nuevo;
    }
    
    /**Carga paquete de codigo fuente para alimentar la tabla de simbolos*/
    private void cargarPaqueteCodigo(String filename) {
       try{
           miParser.ejecutar(new FileReader(filename));
       }
       catch(Exception e){
           System.out.println(e);
       }
    }

}
