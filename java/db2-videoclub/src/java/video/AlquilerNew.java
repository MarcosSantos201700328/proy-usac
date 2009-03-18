/*
 * ClienteNew.java
 *
 * Created on 18/02/2008, 09:10:58 PM
 */
 
package video;

import com.sun.rave.web.ui.appbase.AbstractPageBean;
import com.sun.webui.jsf.component.Body;
import com.sun.webui.jsf.component.Button;
import com.sun.webui.jsf.component.Calendar;
import com.sun.webui.jsf.component.Form;
import com.sun.webui.jsf.component.Head;
import com.sun.webui.jsf.component.Html;
import com.sun.webui.jsf.component.Label;
import com.sun.webui.jsf.component.Link;
import com.sun.webui.jsf.component.Listbox;
import com.sun.webui.jsf.component.Page;
import com.sun.webui.jsf.component.StaticText;
import com.sun.webui.jsf.component.TextArea;
import com.sun.webui.jsf.component.TextField;
import com.sun.webui.jsf.model.DefaultOptionsList;
import javax.annotation.Resource;
import javax.faces.FacesException;
import javax.faces.component.UIComponent;
import javax.faces.context.FacesContext;
import javax.faces.validator.DoubleRangeValidator;
import javax.naming.Context;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import java.util.*;
/**
 * <p>Page bean that corresponds to a similarly named JSP page.  This
 * class contains component definitions (and initialization code) for
 * all components that you have defined on this page, as well as
 * lifecycle methods and event handlers where you may add behavior
 * to respond to incoming events.</p>
 *
 * @author Erik Giron
 */
@PersistenceContext(name = "persistence/LogicalName", unitName = "videoPU")
public class AlquilerNew extends AbstractPageBean {
    // <editor-fold defaultstate="collapsed" desc="Managed Component Definition">

    /**
     * <p>Automatically managed component initialization.  <strong>WARNING:</strong>
     * This method is automatically generated, so any user-specified code inserted
     * here is subject to being replaced.</p>
     */
    private void _init() throws Exception {
    }

    private Page page1 = new Page();
    
    public Page getPage1() {
        return page1;
    }
    
    public void setPage1(Page p) {
        this.page1 = p;
    }
    
    private Html html1 = new Html();
    
    public Html getHtml1() {
        return html1;
    }
    @Resource
    private javax.transaction.UserTransaction utx;
    
    public void setHtml1(Html h) {
        this.html1 = h;
    }
    
    private Head head1 = new Head();
    
    public Head getHead1() {
        return head1;
    }
    
    public void setHead1(Head h) {
        this.head1 = h;
    }
    
    private Link link1 = new Link();
    
    public Link getLink1() {
        return link1;
    }
    
    public void setLink1(Link l) {
        this.link1 = l;
    }
    
    private Body body1 = new Body();
    
    public Body getBody1() {
        return body1;
    }
    
    public void setBody1(Body b) {
        this.body1 = b;
    }
    
    private Form form1 = new Form();
    
    public Form getForm1() {
        return form1;
    }
    
    public void setForm1(Form f) {
        this.form1 = f;
    }
    private Label label1 = new Label();

    public Label getLabel1() {
        return label1;
    }

    public void setLabel1(Label l) {
        this.label1 = l;
    }
    private TextField t1 = new TextField();

    public TextField getT1() {
        return t1;
    }

    public void setT1(TextField tf) {
        this.t1 = tf;
    }
    private TextField t2 = new TextField();

    public TextField getT2() {
        return t2;
    }

    public void setT2(TextField tf) {
        this.t2 = tf;
    }
    private Label label2 = new Label();

    public Label getLabel2() {
        return label2;
    }

    public void setLabel2(Label l) {
        this.label2 = l;
    }
    private DoubleRangeValidator doubleRangeValidator1 = new DoubleRangeValidator();

    public DoubleRangeValidator getDoubleRangeValidator1() {
        return doubleRangeValidator1;
    }

