-- tabla maestro
create table maestro (
	codigo int primary key,
	transaccion varchar2(20),
	nombre varchar2(20),
	valor int,
	tipo char(1),
	valor_anterior int,	
	clave1 varchar2(20),
	clave2 varchar2(20)
);

--tabla departamento

create table depto (
	codigo int primary key,
	departamento varchar(50),	
	area int	
);

--tabla municipio
create table municipio (
	codigo int primary key,
	departamento varchar(50),
	municipio varchar(50),
	rango int,
	codigo_depto int	
);

--tabla detalle
create table detalle (
	codigo int primary key,
	operacion varchar2(20),
	nombre varchar2(50),
	fecha date,
	tipo char(1),
	transaccion varchar2(20),
	clave1 varchar2(20),
	clave2 varchar2(20),
	maestro int,
	municipio int
);

--alter table municipio add constraint municipio_fk
--foreign key (codigo_depto) references depto (codigo) 
--on delete cascade;

--alter table detalle add constraint det_fk_1
--foreign key (municipio) references municipio (codigo) 
--on delete cascade;	


---Carga de datos

--- QUERIES ---
set timing on
-- 1 --
select * from maestro;	
select * from detalle;
select * from depto;
select * from municipio;
-- 2 --
select * from maestro where upper(nombre) = '';	
select * from detalle where upper(nombre) = 'NUMERO';
select * from depto where upper(departamento) = 'RETALHULEU';
select * from municipio where upper(municipio) = 'RETALHULEU';
--3--
select * from maestro where nombre like '%NUMERO%';	
select * from detalle where nombre like '%ERRORES_DE%';
select * from depto where departamento like '%10%';
select * from municipio where upper(municipio) like '%10%';
--4--
select distinct tipo from maestro;
select distinct tipo from detalle;
--5--
select distinct tipo from maestro where tipo in ('D','I','1','V');
select distinct tipo from detalle where tipo in ('D','I','1','V');
--6--
select * from maestro ma, detalle de, municipio mu where ma.codigo = de.maestro and de.municipio = mu.codigo and ma.tipo in ('D','I','1','V','N') and de.fecha > '01-jan-2000';
--7--
select * from depto d, municipio m where m.codigo in (select municipio from detalle);
--8--
select count(*) from detalle where  tipo in ('D','I','1','U','N');
--9--
select * from maestro where transaccion = 236515870;
--10--
select * from maestro where nombre like '%NUMERO%';
--11--
select * from maestro where tipo = 'D';
--12--
select * from detalle where transaccion = '204929274';
--13--
select * from detalle where nombre = 'ERRORES';
--14--
select * from detalle where fecha = '13/06/06';
--15--
select * from detalle where tipo = 'U';
--16--
select * from detalle where operacion = '203087682';
--17--
select * from maestro m ,detalle d where m.codigo > 0;
--18--
select * from municipio where departamento = 'RETALHULEU';
--19--
select * from municipio where municipio = 'EL ASINTAL';
--20--
select * from municipio where rango = '1';