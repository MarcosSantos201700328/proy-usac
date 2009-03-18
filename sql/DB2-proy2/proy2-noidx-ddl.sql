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
