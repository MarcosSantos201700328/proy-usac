/*
 * TokenValue.java
 *
 * Creada el 23 de abril de 2007, 03:24 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package IlGen;

import java.util.*;
/**
 *
 * 
 *
 */

/** Valor semantico del  token devuelto por el analizador lexico @author Erik Giron (200313492) */
public class TokenValue {          
  public int lineBegin;
  public int charBegin;
  public String text;
  public String filename;   

  TokenValue() {
  }

  TokenValue(String text, int lineBegin, int charBegin, String filename) {
    this.text = new String(text); 
    this.lineBegin = lineBegin; 
    this.charBegin = charBegin;
    this.filename = filename;
     /**Esto solo es para debugear*/
    System.out.println("Linea: " + (lineBegin+1) + ", columna: " + (charBegin+1));
  }

  public String toString() { 
    return text;
  }

  public boolean toBoolean() {
    return Boolean.valueOf(text).booleanValue();  
  }
  
  public int toInt() {
    return Integer.valueOf(text).intValue();
  }

  public double toDouble() {
    return Double.valueOf(text).doubleValue();
  }
  public int getPosLine(){
	return lineBegin;
  }
  public int getPosChar(){
	return charBegin;
  }
}



/**Clase de utilidad que representa el relleno de retroceso para el manejo de expresiones booleanas en codigo intermedio*/
class BackFill{
    private LinkedList listaVerdaderos = new LinkedList();
    private LinkedList listaFalsos = new LinkedList(); 
    
        
    BackFill(){        
        nuevaLista();
    }
    /**Agrega un nuevo display al cuadruplo*/
    public void nuevaLista(){
        ArrayList v = new ArrayList();
        ArrayList f = new ArrayList();
        
        listaVerdaderos.add(v);
        listaFalsos.add(f);        
    }
    /**Fusiona los displays*/
    public void fusionarListas(){
        ArrayList topev,topef;
        if(listaVerdaderos.size() > 1){
            topev = (ArrayList) listaVerdaderos.removeLast();            
            topev.addAll((ArrayList)listaVerdaderos.removeLast());
            listaVerdaderos.addLast(topev);
        }
        if(listaFalsos.size() > 1){
            topef = (ArrayList) listaFalsos.removeLast();
            topef.addAll((ArrayList)listaFalsos.removeLast());
            listaFalsos.addLast(topef);
        }        
    }
    
    /**Invierte los displays para que el de falso sea verdadero y viceversa*/
    public void invertir(){
        LinkedList listaAux = listaVerdaderos;
        listaVerdaderos = listaFalsos;
        listaFalsos = listaAux;
    }
    
    /**Inserta una etiqueta de verdadera en el display actual*/
    public void insertarTrue(int etiq){
        Integer nuevo = new Integer(etiq);
        ArrayList top = (ArrayList) listaVerdaderos.getLast();
        top.add(nuevo);
    }
    
    /**Inserta una etiqueta de verdadera en el display actual*/
    public void insertarFalse(int etiq){
        Integer nuevo = new Integer(etiq);
        ArrayList top = (ArrayList) listaFalsos.getLast();
        top.add(nuevo);
    }
   
    /**Devuelve un string formateado con todas las etiquetas verdaderas*/
    public String sacarVerdaderas(){
        String ret = new String();
        ArrayList top = (ArrayList) listaVerdaderos.getLast();
        Iterator i = top.iterator();
        Integer l;
        while(i.hasNext()){
            l = (Integer) i.next();
            ret += "L" + l.toString() + ":\n";
            i.remove();
        }
        return ret;
    }
    
        /**Devuelve un string formateado con todas las etiquetas falsas*/
    public String sacarFalsas(){
        String ret = new String();
        ArrayList top = (ArrayList) listaFalsos.getLast();
        Iterator i = top.iterator();
        Integer l;
        while(i.hasNext()){
            l = (Integer) i.next();
            ret += "L" + l.toString() + ":\n";
            i.remove();
        }
        return ret;
    }
    
    
}

