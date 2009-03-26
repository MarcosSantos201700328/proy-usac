/*
 * Optimizer.java
 *
 * Creada el May 29, 2007, 10:33 AM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package optimizer;
import java.util.*;
import java.io.*;

/**
 * Clase principal del modulo de optimizacion de codigo
 * @author Erik Giron (200313492)
 * 
 */
public class Optimizer {
    /**Constantes*/
    public static final int OP_GT = 100;
    public static final int OP_LT = 101;
    public static final int OP_NE = 102;
    public static final int OP_EQ = 103;
    public static final int OP_GE = 104;
    public static final int OP_LE = 105;
    public static final int OP_MOD = 106;
    public static final int OP_DIV = 107;
    public static final int OP_MULT = 108;
    public static final int OP_MINUS = 109;
    public static final int OP_PLUS = 110;
    
    public static final int TOP_ARIT = 1;
    public static final int TOP_JUMP = 2;
    public static final int TOP_PROP = 4;
    public static final int TOP_EXP = 8;
    
    
    private static ArrayList<Quadruplo> fuente = new ArrayList<Quadruplo>(); // origen
    private static ArrayList<Quadruplo> sumidero = new ArrayList<Quadruplo>(); // codigo completamente optimizado
    
    private static ArrayList<Quadruplo> aritTransOpt = new ArrayList<Quadruplo>(); // optimizacion por transformaciones aritmeticas
    private static ArrayList<Quadruplo> jumpOpt = new ArrayList<Quadruplo>(); // optimizacion por eliminacion de saltos
            
    
    /** Crea una nueva instancia de Optimizer */
    public Optimizer() {
    }
    
    /* Inserta una nueva linea que sera ignorada por el optimizador*/
    public static void addIgnoreString(String cadena, int linea){
        Quadruplo nuevo = new Quadruplo(new Elem(cadena,-1),null,null,-1,Quadruplo.T_IGNORE,linea);
        fuente.add(nuevo);
    }
    
    /* Inserta una nueva linea de etiqueta*/
    public static void addLabel(String cadena, int linea){
        Quadruplo nuevo = new Quadruplo(null,null,new Elem(cadena,Elem.E_LABEL),-1,Quadruplo.T_LABEL,linea);
        fuente.add(nuevo);
    }
    
    /* Inserta una nueva linea de salto goto*/
    public static void addGoto(String cadena, int linea){
        Quadruplo nuevo = new Quadruplo(null,null,new Elem(cadena,Elem.E_GOTO),-1,Quadruplo.T_GOTO,linea);
        fuente.add(nuevo);
    }
    
    /* Inserta una nueva linea condicional if*/
    public static void addIf(String op1, int op,String op2, String gt, int linea ){
        Quadruplo nuevo = new Quadruplo(new Elem(op1,Elem.E_SCALAR),new Elem(op2,Elem.E_SCALAR),new Elem(gt,Elem.E_GOTO),op,Quadruplo.T_IF,linea);
        fuente.add(nuevo);
    }
    
    /* Inserta una nueva linea de asignacion escalar*/
    public static void addScalarAsig(String dest, String src, int linea){
        Quadruplo nuevo = new Quadruplo(new Elem(src,Elem.E_SCALAR),null,new Elem(dest,Elem.E_SCALAR),-1,Quadruplo.T_SCALARASIG,linea);
        fuente.add(nuevo);
    }

    /* Inserta una nueva linea de asignacion vectorial*/
    public static void addMatAsig(String dest, String idx, String src,int linea){
        Quadruplo nuevo = new Quadruplo(new Elem(src,Elem.E_SCALAR),new Elem(idx,Elem.E_SCALAR),new Elem(dest,Elem.E_VECTOR),-1,Quadruplo.T_VECTORASIG,linea);
        fuente.add(nuevo);
    }
    
