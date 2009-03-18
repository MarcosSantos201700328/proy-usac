/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package video;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.Collection;
import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;
import javax.persistence.OneToMany;
import javax.persistence.Table;

/**
 *
 * @author Erik Giron
 */
@Entity
@Table(name = "TIPO_PELICULA")
@NamedQueries({@NamedQuery(name = "TipoPelicula.findByIdTipoPelicula", query = "SELECT t FROM TipoPelicula t WHERE t.idTipoPelicula = :idTipoPelicula"), @NamedQuery(name = "TipoPelicula.findByNombre", query = "SELECT t FROM TipoPelicula t WHERE t.nombre = :nombre"), @NamedQuery(name = "TipoPelicula.findByPrecio", query = "SELECT t FROM TipoPelicula t WHERE t.precio = :precio")})
public class TipoPelicula implements Serializable {
    private static final long serialVersionUID = 1L;
    @Id
    @Column(name = "ID_TIPO_PELICULA", nullable = false)
    private BigDecimal idTipoPelicula;
    @Column(name = "NOMBRE", nullable = false)
    private String nombre;
    @Column(name = "PRECIO", nullable = false)
    private double precio;
    @OneToMany(cascade = CascadeType.ALL, mappedBy = "tipoPelicula")
    private Collection<Fecha> fechaCollection;

    public TipoPelicula() {
    }

    public TipoPelicula(BigDecimal idTipoPelicula) {
        this.idTipoPelicula = idTipoPelicula;
    }

    public TipoPelicula(BigDecimal idTipoPelicula, String nombre, double precio) {
        this.idTipoPelicula = idTipoPelicula;
        this.nombre = nombre;
        this.precio = precio;
    }

    public BigDecimal getIdTipoPelicula() {
        return idTipoPelicula;
    }

    public void setIdTipoPelicula(BigDecimal idTipoPelicula) {
        this.idTipoPelicula = idTipoPelicula;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public double getPrecio() {
        return precio;
    }

    public void setPrecio(double precio) {
        this.precio = precio;
    }

    public Collection<Fecha> getFechaCollection() {
        return fechaCollection;
    }

    public void setFechaCollection(Collection<Fecha> fechaCollection) {
        this.fechaCollection = fechaCollection;
    }

    @Override
    public int hashCode() {
        int hash = 0;
        hash += (idTipoPelicula != null ? idTipoPelicula.hashCode() : 0);
        return hash;
    }

    @Override
    public boolean equals(Object object) {
        // TODO: Warning - this method won't work in the case the id fields are not set
        if (!(object instanceof TipoPelicula)) {
            return false;
        }
        TipoPelicula other = (TipoPelicula) object;
        if ((this.idTipoPelicula == null && other.idTipoPelicula != null) || (this.idTipoPelicula != null && !this.idTipoPelicula.equals(other.idTipoPelicula))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "video.TipoPelicula[idTipoPelicula=" + idTipoPelicula + "]";
    }

}
