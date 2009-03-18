Public Class Form1
    Inherits System.Windows.Forms.Form
    Private NombreArchivo As String    'Establece nombre de archivo
    Private Const version As Double = 0.1
    Private aboutdialog As about
    Private lex As New Lexer()
    Private elParser As New parser()
    Private oldtext As String
    Private line As Integer
    ' Private tim As New Timer()

#Region " Windows Form Designer generated code "

    Public Sub New()
        MyBase.New()

        'This call is required by the Windows Form Designer.
        InitializeComponent()

        'Add any initialization after the InitializeComponent() call

    End Sub

    'Form overrides dispose to clean up the component list.
    Protected Overloads Overrides Sub Dispose(ByVal disposing As Boolean)
        If disposing Then
            If Not (components Is Nothing) Then
                components.Dispose()
            End If
        End If
        MyBase.Dispose(disposing)
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    Friend WithEvents MainMenu1 As System.Windows.Forms.MainMenu
    Friend WithEvents MenuItem1 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem2 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem3 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem4 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem5 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem6 As System.Windows.Forms.MenuItem
    Friend WithEvents OpenFileDialog1 As System.Windows.Forms.OpenFileDialog
    Friend WithEvents RichTextBox1 As System.Windows.Forms.RichTextBox
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents SaveFileDialog1 As System.Windows.Forms.SaveFileDialog
    Friend WithEvents StatusBar1 As System.Windows.Forms.StatusBar
    Friend WithEvents MenuItem8 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem9 As System.Windows.Forms.MenuItem
    Friend WithEvents editor As System.Windows.Forms.RichTextBox
    Friend WithEvents MenuItem10 As System.Windows.Forms.MenuItem
    Friend WithEvents MenuItem7 As System.Windows.Forms.MenuItem
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Dim resources As System.Resources.ResourceManager = New System.Resources.ResourceManager(GetType(Form1))
        Me.MainMenu1 = New System.Windows.Forms.MainMenu()
        Me.MenuItem1 = New System.Windows.Forms.MenuItem()
        Me.MenuItem2 = New System.Windows.Forms.MenuItem()
        Me.MenuItem10 = New System.Windows.Forms.MenuItem()
        Me.MenuItem7 = New System.Windows.Forms.MenuItem()
        Me.MenuItem3 = New System.Windows.Forms.MenuItem()
        Me.MenuItem8 = New System.Windows.Forms.MenuItem()
        Me.MenuItem9 = New System.Windows.Forms.MenuItem()
        Me.MenuItem4 = New System.Windows.Forms.MenuItem()
        Me.MenuItem5 = New System.Windows.Forms.MenuItem()
        Me.MenuItem6 = New System.Windows.Forms.MenuItem()
        Me.OpenFileDialog1 = New System.Windows.Forms.OpenFileDialog()
        Me.RichTextBox1 = New System.Windows.Forms.RichTextBox()
        Me.Button1 = New System.Windows.Forms.Button()
        Me.SaveFileDialog1 = New System.Windows.Forms.SaveFileDialog()
        Me.StatusBar1 = New System.Windows.Forms.StatusBar()
        Me.editor = New System.Windows.Forms.RichTextBox()
        Me.SuspendLayout()
        '
        'MainMenu1
        '
        Me.MainMenu1.MenuItems.AddRange(New System.Windows.Forms.MenuItem() {Me.MenuItem1, Me.MenuItem8, Me.MenuItem4})
        '
        'MenuItem1
        '
        Me.MenuItem1.Index = 0
        Me.MenuItem1.MenuItems.AddRange(New System.Windows.Forms.MenuItem() {Me.MenuItem2, Me.MenuItem10, Me.MenuItem7, Me.MenuItem3})
        Me.MenuItem1.Text = "&Archivo"
        '
        'MenuItem2
        '
        Me.MenuItem2.Index = 0
        Me.MenuItem2.Shortcut = System.Windows.Forms.Shortcut.CtrlO
        Me.MenuItem2.Text = "&Abrir Archivo..."
        '
        'MenuItem10
        '
        Me.MenuItem10.Enabled = False
        Me.MenuItem10.Index = 1
        Me.MenuItem10.Shortcut = System.Windows.Forms.Shortcut.CtrlS
        Me.MenuItem10.Text = "&Guardar archivo..."
        '
        'MenuItem7
        '
        Me.MenuItem7.Index = 2
        Me.MenuItem7.Text = "-"
        '
        'MenuItem3
        '
        Me.MenuItem3.Index = 3
        Me.MenuItem3.Shortcut = System.Windows.Forms.Shortcut.CtrlW
        Me.MenuItem3.Text = "Sali&r"
        '
        'MenuItem8
        '
        Me.MenuItem8.Index = 1
        Me.MenuItem8.MenuItems.AddRange(New System.Windows.Forms.MenuItem() {Me.MenuItem9})
        Me.MenuItem8.Text = "&Programa"
        '
        'MenuItem9
        '
        Me.MenuItem9.Enabled = False
        Me.MenuItem9.Index = 0
        Me.MenuItem9.Shortcut = System.Windows.Forms.Shortcut.F9
        Me.MenuItem9.Text = "P&rocesar Datos"
        '
        'MenuItem4
        '
        Me.MenuItem4.Index = 2
        Me.MenuItem4.MenuItems.AddRange(New System.Windows.Forms.MenuItem() {Me.MenuItem5, Me.MenuItem6})
        Me.MenuItem4.Text = "A&yuda"
        '
        'MenuItem5
        '
        Me.MenuItem5.Enabled = False
        Me.MenuItem5.Index = 0
        Me.MenuItem5.Shortcut = System.Windows.Forms.Shortcut.F1
        Me.MenuItem5.Text = "&Manual de Usuario"
        '
        'MenuItem6
        '
        Me.MenuItem6.Index = 1
        Me.MenuItem6.Text = "&Acerca de..."
        '
        'OpenFileDialog1
        '
        Me.OpenFileDialog1.DefaultExt = "txt"
        Me.OpenFileDialog1.InitialDirectory = "c:\"
        Me.OpenFileDialog1.ReadOnlyChecked = True
        Me.OpenFileDialog1.Title = "Abrir Archivo de Entrada ..."
        '
        'RichTextBox1
        '
        Me.RichTextBox1.BackColor = System.Drawing.Color.WhiteSmoke
        Me.RichTextBox1.Cursor = System.Windows.Forms.Cursors.Default
        Me.RichTextBox1.Font = New System.Drawing.Font("Arial", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.RichTextBox1.ForeColor = System.Drawing.Color.Navy
        Me.RichTextBox1.Location = New System.Drawing.Point(1, 216)
        Me.RichTextBox1.Name = "RichTextBox1"
        Me.RichTextBox1.ReadOnly = True
        Me.RichTextBox1.Size = New System.Drawing.Size(560, 72)
        Me.RichTextBox1.TabIndex = 0
        Me.RichTextBox1.Text = "Salida:"
        '
        'Button1
        '
        Me.Button1.Cursor = System.Windows.Forms.Cursors.Hand
        Me.Button1.Enabled = False
        Me.Button1.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.Button1.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Button1.Location = New System.Drawing.Point(29, 0)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(504, 24)
        Me.Button1.TabIndex = 1
        Me.Button1.Text = "Procesar &datos"
        '
        'SaveFileDialog1
        '
        Me.SaveFileDialog1.DefaultExt = "txt"
        Me.SaveFileDialog1.FileName = "salida"
        Me.SaveFileDialog1.Filter = "Archivos de Texto|*.txt"
        '
        'StatusBar1
        '
        Me.StatusBar1.Location = New System.Drawing.Point(0, 291)
        Me.StatusBar1.Name = "StatusBar1"
        Me.StatusBar1.Size = New System.Drawing.Size(562, 16)
        Me.StatusBar1.TabIndex = 2
        Me.StatusBar1.Text = "Haga clic en ""Archivo->Abrir Archivo"""
        '
        'editor
        '
        Me.editor.Font = New System.Drawing.Font("Courier New", 9.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.editor.Location = New System.Drawing.Point(1, 24)
        Me.editor.Name = "editor"
        Me.editor.Size = New System.Drawing.Size(560, 192)
        Me.editor.TabIndex = 3
        Me.editor.Text = "Editor"
        Me.editor.WordWrap = False
        '
        'Form1
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(5, 13)
        Me.ClientSize = New System.Drawing.Size(562, 307)
        Me.Controls.AddRange(New System.Windows.Forms.Control() {Me.editor, Me.StatusBar1, Me.Button1, Me.RichTextBox1})
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.MaximizeBox = False
        Me.Menu = Me.MainMenu1
        Me.Name = "Form1"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "Conjuntivity"
        Me.ResumeLayout(False)

    End Sub

#End Region

    Private Sub MenuItem5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem5.Click
        StatusBar1.Text = "Lo Siento, Opcion no disponible por el momento"
        'Shell("wordpad man.doc")
    End Sub

    Private Sub MenuItem2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem2.Click
        OpenFileDialog1.ShowDialog() 'abre dialogo de abrir archivo

    End Sub

    Private Sub MenuItem3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem3.Click
        Me.Close()
    End Sub


    Private Sub OpenFileDialog1_FileOk(ByVal sender As System.Object, ByVal e As System.ComponentModel.CancelEventArgs) Handles OpenFileDialog1.FileOk
        Me.setNombreArchivo(OpenFileDialog1.FileName) ' establece nombre de archivo a abrir
        elParser.setNombreArchivo(NombreArchivo)
        Try
            editor.LoadFile(OpenFileDialog1.FileName, RichTextBoxStreamType.PlainText)
            editor.ReadOnly = False
            'editor.Refresh()
            MenuItem10.Enabled = True
            StatusBar1.Text = "Haga Clic sobre el boton Procesar o presione F9 para iniciar la interpretacion"
        Catch
            StatusBar1.Text = "Archivo no existe"
        End Try

        'lex.setnombreArchivo(NombreArchivo)
        Button1.Enabled = True
        MenuItem9.Enabled = True
    End Sub
    Public Sub setNombreArchivo(ByVal nombre As String)
        NombreArchivo = nombre 'asigna nombre de archivo
    End Sub


    Private Sub Procesar()
        'If lex.abrirArchivo() = True Then
        'lex.leerTokenHastaEOF(RichTextBox1)
        'lex.cerrarArchivo()
        'endif
        If elParser.abrirArchivo() = True Then
            StatusBar1.Text = "Procesando archivo de entrada..."
            RichTextBox1.ResetText()
            elParser.setFlagError(False)
            elParser.Leer()
            elParser.cerrarArchivo()
            RichTextBox1.Focus()
            RichTextBox1.Select(RichTextBox1.Text.Length, 0)
            RichTextBox1.ScrollToCaret()
            StatusBar1.Text = "Listo."
        End If
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Call Procesar()
    End Sub

    Private Sub MenuItem7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)
        SaveFileDialog1.ShowDialog()
    End Sub

    Private Sub MenuItem6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem6.Click
        aboutdialog = New about()
        aboutdialog.ShowDialog()

        'aboutdialog.Dispose()
    End Sub

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        elParser.setTextBox(RichTextBox1)
        OpenFileDialog1.DefaultExt = "*.txt"
        OpenFileDialog1.Filter = "Texto plano UTF8 (*.txt)|*.txt|Todos los Archivos (*.*)|*.*"

        'Dim i As Integer
        'For i = 0 To 100
        'Me.Opacity = i
        'Next

    End Sub

    Private Sub MenuItem9_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem9.Click
        Call Procesar()
    End Sub


    Private Sub MenuItem10_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MenuItem10.Click
        Try
            editor.SaveFile(NombreArchivo, RichTextBoxStreamType.PlainText)
        Catch
            StatusBar1.Text = "Imposible guardar"
        End Try
    End Sub

    Private Sub MostrarNumLinea()
        line = editor.GetLineFromCharIndex(editor.SelectionStart()) + 1
        StatusBar1.Text = "Linea: " + line.ToString 'editor.GetLineFromCharIndex(editor.GetCharIndexFromPosition(editor.MousePosition())).ToString
    End Sub

    Private Sub editor_Keyup(ByVal sender As System.Object, ByVal e As System.Windows.Forms.KeyEventArgs) Handles editor.KeyUp
        'If (NombreArchivo.Length > 0) Then
        If e.KeyCode = Keys.Up Or e.KeyCode = Keys.Down _
            Or e.KeyCode = Keys.Left Or e.KeyCode = Keys.Right _
            Or e.KeyCode = Keys.PageDown Or e.KeyCode = Keys.PageUp Then
            MostrarNumLinea()
        End If
        ' End If
    End Sub
    Private Sub editor_enter(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles editor.Enter
        oldtext = StatusBar1.Text
        MostrarNumLinea()
    End Sub
    Private Sub editor_leave(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles editor.Leave
        StatusBar1.Text = oldtext
    End Sub
End Class
