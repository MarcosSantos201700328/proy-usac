-- phpMyAdmin SQL Dump
-- version 2.8.1-Debian-1~dapper1
-- http://www.phpmyadmin.net
-- 
-- Servidor: localhost
-- Tiempo de generación: 02-10-2006 a las 18:33:03
-- Versión del servidor: 5.0.21
-- Versión de PHP: 5.1.2
-- 
-- Base de datos: `fscontent`
-- 

-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `bitmap`
-- 

CREATE TABLE `bitmap` (
  `ID` int(11) NOT NULL COMMENT 'ID de bitmap',
  `MAGIC` int(11) NOT NULL COMMENT 'Numero Magico',
  `DESCRIPCION` varchar(32) default NULL COMMENT 'descripcion de bitmap',
  `ID_SESION` int(11) NOT NULL COMMENT 'Grupo al que pertenece',
  `INICIO` int(11) NOT NULL COMMENT 'Inicio',
  `FIN` int(11) NOT NULL COMMENT 'Fin',
  `FIN_REAL` int(11) NOT NULL COMMENT 'Fin Real',
  `BITMAP` mediumblob NOT NULL COMMENT 'mapa de bit',
  `CODIGO_ERROR` int(11) default NULL COMMENT 'Codigo de Error',
  `TIPO` tinyint(1) NOT NULL COMMENT '1 si es mapa de inodos, 0 si es de bloques',
  PRIMARY KEY  (`ID`)
) TYPE=MyISAM COMMENT='Estructura de un mapa de bit' AUTO_INCREMENT=1 ;

-- 
-- Volcar la base de datos para la tabla `bitmap`
-- 


-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `descriptor`
-- 

CREATE TABLE `descriptor` (
  `ID` int(11) NOT NULL COMMENT 'Llave Primaria',
  `ID_SESION` int(11) NOT NULL COMMENT 'Llave Foranea',
  `NUM_GRUPO` int(11) NOT NULL COMMENT 'Numero de descriptor en la particion',
  `INICIO_BITMAP_INODO` int(11) NOT NULL COMMENT 'posicion respecto el bitmap del primer inodo',
  `INICIO_BITMAP_BLOQUE` int(11) NOT NULL COMMENT 'posicion respecto el bitmap del primer bloque',
  `TABLA_INODOS` int(11) NOT NULL COMMENT 'tabla inodos',
  `BLOQUES_LIBRES` int(11) NOT NULL COMMENT 'Numero de bloques libres en particion',
  `INODOS_LIBRES` int(11) NOT NULL COMMENT 'Numero de Inodos Libres',
  `DIR_USADOS` int(11) NOT NULL COMMENT 'Directorios utilizados',
  `RELLENO` int(11) NOT NULL COMMENT 'Valor de "Padding"',
  PRIMARY KEY  (`ID`)
) TYPE=MyISAM COMMENT='Estrucutra de un descriptor de Grupo' AUTO_INCREMENT=1 ;

-- 
-- Volcar la base de datos para la tabla `descriptor`
-- 


-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `inodo`
-- 

CREATE TABLE `inodo` (
  `ID` int(11) NOT NULL COMMENT 'Identificador del inodo',
  `NUM_INODO` int(11) NOT NULL COMMENT 'numero de inodo',
  `USUARIO` int(11) default NULL COMMENT 'UID',
  `MODO` int(11) default NULL COMMENT 'Modo del inodo',
  `TAM` int(11) default NULL COMMENT 'Tamano de inodo',
  `ACCESADO` int(11) default NULL COMMENT 'Fecha de accesso en formato UNIX',
  `CREADO` int(11) default NULL COMMENT 'Fecha de creacion en formato UNIX',
  `MODIFICADO` int(11) default NULL COMMENT 'Fecha de Modificacion en formato UNIX',
  `GRUPO` int(11) default NULL COMMENT 'Grupo de usuario',
  `NUM_ENLACES` int(11) default NULL COMMENT 'Numero de Hard Links',
  `NUM_BLOQUES` int(11) default NULL COMMENT 'Numero de bloques que ocupa el inode',
  `BANDERA` int(11) default NULL COMMENT 'bandera del inodo',
  `BORRADO` int(11) default NULL COMMENT 'Fecha de Borrado en formato UNIX',
  `NUM_GRUPO` int(11) NOT NULL COMMENT 'Descriptor de Grupo al que pertenece',
  `ID_SESION` int(11) NOT NULL COMMENT 'Sesion a la que pertenece el grupo',
  `ES_DIRECTORIO` tinyint(1) default NULL COMMENT 'el inodo pertenece a un directorio o no',
  `PATH` varchar(30) default NULL COMMENT 'path desde el dir raiz de la particiyn',
  PRIMARY KEY  (`ID`)
) TYPE=MyISAM AUTO_INCREMENT=1 ;

-- 
-- Volcar la base de datos para la tabla `inodo`
-- 


-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `particion`
-- 

