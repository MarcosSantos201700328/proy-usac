namespace Notepad2
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.codePanel = new System.Windows.Forms.Panel();
            this.closebutton = new System.Windows.Forms.Button();
            this.infoPanel = new System.Windows.Forms.Panel();
            this.infoTabs = new System.Windows.Forms.TabControl();
            this.infotab = new System.Windows.Forms.TabPage();
            this.infoTextBox = new System.Windows.Forms.RichTextBox();
            this.errortab = new System.Windows.Forms.TabPage();
            this.errorTextBox = new System.Windows.Forms.RichTextBox();
            this.menuPrincipal = new System.Windows.Forms.MenuStrip();
            this.archivoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.nuevoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.abrirToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.guardarToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.guardarComoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator4 = new System.Windows.Forms.ToolStripSeparator();
            this.cerrarToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.salirToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.edicionToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.deshacerToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator5 = new System.Windows.Forms.ToolStripSeparator();
            this.cortarToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.copiarToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.pegarToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.verToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tablaLALRToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.pilaLRToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.lenguajeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.añadirLenguajeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.lenguajesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.noSeHaAñadidoNingunLenguajeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator6 = new System.Windows.Forms.ToolStripSeparator();
            this.ventanaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.closeTabToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ayudaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.manualDeUsuarioToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.acercaDeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.saveFileDialog = new System.Windows.Forms.SaveFileDialog();
            this.statusBar = new System.Windows.Forms.Panel();
            this.ejecutarCodigoActualToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.rehacerToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.codePanel.SuspendLayout();
            this.infoPanel.SuspendLayout();
            this.infoTabs.SuspendLayout();
            this.infotab.SuspendLayout();
            this.errortab.SuspendLayout();
            this.menuPrincipal.SuspendLayout();
            this.SuspendLayout();
            // 
            // codePanel
            // 
            resources.ApplyResources(this.codePanel, "codePanel");
            this.codePanel.Controls.Add(this.closebutton);
            this.codePanel.Name = "codePanel";
            this.codePanel.Paint += new System.Windows.Forms.PaintEventHandler(this.codePanel_Paint);
            // 
            // closebutton
            // 
            resources.ApplyResources(this.closebutton, "closebutton");
            this.closebutton.Name = "closebutton";
            this.closebutton.UseVisualStyleBackColor = true;
            this.closebutton.Click += new System.EventHandler(this.closebutton_Click);
            // 
            // infoPanel
            // 
            resources.ApplyResources(this.infoPanel, "infoPanel");
            this.infoPanel.Controls.Add(this.infoTabs);
            this.infoPanel.Name = "infoPanel";
            // 
            // infoTabs
            // 
            this.infoTabs.Controls.Add(this.infotab);
            this.infoTabs.Controls.Add(this.errortab);
            resources.ApplyResources(this.infoTabs, "infoTabs");
            this.infoTabs.Name = "infoTabs";
            this.infoTabs.SelectedIndex = 0;
            // 
            // infotab
            // 
            this.infotab.Controls.Add(this.infoTextBox);
            resources.ApplyResources(this.infotab, "infotab");
            this.infotab.Name = "infotab";
            this.infotab.UseVisualStyleBackColor = true;
            // 
            // infoTextBox
            // 
            resources.ApplyResources(this.infoTextBox, "infoTextBox");
            this.infoTextBox.Name = "infoTextBox";
            this.infoTextBox.ReadOnly = true;
            // 
            // errortab
            // 
            this.errortab.Controls.Add(this.errorTextBox);
            resources.ApplyResources(this.errortab, "errortab");
            this.errortab.Name = "errortab";
            this.errortab.UseVisualStyleBackColor = true;
            // 
            // errorTextBox
            // 
            resources.ApplyResources(this.errorTextBox, "errorTextBox");
            this.errorTextBox.Name = "errorTextBox";
            this.errorTextBox.ReadOnly = true;
            // 
            // menuPrincipal
            // 
            this.menuPrincipal.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.archivoToolStripMenuItem,
            this.edicionToolStripMenuItem,
            this.verToolStripMenuItem,
            this.lenguajeToolStripMenuItem,
            this.ventanaToolStripMenuItem,
            this.ayudaToolStripMenuItem});
            resources.ApplyResources(this.menuPrincipal, "menuPrincipal");
            this.menuPrincipal.Name = "menuPrincipal";
            // 
            // archivoToolStripMenuItem
            // 
            this.archivoToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.nuevoToolStripMenuItem,
            this.toolStripSeparator3,
            this.abrirToolStripMenuItem,
            this.guardarToolStripMenuItem,
            this.guardarComoToolStripMenuItem,
            this.toolStripSeparator4,
            this.cerrarToolStripMenuItem,
            this.salirToolStripMenuItem});
            this.archivoToolStripMenuItem.Name = "archivoToolStripMenuItem";
            resources.ApplyResources(this.archivoToolStripMenuItem, "archivoToolStripMenuItem");
            // 
            // nuevoToolStripMenuItem
            // 
            this.nuevoToolStripMenuItem.Name = "nuevoToolStripMenuItem";
            resources.ApplyResources(this.nuevoToolStripMenuItem, "nuevoToolStripMenuItem");
            this.nuevoToolStripMenuItem.Click += new System.EventHandler(this.nuevoToolStripMenuItem_Click);
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            resources.ApplyResources(this.toolStripSeparator3, "toolStripSeparator3");
            // 
            // abrirToolStripMenuItem
            // 
            this.abrirToolStripMenuItem.Name = "abrirToolStripMenuItem";
            resources.ApplyResources(this.abrirToolStripMenuItem, "abrirToolStripMenuItem");
            this.abrirToolStripMenuItem.Click += new System.EventHandler(this.abrirToolStripMenuItem_Click);
            // 
            // guardarToolStripMenuItem
            // 
            this.guardarToolStripMenuItem.Name = "guardarToolStripMenuItem";
            resources.ApplyResources(this.guardarToolStripMenuItem, "guardarToolStripMenuItem");
            this.guardarToolStripMenuItem.Click += new System.EventHandler(this.guardarToolStripMenuItem_Click);
            // 
            // guardarComoToolStripMenuItem
            // 
            this.guardarComoToolStripMenuItem.Name = "guardarComoToolStripMenuItem";
            resources.ApplyResources(this.guardarComoToolStripMenuItem, "guardarComoToolStripMenuItem");
            this.guardarComoToolStripMenuItem.Click += new System.EventHandler(this.guardarComoToolStripMenuItem_Click);
            // 
            // toolStripSeparator4
            // 
            this.toolStripSeparator4.Name = "toolStripSeparator4";
            resources.ApplyResources(this.toolStripSeparator4, "toolStripSeparator4");
            // 
            // cerrarToolStripMenuItem
            // 
            this.cerrarToolStripMenuItem.Name = "cerrarToolStripMenuItem";
            resources.ApplyResources(this.cerrarToolStripMenuItem, "cerrarToolStripMenuItem");
            this.cerrarToolStripMenuItem.Click += new System.EventHandler(this.cerrarToolStripMenuItem_Click);
            // 
            // salirToolStripMenuItem
            // 
            this.salirToolStripMenuItem.Name = "salirToolStripMenuItem";
            resources.ApplyResources(this.salirToolStripMenuItem, "salirToolStripMenuItem");
            this.salirToolStripMenuItem.Click += new System.EventHandler(this.salirToolStripMenuItem_Click);
            // 
            // edicionToolStripMenuItem
            // 
            this.edicionToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.deshacerToolStripMenuItem,
            this.rehacerToolStripMenuItem,
            this.toolStripSeparator5,
            this.cortarToolStripMenuItem,
            this.copiarToolStripMenuItem,
            this.pegarToolStripMenuItem});
            this.edicionToolStripMenuItem.Name = "edicionToolStripMenuItem";
            resources.ApplyResources(this.edicionToolStripMenuItem, "edicionToolStripMenuItem");
            this.edicionToolStripMenuItem.Click += new System.EventHandler(this.edicionToolStripMenuItem_Click);
            // 
            // deshacerToolStripMenuItem
            // 
            this.deshacerToolStripMenuItem.Name = "deshacerToolStripMenuItem";
            resources.ApplyResources(this.deshacerToolStripMenuItem, "deshacerToolStripMenuItem");
            this.deshacerToolStripMenuItem.Click += new System.EventHandler(this.deshacerToolStripMenuItem_Click);
            // 
            // toolStripSeparator5
            // 
            this.toolStripSeparator5.Name = "toolStripSeparator5";
            resources.ApplyResources(this.toolStripSeparator5, "toolStripSeparator5");
            // 
            // cortarToolStripMenuItem
            // 
            this.cortarToolStripMenuItem.Name = "cortarToolStripMenuItem";
            resources.ApplyResources(this.cortarToolStripMenuItem, "cortarToolStripMenuItem");
            this.cortarToolStripMenuItem.Click += new System.EventHandler(this.cortarToolStripMenuItem_Click);
            // 
            // copiarToolStripMenuItem
            // 
            this.copiarToolStripMenuItem.Name = "copiarToolStripMenuItem";
            resources.ApplyResources(this.copiarToolStripMenuItem, "copiarToolStripMenuItem");
            this.copiarToolStripMenuItem.Click += new System.EventHandler(this.copiarToolStripMenuItem_Click);
            // 
            // pegarToolStripMenuItem
            // 
            this.pegarToolStripMenuItem.Name = "pegarToolStripMenuItem";
            resources.ApplyResources(this.pegarToolStripMenuItem, "pegarToolStripMenuItem");
            this.pegarToolStripMenuItem.Click += new System.EventHandler(this.pegarToolStripMenuItem_Click);
            // 
            // verToolStripMenuItem
            // 
            this.verToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tablaLALRToolStripMenuItem,
            this.pilaLRToolStripMenuItem});
            this.verToolStripMenuItem.Name = "verToolStripMenuItem";
            resources.ApplyResources(this.verToolStripMenuItem, "verToolStripMenuItem");
            // 
            // tablaLALRToolStripMenuItem
            // 
            this.tablaLALRToolStripMenuItem.Name = "tablaLALRToolStripMenuItem";
            resources.ApplyResources(this.tablaLALRToolStripMenuItem, "tablaLALRToolStripMenuItem");
            // 
            // pilaLRToolStripMenuItem
            // 
            this.pilaLRToolStripMenuItem.Name = "pilaLRToolStripMenuItem";
            resources.ApplyResources(this.pilaLRToolStripMenuItem, "pilaLRToolStripMenuItem");
            // 
            // lenguajeToolStripMenuItem
            // 
            this.lenguajeToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.añadirLenguajeToolStripMenuItem,
            this.toolStripSeparator1,
            this.lenguajesToolStripMenuItem});
            this.lenguajeToolStripMenuItem.Name = "lenguajeToolStripMenuItem";
            resources.ApplyResources(this.lenguajeToolStripMenuItem, "lenguajeToolStripMenuItem");
            // 
            // añadirLenguajeToolStripMenuItem
            // 
            this.añadirLenguajeToolStripMenuItem.Name = "añadirLenguajeToolStripMenuItem";
            resources.ApplyResources(this.añadirLenguajeToolStripMenuItem, "añadirLenguajeToolStripMenuItem");
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            resources.ApplyResources(this.toolStripSeparator1, "toolStripSeparator1");
            // 
            // lenguajesToolStripMenuItem
            // 
            this.lenguajesToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.noSeHaAñadidoNingunLenguajeToolStripMenuItem,
            this.toolStripSeparator6});
            this.lenguajesToolStripMenuItem.Name = "lenguajesToolStripMenuItem";
            resources.ApplyResources(this.lenguajesToolStripMenuItem, "lenguajesToolStripMenuItem");
            // 
            // noSeHaAñadidoNingunLenguajeToolStripMenuItem
            // 
            this.noSeHaAñadidoNingunLenguajeToolStripMenuItem.Name = "noSeHaAñadidoNingunLenguajeToolStripMenuItem";
            resources.ApplyResources(this.noSeHaAñadidoNingunLenguajeToolStripMenuItem, "noSeHaAñadidoNingunLenguajeToolStripMenuItem");
            // 
            // toolStripSeparator6
            // 
            this.toolStripSeparator6.Name = "toolStripSeparator6";
            resources.ApplyResources(this.toolStripSeparator6, "toolStripSeparator6");
            // 
            // ventanaToolStripMenuItem
            // 
            this.ventanaToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.closeTabToolStripMenuItem,
            this.ejecutarCodigoActualToolStripMenuItem});
            this.ventanaToolStripMenuItem.Name = "ventanaToolStripMenuItem";
            resources.ApplyResources(this.ventanaToolStripMenuItem, "ventanaToolStripMenuItem");
            // 
            // closeTabToolStripMenuItem
            // 
            this.closeTabToolStripMenuItem.Name = "closeTabToolStripMenuItem";
            resources.ApplyResources(this.closeTabToolStripMenuItem, "closeTabToolStripMenuItem");
            // 
            // ayudaToolStripMenuItem
            // 
            this.ayudaToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.manualDeUsuarioToolStripMenuItem,
            this.toolStripSeparator2,
            this.acercaDeToolStripMenuItem});
            this.ayudaToolStripMenuItem.Name = "ayudaToolStripMenuItem";
            resources.ApplyResources(this.ayudaToolStripMenuItem, "ayudaToolStripMenuItem");
            this.ayudaToolStripMenuItem.Click += new System.EventHandler(this.ayudaToolStripMenuItem_Click);
            // 
            // manualDeUsuarioToolStripMenuItem
            // 
            this.manualDeUsuarioToolStripMenuItem.Name = "manualDeUsuarioToolStripMenuItem";
            resources.ApplyResources(this.manualDeUsuarioToolStripMenuItem, "manualDeUsuarioToolStripMenuItem");
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            resources.ApplyResources(this.toolStripSeparator2, "toolStripSeparator2");
            // 
            // acercaDeToolStripMenuItem
            // 
            this.acercaDeToolStripMenuItem.Name = "acercaDeToolStripMenuItem";
            resources.ApplyResources(this.acercaDeToolStripMenuItem, "acercaDeToolStripMenuItem");
            this.acercaDeToolStripMenuItem.Click += new System.EventHandler(this.acercaDeToolStripMenuItem_Click);
            // 
            // openFileDialog
            // 
            this.openFileDialog.FileName = "openFileDialog";
            resources.ApplyResources(this.openFileDialog, "openFileDialog");
            this.openFileDialog.SupportMultiDottedExtensions = true;
            // 
            // saveFileDialog
            // 
            resources.ApplyResources(this.saveFileDialog, "saveFileDialog");
            // 
            // statusBar
            // 
            resources.ApplyResources(this.statusBar, "statusBar");
            this.statusBar.Name = "statusBar";
            // 
            // ejecutarCodigoActualToolStripMenuItem
            // 
            this.ejecutarCodigoActualToolStripMenuItem.Name = "ejecutarCodigoActualToolStripMenuItem";
            resources.ApplyResources(this.ejecutarCodigoActualToolStripMenuItem, "ejecutarCodigoActualToolStripMenuItem");
            // 
            // rehacerToolStripMenuItem
            // 
            this.rehacerToolStripMenuItem.Name = "rehacerToolStripMenuItem";
            resources.ApplyResources(this.rehacerToolStripMenuItem, "rehacerToolStripMenuItem");
            this.rehacerToolStripMenuItem.Click += new System.EventHandler(this.rehacerToolStripMenuItem_Click);
            // 
            // Form1
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.statusBar);
            this.Controls.Add(this.infoPanel);
            this.Controls.Add(this.codePanel);
            this.Controls.Add(this.menuPrincipal);
            this.MainMenuStrip = this.menuPrincipal;
            this.Name = "Form1";
            this.codePanel.ResumeLayout(false);
            this.infoPanel.ResumeLayout(false);
            this.infoTabs.ResumeLayout(false);
            this.infotab.ResumeLayout(false);
            this.errortab.ResumeLayout(false);
            this.menuPrincipal.ResumeLayout(false);
            this.menuPrincipal.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel codePanel;
        private System.Windows.Forms.Panel infoPanel;
        private System.Windows.Forms.MenuStrip menuPrincipal;
        private System.Windows.Forms.ToolStripMenuItem archivoToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem edicionToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem verToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem lenguajeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem ayudaToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem acercaDeToolStripMenuItem;
        private System.Windows.Forms.TabControl infoTabs;
        private System.Windows.Forms.TabPage infotab;
        private System.Windows.Forms.TabPage errortab;
        private System.Windows.Forms.ToolStripMenuItem ventanaToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem closeTabToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem nuevoToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem abrirToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem guardarToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem guardarComoToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem salirToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem deshacerToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem cortarToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem copiarToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem pegarToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem tablaLALRToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem pilaLRToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem añadirLenguajeToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem lenguajesToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem noSeHaAñadidoNingunLenguajeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem manualDeUsuarioToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.OpenFileDialog openFileDialog;
        private System.Windows.Forms.SaveFileDialog saveFileDialog;
        private System.Windows.Forms.RichTextBox infoTextBox;
        private System.Windows.Forms.RichTextBox errorTextBox;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator4;
        private System.Windows.Forms.ToolStripMenuItem cerrarToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator5;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator6;
        private System.Windows.Forms.Button closebutton;
        private System.Windows.Forms.Panel statusBar;
        private System.Windows.Forms.ToolStripMenuItem ejecutarCodigoActualToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem rehacerToolStripMenuItem;
    }
}

