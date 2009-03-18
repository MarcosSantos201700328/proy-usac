<?php include_once('global.php');
/**Escrible listado de sesiones en table rows*/
function write_sessions(){
// 	$database = 'fscontent';
// 	$host = 'localhost';
// 	$user = 'fscontent';
// 	$password = '';
	$database = $GLOBALS["database"];;
	$host = $GLOBALS["host"];
	$user = $GLOBALS["user"];
	$password = $GLOBALS["password"];

	$i = 0;
	
	//print('Database:'.$database.', Host:'.$host.', User:.'.$user.', Password:'.$password);

	$connection = mysql_connect($host,$user,$password)
     		or die ("Imposible conectar al servidor, verifique que escribio el host correcto");
	$db = mysql_select_db($database,$connection)
     		or die ("Imposible seleccionar base de datos, Verifique que escribio el nombre correcto");

	$query = "SELECT * FROM sesion;";
	$result = mysql_query($query)
		or die ("Imposible ejecutar Consulta.");
	while($row = mysql_fetch_array($result)){
		/*Color de fila*/
		if($i%2 == 0){
		?>
		<tr
		style="background: rgb(204, 204, 204) none repeat scroll 0%; -moz-background-clip: initial; -moz-background-origin: initial; -moz-background-inline-policy: initial;">
		<?
		}
		else{
		?>
			<tr>	
		<?
		}/*Imprimimos datos*/
		?>			
		<td><?echo '<a href="reportes.php?session_id='.$row['ID'].'">'.gettime($row['ID']).'</a>';?></td>
		<td><?echo $row['PARTICION'];?></td>
		<td><?echo $row['TIEMPO_ANALISIS'];?> s</td>
		<td><?echo $row['NUM_ELEMENTOS'];?></td>
		<td><?echo $row['NUM_INSERCIONES'];?></td>
		</tr>

		<?
		$i++;
	}
}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
  <meta http-equiv="content-type"
 content="text/html; charset=ISO-8859-1">
  <title>Seleccione sesion...</title>
</head>= 
<body>
<h1>Sesiones encontradas en base de datos <?echo $GLOBALS['database'];?></h1>
<br>
Por favor, seleccione la sesion que desee ver:<br>
<br>
<table
 style="width: 100%; text-align: left; margin-left: auto; margin-right: auto;"
 border="1" cellpadding="2" cellspacing="2">
  <caption></caption><tbody>
    <tr
 style="background: rgb(0, 204, 255) none repeat scroll 0% 50%; -moz-background-clip: initial; -moz-background-origin: initial; -moz-background-inline-policy: initial;">
      <td style="font-weight: bold; text-align: center;">Fecha</td>
      <td style="font-weight: bold; text-align: center;">Particion</td>
      <td style="font-weight: bold; text-align: center;">Tiempo
de Analisis</td>
      <td style="font-weight: bold; text-align: center;">Cantidad
de Elementos
encontrados</td>
      <td style="font-weight: bold; text-align: center;">Cantidad
de
Inserciones</td>
    </tr>
	<?write_sessions();?>

  </tbody>
</table>
</body>
</html>
