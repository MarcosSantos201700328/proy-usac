/*
 * Tablero.java
 *
 * Created on 11 de septiembre de 2005, 02:04 PM
 */

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

/**Clase principal del juego que dibuja el tablero y controla las reglas sobre
 * las "fichas" y los jugadores
 * @author  Erik Giron*/
public class Tablero extends javax.swing.JPanel {
    ColorFichas col;

    private final int cellsize = 10;
    private int i,j;
    private static Ficha[][] fichas;
    private static Ficha[] fs = {null,null,null,null,null,null,null,null,null};
    private boolean juegoIniciado = false;
    private Jugador j1,j2, ganador;  // Instancia para jugador humano
    private int turno = 0;
    private boolean bloqCeldas = false; // Bandera para bloquear fichas
    /**@return verdadero si se ha iniciado, sino falso.*/
    public boolean getJuegoIniciado(){
        return this.juegoIniciado;
    }

    /**Compara entre ambos jugadores para ver quien gano y asigna el puntero
     *  ganador a el jugador que gano o nulo si hubo empate
     *@param jj1 Jugador 1
     *@param jj2 Jugador 2*/
    public void setGanador(Jugador jj1, Jugador jj2){
        if (jj1.getPunteo()> jj2.getPunteo()){
            this.ganador = jj1;
        }
        else if (jj1.getPunteo() < jj2.getPunteo()){
            this.ganador = jj2;
        }
        else this.ganador = null;
    }

    /** @return Retorna el puntero referente al ganador del juego*/
    public Jugador getGanador(){
        return this.ganador;
    }

