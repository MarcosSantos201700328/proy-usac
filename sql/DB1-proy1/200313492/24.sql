/**CONSULTA 24*/
/*
Dar el nombre de los estudiantes y su promedio, para los estudiantes que tienen el promedio mas alto de su promocion y carrera

Obtenemos el carnet, promociion, carrera y el maximo promedio por la carrera y promocion de algun estudiante desde la vista prom_por_promo_carrera
*/
SELECT DISTINCT E.CARNET, P.PROMO,P.CARRERA,MAX(P.PROMEDIO)
FROM ESTUDIANTE E, PROM_POR_PROMO_CARRERA P
WHERE E.CARNET = P.CARNET
AND E.CARRERA = P.CARRERA
GROUP BY E.CARNET,P.PROMO, P.CARRERA;

