/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package video;

import java.io.Serializable;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Collection;
import java.util.Date;
import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;
import javax.persistence.OneToMany;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;

/**
 *
 * @author Erik Giron
 */
@Entity
@Table(name = "PELICULA")
@NamedQueries({@NamedQuery(name = "Pelicula.findByIdPelicula", query = "SELECT p FROM Pelicula p WHERE p.idPelicula = :idPelicula"), @NamedQuery(name = "Pelicula.findByNombre", query = "SELECT p FROM Pelicula p WHERE p.nombre = :nombre"), @NamedQuery(name = "Pelicula.findByFechaEstreno", query = "SELECT p FROM Pelicula p WHERE p.fechaEstreno = :fechaEstreno"), @NamedQuery(name = "Pelicula.findByDescrip", query = "SELECT p FROM Pelicula p WHERE p.descrip = :descrip"), @NamedQuery(name = "Pelicula.findByClasif", query = "SELECT p FROM Pelicula p WHERE p.clasif = :clasif"), @NamedQuery(name = "Pelicula.findByConocidaComo", query = "SELECT p FROM Pelicula p WHERE p.conocidaComo = :conocidaComo"), @NamedQuery(name = "Pelicula.findByNumEjemplares", query = "SELECT p FROM Pelicula p WHERE p.numEjemplares = :numEjemplares")})
public class Pelicula implements Serializable {
    private static final long serialVersionUID = 1L;
    @Id
    @Column(name = "ID_PELICULA", nullable = false)
    private BigDecimal idPelicula;
    @Column(name = "NOMBRE", nullable = false)
    private String nombre;
    @Column(name = "FECHA_ESTRENO", nullable = false)
    @Temporal(TemporalType.DATE)
    private Date fechaEstreno;
    @Column(name = "DESCRIP", nullable = false)
    private String descrip;
    @Column(name = "CLASIF", nullable = false)
    private char clasif;
    @Column(name = "CONOCIDA_COMO", nullable = false)
    private String conocidaComo;
    @Column(name = "NUM_EJEMPLARES", nullable = false)
    private BigInteger numEjemplares;
    @OneToMany(cascade = CascadeType.ALL, mappedBy = "pelicula")
    private Collection<Fecha> fechaCollection;
    @OneToMany(cascade = CascadeType.ALL, mappedBy = "pelicula")
    private Collection<Alquiler> alquilerCollection;

    public Pelicula() {
    }

    public Pelicula(BigDecimal idPelicula) {
        this.idPelicula = idPelicula;
    }

    public Pelicula(BigDecimal idPelicula, String nombre, Date fechaEstreno, String descrip, char clasif, String conocidaComo, BigInteger numEjemplares) {
        this.idPelicula = idPelicula;
        this.nombre = nombre;
        this.fechaEstreno = fechaEstreno;
        this.descrip = descrip;
        this.clasif = clasif;
        this.conocidaComo = conocidaComo;
        this.numEjemplares = numEjemplares;
    }

    public BigDecimal getIdPelicula() {
        return idPelicula;
    }

    public void setIdPelicula(BigDecimal idPelicula) {
        this.idPelicula = idPelicula;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public Date getFechaEstreno() {
        return fechaEstreno;
    }

    public void setFechaEstreno(Date fechaEstreno) {
        this.fechaEstreno = fechaEstreno;
    }

    public String getDescrip() {
        return descrip;
    }

    public void setDescrip(String descrip) {
        this.descrip = descrip;
    }

    public char getClasif() {
        return clasif;
    }

    public void setClasif(char clasif) {
        this.clasif = clasif;
    }

    public String getConocidaComo() {
        return conocidaComo;
    }

    public void setConocidaComo(String conocidaComo) {
        this.conocidaComo = conocidaComo;
    }

    public BigInteger getNumEjemplares() {
        return numEjemplares;
    }

    public void setNumEjemplares(BigInteger numEjemplares) {
        this.numEjemplares = numEjemplares;
    }

    public Collection<Fecha> getFechaCollection() {
        return fechaCollection;
    }

    public void setFechaCollection(Collection<Fecha> fechaCollection) {
        this.fechaCollection = fechaCollection;
    }

    public Collection<Alquiler> getAlquilerCollection() {
        return alquilerCollection;
    }

    public void setAlquilerCollection(Collection<Alquiler> alquilerCollection) {
        this.alquilerCollection = alquilerCollection;
    }

    @Override
    public int hashCode() {
        int hash = 0;
        hash += (idPelicula != null ? idPelicula.hashCode() : 0);
        return hash;
    }

    @Override
    public boolean equals(Object object) {
        // TODO: Warning - this method won't work in the case the id fields are not set
        if (!(object instanceof Pelicula)) {
            return false;
        }
        Pelicula other = (Pelicula) object;
        if ((this.idPelicula == null && other.idPelicula != null) || (this.idPelicula != null && !this.idPelicula.equals(other.idPelicula))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "video.Pelicula[idPelicula=" + idPelicula + "]";
    }

}
