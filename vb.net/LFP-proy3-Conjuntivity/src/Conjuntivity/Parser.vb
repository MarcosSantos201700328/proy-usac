'todo
' [hecho] leer bloque conjuntos
' leer bloque inicio
' [hecho]  -Operacion(string ConjuntoA,int operador, string conjuntoB)
' [hecho]  -Operacion(Conjunto ConjuntoA,int operador, string conjuntoB)
' [hecho]leer bloque resultados
' - validar todos los conjuntos
'   - debugear expr() para que asigne conjuntos)
'   - debugear las operaciones para que generen conjuntos correctos
'   - debugear asignacion de conjuntos en universo
' mandar a impresora

Public Class Parser
    Private scanner As New Lexer()
    Private flagComentario As Boolean = False

    Private textBox As RichTextBox

    Private lexico As Lexer.lex
    Private enumtokens As Lexer.Token

    Private conjUniverso As New Universo() 'conjunto universo

    Private flagError As Boolean
    Private banderaIf = True

    Private printFont As Font
    Private streamToPrint As System.IO.StreamReader
    Structure Simbolos
        Public nombrePrograma As String 'nombre del programa
        Public conjuntoOperado As Conjunto ' conjunto temporal que sera el que se opere paso a paso
        Public operadorActual As Integer ' operador actual
        Public conjuntoAAsignar As String ' id del conjunto al que se le asignara ConjuntoOperado al final de la expresion
        Public conjuntoAEscribir As String
        Public tipoSalida As Integer ' tipo de salida que sera evaluado al final del programa
    End Structure

    Private SimbolosParser As Simbolos

    Public Sub setFlagError(ByVal valor As Boolean)
        flagError = valor
    End Sub

    Public Sub setNombreArchivo(ByVal nom As String)
        scanner.setnombreArchivo(nom)
    End Sub

    Public Function abrirArchivo() As Boolean
        Return scanner.abrirArchivo()
    End Function
    Public Sub cerrarArchivo()
        scanner.cerrarArchivo()
    End Sub
    Public Sub Leer()
        lexico = scanner.leerToken()
        programa()
        Conjuntos()
        inicio()
        resultados()
        fin()
    End Sub

    Private Sub programa()
        Dim nombre As String
        match(enumtokens.tk_kw_programa)
        nombre = identificador()
        If Not (nombre = "ERRORIDENT") Then
            SimbolosParser.nombrePrograma = nombre
        End If
    End Sub

    Private Sub Conjuntos()
        match(enumtokens.tk_kw_conjuntos)
        While Not (lexico.token = enumtokens.tk_kw_inicio) And Not flagError
            defConjs()
            If lexico.token = enumtokens.tk_abreComment Then
                comentario()
            End If
        End While
    End Sub

    Private Sub defConjs()
        Dim nomConj As String
        nomConj = identificador()
        If Not (nomConj = "ERRORIDENT") Then
            SimbolosParser.conjuntoAAsignar = nomConj
            match(enumtokens.tk_op_igual)
            match(enumtokens.tk_sm_abrellave)
            conjUniverso.agregarConjunto(nomConj) 'inicializa conjunto a asignar
            elemList()
        End If
    End Sub

    Private Sub elemList()
        Dim i As Integer
        i = 0
        While Not (lexico.token = enumtokens.tk_sm_cierrallave) And Not flagError
            elemento(i)
            i += 1
            If lexico.token = enumtokens.tk_abreComment Then
                comentario()
            End If
        End While
        If (lexico.token = enumtokens.tk_sm_cierrallave) Then
            match(enumtokens.tk_sm_cierrallave)
        End If
    End Sub

    Sub New()
        SimbolosParser.conjuntoOperado = New Conjunto()
    End Sub

    Private Sub elemento(ByVal i As Integer)
        Dim ret As Integer
        Dim elem As String
        ret = 0
        elem = identOnum()
        If Not (elem = "ERRORIDENT") Then
            If banderaIf = True Then
                ret = conjUniverso.agregarElementoAConjunto(SimbolosParser.conjuntoAAsignar, elem)
            End If
            If Not (lexico.token = enumtokens.tk_sm_cierrallave) Then
                match(enumtokens.tk_sm_coma)
            End If
        End If
    End Sub

    Private Function identOnum() As String
        Dim ret As String
        ret = "ERRORIDENT"
        If (lexico.token = enumtokens.tk_identificador Or lexico.token = enumtokens.tk_num) Then
            ret = lexico.lexema
            lexico = scanner.leerToken()
        ElseIf (lexico.token = enumtokens.tk_abreComment) Then
            comentario()
            If (lexico.token = enumtokens.tk_identificador) Then
                ret = lexico.lexema
                lexico = scanner.leerToken()
            Else
                EscribirError("Se esperaba Identificador")
                flagError = True
            End If
        Else
            EscribirError("Se esperaba Identificador")
            flagError = True
        End If

        Return ret
    End Function
    Private Function identificador() As String
        Dim ret As String
        ret = "ERRORIDENT"
        If (lexico.token = enumtokens.tk_identificador) Then
            ret = lexico.lexema
            lexico = scanner.leerToken()
        ElseIf (lexico.token = enumtokens.tk_abreComment) Then
            comentario()
            If (lexico.token = enumtokens.tk_identificador) Then
                ret = lexico.lexema
                lexico = scanner.leerToken()
            Else
                EscribirError("Se esperaba Identificador")
                flagError = True
            End If
        Else
            EscribirError("Se esperaba Identificador")
            flagError = True
        End If
        Return ret
    End Function

    Private Sub match(ByVal tipoToken As Integer)
        If (lexico.token = tipoToken) Then
            lexico = scanner.leerToken()
        ElseIf (lexico.token = enumtokens.tk_abreComment) Then
            comentario()
            If (lexico.token = tipoToken) Then
                lexico = scanner.leerToken()
            Else
                EscribirError("Se esperaba Identificador")
                flagError = True
            End If
        Else
            EscribirError("Se esperaba otro token")
            flagError = True
        End If
    End Sub
    Public Sub comentario()
        While (lexico.token <> enumtokens.tk_CierraComment)
            lexico = scanner.leerToken()
        End While
        lexico = scanner.leerToken()
    End Sub
    Private Sub fin()
        match(enumtokens.tk_kw_fin)
    End Sub

    Public Sub setTextBox(ByRef tx As RichTextBox)
        textBox = tx
    End Sub

    Private Sub inicio()
        match(enumtokens.tk_kw_inicio)
        While Not (lexico.token = enumtokens.tk_kw_resultados Or flagError)
            If (lexico.token = enumtokens.tk_kw_si) Then
                bloqueIf()
            ElseIf lexico.token = enumtokens.tk_identificador Then
                bloqueAsignacion()
            ElseIf lexico.token = enumtokens.tk_abreComment Then
                comentario()
            Else
                EscribirError("Se esperaba bloque de asignacion o bloque if")
            End If
        End While
    End Sub

    Private Sub bloqueIf()
        banderaIf = False
        match(enumtokens.tk_kw_si)
        op_contencion()
        match(enumtokens.tk_kw_entonces)
        If lexico.token = enumtokens.tk_abreComment Then
            comentario()
        End If
        While (lexico.token = enumtokens.tk_identificador And Not flagError)
            bloqueAsignacion()
            If lexico.token = enumtokens.tk_abreComment Then
                comentario()
            End If
        End While
        banderaIf = True
        If (lexico.token = enumtokens.tk_kw_sino) Then
            match(enumtokens.tk_kw_sino)
            If lexico.token = enumtokens.tk_abreComment Then
                comentario()
            End If
            banderaIf = False
            While (lexico.token = enumtokens.tk_identificador And Not flagError)
                bloqueAsignacion()
                If lexico.token = enumtokens.tk_abreComment Then
                    comentario()
                End If
            End While
            banderaIf = True
            match(enumtokens.tk_kw_fin)
            match(enumtokens.tk_kw_si)
            match(enumtokens.tk_sm_puntoycoma)
        ElseIf (lexico.token = enumtokens.tk_kw_fin) Then
            match(enumtokens.tk_kw_fin)
            match(enumtokens.tk_kw_si)
            match(enumtokens.tk_sm_puntoycoma)
        Else
            EscribirError("Se esperaba sino o fin si")
        End If
    End Sub

    Private Sub op_contencion()
        Dim conjA As String = "/nulo"
        Dim conjB As String = "/nulo"
        conjA = identOnum()
        match(enumtokens.tk_op_contencion)
        conjB = identificador()
        If Not (conjA = "/nulo" Or conjB = "/nulo") Then
            If (conjUniverso.contencion(conjA, conjB)) Then
                banderaIf = True
            Else
                banderaIf = False
            End If
        Else
            EscribirError("Se esperaba identificador")
            banderaIf = False
        End If
    End Sub
    Private Sub bloqueAsignacion()
        SimbolosParser.conjuntoAAsignar = identificador()
        match(enumtokens.tk_op_igual)
        If (lexico.token = enumtokens.tk_sm_abrellave) Then
            match(enumtokens.tk_sm_abrellave)
            If banderaIf = True Then
                conjUniverso.agregarConjunto(SimbolosParser.conjuntoAAsignar) 'inicializa conjunto a asignar
            End If
            elemList()
            match(enumtokens.tk_sm_puntoycoma)
        ElseIf (lexico.token = enumtokens.tk_identificador) Then
            expr()
        Else
            EscribirError("Se esperaba expresion")
        End If
    End Sub
    Private Sub expr() 'evalua gramatica ID = A+B-C...Z
        Dim tmpConjunto As New Conjunto()
        Dim i As Integer = 0
        Dim op As Integer = 0
        Dim conjA As String = "/nulo"
        Dim conjB As String = conjA
        While Not (lexico.token = enumtokens.tk_sm_puntoycoma Or flagError)
            If (i = 0) Then
                conjA = identificador()
                If (lexico.token <> enumtokens.tk_sm_puntoycoma) Then
                    op = operador()
                    ' para los otros operadores
                    If (op <> enumtokens.tk_op_complemento) Then
                        conjB = identificador()
                        If (conjUniverso.buscarConjunto(conjA) <> -1 And conjUniverso.buscarConjunto(conjB) <> -1) Then
                            tmpConjunto = operacion(conjA, op, conjB)
                            i += 1
                        Else
                            EscribirError(conjA + " y " + conjB + " no existen.")
                        End If

                    Else 'para complemento
                        If (conjUniverso.buscarConjunto(conjA) <> -1) Then
                            tmpConjunto = operacion(conjA, op, "\nul")
                            i += 1
                        Else
                            EscribirError(conjA + " y " + conjB + " no existen.")
                        End If
                    End If
                End If
            Else
                op = operador()
                If (op <> enumtokens.tk_op_complemento) Then 'para los otros operadores
                    conjB = identificador()
                    If (conjUniverso.buscarConjunto(conjB) <> -1) Then
                        tmpConjunto = operacion(tmpConjunto, op, conjB)
                    Else
                        EscribirError(conjB + " no existe.")
                    End If
                Else 'para complemento
                    tmpConjunto = operacion(tmpConjunto, op, "")
                End If
            End If
        End While
        If i > 0 And Not (tmpConjunto Is Nothing) Then
            If banderaIf = True Then
                conjUniverso.asignar(SimbolosParser.conjuntoAAsignar, tmpConjunto)
            Else
                tmpConjunto.inicializar()
            End If
        End If
        match(enumtokens.tk_sm_puntoycoma)
    End Sub
    Private Function operador() As Integer
        Dim op As Integer = 0
        Select Case lexico.token
            Case enumtokens.tk_op_union
                op = lexico.token
                match(enumtokens.tk_op_union)
            Case enumtokens.tk_op_intersec
                op = lexico.token
                match(enumtokens.tk_op_intersec)
            Case enumtokens.tk_op_dif
                op = lexico.token
                match(enumtokens.tk_op_dif)
            Case enumtokens.tk_op_difsim
                op = lexico.token
                match(enumtokens.tk_op_difsim)
            Case enumtokens.tk_op_complemento
                op = lexico.token
                match(enumtokens.tk_op_complemento)
            Case Else
                EscribirError("Se esperaba operador (+,-,*,@,<>)")
        End Select
        Return op
    End Function
    'opera semanticamente los conjuntos leidos
    Private Function operacion(ByRef A As Conjunto, ByVal op As Integer, ByVal B As String) As Conjunto
        Select Case op
            Case enumtokens.tk_op_union
                Return conjUniverso.union(A, B)
            Case enumtokens.tk_op_intersec
                Return conjUniverso.interseccion(A, B)
            Case enumtokens.tk_op_dif
                Return conjUniverso.diferencia(A, B)
            Case enumtokens.tk_op_difsim
                Return conjUniverso.diferenciasim(A, B)
            Case enumtokens.tk_op_complemento
                'Return conjUniverso.complemento(A.getID())
                Return conjUniverso.complemento(A)
        End Select
    End Function
    Private Function operacion(ByVal A As String, ByVal op As Integer, ByVal B As String) As Conjunto
        Select Case op
            Case enumtokens.tk_op_union
                Return conjUniverso.union(A, B)
            Case enumtokens.tk_op_intersec
                Return conjUniverso.interseccion(A, B)
            Case enumtokens.tk_op_dif
                Return conjUniverso.diferencia(A, B)
            Case enumtokens.tk_op_difsim
                Return conjUniverso.diferenciasim(A, B)
            Case enumtokens.tk_op_complemento
                Return conjUniverso.complemento(A)
        End Select
    End Function
    Private Sub resultados()
        match(enumtokens.tk_kw_resultados)
        If lexico.token = enumtokens.tk_abreComment Then
            comentario()
        End If
        If (lexico.token = enumtokens.tk_kw_salida) Then
            bloqueSalida()
            bloqueEscribir()
        ElseIf (lexico.token = enumtokens.tk_kw_escribir) Then
            SimbolosParser.tipoSalida = 1
            bloqueEscribir()
        ElseIf lexico.token = enumtokens.tk_abreComment Then
            comentario()
        Else
            EscribirError("Se esperaba Salida o Escribir")
        End If
        If Not (flagError) Then
            Select Case SimbolosParser.tipoSalida
                Case 2
                    imprimir(guardar())
                Case 3
                    guardar()
            End Select
        End If
    End Sub
    Private Function guardar() As String
        Dim myStream As System.IO.Stream
        Dim saveFileDialog1 As New SaveFileDialog()

        saveFileDialog1.Filter = "Archivos de Texto (*.txt)|*.txt|Todos los Archivos (*.*)|*.*"
        saveFileDialog1.FilterIndex = 2
        saveFileDialog1.RestoreDirectory = True
        If saveFileDialog1.ShowDialog() = DialogResult.OK Then
            Try
                textBox.SaveFile(saveFileDialog1.FileName, RichTextBoxStreamType.PlainText)
            Catch exp As Exception
                EscribirError("Imposible escribir: " + exp.ToString)
            End Try

            If Not (myStream Is Nothing) Then
                myStream.Close()
            End If
        End If
        Return saveFileDialog1.FileName
    End Function
    Private Function imprimir(ByVal filename As String)
        Dim pdial As New PrintDialog() ' Dialogo de impresion
        If Not filename Is Nothing Then
            Try
                streamToPrint = New System.IO.StreamReader(filename)
                Try
                    printFont = New Font("Arial", 10)
                    Dim pd As New System.Drawing.Printing.PrintDocument()
                    AddHandler pd.PrintPage, AddressOf Me.pd_PrintPage
                    '-------Asigna propiedades a cuadro de dialogo de impresion
                    pdial.Document = pd
                    pdial.AllowPrintToFile = True
                    pdial.ShowDialog()
                    pdial.Document.Print()
                Finally
                    streamToPrint.Close()
                End Try
            Catch ex As Exception
                MessageBox.Show(ex.Message)
            End Try
        End If
    End Function

    Private Sub pd_PrintPage(ByVal sender As Object, ByVal ev As System.Drawing.Printing.PrintPageEventArgs)
        Dim linesPerPage As Single = 0
        Dim yPos As Single = 0
        Dim count As Integer = 0
        Dim leftMargin As Single = ev.MarginBounds.Left
        Dim topMargin As Single = ev.MarginBounds.Top
        Dim line As String = Nothing

        ' Calcula el numero de lineas por pagina.
        linesPerPage = ev.MarginBounds.Height / printFont.GetHeight(ev.Graphics)

        ' imprime cada linea del archivo.
        While count < linesPerPage
            line = streamToPrint.ReadLine()
            If line Is Nothing Then
                Exit While
            End If
            yPos = topMargin + count * printFont.GetHeight(ev.Graphics)
            ev.Graphics.DrawString(line, printFont, Brushes.Black, leftMargin, yPos, New StringFormat())
            count += 1
        End While

        ' si existen mas lineas imprime mas paginas.
        If Not (line Is Nothing) Then
            ev.HasMorePages = True
        Else
            ev.HasMorePages = False
        End If
    End Sub

    Private Sub bloqueSalida()
        match(enumtokens.tk_kw_salida)
        Select Case lexico.token
            Case enumtokens.tk_kw_pantalla
                match(enumtokens.tk_kw_pantalla)
                SimbolosParser.tipoSalida = 1
            Case enumtokens.tk_kw_impresora
                match(enumtokens.tk_kw_impresora)
                SimbolosParser.tipoSalida = 2
            Case enumtokens.tk_kw_archivo
                match(enumtokens.tk_kw_archivo)
                SimbolosParser.tipoSalida = 3
            Case Else
                EscribirError("Se esperaba tipo de salida (pantalla, impresora, archivo)")
        End Select
    End Sub
    Private Sub bloqueEscribir()
        While Not (lexico.token = enumtokens.tk_kw_fin Or flagError)
            match(enumtokens.tk_kw_escribir)
            match(enumtokens.tk_sm_abreparent)
            listaID()
            match(enumtokens.tk_sm_cierraparent)
        End While
    End Sub
    Private Sub listaID()
        While Not (lexico.token = enumtokens.tk_sm_cierraparent Or flagError)
            SimbolosParser.conjuntoAEscribir = identificador()
            If lexico.token = enumtokens.tk_abreComment Then
                comentario()
            End If
            If Not (flagError) Then
                escribirTmp(SimbolosParser.conjuntoAEscribir)
                If (lexico.token <> enumtokens.tk_sm_cierraparent) Then
                    match(enumtokens.tk_sm_coma)
                End If
            End If
        End While
    End Sub

    Private Sub escribirTmp(ByVal strConjunto As String)
        Dim tmp As Conjunto
        tmp = conjUniverso.getConjunto(strConjunto)
        If Not (tmp Is Nothing) Then
            textBox.Text += tmp.ToString + Chr(10) + Chr(13)
        Else
            EscribirError("Conjunto con identificador " + strConjunto + " no existe.")
        End If
    End Sub
    Private Sub EscribirError(ByVal err As String)
        textBox.Text = textBox.Text + "Error (linea " + scanner.getNumLinea.ToString() + "): " + err + Chr(10) + Chr(13)
        flagError = True
    End Sub

End Class
