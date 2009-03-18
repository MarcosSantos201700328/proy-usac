#include "linkedlist.h"
#include <stdlib.h>

int insertar(linkedlist* list,void* data){
    if(list->first != NULL){
        list->actual = gotoLast(list);	
        list->actual->next = crearNodo(data);
        return 0;
    }
    list->first = crearNodo(data);
    list->actual = list->first;
    return 0;
}
nodo* gotoLast(linkedlist* list){
    nodo* tmp = list->first;
    if(tmp!= NULL){
        while(tmp->next != NULL){
	   tmp = tmp->next;        
	}
	return tmp;
    }
    return NULL;
}

nodo* crearNodo(void* data){
    nodo* tmp;
    tmp = (nodo*) malloc(sizeof(nodo));
    tmp->data = data;
    return tmp;
}

linkedlist* enlazar(linkedlist* list, nodo* n){
    gotoLast(list);
    list->actual->next = n;
    return list;
}
linkedlist* nuevaLista(nodo* first){
    linkedlist* tmplista = (linkedlist*)malloc(sizeof(linkedlist));
    tmplista->first = first;
    return tmplista;			   
}
