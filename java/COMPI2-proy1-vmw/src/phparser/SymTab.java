/*
 * SymTab.java
 *
 * Creada el 18 de marzo de 2007, 06:08 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package phparser;
import java.util.*;
/**
 * Tabla de simbolos a utilizar durante la interpretacion
 * @author Erik Giron (200313492)
 *
 */
public class SymTab {
    
    private HashMap<String,SymTabEntry> tabla = new HashMap<String,SymTabEntry>();///la tabla de registros de todos los simbolos contenidos

    private static final int T_STRING = 0;

    private static final int T_INTEGER = 1;

    private static final int T_FLOAT = 2;
    
    private static final int FUNC = 100;
    private static final int VAR = 101;
    private static final int PTR = 102;
    /** Crea una nueva instancia de SymTab */
    public SymTab() {        
        
    }
    /**Limpia la tabla de simbolos actual*/
    public void limpiarTabla(){
        tabla = new HashMap<String,SymTabEntry> ();
    }
    /**Devuelve verdadero si la tabla esta vacia*/
    public boolean estaVacia(){
        return tabla.isEmpty();
    }
    
    /**Devuelve, si existe, un registro de la tabla de simbolos*/
    public SymTabEntry getRegistro(String id){
        return tabla.get(id);
    }
    
    /**Registro de la tabla de simbolos*/
    public class SymTabEntry{        
        private String id;///Identificador 
         
        private int clase = 0;///Clase (funcion, variable, procedimiento, etc.
        private int tipo = 0;///Tipo (int, string, etc)
        private Object valor = null; /// Dato, puede ser tambien el valor de retorno de una funcion
        private String ambito; /// Ambito al que pertenece la entrada(root, funcion1, funcion2)
        private int nivel = 0; ///Nivel de anidamiento
        private NodoAst pNodo = null; ///Si es funcion, aqui se almacena el puntero de hacia el nodo del arbol de sintaxis donde inicia la funcion para ejecucion dinamica
        
        SymTabEntry(){
            
        }
        
        /**Crea una nueva entrada a la tabla de simbolos, regularmente se usa para variables*/
        SymTabEntry(String id,int  tipo,String ambito,Object valor){
            this.id = id;
            this.tipo = tipo;
            this.ambito = ambito;
            this.valor = valor;
        }
        
        SymTabEntry(String id, int tipo,NodoAst ptrNodo){
            this.id = id;
            this.tipo = tipo;
            this.pNodo = ptrNodo;
        }
        
