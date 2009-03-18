using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace Notepad2
{
    /// <summary>
    /// 
    /// Editor basado en tabs
    /// </summary>
    public class editor : System.Windows.Forms.TabControl
    {
        private EditorPage ep1;
        private LinkedList<lenguaje> langs;/**Lista de lenguajes*/
        //RichTextBox actual;
        public int agregarLenguaje(){
            
        }
        public editor(): base()
        {
            ep1 = new EditorPage("nuevo");
            // 
            // editorTabs
            // 
            this.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            //this.Controls.Add(this.tabPage1);
            this.Location = new System.Drawing.Point(3, 3);
            this.Name = "editorTabs";
            this.SelectedIndex = 0;
            //this.Size = new System.Drawing.Size(586, 200);
            //this.Size = new System.Drawing.Size(616, 260);
            this.Dock = System.Windows.Forms.DockStyle.Fill;
            this.TabIndex = 0;
            //insertamos nueva pagina de tab

            this.Controls.Add(ep1);

        }
        
        ~editor()
        {
        }

        private void InitializeComponent()
        {
            this.SuspendLayout();
            this.ResumeLayout(false);

        }
        /// <summary>
        /// Inserta un nuevo tab.
        /// </summary>
        public void nuevoTab()
        {
            EditorPage ed = new EditorPage("nuevo" + (this.Controls.Count + 1));                      
            this.Controls.Add(ed); //insertamos
            this.SelectTab(ed); //hacemos la nueva visible
        }

        //public void
        /// <summary>
        /// Devuelve el actual editor
        /// </summary>
        /// <returns>
        /// editor actual
        /// </returns>
        public EditorPage getCurrentEditorPage()
        {
            return (EditorPage)this.GetControl(this.SelectedIndex);
        }
        /// <summary>
        /// Obtiene el Textbox del tab seleccionado
        /// </summary>
        /// <returns></returns>
        public RichTextBox getCurrentTextBox()
        {
            return this.getCurrentEditorPage().textBox;
        }

        public void loadFile(Stream s, String filename)
        {            
            this.nuevoTab();
            this.getCurrentTextBox().LoadFile(s, RichTextBoxStreamType.PlainText);
            this.getCurrentEditorPage().Text = filename;
            this.getCurrentEditorPage().Name = filename;
        }
        public void saveFile(Stream s, String filename)
        {
            //this.nuevoTab();
            this.getCurrentTextBox().SaveFile(s, RichTextBoxStreamType.PlainText);
            this.getCurrentEditorPage().Text = filename;
            this.getCurrentEditorPage().Name = filename;            
        }
    }

    /// <summary>
    /// Pagina de editor
    /// </summary>
    public class EditorPage : TabPage
    {
        private RichTextBox rt1;
        private bool isSaved;
        /// <summary>
        /// Especifica si se ha guardado el tab actual
        /// </summary>
        public bool saved{
            get{
                return isSaved;
            }
            set{
                isSaved = value;
            }
        }
        /// <summary>
        /// Propiedad de textbox interno
        /// </summary>
        public RichTextBox textBox
        {
            get{
                return rt1;
            }   
            set{
                rt1 = value;
            }
        }
        /// <summary>
        /// Constructor
        /// </summary>
        /// 
        private void Setup()
        {
            rt1 = new RichTextBox();
            // 
            // richTextBox1
            // 
            this.rt1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.rt1.Location = new System.Drawing.Point(0, 0);
            this.rt1.Name = "richTextBox1";
            this.rt1.Size = new System.Drawing.Size(578, 174);
            this.rt1.TabIndex = 0;
            this.rt1.Text = "";
            this.rt1.Dock = System.Windows.Forms.DockStyle.Fill;
            //this.rt1.r
            // 
            // tabPage1
            //
            this.Controls.Add(this.rt1);
            this.Location = new System.Drawing.Point(4, 22);
            this.Name = "tabPage1";
            this.Padding = new System.Windows.Forms.Padding(3);
            this.Size = new System.Drawing.Size(578, 174);
            this.TabIndex = 0;
            this.Text = "tabPage1";
            this.UseVisualStyleBackColor = true;
            this.Click += new System.EventHandler(this.onClick);          
            this.TextChanged += new System.EventHandler(this.changeSaveState);
            //
            this.saved = false;
        }
        public EditorPage() : base()
        {
            this.Setup();
        }
        public EditorPage(String name) : base(name)
        {            
            this.Setup();
            this.Text = name;
        }
        /// <summary>
        /// Evento de click
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void onClick(object sender, EventArgs e)
        {

        }
        /// <summary>
        /// Cambia el estado del objeto si se modifica texto, asigna la bandera saved
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void changeSaveState(object sender, EventArgs e)
        {            
            saved = false;
            this.Name.Insert(0,"[*]");
        }

        public void saveToFile(){
        }

    }

}
