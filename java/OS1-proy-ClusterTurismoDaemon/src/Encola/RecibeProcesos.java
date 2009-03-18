/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Encola;
import java.net.* ;
import java.io.* ;



/**
 * Clase que escucha en el socket la informacion enviada para que sea procesada
 * @author Erik Giron
 */
public class RecibeProcesos implements Runnable{
    private ColaProcesos cola;
    private Thread threadPadre;
    RecibeProcesos(){
        
    }
    
    RecibeProcesos(ColaProcesos q,Runnable padre){
        cola = q;
        threadPadre = new Thread(padre);
    }
    /**Punto de entrada, escucha por puerto 8031 de UDP una nueva tarea enviada por el front-end administrador*/
    public synchronized void run(){
        try
        {
            int tamaPaquete = 1024;
            DatagramSocket s = new DatagramSocket(8031) ;
            Transaccion tActual;
            synchronized (threadPadre){
                while (true)
                {
                    //leemos mensaje de chucho
                        DatagramPacket datagramaUDP =  new DatagramPacket( new byte [tamaPaquete], tamaPaquete) ;
                        s.receive(datagramaUDP);
                        String msg = new String(datagramaUDP.getData()).trim() ;                                                               
                        
                        System.out.println("Recibido mensaje " + datagramaUDP.getAddress().getHostName() + " - " + msg) ;
                        if(msg != null && msg.length() > 0){
                            if(Integer.parseInt(msg) >= 0){ //si chucho manda mensaje positivo, agregamos a cola
                                cola.agregarProcesos(Integer.parseInt(msg)); 
                            }
                            else{
                                //Thread tCola = new Thread(cola);
                                //tCola.start(); //ejecutamos procesos
                                //wait();
                                cola.exec();
                                //Thread.currentThread().yield();
                                //Administrador.semaforoRP.acquire();
                                enviarAcknowledge();
                                threadPadre.notify(); //despertamos thread padre
                                //Administrador.semaforoAdmin.release();
                                break; //nos salimos del hilo
                            }

                        }                    
                        //Imprimimos cola de procesos por cada iteracion
                        System.out.println(Administrador.getCola().toString());

                }
                s.close();
            }
            
        }
        catch (Exception e)
        {
            System.out.println("Error en proceso: "+ e);
        }
    }

    public ColaProcesos getCola() {
        return cola;
    }

    public void setCola(ColaProcesos cola) {
        this.cola = cola;
    }
    /**Envia acknowledge al programa administrador de  que las tareas fueron ejecutadas*/
    private void enviarAcknowledge(){
        try{
            String cadena = null;
            byte[] paqueteBytes = null;
            DatagramPacket paqueteUDP = null;

            InetAddress direccion = InetAddress.getByName(Administrador.IP_ADMINISTRADOR) ;

            long inicio = System.currentTimeMillis();

            DatagramSocket socketUDP = new DatagramSocket() ;
            cadena = new String(Integer.toString(-1));
            paqueteBytes = cadena.getBytes() ;
            paqueteUDP = new DatagramPacket(paqueteBytes, paqueteBytes.length,direccion,8031);
            socketUDP.send(paqueteUDP) ;
            socketUDP.close() ;

        } 
        catch(Exception e){
            System.out.println("Imposible enviar acknowledge: "+ e.toString());
        }
    }
            
}
