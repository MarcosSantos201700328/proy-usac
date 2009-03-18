/*
 * Vacc.java
 *
 * Creada el 14 de febrero de 2007, 06:45 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package lalrgen;
import java.util.*;
import java.io.*;
import java_cup.runtime.*;
/**
 * Clase principal para el generador de analizadores sintacticos, contiene todos
 * los metodos utiles para su utilizacion
 * @author Erik Giron (200313492)
 *
 */
public class Vacc {
//    public static Terminal epsilon = new Terminal(-1,-1,new String("0_epsilon"));/**Reprentacion de Epsilon*/
//    public static Terminal dolar = new Terminal(-1,-1,new String("0_$$"));/**Reprentacion de $ (fin de cadena)*/
    /**Reprentacion de Epsilon*/
    public static Terminal epsilon = new Terminal(new String("0_epsilon"));
    /**Reprentacion de $EOF$ (fin de cadena)*/
    public static Terminal dolar = new Terminal(new String("$EOF$"));
    /**Representacion de simbolo inicial*/
    public static NoTerminal start = new NoTerminal("0_start_");
    //HashMap<NoTerminal,SymbolSet> first;/**Primero*/
    //HashMap<NoTerminal,SymbolSet> follow;/**Siguiente*/
    
    private boolean parseado = false;
    HashMap<String,SymbolSet> first;/**Primero*/
    HashMap<String,SymbolSet> follow;/**Siguiente*/
    
    private HashMap<String,Terminal> listaT;/**Listado de Terminales*/
    private HashMap<String,NoTerminal> listaNT;/**Listado de no terminales     */    
    private Gramatica g;/**Gramatica aumentada*/
    private ConjuntoLR0 conjuntoLR0; /**Conjunto de estados LR0*/   
    private static final boolean debug = false;/**Bandera para debug de parseo*/
    
    private LALRFilePack paquete = new LALRFilePack();/**Paquete donde se almacenara los datos necesarios LALR persistentes*/
    private String nombrePaquete = new String("default");
    
    /** Crea una nueva instancia de Vacc */
    public Vacc() {
        g = new Gramatica();
        listaT = new HashMap<String,Terminal>();
        listaNT = new HashMap<String,NoTerminal>();
        first = new HashMap<String,SymbolSet>();
        follow = new HashMap<String,SymbolSet>();
        conjuntoLR0 = new ConjuntoLR0(g,listaT,listaNT);
        conjuntoLR0.setFirst(first);
        errormanager.ErrorManager.Inicializar();
        
    }
    
    /**Devolvemos Simbolo identificado por la cadena i1*/
    public Simbolo buscarSimbolo(String i1) {
        Simbolo s;
        if ((s =listaT.get(i1))!=null) 
            return s;
        else if ((s =listaNT.get(i1))!=null) 
            return s;
        else
            return null;
    }
    /**Busca un elemento gramatical*/
    public Elemento buscarElemento(Elemento e) {
        return g.buscarElemento(e);
       
    }
    
    public void insertarElemento(Elemento e) {
        g.insertarElemento(e);
       
    }

    public void insertarProducciones(Vector lp) {
        
    }
    /**Inserta no terminales a tabla de hash desde la gramatica*/
    public void insertarNoTerminales(int tipo, ArrayList lista) {
        Iterator i;
        String tmpStr;
        NoTerminal tmp;
        int prec;
        if(lista != null){
            i = lista.iterator();
            while(i.hasNext()){
                tmpStr = (String) i.next(); 
                tmp = new NoTerminal(tmpStr);//creamos no terminal                
                tmp.setTipo(tipo);  //asignamos tipo
                listaNT.put(tmp.getIdGram(),tmp); //insertamos a hash
            }
        }
    }
    /**Inserta no terminales a tabla de hash desde la gramatica*/
    public int insertarTerminales(int tipo, ArrayList lista) {
        Iterator i;
        String tmpStr;
        Terminal tmp;
        int prec;
        if(lista != null){
            i = lista.iterator();
            while(i.hasNext()){                
                tmpStr = (String) i.next();
                tmp = new Terminal(tmpStr);//creamos  terminal            
                tmp.setTipo(tipo);  //asignamos tipo                
                listaT.put(tmp.getIdGram(),tmp); //insertamos a hash
            }
        }
        return 0;
    }
    
