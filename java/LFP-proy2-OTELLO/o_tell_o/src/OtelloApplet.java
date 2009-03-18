/*
 * OtelloApplet.java
 *
 * Created on 10 de septiembre de 2005, 12:33 PM
 *
 */
//<applet code=OtelloApplet width=640 height=480></applet>

import java.util.*;
//import java.util.List;
import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

//import otello.*;

/**
 *
 * @author Erik Giron
 */

/**Clase principal del juego*/
public class OtelloApplet extends JApplet {

    private Container c;// Contenedor principal del Applet
    private MainPanel panel;// Ventana que se muestra al usuario
//    private Tablero tab;//Tabler de juego
    /**Inicializa el tablero*/
    public void init(){
        setLook();
        c = getContentPane();
        c.setLayout(new BorderLayout());
        panel = new MainPanel();
        c.add (panel);
        panel.setAppletPrincipal(this);// Asigna este applet como applet principal del programa
      //  tab = new Tablero();
        //c.add(tab);
  //      c.add (tab, BorderLayout.SOUTH);

         //JButton jb = new JButton ("Default");
        //c.add (jb, BorderLayout.WEST);
        //jb = new JButton ("LayoutManager");
        //c.add (jb, BorderLayout.CENTER);
        //jb = new JButton ("is");
        //c.add (jb, BorderLayout.EAST);
        //jb = new JButton ("BorderLayout: " +
        //(c.getLayout() instanceof BorderLayout));
        //c.add (jb, BorderLayout.SOUTH);
    }
    public static void iniciar(){

    //    OtelloApplet.getContentPane().add(new Tablero(),BorderLayout.CENTER);

    }

    /**Establece el estilo de forms predeterminados del gestor de ventanas donde
     * se esta corriendo la aplicacion*/
    public void setLook(){
        String laf = UIManager.getSystemLookAndFeelClassName();

	try {
//	    UIManager.setLookAndFeel(laf);

	    // If you want the Cross Platform L&F instead, comment out the above line and
	    // uncomment the following:
	     UIManager.setLookAndFeel(UIManager.getCrossPlatformLookAndFeelClassName());
	} catch (UnsupportedLookAndFeelException exc) {
	    System.err.println("Aviso: LookAndFeel no soportado: " + laf);
	} catch (Exception exc) {
	    System.err.println("Error Cargando " + laf + ": " + exc);
	}
    }
    /**MAIN para correr el applet como aplicacion
     * @param args parametros*/
    public static void main(String[] args){
        //Console.run(new SourceViewer(),640, 480);
        Console.run(new OtelloApplet(), 640, 480);
        iniciar();
    }
    /** Constructor por defecto */
    public OtelloApplet() {
    }

}





