#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#ifdef __cplusplus
extern "C"{
#endif
    /**Nodo de la lista*/
    typedef struct node{
	int key;
	char tipo;
	void* data;	
	struct node* next;
	
    }nodo;
    /**Lista simple*/
    typedef struct linkedlist{
	nodo* first;	
	nodo* actual;
    }linkedlist;
nodo* crearNodo(void* data);/**<crea un nuevo nodo con el dato en parametro*/
nodo* gotoLast(linkedlist* list);/**<Va al ultimo elemento*/
nodo* buscar(linkedlist* list,int key); /**<Busca una clave*/
int insertar(linkedlist* list,void* data);/**<Inserta un nuevo valor*/
linkedlist* enlazar(linkedlist* list, nodo* n);/**<agrega nodo a la lista*/
linkedlist* nuevaLista(nodo* first);/**Crea una nueva lista con el nodo first al inicio*/

#define PRIMERO(x) (x)->actual = (x)->first
#define SIGUIENTE(x) (x)->actual = (x)->actual->next

#ifdef __cplusplus
}
#endif
#endif
