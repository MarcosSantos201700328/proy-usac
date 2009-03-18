/**Function NumALet, Convierte valores monetarios de numeros a letras*/

CREATE OR REPLACE FUNCTION NUMALET(NUMERO in number) RETURN VARCHAR2 IS
centimos 		varchar2(2);
millares 		varchar2(3);
unimills 		varchar2(3);
unimilos 		varchar2(3);
unibilos 		varchar2(3);
numeroch 		varchar2(100);
resultado 	varchar2(1800);
resultado1 	varchar2(200);

function unidades(uni in varchar2) return varchar2 is
begin 
if uni='1'    then return('un');
elsif uni='2' then return('dos');
elsif uni='3' then return('tres');
elsif uni='4' then return('cuatro');
elsif uni='5' then return('cinco');
elsif uni='6' then return('seis');
elsif uni='7' then return('siete');
elsif uni='8' then return('ocho');
elsif uni='9' then return('nueve');
else  		         return null;	
end if;
end;


function decenas(dece in varchar2) return varchar2 is
begin
if substr(dece,1,1)='1' then
	if dece='10'    then  return('diez');
	elsif dece='11' then 	return('once');
	elsif dece='12' then  return('doce');
	elsif dece='13' then  return('trece');
	elsif dece='14' then  return('catorce');
	elsif dece='15' then  return('quince');
	elsif dece='16' then  return('dieciseis');
	elsif dece='17' then  return('diecisiete');
	elsif dece='18' then  return('dieciocho');
	elsif dece='19' then  return('diecinueve');
	else		              return null;	
	end if;
	
elsif substr(dece,1,1)='2' then
	if dece='20' then
		return('veinte');
	else
		return('veinti'||unidades(substr(dece,2,1)));	
	end if;
elsif substr(dece,1,1)='3' then
	if dece='30' then
		return('treinta');
	else
		return('treinta y '||unidades(substr(dece,2,1)));	
	end if;
elsif substr(dece,1,1)='4' then
	if dece='40' then
		return('cuarenta');
	else
		return('cuarenta y '||unidades(substr(dece,2,1)));	
	end if;
elsif substr(dece,1,1)='5' then
	if dece='50' then
		return('cincuenta');
	else
		return('cincuenta y '||unidades(substr(dece,2,1)));	
	end if;
elsif substr(dece,1,1)='6' then
	if dece='60' then
		return('sesenta');
	else
		return('sesenta y '||unidades(substr(dece,2,1)));	
	end if;
elsif substr(dece,1,1)='7' then
	if dece='70' then
		return('setenta');
	else
		return('setenta y '||unidades(substr(dece,2,1)));	
	end if;
elsif substr(dece,1,1)='8' then
	if dece='80' then
		return('ochenta');
	else
		return('ochenta y '||unidades(substr(dece,2,1)));	
	end if;
elsif substr(dece,1,1)='9' then
	if dece='90' then
		return('noventa');
	else
		return('noventa y '||unidades(substr(dece,2,1)));	
	end if;
else
		return unidades(substr(dece,2,1));	
end if;

end;


function centenas(cent in varchar2) return varchar2 is
begin 

if substr(cent,1,1)='1' then
	if cent='100' then
		return('cien');
	else
		return('ciento '||decenas(substr(cent,2,2)));	
	end if;
elsif substr(cent,1,1)='2' then
	if cent='200' then
		return('dos cientos');
	else
		return('dos cientos '||decenas(substr(cent,2,2)));	
	end if;
elsif substr(cent,1,1)='3' then
	if cent='300' then
		return('trescientos');
	else
		return('trescientos '||decenas(substr(cent,2,2)));	
	end if;
elsif substr(cent,1,1)='4' then
	if cent='400' then
		return('cuatrocientos');
	else
		return('cuatrocientos '||decenas(substr(cent,2,2)));	
	end if;
elsif substr(cent,1,1)='5' then
	if cent='500' then
		return('quinientos');
	else
		return('quinientos '||decenas(substr(cent,2,2)));	
	end if;
elsif substr(cent,1,1)='6' then
	if cent='600' then
		return('seiscientos');
	else
		return('seiscientos '||decenas(substr(cent,2,2)));	
	end if;
elsif substr(cent,1,1)='7' then
	if cent='700' then
		return('setecientos');
	else
		return('setecientos '||decenas(substr(cent,2,2)));	
	end if;
elsif substr(cent,1,1)='8' then
	if cent='800' then
		return('ochocientos');
	else
		return('ochocientos '||decenas(substr(cent,2,2)));	
	end if;
elsif substr(cent,1,1)='9' then
	if cent='900' then
		return('novecientos');
	else
		return('novecientos '||decenas(substr(cent,2,2)));	
	end if;
else
		return decenas(substr(cent,2,2));
end if;
end;


BEGIN
numeroch:=to_char(numero,'999999999999999D00');
numeroch:=lpad(ltrim(numeroch),20,'0');
centimos:=substr(numeroch,instr(numeroch,',')+1,2);
millares:=substr(numeroch,instr(numeroch,',')-3,3);
unimills:=substr(numeroch,instr(numeroch,',')-6,3);
unimilos:=substr(numeroch,instr(numeroch,',')-9,3);
unibilos:=substr(numeroch,instr(numeroch,',')-12,3);
resultado:=null;
resultado1:=null;

if decenas(centimos) is not null then --los centimos
	if decenas(centimos)='uno' then
		resultado1:=decenas(centimos)||' centimo';
	else
		resultado1:=decenas(centimos)||' centimos';
	end if;
end if;

if centenas(millares) is not null then
	if resultado is not null then 
		resultado:='y '||resultado;
	end if;
	if centenas(millares)='uno' then
		resultado:=centenas(millares)||' '||resultado;
	else
		resultado:=centenas(millares)||' '||resultado;
	end if;
end if;

if centenas(unimills) is not null then
	if resultado is not null then 
		resultado:=' '||resultado;
	end if;
	if centenas(unimills)='un' then
		resultado:='mil '||resultado;
	else
		resultado:=centenas(unimills)||' mil '||resultado;
  end if;
end if;

if centenas(unimilos) is not null then
	if resultado is not null then 
		resultado:=' '||resultado;
	end if;
	if centenas(unimilos)='un' then
		resultado:=centenas(unimilos)||' millon '||resultado;
	else
		resultado:=centenas(unimilos)||' millones '||resultado;
	end if;
end if;
if centenas(unibilos) is not null then
	if resultado is not null then 
		resultado:=' '||resultado;
	end if;
	if centenas(unibilos)='un' then
		resultado:=centenas(unibilos)||' billon '||resultado;
	else
		resultado:=centenas(unibilos)||' billones '||resultado;
	end if;
end if;

if resultado is not null then
   if resultado1 is not null then
      resultado1:='con '||resultado1;
   end if;
   if substr(resultado,length(resultado)-5,6)='lones' or substr(resultado,length(resultado)-5,6)='illon' then
      resultado:=resultado||'de QUETZALES '||resultado1;
   else
       if resultado='un' then
        		resultado:=resultado||'QUETZAL ';
       else
	        	resultado:=resultado||'QUETZALES ';
	     end if;
   end if;
END if;
resultado:=resultado||resultado1;

return(NLS_UPPER(substr(resultado,1,1))||substr(resultado,2));

	
  
END;
/
