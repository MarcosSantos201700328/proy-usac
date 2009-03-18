/**CONSULTA 16*/
/*
Dar el nombre de los estudiantes, su ingreso en numeros y letras para todos los estudiatnes que tienen un ingreso familar mayor a 10000.

Obtenemos el ingreso de los estudiantes en letras y numeros usando un Stored Procedure que convierte de numeros a letras.

*/
SELECT CARNET,CONCAT(PRIMER_NOMBRE,' ')||PRIMER_APELLIDO,INGRESO_FAMILIAR,NUMALET(INGRESO_FAMILIAR)
FROM ESTUDIANTE
WHERE INGRESO_FAMILIAR >= 10000
;


