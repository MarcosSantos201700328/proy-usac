/*
Mapeo Lexicografico

Autor: Erik Vladimir Giron Marquez
Carnet: 200313492
*/
/***********************************************************************/
// mapeo(): Retorna la direccion de una lista con los parametros
// de un arreglo N-dimensional apuntando a un subindice particular.

// Input: Lista de punteros de enteros, tamano del tipo de dato, direccion
// Output: Direccion del elemento en cuestion

unsigned int mapeo( lista<unsigned int*> lst,
			unsigned int size, unsigned int addr) {
  lst.ultimo(); // Se dirige al ultimo elemento de la lista.

  // Invoca a funcion recursiva y retorna la direccion calculada.
  return (addr + (size * sumatoria(lst))); 
}

/****************************************************************************/
// sumatoria(): Retorna el elemento lineal al que apuntan los parametros dados
// dados en lista del vector de enteros que representan la 
// longitud de un arreglo N-dimensional\

// Input: Lista de punteros de enteros
// Output: Posicion actual del subindice indicado en la lista de vectores
unsigned int sumatoria( lista<unsigned int*> lista) {
  // Puntero a int que almacenara la 
  // direccion de datos de nodo actual.
  unsigned int *tmpvect; 
  unsigned int resultado; // Variable que almacenara temporalmente el resultado.
  tmpvect = lista.getNodo(); // obtiene direccion actual del vector del nodo.
  lista.anterior(); // se mueve al anterior elemento de la lista.
  if (!(lst.esPrimero())){
    resultado += ( ( (*(tmpvect + 2)) - (*(tmpvect + 0))) + // Obtiene el
		   ( (*(tmpvect+1)) - (*tmpvect) + 1)       //resultado usando 
		   * sumatoria(lista) );                    //recursividad 

    return resultado;
  }
  else
    return (*(tmpvect + 2)) - (*(tmpvect + 0)); // si es primero retorna solo
                                                // el ultimo calculo
}
