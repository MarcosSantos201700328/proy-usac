/*
 * SymTab.java
 *
 * Creada el 23 de abril de 2007, 03:33 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 * TODO: Componer el equals para que funcionen los indices de la tabla de simbolos si son repetidos. 
 */

package IlGen;
import java.util.*;
        
/**
 * Tabla de simbolos de tiempo de compilacion, almacena un conjunto de simbolos necesarios para mantener informacion importante para el parser
 * @author Erik Giron (200313492)
 *
 */
public class SymTab {
    /*Constantes de tipos*/
    public static final int T_VOID = 0;
    public static final int T_INT = 1; 
    public static final int T_CHAR = 2;
    public static final int T_STRING = 3;
    public static final int T_TYPEDEF = 4;
    public static final int T_BOOL = 5;
    public static final int T_FLOAT = 6;
    public static final int T_REFERENCE = 100;
    public static final int T_VALUE = 101;
    public static final int T_OP = 102;// Pseudotipo para operadores
    public static final int C_VAR = 200;
    public static final int C_FUNC = 201;
    public static final int C_PROC = 202;
    public static final int C_CLASS = 203;
    public static final int C_STRUCT = 204;
    public static final int C_UNION= 205;
    public static final int C_OBJECT = 206;
    public static final int C_ARRAY = 207;
    public static final int C_CONSTR = 208;      
    
    public static final int A_PUBLIC = 300;
    public static final int A_PRIVATE = 301;
    
    private SymIndex lookFor = new SymIndex();
    
    
    /** Crea una nueva instancia de SymTab */
    public SymTab() {
    }
    /**Tupla de ID - Scope para indizacion sencilla*/
    public class TuplaSS{
        public String scope = new String();
        public String id = new String(); 
        
        public int hashCode(){
            return scope.hashCode() + id.hashCode();
        }
        
        TuplaSS(String i, String s){
            id = i;
            scope = s;
        }
        public boolean equals(Object o){
            TuplaSS tmp;
            if(o.getClass().equals(this.getClass())){
                tmp = (TuplaSS) o;
                if(tmp.getId().equals(this.getId()) && tmp.getScope().equals(this.getScope())){
                    return true;
                }
            }
            return false;
        }

        public void setId(String id) {
            this.id = id;
        }

        public void setScope(String scope) {
            this.scope = scope;
        }

        public String getId() {
            return id;
        }

        public String getScope() {
            return scope;
        }
        
    }
    
    /**Fields*/
    private HashMap<SymIndex, Symbol> table = new HashMap<SymIndex,Symbol>();
    private HashMap<TuplaSS, Symbol> IdxVariables = new HashMap<TuplaSS, Symbol>();
    private HashMap<TuplaSS, Symbol> IdxFunctions = new HashMap<TuplaSS, Symbol>();;
    private HashMap<TuplaSS, Symbol> IdxClasses = new HashMap<TuplaSS, Symbol>();;
    
    /**Devuelve tabla de variables*/
    public HashMap<TuplaSS, Symbol> getIdxVariables(){
        return this.IdxVariables;
    }
    
    /**Devuelve tabla de Funciones*/
    public HashMap<TuplaSS, Symbol> getIdxFunctions(){
        return this.IdxFunctions;
    }    
    /**Devuelve tabla de Clases*/    
    public HashMap<TuplaSS, Symbol> getIdxClasses(){
        return this.IdxClasses;
    }
    /**Devuelve tabla de simbolos*/
    public HashMap<SymIndex, Symbol> getTable() {
        return table;
    }
    
    /**Devuelve el tamano de una instnacia*/
    public int getSize(String id){
        DataType dt = new DataType(C_CLASS);
        Symbol s = getSymbol(id,dt,"global",SymTab.C_CLASS, 0);
        Iterator i = table.keySet().iterator();
        SymIndex actual;
        int size = 0;
        while(s!= null && i.hasNext()){
            actual = (SymIndex)i.next();
            if(actual.getScope().equals(s.getId())){
                if(actual.get_class() == C_ARRAY){
                    size += actual.getSize();
                }
                else
                    size++;
            }
        }
        return size;
    }
    