    /** Inicializa los labels que contendran los nombres de los jugadores*/
    public void initNombres() {
        jLabelAb.setText("");
        jLabelArr.setText("");
        jLabelDer.setText("");
        jLabelIzq.setText("");
    }
    /** Constructor por definicion de Tablero */
    public Tablero() {
        initComponents();
        initNombres();
        initFichas(); // Inicializa las fichas
        col = new ColorFichas(0); // Inicializa el color para asignar a texto

       // setSize(cellsize*8 + 10, cellsize*8 + 10);
    }
    /*Verifica si se puede voltear la ficha en el punto x, y, con color c y a grados
    Devuelve una referencia a la ficha a voltear
     /**@deprecated */
    protected static Ficha chainNGrados(int x,int y,int c, int grados){
        int n=0,m=0,p=0,q=0;
        switch(grados){
            case 0:
                n=2;m=0;p=1;q=0;
                break;
            case 1:
                n=2;m=-2;p=1;q=-1;
                break;
            case 2:
                n=0;m=-2;p=0;q=-1;
                break;
            case 3:
                n=-2;m=-2;p=-1;q=-1;
                break;
            case 4:
                n=-2;m=0;p=-1;q=0;
                break;
            case 5:
                n=-2;m=2;p=-1;q=1;
                break;
            case 6:
                n=0;m=2;p=0;q=1;
                break;
            case 7:
                n=2;m=2;p=1;q=1;
                break;
            case 8:
                n=2;m=0;p=1;q=0;
                break;
        }
        if ((fichas[y+q][x+p].getColor() != c) && (fichas[y+m][x+n].getColor() == c) &&
            (fichas[y+q][x+p].getEstado() > 0) && (fichas[y+m][x+n].getEstado() > 0)){
            return fichas[y+q][x+p];
        }
        else
            return null;
    }
    /**Voltea las fichas si se encuentran encerradas entre fichas de un color
     * @param ff Referencia a ficha que se ha pulsado
     * @param jj1 Referencia a jugador que va a hacer la jugada
     * @param jj2 Referencia a jugador que va a ser afectado
     * @param dir Direccion(0..8 en azimut) a que se intentara generar el efecto en cadena
     * @return 1 si se logro voltear por lo menos 1 ficha, -1 si no se puede hacer movimiento*/
    protected static int chainNGrados(Ficha ff,Jugador jj1, Jugador jj2, int dir){
        int stepx = 0,stepy = 0;
        int x,y,i,j,k;
        int m, n, encontrado = 0, contador = 0;
        x = ff.getPosx();
        y = ff.getPosy();
        i = x;
        j = y;
        k = 0;
        // Selecciona el "paso" conforme direccion
        switch (dir){
            case 0: stepx = 1; stepy = 0; break;
            case 1: stepx = 1; stepy = -1; break;
            case 2: stepx = 0; stepy = -1; break;
            case 3: stepx = -1; stepy = -1; break;
            case 4: stepx = -1; stepy = 0; break;
            case 5: stepx = -1; stepy = 1; break;
            case 6: stepx = 0; stepy = 1; break;
            case 7: stepx = 1; stepy = 1; break;
        }
        // busca si existe la ficha del mismo color como limite
        m = x;
        n = y;
        while(encontrado == 0 && m+stepx>=0 && n+stepy>=0 && m+stepx<8 && n+stepy<8){
          m+=stepx;
          n+=stepy;
          if(contador == 0){
            if(fichas[n][m].getColor() == jj2.getColor() && fichas[n][m].getEstado() > 0)
              contador++;
            else
              encontrado = -1;
          }
          else /*if(contador > 0)*/{
            if(fichas[n][m].getColor() == jj1.getColor() && fichas[n][m].getEstado() > 0)
              encontrado = 1;
            contador++;
          }
//          else
//            encontrado = -1;

        }
        // Voltea fichas si cumplen con condiciones de la busqueda anterior
        i+=stepx; //se mueve a la siguiente ficha
        j+=stepy;
        while(fichas[j][i].getColor()!=jj1.getColor() && fichas[j][i].getEstado() > 0
              && i>=0 && i<8 && j>=0 && j<8){
           if(fichas[j][i].getColor()!=jj1.getColor() && fichas[j][i].getEstado() > 0
             && i>=0 && i<8 && j>=0 && j<8 && fichas[j+stepy][i+stepx].getEstado() > 0 && encontrado == 1){
                fichas[j][i].voltear(jj1);
                jj1.sumarPuntos(1);
                jj2.restarPuntos(1);
                k++;
            }
            i+=stepx; //se mueve a la siguiente ficha
            j+=stepy;
        }
        return k;
    }
    /**Voltea fichas adyacentes para Jugador a si cumplen con los requisitos dados
     * al jugador b
     * @param a Jugador que va a mover
     * @param b Jugador que sera afectado por la movida
     * @param f Referencia a ficha que fue pulsada
     * @return >0 Si se logro hacer algo */
    protected static int voltearFichasAdyacentes(Jugador a, Jugador b, Ficha f){

        int contador = 0,x, y, c, ret = 0;
        boolean encontrado = false;
        fs = new Ficha[8]; // Arreglo de referencias a fichas a voltear
        x = f.getPosx();
        y = f.getPosy();
        c = f.getColor();

        for(int i=0; i<8; i++)
            try{
                //fs[i] = chainNGrados(x,y,c,i);
                ret += chainNGrados(f,a,b,i);
            } catch(Exception e){ // Captura la excepcion si se sale fuera de los limites de array
                System.out.println("Excepcion" + e);
            }
        return ret;

    }
    /**Bloquean los eventos las celdas donde van las fichas
     * @param val Verdadero si se desean bloquear los eventos*/
    public void bloquearCeldas(boolean val){
        bloqCeldas= val;
        for (int i = 0; i<8; i++)
            for (int j = 0; j<8; j++)
                fichas[i][j].setEnabled(val);
    }
    /**@return Retorna estado de bloqueo de las celdas*/
    public boolean getBloqueoCeldas()  {
        return bloqCeldas;
    }

