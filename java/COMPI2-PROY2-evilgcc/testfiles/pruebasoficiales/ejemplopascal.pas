program k;
uses
 crt;
var
 suma,resta,multiplicacion:integer;
 division:real;
 numero1,numero2:integer;
procedure leer(var num1,num2:integer);
 begin
  write('Numero 1: ');readln(num1);
  write('Numero 2: ');readln(num2);
 end;

procedure operar(var s,r,m,d:real);
 begin
  s:=numero1+numero2;
  r:=numero1-numero2;
   if numero2=0 then
     d:=0
   else
     d:=numero1/numero2;
  m:=numero1*numero2;
 end;
begin
 (*ClrScr;*)
 leer(numero1,numero2);
 operar(suma,resta,multiplicacion,division);

 write('Suma: ',suma);
 write('Resta: ',resta);
 write('Multiplicacion: ',multiplicacion);
 write('Division: ',division);

 (*ReadKey;*)
end.