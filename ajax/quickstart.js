// Almacena la referencia al objeto httprequestobject
var xmlHttp = createXmlHttpRequestObject();
// Envia el objeto XMLHttpRequest
function createXmlHttpRequestObject()
{
  // Almacenara la referencia al objeto XMLHttpRequest
  var xmlHttp;
  // Si es IE
  if(window.ActiveXObject)
  {
    try
    {
      xmlHttp = new ActiveXObject("Microsoft.XMLHTTP");
    }
    catch (e)
    {
      xmlHttp = false;
    }
  }
  // Si es mozilla
  else
  {
    try
    {
      xmlHttp = new XMLHttpRequest();
    }
    catch (e)
    {
      xmlHttp = false;
    }
  }
  // Devuelve el objeto creado o retorna error
  if (!xmlHttp)
    alert("Error al crear el objeto XMLHttpRequest.");
  else
    return xmlHttp;
}
// Hace request HTTP asincronos usando el objeto XMLHttpRequest
function process()
{
  // Procede solo sie el objeto xmlHttp no esta ocupado
  if (xmlHttp.readyState == 4 || xmlHttp.readyState == 0)
  {
    // Envia el nombre escrito por el usuario en el formulario
    name = encodeURIComponent(document.getElementById("myName").value);
    // Ejecuta quickstart.php desde el servidor
    xmlHttp.open("GET", "quickstart.php?name=" + name, true);
    // Define el metodo para manejar las respuestas del servidor
    xmlHttp.onreadystatechange = handleServerResponse;
    // Hace el envio al servidor
    xmlHttp.send(null);
  }
  else
    // Si la conexion esta ocupada, intenta despues de 1 seg
    setTimeout('process()', 1000);
}
// Ejecutado automaticamente cuando un mensaje se recive desde el servidor
function handleServerResponse()
{
  // Continua solo si la transaccion se ha completado
  if (xmlHttp.readyState == 4)
  {
    // Estatus 200 indica que la transaccion se completo satisfactoriamente
    if (xmlHttp.status == 200)
    {
      // Extrae el XML devuelto por el servidor
      xmlResponse = xmlHttp.responseXML;
      // Obitiene el elemento del raiz del documento de la estructura XML
      xmlDocumentElement = xmlResponse.documentElement;
      // Obtiene el mensaje que es el primer hijo del
      // elemento documento
      helloMessage = xmlDocumentElement.firstChild.data;
      // Actualiza la pantalla del cliente usando el dato recibido desde el server
      document.getElementById("divMessage").innerHTML =
                                             '<i>' + helloMessage + '</i>';
      // Reinicia la secuencia
      setTimeout('process()', 1000);
    }
    // Un estatus HTTP <> 200 significa error
    else
    {
      alert("Hubo un problema accediendo el servidor: " +
xmlHttp.statusText);
    }
  }
}

