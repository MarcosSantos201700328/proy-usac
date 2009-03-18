/** @file parserheader.h
 * interfaz entre el GUI y el parser.*/
/* Godzilla
* Proyecto No. 2 de Lenguajes y Compiladores 1
* (c) 2006 Erik Giron C# 200313492
*/
//TODO Implementar correctamente los siguientes prototipos dentro del embed.y
#ifndef PARSERHEADER_H
#define PARSERHEADER_H
/**Interfaz para parser y lexer*/
extern int inputparse(const char* filein,const char* fileout);
/**Interfaz para ast y symtab*/
/*extern int generarSalidaHTML(const char* fileout);*/
/**Interfaz para colaerr*/
extern int generarSalidaError(const char* fileerr);
#endif
