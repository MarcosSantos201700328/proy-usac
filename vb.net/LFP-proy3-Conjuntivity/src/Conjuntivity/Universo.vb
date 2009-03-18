'todo:
' ->agregar operacionens de conjuntos
'   -[hecho]Union        
'   -[hecho]Interseccion
'   -[hecho] Diferencia
'   -[hecho] Diferencia Simetrica
'   -[hecho] Contencion
' 

Public Class Universo ' conjunto universo subclase de Conjunto
    Inherits Conjunto

    Private numConjuntos As Integer
    Private arrConjuntos(64) As Conjunto 'subconjunto dentro del universo
    Private TmpConjunto As New Conjunto()
    ' agrega elementos al conjunto universo
    Public Function agregarElementoUniverso(ByVal e As String) As Integer
        If (buscarElemento(e) = 0) Then
            agregarElemento(e)
        End If
    End Function

    Private clon As New Conjunto()
    'agrega un conjunto al arreglo de conjuntos
    Public Function agregarConjunto(ByVal idconj As String) As Integer
        Dim pos As Integer
        pos = buscarConjunto(idconj)
        If pos = -1 Then  ' si no existe
            arrConjuntos(numConjuntos).inicializar()
            arrConjuntos(numConjuntos).setID(idconj)
            numConjuntos += 1
        Else
            'quitarElementos(pos) 
            arrConjuntos(pos).inicializar()
        End If
        Return numConjuntos
    End Function


    Public Sub New()
        inicializar()
        Dim i As Integer
        For i = 0 To 64
            arrConjuntos(i) = New Conjunto()
        Next
        'clon = Me
        'clon.setID("U")
        Me.setID("U")
        arrConjuntos(0) = Me
        numConjuntos += 1
    End Sub
    'busca un conjunto en el arreglo de conjuntos
    Public Function buscarConjunto(ByVal pid As String) As Integer
        Dim pos As Integer
        Dim i As Integer
        Dim repetidos As Integer
        repetidos = 0
        pos = -1
        For i = 0 To numConjuntos
            If arrConjuntos(i).getID = pid Then
                pos = i
                i = numConjuntos
            End If
        Next
        Return pos
    End Function
    ' Union de conjuntos
    Public Function union(ByVal ConjuntoA As String, ByVal conjuntoB As String) As Conjunto
        Dim i, j, limA, limB, n, m As Integer
        'asigna a enteros las posiciones de los conjuntos
        i = buscarConjunto(ConjuntoA)
        j = buscarConjunto(conjuntoB)
        'si los conjuntos existen
        If ((i >= 0) And ((j >= 0))) Then
            TmpConjunto.inicializar()
            ' asigna limites de ciclo basado en num. elementos de cada conjunto
            limA = arrConjuntos(i).getNumElem()
            limB = arrConjuntos(j).getNumElem()
            For m = 0 To limA
                TmpConjunto.agregarElemento(arrConjuntos(i).getElemento(m))
                For n = 0 To limB
                    TmpConjunto.agregarElemento(arrConjuntos(j).getElemento(n))
                Next
            Next
            Return TmpConjunto
        End If
    End Function
    Public Function union(ByRef ConjuntoA As Conjunto, ByRef conjuntoB As Conjunto) As Conjunto
        Dim limA, limB, n, m As Integer
        'asigna a enteros las posiciones de los conjuntos
        TmpConjunto.inicializar()
        ' asigna limites de ciclo basado en num. elementos de cada conjunto
        limA = ConjuntoA.getNumElem()
        limB = conjuntoB.getNumElem()
        For m = 0 To limA
            TmpConjunto.agregarElemento(ConjuntoA.getElemento(m))
            For n = 0 To limB
                TmpConjunto.agregarElemento(conjuntoB.getElemento(n))
            Next
        Next
        Return TmpConjunto
    End Function
    Public Function union(ByRef ConjuntoA As Conjunto, ByVal conjuntoB As String) As Conjunto
        Dim j, limA, limB, n, m As Integer
        'asigna a enteros las posiciones de los conjuntos
        j = buscarConjunto(conjuntoB)
        'si los conjuntos existen
        If (j >= 0) Then
            TmpConjunto.inicializar()
            ' asigna limites de ciclo basado en num. elementos de cada conjunto
            limA = ConjuntoA.getNumElem()
            limB = arrConjuntos(j).getNumElem()
            For m = 0 To limA
                TmpConjunto.agregarElemento(ConjuntoA.getElemento(m))
                For n = 0 To limB
                    TmpConjunto.agregarElemento(arrConjuntos(j).getElemento(n))
                Next
            Next
            Return TmpConjunto
        End If
    End Function
    ' interseccion de conjuntos
    Public Function interseccion(ByVal ConjuntoA As String, ByVal conjuntoB As String) As Conjunto
        Dim i, j, limA, limB, n, m As Integer
        'asigna a enteros las posiciones de los conjuntos
        i = buscarConjunto(ConjuntoA)
        j = buscarConjunto(conjuntoB)
        'si los conjuntos existen
        If ((i >= 0) And ((j >= 0))) Then
            TmpConjunto.inicializar()
            ' asigna limites de ciclo basado en num. elementos de cada conjunto
            limA = arrConjuntos(i).getNumElem()
            limB = arrConjuntos(j).getNumElem()
            For m = 0 To limA
                For n = 0 To limB
                    If (arrConjuntos(i).getElemento(m) = arrConjuntos(j).getElemento(n)) Then
                        TmpConjunto.agregarElemento(arrConjuntos(j).getElemento(n))
                    End If
                Next
            Next
            Return TmpConjunto
        End If
    End Function
    Public Function interseccion(ByRef ConjuntoA As Conjunto, ByVal conjuntoB As String) As Conjunto
        Dim j, limA, limB, n, m As Integer
        'asigna a enteros las posiciones de los conjuntos
        j = buscarConjunto(conjuntoB)
        'si los conjuntos existen
        If (j >= 0) Then
            TmpConjunto.inicializar()
            ' asigna limites de ciclo basado en num. elementos de cada conjunto
            limA = ConjuntoA.getNumElem()
            limB = arrConjuntos(j).getNumElem()
            For m = 0 To limA
                For n = 0 To limB
                    If (ConjuntoA.getElemento(m) = arrConjuntos(j).getElemento(n)) Then
                        TmpConjunto.agregarElemento(arrConjuntos(j).getElemento(n))
                    End If
                Next
            Next
            Return TmpConjunto
        End If
    End Function
    'diferencia
    Public Function diferencia(ByVal conjuntoA As String, ByVal conjuntoB As String) As Conjunto
        Dim i, j, limA, limB, n, m As Integer
        Dim existe As Boolean
        existe = False
        'Dim ret As New Conjunto()
        'asigna a enteros las posiciones de los conjuntos
        i = buscarConjunto(conjuntoA)
        j = buscarConjunto(conjuntoB)
        'si los conjuntos existen
        If ((i >= 0) And ((j >= 0))) Then
            TmpConjunto.inicializar()
            ' asigna limites de ciclo basado en num. elementos de cada conjunto
            limA = arrConjuntos(i).getNumElem()
            limB = arrConjuntos(j).getNumElem()
            ' busca y compara elemento por elemento
            For m = 0 To limA
                existe = False
                ' si existe un elemento de A igual en B, detiene el ciclo
                ' y asigna bandera
                For n = 0 To limB
                    If (arrConjuntos(i).getElemento(m) = arrConjuntos(j).getElemento(n)) Then
                        existe = True
                        n = limB
                    End If
                Next
                ' si la bandera es false agrega elemento a conjunto a retornar
                If Not (existe) Then
                    'ret.agregarElemento(arrConjuntos(i).getElemento(m))
                    TmpConjunto.agregarElemento(arrConjuntos(i).getElemento(m))
                End If
            Next
            Return TmpConjunto
            'Return ret
        End If
    End Function
    Public Function diferencia(ByRef conjuntoA As Conjunto, ByRef conjuntoB As Conjunto) As Conjunto
        Dim limA, limB, n, m As Integer
        Dim existe As Boolean
        existe = False

        TmpConjunto.inicializar()
        ' asigna limites de ciclo basado en num. elementos de cada conjunto
        limA = conjuntoA.getNumElem()
        limB = conjuntoB.getNumElem()
        ' busca y compara elemento por elemento
        For m = 0 To limA
            existe = False
            ' si existe un elemento de A igual en B, detiene el ciclo
            ' y asigna bandera
            For n = 0 To limB
                If (conjuntoA.getElemento(m) = conjuntoB.getElemento(n)) Then
                    existe = True
                    n = limB
                End If
            Next
            ' si la bandera es false agrega elemento a conjunto a retornar
            If Not (existe) Then
                TmpConjunto.agregarElemento(conjuntoA.getElemento(m))
            End If
        Next
        Return TmpConjunto
    End Function
    Public Function diferencia(ByRef conjuntoA As Conjunto, ByVal conjuntoB As String) As Conjunto
        Dim j, limA, limB, n, m As Integer
        Dim existe As Boolean
        existe = False
        'asigna a enteros las posiciones de los conjuntos
        j = buscarConjunto(conjuntoB)
        'si los conjuntos existen
        If (j >= 0) Then
            TmpConjunto.inicializar()
            ' asigna limites de ciclo basado en num. elementos de cada conjunto
            limA = conjuntoA.getNumElem()
            limB = arrConjuntos(j).getNumElem()
            ' busca y compara elemento por elemento
            For m = 0 To limA
                existe = False
                ' si existe un elemento de A igual en B, detiene el ciclo
                ' y asigna bandera
                For n = 0 To limB
                    If (conjuntoA.getElemento(m) = arrConjuntos(j).getElemento(n)) Then
                        existe = True
                        n = limB
                    End If
                Next
                ' si la bandera es false agrega elemento a conjunto a retornar
                If Not (existe) Then
                    TmpConjunto.agregarElemento(conjuntoA.getElemento(m))
                End If
            Next
            Return TmpConjunto
        End If
    End Function
    'diferencia simetrica
    Public Function diferenciasim(ByVal conjuntoA As String, ByVal conjuntoB As String) As Conjunto
        Dim i, j, limA, limB, n, m As Integer
        Dim tmpA, tmpB, ret As Conjunto
        tmpA = New Conjunto()
        tmpB = New Conjunto()
        i = buscarConjunto(conjuntoA)
        j = buscarConjunto(conjuntoB)
        'si los conjuntos existen
        If ((i >= 0) And ((j >= 0))) Then
            'TmpConjunto.inicializar()
            tmpA.inicializar()
            tmpB.inicializar()
            tmpA.asignar(diferencia(arrConjuntos(i), arrConjuntos(j)))
            tmpB.asignar(diferencia(arrConjuntos(j), arrConjuntos(i)))
            'formula A<>b = A-B + B-A
            TmpConjunto.inicializar()
            TmpConjunto = union(tmpA, tmpB)
        End If
        Return TmpConjunto
    End Function
    Public Function diferenciasim(ByRef conjuntoA As Conjunto, ByVal conjuntoB As String) As Conjunto
        Dim j, limA, limB, n, m As Integer
        Dim tmpA, tmpB, ret As Conjunto
        tmpA = New Conjunto()
        tmpB = New Conjunto()
        j = buscarConjunto(conjuntoB)
        'si los conjuntos existen
        If (j >= 0) Then
            'TmpConjunto.inicializar()
            tmpA.inicializar()
            tmpB.inicializar()
            tmpA.asignar(diferencia(conjuntoA, arrConjuntos(j)))
            tmpB.asignar(diferencia(arrConjuntos(j), conjuntoA))
            'formula A<>b = A-B + B-A
            TmpConjunto.inicializar()
            TmpConjunto = union(tmpA, tmpB)
        End If
        Return TmpConjunto
    End Function
    'complemento
    Public Function complemento(ByVal conjA As String) As Conjunto
        Dim i As Integer
        i = buscarConjunto(conjA)
        TmpConjunto.inicializar()
        TmpConjunto = diferencia(arrConjuntos(0), arrConjuntos(i))
        Return TmpConjunto
    End Function
    Public Function complemento(ByVal conjA As Conjunto) As Conjunto
        'Dim i As Integer
        'i = buscarConjunto(conjA)
        TmpConjunto.inicializar()
        TmpConjunto = diferencia(arrConjuntos(0), conjA)
        Return TmpConjunto
    End Function
    'contencion
    Public Function contencion(ByVal A As String, ByVal B As String) As Boolean
        Dim i, j, m As Integer
        i = buscarConjunto(A)
        j = buscarConjunto(B)
        If (j <> -1) Then
            If (i <> -1) Then ' busca en conjunto dentro de conjunto
                If (arrConjuntos(i).getNumElem() <= arrConjuntos(j).getNumElem()) Then
                    For m = 0 To arrConjuntos(i).getNumElem
                        If (arrConjuntos(j).buscarElemento(arrConjuntos(i).getElemento(m)) = -1) Then
                            Return False
                        End If
                    Next
                    Return True
                Else
                    Return False
                End If
            Else ' busca elemento dentro de conjunto
                If (arrConjuntos(j).buscarElemento(A) = -1) Then
                    Return False
                Else
                    Return True
                End If
            End If
        Else
            Return False
        End If
    End Function
    'asignacion
    Public Overloads Sub asignar(ByVal a As String, ByRef b As Conjunto)
        Dim i As Integer
        Dim j As Integer
        i = buscarConjunto(a)
        arrConjuntos(i).asignar(b)
        arrConjuntos(i).setID(a)
    End Sub

    Public Function agregarElementoAConjunto(ByVal idconj As String, ByVal idelem As String) As Integer
        Dim idxConjunto As Integer
        idxConjunto = buscarConjunto(idconj)
        If (idxConjunto >= -1) Then
            If arrConjuntos(idxConjunto).buscarElemento(idelem) = 0 Then
                arrConjuntos(idxConjunto).agregarElemento(idelem)
                Me.agregarElementoUniverso(idelem)
                Return 0
            Else
                Return -1
            End If
        Else
            Return -2
        End If
    End Function
    Public Function getConjunto(ByVal Pid As String) As Conjunto
        Dim i As Integer
        i = buscarConjunto(Pid)
        If (i > -1) Then
            Return arrConjuntos(i)
        Else
            Return Nothing
        End If
    End Function

End Class
