'todo:
' -[hecho] Agregar operacion toString que me transforme el conjunto a cadena de caracteres

Public Class Conjunto ' clase base de TDA conjuntos.
    Implements ICloneable
    Private Const maxelem = 512
    Private elemento(maxelem) As String
    Private ID As String ' identificador del conjunto
    Private contadorElem As Integer ' contador de elementos

    Public Function agregarElemento(ByVal elem As String) As Integer
        If buscarElemento(elem) = 0 Then
            elemento(contadorElem) = elem
            contadorElem = contadorElem + 1
        End If
        Return contadorElem
    End Function

    Public Sub setID(ByVal pid As String)
        ID = pid
    End Sub

    'devuelve el numero de elementos del conjunto
    Public Function getNumElem() As Integer
        Return contadorElem
    End Function

    'inicializa a 0 los elementos
    Public Sub inicializar()
        contadorElem = 0
        Dim i As Integer
        For i = 0 To maxelem
            elemento(i) = ""
        Next
    End Sub
    'devuelve cantidad de elementos encontrados repetidos iguales al del parametro
    Public Function buscarElemento(ByVal elem As String) As Integer
        Dim i As Integer
        Dim repetidos As Integer
        repetidos = 0
        For i = 0 To contadorElem
            If elemento(i) = elem Then
                repetidos = repetidos + 1
            End If
        Next

        Return repetidos
    End Function

    Public Function getElemento(ByRef indice As Integer) As String
        Return elemento(indice)
    End Function

    'Representacion de cadena de caracteres de un conjunto
    Public Overrides Function toString() As String
        Dim ret As String
        Dim i As Integer
        ret = getID() + " = {"
        For i = 0 To Me.contadorElem
            If (i < (Me.contadorElem - 1)) Then
                ret += Me.getElemento(i) + ", "
            Else
                ret += Me.getElemento(i)
            End If
        Next
        ret += "}"
        Return ret
    End Function

    ' constructor
    Public Sub New()
        inicializar()
    End Sub

    ' retorna id del conjunto
    Public Function getID() As String
        Return Me.ID
    End Function

    ' copia elementos de un conjunto en este
    Public Function asignar(ByVal c2 As Conjunto) As Boolean
        Dim i As Integer
        Me.inicializar()
        Me.ID = c2.getID()
        For i = 0 To c2.getNumElem
            Me.agregarElemento(c2.getElemento(i))
        Next
        Return True
    End Function
    Public Overridable Function Clone() As Object Implements ICloneable.Clone
        Dim copy As New Conjunto()
        copy = Me
        Return copy
    End Function
End Class