    /**Inserta un nuevo constructor a la tabla de simbolos*/
    public Symbol addConstructor(String id, String scope, int numParams, ArrayList params) throws Exception{
        // SI EL SIMBOLO NO EXISTE
        DataType t = new DataType(T_VOID);
        if(getSymbol(id,t,scope,SymTab.C_CONSTR,numParams) == null){
            //creamos nueva simbolo funcion
            Symbol s = new Symbol();
            s.set_class(SymTab.C_CONSTR);
            s.setType(t);
            s.setId(id);
            s.setSize(numParams);
            s.setContents(params);
            s.setScope(scope);
            s.setAccess(SymTab.A_PUBLIC);
            // Insertamos en la tabla
            this.table.put(lookFor,s);
            lookFor = new SymIndex();
            return s;
        }
        else
            throw new Exception("No se puede declarar constructor, ya existe un constructor igual");
    }
    
    /**Inserta un nuevo constructor a la tabla de simbolos*/
    public Symbol addFunction(String id, String scope, DataType dt, int numParams, ArrayList params, int currAccess) throws Exception{
        // SI EL SIMBOLO NO EXISTE
        if(getSymbol(id,dt,scope,SymTab.C_FUNC,numParams) == null){
            //creamos nueva simbolo funcion
            
            
            Symbol s = new Symbol();
            s.set_class(SymTab.C_FUNC);
            s.setType(dt);
            s.setId(id);
            s.setSize(numParams);
            s.setContents(params);
            s.setScope(scope);
            s.setAccess(currAccess);
            // Insertamos en la tabla
            TuplaSS newTs = new TuplaSS(id,scope);
            this.IdxFunctions.put(newTs,s);
            this.table.put(lookFor,s);
            lookFor = new SymIndex();
            return s;
        }
        else
            throw new Exception("No se puede declarar funcion, ya existe una funcion igual");
    }
    
    /**Inserta variables a la tabla de simbolos*/
    public Symbol addVariables(ArrayList ids, String scope, DataType dt, int currAccess,int shift) throws Exception{
        // recorremos cada variable de la lista en busqueda si existen
        if(dt == null || (dt.getType() !=SymTab.T_INT && dt.getType() != SymTab.T_CHAR && dt.getType() !=SymTab.T_STRING && dt.getType() !=SymTab.T_BOOL && dt.getType() !=SymTab.T_FLOAT && dt.getType() !=SymTab.T_TYPEDEF)){
            throw new Exception("Imposible declarar variable, esto no es una variable valida"); 
        }
        Iterator i = ids.iterator();      
        Symbol ret = null;
        boolean tst = true;
        int counter = 0;
//        boolean tst = lookFor.equals(new SymIndex(lookFor)); //new SymIndex(null,int, new String(tst), )
        while(i.hasNext()){            
            String id = (String) i.next();
            /// Si es una instancia
            int size;
            if(dt.getType() == C_OBJECT)                
                //Obtenemos tamano del tipo de dato
                size = sizeOfClass(dt);
            else
                size = sizeOf(dt);
            // Buscamos existencia del simbolo
            if(getSymbol(id,dt,scope,SymTab.C_VAR, size) == null){
                //creamos nueva simbolo funcion
                Symbol s = new Symbol();
                s.set_class(SymTab.C_VAR);
                s.setType(dt);
                s.setId(id);
                s.setSize(size);
                s.setPosition(shift + counter);
                //s.setContents(params);
                s.setScope(scope);
                // Insertamos en la tabla
                TuplaSS newTs = new TuplaSS(id,scope);
                this.IdxVariables.put(newTs,s);
                this.table.put(lookFor,s);
                lookFor = new SymIndex();
                ret = s;
                counter++;
            }
            else
                throw new Exception("No se puede declarar variable, ya existe una variable igual");
        }
        return ret;
    }
    