    /* Inserta una nueva linea de escalar desde vector*/
    public static void addDesRef(String dest,  String src,String idx,int linea){
        Quadruplo nuevo = new Quadruplo(new Elem(src,Elem.E_VECTOR),new Elem(idx,Elem.E_SCALAR),new Elem(dest,Elem.E_SCALAR),-1,Quadruplo.T_DESREF,linea);
        fuente.add(nuevo);
    }
    /* Inserta una nueva linea de operacion aritmetica entre escalares*/
    public static void addAritOp(String dest,String op1,String op2, int op,int linea){
        Quadruplo nuevo = new Quadruplo(new Elem(op1,Elem.E_SCALAR),new Elem(op2,Elem.E_SCALAR),new Elem(dest,Elem.E_SCALAR),op,Quadruplo.T_ARITOP,linea);
        fuente.add(nuevo);
    }
    
    /* Inserta una nueva linea de inicio de procedimiento*/
    public static void addBeginProc(String dest, int linea){
        Quadruplo nuevo = new Quadruplo(null,null,new Elem(dest,Elem.E_PROC),-1,Quadruplo.T_BEGIN,linea);
        fuente.add(nuevo);
    }
    
    /* Inserta una nueva linea de fin de procedimiento*/
    public static void addEndProc(String dest, int linea){
        Quadruplo nuevo = new Quadruplo(null,null,new Elem(dest,Elem.E_PROC),-1,Quadruplo.T_END,linea);
        fuente.add(nuevo);
    }
    
    /**Reinicializa los cuadruplos, y vacia las listas*/    
    public static void init(){
        fuente.clear();
        sumidero.clear();
        aritTransOpt.clear();
        jumpOpt.clear();
                
    }
    /**funcion solo para debugear*/
    public static void naranjas(){
        int a = 0;
        a = 1;
        //optimizacionAritmetica();
    }
    
    /**Optimiza reutilizando expresiones comunes*/
    public static void optimizacionExpComunes(){
        Quadruplo actual;
        Quadruplo pivote;
        int i, j;
        for(i = 0; i < fuente.size(); i++){ // tomando cada elemento pivote
            pivote = (Quadruplo) fuente.get(i);
            if (pivote.getTipo() == Quadruplo.T_ARITOP){
                for(j = i + 1; j < fuente.size(); j++){// para cada elemento consecuente al pivote
                    actual = fuente.get(j);
                    if(actual.getTipo() == Quadruplo.T_ARITOP){ //si actual es exp. aritmetica
                        if(!actual.getResultado().getId().equals(pivote.getResultado().getId())  // si la exp. no sustituye ninguna variable usada en pivote
                        && !actual.getResultado().getId().equals(pivote.getOperando1().getId())
                        && !actual.getResultado().getId().equals(pivote.getOperando2().getId())){
                            if(actual.getOperador() == pivote.getOperador()){
                                if((actual.getOperando1().getId().equals(pivote.getOperando1().getId())
                                && actual.getOperando2().getId().equals(pivote.getOperando2().getId())
                                )||(actual.getOperando1().getId().equals(pivote.getOperando2().getId())
                                && actual.getOperando2().getId().equals(pivote.getOperando1().getId())
                                )){
                                    actual.setOperando1(pivote.getResultado());
                                    actual.setOperando2(null);
                                    actual.setOperador(-1);
                                    actual.setTipo(Quadruplo.T_SCALARASIG);
                                    actual.setTipoOptim(actual.getTipoOptim() | TOP_EXP);
                                }
                            }
                        }
                        else{ // sino nos movemos al sig elemento pivote
                            //i++;
                            j = fuente.size();
                        }
                    }
                    
                }
            } 
            
        }
    }
    