    /**Metodo que finaliza el juego estableciendo el ganador del juego si hubo alguno*/
    public void terminarJuego(){
            bloquearCeldas(true);
            //this.juegoIniciado = false; // Retorna al estado de juego sin iniciar
            setGanador(this.j1,this.j2);
            String winner = new String();//("El Ganador es: ");
            if(this.getGanador() !=null)
                winner = "El Ganador es: " + this.getGanador().getNombre() + " con " + this.getGanador().getPunteo() + " puntos";
            else
                winner = "Hubo un empate entre " + j1.getNombre() + " y " + j2.getNombre();

            /*
            if (j1.getPunteo() > j2.getPunteo())
                ganador = "El Ganador es: " + j1.getNombre() + " con " + j1.getPunteo() + " puntos";
            else if(j1.getPunteo() < j2.getPunteo())
                ganador = "El Ganador es: " + j2.getNombre() + " con " + j2.getPunteo() + " puntos";
            else
                ganador ="Hubo un empate entre " + j1.getNombre() + " y " + j2.getNombre();
*/
            avisoTurno.setText(winner);

    }

    /**Manejador de turnos de los jugadores
     * @param f Ficha pulsada por el mouse en el turno
     * @return Entero = 0 por definicion*/
    public int turnoJugador(Ficha f){
        int x, y, ret;
        x = f.getPosx();
        y = f.getPosy();
        jLabelPunteos.setText(j1.getNombre() + ": " + j1.getPunteo() + "puntos" + "     -     " +
                j2.getNombre() + ": " + j2.getPunteo() + "puntos" );
        avisoTurno.setForeground(Color.darkGray);
        // TURNO JUGADOR 1
        if (turno%2 == 0){
            if(voltearFichasAdyacentes(j1,j2,f) > 0 && f.getEstado() == 0){
                turno++;
                fichas[y][x].voltear(j1);
                j1.sumarPuntos(1);
                col.setColor(j2.getColor());
                avisoTurno.setForeground(col.getColor());
                avisoTurno.setText("Le toca turno a: " + j2.getNombre());
            } else{
                col.setColor(j1.getColor());
                avisoTurno.setForeground(col.getColor());
                avisoTurno.setText("Imposible colocar ficha para " + j1.getNombre() +" en esta posicion");
            }

//            fichas[y][x].voltear(j1);
//            if (fichas[y][x].getColor() == j1.getColor()/* fichas[x][y].getEstado() ==1*/){
//                turno++;
//                j1.sumarPuntos(1);
//                voltearFichasAdyacentes(j1,j2,f);
//                avisoTurno.setText("Le toca turno a: " + j2.getNombre());
//            }
        }
        // TURNO JUGADOR 2
        else if( turno%2 == 1){
            if(voltearFichasAdyacentes(j2,j1,f) > 0 && f.getEstado() == 0){
                turno++;
                fichas[y][x].voltear(j2);
                j2.sumarPuntos(1);
                col.setColor(j1.getColor());
                avisoTurno.setForeground(col.getColor());
                avisoTurno.setText("Le toca turno a: " + j1.getNombre());
            } else{
                col.setColor(j2.getColor());
                avisoTurno.setForeground(col.getColor());
                avisoTurno.setText("Imposible colocar ficha para " + j2.getNombre() +" en esta posicion");
            }

//            fichas[y][x].voltear(j2);
//            if (fichas[y][x].getColor() == j2.getColor()/*fichas[x][y].getEstado() == 2*/){
//                turno++;
//                j2.sumarPuntos(1);
//                voltearFichasAdyacentes(j2,j1,f);
//                avisoTurno.setText("Le toca turno a: " + j1.getNombre());

            //      }
        }

        jLabelPunteos.setText(j1.getNombre() + ": " + j1.getPunteo() + "     -     " +
                j2.getNombre() + ": " + j2.getPunteo());
        // Imprime en pantalla el ganador del juego...
        if (turno == 60){
            terminarJuego();
        }
        return 0;
    }
    /**Cuando el usuario presione se colocara la ficha
     * @param evt Instancia de evento para acceder al objeto activado
     **/
    public void FichaPressed(MouseEvent evt){
        //this.juegoIniciado = true;
        Ficha f = new Ficha();
        f = (Ficha)evt.getSource();
        // si estado a la ficha a la que se llamo es 0 se llama a turno(es permisible un movimiento)
        if (f.getEstado() == 0 && !getBloqueoCeldas()){
            turnoJugador(f);
        }
        //   fichas[i][j].setIcon(defaultIcon)
    }

