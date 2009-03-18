<?php include_once("global.php");
/**Escribe posiciones donde se encuentra superbloque*/
function write_pos_super($sid){
	$database = $GLOBALS["database"];;
	$host = $GLOBALS["host"];
	$user = $GLOBALS["user"];
	$password = $GLOBALS["password"];

	$i = 0;

	$connection = mysql_connect($host,$user,$password)
     		or die ("Imposible conectar al servidor, verifique que escribio el host correcto");
	$db = mysql_select_db($database,$connection)
     		or die ("Imposible seleccionar base de datos, Verifique que escribio el nombre correcto");
	$query = "SELECT INICIO_BITMAP_BLOQUE FROM descriptor WHERE ID_SESION =".$sid.";";
	$result = mysql_query($query)
		or die ("Imposible ejecutar Consulta.");
	?> Se encontr<?if(mysql_num_rows($result)>1) echo 'aron'; else echo 'o';?> superbloque<?if(mysql_num_rows($result)>1) echo 's';?> en la<?if(mysql_num_rows($result)>1) echo 's';?> posicion<?if(mysql_num_rows($result)>1) echo 'es';?> o bloque<?if(mysql_num_rows($result)>1) echo 's';?>:<br><br> <?
	while($row = mysql_fetch_array($result)){
		
		
		if ($i==0){
			echo ($row['INICIO_BITMAP_BLOQUE'] + 2519);
			$i++;
		}
		else if ($i > 0 and $i<3){
			echo ', '.($row['INICIO_BITMAP_BLOQUE'] + 2519);
			$i++;
		}
		else{
			echo ', '.($row['INICIO_BITMAP_BLOQUE'] + 2519);
			echo'<br>';
			$i = 0;					
		}
		
	}
	?><br><br><br><?
}
/**Escribe el superbloque de la base de datos*/
function write_superbloque(){ //start write_superbloque

	$database = $GLOBALS["database"];;
	$host = $GLOBALS["host"];
	$user = $GLOBALS["user"];
	$password = $GLOBALS["password"];

	$i = 0;
	

	$connection = mysql_connect($host,$user,$password)
     		or die ("Imposible conectar al servidor, verifique que escribio el host correcto");
	$db = mysql_select_db($database,$connection)
     		or die ("Imposible seleccionar base de datos, Verifique que escribio el nombre correcto");

	$query = "SELECT * FROM superbloque WHERE SESSION_ID = ".$_GET['session_id'].';';
	$result = mysql_query($query)
		or die ("Imposible ejecutar Consulta.");
	$row = mysql_fetch_array($result);
?>
<table style="text-align: left; width: 100%;" border="1" cellpadding="2" cellspacing="2">

  <tbody>

    <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">N&uacute;mero de Inodos:</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['NUM_INODOS'];?></td>

    </tr>

    <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">N&uacute;mero de Bloques:</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['NUM_BLOQUES'];?></td>

    </tr>

    <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">N&uacute;mero de Bloques reservados:</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['NUM_BLOQUES_RES'];?></td>

    </tr>

    <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">Total de Inodos Libres:</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['NUM_BLOQUES_LIBRES'];?></td>

    </tr>

    <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">Primer bloque de datos:</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['NUM_INODOS'];?></td>

    </tr>

    <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">Tama&ntilde;o de Bloques:</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['TAM_BLOQUES'];?> bytes</td>

    </tr>

    <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">Tama&ntilde;o de Fragmento:</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['TAM_FRAGMENTO'];?> bytes</td>

    </tr>

    <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">Bloques por Grupo:</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['BLOQUES_POR_GRUPO'];?></td>

    </tr>

    <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">Fragmentos por Grupo:</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['FRAGMENTOS_POR_GRUPO'];?></td>

    </tr>

    <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">Inodos por Grupo</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['INODOS_POR_GRUPO'];?></td>

    </tr>

    <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">&Uacute;ltima vez Montado:</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo gettime($row['MONTADO_EL']);?></td>

    </tr>

 <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">&Uacute;ltima vez Escrito:</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo gettime($row['ESCRITO_EL']);?></td>

    </tr>
 
 <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">N&uacute;mero de veces Montado:</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['VECES_MONTADO'];?> veces</td>

    </tr>
 
 <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">N&uacute;mero M&aacute;ximo de veces montado para chequeo:</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['MAX_VECES_MONTADO'];?> veces</td>

    </tr>
 
 <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">N&uacute;mero M&aacute;gico:</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo '0x'.sprintf("%x",$row['MAGIC']);?></td>

    </tr>

 <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">Estado:</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['ESTADO'];?></td>

    </tr>
 
 <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">Comportamiento a Errores:</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['COMPORT_ERROR'];?></td>

    </tr>

 <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">Version menor:</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['REVISION_MENOR'];?></td>

    </tr>
 
 <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">Ultima vez chequeado:</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo gettime($row['ULTIMO_FSCK']);?></td>

    </tr>
 
 <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">Intervalo de Chequeo:</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo ($row['INTERVALO_FSCK']/3600/24);?> dias</td>

    </tr>
 
 <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">Sistema Operativo Creador:</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['SISTEMA_OPERATIVO'];?></td>

    </tr>

 <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">Version:</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['REVISION'];?></td>

    </tr>

 <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">UID predet. de bloques res.</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['USUARIO_BLOQUES_RES'];?></td>

    </tr>
 
 <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">GID predet. de bloques res.</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['GRUPO_BLOQUES_RES'];?></td>

    </tr>

 <tr>

      <td style="font-weight: bold;" align="left" nowrap="nowrap" valign="middle">Ultimo Punto de Montaje:</td>

      <td align="left" nowrap="nowrap" valign="middle"><?echo $row['DIR_MONTAJE'];?></td>

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
  <title>Fscontent - Reporte del Superbloque</title>


</head>
<body>

<h1>Reporte del Superbloque:</h1>

<br>
<?
if(($_GET['session_id'])>0)
	write_pos_super($_GET['session_id']);
	write_superbloque();
?>
<?write_returnlinks($_GET['session_id']);?>
<br>

</body>
</html>
