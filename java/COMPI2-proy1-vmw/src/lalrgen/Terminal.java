/*
 * Terminal.java
 *
 * Creada el 13 de febrero de 2007, 06:21 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package lalrgen;

/**
 *  Representa un terminal en una gramatica.
 * @author Erik Giron (200313492)
 * 
 */
public class Terminal extends Simbolo implements java.io.Serializable{
    
    private int token;    
    protected int precedencia;/**Precedencia del operador, si es -1 no tiene ninguna*/
    
    
/** Crea una nueva instancia de Terminal */
    public Terminal() {
        tipoSimbolo = 0;
        precedencia = -1;
    }
    /**Crea nuevo terminal con identificador gramatical pidGram*/
    public Terminal(String pid){        
        super(pid);
        tipoSimbolo = 0;
    }
    /**Creamos nuevo terminal @param ptoken Valor del token @param pprec precedencia @param valor yylval del terminal*/
    public Terminal(int ptoken,int pprec,String pvalor){
        tipoSimbolo = 0;
        token = ptoken;
        precedencia = pprec;
        valor = new String(pvalor);
    }
        /**Creamos nuevo terminal @param ptoken Id del token @param valor yylval del terminal*/
    public Terminal(String pid,String pvalor){
        super(pid);
        tipoSimbolo = 0;
        valor = new String(pvalor);
    }
/*Comparadores*/
    public int compare(Object o1, Object o2){
        return -1;
    }
    
    
    //*
//    public boolean equals(Object t1){
//        if (t1 != null/* && t1.getClass().equals(this.getClass())*/){
//            Simbolo t = (Simbolo)t1;
//            if (/*((Simbolo)this).equals((Simbolo)t1)) && */
//                    //t.getToken() == this.token && t.getValor().equals(this.valor))
//            this.getIdGram().equals(t.getIdGram()) &&
//            t.esTerminal()
//            )
//                return true;                        
//            return false;
//        }
//        return false;
//    }


    
    public int getToken(){
        return token;
    }
    
    public void setToken(int t){
        token = t;
    }
    
    public boolean esTerminal(){        
        return true;
    }

    public int getPrecedencia() {
        return this.precedencia;
    }
         
    
}
