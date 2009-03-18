program static;
uses crt;
{$define fpc} (*Establecer "bc" si se va a compilar en Turbo Pascal*)

{-----\/----- EXCLUDED -----\/-----
todo list:
[hecho]- Implementar como funciones a DesvRespMS y PuntoMedio que devuelvan el array calculado

[hecho]- Funcion para Frecuencia Acumulada;
[hecho]- Procedimiento para Logaritmo de Punto Medio y f*log PuntoMedio;
[hecho]- Funcion de Inverso del Punto medio
[hecho]- Funcion para Diferencia de la Media
[hecho]- Funcion de Control de Calculos respecto bandera
 [hecho]- Media Aritmetica
 [hecho]- Mediana
 [hecho]- Moda
 [hecho]- Media Geometrica
 [hecho]- Media Armonica
 [hecho]- Varianza
 [hecho]- Desviacion Estandar
[hecho]- Funcion de Generar Tabla
[hecho]- Funcion de Impresion en Archivo de Texto;
[hecho]- Funcion de Impresion en Pantalla
- Debugear
- Validar divisiones entre 0
[hecho]- Validar Archivo no existe
 -----/\----- EXCLUDED -----/\-----}

const
   max = 255; (* Maximo numero de valores *)
type
   ArrData  = array [1..max] of integer;
   ReaData  = array [1..max] of real;
   Tabla    = array [1..256,1..16] of  real;
   BoolArr  = array [1..7] of boolean;
var
   titulo	      : string[max];
   entrada	      : Text; (*archivo de entrada*)
   intervD	      : ArrData;(* intervalos *)
   intervI	      : ArrData;
   frec		      : ArrData; (* datos importantes *)
   datos	      : ReaData;
   numinterv,numdatos : byte;
   calcular	      : BoolArr;{bandera para calculos}
{$ifdef bp}
function toup(st : string):string;
var
   i	  : byte;
   tmpstr : string;
begin
   for i:=1 to max do
      tmpstr:=upcase(st[i]);
   toup:=tmpstr;
      
end;
{$endif}

(*
 *Frecuencia:
 *  Calcula la frecuencia de datos respecto  intervalo
 *)
procedure Frecuencia;
var
   i,j : byte;{contadores}
begin
   for i:=1 to numdatos do
      for j:=1 to numinterv do
	 if (datos[i] >= intervI[j]) and (datos[i] < intervD[j]) then
	    frec[j]:=frec[j]+1;
end; { Frecuencia }

(*
 *PuntoMedio:
 *  Calcula el Punto Medio en los intervalos y retorna vector
 *  con datos calculados;
 *
 *)
Procedure PuntoMedio(var PM : readata);
var
   i  : byte;{contador}
begin
   for i:=1 to numinterv do
      PM[i]:=(intervI[i] + intervD[i])/2;
  
end; { PuntoMedio }


(*
 *  Media Supuesta
 *  Calcula la Media supuesta respecto Punto Medio como argumento
 *)
function MediaSupuesta(PM : ReaData) : real;
{var
   nm	 : real;}
begin
   {nm:=NumInterv/2 + 0.001;}
   MediaSupuesta:= PM[round(NumInterv/2 +  0.001)]
end;

(*
 * DesvRespMS
 *  Calcula desviacion respecto media supuesta y devuelve datos como
 *  un array de reales ReaData
 *)
procedure DesvRespA(PM : ReaData; A : real;var desv : Readata);
var
   i : byte;
begin
   for i:=1 to numinterv do
      desv[i] := PM[i] - A;
end; { DesvRespA }


(*
 *  TotalDesv:
 *  Toma la desviacion respecto media supuesta y la multiplica por
 *  frecuencia:
 *  Devuelve el array que contiene los datos y su suma
 *)
Procedure TotalDesv(DRA : ReaData; var TD : readata; var total:real);
var
   i   : byte;
   sum : real;
begin
   sum :=0;
   for i:=1 to numinterv do
   begin
      TD[i]:=frec[i]*DRA[i];
      sum := sum + td[i];
   end;
   total:=sum;
