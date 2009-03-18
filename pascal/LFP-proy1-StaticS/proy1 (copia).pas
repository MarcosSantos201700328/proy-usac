program static;
uses crt, math;
const
   max = 255; (* Maximo numero de valores *)
type
   ArrData = array [1..max] of integer;
   Matdata = array [1..max] of Arrdata;
var
   titulo    : string[255];
   entrada   : Text; (*archivo de entrada*)
   intervalo : MatData;(* intervalos *)
   frec,x,PM : ArrData; (* datos importantes *)
   path	     : string[255];


(*
 *  parse:
 *  analiza lexicograficamente la linea y genera
 *  instrucciones conforme comando leido
 *)
procedure parse(linea : string; numlinea : integer);
begin
{   writeln(numlinea,') ',linea);}

end; { parse }



(*
 *  inputfile:
 *  lee archivo de entrada y guarda linea por linea a un string
 *)
procedure inputfile(path : string);
var
   linea   : string; {linea leida}
   i	   : integer; {numero de linea}
   code	   : word;
   fase	   : char; {bandera para indicar fase}
   comando : string;
   IntTst  : integer;
begin
   i := 1;
   fase := '0';
   assign(entrada,path);
   reset(entrada);
   while not eof(entrada) do
   begin
      readln(entrada,linea);  {lee linea}
      comando := copy(upcase(linea),1,6); {genera comando}
      {debug}      writeln(comando); 
      val(copy(linea,1,2),IntTst,code); {convierte 1er caracter a numero}
      (* cambia bandera conforme comando dado*)
      if comando = 'TITULO' then
      begin
	 titulo := copy(linea,8,255);
	 writeln('titulo:',titulo);
      end;
      if comando = 'INTERV' then
	 fase := 'i';
      if comando = 'DATOS' then
	 fase := 'd';
      if comando = 'CALCUL' then
	 fase := 'c';
      (*Acciones para cuando se encuentra valor numerico*)
      if code = 0 then
      begin
	 case fase of
	   'i' : 
	 begin
	 end;
	   'd' : 
	 begin
	 end;
	 end; { case }
      end
      else (*acciones si no es valor numerico leido y fase es de calculo*)
	 if fase = 'c' then
	 begin
	 end;
      {parse(linea,i);}
      i := i + 1;
   end;
   close(entrada);
end; { inputfile }


begin
   repeat
      writeln('Archivo de entrada:');
      readln(path);
      inputfile(path);
   until length(path)>0;
end.
