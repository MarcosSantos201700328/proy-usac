/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package Encola;

/**
 * Transaccion a realizar
 * @author Erik Giron
 */
/*
 * transaccion.java
 *
 * Created on 2 de diciembre de 2007, 17:15
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */
public class Transaccion {

    private int Id;
	private String query;//chucho
        //public javax.sql.date timeSend; // Fecha de envio
	private java.sql.Date timeStamp; // Fecha de ingreso objeto
	private int delay; // Tiempo aleatorio de retardo para ingreso de la transaccion objeto
	private int prioridad; // prioridad (-2 a 2) objeto
	private int status; // Estado (Estado: 0:No ingresado, 1: Ingresado objeto/ jcgoku
        private int fase;
        private String xmlData; //datos en XML para la clase a ejecutar
    
    /** Creates a new instance of transaccion */
    public Transaccion() {
    }

    public int getId() {
        return Id;
    }

    public void setId(int Id) {
        this.Id = Id;
    }

    public String getQuery() {
        return query;
    }

    public void setQuery(String query) {
        this.query = query;
    }

    public java.sql.Date getTimeStamp() {
        return timeStamp;
    }

    public void setTimeStamp(java.sql.Date timeStamp) {
        this.timeStamp = timeStamp;
    }

    public int getDelay() {
        return delay;
    }

    public void setDelay(int delay) {
        this.delay = delay;
    }

    public int getPrioridad() {
        return prioridad;
    }

    public void setPrioridad(int prioridad) {
        this.prioridad = prioridad;
    }

    public int getStatus() {
        return status;
    }

    public void setStatus(int status) {
        this.status = status;
    }

    public int getFase() {
        return fase;
    }

    public void setFase(int fase) {
        this.fase = fase;
    }

    public String getXmlData() {
        return xmlData;
    }

    public void setXmlData(String xmlData) {
        this.xmlData = xmlData;
    }
    
}