    /**Realiza la optimizacion para operaciones aritmeticas,*/
    public static void optimizacionAritmetica(){
        Iterator i = fuente.iterator();
        Quadruplo actual;        
        Quadruplo nuevo;
        //Recorriendo todas los cuadruplos        
        while(i.hasNext()){
            //clonamos el objeto actual
            actual = (Quadruplo) i.next();
            nuevo = new Quadruplo(actual);
            // verificamos que el cuadruplo sea aritmetico
            if(actual.getTipo() == Quadruplo.T_ARITOP){
                // y segun su operador, se realizara la optimizacion correspondiente
                switch(actual.getOperador()){
                    case OP_DIV:
                        // x = y / 1 -> x = y
                        if(actual.getOperando2().getId().equals("1")){
                            nuevo.setOperando2(null);
                            nuevo.setOperador(-1);
                            nuevo.setTipo(Quadruplo.T_SCALARASIG);
                            nuevo.setTipoOptim(nuevo.getTipoOptim() | TOP_ARIT);
                        }
                        break;
                    case OP_MULT:
                        // x = y * 1 -> x = y
                        if(actual.getOperando2().getId().equals("1")){
                            nuevo.setOperando2(null);
                            nuevo.setOperador(-1);
                            nuevo.setTipo(Quadruplo.T_SCALARASIG);
                            nuevo.setTipoOptim(nuevo.getTipoOptim() | TOP_ARIT);
                        }
                        // x = 1 * y -> x = y
                        else if(actual.getOperando1().getId().equals("1")){
                            nuevo.setOperando1(nuevo.getOperando2());
                            nuevo.setOperando2(null);
                            nuevo.setOperador(-1);
                            nuevo.setTipo(Quadruplo.T_SCALARASIG);
                            nuevo.setTipoOptim(nuevo.getTipoOptim() | TOP_ARIT);
                        }
                        // x = 0 * y ^ x = y * 0 -> x = 0
                        else if(actual.getOperando1().getId().equals("0") || actual.getOperando2().getId().equals("0")){
                            nuevo.setOperando1(new Elem("0",Elem.E_SCALAR));
                            nuevo.setOperando2(null);
                            nuevo.setOperador(-1);
                            nuevo.setTipo(Quadruplo.T_SCALARASIG);
                            nuevo.setTipoOptim(nuevo.getTipoOptim() | TOP_ARIT);
                        }
                        break;
                    case OP_MINUS:
                        // x = y - 0 -> x = y
                        if(actual.getOperando2().getId().equals("0")){
                            nuevo.setOperando2(null);
                            nuevo.setOperador(-1);
                            nuevo.setTipo(Quadruplo.T_SCALARASIG);
                            nuevo.setTipoOptim(nuevo.getTipoOptim() | TOP_ARIT);
                        }
                        // x = 0 - y -> x = -y
                        else if(actual.getOperando1().getId().equals("0")){
                            nuevo.setOperando1(nuevo.getOperando2());
                            nuevo.getOperando1().setId("-" + nuevo.getOperando1().getId());
                            nuevo.setOperando2(null);
                            nuevo.setOperador(-1);
                            nuevo.setTipo(Quadruplo.T_SCALARASIG);
                            nuevo.setTipoOptim(nuevo.getTipoOptim() | TOP_ARIT);
                        }
                        break;
                    case OP_PLUS:
                        // x = y + 0 -> x = y
                        if(actual.getOperando2().getId().equals("0")){
                            nuevo.setOperando2(null);
                            nuevo.setOperador(-1);
                            nuevo.setTipo(Quadruplo.T_SCALARASIG);
                            nuevo.setTipoOptim(nuevo.getTipoOptim() | TOP_ARIT);
                        }
                        // x = 0 + y -> x = y
                        else if(actual.getOperando1().getId().equals("0")){
                            nuevo.setOperando1(nuevo.getOperando2());
                            nuevo.setOperando2(null);
                            nuevo.setOperador(-1);
                            nuevo.setTipo(Quadruplo.T_SCALARASIG);
                            nuevo.setTipoOptim(nuevo.getTipoOptim() | TOP_ARIT);
                        }
                        break;
                }
            }
            // insertamos a sumidero el codigo ya procesado
            sumidero.add(nuevo);
        }
        // actualizamos la fuente con el sumidero actual
        fuente = sumidero;
    }
    
