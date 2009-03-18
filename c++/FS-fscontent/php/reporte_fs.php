<?php include_once("global.php");
/**calcula y devuelve el tamano del descriptor de grupos*/
function get_num_bloques($sid){
	$database = $GLOBALS["database"];;
	$host = $GLOBALS["host"];
	$user = $GLOBALS["user"];
	$password = $GLOBALS["password"];
	$connection = mysql_connect($host,$user,$password)
     		or die ("Imposible conectar al servidor, verifique que escribio el host correcto");
	$db = mysql_select_db($database,$connection)
     		or die ("Imposible seleccionar base de datos, Verifique que escribio el nombre correcto");

	$query = "SELECT NUM_BLOQUES FROM superbloque WHERE SESSION_ID = ".$sid.';';
	$result = mysql_query($query)
		or die ("Imposible ejecutar Consulta.");
	$row = mysql_fetch_array($result);
	//echo $row['NUM_BLOQUES'].'-<br>';
	return $row['NUM_BLOQUES']/* * $row['BLOQUES_POR_GRUPO']*/;
}
	

/**Escribe reporte del sistema de archivos*/
function write_fs(){

	$database = $GLOBALS["database"];;
	$host = $GLOBALS["host"];
	$user = $GLOBALS["user"];
	$password = $GLOBALS["password"];

	$num_bloques = get_num_bloques($_GET['session_id']);
	$i = 0;
	
	//print('Database:'.$database.', Host:'.$host.', User:.'.$user.', Password:'.$password);

	$connection = mysql_connect($host,$user,$password)
     		or die ("Imposible conectar al servidor, verifique que escribio el host correcto");
	$db = mysql_select_db($database,$connection)
     		or die ("Imposible seleccionar base de datos, Verifique que escribio el nombre correcto");

	$query = "SELECT * FROM particion WHERE SESSION_ID = ".$_GET['session_id'].';';
	$result = mysql_query($query)
		or die ("Imposible ejecutar Consulta.");
	$row = mysql_fetch_array($result);
	?>
<table style="text-align: left; width: 100%;" border="1" cellpadding="2" cellspacing="2">
  <tbody>
    <tr>
      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">Dispositivo:</td>
      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['DISPOSITIVO'];?></td>
    </tr>
    <tr>
      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">Banderas:</td>
      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['BANDERAS'];?></td>
    </tr>
    <tr>
      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">Tama&ntilde;o de bloque:</td>
      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['TAM_BLOQUE'];?> bytes</td>
    </tr>
    <tr>
      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">Tama&ntilde;o de fragmento:</td>
      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['TAM_FRAGMENTO'];?> bytes</td>
    </tr>
    <tr>
      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">N&uacute;mero de Descriptores:</td>
      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['NUM_DESCRIPTORES'];?></td>
    </tr>
    <tr>
      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">Bloques del Descriptor:</td>
      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['BLOQUES_DESC'];?></td>
    </tr>
    <tr>
      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">Inodos por Grupo:</td>
      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['INODOS_POR_GRUPO'];?></td>
    </tr>
    <tr>
      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">Tama&ntilde;o de la particion:</td>
      <td align="left" nowrap="nowrap" valign="middle"><?echo '~'.floor(($row['TAM_BLOQUE'] * $num_bloques)/1024/1024).' MB';?></td>
    </tr>
  </tbody>
</table>
	<?
	
}



?>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
  <meta content="text/html; charset=ISO-8859-1" http-equiv="content-type">
  <title>Fscontent - Reporte del Sistema de Archivos</title>
</head>
<body>
<h1>Reporte del Sistema de Archivos:</h1>
<br>
<? write_fs(); ?>
<?write_returnlinks($_GET['session_id']);?>
<br>
</body>
</html>
