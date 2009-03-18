/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package video;

import java.io.Serializable;
import java.math.BigInteger;
import java.util.Date;
import javax.persistence.Column;
import javax.persistence.EmbeddedId;
import javax.persistence.Entity;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;

/**
 *
 * @author Erik Giron
 */
@Entity
@Table(name = "FECHA")
@NamedQueries({@NamedQuery(name = "Fecha.findByIdTipoPelicula", query = "SELECT f FROM Fecha f WHERE f.fechaPK.idTipoPelicula = :idTipoPelicula"), @NamedQuery(name = "Fecha.findByIdPelicula", query = "SELECT f FROM Fecha f WHERE f.fechaPK.idPelicula = :idPelicula"), @NamedQuery(name = "Fecha.findByFecha", query = "SELECT f FROM Fecha f WHERE f.fecha = :fecha")})
public class Fecha implements Serializable {
    private static final long serialVersionUID = 1L;
    @EmbeddedId
    protected FechaPK fechaPK;
    @Column(name = "FECHA", nullable = false)
    @Temporal(TemporalType.DATE)
    private Date fecha;
    @JoinColumn(name = "ID_PELICULA", referencedColumnName = "ID_PELICULA", insertable = false, updatable = false)
    @ManyToOne
    private Pelicula pelicula;
    @JoinColumn(name = "ID_TIPO_PELICULA", referencedColumnName = "ID_TIPO_PELICULA", insertable = false, updatable = false)
    @ManyToOne
    private TipoPelicula tipoPelicula;

    public Fecha() {
    }

    public Fecha(FechaPK fechaPK) {
        this.fechaPK = fechaPK;
    }

    public Fecha(FechaPK fechaPK, Date fecha) {
        this.fechaPK = fechaPK;
        this.fecha = fecha;
    }

    public Fecha(BigInteger idTipoPelicula, BigInteger idPelicula) {
        this.fechaPK = new FechaPK(idTipoPelicula, idPelicula);
    }

    public FechaPK getFechaPK() {
        return fechaPK;
    }

    public void setFechaPK(FechaPK fechaPK) {
        this.fechaPK = fechaPK;
    }

    public Date getFecha() {
        return fecha;
    }

    public void setFecha(Date fecha) {
        this.fecha = fecha;
    }

    public Pelicula getPelicula() {
        return pelicula;
    }

    public void setPelicula(Pelicula pelicula) {
        this.pelicula = pelicula;
    }

    public TipoPelicula getTipoPelicula() {
        return tipoPelicula;
    }

    public void setTipoPelicula(TipoPelicula tipoPelicula) {
        this.tipoPelicula = tipoPelicula;
    }

    @Override
    public int hashCode() {
        int hash = 0;
        hash += (fechaPK != null ? fechaPK.hashCode() : 0);
        return hash;
    }

    @Override
    public boolean equals(Object object) {
        // TODO: Warning - this method won't work in the case the id fields are not set
        if (!(object instanceof Fecha)) {
            return false;
        }
        Fecha other = (Fecha) object;
        if ((this.fechaPK == null && other.fechaPK != null) || (this.fechaPK != null && !this.fechaPK.equals(other.fechaPK))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "video.Fecha[fechaPK=" + fechaPK + "]";
    }

}
