/*
 * Circulo.java
 *
 * Created on 26 de septiembre de 2005, 05:39 PM
 *
 */
import java.awt.*;
import javax.swing.*;

/**
 *Clase que dibuja el icono en el boton, Implementa la interfaz Icon
 *@author Erik Giron
 */
public class Circulo implements Icon{
    private int col;
    private ColorFichas colorf;
    /**@param c Componente
     * @param g Objeto Graphics para dibujar
     * @param x Posicion x relativa donde se desea dibujar
     * @param y Posicion y relativa donde se desea dibujar
     *
     * Dibuja el Circulo representado una ficha*/
    public void paintIcon(Component c, Graphics g,
            int x, int y) {
        // Dibuja la sombra de la ficha
        g.setColor(new Color(128,128,128));
        g.fillOval(x+2, y+2, getIconWidth(), getIconHeight());
        //Dibuja la ficha a usar

        // g.setColor(color(col));
        colorf = new ColorFichas(col);
        g.setColor(colorf.getColor());
        g.fillOval(x, y, getIconWidth(), getIconHeight());

    }
    /**@return Ancho*/
    public int getIconWidth() {
        return 16;
    }
    /**@return Altura*/
    public int getIconHeight() {
        return 16;
    }
    /**@param c Entero que representa el color con el que se desee dibujar*/
    public Circulo(int c){
        super();
        col = c;

    }
    /**Implementacion de la funcion Paint de Icon, llama a paintIcon*/
    public void paint(Component c, Graphics g,int x, int y){
        paintIcon(c,g, x,y);
    }
}

/**@author Erik Giron
 * Controla colores personalizados para las fichas segun jugadores*/
class ColorFichas{
    private Color c; //puntero a colores predefinidos
    /**Constructor
     * @param num Indice de color definido por el usuario en opciones de jugador*/
    ColorFichas(int num){
        setColor(num);
    }
    /**@return Color escogido previamente*/
    public Color getColor(){
        return c;
    }
    /**@param num Entero que define el color establecido por usuario*/
    public void setColor(int num){
        switch (num){
            case 0: // Rojo
                c = Color.red;
                break;
            case 1: // Azul
                c = Color.blue;
                break;
            case 2: // Verde
                c = Color.green;
                break;
            case 3: // Negro
                c = Color.black;
                break;
            default: // Cyan
                c = Color.cyan;
                break;
        }
    }
}
