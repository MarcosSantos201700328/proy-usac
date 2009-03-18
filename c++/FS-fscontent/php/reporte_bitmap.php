<?php include_once("global.php");
/**Escribe el superbloque de la base de datos*/
function write_bitmap($tipo){ //start write_superbloque

	$database = $GLOBALS["database"];;
	$host = $GLOBALS["host"];
	$user = $GLOBALS["user"];
	$password = $GLOBALS["password"];

	$i = 0;
	

	$connection = mysql_connect($host,$user,$password)
     		or die ("Imposible conectar al servidor, verifique que escribio el host correcto");
	$db = mysql_select_db($database,$connection)
     		or die ("Imposible seleccionar base de datos, Verifique que escribio el nombre correcto");
	if ($tipo == 'inodos'){
		$query = "SELECT MAGIC,DESCRIPCION,INICIO,FIN,FIN_REAL,CODIGO_ERROR FROM bitmap WHERE ID_SESION = ".$_GET['session_id'].' AND TIPO = 1;';
	}
	else{
		$query = "SELECT MAGIC,DESCRIPCION,INICIO,FIN,FIN_REAL,CODIGO_ERROR FROM bitmap WHERE ID_SESION = ".$_GET['session_id'].' AND TIPO = 0;';
	}
	$result = mysql_query($query)
		or die ("Imposible ejecutar Consulta.");
	$row = mysql_fetch_array($result);
?>

<table style="text-align: left; width: 100%;" border="1" cellpadding="0" cellspacing="0">
  <tbody>
    <tr>
      <td style="vertical-align: middle; text-align: left; font-weight: bold;">N&uacute;mero M&aacute;gico:</td>
      <td align="left" valign="middle"><?echo '0x'.sprintf('%x',$row['MAGIC']);?></td>
    </tr>
    <tr>
      <td style="font-weight: bold;" align="left" valign="middle">Descripci&oacute;n:</td>
      <td align="left" valign="middle"><?echo $row['DESCRIPCION'];?></td>
    </tr>
    <tr>
      <td style="font-weight: bold;" align="left" valign="middle">Inicio:</td>
      <td align="left" valign="middle"><?echo $row['INICIO'];?></td>
    </tr>
    <tr>
      <td style="font-weight: bold;" align="left" valign="middle">Fin:</td>
      <td align="left" valign="middle"><?echo $row['FIN'];?></td>
    </tr>
    <tr>
      <td style="font-weight: bold;" align="left" valign="middle">Fin Real:</td>
      <td align="left" valign="middle"><?echo $row['FIN_REAL'];?></td>
    </tr>
    <tr>
      <td style="font-weight: bold;" align="left" valign="middle">Bitmap:</td>
      <td align="left" valign="middle"><a href="./download_bitmap.php?session_id=<?echo $_GET['session_id'];?>&amp;tipo=<?echo $tipo;?>">Bajar</a></td>
    </tr>
    <tr>
      <td style="font-weight: bold;" align="left" valign="middle">C&oacute;digo de Error:</td>
      <td align="left" valign="middle"><?echo '0x'.sprintf("%x",$row['CODIGO_ERROR']);?></td>
    </tr>
  </tbody>
</table>
<?
}// End write_superbloque
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
  <meta content="text/html; charset=ISO-8859-1" http-equiv="content-type">
  <title>FSContent - Reporte de Mapa de Bits de <?echo $_GET['tipo'];?></title>
</head>
<body>
<h1>Reporte de mapa de bits de <?echo $_GET['tipo'];?></h1>
<br>
	<?if(($_GET['session_id'])>0) write_bitmap($_GET['tipo']);?>
	<?write_returnlinks($_GET['session_id']);?>
<br>
</body>
</html>
