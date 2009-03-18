/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package video;

import java.io.Serializable;
import java.math.BigInteger;
import java.util.Date;
import javax.persistence.Column;
import javax.persistence.Embeddable;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;

/**
 *
 * @author Erik Giron
 */
@Embeddable
public class AlquilerPK implements Serializable {
    @Column(name = "ID_PELICULA", nullable = false)
    private BigInteger idPelicula;
    @Column(name = "ID_CLIENTE", nullable = false)
    private BigInteger idCliente;
    @Column(name = "FECHA_ALQUILER", nullable = false)
    @Temporal(TemporalType.DATE)
    private Date fechaAlquiler;

    public AlquilerPK() {
    }

    public AlquilerPK(BigInteger idPelicula, BigInteger idCliente, Date fechaAlquiler) {
        this.idPelicula = idPelicula;
        this.idCliente = idCliente;
        this.fechaAlquiler = fechaAlquiler;
    }

    public BigInteger getIdPelicula() {
        return idPelicula;
    }

    public void setIdPelicula(BigInteger idPelicula) {
        this.idPelicula = idPelicula;
    }

    public BigInteger getIdCliente() {
        return idCliente;
    }

    public void setIdCliente(BigInteger idCliente) {
        this.idCliente = idCliente;
    }

    public Date getFechaAlquiler() {
        return fechaAlquiler;
    }

    public void setFechaAlquiler(Date fechaAlquiler) {
        this.fechaAlquiler = fechaAlquiler;
    }

    @Override
    public int hashCode() {
        int hash = 0;
        hash += (idPelicula != null ? idPelicula.hashCode() : 0);
        hash += (idCliente != null ? idCliente.hashCode() : 0);
        hash += (fechaAlquiler != null ? fechaAlquiler.hashCode() : 0);
        return hash;
    }

    @Override
    public boolean equals(Object object) {
        // TODO: Warning - this method won't work in the case the id fields are not set
        if (!(object instanceof AlquilerPK)) {
            return false;
        }
        AlquilerPK other = (AlquilerPK) object;
        if ((this.idPelicula == null && other.idPelicula != null) || (this.idPelicula != null && !this.idPelicula.equals(other.idPelicula))) {
            return false;
        }
        if ((this.idCliente == null && other.idCliente != null) || (this.idCliente != null && !this.idCliente.equals(other.idCliente))) {
            return false;
        }
        if ((this.fechaAlquiler == null && other.fechaAlquiler != null) || (this.fechaAlquiler != null && !this.fechaAlquiler.equals(other.fechaAlquiler))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "video.AlquilerPK[idPelicula=" + idPelicula + ", idCliente=" + idCliente + ", fechaAlquiler=" + fechaAlquiler + "]";
    }

}