end; { TotalDesv }

(*
 * FrecAcum:
 *  Devuelve una arreglo que muestra la frecuencia acumulada
 *  respecto a la que se le dio como parametro.
 *)
procedure FrecAcum(F : Arrdata;var retdata : ArrData);
var
   i,sum   : byte;{contador y suma}
begin;
   sum := 0;
   for i := 1 to numinterv do
   begin
      sum := sum + F[i];
      retdata[i]:= sum;
   end;
end; { FrecAcum }

(*
 * FLogPM:
 *  Genera Logaritmo de Punto Medio y Frecuencia * Logartimo de Punto Medio
 *)
procedure FLogPM(PM : ReaData; F: ArrData;
		 var LPM : ReaData; var FLPM : ReaData; var totalflpm : real );
var
   i : byte; {contador}
begin
   totalflpm:=0;
   for i:=1 to numinterv do
   begin
      LPM[i]:=ln(PM[i]);
      FLPM[i]:=F[i]*LPM[i];
      totalflpm:= totalflpm + flpm[i];
   end;
end; { FLogPM }


(*
 * finvPM:
 *  calcula el inverso del punto medio pm y lo devuelve los
 *  valores en un array de reales
 *)
procedure finvPM(    pm	   : ReaData; var InvPM, FxInvPM : ReaData;
		 var total : real );
var
   i : byte;{contador}
begin
   total:=0;
   for i:=1 to numinterv do
   begin
      if pm[i] <>0 then
	 invPM[i]:=1/pm[i]
      else
	 writeln('Imposible calcular');
      FxInvPM[i] :=invpm[i]*frec[i];
      total:=total + FxInvPM[i];
   end;
end; { invPM }


(*
 * MediaArit
 *  Devuelve la media aritmetica, con parametros de media
 *  supuesta y sumatoria total desviacion
 *)
function MediaArit(A	  : real;
		   sumfxv : real) : real;
begin
   MediaArit:=A + (sumfxv/numdatos);
end; { MediaArit }


(*
 * DiffMedia
 *  Desde los datos del arreglo Punto Medio(PM) y el escalar
 *  Media Aritmetica (PM) devuelve arreglo de Diferencia de la Media
 *)
procedure DiffMedia(PM : ReaData; MA : real;var DM : readata);
var
   i : byte;
begin
   for i:=1 to numinterv do
      DM[i]:=PM[i] - MA;
end; { DiffMedia }


(*
 * FxDiffMedia
 *  Calcula F*Diferencia de la media y F*DM^2, y su total;
 *)
procedure fxDiffMedia(X	: ReaData; var FxX, FxX2: readata; var tot : real);
var
   i : byte;
begin
   tot:=0;
   for i:=1 to numinterv do
   begin
      FxX[i] := frec[i]*X[i];
      FxX2[i] := X[i]*FxX[i];
      tot:=tot + FxX2[i];
   end;
end; { fxDiffMedia }


(*
 * Orden
 *  Algoritmo QuickSort modificado para el proyecto
 *  (c)Copyright 1979,  C.A.R Hoare.
 *)
Procedure orden(var vector : ArrData; primer, ultimo: integer);
var
   i,j	       : byte;
   valor, valt : integer ;
begin
   i:=primer;
   j:=ultimo;
   {encontrar el valor central del arreglo}
   valor := vector[(primer+ultimo)div 2];
   repeat
      while vector[i] < valor do
	 i := i +1;
      while vector[j] > valor do
	 j := j - 1;
      if i<=j then
      begin
	 valt := vector[i];
	 vector[i] := vector[j];
	 vector[j]:= valt;
	 i := i + 1;
	 j := j - 1;
      end
   until i > j;
   if primer < j then
      orden(vector,primer,j);
   if i < ultimo then
      orden(vector,i,ultimo);
end; { orden }

(*
 * Mediana:
 *  Funcion de la Mediana, depende del algoritmo QuickSort
 *  especificado en Orden, devuelve el valor real de la mediana de
 *  las muestras
 *)
