/*
 * TriDiWindow.java
 *
 * Created on 19 de febrero de 2007, 07:17 PM
 */

package practica1;

import com.sun.j3d.utils.geometry.*;
import com.sun.j3d.utils.universe.*;
import java.awt.*;
import java.awt.event.*;
import javax.media.j3d.*;
import javax.vecmath.*;
import java.beans.*;
import java.io.*;
import java.util.zip.*;
import java.util.*;


/**
 *
 * @author  kreig
 */
public class TriDiWindow extends javax.swing.JFrame {
    /*private String body_filename = new String("/media/docs/progra/java/asm2/Practica1/dist/Snow.000.Body.Shape3D.xml.gz");
    private String hat_filename = new String("/media/docs/progra/java/asm2/Practica1/dist/Sombrero.000.Hat.Shape3D.xml.gz");
    private String arms_filename = new String("/media/docs/progra/java/asm2/Practica1/dist/Wood.000.Arms.Shape3D.xml.gz");
    private String eyes_filename = new String("/media/docs/progra/java/asm2/Practica1/dist/Eyes.000.Eyes.Shape3D.xml.gz");
    private String nose_filename = new String("/media/docs/progra/java/asm2/Practica1/dist/Zanahoria.000.Nose.Shape3D.xml.gz");
    */
    private String body_filename = new String("./Snow.000.Body.Shape3D.xml.gz");
    private String hat_filename = new String("./Sombrero.000.Hat.Shape3D.xml.gz");
    private String arms_filename = new String("./Wood.000.Arms.Shape3D.xml.gz");
    private String eyes_filename = new String("./Eyes.000.Eyes.Shape3D.xml.gz");
    private String nose_filename = new String("./Zanahoria.000.Nose.Shape3D.xml.gz");
    
    
    private TransformGroup tHat, tBody, tArms, tEyes, tNose;
    private TransformGroup actual;
    
    
    /** Creates new form TriDiWindow */
    public TriDiWindow() {
        initComponents();        
        /**Inicializacion de canvas*/
        GraphicsConfiguration config = SimpleUniverse.getPreferredConfiguration();
        Canvas3D canvas = new Canvas3D(config);
        this.add(canvas);        
        BranchGroup scene = createSceneGraph2();
       
        scene.compile();
        SimpleUniverse su = new SimpleUniverse();
        
        
        su.getViewingPlatform().setNominalViewingTransform();
        //su.getViewer().getView().setLeftManualEyeInCoexistence(new Point3d(-0.033d, 0.0d, 5d));
        //su.getViewer().getView().setRightManualEyeInCoexistence(new Point3d(-0.033d, 0.0d, 5d));
        su.addBranchGraph(scene);
        
        /***/
        actual = tBody;
    }
    
