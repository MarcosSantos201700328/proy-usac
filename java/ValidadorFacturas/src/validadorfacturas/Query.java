/*
 * Query.java
 *
 * Creada el October 5, 2007, 11:39 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package validadorfacturas;
import java.sql.*;
import java.util.*;
/**
 * Clase conexion y comunicacion con la base de datos
 * @author Erik Giron (200313492)
 *
 */
public class Query {
    ///CAMBIAR ESTO SEGUN LA BASE DE DATOS QUE SE UTILICE
    private static String login = "kreig"; //Usuario de la base de datos
    private static String password = "kreig"; // password de la base de datos
    private static String url = "jdbc:mysql://localhost/Information"; //URI de la base de datos
    private static String driverPackage = "com.mysql.jdbc.Driver";

    //Objeto Connection
    private Connection conn = null;
    
    //Lista de numeros para ejecutar query 1
    private static TreeMap<Integer,Integer> listaNumeros = new TreeMap<Integer,Integer>();
    
    /** Crea una nueva instancia de Query */
    public Query() {
        
    }
    
    /**conecta con el DBMS*/
    public void conectar(){
        try{
            Class.forName(driverPackage).newInstance();
            conn = DriverManager.getConnection(url,login,password); 
        }
        catch(SQLException ex){
            System.out.println("Imposible conectar: " + ex + "\n Favor verificar en el archivo Query.java si \nlos parametros de conexion son los correctos\n\n");
            MainWindow.println("Imposible conectar: " + ex+ "\n Favor verificar en el archivo Query.java si \nlos parametros de conexion son los correctos\n\n");
        }
        catch(ClassNotFoundException ex){
            System.out.println("Imposible conectar: " + ex + "\n Favor verificar en el archivo Query.java si \nlos parametros de conexion son los correctos\n\n");
            MainWindow.println("Imposible conectar: " + ex + "\n Favor verificar en el archivo Query.java si \nlos parametros de conexion son los correctos\n\n");
        }
        catch(Exception ex){
            System.out.println("Imposible conectar: " + ex + "\n Favor verificar en el archivo Query.java si \nlos parametros de conexion son los correctos\n\n");
            MainWindow.println("Imposible conectar: " + ex + "\n Favor verificar en el archivo Query.java si \nlos parametros de conexion son los correctos\n\n");
        }
    }
    /**Desconecta con el DBMS*/
    public void desconectar(){
        try{
            conn.close();
        }
        catch(SQLException ex){
            System.out.println("Imposible desconectar: " + ex);
            MainWindow.println("Imposible desconectar: " + ex);
        }
    }    
    
    /**Ejecuta query de fechas (query 2 segun enunciado), se resolvio usando sql*/
    public void ejecutarQueryFechas(String serie, String fechaInic, String fechaFin){
        try{
             Statement stmt = conn.createStatement();
             ResultSet res  = stmt.executeQuery(" select e2.* from Invoices e2 where not exists(select e1.* from Invoices e1 where e1.initdate>='"+fechaInic+"' and e1.initdate<='"+fechaFin+"' and e1.Serie = e2.Serie and e1.Number=e2.Number && e1.serie='"+serie+"');");
                System.out.println("Reporte de facturas faltantes segun fecha de la serie " + serie  + " para el rango dado:");
                MainWindow.println("Reporte de facturas faltantes segun fecha de la serie " + serie  + " para el rango dado:");
                System.out.println("\nSerie \t Numero \t Cantidad \t Fecha \n");
                MainWindow.println("\nSerie \t Numero \t Cantidad \t Fecha \n");
                while(res.next()){
                   String sr  = res.getString("Serie");
                   String numb   = res.getString("Number");
                   String qty = res.getString("total");
                   String date = res.getString("initdate");

                   System.out.println(sr +" \t "+numb+" \t "+qty + "\t" +  date);
                   MainWindow.println(sr +" \t "+numb+" \t "+qty + "\t" +  date);
                }

                res.close();
                stmt.close(); 
        }
        catch(SQLException ex){
            System.out.println("Imposible desconectar: " + ex);
        }
    }
    
    /**Ejecuta consulta para buscar numeros de facturas inexistentes dentro de un rango*/
    public void ejecutarQueryRangos(String serie, int numInic, int numFin) {
         try{
                Statement stmt = conn.createStatement();
                ResultSet res  = stmt.executeQuery("select Number from Invoices where Serie='" + serie + "';");
                while(res.next()){
                   String numb   = res.getString("Number");
                   insertarALista(numb,numInic,numFin);                   
                }
                imprimirLista(serie);
                limpiarLista();
                res.close();
                stmt.close(); 
        }
        catch(SQLException ex){
            System.out.println("Imposible desconectar: " + ex);
        }
    }
    
    /**Agrega numero recien leido a la lista estatica*/
    private static void insertarALista(String numb,int numInic, int numFin) {
        try{
            Integer number = new Integer(Integer.parseInt(numb));
            if(number >= numInic && number <= numFin)
                listaNumeros.put(number,number);
        }
        catch (NumberFormatException e){
            
        }
        catch (Exception e){
            
        }
    }
    
    /**Imprime listado de numeros de facturas faltantes segun la lista*/
    private static void imprimirLista(String serie){
        Object[] listado = listaNumeros.keySet().toArray();
        int numInic;
        int numFin;
        //Imprimimos titulo
        System.out.println("Reporte de facturas faltantes de la serie " + serie  + " para el rango dado:");
        MainWindow.println("Reporte de facturas faltantes de la serie " + serie  + " para el rango dado:");
        //recorremos todo el array de integers en busca de discontinuidades
        if(listado.length >= 1){
            for(int i=0; i < listado.length - 1; i++){
                numInic = ((Integer)listado[i]).intValue();
                numFin = ((Integer)listado[i+1]).intValue();
                if(numFin - numInic > 1){
                    for(int j = numInic + 1; j < numFin; j++){
                        System.out.println("Serie: " + serie + " Numero: " + j);
                        MainWindow.println("Serie: " + serie + " Numero: " + j);
                    }
                }
            }
        }
        else{
            System.out.println("Aviso: No se encontro ninguna factura entre el rango especificado para la serie dada");
            MainWindow.println("Aviso: No se encontro ninguna factura entre el rango especificado para la serie dada");
        }
            
    }
    /**Limpia el listado de numeros*/
    private static void limpiarLista() {
        listaNumeros.clear();
    }

    /**Devuelve true si se establecio una conexion exitosa*/
    boolean estaConectado() {
        if(conn == null)
            return false;
        return true;
    }

}


