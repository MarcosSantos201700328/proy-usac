LOAD DATA
INFILE 'c:\municipios.txt'
DISCARDMAX 999
append
CONTINUEIF THIS (1) = '*'
INTO TABLE municipio 
FIELDS TERMINATED BY ','
OPTIONALLY ENCLOSED BY '"'
(
codigo    INTEGER EXTERNAL "trim(:codigo)",
departamento   CHAR "trim(:departamento)",
nombre CHAR "trim(:nombre)",
tipo INTEGER EXTERNAL "trim(:tipo)"
--codigo_depto INTEGER EXTERNAL
)