        public boolean equals(Object e1){
            SymTabEntry n = (SymTabEntry) e1;
            if(e1 == null || !(e1.getClass().equals(this.getClass()))){
                return false;
            }            
            if(this.getId().equals(n.getId())){
                if(this.getClase() == n.getClase()){
                    if(this.getAmbito().equals(n.getAmbito())){
                        return true;
                    }                        
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
            return false;
        }
        /**Devuelve el ambito*/
        public String getAmbito() {
            return ambito;
        }

        public int getClase() {
            return clase;
        }

        public String getId() {
            return id;
        }

        public int getNivel() {
            return nivel;
        }

        public NodoAst getPNodo() {
            return pNodo;
        }

        public int getTipo() {
            return tipo;
        }

        public Object getValor() {
            return valor;
        }

        public void setAmbito(String ambito) {
            this.ambito = ambito;
        }

        public void setClase(int clase) {
            this.clase = clase;
        }

        public void setId(String id) {
            this.id = id;
        }

        public void setNivel(int nivel) {
            this.nivel = nivel;
        }

        public void setPNodo(NodoAst pNodo) {
            this.pNodo = pNodo;
        }

        public void setTipo(int tipo) {
            this.tipo = tipo;
        }

        public void setValor(Object valor) {
            this.valor = valor;
        }
    }
    
    /**Agrega una nueva variable a la tabla de simbolos*/
    public int insertarVariable(String id, int tipo, String ambito, Object valor){
        SymTabEntry t;        
        t = new SymTabEntry(id, tipo, ambito, valor);        
        t.setClase(SymTab.VAR);
        tabla.put(id,t);
        return 0;
    }
    
    
    /**Agrega una nueva variable a la tabla de simbolos*/
    public int insertarFuncion(String id, NodoAst ptrNodo){
        SymTabEntry t = new SymTabEntry(id, -1 , ptrNodo);
        t.setClase(SymTab.FUNC);
        tabla.put(id,t);
        return 0;
    }
    
    /**Agrega una nueva referencia de la variable destino existente en tabla de simbolos a la variable dada */
    public int insertarReferencia(String variable, String destino){
        SymTabEntry t = tabla.get(destino);
        //t.setClase(SymTab.PTR);
        tabla.put(variable,t);
        return 0;
    }
    
    /**Obtiene entrada de la tabla de simbolos*/
    public SymTabEntry get(String id){
        return tabla.get(id);
    }
    /**Insertamos un atributo de la definicion dirigida por la sintaxis*/
    public int insertarAtributo(String string, int tipo, Object valor) {
        SymTabEntry nuevo = null;
        if(string != null && string.length() > 0)
        switch (tipo){
            case 1:
                if(valor!=null){
                    if(valor.getClass().equals(string.getClass()))
                        nuevo = new SymTabEntry(new String("$" + string),Ast.N_LIT_INT,new String("$atributo"),new Integer(Integer.parseInt((String)valor)));
                    else if(valor.getClass().equals(new Float(0).getClass()))
                        nuevo = new SymTabEntry(new String("$" + string),Ast.N_LIT_INT,new String("$atributo"),new Integer(((Float)valor).intValue()));
                    else
                        nuevo = new SymTabEntry(new String("$" + string),Ast.N_LIT_INT,new String("$atributo"),new Integer((Integer)valor));
                }
                else
                    nuevo = new SymTabEntry(new String("$" + string),Ast.N_LIT_INT,new String("$atributo"),new Integer(0));
                break;
            case 2:
                if(valor!=null){
                    if(valor.getClass().equals(string.getClass()))
                        nuevo = new SymTabEntry(new String("$" + string),Ast.N_LIT_FLOAT,new String("$atributo"),new Float(Float.parseFloat((String)valor)));
                    else if ((valor.getClass().equals(new Integer(0).getClass())))
                        nuevo = new SymTabEntry(new String("$" + string),Ast.N_LIT_FLOAT,new String("$atributo"),new Float((Integer)valor));
                    else
                        nuevo = new SymTabEntry(new String("$" + string),Ast.N_LIT_FLOAT,new String("$atributo"),new Float((Float)valor));
                }        
                else
                    nuevo = new SymTabEntry(new String("$" + string),Ast.N_LIT_FLOAT,new String("$atributo"),new Float(0.0f));
                break;
            default:
                if(valor!=null)
                    nuevo = new SymTabEntry(new String("$" + string),Ast.N_LIT_STRING,new String("$atributo"),new String((String)valor));
                else
                    nuevo = new SymTabEntry(new String("$" + string),Ast.N_LIT_STRING,new String("$atributo"),new String());
                break;
        }
        this.tabla.put(nuevo.getId(),nuevo);
        return 0;
    }
    /**Elimina una entrada especificada por id de la tabla de simbolos*/
    public int borrarEntrada(String id) {
        if(!id.startsWith("$"))
            this.tabla.remove("$" + id);            
        else
            this.tabla.remove(id);
        return 0;
    }

    public int updateVariable(String key, int tipo, String ambito, Object valor) {
        SymTabEntry t;
        t = this.tabla.get(key);
        if(t!= null){
            t.setTipo(tipo);
            //t.setAmbito(am)
            t.setValor(valor);
        }
        return 0;
    }
    
    /** Se puede decir formalmente que se inserta un puntero hacia la variable destino inserta en una tabla de simbolos old que es de otro ambito
     en esta tabla que es del ambito actual.  Esto se usa para el paso de variables por referencia en las llamadas a funciones*/
    public int insertarReferenciaParametro(String variable, String destino, SymTab old) {
        //obtenemos entrada de la tabla de simbolos a referenciar
        SymTabEntry t = old.get(destino);
        //t.setClase(SymTab.PTR);
        tabla.put(variable,t);
        return 0;
    }
    
    /**Inserta entradas de funciones en la tabla anterior hacia esta*/
    public void insertarFunciones(SymTab anterior) throws Exception{
        SymTabEntry entryActual;
        String idActual;
        if(anterior != null){
            Iterator i = anterior.tabla.keySet().iterator();
            while(i.hasNext()){
                idActual = (String) i.next();
                entryActual = anterior.get(idActual);
                if(entryActual.getClase() == SymTab.FUNC){
                    this.tabla.put(idActual,entryActual);
                }
            }
        }
        else{
            throw new Exception("Imposible insertar funciones, la tabla de simbolos que las contiene no existe");
        }
    }
}