    /**Inserta punteros a la tabla de simbolos*/
    public Symbol addPointers(ArrayList ids, String scope, DataType dt, int currAccess, int shift) throws Exception{
        Iterator i = ids.iterator();
        dt.setReference(true);
        Symbol ret= null;
        int counter = 0;
        while(i.hasNext()){            
            String id = (String) i.next();
            
            //Obtenemos tamano del tipo de dato
            int size = sizeOf(dt);
            if(getSymbol(id,dt,scope,SymTab.T_REFERENCE, size) == null){
                //creamos nueva simbolo funcion
                Symbol s = new Symbol();
                s.set_class(SymTab.T_REFERENCE);
                s.setType(dt);
                s.setId(id);
                s.setSize(size);
                //s.setContents(params);
                s.setScope(scope);
                s.setPosition(shift + counter);
                ret = s;
                // Insertamos en la tabla
                TuplaSS newTs = new TuplaSS(id,scope);
                this.IdxVariables.put(newTs,s);
                this.table.put(lookFor,s);
                lookFor = new SymIndex();
            }
            else
                throw new Exception("No se puede declarar puntero, ya existe una variable igual");
        }
        return ret;
    }
    
    /**Inserta arreglos n-dimensionales a la tabla de simbolos*/
    public Symbol addArray(String id, ArrayList listaIndices, String scope, DataType dt, int currAccess,int shift) throws Exception{
        //throw new UnsupportedOperationException("Not Yet Implemented");
        int size = 1;
        Iterator i = listaIndices.iterator();
        ArrElem ae;
        // Calculamos tamano de arreglo
        while(i.hasNext()){
            ae = (ArrElem) i.next();
            size *= (ae.getTo() - ae.getFrom());
        }
        
        dt.setReference(true);
        if (getSymbol(id,dt,scope,SymTab.C_ARRAY, size) == null) {
                //creamos nueva simbolo funcion
                Symbol s = new Symbol();
                s.set_class(SymTab.C_ARRAY);
                s.setType(dt);
                s.setId(id);
                s.setSize(size);
                s.setContents(listaIndices);
                s.setScope(scope);
                s.setPosition(shift);
                // Insertamos en la tabla
                TuplaSS newTs = new TuplaSS(id,scope);
                this.IdxVariables.put(newTs,s);
                this.table.put(lookFor,s);
                lookFor = new SymIndex();
                return s;
        }
        else
            throw new Exception("No se puede declarar puntero, ya existe una variable igual");
    }
    
    /**Inserta una clase a la tabla de simbolos*/
    public Symbol addClass(String id, String scope) throws Exception {
        
        DataType dt = new DataType(C_CLASS);
        //Obtenemos tamano del tipo de dato
        int size = 2;
        if(getSymbol(id,dt,scope,SymTab.C_CLASS, 0) == null){
            
            //creamos nueva simbolo funcion
            Symbol s = new Symbol();
            s.set_class(SymTab.C_CLASS);
            s.setType(dt);
            s.setId(id);
            s.setSize(0);
            //s.setContents(params);
            s.setScope(scope);
            // Insertamos en la tabla
            TuplaSS newTs = new TuplaSS(id,scope);
            this.IdxClasses.put(newTs,s);
            this.table.put(lookFor,s);
            lookFor = new SymIndex();
            return s;
        }
        else
            throw new Exception("Declaracion de clase invalida, ya existe otra clase con el mismo nombre");

    }
    
    /**Busca un simbolo por cada uno de sus campos*/
    public Symbol getSymbol( String id, DataType dt, String scope, int cls,int size) {
        /*lookFor.setId(id);
        lookFor.setType(dt);
        lookFor.setScope(scope);
        lookFor.set_class(cls);
        lookFor.setSize(size);
        
        return this.table.get(lookFor);*/
        TuplaSS newTs = new TuplaSS(id,scope);
        switch (cls) {
            case C_FUNC:
            case C_PROC:
            case C_CONSTR:                
                return this.IdxFunctions.get(newTs);
            case C_VAR:
            case C_ARRAY:                
            case C_OBJECT:               
                return this.IdxVariables.get(newTs);
            case C_CLASS:
            case C_STRUCT:
            case C_UNION:
                return this.IdxClasses.get(newTs);
        }
        return null;
        
    }
    
    /**Busca un simbolo por indice de symbolo dado*/
    public Symbol getSymbol(SymIndex s) {
        return this.table.get(s);
    }
    
    /**Busca y devuelve una variable*/ 
    public Symbol getVar(String id, String scope){
        TuplaSS newTs = new TuplaSS(id,scope);
        return IdxVariables.get(newTs);
    }
    
    /**Busca y devuelve un objeto*/ 
    public Symbol getObj(String id, String scope){        
        TuplaSS newTs = new TuplaSS(id,scope);
        return IdxVariables.get(newTs);
    }
    