function mediana(FAc : ArrData ) : real;
var
   i,index : byte;
   {s	   : boolean;}
   {selec  : arrdata;}
begin
   i:=1;
   index:=0;
   while (index = 0) AND (i <= numinterv) do
   begin
      if FAc[i] >= (numdatos/2) then
      begin;
	 index := i;
      end;
      i:=i+1;
   end;
   {calcula la mediana}
   if (frec[index] <> 0) AND (index > 0) then
      mediana:= IntervI[index] + (((numdatos/2) -
		 FAc[index-1])/Frec[index]) * (intervD[index]-intervI[index])
   else
   begin
      writeln('Error: imposible calcular mediana, division entre cero');
      mediana:=-1;
   end;
end; { mediana }


(*
 * Moda:
 *  Calcula la moda de los valores;
 *)
function moda : real;
var
   i,idx : byte;
   tmp	 : real;
begin
   idx:=0;
   for i:=1 to numdatos do
   begin
      if (i>1) and (i <=2) then
   {   begin}
	 if (frec[i] > frec[i-1]) then
	 begin
	    tmp := frec[i];
	    idx := i
	 end
	 else
	 begin
	    tmp := frec[i+1];
	    idx := i+1
	 end;
     { end;}
      if (i > 2) and (i <= numdatos) then
      begin
	 if (frec[i+1]> frec[i]) or (frec[i+1] > tmp) then
	 begin
	    tmp := frec[i+1];
	    idx := i+1
	 end;
      end;
   end;
   if (2*frec[idx] - frec[idx-1] - frec[idx+1])<> 0 then
      moda := IntervI[idx] + (frec[idx]-frec[idx-1])*
      (intervD[idx] - IntervI[idx])/ (2*frec[idx] - frec[idx-1] - frec[idx+1]);

end; { moda }


(*
 * MediaGeom
 *  Retorna la media Geometrica con el total de f*log(pm)
 *)
function MediaGeom(totflpm : real): real;
begin
   MediaGeom := exp(totflpm/numdatos);
end; { MediaGeom }

(*
 * MediaArm
 *  Calcula la media armonica.
 *)
function MediaArm(TotFxIPM : real) : real;
begin
   if TotFxIPM <> 0 then
      
      MediaArm:=numdatos/(TotFxIPM)
   else
   begin
      writeln('imposible calcular');
      MediaArm:=0;
   end;
end;

(*
 * Varianza:
 *  Calcula la varianza de la muestra;
 *)
function Varianza(totFxX2 : real):real;
begin
   Varianza :=  TotFxX2/numdatos;
end;			


(*
 *  parse:
 *  analiza lexicograficamente la linea y genera
 *  instrucciones conforme comando leido
 *)
procedure parse(lin : string;fase : char; index : integer);
var
   substr    : string; {string auxiliar para operaciones internas}
   num	     : real; {real auxiliar para datos}
   code	     : word; {Verificador de error de VAL()}
   IL,IR     : integer; {enteros auxiliares para Intervalos}
   poss,posl : Integer; {enteros que indican posiciones para Intervalos}
   isneg     : boolean;
