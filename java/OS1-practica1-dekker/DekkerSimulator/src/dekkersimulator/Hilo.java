/*
 * Hilo.java
 *
 * Creada el August 12, 2007, 4:20 PM
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
public class Hilo extends Thread {
       private String name;
       private int m_iId;
       private ModeloExclusion m_oExc;
       public Hilo(String sName, int iId, ModeloExclusion oExc) {
               name = sName;
               m_iId = iId;
               m_oExc = oExc;
       }
       public void run() {
               while (true) {
                      System.out.println(name + " desea entrar a la SC");
                      m_oExc.entrarSC(m_iId);
                      System.out.println(name + " entro a la SC");
                      ModeloExclusion.SC();
                      m_oExc.salirSC(m_iId);
                      System.out.println(name + " salio de la SC");
                      ModeloExclusion.noSC();
               }
       }
}

