/*
 * Jugador.java
 *
 * Created on 11 de septiembre de 2005, 09:26 PM
 *
 */

//package otello;

/**Clase que define la logica del Jugador base
 *@author Erik Giron*/
public class Jugador {
    private String nombre;/** Nombre del jugador*/
    private int posicion,color = 16,punteo = 0;
    /**Constructor Predeterminado*/
    public Jugador() {
        this.posicion = this.color = this.punteo = 0;
    }
    /**
     *@param n Nombre de jugador
     *@param pos Entero (0..3) para posicion de jugador en el tablero
     *@param col Entero (0..3) para color del jugador
     * Constructor de Oficio
     */
    public Jugador(String n,int pos, int col){
        this.color = col;
        this.nombre = n;
        this.posicion = pos;
    }
    /**@param j2 Jugador a copiar los campos
     * Constructor de Copia*/
    public Jugador(Jugador j2)
    {
        this.posicion = j2.getPos();
        this.color = j2.getColor();
        this.nombre = j2.getNombre();
        this.punteo = j2.getPunteo();
    }

    /** Establece parametros de Jugador
     * @param n Nombre
     * @param pos Posicion en el tablero (0..3)
     * @param col Color (0..3)*/
    public void setJugador(String n,int pos, int col){
        color = col;
        nombre = n;
        posicion = pos;
    }
    /**Agrega puntos al jugador
     * @param p Puntos a sumar*/
    public void sumarPuntos(int p){ this.punteo+=p;}
    /**Resta puntos al jugador
     * @param p Puntos a Restar*/
    public void restarPuntos(int p){ this.punteo-=p;}
    /**Asigna Puntos
     * @param p a asignar*/
    public void setPunteo(int p){  this.punteo = p; }
    /**@return Punteo actual del jugador*/
    public int getPunteo(){ return this.punteo;}
    /**Asigna nombre a jugador
     * @param nombre Nombre a asignar a Jugador
     */
    public void setNombre(String nombre){this.nombre = nombre; }
    /** Obtiene el nombre del jugador.
     *@return Nombre asignado a Jugador.
     */
    public String getNombre(){ return this.nombre; }
    /**Asigna color a Jugador
     *@param color Color (0..3)
     */
    public void setColor(int color){this.color = color;}
    /**Obtiene el color del jugador
     *@return Color actual del Jugador
     */
    public int getColor(){return this.color;}
    
    /** Obtiene posicion del Jugador
     *@return Posicion Actual del Jugador.
     */
    public int getPos(){return posicion;}
    
    /** Establece posicion del Jugador
     * @param pos Posicion en el tablero (0..3)
     */
    public void setPos(int pos){this.posicion = pos;}
}
