'todo:
'Probar el lexer
Public Class Lexer
    Private nombreArchivo As String
    Private caracterleido As Char ' caracter actualmente leido
    Private pos As Long ' posicion dentro del archivo
    Private Numlinea As Integer = 1  ' Numero de linea actual
    Private Const numkeywords = 13
    Private inicio As Integer
    Private fin As Boolean
    Private salir As Boolean
    Private tmpCadena As String
    Private tmpLexema As String
    Structure lex 'Relaciona lexemas de las palabras reservadas con su respectivo token
        Public token As Integer
        Public lexema As String
    End Structure
    ' Listado de tokens enumerados
    Public Enum Token
        s_inicio = 0 ' estado inicial
        s_normal = 1 ' estado normal de transicion
        s_fin = 2   ' estado final
        s_error = 3 ' Si hay error lexico
        '---------Elementos del lenguaje
        tk_alpha = 10 '::=(a|b|...|z|A|B|...|Z)
        tk_digito = 11 '::=(0|1|2|3|4|5|6|7|8|9)
        tk_num = 12 '::=(num)(num)*
        tk_identificador = 13 '::=(tk_alpha)(tk_alpha | tk_num)*
        tk_simbolo = 14 '::=(tk_op... | tk_sim...)
        tk_texto = 15
        tk_abreComment = 16 '::="/*"
        tk_CierraComment = 17 '::="*/"
        '---------Operadores y Simbolos
        'Operadores
        tk_op_igual = 20 ' ::= "="
        tk_op_union = 21 ' ::= "+"
        tk_op_intersec = 22 ' ::= *
        tk_op_dif = 23 ' ::= "-" 
        tk_op_difsim = 24 ' ::= "<>"
        tk_op_complemento = 25 ' ::= "@"
        tk_op_contencion = 26 ' ::= "%"
        'Simbolos
        tk_sm_abreparent = 30 ' ::= "("
        tk_sm_cierraparent = 31 ' ::= ")"
        tk_sm_puntoycoma = 32 ' ::= ";"
        tk_sm_dospuntos = 33 ' ::= ":"
        tk_sm_abrellave = 34 ' ::= "{"
        tk_sm_cierrallave = 35 ' ::= "}"
        tk_sm_diagonal = 36 ' ::= "/"
        tk_sm_coma = 37 ' ::=","
        tk_sm_lesst = 38 ' ::="<"
        tk_sm_greatt = 38 ' ::=">"
        '        tk_sm_abrecoment = 38 ' ::= (
        '        tk_sm_cierracoment = 39 '
        ' otros
        '---------Palabras reservadas'
        tk_kw_programa = 100
        tk_kw_conjuntos = 101
        tk_kw_inicio = 102
        tk_kw_resultados = 103
        tk_kw_fin = 104
        tk_kw_si = 105
        tk_kw_entonces = 106
        tk_kw_sino = 107
        tk_kw_salida = 108
        tk_kw_escribir = 109
        tk_kw_pantalla = 110
        tk_kw_archivo = 111
        tk_kw_impresora = 112
        'tk_reservada = 31 ' palabra reservada


    End Enum

    Public reservadas(numkeywords) As lex
    ' INICIALIZA TABLA DE PALABRAS RESERVADAS
    Public Sub initReservadas()
        Dim i As Integer
        ' asigna numero de token al vector de reservadas
        For i = 0 To numkeywords
            reservadas(i).token = i + 100
        Next
        reservadas(0).lexema = "PROGRAMA"
        reservadas(1).lexema = "CONJUNTOS"
        reservadas(2).lexema = "INICIO"
        reservadas(3).lexema = "RESULTADOS"
        reservadas(4).lexema = "FIN"
        reservadas(5).lexema = "SI"
        reservadas(6).lexema = "ENTONCES"
        reservadas(7).lexema = "SINO"
        reservadas(8).lexema = "SALIDA"
        reservadas(9).lexema = "ESCRIBIR"
        reservadas(10).lexema = "PANTALLA"
        reservadas(11).lexema = "ARCHIVO"
        reservadas(12).lexema = "IMPRESORA"
    End Sub
    Public Sub setnombreArchivo(ByVal n As String)
        nombreArchivo = n
    End Sub
    ' Lee tokens desde el archivo de entrada y devuelve sus respectivos valores 
    Public Function leerToken() As lex
        Dim tipo As Integer ' evita el parametro antiguo
        tipo = 1

        Dim tokenA As Token
        Dim regLex As lex ' Estructura a devolver con el token y el lexema
        tokenA = tokenA.s_inicio
        fin = False
        salir = False
        tmpLexema = ""
        While (salir = False) And (EOF(1) = False)
            leerCaracter()
            tmpCadena = caracterleido
            tmpLexema += tmpCadena
            Select Case (tokenA)
                Case Token.s_inicio
                    dfaInicio(tokenA) 'llama para procesar DFA inicial
                Case Token.tk_identificador
                    dfaIdentificador(tokenA) 'llama para procesar DFA para identificador
                Case Token.tk_digito
                    dfaNumero(tokenA) 'llama para procesar DFA para numero
                Case Token.tk_num
                    dfaNumero(tokenA) 'llama para procesar DFA para numero
                Case Token.tk_sm_lesst ' llama para procesar dfa para '<>'
                    dfaDifSim(tokenA)
                Case Token.tk_sm_diagonal ' llama para procesar dfa para '/*'
                    dfaAbreComent(tokenA)
                Case Token.tk_op_intersec
                    dfaCierraComent(tokenA)
                Case Else
                    salir = True
                    tmpLexema = tmpLexema.TrimEnd(caracterleido) ' elimina un caracter
                    PutChar() 'devuelve el ultimo caracter leido
            End Select
        End While
        If (EOF(1)) Then ' si se encuentra EOF se asigna bandera Salir
            salir = 1
        End If
        If (tokenA = Token.tk_identificador) Then ' Si es identificador
            If (tipo = 1) Then   ' Compara para ver si es palabra reservada
                tokenA = getPalabraReservada()
            Else ' sino, es texto normal
                tokenA = Token.s_normal
            End If
        End If
        regLex.lexema = tmpLexema ' asigna al registro el lexema actual
        regLex.token = tokenA ' y su respectivo token
        Return regLex
    End Function
    Public Sub dfaInicio(ByRef tok As Token)
        'delimitadores
        If (caracterleido = " " Or Asc(caracterleido) = 13 Or Asc(caracterleido) = 10 Or Asc(caracterleido) = 9) Then
            tmpLexema = tmpLexema.TrimEnd(caracterleido) ' elimina un caracter
            '----------------'

        ElseIf (Char.IsDigit(caracterleido) = True) Then
            tok = Token.tk_digito
        ElseIf (Char.IsLetter(caracterleido) = True) Then
            tok = Token.tk_identificador
        ElseIf (caracterleido = "=") Then
            tok = Token.tk_op_igual
        ElseIf (caracterleido = "+") Then
            tok = Token.tk_op_union
        ElseIf (caracterleido = "*") Then
            tok = Token.tk_op_intersec
        ElseIf (caracterleido = "=") Then
            tok = Token.tk_op_igual
        ElseIf (caracterleido = "-") Then
            tok = Token.tk_op_dif
        ElseIf (caracterleido = "<") Then 'dfa para Diferencia Simi
            tok = Token.tk_sm_lesst
        ElseIf (caracterleido = "@") Then
            tok = Token.tk_op_complemento
        ElseIf (caracterleido = "%") Then
            tok = Token.tk_op_contencion
        ElseIf (caracterleido = "(") Then
            tok = Token.tk_sm_abreparent
        ElseIf (caracterleido = ")") Then
            tok = Token.tk_sm_cierraparent
        ElseIf (caracterleido = ";") Then
            tok = Token.tk_sm_puntoycoma
        ElseIf (caracterleido = ":") Then
            tok = Token.tk_sm_dospuntos
        ElseIf (caracterleido = "{") Then
            tok = Token.tk_sm_abrellave
        ElseIf (caracterleido = "}") Then
            tok = Token.tk_sm_cierrallave
        ElseIf (caracterleido = "/") Then
            tok = Token.tk_sm_diagonal
        ElseIf (caracterleido = ",") Then
            tok = Token.tk_sm_coma
        Else
            tok = Token.tk_texto
            salir = True
        End If


    End Sub

    Public Sub dfaIdentificador(ByRef tk As Token)
        If (Char.IsLetterOrDigit(caracterleido)) Then
            tk = Token.tk_identificador
        Else
            PutChar()
            salir = True
            tmpLexema = tmpLexema.TrimEnd(caracterleido) ' elimina un caracter
        End If
    End Sub
    'REVISAR
    Public Sub dfaAbreComent(ByRef tk As Token)
        If caracterleido = "*" Then
            tk = Token.tk_abreComment
        Else
            PutChar()
            salir = True
            tmpLexema = tmpLexema.TrimEnd(caracterleido) ' elimina un caracter
            tk = Token.s_error ' error
        End If
    End Sub
    Public Sub dfaCierraComent(ByRef tk As Token)
        If caracterleido = "/" Then
            tk = Token.tk_CierraComment
        Else
            PutChar()
            salir = True
            tmpLexema = tmpLexema.TrimEnd(caracterleido) ' elimina un caracter
            tk = Token.tk_op_intersec ' error
        End If
    End Sub
    Public Sub dfaDifSim(ByRef tk As Token)
        If caracterleido = ">" Then
            tk = Token.tk_op_difsim 'diferencia simetrica
        Else
            PutChar()
            salir = True
            tmpLexema = tmpLexema.TrimEnd(caracterleido) ' elimina un caracter
            tk = Token.s_error ' error
        End If
    End Sub
    Public Sub dfaNumero(ByRef tk As Token)
        tk = Token.tk_num
        If Char.IsDigit(caracterleido) Then
            tk = Token.tk_num
        Else
            PutChar()
            salir = True
            tmpLexema = tmpLexema.TrimEnd(caracterleido) ' elimina un caracter
        End If
    End Sub

    Public Function getPalabraReservada() As Token
        Dim tmpToken As Token = Token.tk_identificador
        Dim i As Integer = 0
        While (i < numkeywords)
            If (reservadas(i).lexema = tmpLexema) Then
                tmpToken = reservadas(i).token
                i = 17
            Else
                i += 1
            End If
        End While
        Return tmpToken
    End Function

    Public Function getNombreArchivo() As String
        Return nombreArchivo
    End Function
    'constructor
    Public Function getNumLinea() As Int16
        Return Numlinea
    End Function
    Sub New()
        initReservadas()
        caracterleido = ChrW(0)
        pos = 0

    End Sub

    Public Function abrirArchivo() As Boolean 'abre archivo de entrada
        Try
            'abre en modo aleatorio para poder retroceder un caracter
            FileOpen(1, nombreArchivo, OpenMode.Random, OpenAccess.Read, , Len("b"))
        Catch
            Return False
        End Try
        Return True
    End Function
    Public Function cerrarArchivo() As Integer 'cierra archivo de entrada
        Try
            FileClose(1)
            Numlinea = 1
        Catch
            Return -1
        End Try
        Return 0
    End Function

    'lee un solo caracter desde input
    Public Sub leerCaracter()
        Dim charVal As Integer
        FileGet(1, caracterleido) 'lee caracter
        charVal = Asc(caracterleido)
        pos = Seek(1) ' actualiza posicion de caracter
        If Char.IsLetter(caracterleido) Then 'Con esto se elimina la sensibilidad a mayusculas
            'Char.ToUpper(caracterleido)
            caracterleido = UCase(caracterleido)
        End If
        If Asc(caracterleido) = 13 Then
            Numlinea += 1
        End If
        'Return InputString(1, 1)
    End Sub
    'backspace de un solo caracter para lectura de fichero
    Public Sub PutChar()
        pos = pos - 1
        Seek(1, pos)
        If Asc(caracterleido) = 13 Then
            Numlinea -= 1
        End If
    End Sub
    'devuelve caracter leido
    Public Function getCaracterLeido() As Char
        Return caracterleido
    End Function
    'lee todos los caracteres hasta EOF y lo escribe al stdout
    Public Sub leerHastaEOF(ByRef salida As RichTextBox)
        While EOF(1) = False
            leerCaracter() ' lee caracter
            salida.Text = salida.Text + getCaracterLeido()
            'salida.Refresh()
        End While
    End Sub
    'DEBUG
    Public Sub leerTokenHastaEOF(ByRef salida As RichTextBox)
        Dim localLex As lex
        While EOF(1) = False
            localLex = leerToken() ' lee caracter
            salida.Text = salida.Text + "Token =" + localLex.token.ToString + " lexema = " + localLex.lexema + Chr(10) + Chr(13)
            'salida.Refresh()
        End While
    End Sub
End Class
