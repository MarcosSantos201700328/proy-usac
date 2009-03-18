/**CONSULTA 10*/
/*
Dar el nombre de las parejas de hermanos gemelos que estan estudiando en este semestre en alguna clase comun.

Obtenemos los datos de una pareja de estudiantes tal que concuerden sus apelllidos y su fecha de nacimiento y que exista alguna asignacion que hayan llevado juntos.
*/
SELECT E1.PRIMER_NOMBRE||' Y '||E2.PRIMER_NOMBRE||' '||E1.PRIMER_APELLIDO
FROM ESTUDIANTE E1,ESTUDIANTE E2
WHERE E1.PRIMER_APELLIDO = E2.PRIMER_APELLIDO
AND E1.SEGUNDO_APELLIDO = E2.SEGUNDO_APELLIDO
AND E1.FECHA_NACIMIENTO = E2.FECHA_NACIMIENTO
AND E1.CARNET > E2.CARNET
AND  EXISTS(
	SELECT 1
	FROM ASIGNACION A1, ASIGNACION A2
	WHERE A1.CARNET = E1.CARNET
	AND A2.CARNET = E2.CARNET
	AND A1.CODIGO = A2.CODIGO
	AND A1.SECCION = A2.SECCION
	AND A1.CICLO = A2.CICLO
	AND A1.ANIO = A2.ANIO
);

