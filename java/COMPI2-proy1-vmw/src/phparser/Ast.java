/*
 * Ast.java
 *
 * Creada el 18 de marzo de 2007, 05:48 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package phparser;

import com.sun.org.apache.bcel.internal.generic.ASTORE;
import java.util.*;
import errormanager.*;
/**
 * Clase que representa un arbol de sintaxis abstracta para la interpretacion dinamica
 * del lenguaje dado
 * @author Erik Giron (200313492)
 *
 */
public class Ast {
    
    /**Constantes de tipos de nodo*/
    public static final int N_IF = 0;
    public static final int N_SYMTABENTRY = 1;
    public static final int N_LIT_STRING = 2;
    public static final int N_LIT_FLOAT = 3;
    public static final int N_LIT_INT= 4;
    public static final int N_OPARIT= 5;    
    public static final int N_OPCOMP= 6;
    public static final int N_OPCOND= 7;
    public static final int N_ASIGREF = 8;
    public static final int N_ASIGVAL = 9;
    public static final int N_WHILE = 10;
    public static final int N_CALL = 11;
    public static final int N_FUNC = 12;
    public static final int N_PARAMBYREF = 13;
    public static final int N_PARAMBYVAL = 14;
    public static final int N_PARAM = 15;
    public static final int OP_MAS = 100;
    public static final int OP_MENOS = 101;
    public static final int OP_MUL = 102;
    public static final int OP_DIV = 103;
    public static final int OP_OR = 104;
    public static final int OP_AND = 105;
    public static final int OP_GT = 106;
    public static final int OP_GTE = 107;
    public static final int OP_LT = 108;
    public static final int OP_LTE = 109;
    public static final int OP_EQ = 110;
    public static final int OP_NE = 111;
    
    
    public NodoAst raiz;//raiz del arbol ast actual;
    
    /** Crea una nueva instancia de Ast */
    public Ast() {
    }
    /**Devuelve raiz del arbol*/
    public NodoAst getRaiz() {
        return raiz;
    }
    /**Obtiene raiz del arbol*/
    public void setRaiz(NodoAst raiz) {
        this.raiz = raiz;
    }
    
    /**Recorre arbol y ejecuta instrucciones en ese*/
    public void recorrer() throws Exception{
        throw new UnsupportedOperationException();
    }
    
    /**Crea un nuevo nodo, enlazandole los nodos izq y der dados como parametros*/
    public static NodoAst crearNodo(int tipo, NodoAst izq, NodoAst der,Object value, int operator){
        NodoAst nuevo = new NodoAst(tipo, izq,der, value, operator);
        return nuevo;
    }
    
