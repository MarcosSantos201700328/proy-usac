--FLUJO DE EJECUCION

@proy2_ddl.sql; --creacion
@carga.sql; --carga de datos
-- sin indces
@proy2-0_noidx.sql;
@proy2-selects.sql;
-- con BTREE
@proy2-1_btree.sql;
@proy2-selects.sql;
--... y asi sucesivamente