/**CONSULTA 27**/
/*
Para cada carrera, dar el nombre de los estudiantes que han cerrado pensum en menos tiempo.

Obtenemos datos de estudiante y carrera y los relacionamos con la vista Listado_estudiantes_cierre que contiene el listado de estudiantes de cierre y el tiempo tardado en cerrar.
*/

SELECT E.CARRERA,C.NOMBRE, E.PRIMER_NOMBRE || E.PRIMER_APELLIDO
FROM ESTUDIANTE E, CARRERA C
WHERE EXISTS (
	SELECT CARNET, MAX(DELTAT)
	FROM LISTADO_ESTUDIANTES_CIERRE
	WHERE E.CARNET = CARNET
	GROUP BY E.CARRERA
)
AND C.CARRERA = E.CARRERA
;

