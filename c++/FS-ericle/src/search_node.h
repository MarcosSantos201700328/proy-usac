/**
@file search_node.h
@brief Arbol de sintaxis abstracto para realizar las busquedas
@author Erik Giron (C#200313492)
@todo ALL

Copyright (C) 2006 Erik Giron

http://www.itforcegt.org/200313492

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/
//typedef struct search_node* ptr_search_node;
//typedef struct search_node* ptrSearchNode;
#ifndef SEARCH_NODE_H
#define SEARCH_NODE_H
#ifdef __cplusplus
extern "C"{
#endif
//typedef struct search_node searchNode;
typedef struct search_node{
    union {
	union {
	    char* cadena; ///< cadena.
	    long numero; ///< .
	}condicion;///<Cadena de condicion, por lo regular se encontrara en las hojas del arbol
	int operador; ///<puede ser and, or, = != < <= > >=
    }campo;///< Campo
    struct search_node* izquierda;///< hijo izquierdo.
    struct search_node* derecha;///< hijo derecho.
} search_node;
//typedef struct search_node searchNode;
#ifdef __cplusplus
};
#endif
//typedef struct search_node* ptrSearchNode;
#endif
