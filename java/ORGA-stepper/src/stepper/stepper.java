/*
 * stepper.java
 *
 * Creada el 21 de mayo de 2006, 08:41 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package stepper;
import java.io.*;
/**
 * Clase controladora que hace girar un motor stepper desde un puerto paralelo aprovechando 
 * el dispositivo por bloques /dev/lp0 que el kernel de linux provee
 *
 * @author Erik Giron (200313492)
 *
 */
public class stepper {
    static int timeout = 50;
    int ciclos = 0;
    int valor = 1;
    private Writer out;
    /** Crea una nueva instancia de stepper */
    public stepper() {
        
    }
    /** Crea una nueva instancia, activando cada bobina en los milisigeundos dados
     @param timeout Intervalo de activacion de cada bobina*/
    public stepper(int t){
        timeout = t;
    }
    public void setTimeout(int time){
        timeout = time;
    }
    /**Asigna velocidad dada en rpm*/
    public void setVelocidad(int vel){
        timeout = 1000*60/(vel*4);
    }
    /**Gira motor enviando mensajes cada 100 milisegundos
    @param ciclos ciclos a girar el motor*/
    public synchronized void girarMotor(int ciclos) throws Exception{
        // Abrimos el dispositivo lp0 para escritura en el puerto paralelo y 
        // establecemos el buffer a 8 bits.
        out = new PrintWriter(new BufferedWriter(new FileWriter("/dev/lp0"),8));
        for(int i = 0; i < ciclos; i++){
            for (int j =0; j < 4; j++){   
                out.write((int)valor << j);     //desplazamos un bit a la izquierda y mandamos byte desplazado hacia lp0
                System.out.println("Grado Actual: " + (j*90) + " Valor actual: " + Integer.toBinaryString(valor << j)); //imprimimos estado hacia consola                
                this.wait(timeout); //retardamos el hilo tantos milisegundos dados por timeout
            }
        }  
    }
}
