using System;
using System.Data;
using System.Configuration;
using System.Collections;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
using System.Data.OracleClient;

public partial class cliente : System.Web.UI.Page
{

    static ArrayList queries = new ArrayList(5);

    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
            this.Button2.Enabled = false;
    }

    /**Funcion de insercion a la DB*/
    private int oracleInsert(ArrayList q)
    {
        /**Almacenamos data en BD*/
        int count = 0;
        OracleConnection conn = new OracleConnection(ConfigurationManager.ConnectionStrings["ConnectionString1"].ConnectionString)/*"Data Source=localhost;Persist Security Info=True;User ID=webadmin;Password=webadmin;Unicode=True")*/;
        conn.Open();
        OracleTransaction t = conn.BeginTransaction();
        try
        {
            OracleCommand cmd = new OracleCommand();
            cmd.Connection = conn;
            cmd.Transaction = t;
            cmd.CommandType = CommandType.Text;
            //Ejecutamos cada insert en la lista
            foreach (String s in q)
            {
                cmd.CommandText = s;
                count += cmd.ExecuteNonQuery();                
            }
            //Si fue exitoso, Commit
            t.Commit();
        }
        catch (Exception ex)
        {
            //Sino rollback
            Response.Write(ex);
            t.Rollback();
        }
        finally
        {
            //Cerramos conexion
            t.Dispose();
            conn.Dispose();
            conn.Close();
            
        }
        return count;
    }



    protected void Button1_Click(object sender, EventArgs e)
    {
        String query = "INSERT INTO cliente VALUES ("
                         + this.TextBox1.Text + "," + "'" + this.TextBox2.Text + "'" + "," +
                             "'" + this.TextBox3.Text + "'" + "," + "'" + this.TextBox4.Text + "'" + "," +
                             "'" + this.TextBox5.Text + "'" + "," +
                             "'" + this.Calendar1.SelectedDate.Month + "/" + this.Calendar1.SelectedDate.Day + "/" + this.Calendar1.SelectedDate.Year + "'," +
                             "'" + this.Calendar2.SelectedDate.Month + "/" + this.Calendar2.SelectedDate.Day + "/" + this.Calendar2.SelectedDate.Year + "'" +
                             ")";
        queries.Add(query);
        BulletedList1.Items.Add(query);
        if(!this.Button2.Enabled){
            this.Button2.Enabled = true;
        }
    }

    protected void Button2_Click(object sender, EventArgs e)
    {       
            BulletedList1.Items.Clear();
            BulletedList1.Items.Add("Se insertaron " + oracleInsert(queries) + " filas.");
            this.Button2.Enabled = false;
    }
}
