/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package video;

import java.io.Serializable;
import java.math.BigDecimal;
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
@Table(name = "CLIENTE")
@NamedQueries({@NamedQuery(name = "Cliente.findByIdCliente", query = "SELECT c FROM Cliente c WHERE c.idCliente = :idCliente"), @NamedQuery(name = "Cliente.findByNombre", query = "SELECT c FROM Cliente c WHERE c.nombre = :nombre"), @NamedQuery(name = "Cliente.findByTelefono", query = "SELECT c FROM Cliente c WHERE c.telefono = :telefono"), @NamedQuery(name = "Cliente.findByDireccion", query = "SELECT c FROM Cliente c WHERE c.direccion = :direccion"), @NamedQuery(name = "Cliente.findBySexo", query = "SELECT c FROM Cliente c WHERE c.sexo = :sexo"), @NamedQuery(name = "Cliente.findByFechaAfiliacion", query = "SELECT c FROM Cliente c WHERE c.fechaAfiliacion = :fechaAfiliacion"), @NamedQuery(name = "Cliente.findByFechaNac", query = "SELECT c FROM Cliente c WHERE c.fechaNac = :fechaNac")})
public class Cliente implements Serializable {
    private static final long serialVersionUID = 1L;
    @Id
    @Column(name = "ID_CLIENTE", nullable = false)
    private BigDecimal idCliente;
    @Column(name = "NOMBRE", nullable = false)
    private String nombre;
    @Column(name = "TELEFONO", nullable = false)
    private String telefono;
    @Column(name = "DIRECCION", nullable = false)
    private String direccion;
    @Column(name = "SEXO", nullable = false)
    private char sexo;
    @Column(name = "FECHA_AFILIACION", nullable = false)
    @Temporal(TemporalType.DATE)
    private Date fechaAfiliacion;
    @Column(name = "FECHA_NAC", nullable = false)
    @Temporal(TemporalType.DATE)
    private Date fechaNac;
    @OneToMany(cascade = CascadeType.ALL, mappedBy = "cliente")
    private Collection<Alquiler> alquilerCollection;

    public Cliente() {
    }

    public Cliente(BigDecimal idCliente) {
        this.idCliente = idCliente;
    }

    public Cliente(BigDecimal idCliente, String nombre, String telefono, String direccion, char sexo, Date fechaAfiliacion, Date fechaNac) {
        this.idCliente = idCliente;
        this.nombre = nombre;
        this.telefono = telefono;
        this.direccion = direccion;
        this.sexo = sexo;
        this.fechaAfiliacion = fechaAfiliacion;
        this.fechaNac = fechaNac;
    }

    public BigDecimal getIdCliente() {
        return idCliente;
    }

    public void setIdCliente(BigDecimal idCliente) {
        this.idCliente = idCliente;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getTelefono() {
        return telefono;
    }

    public void setTelefono(String telefono) {
        this.telefono = telefono;
    }

    public String getDireccion() {
        return direccion;
    }

    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    public char getSexo() {
        return sexo;
    }

    public void setSexo(char sexo) {
        this.sexo = sexo;
    }

    public Date getFechaAfiliacion() {
        return fechaAfiliacion;
    }

    public void setFechaAfiliacion(Date fechaAfiliacion) {
        this.fechaAfiliacion = fechaAfiliacion;
    }

    public Date getFechaNac() {
        return fechaNac;
    }

    public void setFechaNac(Date fechaNac) {
        this.fechaNac = fechaNac;
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
        hash += (idCliente != null ? idCliente.hashCode() : 0);
        return hash;
    }

    @Override
    public boolean equals(Object object) {
        // TODO: Warning - this method won't work in the case the id fields are not set
        if (!(object instanceof Cliente)) {
            return false;
        }
        Cliente other = (Cliente) object;
        if ((this.idCliente == null && other.idCliente != null) || (this.idCliente != null && !this.idCliente.equals(other.idCliente))) {
            return false;
        }
        return true;
    }

    @Override
    public String toString() {
        return "video.Cliente[idCliente=" + idCliente + "]";
    }

}
