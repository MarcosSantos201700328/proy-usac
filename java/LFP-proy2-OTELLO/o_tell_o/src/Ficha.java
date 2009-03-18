/*
 * Ficha.java
 *
 * Created on 24 de septiembre de 2005, 06:08 PM
 *
 */

import javax.swing.*;
import java.awt.*;
import java.util.*;
/**Establece las propiedades de la ficha, asi como quien la posee o si no la pose nadie es celda
 *@author Erik Giron
 **/
public class Ficha extends JButton {
    private int color; /** Color identificador para jugador*/
    private int estado;/** Es Celda = 0 o es Ficha = 1 */
    private int posx,posy;/**Posiciones dentro de la matriz*/
    private Circulo c;/**Icono simulando una ficha derivada de la clase interna Circulo*/
    /***/

    /**Constructor por deficion de Ficha*/
    public Ficha(){
        super();
       //c c = new Circulo(color);
        estado = 0;
        color = -1;

    }
    /**Constructor para que la ficha pertenezca al jugador
     * @param j Jugador desde donde se copiara la info*/
    public Ficha(Jugador j){
        super();
        this.color = j.getColor();
        c = new Circulo(color);
        //c.color(j.getColor());
        this.setIcon(c);
        estado = 1;     /*se convierte en ficha*/

        //this.pos = new int[2][8];
  //      this.


    }
    /**Constructor para inicalizar indice de posiciones de
     * la celda que contendra la ficha dentro de la matriz de celdas vacias
     * @param posx Posicion en X
     * @param posy Posicion en Y*/
    public Ficha(byte posx,byte posy){
        this.posx = posx;
        this.posy = posy;
    }
    /**Asigna direccion de la ficha dentro de la matriz
     * @param x posicion en x
     * @param y posicion en y*/
    public void setPos(int x,int y){
        this.posx = x;
        this.posy = y;
    }
    /**@return Devuelve posicion en x dentro de la matriz*/
    public int getPosx(){return this.posx;}
    /**@return Devuelve posicion en y dentro de la matriz*/
    public int getPosy(){return this.posy;}
    /**Coloca color al icono de ficha basado en el color del jugador
     * @param j Jugador al que se le copiara el color*/
    public void SetColor(Jugador j){
        this.color = j.getColor();
    }
    /**Obtiene estado actual
     * @return celda vacia =0; ficha jugador 1 = 1; ficha jugador 2 = 2*/
    public int getEstado(){
        return this.estado;
    }
    /**Convierte la celda actual a ficha del jugador
     * @param j Jugador que voltea*/
    public void voltear(Jugador j)
    {
        //if estado = 0{
            c = new Circulo(j.getColor()); // Crea nuevo circulo del color del jugador
            //this.color = j.getColor(); // Asigna color de icono
          //  c.color(j.getColor());
            this.setIcon(c);
            estado = 1;     /*se convierte en ficha de jugador 1*/
            this.color = j.getColor();
    }
  //  /**Convierte la celda actual a ficha del jugador virtual dado en el parametro*/
 //   public void voltear(JugadorVirtual j)
 //   {
 //       c = new Circulo(j.getColor());
        //this.color = j.getColor(); // Asigna color de icono
        //c = new Circulo(color);
     //   c.color(j.getColor());
 //       this.setIcon(c);
 //       estado = 2;     /*se convierte en ficha de jugador 2*/
 //   }
    public int getColor(){
        return this.color;
    }

}