    /**Ejecuta una expresion aritmetica y devuelve su resultado*/
    public static ResultSet ejecutarExpresion(NodoAst nodo, String ambito) throws Exception{
        ResultSet ret = null, r1 = null, r2 = null;
        
        /**Si el nodo no es hoja*/
        if(nodo.getLeft() != null && nodo.getRight() != null){
            if(nodo.getLeft() != null){
                r1 = ejecutarExpresion(nodo.getLeft(),ambito);
            }
            if(nodo.getRight() != null){
                r2 = ejecutarExpresion(nodo.getRight(),ambito);
            }
            /**Ejecutamos accion*/
            if(r1 != null && r2 != null){
                /**Si cualquiera de los resultados es de tipo string, la respuesta sera string*/
                if(r1.getTipo() == Ast.N_LIT_STRING || r2.getTipo() == Ast.N_LIT_STRING){
                    // si r1 es string, convertimos a string el r2
                    if(r1.getTipo() == Ast.N_LIT_STRING && r2.getTipo() != Ast.N_LIT_STRING){
                        convertirAString(r2);
                    }
                    else if (r2.getTipo() == Ast.N_LIT_STRING && r1.getTipo() != Ast.N_LIT_STRING){
                        convertirAString(r1);
                    }
                    /// Tomamos en cuenta que solo se puede realizar la concatenacion entre cadenas
                    if(nodo.getOperator() == Ast.OP_MAS){
                        ret = new ResultSet(N_LIT_STRING,new String(
                            (String)r1.getData() + 
                            (String)r2.getData()));
                    }
                    else
                        throw new Exception("Imposible evaluar expresion, solo se  permite la concatenacion de cadenas");
                }
                /** Si son tipos numericos, se toman como Floats ambos si alguno es float (upcast)*/
                else{
                    int tipoactual;
                    if(r1.getTipo() == Ast.N_LIT_INT && r2.getTipo() != Ast.N_LIT_INT){
                        tipoactual = Ast.N_LIT_INT;
                    }
                    else
                        tipoactual = Ast.N_LIT_FLOAT;
                    //Hacemos la operacion de concatenacion
                    ret = operacionNumerica(r1, r2, nodo.getOperator(),tipoactual);
                }
            }
            else
                throw new Exception("Imposible evaluar la expresion en nodo " + nodo.toString() + ", el nodo debe tener dos hijos");
        }
        /**Si es nodo hoja, evaluamos*/
        else{
            if(nodo.getLeft() == null && nodo.getRight() == null){
                /**Si el nodo no es una variable o una llamada a funcion, obtenemos el valor de la literal*/
                if(nodo.tipo != Ast.N_SYMTABENTRY && nodo.tipo != Ast.N_CALL)
                    ret = new ResultSet(nodo.getTipo(),nodo.getData());
                else if (nodo.tipo == Ast.N_SYMTABENTRY){ // sino, obtenemos valor de la tabla de simbolos
                    SymTab.SymTabEntry s = PhParser.getTablaSimbolos().get((String)nodo.getData());
                    ret = new ResultSet(s.getTipo(),s.getValor());
                }
                else if(nodo.tipo == Ast.N_CALL){ // sino, evaluamos la funcion
                    NodoAst a = ejecutarFuncion(nodo,ambito);
                    ret = ejecutarExpresion(a,ambito);
                    
                }
                    
            }
            else
                throw new Exception("Expresion invalida, se debe tener por lo menos 2 operandos");
        }
        return ret;
    }
    
    /**Convierte un numero a float*/
    private static void convertirAFloat(ResultSet r2) throws Exception {
        Float val = null;
        if(r2 != null){
            if(r2.getTipo() == Ast.N_LIT_INT){
                  val = new Float(((Integer)r2.getData()).floatValue());
            }/**Si es cadena, la convertimos a float*/
            else if (r2.getTipo() == Ast.N_LIT_STRING){
                val = new Float((Float.parseFloat((String)r2.getData())));
            }
            else if(r2.getTipo() == Ast.N_LIT_FLOAT){
                  val = ((Float)r2.getData()).floatValue();
            }
            else{
                throw new Exception("Imposible hacer la conversion, tipo no valido");
            }
            r2.setTipo(Ast.N_LIT_FLOAT);
            r2.setData(val);
        }
        else{
            throw new Exception("Imposible hacer la conversion, el resultset es nulo");
        }
        
    }
    
    /**Convierte a string un resultSet*/
    private static void convertirAString(ResultSet r2) throws Exception  {
        String val = null;
        if(r2 != null){
            if(r2.getTipo() == Ast.N_LIT_INT){
                  val = new String(((Integer)r2.getData()).toString());
            }/**Si es cadena, la convertimos a float*/
            else if (r2.getTipo() == Ast.N_LIT_FLOAT){
                val = new String(((Float)r2.getData()).toString());
            }
            else if (r2.getTipo() == Ast.N_LIT_STRING){
                val = (String)r2.getData();
            }
            else{
                throw new Exception("Imposible hacer la conversion, tipo no valido");
            }
            r2.setTipo(Ast.N_LIT_STRING);
            r2.setData(val);
        }
        else{
            throw new Exception("Imposible hacer la conversion, el resultset es nulo");
        }
        
    }
    
