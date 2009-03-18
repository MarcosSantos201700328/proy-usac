/*
 * Main.java
 *
 * Created on 13 de febrero de 2007, 06:17 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package vmw;

/**
 *
 * @author kreig
 */
public class Main {
    
    private static Vmw poe = new Vmw();/**Punto de Entrada hacia el motor*/
    /** Creates a new instance of Main */
    public Main() {
        //poe = new Vmw();
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args){
        if (args[0].length() > 0){
            poe.parseGrammarFileNameAndExecute(args[0],args[1]);             

        }
        // TODO code application logic here
    }    
}
