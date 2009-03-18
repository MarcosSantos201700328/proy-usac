<?php include_once("global.php");
/**Escribe el superbloque de la base de datos*/
function write_bloques_libres($sid){ //start write_superbloque

	$database = $GLOBALS["database"];;
	$host = $GLOBALS["host"];
	$user = $GLOBALS["user"];
	$password = $GLOBALS["password"];

	$i = 0;
	

	$connection = mysql_connect($host,$user,$password)
     		or die ("Imposible conectar al servidor, verifique que escribio el host correcto");
	$db = mysql_select_db($database,$connection)
     		or die ("Imposible seleccionar base de datos, Verifique que escribio el nombre correcto");

	$query = "SELECT NUM_BLOQUES_LIBRES,NUM_BLOQUES FROM superbloque WHERE SESSION_ID = ".$sid.';';
	$result = mysql_query($query)
		or die ("Imposible ejecutar Consulta.");
	$row = mysql_fetch_array($result);
?>
Se encontraron&nbsp;<?echo $row['NUM_BLOQUES_LIBRES'];?> bloques libres, de un total de <?echo $row['NUM_BLOQUES'];?> bloques.
<?}?>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">

<html>
<head>
  <meta content="text/html; charset=ISO-8859-1" http-equiv="content-type">
  <title>Reporte de Bloques de datos libres</title>
</head>
<body>
<h1>Reporte de Bloques de datos libres en total</h1>
<br>
<?
if(($_GET['session_id'])>0)
	write_bloques_libres($_GET['session_id']);
?>
<?write_returnlinks($_GET['session_id']);?>
</body>
</html>
