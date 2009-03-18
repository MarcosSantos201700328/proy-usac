/**CONSULTA 17*/
/*
Dar el nombre de los estudiantes y del curso quese han registrado por lo menos 3 veces en un mismo curso

Obtenemos todos aquiellos estudiatnes tal que se el conteo de veces asignadas sea >=3
*/
SELECT AS1.CARNET,C.NOMBRE,CONCAT(E.PRIMER_NOMBRE,E.PRIMER_APELLIDO),COUNT(AS1.CODIGO)
FROM ASIGNACION AS1, ESTUDIANTE E, CURSO C
WHERE AS1.CARNET = E.CARNET
AND AS1.CODIGO = C.CURSO
GROUP BY AS1.CARNET,C.NOMBRE,CONCAT(E.PRIMER_NOMBRE,E.PRIMER_APELLIDO)
HAVING COUNT(AS1.CODIGO) >= 3
;

