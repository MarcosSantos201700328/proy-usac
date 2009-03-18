/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package Encola;
import java.util.concurrent.*;
/**
 * Clase principal que administra las cola de procesos
 * @author Erik Giron
 */
public class Administrador implements Runnable {
    public static final String IP_NODO = new String("192.168.1.6");
    public static final String IP_ADMINISTRADOR = new String("192.168.1.2");
    private static ColaProcesos cola = new ColaProcesos();
    private RecibeProcesos rp = new RecibeProcesos(cola,this);
    private static DBConector conexion = new DBConector("jdbc:mysql://localhost:3306/turismo","root","kreig");
    private static boolean salir = false;
    public static Semaphore semaforoAdmin = new Semaphore(1);
    public static Semaphore semaforoColaP = new Semaphore(1);
    public static Semaphore semaforoRP = new Semaphore(1);

    public static ColaProcesos getCola() {
        return cola;
    }

    public static void setCola(ColaProcesos aCola) {
        cola = aCola;
    }

    public RecibeProcesos getRp() {
        return rp;
    }

    public void setRp(RecibeProcesos aRp) {
        rp = aRp;
    }

    public static DBConector getConexion() {
        return conexion;
    }

    public static void setConexion(DBConector aConexion) {
        conexion = aConexion;
    }
    Administrador(){
        rp.setCola(cola); //asignamos cola de procesos al recibe procesos
        try{
            conexion.conectar();        
        }
        catch(Exception e){
            System.out.println("Imposible conectar :" + e);
        }
        
        
    }
    
    public static void main(String args[]){
        Administrador a = new Administrador();
        Thread t = new Thread(a);
        t.start();
    }
    
    /**Ejecuta el administrador de procesos*/
    public void ejecutar(){  
        Thread t_rp = new Thread(getRp());
        Thread t_cola = new Thread(getCola());
        t_rp.start();
               
    }

    public synchronized void run() {
        try{
            while (true){
                ejecutar();        
                wait();
                //getConexion().desconectar();
            }
            
            //Thread.currentThread().wait();
            //Thread.currentThread().yield();
            //Administrador.semaforoAdmin.acquire();
            //this.wait();
            
        }
        catch(Exception e){
            System.out.println("Imposible ejecutar: "+ e.toString());
        }      
    }

}
