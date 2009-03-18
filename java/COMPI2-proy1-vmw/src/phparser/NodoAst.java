/*
 * NodoAst.java
 *
 * Creada el 18 de marzo de 2007, 07:12 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package phparser;

import java.util.*;
/**
 * Representa un nodo abstracto de la cual se derivaran todos los diferentes tipos de nodos nodos del AST
 * @author Erik Giron (200313492)
 * 
 */
public class NodoAst {
            /**tipo de dato incluido*/
        protected int tipo;
        /**clase de nodo*/
        protected int clase;    
        /**Dato que lleva el nodo del arbol*/
        protected Object data; 
        /**Dato auxiliar para propositos multiples*/
        protected Object aux;
        
    public LinkedList<NodoAst> getSentenciasTrue() {
        return sentenciasTrue;
    }

    public LinkedList<NodoAst> getSentenciasFalse() {
        return sentenciasFalse;
    }
        /**hijo izquierdo del nodo, se tomara este nodo cuando se tiene solo un hijo*/
        protected NodoAst left;

    public Object getAux() {
        return aux;
    }

    public void setAux(Object aux) {
        this.aux = aux;
        
    }
        /**hijo derecho del nodo*/
        protected NodoAst right;
        /**Listado de sentencias verderas*/
        protected LinkedList<NodoAst> sentenciasTrue;
        /**Listado de sentencias falsas*/
        protected LinkedList<NodoAst> sentenciasFalse;
        /**Operador*/        
        protected int operator = -1;

    public void setSentenciasFalse(LinkedList<NodoAst> sentenciasFalse) {
        this.sentenciasFalse = sentenciasFalse;
    }

    public void setSentenciasTrue(LinkedList<NodoAst> sentenciasTrue) {
        this.sentenciasTrue = sentenciasTrue;
    }
    /** Crea una nueva instancia de NodoAst */
    public NodoAst() {
    }
    /** Constructor de Oficio*/
    public NodoAst(int tipo,NodoAst izq,NodoAst der,Object value,int operator){
        this.tipo = tipo;
        this.left = izq;
        this.right = der;
        this.data = value;
        this.operator = operator;
    }

    public int getClase() {
        return clase;
    }

    public Object getData() {
        return data;
    }

    public NodoAst getLeft() {
        return left;
    }

    public int getOperator() {
        return operator;
    }

    public NodoAst getRight() {
        return right;
    }

    public int getTipo() {
        return tipo;
    }
}

/**Nodo para las sentencias if*/
class IfNodoAst extends NodoAst{
    IfNodoAst(){
        this.tipo = 0;
        this.clase = Ast.N_IF;
    }
}

/**Nodo para los operadores*/
