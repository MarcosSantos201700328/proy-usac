/**CONSULTA 14*/
/*
Excluyendo los estudiantes de ingenieria quimica, e ingenieria civil, dar el nombre y promedio de los estudiantes que tienen mejor promedio que el promedio de los estudiantes de quimica pero peor promedio que el promedio de los estudiantes de civil y una edad menor que la edad promedio de los estudiantes de civil pero mayor que la edad promedio de los estudiantes de quimica

estudiantes que en el pensum de su carrera no exista algun curso obligatorio que no exista en los cursos que ya gano y que tenga un conteo de creditos > creditos_cierre de carrera
*/
SELECT E1.CARNET,E1.PRIMER_NOMBRE ||' '||E1.PRIMER_APELLIDO,MAX(ANUM_CREDITOS)/*,MAX(ANUM_CURSOS)*/
FROM LISTADO_ESTUDIANTES_CIERRE C1, ESTUDIANTE E1, (
	SELECT AS1.CARNET"ACARNET",SUM(CU1.CREDITOS)"ANUM_CREDITOS"
	FROM ASIGNACION AS1, PLAN PL1, APROBACION AP1, CURSO CU1
	WHERE AS1.CODIGO = CU1.CURSO
	AND (	(PL1.ANIO_INICIO = AS1.ANIO AND PL1.CICLO_INICIO <= AS1.CICLO)
				OR (PL1.ANIO_FIN = AS1.ANIO AND PL1.CICLO_FIN >= AS1.CICLO)
				OR (PL1.ANIO_INICIO < AS1.ANIO AND PL1.ANIO_FIN > AS1.ANIO)
	)
	/*AND PL1.ANIO_INICIO <= AS1.ANIO
	AND PL1.ANIO_FIN > AS1.ANIO
	AND PL1.CICLO_INICIO <= AS1.CICLO
	AND PL1.CICLO_FIN > AS1.CICLO*/
	AND AP1.PLAN = PL1.PLAN
	AND AP1.CARRERA = PL1.CARRERA
	AND AP1.CICLO = AS1.CICLO
	AND AS1.NOTA >= AP1.NOTA_APROBACION
	AND AS1.ZONA >= AP1.ZONA_MINIMA	
	GROUP BY AS1.CARNET
	)
WHERE E1.CARNET = ACARNET
GROUP BY E1.CARNET,E1.PRIMER_NOMBRE,E1.PRIMER_APELLIDO;


