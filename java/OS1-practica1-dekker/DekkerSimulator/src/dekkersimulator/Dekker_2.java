/*
 * Dekker_2.java
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
public class Dekker_2 extends ModeloExclusion {
       private volatile boolean[] m_bFlag = new boolean[2];
       public Dekker_2() {
               m_bFlag[0] = false;
               m_bFlag[1] = false;
       }
       public void entrarSC(int iId) {
               int other = 1 - iId;
               m_bFlag[iId] = true;
               while (m_bFlag[other] == true)
                      Thread.yield();
       }
       public void salirSC(int iId) {
               m_bFlag[iId] = false;
       }
}

