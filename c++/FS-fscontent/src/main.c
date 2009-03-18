/** @file main.c
@brief Punto de entrada del programa.
@author Erik Giron
*/
/**
@todo
    - obtener datos de filesystem
      - filesys
      - superbloque
      - descriptores
      - bitmap de inodos
      - bitmap de bloques
      - inodos
      
*/
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <ext2fs/ext2fs.h>
#include "fscontent.h"
#include "mysqlmanager.h"

/** main
Sinopsis
argv[1]: particion
argv[2]: base de datos
argv[3]: host
argv[4]: usuario mysql
argv[5]: password mysql
*/

//#define DEBUG

int main(int argc, char *argv[]){      
  MYSQL mydb;
  int check_db_er_t;
#ifndef DEBUG
  if(argc >= 5){
#endif
    check_permissions();//verifica permisos de usuario
    ismounted(argv[1]);//verifica si esta montado la particion
    
#ifdef DEBUG
    check_db_er_t = auto_check_db(&mydb);
#else
    if (argv[5] == 0)
      check_db_er_t = check_db(argv[2],argv[3],argv[4],NULL,&mydb);    
    else
      check_db_er_t = check_db(argv[2],argv[3],argv[4],argv[5],&mydb);
#endif
    if(/*auto_check_db(&mydb) == 0*/ check_db_er_t == 0)//conecta a DB.    
      {
	/**recopilacion de datos*/
	gather_info(&mydb,argv[1]);//recupera informacion de la particion
	return EXIT_SUCCESS;
      }
    return -1;
#ifndef DEBUG
  }
  fprintf(stdout,"\n\nfscontent (c) 2006 Erik Giron (C#200313492)\n\n\n");
  fprintf(stdout,"Uso:\n");
  fprintf(stdout,"fscontent <particion> <db> <host_db> <usuario_db> [password_db]\n\n");
  fprintf(stdout,"Donde:\n");
  fprintf(stdout,"<particion>: Particion en formato ext2 (e.g. /dev/hda1).\n");
  fprintf(stdout,"<db>: Nombre de la base de datos que se usara.\n");
  fprintf(stdout,"<host_db>: Maquina hacia donde se encuentra la base de datos\n\t(localhost o algun ip).\n");
  fprintf(stdout,"<usuario_db>: Usuario de la DB con permisos de ejecutar la \n\tsentencia INSERT y SELECT.\n");
  fprintf(stdout,"[password_db]: Password del usuario para conexion a base de datos,\nno obligatorio.\n");
  fprintf(stdout,"\n\n");
#endif
  return EXIT_SUCCESS;
}
