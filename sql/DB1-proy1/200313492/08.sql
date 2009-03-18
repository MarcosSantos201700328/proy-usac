/**CONSULTA 8*/
/*
Dar el nombre de los estudiantes que en este semestre cada dia que vienen a la u no tienen periodos libres

es decir todos los estudiantes que para cualquier curso asignado en el semsetre actual no exista un dia habil que no este asignado en su horario y no exista algun periodo que dado el horario dado no exita mas de 2 periodos con horario_inicial<> horario_final
*/
SELECT *
FROM ESTUDIANTE E
WHERE EXISTS(
	SELECT A.CARNET
	FROM ASIGNACION A
	WHERE A.CARNET = E.CARNET
	AND A.ANIO = 2007
	AND A.CICLO = 1
	AND NOT EXISTS(
		SELECT DIA
		FROM DIA_HABIL D
		WHERE NOT EXISTS(
			SELECT 1
			FROM HORARIO H
			WHERE H.ANIO = A.ANIO
			AND H.CICLO = A.CICLO
			AND D.DIA <> H.DIA
		)
	)
	AND NOT EXISTS(
		SELECT A.ANIO,A.CICLO,H1.DIA
		FROM HORARIO H1, PERIODO P1
		WHERE H1.ANIO = A.ANIO
		AND H1.CICLO = A.CICLO
		AND P1.PERIODO = H1.PERIODO
		AND EXISTS(
			SELECT *
			FROM HORARIO H2, PERIODO P2
			WHERE H2.ANIO = A.ANIO
			AND H2.CICLO = A.CICLO
			AND P2.PERIODO = H2.PERIODO
			AND H1.DIA = H2.DIA	
			AND P2.PERIODO <> P1.PERIODO
			AND P1.HORA_INICIO <> P2.HORA_FIN
		)
		GROUP BY A.ANIO,A.CICLO,H1.DIA
		HAVING COUNT(*) > 1
	)
);