    /**Realiza una operacion aritmetica entre numeros*/
    private static ResultSet operacionNumerica(ResultSet r1, ResultSet r2, int operador, int tipo) throws Exception {
        ResultSet ret;
        //convertimos a float ambos valores
        convertirAFloat(r1);
        convertirAFloat(r2);
        //operamos
        switch(operador){
            case Ast.OP_MAS:
                ret = new ResultSet(N_LIT_FLOAT,new Float(
                            ((Float)r1.getData()).floatValue() + 
                            ((Float)r2.getData()).floatValue()));
                break;
            case Ast.OP_MENOS:
                ret = new ResultSet(N_LIT_FLOAT,new Float(
                            ((Float)r1.getData()).floatValue() - 
                            ((Float)r2.getData()).floatValue()));
                break;
            case Ast.OP_MUL:
                ret = new ResultSet(N_LIT_FLOAT,new Float(
                            ((Float)r1.getData()).floatValue() * 
                            ((Float)r2.getData()).floatValue()));
                break;
            case Ast.OP_DIV:
                if(((Float)r2.getData()).floatValue() != 0)
                    ret = new ResultSet(N_LIT_FLOAT,new Float(
                            ((Float)r1.getData()).floatValue() / 
                            ((Float)r2.getData()).floatValue()));
                else
                    throw new Exception("Imposible evaluar expresion, Division entre 0");
                break;
            default:
                throw new Exception("Imposible evaluar expresion numerica, operador invalido");
        }
        // Si los dos operandos son int devolvemos int, sino devolvemos dato float
        if(tipo == Ast.N_LIT_INT){
            convertirAInt(ret);
            return ret;
        }
        return ret;
    }
    /**Crea un nuevo nodo para la sentencia if*/
    public static NodoAst crearNodoIf(int tipo, NodoAst cond, LinkedList sTrue, LinkedList sFalse) {
        NodoAst nuevo = new NodoAst(tipo, cond, null, null, -1);
        nuevo.setSentenciasTrue(sTrue);
        nuevo.setSentenciasFalse(sFalse);
        return nuevo;
    }
    
    /**Crea un nuevo nodo de sentencia de asignacion/declaracion*/
    public static NodoAst crearNodoAsignacion(int tipo, NodoAst operacion, String var1, String var2){
        NodoAst nuevo = new NodoAst(tipo, operacion, null, var1, -1);
        nuevo.setAux(var2);
        return nuevo;
    }
    
    /**ejecuta sentencia de asignacion de valor*/
    public static ResultSet asignarValor(NodoAst sentencia, String ambito) throws Exception{        
        ResultSet resultado = Ast.ejecutarExpresion(sentencia.getLeft(),ambito);
	if(PhParser.getTablaSimbolos().get((String)sentencia.getData()) == null){
            PhParser.getTablaSimbolos().insertarVariable((String)sentencia.getData(),resultado.getTipo(),ambito,resultado.getData());
        }
        else{
            PhParser.getTablaSimbolos().updateVariable((String)sentencia.getData(),resultado.getTipo(),ambito,resultado.getData());
        }
        return resultado;
    }
    
    /**ejecuta sentencia de asignacion de referencia*/
    public static void asignarReferencia(NodoAst sentencia, String ambito) throws Exception{
        if(PhParser.getTablaSimbolos().get((String)sentencia.getAux()) != null)
            PhParser.getTablaSimbolos().insertarReferencia((String)sentencia.getData(),(String)sentencia.getAux());
        else{
                ErrorManager.agregarErrorSemantico(-1,-1,"Imposible referenciar variable " + (String)sentencia.getAux() + ", no existe.");
                throw new Exception("Imposible referenciar variable " + (String)sentencia.getAux() + ", no existe.");
        }
    }
    
    /**Ejecuta una sentencia if*/
    public static void ejecutarIf(NodoAst sentenciaIf, String ambito) throws Exception{
        boolean condicion;
        if (sentenciaIf.getTipo() == N_IF){
            condicion = evaluarCondicion(sentenciaIf.getLeft(),ambito);
            if(condicion == true){
                ejecutarSentencias(sentenciaIf.getSentenciasTrue(),ambito);
            }
            else{
                if (sentenciaIf.getSentenciasFalse() != null)
                    ejecutarSentencias(sentenciaIf.getSentenciasFalse(),ambito);                
            }
        }
        else
            throw new Exception("Imposible evaluar sentencia, no es una condicion if.");
    }
    
