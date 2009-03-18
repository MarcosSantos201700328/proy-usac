/** @file mysqlmanager.h
 Manejador de DB, incluye funciones para validacion,e insercion, a la base Mysql
@author Erik Giron 
*/
#ifndef MYSQLMANAGER_H
#define MYSQLMANAGER_H
#include <stdio.h>
#include <stdlib.h>
//#include <mysql/my_global.h>
#include <mysql/mysql.h>

#define DEFAULT_HOST "localhost"



int check_db(const char*,const char*,const char*,const char*,MYSQL* mydb);///<conecta a DB.
int auto_check_db(MYSQL* mydb);///<conecta automaticamente a la base de datos, usado solo para debug
void close_connection(MYSQL* mydb);///<cierra la conexion a la DB

#endif
