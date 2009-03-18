using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;
namespace Notepad2
{
     

    public partial class Form1 : Form
    {
        private AboutBox ab;
        //tabbed editor
        private editor editorTabs;
        public Form1()
        {
            InitializeComponent();
            
            editorTabs = new editor();
            this.codePanel.Controls.Add(this.editorTabs);
        }

        private void ayudaToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void tabPage1_Click(object sender, EventArgs e)
        {

        }

        private void abrirToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Stream myStream;

            openFileDialog.FileName = editorTabs.getCurrentEditorPage().Name;
            if(openFileDialog.ShowDialog() == DialogResult.OK)
            {
                if((myStream = openFileDialog.OpenFile())!= null)
                {
                    editorTabs.loadFile(myStream,openFileDialog.FileName);
                    
                    myStream.Close();
                }
            }
        }

        private void salirToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void deshacerToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (this.editorTabs.Controls.Count > 0)
                editorTabs.getCurrentTextBox().Undo();
        }

        private void acercaDeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ab = new AboutBox();
            ab.Show();
        }

        private void nuevoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.editorTabs.nuevoTab();
        }

        private void guardarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                this.editorTabs.getCurrentTextBox().SaveFile(this.editorTabs.getCurrentEditorPage().Name, RichTextBoxStreamType.PlainText);
            }
            catch(Exception exp)
            {
                execSaveAsDialog();
            }
            finally
            {
            }
        }
        /// <summary>
        /// Ejecuta un dialogo de Guardar Como y guarda datos si se requiere
        /// </summary>
        private void execSaveAsDialog()
        {
            Stream myStream;
            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                if ((myStream = saveFileDialog.OpenFile()) != null)
                {
                    editorTabs.saveFile(myStream, saveFileDialog.FileName);
                    myStream.Close();
                }
            }
        }

        private void edicionToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void codePanel_Paint(object sender, PaintEventArgs e)
        {

        }

        private void guardarComoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            execSaveAsDialog();
        }

        private void cerrarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            cerrarActual();
        }
        public void cerrarActual()
        {

            if (this.editorTabs.Controls.Count > 0)
                this.editorTabs.Controls.Remove(this.editorTabs.getCurrentEditorPage());
        }

        private void closebutton_Click(object sender, EventArgs e)
        {
            cerrarActual();
        }

        private void rehacerToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (this.editorTabs.Controls.Count > 0)
                editorTabs.getCurrentTextBox().Redo();
        }

        private void cortarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (this.editorTabs.Controls.Count > 0)
                editorTabs.getCurrentTextBox().Cut();
        }

        private void copiarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (this.editorTabs.Controls.Count > 0)
                editorTabs.getCurrentTextBox().Copy();
        }

        private void pegarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (this.editorTabs.Controls.Count > 0)
                editorTabs.getCurrentTextBox().Paste();
        }
    }
}