    public void iniciarJuego()
    {
        this.juegoIniciado = true;
        //bloquearCeldas(false);
    }
    /**Inicializa jugadores
     * @param a Jugador 1
     * @param b Jugador 2*/
    public void setJugador(Jugador a, Jugador b){
        j1 = new Jugador(a); // crea jugador
        j2 = new Jugador(b);
        //j1 = a; // copia a en j1
        setJugPos(j1); // establece posicion inicial del nombre en tablero
        setJugPos(j2);
        j1.setPunteo(2); // Establece punteos iniciales a jugadores
        j2.setPunteo(2);

    }

    /**Inicializa la matriz de fichas y les agrega listeners*/
    private void initFichas(){
        fichas =  new Ficha[8][]; // crea direccion general del puntero
        jPanel1.setSize(240,240);
        try{
            for (i = 0; i < 8;i++){
                fichas[i] = new Ficha[8]; // crea direccion para cada fila
                for (j = 0; j< 8; j++){
                    fichas[i][j]=new Ficha(); // crea direccion para cada columna
                    //       fichas[i] =  new Ficha();
                    fichas[i][j].setPos(j,i);
                    //fichas[i][j].setSize(16, 16);
                    //fichas[i][j].setBorder(new javax.swing.border.LineBorder(new java.awt.Color(0, 0, 0)));
                    fichas[i][j].addMouseListener(new MouseAdapter() {
                        public void mouseReleased(MouseEvent evt) {
                            FichaPressed(evt); // Agrega escucha a evento
                        }
                    }
                    );
                    jPanel1.add(this.fichas[i][j],-1); // Agrega a Panel
                }
            }
        } catch(Exception e){
            System.out.println(e);
        }

    }
    /**Establece posicion en el tablero para el jugador.
     * @param j Jugador que sera posicionado segun sus atributos*/
    public void setJugPos(Jugador j){
        col.setColor(j.getColor());
        switch (j.getPos()){
            case 0:
                jLabelArr.setForeground(col.getColor());
                jLabelArr.setText(j.getNombre());
                break;
            case 1:
                jLabelAb.setForeground(col.getColor());
                jLabelAb.setText(j.getNombre());
                break;
            case 2:
                jLabelIzq.setForeground(col.getColor());
                jLabelIzq.setText(j.getNombre());
                break;
            case 3:
                jLabelDer.setForeground(col.getColor());
                jLabelDer.setText(j.getNombre());
                break;
        }
    }

