/*
 * Output.java
 *
 * Creada el 29 de abril de 2007, 06:50 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package IlGen;

import java.io.*;
import java.util.*;
/**
 * Representa un stream de salida de datos para el codigo intermedio generado
 * @author Erik Giron (200313492)
 *
 */
public class Output {
    
    private static final int debug = 1;
    private static String path = new String();
    private static String filename = new String();
    
    private static BufferedWriter out;
    
    /** Crea una nueva instancia de Output */
    public Output() {
        //justtodebug
        
    }
    /**Rutina para escribir una linea*/
    public static void writeLn(String linea) throws Exception{
        System.out.println(linea);
        writeToFile(linea + "\n");
    }
    /**Rutina para escribir sin cambio de linea*/
    public static void write(String linea) throws Exception{
        System.out.print(linea);
        writeToFile(linea);
    }
    /**Escribe el encabezado del archivo de 3 direcciones*/
    public static void writeHeader() throws Exception{
        writeToFile("#include \"" + filename + ".out.h\"\n\n");
    }
    /**Escribe linea en archivo de salida*/
    protected static void writeToFile(String linea) throws Exception{
        out.write(linea);
    }
    
    /**Genera archivo .h con las declaraciones de variables globales, y funciones, tomando la tabla de simbolos de tiempo de compilacion*/
    protected static void createHeader(int temps, SymTab tablaSimbolos) throws Exception{
        BufferedWriter fo;
        IlGen.Symbol s;
        Iterator i;
        int j;
        //Abrimos archivo
        fo = new BufferedWriter(new FileWriter(path + java.io.File.separator + filename + ".out.h"));
        //Creamos encabezado
        fo.write("/* INCLUDES */\n");
        fo.write("#include <stdio.h>\n");
        fo.write("#include <stdlib.h>\n\n\n");
        fo.write("float STACK[65536]; /*pila*/\n\n");
        // escribimos typedefs
        // fo.write("/**Typedefs*/\n\n");
        
        // escribimos prototipos de funciones
        fo.write("/**Funciones*/\n\n");
        i = tablaSimbolos.getIdxFunctions().values().iterator();
        while(i.hasNext()){
            s = (IlGen.Symbol) i.next();
            if (s.get_class() == SymTab.C_PROC || s.get_class() == SymTab.C_FUNC){
                if(!(s.getId().equalsIgnoreCase("main")) && !(s.getId().equalsIgnoreCase("printf")) 
                && !(s.getId().equalsIgnoreCase("scanf")) && !(s.getId().equalsIgnoreCase("read"))
                && !(s.getId().equalsIgnoreCase("readln")) && !(s.getId().equalsIgnoreCase("write"))
                && !(s.getId().equalsIgnoreCase("writeln")))
                fo.write("void " + s.getId() + "();\n");
            }
        }
        // escribimos variables globales
        fo.write("/**Variables Globales*/\n\n");
        i = tablaSimbolos.getIdxVariables().values().iterator();
        while(i.hasNext()){
            s = (IlGen.Symbol) i.next();
            //if (s.get_class() == SymTab.C_OBJECT){
            //    fo.write(s.getType().getObjType() + " " + s.getId() + ";\n");
           // }
            /*else */
            if(s.getScope().equals("global")){
                if (s.get_class() == SymTab.C_VAR){
                    switch (s.getType().getType()){
                        case SymTab.T_BOOL:
                        case SymTab.T_INT:
                            fo.write("int " + s.getId() + ";\n");
                            break;
                        case SymTab.T_CHAR:
                            fo.write("char " + s.getId() + ";\n");
                            break;
                        case SymTab.T_FLOAT:
                            fo.write("float " + s.getId() + ";\n");
                            break;                        
                        case SymTab.T_STRING:
                            fo.write("char " + s.getId() + "[255];\n");
                            break;
                        default:
                            fo.write("float " + s.getId() + ";\n");
                            break;
                    }
                }
                else if (s.get_class() == SymTab.C_ARRAY){
                    switch (s.getType().getType()){
                        case SymTab.T_BOOL:
                        case SymTab.T_INT:
                            fo.write("int " + s.getId() + "[" + s.getSize() +  "]" + ";\n");
                            break;
                        case SymTab.T_CHAR:
                            fo.write("char " + s.getId() + "[" + s.getSize() +  "]" + ";\n");
                            break;
                        case SymTab.T_FLOAT:
                            fo.write("float " + s.getId() + "[" + s.getSize() +  "]" + ";\n");
                            break;                        
                        case SymTab.T_STRING:
                            fo.write("char " + s.getId() + "[" + s.getSize() +  "]" + "[255];\n");
                            break;
                        default:
                            fo.write("float " + s.getId() + "[" + s.getSize() +  "]" + ";\n");
                            break;
                    }
                }
                else{
                    fo.write("float " + s.getId() + ";\n");
                }
            }
        }
        // escribimos variables globales t
        fo.write("/**Temporales */\n\n");
        for(j = 0; j < temps; j++){
            fo.write("float t" + j + ";\n");
        }
        //cerramos archivo
        fo.close();
    }
    /**Devuelve el nombre de archvo*/
    public static String getFilename() {
        return filename;
    }
    /**Devuelve el path*/
    public static String getPath() {
        return path;
    }

    public static void setFilename(String f) {
        filename = f;
    }

    public static void setPath(String p) {
        path = p;
    }
    /**Asigna y abre archivo de salida dado por el path p, y el nombre n*/
    public static void setOutputFile(String p, String n) throws IOException{
        setPath(p);
        setFilename(n);
        try{
            close();
            out = new BufferedWriter(new FileWriter(path + java.io.File.separator + filename + ".out.c"));
        }
        catch(IOException e){
            System.out.println("Imposible abrir archivo, verifique que el path es correcto y que tiene los permisos para escritura en el directorio actual");
        }
        
    }
    /**Cierra streams abiertos*/
    public static void close() {
        if(out!=null){
            try{
                out.close();
            }
            catch(Exception e){
                System.out.println(e.toString());
            }
        }
    }
    
}