begin
   isneg := false;
   case fase of
     'i' : 
   begin
      val(lin[1],num,code);
      if(code = 0) then
      begin
	    poss := pos(' ',lin);
	    posl := pos('<',lin);
	    if ((poss < posl) and (poss<>0)) then
	       substr := copy(lin,1,poss-1)
	    else
	       substr := copy(lin,1,posl-1);
	    val(substr,IL,code);
	    if code = 0 then
	    begin
	       substr := copy(lin,pos('<',lin)+1,64);
	       val(substr,IR,code);
	       intervD[index]:=IR;
	       intervI[index]:=IL;
	       numinterv:=index; {establece total de intervalos}
	    end;
      end
   end;
     'd' : 
   begin
      substr := lin;
      if (lin[1] = '.') then
	 insert('0',lin,1);
      if (lin[1] = '-') then
      begin
	 delete(lin,1,1);
	 if lin[1] = '.' then
	    insert('0',lin,1);
	 isneg := true;
      end;
      val(lin,num,code);
      if code = 0 then
      begin
	 if isneg= true then
	    datos[index]:=(-1)*num
	 else
	    datos[index]:=num;
	 numdatos:=index; {establece total de datos}
      end
      else
      begin
      end;
   end;
      'c' :
   begin
      {$ifdef bp}
      substr:=copy(toup(lin),1,9);
      {$else}
      substr:=copy(upcase(lin),1,9);
      {$endif}
      {$ifdef debug}
      writeln(' fase: ',fase,' index: ',index,' linea: ',substr);
      {$endif}
      if substr = 'MEDIA ARI' then calcular[1] := true;
      if substr = 'MEDIANA'  then calcular[2] := true;
      if substr = 'MODA' then calcular[3]  := true;
      if substr = 'MEDIA ARM' then calcular[4]:= true;
      if substr = 'MEDIA GEO' then calcular[5] := true;
      if substr = 'VARIANZA' then calcular[6] := true;
      if substr = 'DESVIACIO' then calcular[7] := true;
   end;
   end; { case }
end;


(*
 *  inputfile:
 *  lee archivo de entrada y guarda linea por linea a un string
 *)
function inputfile(path : string): boolean;
var
   linea    : string[255]; {linea leida}
   i,j	    : integer; {numero de linea}
(*   code	    : integer; {entero para Val()}*)
   fase	    : char; {bandera para indicar fase}
   comando  : string; {valor de comando}
   existe   : integer; {Existencia de Archivo de Entrada}
 {  Strvalor : string[2]; }
begin	
   i := 1;
   j := 1;
   fase := '0';
   assign(entrada,path);
   {$I-}
   reset(entrada);
   existe:=IOresult;
   {$I+}
   if (existe<>0) OR (length(path)=0) then
   begin
      writeln('archivo no existe');
      inputfile:=false;
   end
   else
   begin
      clrscr;
      textcolor(lightgreen);
      numinterv :=0;
      numdatos:=0;
      write('Leyendo y Analizando el archivo de texto ');
      textcolor(lightblue);
      write(path);
      textcolor(lightgreen);
      writeln('....');
      while not eof(entrada) do
      begin
	 readln(entrada,linea);  {lee linea}
	 {$ifdef bp}
	 comando := copy(toup(linea),1,6); {genera comando}
	 {$else}
	 comando := copy(upcase(linea),1,6); {genera comando}
	 {$endif}
	 {$ifdef debug}      writeln(comando); {$endif}
(*	 val(copy(linea,1,2),IntTst,code); {convierte 1er caracter a numero}*)
	 (* cambia bandera conforme comando dado*)
	 if comando = 'TITULO' then
	 begin
	    {$ifdef bp}
	    titulo := toup(copy(linea,8,max)); {Copia el Titulo principal}
	    {$else}
	    titulo := upcase(copy(linea,8,max)); {Copia el Titulo principal}
	    {$endif}
	       
	    {$ifdef debug}
	    writeln('titulo:',titulo);
	    {$endif}
	    j := i;
	 end;
	 if comando = 'INTERV' then
	 begin
	    fase := 'i';
	    j := i;
	 end;
	 if comando = 'DATOS' then
	 begin
	    fase := 'd';
	    j := i;
	 end;
	 if comando = 'CALCUL' then
	 begin
	    fase := 'c';
	    j:= i;
	 end;
	 if (length(linea) > 0) and not((fase = 'i') and ((linea[1] = '-') or (linea[1] = '.') or (linea[2] = '.'))) then
	 begin
	    Parse(linea,fase,i-j);
	    i := i + 1;
	 end;
      end;
      close(entrada);
      textcolor(white);
      inputfile:=true;
   end;
end; { inputfile }

(*
 * DataGen:
 *  Genera la tabla principal de tipo tabla a ser usada para la salida
 *)