CREATE TABLE `particion` (
  `SESSION_ID` int(11) NOT NULL COMMENT 'id de la particion',
  `DISPOSITIVO` varchar(15) NOT NULL COMMENT 'Ruta del Dispositivo',
  `BANDERAS` int(11) NOT NULL COMMENT 'Banderas del dispositivo',
  `TAM_BLOQUE` int(11) NOT NULL COMMENT 'Tamano bloque',
  `TAM_FRAGMENTO` int(11) NOT NULL COMMENT 'Tamano de Fragmento',
  `NUM_DESCRIPTORES` int(11) NOT NULL COMMENT 'Numero de Descriptores',
  `BLOQUES_DESC` int(11) default NULL COMMENT 'Bloques por descriptor',
  `INODOS_POR_GRUPO` int(11) default NULL COMMENT 'Numero de bloques de inodos por grupo',
  PRIMARY KEY  (`SESSION_ID`)
) TYPE=MyISAM COMMENT='Informacion general de particion, tomando como llave el disp';

-- 
-- Volcar la base de datos para la tabla `particion`
-- 


-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `sesion`
-- 

CREATE TABLE `sesion` (
  `ID` int(11) NOT NULL COMMENT 'id de sesion',
  `PARTICION` varchar(15) NOT NULL COMMENT 'Particion utilizada',
  `TIEMPO_ANALISIS` int(11) NOT NULL COMMENT 'Tiempo de Recorrido',
  `NUM_ELEMENTOS` int(11) NOT NULL default '0' COMMENT 'Total elementos encontrados en sesion',
  `NUM_INSERCIONES` int(11) NOT NULL COMMENT 'Numero de Inserciones en la sesion',
  PRIMARY KEY  (`ID`)
) TYPE=MyISAM;

-- 
-- Volcar la base de datos para la tabla `sesion`
-- 


-- --------------------------------------------------------

-- 
-- Estructura de tabla para la tabla `superbloque`
-- 

CREATE TABLE `superbloque` (
  `ID` int(11) NOT NULL COMMENT 'Llave Primaria',
  `NUM_INODOS` int(11) NOT NULL COMMENT 'Total inodos en superbloque',
  `NUM_BLOQUES` int(11) NOT NULL COMMENT 'total bloques en superbloque',
  `NUM_BLOQUES_RES` int(11) NOT NULL COMMENT 'numerobloques reservados',
  `NUM_BLOQUES_LIBRES` int(11) NOT NULL COMMENT 'numero bloques libres',
  `NUM_INODOS_LIBRES` int(11) NOT NULL COMMENT 'numero inodos libres',
  `PRIMER_BLOQUE_DATOS` int(11) NOT NULL COMMENT 'puntero al primer bloque de datos',
  `TAM_BLOQUES` int(11) NOT NULL COMMENT 'Tamano de bloques',
  `TAM_FRAGMENTO` int(11) NOT NULL COMMENT 'tamano de fragmentos',
  `BLOQUES_POR_GRUPO` int(11) NOT NULL COMMENT 'bloques por grupo',
  `FRAGMENTOS_POR_GRUPO` int(11) NOT NULL COMMENT 'fragmentos por grupo',
  `INODOS_POR_GRUPO` int(11) NOT NULL COMMENT 'inodos por grupo',
  `MONTADO_EL` int(11) default NULL COMMENT 'hORA DE MONTADO en formato UNIX',
  `ESCRITO_EL` int(11) default NULL COMMENT 'HORA DE ESCRITO en formato UNIX',
  `VECES_MONTADO` int(11) NOT NULL COMMENT 'veces que ha sido montado',
  `MAX_VECES_MONTADO` int(11) NOT NULL COMMENT 'Maximo de veces montado',
  `MAGIC` int(11) NOT NULL COMMENT 'Nuemro mgico',
  `ESTADO` int(11) default NULL COMMENT 'bandera de estado',
  `COMPORT_ERROR` int(11) default NULL COMMENT 'comportamiento ante errores',
  `REVISION_MENOR` int(11) default NULL COMMENT 'Cifra menor de Revision',
  `ULTIMO_FSCK` int(11) default NULL COMMENT 'Ultima fecha de chequeo del sistema de archivos en formato UNIX',
  `INTERVALO_FSCK` int(11) default NULL COMMENT 'Intervalo de cheque del sistema de archivos del sistema de archivos',
  `SISTEMA_OPERATIVO` int(11) NOT NULL COMMENT 'Sistema operativo donde se creo el sistema de archivos',
  `REVISION` int(11) NOT NULL COMMENT 'revision',
  `USUARIO_BLOQUES_RES` int(11) NOT NULL COMMENT 'UID predeterminado de los bloques reservados',
  `GRUPO_BLOQUES_RES` int(11) NOT NULL COMMENT 'GID predeterminado de los bloques reservados',
  `DIR_MONTAJE` varchar(30) NOT NULL COMMENT 'DIRECTORIO DE MONTAJE',
  `SESSION_ID` int(11) NOT NULL COMMENT 'Llave Foranea',
  PRIMARY KEY  (`ID`)
) TYPE=MyISAM COMMENT='Estructura de un supergrupo' AUTO_INCREMENT=1 ;

-- 
-- Volcar la base de datos para la tabla `superbloque`
-- 

