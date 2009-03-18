program outtst;
uses crt;
var
   out : text;


begin
   assign(out,'out.txt');
   rewrite(out);
   writeln(out,'+___+__________+_____+__________+__________+_____+__________+______+_______+_______+____+____+_____+_______+');
   writeln(out,'|   |          |     |          |          |Total|          |      |       |       |    | X= |     |       |');
   writeln(out,'|No.|Intervalo |Punto|Frecuencia|Desviacion|Desv.|Frecuencia| Log  |  f*   |Inverso| f* |PM- | f*x | f*x^2 |');
   writeln(out,'|   |          |Medio|    f     | v=PM-A   |f*v  |Acumulada | (PM) |Log(PM)| 1/PM  |1/PM| MAR|     |       |');
   writeln(out,'+===+==========+=====+==========+==========+=====+==========+======+=======+=======+====+====+=====+=======+');
   close(out);
end.
