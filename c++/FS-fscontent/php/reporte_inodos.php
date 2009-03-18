<?php include_once('global.php');
/**Escrible listado de descriptores en table rows segun la sesion actual*/
function write_inodos($s_id,$g_id,$usados){

	$database = $GLOBALS["database"];;
	$host = $GLOBALS["host"];
	$user = $GLOBALS["user"];
	$password = $GLOBALS["password"];

	$i = 0;

	$connection = mysql_connect($host,$user,$password)
     		or die ("Imposible conectar al servidor, verifique que escribio el host correcto");
	$db = mysql_select_db($database,$connection)
     		or die ("Imposible seleccionar base de datos, Verifique que escribio el nombre correcto");
// TABLE HEADER
?>
<table style="text-align: left; width: 100%;" border="1" cellpadding="2" cellspacing="2">
  <tbody>
    <tr>

      <th style="font-weight: bold;"><small><small>Numero</small></small></th>
<?
	if($usados == 'true'){
?>
      <th style="font-weight: bold;"><small><small>UID</small></small></th>
      <th style="font-weight: bold;"><small><small>Modo</small></small></th>
      <th style="font-weight: bold;"><small><small>Tama&ntilde;o</small></small></th>
      <th style="font-weight: bold;"><small><small>Acceso</small></small></th>
      <th style="font-weight: bold;"><small><small>Creacion</small></small></th>
      <th style="font-weight: bold;"><small><small>Modificacion</small></small></th>
      <th style="font-weight: bold;"><small><small>GID</small></small></th>
      <th style="font-weight: bold;"><small><small>Enlaces</small></small></th>
      <th style="font-weight: bold;"><small><small>Bloques</small></small></th>
      <th style="font-weight: bold;"><small><small>Banderas</small></small></th>
      <th style="font-weight: bold;"><small><small>Es Directorio</small></small></th>
<?
	}
?>
    </tr>
<?
// END TABLE HEADER
	
	if ($usados == 'true')
		$query = "SELECT * FROM inodo WHERE ID_SESION =".$s_id." AND NUM_GRUPO = ".$g_id." AND NUM_ENLACES > 0;";
	else
		$query = "SELECT NUM_INODO FROM inodo WHERE ID_SESION =".$s_id." AND NUM_GRUPO = ".$g_id." AND NUM_ENLACES = 0;";
	
	$result = mysql_query($query)
		or die ("Imposible ejecutar Consulta.");
	while($row = mysql_fetch_array($result)){
		/*Color de fila*/
		if($i%2 == 0){
		//TABLE BODY
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
				
      <td align="undefined" valign="undefined"><small><small><?echo $row['NUM_INODO'];?></small></small></td>
		<?
		if($usados=='true'){?>
      <td align="undefined" valign="undefined"><small><small><?echo $row['USUARIO'];?></small></small></td>
      <td align="undefined" valign="undefined"><small><small><?echo $row['MODO'];?></small></small></td>
      <td align="undefined" valign="undefined"><small><small><?echo $row['TAM'];?></small></small></td>
      <td align="undefined" valign="undefined"><small><small><?echo gettime($row['ACCESADO']);?></small></small></td>
      <td align="undefined" valign="undefined"><small><small><?echo gettime($row['CREADO']);?></small></small></td>
      <td align="undefined" valign="undefined"><small><small><?echo gettime($row['MODIFICADO']);?></small></small></td>
      <td align="undefined" valign="undefined"><small><small><?echo $row['GRUPO'];?></small></small></td>
      <td align="undefined" valign="undefined"><small><small><?echo $row['NUM_ENLACES'];?></small></small></td>
      <td align="undefined" valign="undefined"><small><small><?echo $row['NUM_BLOQUES'];?></small></small></td>
      <td align="undefined" valign="undefined"><small><small><?echo $row['BANDERA'];?></small></small></td>
      <td align="undefined" valign="undefined"><small><small><?echo $row['ES_DIRECTORIO'];?></small></small></td>
    </tr>
		<?
		}
		//END TABLE BODY
		$i++;

	}
//TABLE FOOTER
?>
  </tbody>
</table>
<?
//END TABLE FOOTER
}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
  <meta content="text/html; charset=ISO-8859-1" http-equiv="content-type">
  <title>FSContent - Reporte de inodos usados</title>
</head>
<body>
<h1 style="text-align: left;">Reporte de Inodos utilizados en el grupo <?echo ($_GET['groupid'] + 1);?>:</h1>
<br>
	<?php write_inodos($_GET['sessionid'],$_GET['groupid'],$_GET['usados']);?>
	<?write_returnlinks($_GET['session_id']);?>
<br>
</body>
</html>