procedure DataGen(var t1 : tabla; var ResCalcs: ReaData);
var
   i						    : integer;
   PM, V, FxV, LPM, FLPM, IPM, DM, FxIPM, FxX, FxX2 : ReaData;
   FA						    : ArrData;
   A, TotFxV, TotFLPM,totFxIPM, MAr,TotFxX2	    : real;
begin
   Writeln('Generando Tabla de Datos...');
   Writeln('  Calculando datos para los intervalos...');
   PuntoMedio(PM); {Punto Medio}
   A := MediaSupuesta(PM); {Media Supuesta}
   DesvRespA(PM,A,V); {Desviacion Respecto A}
   TotalDesv(V,FxV,TotFxV); {frec * Desv y Desviacion Total}
   FrecAcum(frec,FA); {Frecuencia Acumulada}
   FLogPM(PM,frec,LPM,FLPM,TotFLPM);{Log(PM) frec*Log(PM) y Total Frec*Log(PM}
   FInvPM(PM,IPM,FxIPM,totFxIPM); {inverso Punto Medio}
   MAr := MediaArit(A,TotFxV); {Media Aritmetica}
   DiffMedia(PM,MAr, DM); {diferencia Punto Medio}
   FxDiffMedia(DM,FxX,FxX2,TotFxX2);{Frec*DiffMedia, Frec*DiffMedia^2}
   {generacion de la tabla}
   for i:=1 to numinterv do
   begin
      t1[i][1]  := i;
      t1[i][2]  := intervI[i];
      t1[i][3]  := intervD[i];
      t1[i][4]  := PM[i];
      t1[i][5]  := frec[i];
      t1[i][6]  := V[i];
      t1[i][7]  := FxV[i];
      t1[i][8]  := FA[i];
      t1[i][9]  := LPM[i];
      t1[i][10] := FLPM[i];
      t1[i][11] := IPM[i];
      t1[i][12] := FxIPM[i];
      t1[i][13] := DM[i];
      t1[i][14] := FxX[i];
      t1[i][15] := FxX2[i];
   end;
   t1[numinterv + 1][5] := numdatos;
   t1[numinterv + 1][7] := TotFxV;
   t1[numinterv + 1][10] := TotFLPM;
   t1[numinterv + 1][12] := TotFxIPM;
   t1[numinterv + 1][15] := TotFxX2;
   {generacion de resultados de calculos}
   WriteLN('  Calculando Medidas de Tendencia Central...');
   ResCalcs[1] := MAr;
   ResCalcs[2] := mediana(FA);
   ResCalcs[3] := moda;
   ResCalcs[4] := MediaGeom(TotFLPM);
   ResCalcs[5] := MediaArm(TotFxIPM);
   ResCalcs[6] := Varianza(TotFxX2);
   ResCalcs[7] := sqrt(ResCalcs[6]);
   i:=1;
end;

function MostrarStdout(ruta : string): boolean;
forward;

(*
 *  Salida:
 *  Genera la tabla de datos en caracteres ASCII y los escribe
 *  secuencialmente al archivo de salida con el nombre dado por
 *  el usuario
 *)
function salida(Datos : tabla; resultados: ReaData): boolean;
var
   ruta,calcs,filename : string[max];
   out		       : text;
{   existe	       : integer;}
   i		       : byte;
   mostrar	       : char;
begin
   (* Abre archivo de salida *)
   repeat
      textcolor(yellow);
      Writeln('ingrese nombre de archivo de salida');
      textcolor(lightgreen);
      writeln('NOTA:');
      writeln('Seran generados 2 archivos, uno en formato ASCII plano y otro ');
      writeln('en formato HTML. por lo que se debe colocar SOLO EL NOMBRE');
      writeln('SIN EXTENSION');
      textcolor(white);
      readln(filename);
   until (length(filename)>0)  and (pos('.',filename)=0);
   ruta:=concat(filename,'.txt');
   assign(out,ruta);
   {$I-}
   rewrite(out);
{   existe:=IOresult;}
   {$I+}
   {-----\/----- EXCLUDED -----\/-----
   PARTE 1: Archivo TXT
   
   -----/\----- EXCLUDED -----/\-----}
   
   (*Escribe encabezado en archivo de salida TXT*)
   clrscr;
   textcolor(lightgreen);
   write('Creando Tabla en archivo ');
   textcolor(lightblue);
   write(ruta);
   textcolor(lightgreen);
   writeln('....');
   writeln(out,'                               -=',Titulo,'=-');
   write(out,'+___+__________+_____+__________+__________+_____+________');
   writeln(out,'__+______+_______+_______+____+______+_______+_______+');
   write(out,'|   |          |     |          |          |Total|          ');
   writeln(out,'|      |       |       |    | X=   |       |       |');
   write(out,'|No.|Intervalo |Punto|Frecuencia|Desviacion|Desv.|Frecuenc');
   writeln(out,'ia|Ln(PM)|  f*   |Inverso| f* |PM-   | f*x   | f*x^2 |');
   write(out,'|   |          |Medio|    f     | v=PM-A   |f*v  |Acum');
   writeln(out,'ulada |      | Ln(PM)| 1/PM  |1/PM| MAR  |       |       |');
   write(out,'+===+==========+=====+==========+==========+=====+==');
   writeln(out,'========+======+=======+=======+====+======+=======+=======+');
   (*Escribe cada dato en la tabla de archivo de salida TXT*)
   for i:= 1 to numinterv do
   begin
      writeln(out,'|',Datos[i][1]:3:0,'|',Datos[i][2]:3:0,'  < ',
	      Datos[i][3]:3:0,'|', datos[i][4]:5:0,'|',datos[i][5]:6:0,
	      '    |',datos[i][6]:5:0,'     |',datos[i][7]:5:0,'|',
	      datos[i][8]:5:0,'     |',datos[i][9]:1:4,'|',
	      datos[i][10]:7:4,'|',datos[i][11]:7:5,'|',
	      datos[i][12]:4:2,'|', datos[i][13]:6:2,'|',
	      datos[i][14]:7:3,'|',datos[i][15]:7:3,'|');
      if i<numinterv then
      begin
	 write(out,'+---+----------+-----+----------+----------+-----+---');
	 writeln(out,'-------+------+-------+-------+----+------+-------+-------+');
      end
      else
      begin
	 write(out,'+===+==========+=====+==========+==========+=====+==');
	 writeln(out,'========+======+=======+=======+====+======+=======+=======+');
      end;
   end;

   (*Escribe los totales al final de la tabla en el archivo de salida TXT*)
   writeln(out,'|   |   Total  |     | =',Datos[i+1][5]:8:0,
	   '|          |=',Datos[i+1][7]:4:0,'|          |      |=',
	   Datos[i+1][10]:6:2, '|       |',Datos[i+1][12]:4:1,
	   '|      |       |=',datos[i+1][15]:6:2,'|');
   writeln(out,'+===+==========+=====+==========+==========+=====+');
   writeln(out,'==========+======+=======+=======+====+======+=======+=======+');

   (*Escribe los calculos pedidos hacia el archivo de salida TXT*)
   for i:=1 to 7 do
   begin
      if calcular[i]=true then
      begin
	 case i of
	   1 : calcs:='Media Aritmetica: ';
	   2 : calcs:='Mediana : ';
	   3 : calcs:='Moda : ';
	   4 : calcs:='Media Geometrica : ';
	   5 : calcs:='Media Armonica : ';
	   6 : calcs:='Varianza : ';
	   7 : calcs:='Desviacion Estandar: ';
	 end; { case }
	 writeln(out,calcs,resultados[i]:8:5);
      end;
   end;
   close(out);
   writeln('Archivo ',ruta,' creado satisfactoriamente.');
   {-----\/----- EXCLUDED -----\/-----
   PARTE 2: Archivo HTML
   
   -----/\----- EXCLUDED -----/\-----}
   {filename:=copy(ruta,1,pos('.',ruta)-1);}
   ruta:=concat(filename,'.htm');
   assign(out,ruta);
   rewrite(out);
   
   textcolor(lightgreen);
   write('Creando Tabla en archivo ');
   textcolor(lightblue);
   write(ruta);
   textcolor(lightgreen);
   writeln('....');

   writeln(out,'<html> <head> <title> Statics : ');
   write(out,titulo);
   writeln(out,'</title></head>');
   writeln(out,'<body> <p align="center"><font size=4 color="#0000ff"><b>');
   write(out,titulo);
   writeln(out,'</b></font> </p> <table border=0 width=75% align=center>');
   writeln(out,'<tr align="center" bgcolor="#2299ff"><b>');
   write(out,'<td> No. </td>');
   write(out,'<td> Intervalo </td>');
   write(out,'<td> Punto Medio </td>');
   write(out,'<td> Frecuencia f. </td>');
   write(out,'<td> Desviacion v=PM-A. </td>');
   write(out,'<td> Total Desviacion f*v </td>');
   write(out,'<td> Frecuencia Acumulada </td>');
   write(out,'<td> Ln(pm) </td>');
   write(out,'<td> F * Ln(pm) </td>');
   write(out,'<td> Inverso 1/PM </td>');
   write(out,'<td> F*1/PM </td>');
   write(out,'<td> X=PM-Media Arit. </td>');
   write(out,'<td> f*x </td>');
   writeln(out,'<td> f*x^2 </td></b></tr>');
   for i:=1 to numinterv + 1 do
   begin
      if i <= numinterv then
      begin
	 if i mod 2 = 0 then
	    writeln(out,'<tr align="right">')
	 else
	    writeln(out,'<tr align="right" bgcolor="#bfbfbf">');
	 write(out,'<td>',datos[i][1]:6:0 ,'</td>');
	 write(out,'<td>',datos[i][2]:6:0 ,' a ', datos[i][3]:6:0,'</td>');
	 write(out,'<td>',datos[i][4]:6:4 ,'</td>');
	 write(out,'<td>',datos[i][5]:6:4 ,'</td>');
	 write(out,'<td>',datos[i][6]:6:4 ,'</td>');
	 write(out,'<td>',datos[i][7]:6:4 ,'</td>');
	 write(out,'<td>',datos[i][8]:6:4 ,'</td>');
	 write(out,'<td>',datos[i][9]:6:4 ,'</td>');
	 write(out,'<td>',datos[i][10]:6:4 ,'</td>');
	 write(out,'<td>',datos[i][11]:6:4 ,'</td>');
	 write(out,'<td>',datos[i][12]:6:4 ,'</td>');
	 write(out,'<td>',datos[i][13]:6:4 ,'</td>');
	 write(out,'<td>',datos[i][14]:6:4 ,'</td>');
	 write(out,'<td>',datos[i][15]:6:4 ,'</td>');
	 writeln(out,'</tr>');
      end
      else
      begin	 
	 writeln(out,'<tr align="right" bgcolor = "#dd0000">');
	 write(out,'<td></td>');
	 write(out,'<td> Total </td>');
	 write(out,'<td></td>');
	 write(out,'<td>',datos[i][5]:6:4 ,'</td>');
	 write(out,'<td></td>');
	 write(out,'<td>',datos[i][7]:6:4 ,'</td>');
	 write(out,'<td></td>');
	 write(out,'<td></td>');
	 write(out,'<td>',datos[i][10]:6:4 ,'</td>');
	 write(out,'<td></td>');
	 write(out,'<td>',datos[i][12]:6:4 ,'</td>');
	 write(out,'<td>',datos[i][13]:6:4 ,'</td>');
	 write(out,'<td></td>');
	 write(out,'<td>',datos[i][15]:6:4 ,'</td>');
	 writeln(out,'</tr>');
      end;
   end;
   writeln(out,'</table>');
   for i:=1 to 7 do
   begin
      if calcular[i]=true then
      begin
	 case i of
	   1 : calcs:='Media Aritmetica: ';
	   2 : calcs:='Mediana : ';
	   3 : calcs:='Moda : ';
	   4 : calcs:='Media Geometrica : ';
	   5 : calcs:='Media Armonica : ';
	   6 : calcs:='Varianza : ';
	   7 : calcs:='Desviacion Estandar: ';
	 end; { case }
	 writeln(out,'<b>',calcs,'</b>',resultados[i]:8:5,'<br>');
      end;
   end;
   writeln(out,'<p align="right"><i>Archivo creado por StaticS, (c) 2005 Erik Giron</i></p>');
   writeln(out,'</body></htm>');

   
   close(out);
   
   writeln('Archivo ',ruta,' creado satisfactoriamente.');
   (*Muestra en pantalla*)
   textcolor(yellow);
   writeln('Desea ver en pantalla?? [s:si][otra tecla:no]');
   readln(mostrar);
   textcolor(white);
   if mostrar='s' then
   begin
      ruta:=concat(filename,'.txt');
      MostrarStdout(ruta);
   end;
   salida:=true;
end;

(*
 * MostrarStdout
 *  Muestra el archivo de texto creado hacia la pantalla;
 *)
function MostrarStdout(ruta : string) : boolean;
const
   maxlin = 12;
var
   i,j	   : byte;
   entrada : text;
   linea   : string;
{   existe  : integer;}
begin
   assign(entrada,ruta);
   {$I-}
   reset(entrada);
   {existe:=IOresult;}
   {$I+}
   if IOresult<>0 then
   begin
      textcolor(red);
      writeln('Archivo no existe');
      textcolor(white);
      MostrarStdout := false;
   end
   else
   begin
      i:=1;
      j:=maxlin;
      while not eof(entrada) do
      begin {Arreglar}
	 textcolor(LightGreen);
	 readln(entrada,linea);
	 gotoxy(1,i);
	 writeln(copy(linea,1,76));
	 gotoxy(1,j);
	 writeln(copy(linea,77,255));
	 if (i=maxlin)then
	 begin
	    textcolor(yellow);
	    writeln('Presione cualquier tecla para continuar...');
	    readkey;
	    clrscr;
	    i:=1;
	    j:=maxlin;
	 end
	 else
	 begin
	    i:=i+1;
	    j:=j+1;
	 end;
      end;
      textcolor(white);
      close(entrada);
      MostrarStdout:=true;
   end;
end;

(*
 * Principal:
 *  Funcion principal que controla todas las funciones y procedimientos,
 *  administra las variables principales que se pasaran como parametro
 *  a las demas rutinas
 *)
function principal : boolean;
var
   path	      : string[max];
   TablaDatos : Tabla;
   Resultados : ReaData;
{   existe     : integer;}
begin
   repeat
      textcolor(yellow);
      writeln('Indique el archivo de entrada por favor:');
      textcolor(white);
      readln(path);
      while (inputfile(path) = false) do
      begin
	 clrscr;
	 textcolor(red);
	 Writeln('AVISO: Escriba Archivo de Entrada Correcto: ');
	 textcolor(white);
	 readln(path);
      end;
   until length(path)>0;
   frecuencia;
   DataGen(TablaDatos,Resultados);
   Salida(TablaDatos,Resultados);
   
   principal := true;

end; { principal }


(*
 * header:
 *  Muestra encabezado al inicio del programa
 *)
procedure header;
begin
   writeln('                Proyecto No. 1: STATICS');
   writeln('                =======================');
   writeln('       (STATistical Interactive Computarized Sheet)');
   writeln('            -Para ayuda ver Manual de Usuario-');
   writeln;
   writeln('Creado por: Erik Vladimir Giron Marquez');
   writeln('Carnet No. 200313492');
   writeln('Para el curso: Lenguajes Formales y de Programacion');
   writeln('Seccion A+');
   writeln('Segundo Semestre, 2005');
   writeln('Facultad de Ingenieria, USAC');
   writeln;
    
end;

(*
 *  MAIN
 *)
begin
   clrscr;
   header;
   if principal = true then
   begin
      textcolor(yellow);
      writeln('Presione cualquier tecla para salir');
      textcolor(white);
      readkey;
   end;
end.

