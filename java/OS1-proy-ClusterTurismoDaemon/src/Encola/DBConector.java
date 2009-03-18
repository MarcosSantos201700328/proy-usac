/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package Encola;
import java.sql.*;
/**
 * Clase para la conexion a la base de datos
 * @author Erik Giron
 */
public class DBConector {
     Connection conn = null;
     String userName = "root";
     String password = "kreig";
     String url = "jdbc:mysql://localhost:3306/turismo";     
     
    DBConector(){
    }
    
    DBConector(String pUrl, String pUser, String pPass){
        url = pUrl;
        userName = pUser;
        password = pPass;
    }
    /** Conecta a la base de datos establecida*/
    public void conectar() throws Exception{
        Class.forName("com.mysql.jdbc.Driver").newInstance();
        conn = DriverManager.getConnection(url, userName, password);
        System.out.println ("Conexion establecida");   
    }
    /** Conecta a la base de datos establecida*/
    public void desconectar() throws Exception{
        if(conn != null)
            conn.close ();
    }
    /**Ejecuta un query a la base de datos y devuelve resultados en el resultset*/
    public ResultSet ejecutarQuery(String Query,int tipo) throws Exception{
        Statement s = conn.createStatement ();        
        
        if(tipo == 0)
            s.executeQuery (Query);
        else          
            s.executeUpdate(Query);
        ResultSet rs = s.getResultSet ();
        return rs;
    }
}