    /**Importa modelo desde archivo XML*/
    public BranchGroup createSceneGraph2(){
        BranchGroup objRoot = new BranchGroup();
        /**Transformaciones inicialespara objetos visuales*/
        
        
        Transform3D rotateHatX = new Transform3D();
        Transform3D rotateHatZ = new Transform3D();
        Transform3D rotateBodyX = new Transform3D();
        Transform3D rotateArmsY = new Transform3D();
        Transform3D rotateArmsZ = new Transform3D();
        Transform3D rotateEyesX = new Transform3D();
        Transform3D rotateNoseX = new Transform3D();
        Transform3D translateHat = new Transform3D();
        Transform3D translateBody = new Transform3D();
        Transform3D translateArms = new Transform3D();
        Transform3D translateEyes = new Transform3D();
        Transform3D translateNose = new Transform3D();
        
        rotateHatX.rotX(-Math.PI/2);        
        rotateHatZ.rotZ(Math.PI/16);    
        rotateHatX.mul(rotateHatZ);
        
        rotateBodyX.rotX(Math.PI/2); 
        
        rotateArmsY.rotY(-Math.PI/2);        
        rotateArmsZ.rotZ(Math.PI/2);
        rotateArmsY.mul(rotateArmsZ);
        
        rotateEyesX.rotX(0);
        rotateNoseX.rotX(Math.PI/2);
        
        /**Aqui Las coordenadas estan como en mate 5 ( el eje z atraviesa la camara)*/
        translateHat.set(new Vector3d(0,0,0.4));
        translateBody.set(new Vector3d(0,0,0.3));
        translateArms.set(new Vector3d(-0.15,0.7,-0.6));        
        translateEyes.set(new Vector3d(-0.1,0.15,0));
        translateNose.set(new Vector3d(0,0.08,0));
                
                
        //rotateHatZ.rotZ(-Math.PI/2);
        //rotateBodyZ.rotZ(-Math.PI/2);
        //rotateArmsZ.rotZ(-Math.PI/2);
        
        rotateHatX.mul(translateHat);
        rotateBodyX.mul(translateBody);
        rotateArmsY.mul(translateArms);
        rotateEyesX.mul(translateEyes);
        translateNose.mul(rotateNoseX);
        
        tHat = new TransformGroup(rotateHatX);
        tBody = new TransformGroup(rotateBodyX);
        tArms = new TransformGroup(rotateArmsY);      
        tEyes = new TransformGroup(translateEyes);
        tNose = new TransformGroup(translateNose);
        /**Asignamos capacidades de escritura en tiempo real*/
        //tHat.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);
        tHat.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
        //tBody.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);
        tBody.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
        //tArms.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);
        tArms.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
        //tEyes.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);
        tEyes.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
        //tNose.setCapability(TransformGroup.ALLOW_TRANSFORM_READ);
        tNose.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
        /**animacion basica*/
        /*Alpha rotationAlpha = new Alpha(-1, 4000);
        RotationInterpolator rotator =
            new RotationInterpolator(rotationAlpha, tEyes);
                //new RotationInterpolator(rotationAlpha,tHat,rotateEyesX,0f,new Float((Math.PI*2)-0.01).floatValue());
        BoundingSphere bounds = new BoundingSphere();
        rotator.setSchedulingBounds(bounds);
        tEyes.addChild(rotator);
        */
        
        
        
        //HatBehavior hbhv = new HatBehavior(tHat);
        //objRoot.addChild(hbhv);
        
        
        XMLDecoder de;
        /**Luces*/
        AmbientLight l1 = new AmbientLight();        
        PointLight l2 = new PointLight(true,new Color3f(1,1,1),new Point3f(3,3,3),new Point3f(1,0,0));
        l1.setInfluencingBounds(new BoundingSphere());
        l2.setInfluencingBounds(new BoundingSphere());
        objRoot.addChild(l1);
        objRoot.addChild(l2);
        
 

        try{
            /**Cargamos cuerpo*/

            de = new XMLDecoder(new BufferedInputStream(new GZIPInputStream( new FileInputStream(body_filename))));
            Shape3D body = (Shape3D) de.readObject();               
            /**Cargamos sombrero*/
            de = new XMLDecoder(new BufferedInputStream(new GZIPInputStream( new FileInputStream(hat_filename))));
            Shape3D hat = (Shape3D) de.readObject();            
            /**Cargamos Brazos*/
            de = new XMLDecoder(new BufferedInputStream(new GZIPInputStream( new FileInputStream(arms_filename))));
            Shape3D arms = (Shape3D) de.readObject();            
            /**Cargamos Ojos*/
            de = new XMLDecoder(new BufferedInputStream(new GZIPInputStream( new FileInputStream(eyes_filename))));
            Shape3D eyes = (Shape3D) de.readObject();            
            /**Cargamos Nariz*/
            de = new XMLDecoder(new BufferedInputStream(new GZIPInputStream( new FileInputStream(nose_filename))));
            Shape3D nose = (Shape3D) de.readObject();            
          //  shape.setAppearance (app);    
            /**Insertamos body al branch*/
            
            tBody.addChild(body);
            objRoot.addChild(tBody);
            /**Insertamos hat al branch*/
            tHat.addChild(hat);
            objRoot.addChild(tHat);
            /**Insertamos brazos al branch*/
            tArms.addChild(arms);
            objRoot.addChild(tArms);
            /**Insertamos ojos al branch*/
            tEyes.addChild(eyes);
            objRoot.addChild(tEyes);
            /**Insertamos nariz al branch*/
            tNose.addChild(nose);
            objRoot.addChild(tNose);
            
            Alpha colAlpha = new Alpha(-1, 2000);
            
            eyes.getAppearance().getMaterial().setCapability(Material.ALLOW_COMPONENT_WRITE);
            ColorInterpolator colint = 
                    new ColorInterpolator(colAlpha, eyes.getAppearance().getMaterial(),new Color3f(1,1,1),new Color3f(0,0,0));
                    
            BoundingSphere bounds = new BoundingSphere();
            colint.setSchedulingBounds(bounds);
            tEyes.addChild(colint);
            
            
            return objRoot;
        }
        catch(Exception e){
            System.out.print(e);
        }
        return null;
     
    }
    
