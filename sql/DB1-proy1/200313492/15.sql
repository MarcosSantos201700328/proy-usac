/**CONSULTA 15*/
/*
Excluyendo los estudiantes de ingenieria quimica, e ingenieria civil, dar el nombre y promedio de los estudiantes que tienen mejor promedio que el promedio de los estudiantes de quimica pero peor promedio que el promedio de los estudiantes de civil y una edad menor que la edad promedio de los estudiantes de civil pero mayor que la edad promedio de los estudiantes de quimica

Obtenemos promedios y edades de todos los estudiantes de quimica y civil y los comparamos entre si, para los promedios se utilizo la tabla ESTUDIANTE_CARR_PROM_EDAD

*/
SELECT EC3.CARNET,E1.PRIMER_NOMBRE||' '||E1.PRIMER_APELLIDO,EC3.PROM
FROM ESTUDIANTE_CARR_PROM_EDAD EC3, ESTUDIANTE E1
WHERE EC3.CARNET = E1.CARNET
AND EC3.CARRERA NOT LIKE '%civil%'
AND EC3.CARRERA NOT LIKE '%quimica%'
AND EC3.EDAD > (
	SELECT AVG(EC1.PROM)
	FROM ESTUDIANTE_CARR_PROM_EDAD EC1	
	WHERE EC1.CARRERA LIKE '%quimica%'
	GROUP BY EC1.CARRERA
)
AND EC3.EDAD < (
	SELECT AVG(EC1.PROM)
	FROM ESTUDIANTE_CARR_PROM_EDAD EC1	
	WHERE EC1.CARRERA LIKE '%civil%'
	GROUP BY EC1.CARRERA
)
AND EC3.PROM > (
	SELECT AVG(EC1.EDAD)
	FROM ESTUDIANTE_CARR_PROM_EDAD EC1	
	WHERE EC1.CARRERA LIKE '%quimica%'
 	gROUP BY EC1.CARRERA
)
AND EC3.PROM < (
	SELECT AVG(EC1.EDAD)
	FROM ESTUDIANTE_CARR_PROM_EDAD EC1	
	WHERE EC1.CARRERA LIKE '%civil%'
	GROUP BY EC1.CARRERA
)
;
	

