/*
 * ErrorElem.java
 *
 * Creada el 13 de marzo de 2007, 02:25 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package errormanager;

/**
 * elemento que describe a un error de lectura
 * @author Erik Giron (200313492)
 *
 */
public class ErrorElem implements java.io.Serializable{
    int linea; //linea donde ocurrio el error
    int columna; ///columna donde ocurrio el error
    String desc; ///descripcion del error
    /** Crea una nueva instancia de ErrorElem */
    public ErrorElem() {
        
    }
    /**Crea un nuevo error con la descripcion dada*/
    public ErrorElem(String descripcion){
        desc = new String(descripcion);
    }

    public ErrorElem(int linea,int columna,String descripcion){
        setLinea(linea);
        setColumna(columna);
        setDesc(descripcion);
    }
    
    public int getColumna() {
        return columna;
    }

    public String getDesc() {
        return desc;
    }

    public int getLinea() {
        return linea;
    }

    public void setColumna(int columna) {
        this.columna = columna;
    }

    public void setDesc(String desc) {
        this.desc = desc;
    }

    public void setLinea(int linea) {
        this.linea = linea;
    }
    
    public String toString(){
        String ret = new String();
        ret += "En linea:" + this.linea + " Columna:" + this.columna
                + "\nDescripcion:" + this.desc;
        return ret;
    }
    
}
