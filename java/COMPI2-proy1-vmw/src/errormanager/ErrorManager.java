/*
 * ErrorManager.java
 *
 * Creada el 13 de marzo de 2007, 02:21 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package errormanager;

/**
 * Clase que implementa la cola de errores de lectura de archivo paquete
 * @author Erik Giron (200313492)
 *
 */
import java.util.*;
public class ErrorManager {
    private static LinkedList<ErrorElem> lexErrorQueue = new LinkedList<ErrorElem>();
    private static LinkedList<ErrorElem> sinErrorQueue = new LinkedList<ErrorElem>();
    private static LinkedList<ErrorElem> semErrorQueue = new LinkedList<ErrorElem>();
    /** Crea una nueva instancia de ErrorManager */
    public ErrorManager() {
    }
    

    public LinkedList<ErrorElem> getLexErrorQueue() {
        return lexErrorQueue;
    }

    public LinkedList<ErrorElem> getSemErrorQueue() {
        return semErrorQueue;
    }

    public LinkedList<ErrorElem> getSinErrorQueue() {
        return sinErrorQueue;
    }

    public void setLexErrorQueue(LinkedList<ErrorElem> lexErrorQueue) {
        this.lexErrorQueue = lexErrorQueue;
    }

    public void setSemErrorQueue(LinkedList<ErrorElem> semErrorQueue) {
        this.semErrorQueue = semErrorQueue;
    }

    public void setSinErrorQueue(LinkedList<ErrorElem> sinErrorQueue) {
        this.sinErrorQueue = sinErrorQueue;
    }
    
    /**Crea un nuevo error lexico en la linea y columna dada*/
    public static void agregarErrorLexico(int linea,int columna, String descripcion){
        ErrorElem e;
        if(linea > 0 && columna > 0){
             e = new ErrorElem(linea,columna,descripcion);
        }
        else
            e = new ErrorElem(descripcion);
        lexErrorQueue.addLast(e);        
    }
    
    /**Crea un nuevo error sintactico en la linea y columna dada*/
    public static void agregarErrorSintactico(int linea,int columna, String descripcion){
        ErrorElem e;
        if(linea > 0 && columna > 0){
             e = new ErrorElem(linea,columna,descripcion);
        }
        else
            e = new ErrorElem(descripcion);
        sinErrorQueue.addLast(e);        
    }        
    /**Crea un nuevo error semantico en la linea y columna dada*/
    public static void agregarErrorSemantico(int linea,int columna, String descripcion){
        ErrorElem e;
        if(linea > 0 && columna > 0){
             e = new ErrorElem(linea,columna,descripcion);
        }
        else
            e = new ErrorElem(descripcion);
        semErrorQueue.addLast(e);        
    }        
    /**Imprime todos los errores que hay en la cola*/
    public static String printAll(){
        String ret = new String();
        ErrorElem eact;
        Iterator i = lexErrorQueue.iterator();        
        ret += "Errores Lexicos:\n";
        while(i.hasNext()){
            eact = (ErrorElem) i.next();
            ret += eact.toString() + "\n";
        }
        i = sinErrorQueue.iterator();                
        ret += "\nErrores Sintacticos:\n";
        while(i.hasNext()){
            eact = (ErrorElem) i.next();
            ret += eact.toString() + "\n";
        }
        i = semErrorQueue.iterator();                
        ret += "\nErrores Semanticos:\n";
        while(i.hasNext()){
            eact = (ErrorElem) i.next();
            ret += eact.toString() + "\n";
        }
        return ret;
    }
    
    /**Devuelve una cadena con todos los errores sintacticos*/
    public static String printErroresSintaticos(){
        ErrorElem eact;
        String ret = new String();
        Iterator i;
        i = sinErrorQueue.iterator();                
        ret += "\nErrores Sintacticos:\n";
        while(i.hasNext()){
            eact = (ErrorElem) i.next();
            ret += eact.toString() + "\n";
        }
        return ret;
    }
    
    /**Devuelve una cadena con todos los errores lexicos*/
    public static String printErroresLexicos(){
        ErrorElem eact;
        String ret = new String();        
        Iterator i = lexErrorQueue.iterator();        
        ret += "Errores Lexicos:\n";
        while(i.hasNext()){
            eact = (ErrorElem) i.next();
            ret += eact.toString() + "\n";
        }
        return ret;
    }
    
    /**Devuelve una cadena con todos los errores semanticos*/
    public static String printErroresSemanticos(){
        ErrorElem eact;
        String ret = new String();        
        Iterator i = semErrorQueue.iterator();                
        ret += "\nErrores Semanticos:\n";
        while(i.hasNext()){
            eact = (ErrorElem) i.next();
            ret += eact.toString() + "\n";
        }
        return ret;
    }
    /**Limpia e inicializa la cola de errores*/
    public static void Inicializar(){
        lexErrorQueue.clear();
        sinErrorQueue.clear();
        semErrorQueue.clear();
    }
}
