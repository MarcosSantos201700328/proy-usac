/*
 * Quadruplo.java
 *
 * Creada el May 29, 2007, 10:28 AM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package optimizer;

import java.util.*;
/**
 * Representacio abstracta de un cuadruplo de tres direcciones
 * @author Erik Giron (200313492)
 *
 */
public class Quadruplo {
    public static final int T_SCALARASIG = 100;
    public static final int T_ARITOP = 101;
    public static final int T_DESREF = 102;
    public static final int T_VECTORASIG = 103;
    public static final int T_IGNORE= 104;
    public static final int T_LABEL= 105;
    public static final int T_GOTO = 106;
    public static final int T_IF = 107;
    public static final int T_BEGIN = 108;
    public static final int T_END = 109;
    /** Crea una nueva instancia de Quadruplo */
    public Quadruplo() {
    }
    
    /**Crea nueva instancia*/
    public Quadruplo(Elem o1, Elem o2, Elem res, int op, int tipo, int l){
        this.operando1 = o1;
        this.operando2 = o2;
        this.resultado = res;
        this.operador = op;
        this.tipo = tipo;
        this.linea = l;
    }
    
    
    private int tipo = 0;
    private Elem operando1 = new Elem();
    private Elem operando2 = new Elem();
    private Elem resultado = new Elem();
    private int operador = -1;
    private int linea = -1;
    private int tipoOptim = 0; // se ira agregando como flags donde el bit 0 da optimizacion aritmetica, bit 1 da optimizacion por saltos
    

    public int getLinea() {
        return linea;
    }

    public int getOperador() {
        return operador;
    }

    public int getTipo() {
        return tipo;
    }

    public Elem getOperando1() {
        return operando1;
    }

    public Elem getOperando2() {
        return operando2;
    }

    public Elem getResultado() {
        return resultado;
    }

    public int getTipoOptim() {
        return tipoOptim;
    }
    
    /**Clona el objeto actual*/
    public Quadruplo(Quadruplo q){         
        this(new Elem(q.getOperando1()), new Elem(q.getOperando2()), new Elem(q.getResultado()), q.getOperador(), q.getTipo(), q.getLinea());
        this.setTipoOptim(q.getTipoOptim());
    }

    public void setOperador(int operador) {
        this.operador = operador;
    }

    public void setLinea(int linea) {
        this.linea = linea;
    }

    public void setOperando1(Elem operando1) {
        this.operando1 = operando1;
    }

    public void setOperando2(Elem operando2) {
        this.operando2 = operando2;
    }

    public void setResultado(Elem resultado) {
        this.resultado = resultado;
    }

    public void setTipo(int tipo) {
        this.tipo = tipo;
    }

    public void setTipoOptim(int tipoOptim) {
        this.tipoOptim = tipoOptim;
    }
    
    public String toString(){
        String ret;// = new String();
        String signo;
        switch (this.operador){
            case Optimizer.OP_GT:
                signo = new String(">");
                break;
            case Optimizer.OP_LT:
                signo = new String("<");
                break;
            case Optimizer.OP_NE:
                signo = new String("!=");
                break;
            case Optimizer.OP_EQ:
                signo = new String("==");
                break;
            case Optimizer.OP_GE:
                signo = new String(">=");
                break;
            case Optimizer.OP_LE :
                signo = new String("<=");
                break;
            case Optimizer.OP_MOD:
                signo = new String("%");
                break;
            case Optimizer.OP_DIV:
                signo = new String("/");
                break;
            case Optimizer.OP_MULT:
                signo = new String("*");
                break;
            case Optimizer.OP_MINUS:
                signo = new String("-");
                break;
            case Optimizer.OP_PLUS:
                signo = new String("+");
                break;
            case -1:
                signo = new String("");
                break;
            default:
                signo = new String("?");
                break;
        }
        switch(this.tipo){
            case T_ARITOP:
                ret = new String(this.resultado.toString() + " = " + this.operando1.toString() + " " + signo + " " + this.operando2.toString() + ";");
                break;
            case T_BEGIN:
                ret = new String("void " + this.resultado.toString() + "() {");
                break;
            case T_DESREF:
                ret = new String(this.resultado.toString() + " = " + this.operando1.toString() + "[" + this.operando2.toString() + "];");
                break;
            case T_END:
                ret = new String("}");
                break;
            case T_GOTO:
                ret = new String("goto " + this.resultado.toString());
                break;
            case T_IF:
                ret = new String("if ( " + operando1.toString() + signo + operando2.toString() +" ) goto " + resultado +";");
                break;
            case T_IGNORE:
                ret = new String(this.operando1.toString());
                break;
            case T_LABEL:
                ret = new String(this.resultado.toString() + ":");
                break;
            case T_SCALARASIG:
                ret = new String(this.resultado.toString() + " = " + this.operando1.toString() + ";");
                break;
            case T_VECTORASIG:
                ret = new String(this.resultado.toString()  + "[" + this.operando2.toString() + "] = " + this.operando1.toString() + ";");                
                break;
            default:
                ret = new String("//--");                
                break;
        }
        return ret;
    }
    
}
