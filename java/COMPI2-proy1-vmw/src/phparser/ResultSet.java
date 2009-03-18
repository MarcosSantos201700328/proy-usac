 /*
 * ResultSet.java
 *
 * Creada el 19 de marzo de 2007, 12:36 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package phparser;

/**
 * Simboliza un resultado devuelto por un recorrido hecho en un AST, y es usado para intercambios
 * @author Erik Giron (200313492)
 *
 */
public class ResultSet {
    
    private int tipo;
    private Object data;
    
    
    
    /** Crea una nueva instancia de ResultSet */
    public ResultSet() {
    }

    /**Constructor de Oficion*/
    public ResultSet(int tipo, Object value){
        this.tipo = tipo;
        this.data = value;
    }
    public Object getData() {
        return data;
    }

    public int getTipo() {
        return tipo;
    }

    public void setData(Object data) {
        this.data = data;
    }
    /**Devuelve representacion de cadena de caracteres del dato interno*/
    public String toString(){
        switch(this.tipo){
            case Ast.N_LIT_FLOAT:
                return new String(((Float)this.data).toString());
            case Ast.N_LIT_INT:
                return new String(((Integer)this.data).toString());
            case Ast.N_LIT_STRING:
                return (String)this.data;
        }
        return new String(this.data.toString());
    }

    public void setTipo(int tipo) {
        this.tipo = tipo;
    }
    
}