    /**Busca y devuelve un objeto*/ 
    public Symbol getFunc(String id, String scope){        
        TuplaSS newTs = new TuplaSS(id,scope);
        return IdxFunctions.get(newTs);
    }
    
    /**Devuelve tamano unitario de cada tipo de datos, asumiendo como valor unitario el char*/
    public int sizeOf(DataType dt) {
        /**Si es puntero, tiene tamano de entero*/
        if (dt.isReference())
            return 2;
        /**Si es tipo de dato primitivo, tiene tamano de cada tipo de dato*/
        switch(dt.getType()){
            case T_BOOL:
                return 1;
            case T_CHAR:
                return 1;
            case T_INT:
                return 2;
            case T_FLOAT:
                return 4;
        }
        return 2;
    }
    
    /**Devuelve la suma del tamano de los campos de una clase*/
    public int sizeOfClass(DataType dt) throws Exception{        
        throw new Exception("Function not implemented yet ...");
    }

    /**Devuelve true si la funcion actual identificada con "function es miembro de la clase "clas"*/
    public boolean isMemberFunction(String function, String clas){
        DataType dt = new DataType(C_CLASS);
        TuplaSS clk = new TuplaSS(clas,"global");
        Symbol s = this.IdxClasses.get(clk);//getSymbol(clas,dt,"global",SymTab.C_CLASS, 0);
        Iterator i = table.keySet().iterator();
        SymIndex actual;
        int size = 0;
        TuplaSS fk = new TuplaSS(function,s.getId());
        Symbol sf = this.IdxFunctions.get(fk);//getSymbol(clas,dt,"global",SymTab.C_CLASS, 0);
        if (sf!= null){
            return true;
        }
       
//        while(s!= null && i.hasNext()){
//            actual = (SymIndex)i.next();
//            if(actual.getScope() == s.getId()){
//                if(actual.getId() == function)// && actual.get_class() == SymTab.C_FUNC){
//                    return true;
//                
//            }
//        }
        return false;
    }
        /**Compara tipos y devuelve true si es posible la realizacion de una operacion aritmetica entre estos*/
    public static boolean tiposCompatibles(int tipo1, int tipo2){
        if(tipo1==tipo2){
            return true;
        }
        if((tipo1 == SymTab.T_INT &&  tipo2== SymTab.T_CHAR) ||
                (tipo1 == SymTab.T_CHAR &&  tipo2== SymTab.T_INT) ||                
            (tipo1 == SymTab.T_INT &&  tipo2== SymTab.T_FLOAT) ||
                (tipo1 == SymTab.T_FLOAT &&  tipo2== SymTab.T_INT) ||
                 (tipo1 == SymTab.T_CHAR &&  tipo2== SymTab.T_FLOAT) ||
                (tipo1 == SymTab.T_FLOAT &&  tipo2== SymTab.T_CHAR))                
            return true;
        return false;
    }
}


/** Clave de un simbolo semantico para ser usada en indizacion basada en hash*/
class SymIndex{
    private DataType type = new DataType();/**Datatype*/
    private int _class;/**Symbol's Class*/
    private String id = new String();/**Symbol's Identifier*/
    private int size;/**Size of the Symbol*/
    private String scope = new String(); /**Scope of the symbol*/
    
    SymIndex(DataType t, int c, String i, int s, String sc){
        type = t;
        _class = c;
        id = i;
        size = s;
        scope = sc;
    }

    SymIndex(SymIndex s){
        type = s.getType();
        _class = s.get_class();
        id = s.getId();
        size = s.getSize();
        scope = s.getScope();
    }
    
    public String getId() {
        return id;
    }

    public int getSize() {
        return size;
    }

    public DataType getType() {
        return type;
    }

    public int get_class() {
        return _class;
    }

