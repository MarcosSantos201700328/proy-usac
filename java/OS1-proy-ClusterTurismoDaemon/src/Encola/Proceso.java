/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package Encola;

/**
 *
 * @author Erik Giron
 */
import javax.xml.*;
import javax.sql.*;
import java.sql.*;
import java.net.* ;
import java.io.* ;
import java.util.*;
/**Clase que representa un proceso que se esta ejecutando*/
public class Proceso implements Runnable{
    int prioridad; //Prioridad del proceso
    String tabla; // tabla a la que se lee
    int timeOut; //Tiempo de espera
    String tablaPK; //Primaky Key de la tabla
    private Thread colaProcesos; // Hilo de cola de procesos
    private int transaccionId; // Id de transaccion
    private String query;
    private int tiempo;
    private int status;
    private int fase;
    private int tipoOperacion;
    
    /**Crea un nuevo proceso
     @param cola cola padre de procesos,
     @param rowId Id de transaccion donde se encuentra el proceso a ejecutar*/
    Proceso(Thread cola, int tId){        
        colaProcesos = cola;
        this.transaccionId = tId; 
        obtenerInfo();// obtenemos info de la DB
        
    }
    
    /**Ejecuta un nuevo proceso en el nodo del cluster, y espera respuesta de finalizacion*/    
    public void ejecutar(){
         //Enviamos mensaje a kakaroto
        enviaProceso();
        int respuesta;
        //while (true){
            //esperamos mensaje de kakaroto de respuesta;
            respuesta = recibeRespuesta();
            //leemos mensaje de la db;
            if(respuesta == transaccionId){
                //asignamos nuevo estado
                status = 1;
                fase = 5;
                guardarTransaccion(); // guardamos datos en BD
                // si hay mensaje de respuesta, terminamos el hilo,      
                //break;
            }
            
        //}
        //synchronized (colaProcesos){
        //    colaProcesos.notify();
        //}
        //Reiniciamos proceso de la cola de procesos
        
        //Administrador.semaforoColaP.release();
    }
    /**Ejecuta un nuevo proceso en el nodo del cluster, y espera respuesta de finalizacion*/
    public synchronized void run(){
        //Enviamos mensaje a kakaroto
        enviaProceso();
        int respuesta;
        //while (true){
            //esperamos mensaje de kakaroto de respuesta;
            respuesta = recibeRespuesta();
            //leemos mensaje de la db;
            if(respuesta == transaccionId){
                //asignamos nuevo estado
                status = 1;
                fase = 5;
                guardarTransaccion(); // guardamos datos en BD
                // si hay mensaje de respuesta, terminamos el hilo,      
                //break;
            }
            
        //}
        //synchronized (colaProcesos){
        //    colaProcesos.notify();
        //}
        //Reiniciamos proceso de la cola de procesos
        
        //Administrador.semaforoColaP.release();
    }
    //Obtiene toda la informacion del proceso de la transaccion dada en la BD
    public void obtenerInfo(){
        //Leemos de la BD informacion de la transaccion
        String xmlData;
        ResultSet s = null;
        String query = "SELECT * from Transaccion where transaccion = " +transaccionId + ";";
        try{
            s = Administrador.getConexion().ejecutarQuery(query,0);
            if (s != null && s.first()){                
                //leemos transaccion
                
                tabla = new String(s.getString("tabla"));
                this.query = new String(s.getString("query"));
                status = s.getInt("status");
                fase = s.getInt("fase");
                //xmlData = s.getString("xmlData");
                timeOut = s.getInt("delay");
                tipoOperacion = s.getInt("tipoOperacion");
                tablaPK = s.getString("PKTabla");
                //Asignamos prioridad
                //asignamos prioridad segun el tipo de operacion
                this.prioridad = tipoOperacion;
                this.timeOut = 1000;//(Math.random() * 10000);
                s.close();                                
                guardarTransaccion();
            }                       
        }
        catch(Exception e){
            System.err.println("Imposible realizar tarea de DB: "+ e );
        }
                
    }
    /**Almacena transaccion modificada en la base de datos*/
    private void guardarTransaccion(){
        String query = "update Transaccion t set t.prioridad = "+this.prioridad +", t.delay = "+/*this.timeOut*/(int)(Math.random()*10000) +",  t.fase =" +this.fase+ ",  t.status = " +this.fase+" where t.transaccion = 1;";        
        ResultSet s = null;        
        try{
            s = Administrador.getConexion().ejecutarQuery(query,1);
        }
        catch(Exception e){
            System.err.println("Imposible realizar tarea de DB: "+ e );
        }
    }
    