    public void setDoubleRangeValidator1(DoubleRangeValidator drv) {
        this.doubleRangeValidator1 = drv;
    }
    private Label label6 = new Label();

    public Label getLabel6() {
        return label6;
    }

    public void setLabel6(Label l) {
        this.label6 = l;
    }
    private Calendar calendar1 = new Calendar();

    public Calendar getCalendar1() {
        return calendar1;
    }

    public void setCalendar1(Calendar c) {
        this.calendar1 = c;
    }
    private Label label7 = new Label();

    public Label getLabel7() {
        return label7;
    }

    public void setLabel7(Label l) {
        this.label7 = l;
    }
    private Calendar calendar2 = new Calendar();

    public Calendar getCalendar2() {
        return calendar2;
    }

    public void setCalendar2(Calendar c) {
        this.calendar2 = c;
    }
    private Button button1 = new Button();

    public Button getButton1() {
        return button1;
    }

    public void setButton1(Button b) {
        this.button1 = b;
    }
    private Button button2 = new Button();

    public Button getButton2() {
        return button2;
    }

    public void setButton2(Button b) {
        this.button2 = b;
    }

    // </editor-fold>

    
    ArrayList<Alquiler> cola = new ArrayList<Alquiler>();
    private StaticText staticText1 = new StaticText();

    public StaticText getStaticText1() {
        return staticText1;
    }

    public void setStaticText1(StaticText st) {
        this.staticText1 = st;
    }
    private TextArea tareas = new TextArea();

    public TextArea getTareas() {
        return tareas;
    }

    public void setTareas(TextArea ta) {
        this.tareas = ta;
    }
    /**
     * <p>Construct a new Page bean instance.</p>
     */
    public AlquilerNew() {
        
    }

    /**
     * <p>Callback method that is called whenever a page is navigated to,
     * either directly via a URL, or indirectly via page navigation.
     * Customize this method to acquire resources that will be needed
     * for event handlers and lifecycle methods, whether or not this
     * page is performing post back processing.</p>
     * 
     * <p>Note that, if the current request is a postback, the property
     * values of the components do <strong>not</strong> represent any
     * values submitted with this request.  Instead, they represent the
     * property values that were saved for this view when it was rendered.</p>
     */
    @Override
    public void init() {
        // Perform initializations inherited from our superclass
        super.init();
        // Perform application initialization that must complete
        // *before* managed components are initialized
        // TODO - add your own initialiation code here
        
        // <editor-fold defaultstate="collapsed" desc="Managed Component Initialization">
        // Initialize automatically managed components
        // *Note* - this logic should NOT be modified
        try {
            _init();
        } catch (Exception e) {
            log("ClienteNew Initialization Failure", e);
            throw e instanceof FacesException ? (FacesException) e: new FacesException(e);
        }
        
        // </editor-fold>
        // Perform application initialization that must complete
        // *after* managed components are initialized
        // TODO - add your own initialization code here
        this.tareas.setText(new String());
        this.button2.setDisabled(true);
    }

    /**
     * <p>Callback method that is called after the component tree has been
     * restored, but before any event processing takes place.  This method
     * will <strong>only</strong> be called on a postback request that
     * is processing a form submit.  Customize this method to allocate
     * resources that will be required in your event handlers.</p>
     */
    @Override
    public void preprocess() {        
    }

    /**
     * <p>Callback method that is called just before rendering takes place.
     * This method will <strong>only</strong> be called for the page that
     * will actually be rendered (and not, for example, on a page that
     * handled a postback and then navigated to a different page).  Customize
     * this method to allocate resources that will be required for rendering
     * this page.</p>
     */
    @Override
    public void prerender() {
    }

    /**
     * <p>Callback method that is called after rendering is completed for
     * this request, if <code>init()</code> was called (regardless of whether
     * or not this was the page that was actually rendered).  Customize this
     * method to release resources acquired in the <code>init()</code>,
     * <code>preprocess()</code>, or <code>prerender()</code> methods (or
     * acquired during execution of an event handler).</p>
     */
    @Override
    public void destroy() {
    }

