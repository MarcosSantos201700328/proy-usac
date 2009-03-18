<?php
// Generaremos salida XML
header('Content-Type: text/xml');
// Genera encabezado XML
echo '<?xml version="1.0" encoding="UTF-8" standalone="yes"?>';
// Crea el elemento <response>
echo '<response>';
// Recibe el nombre de usuario
$name = $_GET['name'];
// Genera salida dependiendo de la entrada del usuario
$userNames = array('ERIK', 'SAULO', 'GABRIEL', 'YODA');
if (in_array(strtoupper($name), $userNames))
  echo 'Buen dia, maestro ' . htmlentities($name) . '!';
else if (trim($name) == '')
  echo 'Extrano, por favor diga su nombre!';
else
  echo htmlentities($name) . ', No lo conozco!';
// Cierra el elemento <response>
echo '</response>';
?>


