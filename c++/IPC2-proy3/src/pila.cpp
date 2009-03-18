#ifndef PILA_CPP
#define PILA_CPP

//#include <iostream>
#ifndef bc
using namespace std;
#endif


template<class TIPO> class pila;

template<class TIPO>
class nodopila{
   public:
	  nodopila(TIPO v, nodopila<TIPO> *sig = NULL) : valor(v), siguiente(sig) {}

   private:
      TIPO valor;
      nodopila<TIPO> *siguiente;

      friend class pila<TIPO>;
};

template<class TIPO>
class pila {
   public:
      pila() : ultimo(NULL) {}
      ~pila();

      void Push(TIPO v);
      TIPO Pop();
      TIPO * cima(); // retorna puntero al valor que se encuentra en la cima
      bool estaVacia(){return (ultimo==NULL);};
   private:
      nodopila<TIPO> *ultimo;
};

/********************************************/
template<class TIPO>
pila<TIPO>::~pila()
{
   while(ultimo) Pop();
}
template<class TIPO>
TIPO * pila<TIPO>::cima(){
    if (ultimo) return &(ultimo->valor);
    else return NULL;

}
template<class TIPO>
void pila<TIPO>::Push(TIPO v)
{
   nodopila<TIPO> *nuevo;

   /* Crear un nodopila nuevo */
   nuevo = new nodopila<TIPO>(v, ultimo);
   /* Ahora, el comienzo de nuestra pila es en nuevo nodopila */
   ultimo = nuevo;
}

template<class TIPO>
TIPO pila<TIPO>::Pop()
{
    nodopila<TIPO> *nodopila; /* variable auxiliar para manipular nodopila */
    TIPO v;      /* variable auxiliar para retorno */
    
    
    //DA ERRORES DE RESOLUCION DE TIPO-->> if(!ultimo) return 0; /* Si no hay nodopilas en la pila retornamos 0 */

    /* nodopila apunta al primer elemento de la pila */
	nodopila = ultimo;
    /* Asignamos a pila toda la pila menos el primer elemento */
    ultimo = nodopila->siguiente;
    /* Guardamos el valor de retorno */
    v = nodopila->valor;
    /* Borrar el nodopila */
    delete nodopila;
    return v;
}
#endif