    public BranchGroup createSceneGraph1(){
        BranchGroup objRoot = new BranchGroup();     
        Transform3D rotateX = new Transform3D();        
        Transform3D rotateY = new Transform3D();        
        rotateX.rotX(Math.PI/4.0d);
        rotateY.rotY(Math.PI/4.0d);
        rotateX.mul(rotateY);
        TransformGroup objRotate = new TransformGroup(rotateX);
        
        objRotate.addChild(new ColorCube(0.4));
        objRoot.addChild(objRotate);      
        
        return objRoot;
    }

        public BranchGroup createSceneGraph3(){
        BranchGroup objRoot = new BranchGroup();     
        Transform3D rotateX = new Transform3D();        
        Transform3D rotateY = new Transform3D();        
        rotateX.rotX(Math.PI/4.0d);
        rotateY.rotY(Math.PI/4.0d);
        rotateX.mul(rotateY);
        TransformGroup objRotate = new TransformGroup(rotateX);
        
        objRotate.addChild(new ColorCube(0.4));
        objRoot.addChild(objRotate);      
        
        return objRoot;
    }

    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    // <editor-fold defaultstate="collapsed" desc=" Generated Code ">//GEN-BEGIN:initComponents
    private void initComponents() {
        jScrollPane1 = new javax.swing.JScrollPane();
        jTextArea1 = new javax.swing.JTextArea();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        jTextArea1.setColumns(20);
        jTextArea1.setRows(5);
        jTextArea1.setText("Practica 1, Arq. de computadoras \n\ty Ensambladores 2\n\nFrosty en Java 3d\n\nErik Vladimir Giron Marquez\nC# 200313492");
        jScrollPane1.setViewportView(jTextArea1);

        org.jdesktop.layout.GroupLayout layout = new org.jdesktop.layout.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(layout.createSequentialGroup()
                .addContainerGap()
                .add(jScrollPane1, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 242, Short.MAX_VALUE)
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(layout.createSequentialGroup()
                .addContainerGap()
                .add(jScrollPane1, org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 111, Short.MAX_VALUE)
                .addContainerGap())
        );
        pack();
    }// </editor-fold>//GEN-END:initComponents
    
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new TriDiWindow().setVisible(true);
            }
        });
    }
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTextArea jTextArea1;
    // End of variables declaration//GEN-END:variables
    
}

class HatBehavior extends Behavior {
    
    private TransformGroup targetTG;
    private Transform3D rotation = new Transform3D();
    private Transform3D abadon;
    private double angle = 0.0;
   // Alpha rotationAlpha = new Alpha(1, 4000);
   // RotationInterpolator rotator = new RotationInterpolator(rotationAlpha, targetTG);                
   // BoundingSphere bounds = new BoundingSphere();
    
    
    HatBehavior(TransformGroup targetTG){
   //     rotator.setSchedulingBounds(bounds);
        this.targetTG = targetTG;
   //     this.targetTG.addChild(rotator);
    }
    
    public void initialize(){
       // Condicion de inicio
        this.wakeupOn(new WakeupOnAWTEvent(KeyEvent.KEY_PRESSED));
    }

    public void processStimulus(Enumeration criteria){
    // Respuesta al estimulo
        angle += 0.1;        
        rotation.rotY(angle);
        targetTG.setTransform(rotation);
        this.wakeupOn(new WakeupOnAWTEvent(java.awt.event.MouseEvent.BUTTON1 /*KeyEvent.KEY_PRESSED*/));
    }


}

