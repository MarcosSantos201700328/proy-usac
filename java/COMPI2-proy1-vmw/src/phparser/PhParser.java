/*
 * PhParser.java
 *
 * Creada el 18 de marzo de 2007, 08:02 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package phparser;

import errormanager.ErrorManager;
import java.io.*;
/**
 * Punto de entrada para el parsing del codigo en PHP
 * @author Erik Giron (200313492)
 *
 */
public class PhParser {
    
    private static MensajesParser cuadroMensajes = new MensajesParser();
    
    private static SymTab tablaSimbolos = new SymTab(); // Tabla de simbolos utilizada
    
    private static Ast arbolActual = new Ast(); //Arbol AST Actualmente en proceso
    /** Crea una nueva instancia de PhParser */
    
    private parser p;
    
    private Lexer l;
    
    public PhParser() {
        //cuadroMensajes.setVisible(true);
    }
    /**Devuelve la tabla de simbolos*/
    public static SymTab getTablaSimbolos() {
        return tablaSimbolos;
    }
   
    /**Ejecuta codigo contenido en un stream dado*/
    public int ejecutar(Reader stream) throws Exception{
        try{
            l = new Lexer(stream);
            p = new parser(l);
            //p.debug_parse();
            p.parse();
        }
        catch(Exception e){
            this.escribirMensaje(e.toString() + "\n");
            throw e;
        }
        return 0;
    }
    /**Asigna una nueva tabla de simbolos*/
    public static void setTablaSimbolos(SymTab nuevo) {
        tablaSimbolos = nuevo;
    }
   
    /**Oculta ventana de mensajes*/
    public static void ocultarCuadroMensajes(){
        cuadroMensajes.setVisible(false);
    }
    
    /**muestra ventana de mensajes*/
    public static void mostrarCuadroMensajes(){
        cuadroMensajes.setVisible(true);
    }
    
    /**escribe a cuadro de mensajes*/
    public static void escribirMensaje(String msg){
        //cuadroMensajes.setVisible("true");
        cuadroMensajes.escribirMensaje(msg + "\n");
        cuadroMensajes.setVisible(true);
    }
    
}