    /**Evalua una condicion AND o OR*/
    public static boolean evaluarCondicion(NodoAst nodo, String ambito) throws Exception{
        boolean ret, a1, a2;
        if(nodo.getTipo() == N_OPCOND){
            /**Si los nodos izquierdo y derecho existen*/
            if(nodo.getLeft()!= null && nodo.getRight() != null){
                a1 = evaluarCondicion(nodo.getLeft(),ambito);
                a2 = evaluarCondicion(nodo.getRight(),ambito);
                if(nodo.operator == OP_AND){
                    return (a1 && a2);
                }
                else if (nodo.operator == OP_OR){
                    return (a1 || a2);
                }
                else
                    throw new Exception ("Imposible evaluar condicional, operador invalido.");
            }
            else{
                throw new Exception ("Imposible evaluar condicional, falta algun operando.");
            }
        }
        else if (nodo.getTipo() == N_OPCOMP){
            ret = evaluarComparacion(nodo,ambito);
            return ret;
        }
        else{
            throw new Exception ("Imposible evaluar condicional, la expresion no es booleana.");
        }
        
    }
    /**Evalua un arbol que contiene expresion comparativa con == != < <= > >=*/
    private static boolean evaluarComparacion(NodoAst nodo, String ambito) throws Exception {
        boolean ret, a1 = false, a2 = false;
        ResultSet valor1 = null, valor2 = null;
        if(nodo.getTipo() == N_OPCOMP){
            /**Si los nodos izquierdo y derecho existen*/
            if(nodo.getLeft()!= null && nodo.getRight() != null){
                if(nodo.getLeft().tipo == N_OPCOMP)
                    a1 = evaluarComparacion(nodo.getLeft(),ambito);                
                else if(nodo.getLeft().tipo == N_OPARIT 
                        || nodo.getLeft().tipo == N_LIT_FLOAT
                        || nodo.getLeft().tipo == N_LIT_STRING
                        || nodo.getLeft().tipo == N_LIT_INT
                        || nodo.getLeft().tipo == N_SYMTABENTRY){
                    valor1 = ejecutarExpresion(nodo.getLeft(),ambito);
                }
                else
                    throw new Exception("Imposible evaluar comparacion, las subexpresiones son invalidas.");
                    
                if(nodo.getRight().tipo == N_OPCOMP)
                    a2 = evaluarComparacion(nodo.getRight(),ambito);                
                else if(nodo.getRight().tipo == N_OPARIT 
                        || nodo.getRight().tipo == N_LIT_FLOAT
                        || nodo.getRight().tipo == N_LIT_STRING
                        || nodo.getRight().tipo == N_LIT_INT
                        || nodo.getRight().tipo == N_SYMTABENTRY){                    
                    valor2 = ejecutarExpresion(nodo.getRight(),ambito);
                }
                else
                    throw new Exception("Imposible evaluar comparacion, las subexpresiones son invalidas.");
                
                if(valor1 != null && valor2 != null){
                    return compararResultSets(valor1, valor2,nodo.getOperator());
                }
                else if(valor1 == null && valor2 == null){
                        if(nodo.operator == OP_EQ){
                            return (a1 == a2);
                        }
                        else if(nodo.operator == OP_NE){
                            return (a1 != a2);
                        }
                        else
                            throw new Exception ("Imposible evaluar comparacion, la expresion debe de ser aritmetica.");
                }
                else{
                    throw new Exception ("Imposible evaluar comparacion, la expresion debe de ser aritmetica.");
                        
                }  
            }
            else
                throw new Exception ("Imposible evaluar comparacion, falta algun operando.");
        }        
        else{
            throw new Exception ("Imposible evaluar comparacion, la expresion es invalida.");
        }
    }
    