    public void setId(String id) {
        this.id = id;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public void setType(DataType type) {
        this.type = type;
    }

    public void set_class(int _class) {
        this._class = _class;
    }
    
    public boolean equals(Object o){
        if(o.getClass().equals(this.getClass())){
            /**Si es referencia, no tomamos en cuenta el tamano, si es valor, si*/
            //if((((SymIndex)o).type.isReference())){
                 return (//this._class == ((SymIndex)o)._class &&
                    this.id.equals(((SymIndex)o).id));// &&
                    //this.type.equals(((SymIndex)o).type) &&
                    //this.scope.equals(((SymIndex)o).scope));
            //}               
            //else{                
            //    return (this._class == ((SymIndex)o)._class &&
            //        this.id.equals(((SymIndex)o).id) &&
            //        this.size == ((SymIndex)o).size &&
            //        this.type.equals(((SymIndex)o).type) &&
            //        this.scope.equals(((SymIndex)o).scope));
            //}
        }
        return false;
    }

    public String getScope() {
        return scope;
    }

    public void setScope(String scope) {
        this.scope = scope;
    }
    
    SymIndex(){
    }

    
}

/**Simbolo semantico, representa una tupla en la tabla de simbolos*/
class Symbol extends SymIndex {
    private Object contents;// = new Object();
    private int position;
    private int access;
    
    Symbol(){
        
    }
    
    Symbol(DataType t, int cls){
        this.setType(t);
        this.set_class(cls);
    }

    public int getAccess() {
        return access;
    }

    public Object getContents() {
        return contents;
    }

    public int getPosition() {
        return position;
    }

    public void setAccess(int access) {
        this.access = access;
    }

    public void setContents(Object contents) {
        this.contents = contents;
    }

    public void setPosition(int position) {
        this.position = position;
    }

 
    
}

/** Clase que contiene una tupla que define el tipo de dato de un simbolo */
class DataType{
    private boolean reference = false; /**verdadero si el dato contenido es una referencia, falso si es una variable normal*/
    private int type = SymTab.T_VOID;/* Tipo de dato primitivo*/

    private String objType = new String(); /**Tipo de dato instancia*/
    
    public void setReference(boolean reference) {
        this.reference = reference;
    }
    /**Constructor por defecto*/
    DataType(){
        
    }
    /**Construye un nuevo tipo primitivo*/
    DataType(int t){
        type = t;
    }
    
    /**Construye un nuevo tipo instancia*/
    DataType(String s,boolean ref){
        type = SymTab.T_TYPEDEF;
        objType = new String(s);
        this.reference = ref;
    }
    
    /**Construye un nuevo tipo instancia @deprecated*/
    DataType(String s,boolean ref,int size){
        type = SymTab.T_TYPEDEF;
        objType = new String(s);
        this.reference = ref;
    }
    
    public boolean isReference() {
        return reference;
    }
    
    public boolean equals(Object o){
        if(this.getClass().equals(o.getClass())){
            if(     ((DataType)o).reference == this.reference &&
                    ((DataType)o).type == this.type &&
                    ((DataType)o).objType.equals(this.objType)
                    )
                return true;
        }
        return false;
    }

    /**Devuelve el tipo de dato del objeto*/
    public int getType() {
        return type;
    }

    public void setType(int type) {
        this.type = type;
    }
    /**Devuelve el nombre de la clase a la que pertenece la instancia*/
    public String getObjType() {
        return objType;
    }

    public void setObjType(String objType) {
        this.objType = objType;
    }
    
}   
/** Clase que contiene los rangos de un indice de una dimension de un array*/
class ArrElem{
    private int from = 0;
    private int to = 0;
    
    ArrElem(int f, int t){
        from = f;
        to = t; 
    }
    
    /**Devuelve limite inferior*/
    public int getFrom() {
        return from;
    }

    /**Devuelve limite superior*/
    public int getTo() {
        return to;
    }
}
/**Atributo usado para las expresiones en tiempo de analisis sintactico*/
class ExpAttribute{
    /**Cadena que se lleva como atributo*/
    private int tipo = -1; //tipo
    private String cad = new String();
    ExpAttribute(){
        
    }
      
    ExpAttribute(String c, int t){
        cad = c;
        tipo = t;
    }
    
    /**Devuelve cadena que se lleva como atributo*/
    public String getCad() {
        return cad;
    }
    /**Asigna cadena que se lleva como atributo*/
    public void setCad(String cad) {
        this.cad = cad;
    }
    
    public void setTipo(int tipo) {
        this.tipo = tipo;
    }
    
    public int getTipo() {
        return tipo;
    }
    
}