    /**Optimiza por propagacion de copias*/
    public static void optimizacionPropCopia(){
        Quadruplo actual;
        Quadruplo pivote;
        boolean updated = false;
        int i, j;
        for(i = 0; i < fuente.size(); i++){ // tomando cada elemento pivote
            pivote = (Quadruplo) fuente.get(i);
            updated = false;
            if (pivote.getTipo() == Quadruplo.T_SCALARASIG){
                for(j = i + 1; j < fuente.size(); j++){// para cada elemento consecuente al pivote
                    actual = fuente.get(j);
                    if(actual.getTipo() == Quadruplo.T_IF){ //si actual es if
                        if(actual.getOperando1().getId().equals(pivote.getResultado().getId())){ // si primer operando es igual al elemento susodicho
                            actual.setOperando1(pivote.getOperando1());                                                                
                            updated = true;
                            actual.setTipoOptim(actual.getTipoOptim() | TOP_PROP);
                        }
                        if (actual.getOperando2().getId().equals(pivote.getResultado().getId())){ // si segundo operando es igual al elemento susodicho
                            actual.setOperando2(pivote.getOperando1());                                                                
                            updated = true;
                            actual.setTipoOptim(actual.getTipoOptim() | TOP_PROP);
                        }
                        
                    }
                    else if(actual.getTipo() == Quadruplo.T_ARITOP){ //si actual es exp. aritmetica
                        if(!actual.getResultado().getId().equals(pivote.getResultado().getId())  // si la exp. no sustituye ninguna variable usada en pivote
                        && !actual.getResultado().getId().equals(pivote.getOperando1().getId())){
                            if(actual.getOperando1().getId().equals(pivote.getResultado().getId())){ // si primer operando es igual al elemento susodicho
                                actual.setOperando1(pivote.getOperando1());                                                                
                                updated = true;
                                actual.setTipoOptim(actual.getTipoOptim() | TOP_PROP);
                            }
                            if (actual.getOperando2().getId().equals(pivote.getResultado().getId())){ // si segundo operando es igual al elemento susodicho
                                actual.setOperando2(pivote.getOperando1());                                                                
                                updated = true;
                                actual.setTipoOptim(actual.getTipoOptim() | TOP_PROP);
                            }
                        }
                        else{ // sino nos movemos al sig elemento pivote
                            //i++;
                            j = fuente.size();
                        }
                    }
                    else if(actual.getTipo() == Quadruplo.T_SCALARASIG){ //si actual es asignacion escalar
                        if(!actual.getResultado().getId().equals(pivote.getResultado().getId())  // si la exp. no sustituye ninguna variable usada en pivote
                        && !actual.getResultado().getId().equals(pivote.getOperando1().getId())){
                            if(actual.getOperando1().getId().equals(pivote.getResultado().getId())){ // si primer operando es igual al elemento susodicho
                                actual.setOperando1(pivote.getOperando1());                                                                
                                updated = true;
                                actual.setTipoOptim(actual.getTipoOptim() | TOP_PROP);
                            }
                        }
                        else{ // sino nos movemos al sig elemento pivote
                            //i++;
                            j = fuente.size();
                        }
                    }
                    else if(actual.getTipo() == Quadruplo.T_DESREF){ //si actual es asignacion de desreferencia
                        if(!actual.getResultado().getId().equals(pivote.getResultado().getId())  // si la exp. no sustituye ninguna variable usada en pivote
                        && !actual.getResultado().getId().equals(pivote.getOperando1().getId())){
                            if(actual.getOperando2().getId().equals(pivote.getResultado().getId())){ // si indice operando es igual al elemento susodicho
                                actual.setOperando2(pivote.getOperando1());                                                                
                                updated = true;
                                actual.setTipoOptim(actual.getTipoOptim() | TOP_PROP);
                            }
                        }
                        else{ // sino nos movemos al sig elemento pivote
                            //i++;
                            j = fuente.size();
                        }
                    }
                    else if(actual.getTipo() == Quadruplo.T_VECTORASIG){ //si actual es asignacion a vector
                        if(actual.getOperando1().getId().equals(pivote.getResultado().getId())){ // si indice operando es igual al elemento susodicho
                            actual.setOperando1(pivote.getOperando1());                                                                
                            updated = true;
                            actual.setTipoOptim(actual.getTipoOptim() | TOP_PROP);
                        }
                        if(actual.getOperando2().getId().equals(pivote.getResultado().getId())){ // si indice operando es igual al elemento susodicho
                                actual.setOperando2(pivote.getOperando1());                                                                
                                updated = true;
                                actual.setTipoOptim(actual.getTipoOptim() | TOP_PROP);
                        }
                    }
                }
                if (updated){ // si se actualizo, se quitara la instruccion redundante
                    fuente.remove(i);
                    i--;
                }
            } 
            
        }
    }
    
