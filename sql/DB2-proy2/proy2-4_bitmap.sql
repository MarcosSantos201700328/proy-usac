--- indices
drop index idx_1;
drop index idx_2;
drop index idx_3;
drop index idx_4;
drop index idx_5;
drop index idx_6;
drop index idx_7;
drop index idx_8;
drop index idx_9;
drop index idx_10;
drop index idx_11;
drop index idx_12;
CREATE BITMAP INDEX idx_1
ON maestro (transaccion)
PCTFREE 0;

CREATE BITMAP INDEX idx_2
ON maestro (nombre)
PCTFREE 0;

CREATE BITMAP INDEX idx_3
ON maestro (tipo)
PCTFREE 0;

CREATE BITMAP INDEX idx_4
ON detalle (operacion)
PCTFREE 0;

CREATE BITMAP INDEX idx_5
ON detalle (nombre)
PCTFREE 0;

CREATE BITMAP INDEX idx_6
ON detalle (fecha)
PCTFREE 0;

CREATE BITMAP INDEX idx_7
ON detalle (tipo)
PCTFREE 0;

CREATE BITMAP INDEX idx_8
ON depto (nombre)
PCTFREE 0;

CREATE BITMAP INDEX idx_9
ON depto (tipo)
PCTFREE 0;

CREATE BITMAP INDEX idx_10
ON municipio (departamento)
PCTFREE 0;

CREATE BITMAP INDEX idx_11
ON municipio (nombre)
PCTFREE 0;

CREATE BITMAP INDEX idx_12
ON municipio (tipo)
PCTFREE 0;

commit;