    /**Aplica operadores comparativos a dos resultsets*/
    private static boolean compararResultSets(ResultSet valor1, ResultSet valor2, int operator) throws Exception {
        if(valor1!= null && valor2 != null){
            if (valor1.getTipo() == valor2.getTipo()){
                switch (operator){
                    case Ast.OP_EQ:
                        switch(valor1.getTipo()){
                            case Ast.N_LIT_STRING:
                                return ((String)valor1.getData()).equals((String)valor2.getData());                                
                            case Ast.N_LIT_FLOAT:
                                return ((Float)valor1.getData()).equals((Float)valor2.getData());                                
                            case Ast.N_LIT_INT:
                                return ((Integer)valor1.getData()).equals((Integer)valor2.getData());                                
                            default:
                                throw new Exception("Imposible evaluar operacion comparativa, el tipo de dato es invalido");
                        }
                    case Ast.OP_NE:
                        switch(valor1.getTipo()){
                            case Ast.N_LIT_STRING:
                                return !((String)valor1.getData()).equals((String)valor2.getData());                                
                            case Ast.N_LIT_FLOAT:
                                return !((Float)valor1.getData()).equals((Float)valor2.getData());                                
                            case Ast.N_LIT_INT:
                                return !((Integer)valor1.getData()).equals((Integer)valor2.getData());
                            default:
                                throw new Exception("Imposible evaluar operacion comparativa, el tipo de dato es invalido");
                        }
                    case Ast.OP_LT:
                        switch(valor1.getTipo()){                            
                            case Ast.N_LIT_FLOAT:
                                return (((Float)valor1.getData()).floatValue() < ((Float)valor2.getData()).floatValue());                                
                            case Ast.N_LIT_INT:
                                return (((Integer)valor1.getData()).floatValue() < ((Integer)valor2.getData()).floatValue());
                            default:
                                throw new Exception("Imposible evaluar operacion comparativa, el tipo de dato es invalido");
                        }
                    case Ast.OP_LTE:
                        switch(valor1.getTipo()){                            
                            case Ast.N_LIT_FLOAT:
                                return (((Float)valor1.getData()).floatValue() <= ((Float)valor2.getData()).floatValue());
                            case Ast.N_LIT_INT:
                                return (((Integer)valor1.getData()).floatValue() <= ((Integer)valor2.getData()).floatValue());
                            default:
                                throw new Exception("Imposible evaluar operacion comparativa, el tipo de dato es invalido");
                        }
                    case Ast.OP_GT:
                        switch(valor1.getTipo()){                            
                            case Ast.N_LIT_FLOAT:
                                return (((Float)valor1.getData()).floatValue() > ((Float)valor2.getData()).floatValue());
                            case Ast.N_LIT_INT:
                                return (((Integer)valor1.getData()).floatValue() > ((Integer)valor2.getData()).floatValue());
                            default:
                                throw new Exception("Imposible evaluar operacion comparativa, el tipo de dato es invalido");
                        }
                    case Ast.OP_GTE:
                        switch(valor1.getTipo()){                            
                            case Ast.N_LIT_FLOAT:
                                return (((Float)valor1.getData()).floatValue() >= ((Float)valor2.getData()).floatValue());
                            case Ast.N_LIT_INT:
                                return (((Integer)valor1.getData()).floatValue() >= ((Integer)valor2.getData()).floatValue());
                            default:
                                throw new Exception("Imposible evaluar operacion comparativa, el tipo de dato es invalido");
                        }
                    default:
                        throw new Exception("Imposible evaluar operacion comparativa, el operador es invalido");
                }
                
            }
            return false;
        }
        return false;
    }
    
