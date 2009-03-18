
-->---------------------------------------------<--
--+ ERIK VLADIMIR GIRON MARQUEZ			+--
--+ CARNET NO. 200313492			+--
--+ PRACTICA 1 SISTEMAS DE BASES DE DATOS 2	+--
--+ BASE DE DATOS WALMART			+--
--+ GUATEMALA, 04-FEB-2008			+--
-->---------------------------------------------<--
create tablespace walmart datafile 'E:\oraclexe\oradata\XE\walmart01.dbf' size 50M;

commit;

drop table Familia cascade constraint;
drop table Tienda cascade constraint;
drop table articulo cascade constraint;
drop table clase cascade constraint;
drop table departamento cascade constraint;
drop table inventario cascade constraint;
drop table seccion cascade constraint;
drop table tienda_departamento cascade constraint;
drop table tienda_seccion cascade constraint;


commit;


-- creacion de usuario y asignacion de tablespace
create user wmadmin identified by wmadmin default tablespace walmart;
alter user wmadmin quota 50M on walmart;
grant create session to wmadmin identified by wmadmin;
grant connect to wmadmin;
grant resource to wmadmin;
grant dba to wmadmin;
grant create table to wmadmin;
grant all to wmadmin;

-- Conexion de usuario
connect wmadmin/wmadmin;

--creacion de tablas
create table pruebaa (
  pruebaa number(5) primary key, 
  dt varchar2(16)) 
tablespace walmart;

--crear tablas y adjuntarle el tablespace


--S 'Familia';
CREATE TABLE  Familia (
  id_familia int NOT NULL,
  nombre VARCHAR2(20) NOT NULL,
  id_departamento int NOT NULL,
  PRIMARY KEY  (id_familia)
)
tablespace walmart;

commit;
-- --------------------------------------------------------


--S 'Tienda';
CREATE TABLE   Tienda  (
   id_tienda  NUMBER NOT NULL,
   nombre  VARCHAR2(20) NOT NULL,
   direccion  VARCHAR2(40) NOT NULL,
   gerente  VARCHAR2(20) NOT NULL,
  PRIMARY KEY  ( id_tienda )
)
tablespace walmart;

commit;
-- --------------------------------------------------------

--S 'articulo';
CREATE TABLE   articulo  (
   id_articulo  NUMBER NOT NULL,
   descripcion  VARCHAR2(50) NOT NULL,
   id_clase  NUMBER NOT NULL,
   codigo_barras  NUMBER NOT NULL,
  PRIMARY KEY  ( id_articulo ) 
)
tablespace walmart;
commit;
-- --------------------------------------------------------

--S 'clase';
CREATE TABLE   clase  (
   id_clase  NUMBER NOT NULL,
   nombre  VARCHAR2(20) NOT NULL,
   id_familia  NUMBER NOT NULL,
  PRIMARY KEY  ( id_clase )
)
tablespace walmart;

-- --------------------------------------------------------

--S 'departamento';
CREATE TABLE   departamento  (
   id_departamento  NUMBER NOT NULL,
   id_seccion  NUMBER NOT NULL,
   nombre  VARCHAR2(20) NOT NULL,
  PRIMARY KEY  ( id_departamento )
)
tablespace walmart;

-- --------------------------------------------------------


--S 'inventario';
CREATE TABLE   inventario  (
   id_tienda  NUMBER NOT NULL,
   id_articulo  NUMBER NOT NULL,
   existencia  NUMBER NOT NULL,
   precio  float NOT NULL,
   costo  float NOT NULL,
   venta  float NOT NULL,
   num_ventas  NUMBER NOT NULL
)
tablespace walmart;

-- --------------------------------------------------------

--S 'seccion';
CREATE TABLE   seccion  (
   id_seccion  NUMBER NOT NULL,
   nombre  VARCHAR2(20) NOT NULL,
  PRIMARY KEY  ( id_seccion )
)
tablespace walmart;

-- --------------------------------------------------------

--S 'tienda-departamento';
CREATE TABLE   tienda_departamento  (
   id_tienda  NUMBER NOT NULL,
   id_departamento  NUMBER NOT NULL,
   Encargado  VARCHAR2(20) NOT NULL,
   total_empleados  NUMBER NOT NULL,
   area  NUMBER NOT NULL,
  PRIMARY KEY  ( id_tienda , id_departamento )
)
tablespace walmart;

-- --------------------------------------------------------



--S 'tienda-seccion';
CREATE TABLE   tienda_seccion  (
   id_tienda  NUMBER NOT NULL,
   id_seccion  NUMBER NOT NULL,
  PRIMARY KEY  ( id_seccion )
)
tablespace walmart;


-- 
-- 'Familia'
-- 
ALTER TABLE Familia ADD CONSTRAINT  Familia_ibfk_1  FOREIGN KEY ( id_departamento ) REFERENCES  departamento  ( id_departamento ) ON DELETE CASCADE;

-- 
-- 'articulo'
-- 
ALTER TABLE articulo
  ADD CONSTRAINT  articulo_ibfk_1  FOREIGN KEY ( id_clase ) REFERENCES  clase  ( id_clase ) ON DELETE CASCADE;

-- 
-- 'clase'
-- 
ALTER TABLE clase
  ADD CONSTRAINT  clase_ibfk_1  FOREIGN KEY ( id_familia ) REFERENCES  Familia  ( id_familia ) ON DELETE CASCADE;

-- 
-- 'departamento'
-- 
ALTER TABLE departamento
  ADD CONSTRAINT  departamento_ibfk_1  FOREIGN KEY ( id_seccion ) REFERENCES  seccion  ( id_seccion ) ON DELETE CASCADE;

-- 
--  'inventario'
-- 
ALTER TABLE inventario
  ADD CONSTRAINT  inventario_ibfk_2  FOREIGN KEY ( id_articulo ) REFERENCES  articulo  ( id_articulo ) ON DELETE CASCADE;

ALTER TABLE inventario
  ADD CONSTRAINT  inventario_ibfk_1  FOREIGN KEY ( id_tienda ) REFERENCES  Tienda  ( id_tienda ) ON DELETE CASCADE ;

-- 
-- 'tienda-departamento'
-- 
ALTER TABLE tienda_departamento
  ADD CONSTRAINT  tienda_departamento_ibfk_2  FOREIGN KEY ( id_departamento ) REFERENCES  Tienda  ( id_tienda ) ON DELETE CASCADE;

ALTER TABLE tienda_departamento
  ADD CONSTRAINT  tienda_departamento_ibfk_1  FOREIGN KEY ( id_tienda ) REFERENCES  Tienda  ( id_tienda ) ON DELETE CASCADE;

-- 
-- 'tienda-seccion'
-- 
ALTER TABLE tienda_seccion
  ADD CONSTRAINT  tienda_seccion_ibfk_2  FOREIGN KEY ( id_seccion ) REFERENCES  seccion  ( id_seccion ) ON DELETE CASCADE;
ALTER TABLE tienda_seccion
  ADD CONSTRAINT  tienda_seccion_ibfk_1  FOREIGN KEY ( id_tienda ) REFERENCES  Tienda  ( id_tienda ) ON DELETE CASCADE;

commit;



