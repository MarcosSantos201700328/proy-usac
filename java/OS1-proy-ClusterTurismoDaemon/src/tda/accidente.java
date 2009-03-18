/*
 * accidente.java
 *
 * Created on 7 de diciembre de 2007, 05:11 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package tda;
//miras esto

/**
 *
 * @author cristian
 */
public class accidente {
    private String nombre;
    private String tipo;
    private String Departamento;
    
    /** Creates a new instance of accidente */
    public accidente(String n, String t, String d) {
        nombre = n; tipo = t; Departamento = d;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public String getDepartamento() {
        return Departamento;
    }

    public void setDepartamento(String departamento) {
        this.Departamento = departamento;
    }
    
}
