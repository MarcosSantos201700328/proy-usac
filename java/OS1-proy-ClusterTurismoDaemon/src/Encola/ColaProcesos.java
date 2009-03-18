/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package Encola;


import java.sql.*;
import java.util.*;
/**
 * Clase que representa la cola de procesos, para aplicar el
 * FIFO de planificacion
 * @author Erik Giron
 */
public class ColaProcesos implements Runnable{
    private static java.util.LinkedList<Proceso> colaProcesos = new java.util.LinkedList<Proceso>();
    private static java.util.concurrent.Semaphore mutex 
            = new java.util.concurrent.Semaphore(1); //semaforo de exclusion
    //private static java.util.concurrent.Semaphore semaforoColaProcesos;
    private static Proceso procesoActual;/**Proceso actual que se esta ejecutando*/
    
    /**Ejecuta el hilo ColaProcesos*/
    public synchronized void run() {
        while (true){
            if(!colaProcesos.isEmpty()){
                try{
                    //ejecutamos cada proceso que este en cola                        
                    ejecutar();
                    //ponemos al hilo de ejecucion de cola en espera.
                    //this.wait();
                    //Thread.currentThread().yield();
                    //wait();
                    //Administrador.semaforoColaP.acquire();
                    //Luego de ejecutar lo sacamos de la pila
                    mutex.acquire();
                    colaProcesos.removeFirst();                
                    mutex.release();
                    //detenemos el hilo si ya no hay mas elementos en la pila
                   //  semaforoColaProcesos.acquire();
                }
                catch(Exception e){
                    System.out.println("Error al ejecutar cola: "+ e.toString());
                }
                //Imprimimos cola de procesos por cada iteracion
                System.out.println(Administrador.getCola().toString());
            } 
            else{
                //nos eliminamos la tabla de transaccion
                borrarTransacciones();
                break;
            }
        }
        this.notifyAll();
        //Administrador.semaforoColaP.release();
    }
    /**Ejecuta la cola de procesos*/
    public void exec(){
        while (true){
            if(!colaProcesos.isEmpty()){
                try{
                    //ejecutamos cada proceso que este en cola                        
                    ejecutar();
                    //ponemos al hilo de ejecucion de cola en espera.
                    //this.wait();
                    //Thread.currentThread().yield();
                    //wait();
                    //Administrador.semaforoColaP.acquire();
                    //Luego de ejecutar lo sacamos de la pila
                    mutex.acquire();
                    colaProcesos.removeFirst();                
                    mutex.release();
                    //detenemos el hilo si ya no hay mas elementos en la pila
                   //  semaforoColaProcesos.acquire();
                }
                catch(Exception e){
                    System.out.println("Error al ejecutar cola: "+ e.toString());
                }
            } 
            else{
                //nos eliminamos la tabla de transaccion
                borrarTransacciones();
                break;
            }
            //Imprimimos cola de procesos por cada iteracion
                System.out.println(Administrador.getCola().toString());
        }
    }
    //Crea un nuevo proceso y lo agrega a la cola
    public void agregarProcesos(int tId){
        Proceso nuevo = new Proceso(Thread.currentThread(),tId);        
        encolar(nuevo);
    }
    /**Agrega proceso nuevo a la cola de procesos*/
    private static void encolar(Proceso p){        
        //Agregamos a cola de procesos
        try{
            mutex.acquire();
            colaProcesos.addLast(p);
            mutex.release();
        
        }
        catch(Exception e){
            System.out.println("Imposible encolar proceso: "+ e.toString());
        }
        
        //
    }
        
        /** Ejecuta el proceso situado en la cima de la cola*/
    private static void ejecutar() throws Exception{        
        Thread t;        
        try{
            // obtenemos proceso
            mutex.acquire();
            procesoActual = colaProcesos.peekFirst();
            mutex.release();
            //ejecutamos proceso
            //t = new Thread(procesoActual);        
            procesoActual.ejecutar();
            //t.start();            
        }
        catch(Exception e){
            System.out.println("Imposible ejecutar proceso en cola: " + e);
            throw e;
        }
        
    }
    /**Borra transacciones pendientes*/
    private static void borrarTransacciones(){
        String query = "delete from Transaccion;";        
        ResultSet s = null;        
        try{
            s = Administrador.getConexion().ejecutarQuery(query,1);
        }
        catch(Exception e){       
            System.out.println("Imposible borrar transacciones: "+ e.toString());
        }
    }
    /**Devuelve el contenido de la cola de procesos*/
    public String toString(){
        String str = new String();
        Iterator i = this.colaProcesos.iterator();
        int n = 0;
        Proceso actual;
        str +="Cola de Procesos\n";
        str +="================";
        try{
            mutex.acquire();
            while (i.hasNext()){                
                actual = (Proceso) i.next();                                
                str += n + " -> " + actual.toString() + "\n";
                n++;            
            }
            mutex.release();
        }
        catch(InterruptedException e){            
            System.out.println("muestreo interrumpido "+ e.toString());
        }
        catch(Exception e){
            System.out.println("muestreo interrumpido "+ e.toString());
        }
        finally{
            return str;
        }
    }
}
