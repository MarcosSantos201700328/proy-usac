/**CONSULTA 21*/
/*
Para el proximo ciclo, debe insertar una asignacion automatica en la seccion A de Bases de datos 2 para todos los estudiantes que han aprobado los prerrequisitos necesarios del curso en algunos de los ciclos anteriores

Insertamos una nueva asignacion para el ciclo 2007,2 del curso base de datos 2 tal que no exista lgun prerrequisito de este curso que no este ganado en las asignaciones.
*/
INSERT INTO ASIGNACION (ANIO,CICLO,CODIGO,SECCION,CARNET,ZONA,NOTA) (
	SELECT '2007','2',CU1.CURSO,'A',E1.CARNET,'0','0'
	FROM CURSO CU1, ESTUDIANTE E1
	WHERE CU1.NOMBRE = '%BASES DE DATOS 2%'
	AND NOT EXISTS(
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
			AND PL1.CICLO_FIN > AS1.CICLO
			*/
			AND PL1.CARRERA = E1.CARRERA
			AND AP1.PLAN = PL1.PLAN
			AND AP1.CARRERA = PL1.CARRERA
			AND AP1.CICLO = AS1.CICLO
			AND AS1.NOTA >= AP1.NOTA_APROBACION
			AND AS1.ZONA >= AP1.ZONA_MINIMA			
		)
	)
);


