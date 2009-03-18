/*
 * VentanaReporteFechas.java
 *
 * Created on October 5, 2007, 11:32 PM
 */

package validadorfacturas;

/**
 * Ventana para ingreso del reporte de rango de fechas
 * @author  Erik Giron
 */
public class VentanaReporteFechas extends javax.swing.JFrame {
    
    /** Creates new form VentanaReporteFechas */
    public VentanaReporteFechas() {
        initComponents();
    }
    
    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    // <editor-fold defaultstate="collapsed" desc=" Generated Code ">//GEN-BEGIN:initComponents
    private void initComponents() {
        jButton1 = new javax.swing.JButton();
        jTextFieldSerie = new javax.swing.JTextField();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jTextFieldFechaInic = new javax.swing.JTextField();
        jTextFieldFechaFin = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        jButton2 = new javax.swing.JButton();

        setTitle("Consulta 2. Ingrese serie y rango de fechas...");
        jButton1.setText("Generar Consulta");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jLabel1.setText("Serie:");

        jLabel2.setText("Fecha Inicio: ");

        jTextFieldFechaInic.setText("aaaa/mm/dd");

        jTextFieldFechaFin.setText("aaaa/mm/dd");

        jLabel3.setText("Fecha Fin: ");

        jButton2.setText("Cancelar");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        org.jdesktop.layout.GroupLayout layout = new org.jdesktop.layout.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(layout.createSequentialGroup()
                .addContainerGap()
                .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
                    .add(layout.createSequentialGroup()
                        .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
                            .add(jLabel1)
                            .add(jLabel2)
                            .add(jLabel3))
                        .add(23, 23, 23)
                        .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
                            .add(jTextFieldFechaFin, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
                            .add(jTextFieldFechaInic, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
                            .add(jTextFieldSerie, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, 55, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)))
                    .add(org.jdesktop.layout.GroupLayout.TRAILING, layout.createSequentialGroup()
                        .add(jButton2)
                        .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED, 25, Short.MAX_VALUE)
                        .add(jButton1)))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(layout.createSequentialGroup()
                .addContainerGap()
                .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.BASELINE)
                    .add(jLabel1)
                    .add(jTextFieldSerie, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED)
                .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.BASELINE)
                    .add(jLabel2)
                    .add(jTextFieldFechaInic, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED)
                .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.BASELINE)
                    .add(jTextFieldFechaFin, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
                    .add(jLabel3))
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED, 53, Short.MAX_VALUE)
                .add(layout.createParallelGroup(org.jdesktop.layout.GroupLayout.BASELINE)
                    .add(jButton1)
                    .add(jButton2))
                .addContainerGap())
        );
        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
        this.setVisible(false);
    }//GEN-LAST:event_jButton2ActionPerformed

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        //Hacemos consulta a base de datos e imprimimos resultados
        if(this.jTextFieldSerie.getText().length() > 0
                && this.jTextFieldFechaInic.getText().length() > 0
                && this.jTextFieldFechaFin.getText().length() > 0){
                MainWindow.getQuery().ejecutarQueryFechas(this.jTextFieldSerie.getText(),this.jTextFieldFechaInic.getText(),this.jTextFieldFechaFin.getText());
                this.setVisible(false);
        }
        else{
            MainWindow.println("Aviso: Debe llenar todos los campos");
        }
    }//GEN-LAST:event_jButton1ActionPerformed
    
    
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new VentanaReporteFechas().setVisible(true);
            }
        });
    }
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JTextField jTextFieldFechaFin;
    private javax.swing.JTextField jTextFieldFechaInic;
    private javax.swing.JTextField jTextFieldSerie;
    // End of variables declaration//GEN-END:variables
    
}
