/*
 * NoTerminal.java
 *
 * Creada el 13 de febrero de 2007, 06:21 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package lalrgen;

/**
 * Representacion de un no terminal de la gramatica dada.
 * @author Erik Giron (200313492)
 *
 */
public class NoTerminal extends Simbolo implements java.io.Serializable {   
    
    
    /** Crea una nueva instancia de NoTerminal */
    public NoTerminal() {
        tipoSimbolo = 1;
        int precedencia = -1;
    }
    
    public NoTerminal(String pid){                
        super(pid);
        tipoSimbolo = 1;
    }
    public NoTerminal(Simbolo s) {
        this.setSemId(s.getSemId());
        this.setIdGram(s.getIdGram());
        this.setTipo(s.getTipo());   
        this.tipoSimbolo = 1;
        
    }

    public NoTerminal(NoTerminal nst) {
        this.setSemId(nst.getSemId());
        this.setIdGram(nst.getIdGram());
        this.setTipo(nst.getTipo());   
        this.tipoSimbolo = 1;
    }
    
//    public boolean equals(Object t1){
//        //if(!t1.getClass().equals(this.getClass()))
//        //    return false;
//        if (this.getIdGram().equals(((Simbolo)t1).getIdGram()) &&
//            ((Simbolo)t1).esNoTerminal())
//            return true;
//        return false;
//        //return super.equals(t1);
//    }
//    public boolean equals(Object t1){
//        if (t1 != null && t1.getClass().equals(this.getClass())){
//            NoTerminal t = (NoTerminal)t1;            
//            if (/*(((Simbolo)this).equals((Simbolo)t1)))*/
//                    this.getIdGram().equals(t.getIdGram()) && this.getTipo() == t.getTipo() )
//                return true;                        
//            return false;
//        }
//        return false;
//    }
    
    
    public boolean esNoTerminal(){        
        return true;
    }    /*
    public void setSemId(String v){
        semId = new String(v);    
    }*/
    public String toString(){
        return this.getIdGram();
        
    }
}
