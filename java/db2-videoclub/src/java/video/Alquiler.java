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
@Table(name = "ALQUILER")
@NamedQueries({@NamedQuery(name = "Alquiler.findByIdPelicula", query = "SELECT a FROM Alquiler a WHERE a.alquilerPK.idPelicula = :idPelicula"), @NamedQuery(name = "Alquiler.findByIdCliente", query = "SELECT a FROM Alquiler a WHERE a.alquilerPK.idCliente = :idCliente"), @NamedQuery(name = "Alquiler.findByFechaAlquiler", query = "SELECT a FROM Alquiler a WHERE a.alquilerPK.fechaAlquiler = :fechaAlquiler"), @NamedQuery(name = "Alquiler.findByFechaDevCresta", query = "SELECT a FROM Alquiler a WHERE a.fechaDevCresta = :fechaDevCresta"), @NamedQuery(name = "Alquiler.findByFechaDevEcho", query = "SELECT a FROM Alquiler a WHERE a.fechaDevEcho = :fechaDevEcho")})
public class Alquiler implements Serializable {
    private static final long serialVersionUID = 1L;
    @EmbeddedId
    protected AlquilerPK alquilerPK;
    @Column(name = "FECHA_DEV_CRESTA", nullable = false)
    @Temporal(TemporalType.DATE)
    private Date fechaDevCresta;
    @Column(name = "FECHA_DEV_ECHO")
    @Temporal(TemporalType.DATE)
    private Date fechaDevEcho;
    @JoinColumn(name = "ID_CLIENTE", referencedColumnName = "ID_CLIENTE", insertable = false, updatable = false)
    @ManyToOne
    private Cliente cliente;
    @JoinColumn(name = "ID_PELICULA", referencedColumnName = "ID_PELICULA", insertable = false, updatable = false)
    @ManyToOne
    private Pelicula pelicula;

    public Alquiler() {
    }

    public Alquiler(AlquilerPK alquilerPK) {
        this.alquilerPK = alquilerPK;
    }

    public Alquiler(AlquilerPK alquilerPK, Date fechaDevCresta) {
        this.alquilerPK = alquilerPK;
        this.fechaDevCresta = fechaDevCresta;
    }

    public Alquiler(BigInteger idPelicula, BigInteger idCliente, Date fechaAlquiler) {
        this.alquilerPK = new AlquilerPK(idPelicula, idCliente, fechaAlquiler);
    }

    public AlquilerPK getAlquilerPK() {
        return alquilerPK;
    }

    public void setAlquilerPK(AlquilerPK alquilerPK) {
        this.alquilerPK = alquilerPK;
    }

    public Date getFechaDevCresta() {
        return fechaDevCresta;
    }

    public void setFechaDevCresta(Date fechaDevCresta) {
        this.fechaDevCresta = fechaDevCresta;
    }

    public Date getFechaDevEcho() {
        return fechaDevEcho;
    }

    public void setFechaDevEcho(Date fechaDevEcho) {
        this.fechaDevEcho = fechaDevEcho;
    }

    public Cliente getCliente() {
        return cliente;
    }

    public void setCliente(Cliente cliente) {
        this.cliente = cliente;
    }

    public Pelicula getPelicula() {
        return pelicula;
    }

    public void setPelicula(Pelicula pelicula) {
        this.pelicula = pelicula;
    }

    @Override
    public int hashCode() {
        int hash = 0;
        hash += (alquilerPK != null ? alquilerPK.hashCode() : 0);
        return hash;
    }

    @Override
    public boolean equals(Object object) {
        // TODO: Warning - this method won't work in the case the id fields are not set
        if (!(object instanceof Alquiler)) {
            return false;
        }
        Alquiler other = (Alquiler) object;
        if ((this.alquilerPK == null && other.alquilerPK != null) || (this.alquilerPK != null && !this.alquilerPK.equals(other.alquilerPK))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "video.Alquiler[alquilerPK=" + alquilerPK + "]";
    }

}
