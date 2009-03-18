<?php include_once('global.php');?>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
  <meta content="text/html; charset=ISO-8859-1" http-equiv="content-type">
  <title>FScontent - Seleccione Reporte</title>
</head>
<body>
<?
$s = $_GET['session_id'];

//echo $s;
if( $s > 0){
?>
<h1>Seleccione Reporte:</h1>
<br>
<ol>
  <li><a href="./reporte_fs.php?session_id=<?echo $s;?>">Ver reporte general del Sistema de Archivos...</a></li>
 <li><a href="./reporte_super.php?session_id=<?echo $s;?>">Ver reporte de Superbloques...</a></li>
  <li><a href="./reporte_gd.php?session_id=<?echo $s;?>">Ver reporte de Descriptores de Grupo...</a></li>
  <li><a href="./reporte_gd.php?session_id=<?echo $s;?>">Ver reporte de&nbsp;nodos &iacute;ndice (inodes) usados por Grupo...</a></li>
  <li><a href="./reporte_gd.php?session_id=<?echo $s;?>">Ver reporte de&nbsp;nodos &iacute;ndice (inodes) libres por Grupo...</a></li>
  <li><a href="./reporte_bloques.php?session_id=<?echo $s;?>">Ver reporte de bloques de datos libres en total...</a></li>
  <li><a href="./reporte_bitmap.php?tipo=inodos&session_id=<?echo $s;?>">Ver reporte de Mapa de Bits de I-nodos...</a></li>
  <li><a href="./reporte_bitmap.php?tipo=datos&session_id=<?echo $s;?>">Ver reporte de Mapa de Bits de datos...</a></li>
</ol>
<?
}
?>
<br>
<?write_returnlinks($_GET['session_id']);?>
</body>
</html>
