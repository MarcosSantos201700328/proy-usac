/**CONSULTA 9*/
/*
Dar el nombre de los catedraticos que este semestre vienen todos los dias habiles para impartir exactamente una clase

es decir los catedraticos tal que exista cualquier catedratico exista en una seccion tal que no exista un dia que exista en el horario tal que no de clase en su seccion en el mismo dia de la semana y tal que en ese dia dado imparta exactamente una clase
*/
SELECT *
FROM CATEDRATICO CAT
WHERE EXISTS(
	SELECT DISTINCT *
	FROM SECCION SEC
	WHERE SEC.CATEDRATICO = CAT.CATEDRATICO
	AND SEC.ANIO = 2007
	AND SEC.CICLO = 1
	AND NOT EXISTS(
		SELECT 1
		FROM DIA_HABIL D
		WHERE NOT EXISTS(
			SELECT 1
			FROM HORARIO H
			WHERE H.ANIO = SEC.ANIO
			AND H.CICLO = SEC.CICLO
			AND H.SECCION = SEC.SECCION
			AND H.DIA <> D.DIA
		)
		AND NOT EXISTS(
			SELECT H.DIA
			FROM HORARIO H, SECCION S1
			WHERE H.ANIO = SEC.ANIO
			AND H.CICLO = SEC.CICLO
			AND H.DIA = D.DIA
			AND S1.CATEDRATICO = CAT.CATEDRATICO
			AND H.SECCION = S1.SECCION
			GROUP BY H.DIA
			HAVING COUNT(H.DIA) = 1
		)
	)
);

