LOAD DATA
INFILE 'H:\maestro.txt'
replace
CONTINUEIF THIS (1) = '*'
INTO TABLE maestro
--OPTIONALLY ENCLOSED BY '"'
(
codigo position(1:11) integer external "trim(:codigo)",
transaccion position(12:21) char "trim(:transaccion)",
nombre position(22:49) char "trim(:nombre)",
valor position(50:52) integer external "trim(:valor)",
tipo position(53:54) char "trim(:tipo)",
valor_anterior position(55:57) integer external "trim(:valor_anterior)",
clave1 position(58:75) char "trim(:clave1)",
clave2 position(89:112) char "trim(:clave2)"
)