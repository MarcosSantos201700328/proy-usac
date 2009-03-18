/*
 * Console.java
 *
 * Created on 12 de septiembre de 2005, 06:35 PM
 *
 */

import javax.swing.*;
import java.awt.event.*;
/**Clase para correr el applet o panel desde el sistema operativo
 * @author Erik Giron*/
public class Console {
    /**Establece titulo para ventana StandAlone
     * @param o Objeto del que se extraera el nombre de clase
     * @return nombre de la clase dada en el parametro*/
    public static String title(Object o)        {
        String t = o.getClass().toString();
        if(t.indexOf("class") != 1)
            t = t.substring(6);
        return t;
    }

    /*Metodo para cerrar ventana*/
    public static void setupClosing(JFrame frame) {
        frame.addWindowListener(new WindowAdapter(){
            public void WindowClosing(WindowEvent e){
                System.exit(0);
            }
        });
    }
    /**Ejecuta Ventana desde consola
     * @param frame Ventana que se mostrara
     * @param w Ancho
     * @param h Altura*/
    public static void run(JFrame frame, int w, int h){
        setupClosing(frame);
        frame.setSize(w,h);
        frame.setVisible(true);
    }
    /**Ejecuta applet desde consola
     * @param applet Applet que se mostrara
     * @param w Ancho
     * @param h Altura*/
    public static void run(JApplet applet, int w, int h)
    {
        JFrame frame = new JFrame(title(applet));
        setupClosing(frame);
        frame.getContentPane().add(applet);
        frame.setSize(w,h);
        applet.init();
        applet.start();
        frame.setVisible(true);

    }
    /**Ejecuta Panel desde consola
     * @param panel Panel que se mostrara como principal
     * @param w Ancho
     * @param h Altura*/
    public static void run(JPanel panel, int w, int h){
        JFrame frame = new JFrame(title(panel));
        setupClosing(frame);
        frame.getContentPane().add(panel);
        frame.setSize(w,h);
        frame.setVisible(true);
    }

}