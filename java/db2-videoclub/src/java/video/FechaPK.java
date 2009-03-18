/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package video;

import java.io.Serializable;
import java.math.BigInteger;
import javax.persistence.Column;
import javax.persistence.Embeddable;

/**
 *
 * @author Erik Giron
 */
@Embeddable
public class FechaPK implements Serializable {
    @Column(name = "ID_TIPO_PELICULA", nullable = false)
    private BigInteger idTipoPelicula;
    @Column(name = "ID_PELICULA", nullable = false)
    private BigInteger idPelicula;

    public FechaPK() {
    }

    public FechaPK(BigInteger idTipoPelicula, BigInteger idPelicula) {
        this.idTipoPelicula = idTipoPelicula;
        this.idPelicula = idPelicula;
    }

    public BigInteger getIdTipoPelicula() {
        return idTipoPelicula;
    }

    public void setIdTipoPelicula(BigInteger idTipoPelicula) {
        this.idTipoPelicula = idTipoPelicula;
    }

    public BigInteger getIdPelicula() {
        return idPelicula;
    }

    public void setIdPelicula(BigInteger idPelicula) {
        this.idPelicula = idPelicula;
    }

    @Override
    public int hashCode() {
        int hash = 0;
        hash += (idTipoPelicula != null ? idTipoPelicula.hashCode() : 0);
        hash += (idPelicula != null ? idPelicula.hashCode() : 0);
        return hash;
    }

    @Override
    public boolean equals(Object object) {
        // TODO: Warning - this method won't work in the case the id fields are not set
        if (!(object instanceof FechaPK)) {
            return false;
        }
        FechaPK other = (FechaPK) object;
        if ((this.idTipoPelicula == null && other.idTipoPelicula != null) || (this.idTipoPelicula != null && !this.idTipoPelicula.equals(other.idTipoPelicula))) {
            return false;
        }
        if ((this.idPelicula == null && other.idPelicula != null) || (this.idPelicula != null && !this.idPelicula.equals(other.idPelicula))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "video.FechaPK[idTipoPelicula=" + idTipoPelicula + ", idPelicula=" + idPelicula + "]";
    }

}
