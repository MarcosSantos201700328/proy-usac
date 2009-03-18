VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Object = "{3B7C8863-D78F-101B-B9B5-04021C009402}#1.2#0"; "RICHTX32.OCX"
Begin VB.Form Form1 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "STRIM Frontend"
   ClientHeight    =   5550
   ClientLeft      =   3150
   ClientTop       =   1995
   ClientWidth     =   7455
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   5550
   ScaleWidth      =   7455
   Begin MSComDlg.CommonDialog CommonDialog2 
      Left            =   4320
      Top             =   0
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      DefaultExt      =   "*.txt"
      DialogTitle     =   "Guardar Como..."
      FileName        =   "200313492.txt"
      Filter          =   "*.txt"
   End
   Begin VB.Timer Timer1 
      Enabled         =   0   'False
      Interval        =   5000
      Left            =   4920
      Top             =   0
   End
   Begin RichTextLib.RichTextBox RichTextBox2 
      Height          =   2055
      Left            =   0
      TabIndex        =   2
      Top             =   3480
      Width           =   7455
      _ExtentX        =   13150
      _ExtentY        =   3625
      _Version        =   393217
      BorderStyle     =   0
      Enabled         =   -1  'True
      ScrollBars      =   3
      TextRTF         =   $"Form1.frx":0000
   End
   Begin RichTextLib.RichTextBox RichTextBox1 
      Height          =   2535
      Left            =   0
      TabIndex        =   1
      Top             =   720
      Width           =   7455
      _ExtentX        =   13150
      _ExtentY        =   4471
      _Version        =   393217
      BorderStyle     =   0
      Enabled         =   -1  'True
      ScrollBars      =   3
      TextRTF         =   $"Form1.frx":0085
   End
   Begin VB.CommandButton Ejecutar 
      Caption         =   "&Ejecutar"
      Enabled         =   0   'False
      Height          =   495
      Left            =   2880
      TabIndex        =   0
      Top             =   0
      Width           =   1215
   End
   Begin MSComDlg.CommonDialog CommonDialog1 
      Left            =   5640
      Top             =   0
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      DefaultExt      =   "*.txt"
      DialogTitle     =   "Abrir\Guardar..."
      Filter          =   "*.txt"
      InitDir         =   "c:/"
   End
   Begin VB.Label Label2 
      Caption         =   "Archivo de Salida"
      Height          =   255
      Left            =   120
      TabIndex        =   4
      Top             =   3240
      Width           =   1815
   End
   Begin VB.Label Label1 
      Caption         =   "Archivo de Entrada"
      Height          =   255
      Left            =   120
      TabIndex        =   3
      Top             =   480
      Width           =   1815
   End
   Begin VB.Menu menuArchivo 
      Caption         =   "Archivo"
      Begin VB.Menu menuAbrir 
         Caption         =   "Abrir..."
         Shortcut        =   ^O
      End
      Begin VB.Menu menuGuardar 
         Caption         =   "Guardar"
         Shortcut        =   ^S
      End
      Begin VB.Menu menuSalir 
         Caption         =   "Salir"
         Shortcut        =   ^W
      End
   End
   Begin VB.Menu menuCodigo 
      Caption         =   "Codigo"
      Begin VB.Menu menuEjecutar 
         Caption         =   "Ejecutar"
         Enabled         =   0   'False
         Shortcut        =   {F9}
      End
   End
   Begin VB.Menu menuHelp 
      Caption         =   "Ayuda"
      Begin VB.Menu menuManual 
         Caption         =   "Manual de Usuario"
         Shortcut        =   {F1}
      End
      Begin VB.Menu menuAcerca 
         Caption         =   "Acerca De..."
      End
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim Filename As String
Dim FileNameSalida As String
Private Sub fillEntradaTextBox()
    If Filename <> "" Then
        RichTextBox1.LoadFile Filename, 1
    End If
End Sub

' Guarda el contenido del archivo de entrada
Private Sub saveEntradaTextBox()
    If Filename <> "" Then
        RichTextBox1.SaveFile Filename, 1
    End If
End Sub


Private Sub Ejecutar_Click()
    Call Exec
End Sub

Private Sub FillSalidaTextBox()
    If Filename <> "" Then
         '     Timer1.Enabled
        RichTextBox2.LoadFile FileNameSalida, 1
        
    End If
End Sub

Private Sub Exec()
'Timer = True
    Dim cmd As String
   
    CommonDialog2.ShowSave
    FileNameSalida = CommonDialog2.Filename
    If FileNameSalida <> "" Then
        cmd = "strim.exe " + Chr(34) + Filename + Chr(34) + " " + Chr(34) + FileNameSalida + Chr(34) 'concatena nombre del programa con parametros
        If Shell(cmd) <> 0 Then ' abre aplicacion strim
            Call FillSalidaTextBox
            Ejecutar.Enabled = True
            menuEjecutar.Enabled = True
        Else
            menuEjecutar.Enabled = False
        End If
    End If
    
End Sub

Private Sub menuAbrir_Click()
    CommonDialog1.ShowOpen
    Filename = CommonDialog1.Filename
    If Filename <> "" Then
        Call fillEntradaTextBox
        Ejecutar.Enabled = True
        menuEjecutar.Enabled = True
    Else
        menuEjecutar.Enabled = False
    End If
End Sub


Private Sub menuAcerca_Click()
frmAbout.Show
End Sub

Private Sub menuEjecutar_Click()
    Call Exec
End Sub

Private Sub menuGuardar_Click()
    Call saveEntradaTextBox
End Sub

Private Sub menuSalir_Click()
        Unload Me
        End
        
End Sub

