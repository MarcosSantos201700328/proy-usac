/*
 * Main.java
 *
 * Created on August 12, 2007, 4:20 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package dekkersimulator;

/**
 *
 * @author kreig
 */
public class Main {
    
    /** Creates a new instance of Main */
    public Main() {
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        ModeloExclusion alg = new Peterson(); // alternar entre los algoritmos
        Hilo hilo1 = new Hilo("Hilo 1", 0, alg);
        Hilo hilo2 = new Hilo("Hilo 2", 1, alg);
        hilo1.start();
        hilo2.start();

    }
    
}
