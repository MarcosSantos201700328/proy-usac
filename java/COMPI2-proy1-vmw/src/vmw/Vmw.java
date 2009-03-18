/*
 * Vmw.java
 *
 * Creada el 15 de febrero de 2007, 09:12 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package vmw;

import lalrgen.*;
import java.io.*;
import lrparser.*;
import phparser.*;
/**
 *
 * @author Erik Giron (200313492)
 *
 */
public class Vmw {
    
    private static Vacc vacc;
    
    public static Vacc getVacc(){
        return vacc;
    }
    
    public static void setVacc(Vacc pVacc){
        vacc = pVacc;
    }
    /** Crea una nueva instancia de Vmw */
    public Vmw() {
        vacc = new Vacc();
    }
    /**Prueba*/
    public int parseGrammarFileNameAndExecute(String cpmFilename,String exeFilename){        
        int ret;
        Reader r;
        LRParser parser;
        TestLexer l;
        try{ 
            r = new FileReader(cpmFilename);     
            vacc.parse(r);    
            r.close();
            l = new lrparser.TestLexer(new FileReader(exeFilename));
            vacc.procesarLALRyGuardarTablas("/home/kreig/test/");
            
            parser = new lrparser.LRParser((Scanner)l,"/home/kreig/test/",vacc.getNombrePaquete());
            
            parser.verTablaLALR();
            
            parser.parse();
        }
        catch(Exception e){
            System.out.println(e);
            return -1;            
        }
        
        
        
        return 0;
    }    
}
