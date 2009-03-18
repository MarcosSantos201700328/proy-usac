#ifndef COLA_CPP
#define COLA_CPP


//#include <iostream>
#ifndef bc
using namespace std;
#endif
 

template<class TIPO> class cola;



template<class TIPO>

class nodo {

   public:

    nodo(TIPO v, nodo<TIPO> *sig = NULL)

    {

       valor = v;

       siguiente = sig;

    }



   private:

    TIPO valor;

    nodo<TIPO> *siguiente;



   friend class cola<TIPO>;

};



template<class TIPO>

class cola {

   public:

    cola() : primero(NULL), ultimo(NULL) {}

    ~cola();



    void Anadir(TIPO v);

    TIPO Leer();
    bool estaVacia();



   private:

    nodo<TIPO> *primero, *ultimo;

};




template<class TIPO>
cola<TIPO>::~cola()
{
   while(primero) Leer();
}

template<class TIPO>
void cola<TIPO>::Anadir(TIPO v)
{
   nodo<TIPO> *nuevo;

   /* Crear un nodo nuevo */
   /* Este será el último nodo, no debe tener siguiente */
   nuevo = new nodo<TIPO>(v);
   /* Si la cola no estaba vacía, añadimos el nuevo a continuación de ultimo */
   if(ultimo) ultimo->siguiente = nuevo;
   /* Ahora, el último elemento de la cola es el nuevo nodo */
   ultimo = nuevo;
   /* Si primero es NULL, la cola estaba vacía, ahora primero apuntará también al nuevo nodo */
   if(!primero) primero = nuevo;
}

template<class TIPO>
TIPO cola<TIPO>::Leer()
{
   nodo<TIPO> *Nodo; /* variable auxiliar para manipular nodo */
   TIPO v;      /* variable auxiliar para retorno */

   /* Nodo apunta al primer elemento de la pila */
   Nodo = primero;
     //->Da clavos de resolucion de tipo   if(!Nodo) return 0; /* Si no hay nodos en la pila retornamos 0 */
   /* Asignamos a primero la dirección del segundo nodo */
   primero = Nodo->siguiente;
   /* Guardamos el valor de retorno */
   v = Nodo->valor;
   /* Borrar el nodo */
   delete Nodo;
   /* Si la cola quedó vacía, ultimo debe ser NULL también*/
   if(!primero) ultimo = NULL;
   return v;
}
template<class TIPO>
bool cola<TIPO>::estaVacia(){
   if (!primero) return true;
return false;


}
#endif
