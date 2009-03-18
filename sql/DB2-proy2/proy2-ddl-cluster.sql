drop table detalle cascade constraint;

drop table municipio cascade constraint;
drop table depto cascade constraint;
drop table maestro cascade constraint;

drop cluster ma_det;
drop cluster dep_muni;

drop index idx1;
drop index idx2;

create cluster dep_muni (id_dep int);
create cluster ma_det (id_muni int);

create table maestro (
	codigo int primary key,
	transaccion int,
	nombre varchar2(32),
	valor varchar(10),
	tipo char(1),
	valor_anterior varchar(10),	
	clave1 varchar2(32),
	clave2 varchar2(32)
)
ORGANIZATION INDEX;

--tabla departamento

create table depto (
	codigo int primary key,
	nombre varchar2(64),	
	tipo int	
)
--CLUSTER dep_muni (codigo);

--tabla municipio
create table municipio (
	codigo int primary key,
	departamento varchar2(50),
	nombre varchar2(64),
	tipo int,
	codigo_depto int	
)
--CLUSTER dep_muni (codigo_depto),
CLUSTER ma_det (codigo);

--tabla detalle
create table detalle (
	codigo int primary key,
	operacion varchar2(32),
	nombre varchar2(64),
	fecha date,
	tipo char(1),
	transaccion varchar2(32),
	clave1 varchar2(32),
	clave2 varchar2(32),
	maestro int,
	municipio int
)
CLUSTER ma_det (municipio);

CREATE INDEX idx1 ON CLUSTER dep_muni;
CREATE INDEX idx2 ON CLUSTER ma_det;

alter table municipio add constraint municipio_fk
foreign key (codigo_depto) references depto (codigo) 
on delete cascade;

alter table detalle add constraint det_fk_1
foreign key (municipio) references municipio (codigo) 
on delete cascade;	

commit;