/**@file mysqlmanager.c
   @author Erik Giron
   @brief definiciones de funciones de fscontent.h
*/

#include "mysqlmanager.h"
#include <string.h>
int check_db(const char* db,const char* host, const char* user, const char* password,MYSQL* mydb){
  //seteamos parametros de server
  //  mydb.host =(char*) host;
  //  mydb.user =(char*) user;
  // mydb.passwd = (char*) password;
  //mydb.db = (char*) malloc(sizeof(char) * strlen("fscontent")) + 1;
  //strcpy(mydb.db,"fscontent");
  //iniciamos libreria
  mysql_init(mydb);
  if(mysql_real_connect(mydb,host,user,password,db,0,NULL,0) != NULL){
    return 0;
  }
  fprintf(stderr,"\n\nERROR: Imposible conectar a base de datos, revise si escribio bien los \nparametros de conexion.\n");
  return -2;
}

int auto_check_db(MYSQL* mydb){
  return check_db("fscontent","localhost","fscontent",NULL,mydb);
}

void close_connection(MYSQL* mydb){
  mysql_close(mydb);
}


