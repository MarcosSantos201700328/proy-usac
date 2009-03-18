<?php include_once('global.php');
	//print('Database:'.$_POST['database'].', Host:'.$_POST['host'].', User:.'.$_POST['user'].', Password:'.$_POST['password']);
	abrir_sesion($_POST['database'],$_POST['host'],$_POST['user'],$_POST['password']);
	header('Location: ./sesiones.php');
	
?>
