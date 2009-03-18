
--- QUERIES ---
set timing on
-- 1 --
select count(*) from maestro;	
select count(*) from detalle;
select count(*)  from depto;
select count(*) from municipio;
-- 2 --
select * from maestro where upper(nombre) = '';	
select * from detalle where upper(nombre) = 'NUMERO';
select * from depto where upper(nombre) = 'RETALHULEU';
select * from municipio where upper(nombre) = 'RETALHULEU';
--3--
select * from maestro where nombre like '%NUMERO%';	
select count(*) from detalle where nombre like '%ERRORES_DE%';
select * from depto where nombre like '%10%';
select * from municipio where upper(nombre) like '%10%';
--4--
select distinct tipo from maestro;
select distinct tipo from detalle;
--5--
select distinct tipo from maestro where tipo in ('D','I','1','V');
select distinct tipo from detalle where tipo in ('D','I','1','V');
--6--
select count(*) from maestro ma, detalle de, municipio mu where ma.codigo = de.maestro and de.municipio = mu.codigo and ma.tipo in ('D','I','1','V','N') and de.fecha > '01-jan-2000';
--7--
select count(*) from depto d, municipio m where m.codigo in (select municipio from detalle);
--8--
select count(*) from detalle where  tipo in ('D','I','1','U','N');
--9--
select * from maestro where transaccion = 236515870;
--10--
select * from maestro where nombre like '%NUMERO%';
--11--
select count(*) from maestro where tipo = 'D';
--12--
select * from detalle where transaccion = '204929274';
--13--
select count(*) from detalle where nombre = 'ERRORES';
--14--
select count(*) from detalle where fecha = '13-jun-06';
--15--
select count(*) from detalle where tipo = 'U';
--16--
select * from detalle where operacion = '203087682';
--17--
--select count(*) from maestro m ,detalle d where m.codigo > 0; -- no sale
--18--
select * from municipio where departamento = 'Retalhuleu';
--19--
select * from municipio where nombre = 'El Asintal';
--20--
select * from municipio where tipo = '1';