/**CONSULTA 25*/
/*
Dar el nombre de los cursos que tienen el promedio de repitentes mas alto.

Obtenemos el curso, y el maximo del promedio de repeitentes de la vista count_rep_curso_per_ciclo agrupado por curso
*/
SELECT CURSO,MAX(AVG_REP)"CONTEO MAXIMO REPITENTES"
FROM(
	SELECT CURSO,AVG(COUNT_REP)"AVG_REP"
	FROM COUNT_REP_CURSO_PER_CICLO
	GROUP BY CURSO
)
GROUP BY CURSO;