    /**Ejecuta sucesivamente un listado de sentencias*/
    private static void ejecutarSentencias(LinkedList<NodoAst> al,String ambito) throws Exception{
        Iterator i;
        NodoAst s;
        if(al!= null){
            i = al.iterator();
            while (i.hasNext()){
                s = (NodoAst) i.next();
                ejecutarSentencia(s,ambito);
            }
        }
        else
            throw new Exception("Imposible evaluar sentencias, no se ha asignado ninguna");
    }
    /**Ejecuta un nodo sentencia*/
    private static void ejecutarSentencia(NodoAst s, String ambito) throws Exception{
        if(s != null){
            switch(s.tipo){
                case (Ast.N_IF):
                    ejecutarIf(s,ambito);
                    break;
                case (Ast.N_ASIGREF):
                    asignarReferencia(s,ambito);
                    break;
                case (Ast.N_ASIGVAL):
                    asignarValor(s,ambito);
                    break;
                case (Ast.N_WHILE):
                    ejecutarWhile(s,ambito);
                    break;
                    //throw new UnsupportedOperationException("While todavia no implementado");
                case (Ast.N_CALL):
                    ejecutarFuncion(s,ambito);
                    break;
                    //throw new UnsupportedOperationException("Llamadas a funciones aun no implementadas");
                default:
                    throw new Exception("Imposible evaluar sentencia, sentencia invalida.");
            }
        }
        else{
            throw new Exception("Imposible evaluar sentencia, el nodo no existe");
        }
        
    }
    /**Ejecuta una sentencia while*/
    public static int ejecutarWhile(NodoAst sentenciaWhile, String ambitoActual) throws Exception {
        boolean condicion;
        if (sentenciaWhile.getTipo() == N_WHILE){
            //condicion = evaluarCondicion(sentenciaIf.getLeft(),ambito);
            while((condicion = evaluarCondicion(sentenciaWhile.getLeft(),ambitoActual)) == true){
                ejecutarSentencias(sentenciaWhile.getSentenciasTrue(),ambitoActual);
            }
            return 0;
            //if(condicion == true){
            //    ejecutarSentencias(sentenciaIf.getSentenciasTrue(),ambito);
            //}
            //else{
             //   if (sentenciaIf.getSentenciasFalse() != null)
             //       ejecutarSentencias(sentenciaIf.getSentenciasFalse(),ambito);                
           // }
        }
        else
            throw new Exception("Imposible evaluar sentencia, no es una condicion if.");
    }
    
    /**Crea un nodo AST para la sentencia while*/
    public static NodoAst crearNodoWhile(int tipo, NodoAst cond, LinkedList<NodoAst> sTrue) {
        NodoAst nuevo = new NodoAst(tipo, cond, null, null, -1);
        nuevo.setSentenciasTrue(sTrue);
        nuevo.setSentenciasFalse(null);
        return nuevo;
    }
    
    /**Crea un nuevo nodo de funcion*/
    public static NodoAst crearNodoFuncion(int tipo, String nombre, LinkedList<NodoAst> lparam, LinkedList<NodoAst> lsent, NodoAst ret) {
        NodoAst nuevo = new NodoAst(tipo, ret, null, null, -1);
        nuevo.setSentenciasTrue(lsent); // asignamos cuerpo del programa
        nuevo.setSentenciasFalse(lparam); // asignamos listado de parametros
        //insertamos funcion a la tabla de simbolos
        PhParser.getTablaSimbolos().insertarFuncion(nombre,nuevo);
        return nuevo;
    }
    /**Crea un nuevo nodo de parametro de funcion*/
    public static NodoAst crearNodoParam(int tipo, String id, NodoAst li) {
        NodoAst nuevo = new NodoAst(tipo, li, null, id, -1);
        return nuevo;
    }
    
    /**Crea un nuevo nodo de llamada a funcion*/
    public static NodoAst crearNodoCallFunc(int tipo, String id, LinkedList<NodoAst> args) {
        NodoAst nuevo = new NodoAst(tipo, null, null, id, -1);
        nuevo.setSentenciasTrue(args); // asignamos argumentos
        return nuevo;
    }
    
