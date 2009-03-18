LOAD DATA
INFILE 'h:\detalle.txt'
APPEND
CONTINUEIF THIS (1) = '*'
INTO TABLE detalle 
--OPTIONALLY ENCLOSED BY '"'
(
codigo position(1:10) integer external,
operacion position(11:21) char "trim(:operacion)",
nombre position(22:48) char "trim(:nombre)",
fecha position(49:58) date "DD-MM-YY", --"trim(:fecha)",
tipo position(59:60) char "TRIM(:tipo)",
transaccion  position(61:72) char "trim(:transaccion)",
clave1 position(73:102) char "trim(:clave1)",
clave2 position(104:134) char "trim(:clave2)",
maestro position(135:143) integer external "trim(:maestro)",
municipio position(175:178) integer external "trim(:municipio)"
)
