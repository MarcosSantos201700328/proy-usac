/**CONSULTA 22*/
/*
Eliminar todas las a signaciones que se han hecho en las cuales los estudiantes no habian aprobado previamente los prerrequisitos del curso

Borramos de la tabla asignacion si existe algun curso asignado donde exista algun prerrequisito de la carrera de algun estudiante tal que no exista un curso que no haya ganado
*/
DELETE FROM ASIGNACION AS1
WHERE EXISTS(
	SELECT 1
	FROM CURSO CU1, ESTUDIANTE E1
	WHERE CU1.CURSO = AS1.CODIGO
	AND EXISTS(
		SELECT 1
		FROM PRERREQUISITO PR1
		WHERE PR1.CARRERA = E1.CARRERA
		AND PR1.CODIGO = CU1.CURSO
		AND NOT EXISTS(
			SELECT 1
			FROM APROBACION AP1, PLAN PL1, ASIGNACION AS1
			WHERE E1.CARNET = AS1.CARNET
			AND (	(PL1.ANIO_INICIO = AS1.ANIO AND PL1.CICLO_INICIO <= AS1.CICLO)
				OR (PL1.ANIO_FIN = AS1.ANIO AND PL1.CICLO_FIN >= AS1.CICLO)
				OR (PL1.ANIO_INICIO < AS1.ANIO AND PL1.ANIO_FIN > AS1.ANIO)
			)
			/*AND PL1.ANIO_INICIO <= AS1.ANIO
			AND PL1.ANIO_FIN > AS1.ANIO
			AND PL1.CICLO_INICIO <= AS1.CICLO
			AND PL1.CICLO_FIN > AS1.CICLO*/
			AND PL1.CARRERA = E1.CARRERA
			AND AP1.PLAN = PL1.PLAN
			AND AP1.CARRERA = PL1.CARRERA
			AND AP1.CICLO = AS1.CICLO
			AND AS1.NOTA >= AP1.NOTA_APROBACION
			AND AS1.ZONA >= AP1.ZONA_MINIMA			
		)
	)
);

