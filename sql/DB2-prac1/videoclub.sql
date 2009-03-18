-- Database: `videoclub`
-- 
create user webadmin identified by webadmin;
grant create session to webadmin identified by webadmin;
grant connect to webadmin;
grant resource to webadmin;
grant dba to webadmin;
grant create table to webadmin;
grant all to webadmin;
connect webadmin/webadmin;
-- --------------------------------------------------------

-- 
-- Table structure for table `alquiler`
-- 

CREATE TABLE alquiler (
  id_pelicula int NOT NULL,
  id_cliente int NOT NULL,
  fecha_alquiler DATE NOT NULL,
  fecha_dev_cresta DATE NOT NULL,
  fecha_dev_echo DATE default NULL,
  PRIMARY KEY  (id_pelicula,id_cliente,fecha_alquiler)--,
--  KEY id_cliente (id_cliente)
);

-- --------------------------------------------------------

-- 
-- Table structure for table `cliente`
-- 

CREATE TABLE  cliente  (
   id_cliente  int NOT NULL  ,
   nombre  varchar(50) NOT NULL,
   telefono  varchar(15) NOT NULL,
   direccion  varchar(50) NOT NULL,
   sexo  char(1) NOT NULL,
   fecha_afiliacion  DATE NOT NULL,
   fecha_nac  DATE NOT NULL,
  PRIMARY KEY  ( id_cliente )
)   ;

-- --------------------------------------------------------

-- 
-- Table structure for table `fecha`
-- 

CREATE TABLE  fecha  (
   id_tipo_pelicula  int NOT NULL,
   id_pelicula  int NOT NULL,
   fecha  DATE NOT NULL,
  PRIMARY KEY  ( id_tipo_pelicula , id_pelicula )
);

-- --------------------------------------------------------

-- 
-- Table structure for table `pelicula`
-- 

CREATE TABLE  pelicula  (
   id_pelicula  int NOT NULL  ,
   nombre  varchar(30) NOT NULL,
   fecha_estreno  DATE NOT NULL,
   descrip  varchar(1000) NOT NULL,
   clasif  char(1) NOT NULL,
   conocida_como  varchar(20) NOT NULL,
   num_ejemplares  int NOT NULL,
  PRIMARY KEY  ( id_pelicula )
)   ;

-- --------------------------------------------------------

-- 
-- Table structure for table `tipo_pelicula`
-- 

CREATE TABLE  tipo_pelicula  (
   id_tipo_pelicula  int NOT NULL,
   nombre  varchar(30) NOT NULL,
   precio  float NOT NULL,
  PRIMARY KEY  ( id_tipo_pelicula )
);

-- 
-- Constraints for dumped tables
-- 

-- 
-- Constraints for table `alquiler`
-- 
ALTER TABLE alquiler
  ADD CONSTRAINT  alquiler_ibfk_2  FOREIGN KEY ( id_cliente ) REFERENCES  cliente  ( id_cliente ) ON DELETE CASCADE;
ALTER TABLE alquiler
  ADD CONSTRAINT  alquiler_ibfk_1  FOREIGN KEY ( id_pelicula ) REFERENCES  pelicula  ( id_pelicula ) ON DELETE CASCADE;

-- 
-- Constraints for table `fecha`
-- 
ALTER TABLE fecha
  ADD CONSTRAINT  fecha_ibfk_2  FOREIGN KEY ( id_pelicula ) REFERENCES  pelicula  ( id_pelicula ) ON DELETE CASCADE;
ALTER TABLE fecha
  ADD CONSTRAINT  fecha_ibfk_1  FOREIGN KEY ( id_tipo_pelicula ) REFERENCES  tipo_pelicula  ( id_tipo_pelicula ) ON DELETE CASCADE;