    /**Almacena transaccion modificada en la base de datos*/
    private static void CrearTransaccionPrueba(){
        String query = "INSERT INTO `Transaccion` ( `tabla` , `transaccion` , `query` , `tiempo` , `delay` , `prioridad` , `status` , `fase` , `PKTabla` , `tipoOperacion` )VALUES ('abc', '666', 'asdfasdf', NOW( ) , '0', '0', '0', '0', 'asdfasdf', '1');";
                //"update Transaccion t set t.prioridad = "+this.prioridad +", t.delay = "+this.timeOut +",  t.fase =" +this.fase+ ",  t.status = " +this.fase+" where t.transaccion = 1;";        
        ResultSet s = null;        
        try{
            s = Administrador.getConexion().ejecutarQuery(query,0);
        }
        catch(Exception e){
            System.err.println("Imposible realizar tarea de DB: "+ e );
        }
    }
    
    /**Almacena transaccion modificada en la base de datos*/
    private static ResultSet ConsultarTransaccionPrueba(){
        String query = "Select * from Transaccion;";
        ResultSet s = null;        
        try{
            s = Administrador.getConexion().ejecutarQuery(query,0);
            
        }
        catch(Exception e){
            System.err.println("Imposible realizar tarea de DB: "+ e );
        }
        return s;
    }
    
     /**Almacena transaccion modificada en la base de datos*/
    private static void GuardarTransaccionPrueba(){
        String query = "update Transaccion t set t.prioridad = 5, t.delay = 5,  t.fase =5,  t.status = 5 where t.transaccion = 666;";        
        ResultSet s = null;        
        try{
            s = Administrador.getConexion().ejecutarQuery(query,1);
        }
        catch(Exception e){
            System.err.println("Imposible realizar tarea de DB: "+ e );
            
        }
    }
    
    private static void borrarTransaccionPrueba(){
        String query = "delete from Transaccion t where t.transaccion = 666;";        
        ResultSet s = null;        
        try{
            s = Administrador.getConexion().ejecutarQuery(query,0);
        }
        catch(Exception e){            
            System.err.println("Imposible realizar tarea de DB: "+ e );
        }
    }
    
    /**Envia proceso a nodo del cluster para ejecucion*/
    private void enviaProceso(){
        try{
            String cadena = null;
            byte[] paqueteBytes = null;
            DatagramPacket paqueteUDP = null;

            InetAddress direccion = InetAddress.getByName(Administrador.IP_NODO) ;

            long inicio = System.currentTimeMillis();

            DatagramSocket socketUDP = new DatagramSocket() ;
            cadena = new String(Integer.toString(transaccionId));
            paqueteBytes = cadena.getBytes() ;
            paqueteUDP = new DatagramPacket(paqueteBytes, paqueteBytes.length,direccion,8033);
            socketUDP.send(paqueteUDP) ;
            System.out.println(Integer.toString(transaccionId) + "\n");
            socketUDP.close() ;

        } 
        catch(Exception e){
            System.out.println("Error al enviar proceso: " + e.toString());
        }
    }
    