    /**
     * <p>Return a reference to the scoped data bean.</p>
     *
     * @return reference to the scoped data bean
     */
    protected SessionBean1 getSessionBean1() {
        return (SessionBean1) getBean("SessionBean1");
    }

    /**
     * <p>Return a reference to the scoped data bean.</p>
     *
     * @return reference to the scoped data bean
     */
    protected ApplicationBean1 getApplicationBean1() {
        return (ApplicationBean1) getBean("ApplicationBean1");
    }

    /**
     * <p>Return a reference to the scoped data bean.</p>
     *
     * @return reference to the scoped data bean
     */
    protected RequestBean1 getRequestBean1() {
        return (RequestBean1) getBean("RequestBean1");
    }

    protected void persist(Object object) {
        try {
            Context ctx = (Context) new javax.naming.InitialContext().lookup("java:comp/env");
            utx.begin();
            EntityManager em = (EntityManager) ctx.lookup("persistence/LogicalName");
            em.persist(object);
            utx.commit();
        } catch (Exception e) {
            java.util.logging.Logger.getLogger(getClass().getName()).log(java.util.logging.Level.SEVERE, "exception caught", e);
            throw new RuntimeException(e);
        }
    }

    public void textfield1_validate(FacesContext context, UIComponent component, Object value) {
    }
    /**agrega tarea a la cola, cambiar*/
    public String button1_action() {
        // TODO: Process the action. Return value is a navigation
        // case name where null will return to the same page.
        /*if (this.getBean("Cola")!=null)
            cola = (ArrayList)this.getBean("Cola");*/
        //Obtenemos data
        if(this.retrieveData("cola") != null)
	        cola  = (ArrayList<Alquiler>) this.retrieveData("cola");
        //Ingresamos nuevo registro
        Alquiler c = new Alquiler();        
        AlquilerPK pk = new AlquilerPK(
                new java.math.BigInteger(this.t1.getText().toString()),
                new java.math.BigInteger(this.t2.getText().toString()),
                this.calendar1.getSelectedDate())
                ;
        c.setAlquilerPK(pk);
        c.setFechaDevCresta(this.calendar2.getSelectedDate());
        
        //agregamos a la cola
        cola.add(c);
        //guardamos la data
        this.saveData("cola", cola);
        //realizamos tareas de UI
        this.tareas.setText((String)this.tareas.getText() + c.toString() + "\n" );
        this.button2.setDisabled(false);
        return null;
    }

    public String button2_action() {
        // TODO: Process the action. Return value is a navigation
        // case name where null will return to the same page.
        guardar();
        return null;
    }
    /**Almacena info a la DB, cambiar*/
    private void guardar(){
        try {
            //obtenemos la cola
            cola = (ArrayList<Alquiler>)this.retrieveData("cola");
            Context ctx = (Context) new javax.naming.InitialContext().lookup("java:comp/env");
            //iniciamos transaccion
            utx.begin();
            EntityManager em = (EntityManager) ctx.lookup("persistence/LogicalName");
            Iterator i = cola.iterator();
            Alquiler actual;
            /**Ingresamos a la base de datos*/
            while(i.hasNext()){
                actual = (Alquiler) i.next();
                em.persist(actual);
            }            
            utx.commit();
        } catch (Exception e) {
            java.util.logging.Logger.getLogger(getClass().getName()).log(java.util.logging.Level.SEVERE, "exception caught", e);
            // hacemos rollback
            try{
                utx.rollback();
            }
            catch(Exception e2){
                
            }
            finally{
                //this.tareas.setText(e.toString());
                //return;
                throw new RuntimeException(e);
            }
        }
        finally{
            this.button2.setDisabled(false);
            this.tareas.setText(new String());
            this.saveData("cola", null);
        }
    }
    
    
}