    /**Parsea un Stream con la gramatica y construye listado de elementos*/
    public int parse(Reader pr)
    {
      Lexer l = new Lexer(pr);
      /* create a parsing object */
      parser parser_obj = new parser(l);
      /**Asignamos motor a parser*/
      parser.setEngine(this);
      /* open input files, etc. here */
      Symbol parse_tree = null;

      try {
        if (debug)
          parse_tree = parser_obj.debug_parse();
        else
          parse_tree = parser_obj.parse();
        pr.close();
        parseado = true;
        return 0;
      } catch (Exception e) {
        /* do cleanup here - - possibly rethrow e */
          
          System.out.println(e);
          pr.close();
          return -1;
      } finally {   
	/* do close out here */          
          return -1;
      }             
    }
    /**Metodo que inicia el procesamiento lalr en la gramatica. Llamando a metodos
     * que amplian la gramatica, calculan conjunto primero de cada simbolo, 
     * y generan los estados y la respectiva tabla goto y action LALR(1)*/
    public void procesarLALR()  throws Exception{
        //System.out.println(g);
        if(parseado){
            g.ampliar();/**Ampliamos la gramatica*/
            g.asignarIndicesProduccion();/**Asignamos indices a las producciones*/
            this.first(null);/**Calculamos funcion primero*/
            conjuntoLR0.calcularEstados();/**Calculamos estados*/ 
            System.out.println(conjuntoLR0);
        }
        else{
            throw new Exception("Imposible procesar el LALR, la gramatica no ha sido cargada, verifique si se analizo bien el archivo cmp.");
        }
        
        //return 0;
    }
    /**Procesa la gramatica, genera tabla LALR y la almacena al path dado*/
    public void procesarLALRyGuardarTablas(String path) throws Exception{
        //try{
            procesarLALR();
            guardarPaquete(path);
        //    testLeerPaquete(path);
        //}
        //catch(Exception e){
        //    System.out.println(e);
        //}
    }
    
