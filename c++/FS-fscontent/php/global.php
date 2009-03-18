<?php

// Variables Globales
$database = 'fscontent';///< Variable para nombre de base de datos
$host = 'localhost';///<Variable para nombre de base de la maquina
$user = 'fscontent';///<Variable para nombre de Usuario
$password = '';///<Variable para password
$db_sessionid;///< ID de la tabla sesion de la base de datos

// Funciones
/**Abre una sesion de PHP y configura variables de sesion*/
function abrir_sesion($d,$m,$u,$p){
	//session_start();
	global $database;
	global $host;
	global $user;
	global $password;
	$database = $d;
	$host = $m;
	$user = $u;
	$password = $p;
//	conectar($d,$m,$u,$p);
    	
}

/**Escribe links de retorno*/
function write_returnlinks($sid){
	?>
	<br>	
	<a href=<? echo "./reportes.php?session_id=$sid";?>>
	Regresar al menu de reportes
	</a><br>
	<a href="./sesiones.php">
	Regresar al menu de sesiones
	</a><br>
	<?
}
/**Conecta a la base de datos*/
function conectar($d,$h,$u,$p){
	/*$db = new mysqli($h,$u, $p,$d);
	if (mysqli_connect_errno())
	{
   		echo 'Error: Could not connect to database';
   		exit;
	}
*/
	$connection = mysql_connect($h,$u,$p)
     		or die ("Imposible conectar al servidor, verifique que escribio el host correcto");
	$db = mysql_select_db($d,$connection)
     		or die ("Imposible seleccionar base de datos, Verifique que escribio el nombre correcto");
}

/**Cierra sesion de PHP*/
function cerrar_sesion(){
	session_destroy();
}

/**Chequea que usuario este logeado*/
function check_session(){
  session_start();
  if ( @$_SESSION['login'] != "yes" )
  {
    header("Location: login.html");
    exit();
  }
}
/**Convierte una fecha en formato UNIX a formato gregoriano*/
function gettime($timestamp){
	return gmdate('d-M-Y h:m:s',$timestamp);
}

/*
$host=”localhost”;
$user=”admin”;
$password=””;
$database=”MemberDirectory”;
$loginName = “gsmith”; // passed from previous page
$connection = mysql_connect($host,$user,$password)
     or die (“couldn’t connect to server”);
$db = mysql_select_db($database,$connection)
     or die (“Couldn’t select database”);
if (@$_GET[‘first’] == “no”)
{
  $phone = $_POST[‘phone’];
  if (!ereg(“^[0-9)( -]{7,20}(([xX]|(ext)|(ex))?[ -]?[0-9]{1,7})?$”,$phone)
          or $phone == “”)
  {
       echo “<p align=’center’>Phone number does not
                appear to be valid.<br>”;
  }
  else
  {
      $query = “UPDATE Member SET phone=’$phone’
                         WHERE loginName=’$loginName’”;
      $result = mysql_query($query)
            or die (“Couldn’t execute query.”);
      echo “Phone number has been updated.<br>”;
      exit();
  }
}
else
{
  $query = “SELECT phone FROM Member WHERE loginName=’$loginName’”;
  $result = mysql_query($query)
        or die (“Couldn’t execute query.”);
  $row = mysql_fetch_array($result);
  extract($row);
}
*/
?>