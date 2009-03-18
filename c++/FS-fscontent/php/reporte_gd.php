<?php include_once('global.php');
/**Escrible listado de descriptores en table rows segun la sesion actual*/
function write_descriptors($s_id){

	$database = $GLOBALS["database"];;
	$host = $GLOBALS["host"];
	$user = $GLOBALS["user"];
	$password = $GLOBALS["password"];

	$i = 0;

	$connection = mysql_connect($host,$user,$password)
     		or die ("Imposible conectar al servidor, verifique que escribio el host correcto");
	$db = mysql_select_db($database,$connection)
     		or die ("Imposible seleccionar base de datos, Verifique que escribio el nombre correcto");
?>
<table style="text-align: left; width: 100%;" border="1" cellpadding="0" cellspacing="0">
  <tbody>
    <tr>
      <th style="vertical-align: middle; text-align: center;"><small>Grupo</small></th>
      <th style="vertical-align: middle; text-align: center;"><small>Inicio Bitmap de Inodos</small></th>
      <th style="vertical-align: middle; text-align: center;"><small>Inicio bitmap de Bloques</small></th>
      <th style="vertical-align: middle; text-align: center;"><small>Dir. Tabla de Inodos</small></th>
      <th style="vertical-align: middle; text-align: center;"><small>Cantidad de Bloques Libres</small></th>
      <th style="vertical-align: middle; text-align: center;"><small>Cantidad de Inodos Libres</small></th>
      <th style="vertical-align: middle; text-align: center;"><small>Directorios Usados</small></th>
      <th style="vertical-align: middle; text-align: center;"><small>Relleno</small></th>
    </tr>
<?
	$query = "SELECT * FROM descriptor WHERE ID_SESION =".$s_id.";";
	$result = mysql_query($query)
		or die ("Imposible ejecutar Consulta.");
	while($row = mysql_fetch_array($result)){
		/*Color de fila*/
		if($i%2 == 0){
		?>
		<tr
		style="background: rgb(216, 216, 216) none repeat scroll 0%; -moz-background-clip: initial; -moz-background-origin: initial; -moz-background-inline-policy: initial;">
		<?
		}
		else{
		?>
			<tr>	
		<?
		}/*Imprimimos datos*/
		?>			
      <td align="center" valign="middle"><b><?echo $row['NUM_GRUPO'] + 1;?></b><br><small>
(<a href=<?echo '"./reporte_inodos?sessionid='.$s_id.'&amp;groupid='.$row['NUM_GRUPO'].'&amp;usados=false"';?>>ver inodos libres</a>)<br>
(<a href=<?echo '"./reporte_inodos?sessionid='.$s_id.'&amp;groupid='.$row['NUM_GRUPO'].'&amp;usados=true"';?>>ver inodos usados</a>)</small></td>
      <td align="left" valign="middle"><small><br><?echo $row['INICIO_BITMAP_INODO'];?></small></td>
      <td align="left" valign="middle"><small><?echo $row['INICIO_BITMAP_BLOQUE'];?></small></td>
      <td align="left" valign="middle"><small><?echo $row['TABLA_INODOS'];?></small></td>
      <td align="left" valign="middle"><small><?echo $row['BLOQUES_LIBRES'];?></small></td>
      <td align="left" valign="middle"><small><?echo $row['INODOS_LIBRES'];?></small></td>
      <td align="left" valign="middle"><small><?echo $row['DIR_USADOS'];?></small></td>
      <td align="left" valign="middle"><small><?echo $row['RELLENO'];?></small></td>
    </tr>
		<?
		$i++;
	}
?>
  </tbody>
</table>
<?
}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
  <meta content="text/html; charset=ISO-8859-1" http-equiv="content-type">
  <title>FSContent - Reporte de Descriptores</title>
</head>
<body>
<h1>Por favor, seleccione grupo:</h1>
<br>
<?
	write_descriptors($_GET['session_id']);
?>
<?write_returnlinks($_GET['session_id']);?>
<br>
</body>
</html>