    /**Optimiza un archivo dado por filename, siguiendo los patrones de optimizacion dados en tipo, para generar como resultado un .htm y un .opt de salida*/
    public static void optimizar(String filename, int tipo) throws Exception {
        //abrimos archivo y lo parseamos
        try{
                OptParser p = new OptParser(new OptLexer(new FileReader(filename)));
                //p.debug_parse();
                p.parse();
                
        }
        catch(Exception e){
                System.out.println(e);
                throw e;
        }
        
        //seleccionamos el tipo de optimizacion a realizar
        switch (tipo){
            case 0: // optimiza por los 4 metodos consecutivamente
                optimizacionAritmetica();
                optimizacionExpComunes();
                optimizacionPropCopia();                
                break;
            case 1: // optimiza solo por expresiones comunes
                optimizacionExpComunes();
                break;
            case 2: // optimiza por propagacion de copias
                optimizacionPropCopia();
                break;
            case 3: // optimiza por trans. aritmeticas
                optimizacionAritmetica();
                break;
            case 4: // optimiza por saltos
                break;
        }
        
        // generamos archivo de salida y reporte html
        generarSalida(filename);
        
    }
    
    /**Genera archivos de salida optimizados*/
    private static void generarSalida(String filename) throws Exception {
        BufferedWriter fhtm, fopt;
        fopt = new BufferedWriter(new FileWriter(filename + ".opt.c"));
        fhtm = new BufferedWriter(new FileWriter(filename + ".opt.html"));
        
        
        //Escribimos encabezado html
        fhtm.write("<html>\n");
        fhtm.write("<head>\n");
        fhtm.write("<title>Reporte de optimizacion - EvilGCC (c) 2007 Erik Giron</title>\n");
        fhtm.write("</head>\n");
        fhtm.write("<body>\n");
        fhtm.write("<h1> REPORTE DE  OPTIMIZACION </h1>\n");
        //iteramos sobre el codigo optimizado y lo generamos
        Iterator i = fuente.iterator();
        Quadruplo actual;
        while(i.hasNext()){
            actual = (Quadruplo) i.next();
            switch(actual.getTipoOptim()){
                case TOP_ARIT:
                    fhtm.write("<font color = \"#00AA00\" face=\"helvetica\">");
                    break;
                case TOP_JUMP:
                    fhtm.write("<font color = \"#AA0000\" face=\"helvetica\">");
                    break;
                case TOP_PROP:
                    fhtm.write("<font color = \"#0000AA\" face=\"helvetica\">");
                    break;
                case TOP_EXP:
                    fhtm.write("<font color = \"#AA00AA\" face=\"helvetica\">");
                    break;
                case 0:
                case -1:
                    fhtm.write("<font color = \"#666666\" face=\"helvetica\">");
                    break;
                default:
                    fhtm.write("<font color = \"#000000\" face=\"helvetica\">");
                    break;
            }
            fhtm.write(actual.toString() + "</font><br>\n");
            fopt.write(actual.toString() + "\n");            
        }
        fhtm.write("</body>");
        fhtm.write("</html>");
           
        fopt.close();
        fhtm.close();
    }
}