    /**Inicializa posiciones para las fichas
     * @param cambiar Entero que serbira para cambiar la dispocision inicial de las fichas*/
    public void setPosInicialFichas(int cambiar){
        // Crea posicion inicial para las fichas
        if (juegoIniciado == false){
            int opcion;

            opcion = cambiar;
            switch (opcion){
                case 1:
                    fichas[3][3].voltear(j1);
                    fichas[3][4].voltear(j2);
                    fichas[4][3].voltear(j2);
                    fichas[4][4].voltear(j1);
                    break;
                case 2:
                    fichas[3][3].voltear(j2);
                    fichas[3][4].voltear(j1);
                    fichas[4][3].voltear(j1);
                    fichas[4][4].voltear(j2);
                    break;
                case 3:
                    fichas[3][3].voltear(j2);
                    fichas[3][4].voltear(j2);
                    fichas[4][3].voltear(j1);
                    fichas[4][4].voltear(j1);
                    break;
                case 4:
                    fichas[3][3].voltear(j1);
                    fichas[3][4].voltear(j1);
                    fichas[4][3].voltear(j2);
                    fichas[4][4].voltear(j2);
                    break;
                case 5:
                    fichas[3][3].voltear(j1);
                    fichas[3][4].voltear(j2);
                    fichas[4][3].voltear(j1);
                    fichas[4][4].voltear(j2);
                    break;
                case 6:
                    fichas[3][3].voltear(j2);
                    fichas[3][4].voltear(j1);
                    fichas[4][3].voltear(j2);
                    fichas[4][4].voltear(j1);
                    break;
                default:
                  fichas[3][3].voltear(j1);
                  fichas[3][4].voltear(j2);
                  fichas[4][3].voltear(j2);
                  fichas[4][4].voltear(j1);
                    break;
            }
        }


    }
    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    // <editor-fold defaultstate="collapsed" desc=" Generated Code ">//GEN-BEGIN:initComponents
    private void initComponents() {
        jPanel4 = new javax.swing.JPanel();
        jLabelAb = new javax.swing.JLabel();
        jLabelDer = new javax.swing.JLabel();
        jLabelIzq = new javax.swing.JLabel();
        jLabelArr = new javax.swing.JLabel();
        jPanel2 = new javax.swing.JPanel();
        jPanel1 = new javax.swing.JPanel();
        jPanel3 = new javax.swing.JPanel();
        jPanel6 = new javax.swing.JPanel();
        jLabelPunteos = new javax.swing.JLabel();
        jPanel5 = new javax.swing.JPanel();
        avisoTurno = new javax.swing.JLabel();

        setLayout(new java.awt.BorderLayout());

        jPanel4.setLayout(new java.awt.BorderLayout());

        jLabelAb.setFont(new java.awt.Font("Dialog", 0, 10));
        jLabelAb.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabelAb.setText("jLabel1");
        jPanel4.add(jLabelAb, java.awt.BorderLayout.SOUTH);

        jLabelDer.setFont(new java.awt.Font("Dialog", 0, 10));
        jLabelDer.setText("jLabel2");
        jPanel4.add(jLabelDer, java.awt.BorderLayout.EAST);

        jLabelIzq.setFont(new java.awt.Font("Dialog", 0, 10));
        jLabelIzq.setText("jLabel3");
        jPanel4.add(jLabelIzq, java.awt.BorderLayout.WEST);

        jLabelArr.setFont(new java.awt.Font("Dialog", 0, 10));
        jLabelArr.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabelArr.setText("jLabel4");
        jPanel4.add(jLabelArr, java.awt.BorderLayout.NORTH);

        jPanel1.setLayout(new java.awt.GridLayout(8, 8));

        jPanel1.setBorder(new javax.swing.border.SoftBevelBorder(javax.swing.border.BevelBorder.RAISED));
        jPanel1.setMaximumSize(new java.awt.Dimension(256, 256));
        jPanel1.setMinimumSize(new java.awt.Dimension(128, 128));
        jPanel1.setPreferredSize(new java.awt.Dimension(224, 224));
        jPanel2.add(jPanel1);

        jPanel2.add(jPanel3);

        jPanel4.add(jPanel2, java.awt.BorderLayout.CENTER);

        add(jPanel4, java.awt.BorderLayout.CENTER);

        jPanel6.setBackground(java.awt.Color.white);
        jPanel6.setBorder(new javax.swing.border.LineBorder(new java.awt.Color(0, 0, 0)));
        jLabelPunteos.setFont(new java.awt.Font("Courier", 1, 12));
        jLabelPunteos.setText("Punteos");
        jPanel6.add(jLabelPunteos);

        add(jPanel6, java.awt.BorderLayout.SOUTH);

        jPanel5.setBackground(new java.awt.Color(255, 255, 204));
        jPanel5.setBorder(new javax.swing.border.LineBorder(new java.awt.Color(0, 0, 0)));
        avisoTurno.setFont(new java.awt.Font("Dialog", 1, 14));
        avisoTurno.setForeground(java.awt.Color.darkGray);
        avisoTurno.setText("Jugador No. 1 Inicia el Juego");
        jPanel5.add(avisoTurno);

        add(jPanel5, java.awt.BorderLayout.NORTH);

    }
    // </editor-fold>//GEN-END:initComponents


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel avisoTurno;
    private javax.swing.JLabel jLabelAb;
    private javax.swing.JLabel jLabelArr;
    private javax.swing.JLabel jLabelDer;
    private javax.swing.JLabel jLabelIzq;
    private javax.swing.JLabel jLabelPunteos;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JPanel jPanel3;
    private javax.swing.JPanel jPanel4;
    private javax.swing.JPanel jPanel5;
    private javax.swing.JPanel jPanel6;
    // End of variables declaration//GEN-END:variables

}