    /**Procesa archivo especificado por path dado*/
    public void compilar(String pFilenameInput, String pathRepositorio) throws Exception{
                int ret;
        Reader r;
        try{ 
            r = new FileReader(pFilenameInput);     
            parse(r);                      
            procesarLALRyGuardarTablas(pathRepositorio);
        }
        catch(Exception e){
            System.out.println(e);
            throw e;
            //return -1;            
        }
    }
    /**Calcula recursivamente la funcion primero
     @param nt No terminal a calcularle, si este es igual a nulo, calcula primero
     para todos los elementos no terminales de la gramatica
     @return Conjunto de simbolos dados por Primero(nt)*/    
    public SymbolSet first(NoTerminal nt)/* throws Exception*/{
        Iterator i,j;
        SymbolSet tmpss = null, primAnt = null,sst;
        Simbolo sact;
        Elemento eact;
        NoTerminal ntact;
        Terminal tact;
        i = g.getProducciones().iterator();
        /**Paso inicial: Iteramos por todas las producciones obteniendo cada LI*/
        if(nt == null){        
            NoTerminal ntActual;
            i = g.getProducciones().iterator();
            //la = new HashSet<NoTerminal>();
            /**Para cada produccion de la gramatica, sacamos primero del NT a la izquierda*/
            if(i.hasNext() == false)
                return null;
                //throw new Exception("No existen producciones");
            while(i.hasNext()){
                eact =(Elemento) i.next();
                /**Creamos un conjunto primero para cada NT del lado izquierdo 
                 * de la produccion actual para el cual no exista conjunto todavia
                 * y calculamos su conjunto primero*/                
                ntActual = eact.getLi();
                sst = first.get(ntActual.getIdGram());
                if (sst == null/*!first.get(ntActual)==null*/){/**Si no existe */
                    //la.add(ntActual);/**Agregamos a listaAgregados*/
                    //tmpss = first(ntActual,la)/*Calculamos primero del elemento en cuestion*/;
                    tmpss = new SymbolSet(ntActual,first(ntActual))/*Calculamos primero del elemento en cuestion*/;
                    //tmpss.setNT(ntActual);
                    first.put(ntActual.getIdGram(),tmpss);                    
                }                    
            }
            return null;
        }
        else{/**Calculamos primero para el elemento dado en el parametro*/                                
            if(first.get(nt.getIdGram()) != null)
                return (SymbolSet)first.get(nt.getIdGram());        /**Si ya existe primero del simbolo retornamos*/
            else{
                tmpss = new SymbolSet(nt);      
                first.put(nt.getIdGram(),tmpss);//insertamos nuevo conjunto
            }
            while(i.hasNext()){/**Recorremos todas las producciones en busqueda de primero*/
                eact =(Elemento) i.next();

                /**Si el simbolo del lado izquierdo es el mismo*/
                if(eact.getLi().equals(nt)){
                    /**Recorremos cada simbolo del lado derecho de la gramatica*/
                    j = eact.getLd().getSimbolos().iterator();                
                    while(j.hasNext()){
                        /**Si es no terminal y estamos al inicio de la iteracion 
                         * o si primero calculado anteriormente contiene algun cadena vacia epsilon
                         * creamos recursivamente primero para el conjunto dado*/
                        sact = (Simbolo) j.next();
                        //System.out.println(sact.getClass());
                        if((sact.esNoTerminal() && primAnt == null) 
                        || (sact.esNoTerminal() && primAnt.existeTerminal(Vacc.epsilon)) ){                    
                            ntact = (NoTerminal) this.buscarSimbolo(sact.getIdGram());
                            /**Validacion para evitar blucles del tipo e->eB*/
                            if(!ntact.equals(nt)){
                                primAnt = first(ntact); /**Calculamos primero*/
                                tmpss.union(primAnt); /*Agregamos primero al elemento actual*/
                            }
                            else
                                break;/**Avanzamos si es igual simb del LR al simb de LI*/
                        }
                        /**Si es terminal o epsilon*/
                        else if((!sact.esNoTerminal() && 
                                primAnt == null) 
                                ||  /**Si es terminal lo insertamos y nos salimos del ciclo*/
                                (!sact.esNoTerminal() && primAnt.existeTerminal(Vacc.epsilon)) ){
                            if(!sact.equals(Vacc.epsilon)){
                                tact = (Terminal) this.buscarSimbolo(sact.getIdGram());
                                tmpss.insertarTerminal(tact);
                            }
                            else
                                tmpss.insertarTerminal(Vacc.epsilon);
                            break;
                            //return tmpss;
                        }
                        else if (primAnt != null){
                            
                        }
                    }
                }
            }
        return tmpss;
        }
    }
    
    /**Almacena paquete LALR en path dado. @param path Path hacia donde se almacenara el paquete, debe llevar diagonal al final */
    public void guardarPaquete(String path) throws IOException{
        prepararPaquete();
        
        FileOutputStream out = new FileOutputStream(path + nombrePaquete + ".lalr");
        ObjectOutputStream s = new ObjectOutputStream(out);
        s.writeObject(this.paquete);
        s.flush();
    }
    
    /**Devuelve el paquete LALR actual*/
    public LALRFilePack getPaquete() {
        return paquete;
    }
    /**Devuelve nombre de paquete actual*/
    public String getNombrePaquete() {
        return nombrePaquete;
    }
    /**Asigna nombre al paquete actual*/
    public void setNombrePaquete(String nombrePaquete) {
        this.nombrePaquete = nombrePaquete;
    }
    
    /**Prepara el paquete para que pueda ser serializado*/
    private void prepararPaquete() {
        paquete.setG(this.g);
        paquete.setListaNT(this.listaNT);
        paquete.setListaT(this.listaT);
        paquete.setTablaAcciones(this.conjuntoLR0.getTablaAcciones());
        paquete.setTablaGoto(this.conjuntoLR0.getTablaGoto());
        paquete.setNumEstados(this.conjuntoLR0.getNumEstados());
    }

    private void testLeerPaquete(String path) throws Exception {        
        LALRFilePack p1;
        FileInputStream in = new FileInputStream(path + "default.lalr");
        ObjectInputStream s = new ObjectInputStream(in);
        p1 = (LALRFilePack)s.readObject();    
        System.out.println(p1);
    }
    
}
