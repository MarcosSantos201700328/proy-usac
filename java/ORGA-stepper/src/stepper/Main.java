/*
 * Main.java
 *
 * Created on 21 de mayo de 2006, 07:53 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package stepper;

/**
 * Gira un motor stepper dando numero de ciclos y usando puerto paralelo
 * Nota: se necesitara permisos de superusuario para poder ejecutar el prograna
 * @author Erik Giron
 */
public class Main {
    
    static int ciclos;
    private static stepper motor = new stepper();
    /** Creates a new instance of Main */
    public Main() {        
    }
    
    /**
     * @param args the command line arguments
     * 1er parametro: no de ciclos
     * 2do parametro: Velocidad: en rpm
     */
    public static void main(String[] args) {
        try{
            if(args[0] != null){
               
                try{           
                    System.out.println("Se girara el motor " + args[0] + " ciclos");        
                    if(args[1] == null)
                        motor.girarMotor(Integer.parseInt(args[0])); // llamamos a metodo que gira motor a 100 rpm
                    else{
                        System.out.println(" a " + args[1] + " revoluciones por minuto\n");        
                        motor.setVelocidad(Integer.parseInt(args[1])); //asignamos velocidad del motor en rpm
                        motor.girarMotor(Integer.parseInt(args[0])); // llamamos a metodo que gira motor a velocidad dada
                    }
                }
                catch(Exception e){
                    System.out.println("Especifique el numero de ciclos a girar el motor y la velocidad angular (en rpm) como parametro\n ejemplo: \"$ java -jar stepper 3 1500\" hara girar 3 veces el motor a 1500 rpm. \n");        
                    System.out.println(e + "\n\tAsegurese tambien de que tiene permisos de root para escribir al dispositivo lp0");
                    
                }
            }
            else{
                System.out.println("Especifique el numero de ciclos a girar el motor y la velocidad angular (en rpm) como parametro\n ejemplo: \"$ java -jar stepper 3 1500\" hara girar 3 veces el motor a 1500 rpm. \n");        
                System.out.println("\n\tAsegurese tambien de que tiene permisos de root para escribir al dispositivo lp0\n");
            }
        }        
        catch(Exception e){
            System.out.println("Especifique el numero de ciclos a girar el motor y la velocidad angular (en rpm) como parametro\n ejemplo: \"$ java -jar stepper 3 1500\" hara girar 3 veces el motor a 1500 rpm. \n");        
            System.out.println(e + "\n\tAsegurese tambien de que tiene permisos de root para escribir al dispositivo lp0\n");
        }
        // TODO code application logic here
    }

}
