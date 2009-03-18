/*
 * Dekker_1.java
 *
 * Creada el August 12, 2007, 4:22 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package dekkersimulator;

/**
 *
 * @author Erik Giron (200313492)
 *
 */
public class Dekker_1 extends ModeloExclusion {
       private volatile int m_iTurn;
       public Dekker_1() {
               m_iTurn = TURN_0;
       }
       public void entrarSC(int iId) {
               while (m_iTurn != iId)
                      Thread.yield();
       }
       public void salirSC(int iId) {
               m_iTurn = 1 - iId;
       }
}

