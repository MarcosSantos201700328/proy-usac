<?php include_once('global.php');
/**Genera bitmap y lo manda al stdout*/
function generate_bitmap($session_id,$tipo) {
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
		$query = "SELECT BITMAP FROM bitmap WHERE ID_SESION = ".$session_id.' AND TIPO = 1;';
	}
	else{
		$query = "SELECT BITMAP FROM bitmap WHERE ID_SESION = ".$session_id.' AND TIPO = 0;';
	}
	$result = mysql_query($query)
		or die ("Imposible ejecutar Consulta.");
	$row = mysql_fetch_array($result);
	echo $row['BITMAP']; //escribo a documento le campo
}
header ('Content-Type: text/plain');// mi propio mime-type jejeje :~)
generate_bitmap($_GET['session_id'],$_GET['tipo']);
?>