    /**Ejecuta una funcion y devuelve un nodo de expresion aritmetica*/
    public static NodoAst ejecutarFuncion(NodoAst nodo, String ambito) throws Exception{
        ResultSet ret;
        String nombreFunc = (String)(nodo.getData());
        //Guardamos tabla de simbolos anterior
        SymTab anterior = PhParser.getTablaSimbolos();
        
        
        if(nombreFunc.equals("@get")){ // si es funcion de get, ejecutamos el get
            return ejecutarGetCall();
        }
        else if (nombreFunc.equals("@echo")){ // si es funcion echo, ejecutamos echo
            ejecutarEchoCall(nodo.getSentenciasTrue(),ambito);
            return null;
        }
        else if( PhParser.getTablaSimbolos().get(nombreFunc) != null){ // si es funcion de usuario, la ejecutamos
            
            //obtenemos nodo de Funcion
            NodoAst funcion = PhParser.getTablaSimbolos().get(nombreFunc).getPNodo();
            // creamos nueva tabla y la asignamos como principal        
            SymTab nuevo = new SymTab();
            PhParser.setTablaSimbolos(nuevo);            
            // Evaluamos la funcion
            try{         
                //Agregamos funciones de la tabla anterior a nueva tabla de simbolos
                nuevo.insertarFunciones(anterior);
                //Asignamos parametros a nodo funcion y agregamos a tabla de simbolos
                asignarParametros(funcion.getSentenciasFalse(),nodo.getSentenciasTrue(),anterior,ambito);
                //Ejecutamos sentencias de la funcion
                ejecutarSentencias(funcion.getSentenciasTrue(),ambito);
                //Ejecutamos sentencia de retorno si existe;
                if(funcion.getLeft() != null){
                    ret = ejecutarExpresion(funcion.getLeft(),ambito);
                    PhParser.setTablaSimbolos(anterior);
                    return crearNodo(ret.getTipo(),null,null,ret.getData(),-1);
                }
                PhParser.setTablaSimbolos(anterior);
            }
            catch (Exception e){
                //devolvemos tabla de simbolos anterior
                PhParser.setTablaSimbolos(anterior);
                throw e;
            }
            finally{
                //devolvemos tabla de simbolos anterior
                PhParser.setTablaSimbolos(anterior);
            }
        }
        else
            throw new Exception("Funcion \"" + nombreFunc + "\" no existe");
        return null;
    }
    /**Asocia los argumentos de una llamada de una funcion con los parametros de la misma*/
    private static void asignarParametros(LinkedList<NodoAst> params, LinkedList<NodoAst> args, SymTab old,String ambito) throws Exception{
        //contamos que los argumentos sean <= que los parametros de la funcion
        NodoAst paramActual, argActual;
        Iterator i, j;
        ResultSet rt = null;
        if(args.size() <= params.size()){
            //para cada parametro, asociamos cada uno con los argumentos y los metemos a la tabla de simbolos
            i = params.iterator();
            j = args.iterator();
            while(i.hasNext()){
                paramActual = (NodoAst)(i.next());
                //Asociamos cada parametro con su argumento cuando todavia tengamos, para meterlo en la tabla
                if(j.hasNext()){ 
                    argActual = (NodoAst)(j.next());
                    asociarParametros(paramActual, argActual, old, ambito);
                }
                // Si se nos terminan los argumentos, asociamos parametros con su valor por defecto y lo zampamos a la tabla de simbolo
                else{
                    if(paramActual.getLeft().getTipo() == Ast.N_LIT_FLOAT
                            || paramActual.getLeft().getTipo() == Ast.N_LIT_STRING
                            || paramActual.getLeft().getTipo() == Ast.N_LIT_INT
                            ){
                        rt = ejecutarExpresion(paramActual.getLeft(),ambito);
                        PhParser.getTablaSimbolos().insertarVariable((String)paramActual.getData(),rt.getTipo(),ambito,rt.getData());
                    }
                    else{
                        throw new Exception("El valor por default del parametro " + (String)paramActual.getData() + " debe ser un string, entero, float");
                    }
                }
                   
            }
        }
        else
            throw new Exception("Numero de parametros invalidos");
       
    }
    /**Asocia individualmente un argumento con su parametro, y los ingresa a la tabla de simbolos*/
    private static void asociarParametros(NodoAst paramActual, NodoAst argActual, SymTab old,String ambito) throws Exception {
        ResultSet rt;
        SymTab anterior;
        if(argActual.getTipo() == Ast.N_PARAMBYREF){ // si queremos asociar parametros por referencia
            //if(argActual.getTipo() == Ast.N_SYMTABENTRY)
            //PhParser.getTablaSimbolos().insertarReferencia((String)paramActual.getData(),(String)argActual.getData());
            PhParser.getTablaSimbolos().insertarReferenciaParametro((String)paramActual.getData(),(String)argActual.getData(), old);
            //else
            //    throw new Exception("Imposible asignar parametro, el tipo de parametro acepta solo argumentos que sean referencias a variables");
        }
        else if(argActual.getTipo() == Ast.N_PARAMBYVAL){
            /**Usamos tabla de simbolos anterior para evaluar parametros*/
            anterior = PhParser.getTablaSimbolos();
            PhParser.setTablaSimbolos(old);
            /**evaluamos parametro*/
            rt = ejecutarExpresion(argActual.getLeft(),ambito);
            /*regresamos a nuestra tabla actual*/
            PhParser.setTablaSimbolos(anterior);
            /**Insertamos parametro en tabla actual*/
            PhParser.getTablaSimbolos().insertarVariable((String)paramActual.getData(),rt.getTipo(),ambito,rt.getData());
        }
        else{
            throw new Exception("Imposible asignar, ya que el nodo no es un parametro.");
        }

        
//        if(paramActual.getTipo() == Ast.N_PARAMBYREF){ // si queremos asociar parametros por referencia
//            if(argActual.getTipo() == Ast.N_SYMTABENTRY)
//                PhParser.getTablaSimbolos().insertarReferencia((String)paramActual.getData(),(String)argActual.getData());
//            else
//                throw new Exception("Imposible asignar parametro, el tipo de parametro acepta solo argumentos que sean referencias a variables");
//        }
//        else if(paramActual.getTipo() == Ast.N_PARAMBYVAL){
//            rt = ejecutarExpresion(argActual,ambito);
//            PhParser.getTablaSimbolos().insertarVariable((String)paramActual.getData(),rt.getTipo(),ambito,rt.getData());
//        }
//        else{
//            throw new Exception("Imposible asignar, ya que el nodo no es un parametro.");
//        }
    }
    /**Ejecuta una llamada a la funcion nativa get*/
    private static NodoAst ejecutarGetCall() {
        GetFrame g = new GetFrame();
        g.setVisible(true);
        while(g.isVisible()){
        }
        return g.getRet();
    }
    /**Ejecuta una llamada a la funcion nativa Echo*/
    private static void ejecutarEchoCall(LinkedList<NodoAst> operatoria,String ambito) throws Exception {
        ResultSet r;
        if (operatoria != null){
            if(operatoria.size() == 1){
                r = ejecutarExpresion(operatoria.getFirst(), ambito);
                PhParser.escribirMensaje("PHParser: " + r.toString());
            }
            else
                throw new Exception("Error, Parametros invalidos para llamada de echo");
        }
        else
            throw new Exception("Error, Parametros invalidos para llamada de echo");
    }

    private static void convertirAInt(ResultSet r2) throws Exception{
        Integer val = null;
        if(r2 != null){
            if(r2.getTipo() == Ast.N_LIT_FLOAT){
                  val = new Integer(((Float)r2.getData()).intValue());
            }/**Si es cadena, la convertimos a float*/
            else if (r2.getTipo() == Ast.N_LIT_STRING){
                val = new Integer((Integer.parseInt((String)r2.getData())));
            }
            else if(r2.getTipo() == Ast.N_LIT_INT){
                  val = ((Integer)r2.getData()).intValue();
            }/**Si es cadena, la convertimos a float*/
            else{
                throw new Exception("Imposible hacer la conversion, tipo no valido");
            }
            r2.setTipo(Ast.N_LIT_INT);
            r2.setData(val);
        }
        else{
            throw new Exception("Imposible hacer la conversion, el resultset es nulo");
        }
    }
}



