/*
 * Simbolo.java
 *
 * Creada el 13 de febrero de 2007, 06:21 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package lalrgen;

import java.util.*;
/**
 * Superclase que representa los simbolos gramaticales.
 * @author Erik Giron (200313492)
 *
 */
public class Simbolo implements Comparator, java.io.Serializable{
    /*Campos*/    
    private int tipo;/**Tipo de datos para el atributo sintetizado 1:int, 2:real 3: string*/
    private String idGram;/**Identificador Gramatical: si E->A ,entonces el id seria la cadena "E" o la cadena  "A" ya sea term. o o noterm*/
    private String semId;/**Identificador semantico con que se nombra al el no terminal en las acciones*/
    protected int tipoSimbolo; /**Bandera para definir si es terminal(0), no terminal(1) o especial(2)*/
    /** Crea una nueva instancia de Simbolo */
    protected Object valor;
    public Simbolo() {
        idGram = new String();
        semId = new String();
    }
    /**Crea nuevo simbolo con identificador gramatical pidGram*/
    public Simbolo(String pidGram){
        idGram = new String(pidGram);
        semId = new String();
    }
    /**Constructor de copia*/
    public Simbolo(Simbolo s) {
        idGram = new String(s.getIdGram());
        this.tipo = s.getTipo();
        this.semId = s.getSemId();
        this.tipoSimbolo = s.tipoSimbolo;
    }
    /**Crea nuevo simbolo con identificador gramatical pidGram y contenido semantico semId*/
    public Simbolo(String pidGram, String semId){
        idGram = new String(pidGram);
        semId = new String();
    }
/*Comparadores*/
    public int compare(Object s1, Object s2){    
        return -1;
    }
    
    public boolean equals(Object s1){
        if (s1 != null )//&& s1.getClass().equals(this.getClass()) 
            if(((Simbolo)s1).getTipoSimbolo() == tipoSimbolo
            //&& tipo ==((Simbolo)s1).getTipo() 
            && ((Simbolo)s1).getIdGram().equals(idGram) 
            )
            return true;
        return false;
    }
/*Accesores*/
    public int getTipo() {
        return tipo;
    }

    public String getIdGram() {
        return idGram;
    }
    
    public String getSemId() {
        return semId;
    }
    /**Asigna identificador semantico*/
    public void setSemId(String i2) {
        this.semId = new String(i2);
 //       throw new UnsupportedOperationException("Not yet implemented");
    }
    /**Asigna tipo de dato*/
    public void setTipo(int ptipo){
        this.tipo = ptipo;
    }
    
    public void setIdGram(String pid){
        this.idGram = new String(pid);
    }
    
    public boolean esTerminal(){        
        if(tipoSimbolo == 0)
            return true;
        return false;
    }
         
    public boolean esNoTerminal(){        
        if(tipoSimbolo == 1)
            return true;
        return false;
    }

    private int getTipoSimbolo() {
        return tipoSimbolo;
    }

    public String toString(){
        return idGram;
    }

    public Object getValor() {
        return this.valor;
    }

    public void setValor(String v){ 
        valor = new String(v);
    }
    
    public void setValor(Object o){
        valor = o;
    }
    
    
}