    private static void enviaProcesoPrueba(){
        try{
            String cadena = null;
            byte[] paqueteBytes = null;
            DatagramPacket paqueteUDP = null;

            InetAddress direccion = InetAddress.getByName("192.168.1.2") ;

            long inicio = System.currentTimeMillis();

            DatagramSocket socketUDP = new DatagramSocket() ;
            cadena = new String(Integer.toString(-1));
            paqueteBytes = cadena.getBytes() ;
            
            paqueteUDP = new DatagramPacket(paqueteBytes, paqueteBytes.length,direccion,8033);
            //for (int i=0; i < 50; i++){
                socketUDP.send(paqueteUDP) ;
            //    Thread.sleep(50);
            //}
            socketUDP.close() ;

        } 
        catch(Exception e){
            
        }
    }
    
    private int recibeRespuesta(){
        try
        {
            int tamaPaquete = 1024;
            DatagramSocket s = new DatagramSocket(8033) ;
            DatagramPacket datagramaUDP =  new DatagramPacket( new byte [tamaPaquete], tamaPaquete) ;
            s.receive(datagramaUDP) ;

            String msg = new String(datagramaUDP.getData()).trim() ;
            System.out.println("Recibido mensaje " + datagramaUDP.getAddress().getHostName() + " - " + msg) ;
            s.close();
            return Integer.parseInt(msg);
            
        }
        catch (Exception e)
        {
            System.out.println("Error en proceso: " + e.toString());
        }
        return -1;
    }
    
    private static int recibeRespuestaTest(){
        try
        {
            int tamaPaquete = 1024;
            DatagramSocket s = new DatagramSocket(8033) ;
            DatagramPacket datagramaUDP =  new DatagramPacket( new byte [tamaPaquete], tamaPaquete) ;
            s.receive(datagramaUDP) ;

            String msg = new String(datagramaUDP.getData()).trim() ;
            System.out.println("Recibido mensaje " + datagramaUDP.getAddress().getHostName() + " - " + msg) ;
            s.close();
            return Integer.parseInt(msg);
            
        }
        catch (Exception e)
        {
            System.out.println("Error en proceso: " + e.toString());
        }
        return -1;
    }
    
    public static void main(String args[]){
        //pruebaComChucho();
        //pruebaDB();
        //pruebaComKkroto();
        for(int i = 0;i < 10; i++){
            System.out.println("Random:" + (int)(Math.random()*10000) +"\n");
        }
    }
    
    private static void pruebaDB(){
        ResultSet R;
        try{
            Administrador.getConexion().conectar();
            CrearTransaccionPrueba();
            R = ConsultarTransaccionPrueba();
            GuardarTransaccionPrueba();
            borrarTransaccionPrueba();        
            Administrador.getConexion().desconectar();
        }
        catch (Exception e){
            System.out.println("Error:" + e);
        }
        finally{

        }
        
        
        
    }
    private static void pruebaComChucho(){
        Stack respuesta = new java.util.Stack();
        int actual = 0;
        while(true){
            actual = recibeRespuestaTest();
            if(actual == -1){
                try{
                    Thread.sleep(300);                
                    enviaProcesoPrueba();  
                }
                catch(Exception e){
                    System.out.println("Error en enviar pvoexo: " + e.toString());
                }
                finally{
                    break;
                }
            }
            else                
                respuesta.add(actual);                            
        }
    }
    
    private static void pruebaComKkroto(){
        Stack respuesta = new java.util.Stack();
        int actual = 0;
        while(true){
            try{
                    Thread.sleep(300); 
                    enviaProcesoPrueba();                                     
                    actual = recibeRespuestaTest();                    
                }
                catch(Exception e){
                    System.out.println("Error en proceso kakaroto: " + e.toString());
                    break;
                }
                finally{
                    
                }
        }

        
    }
    /**Devuelve los datos del proceso*/
    public String toString(){
        String str = new String();
        
        str += "Proceso:" + this.transaccionId + ",Tabla:"+this.tabla+ ",Dato" + this.tablaPK + ", tiempo:" + this.tiempo;       
        
        return str;
    }
            

}
