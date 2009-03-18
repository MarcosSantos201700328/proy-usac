/** @file fscontent.h
@brief Definicion de las estructuras y funciones principales del proyecto
@author Erik Giron
*/
#ifndef FSCONTENT_H
#define FSCONTENT_H

#ifdef __cplusplus
extern "C" {
#endif


#include <ext2fs/ext2fs.h>
#include <unistd.h>
#include <sys/types.h>

#include "mysqlmanager.h"
#include "session.h"
 
  void check_permissions();///<chequea que usuario root ejecute la aplicacion
  int ismounted(const char *);///<verifica la particion y la abre si es posible
  int gather_info(MYSQL*,const char*);///<recupera informacion de la particion
  int open_fs(const char*,ext2_filsys*); ///<abre particion y la almacena en estructura
  int get_particion(MYSQL*,sesion* , ext2_filsys);///<obtiene particion y la almacena en base de datos
  /**Almacena datos de particion en base de datos*/
  int guardar_particion(MYSQL* mydb,char* n, int flag, unsigned int bz,int fz, int gdc, ulong db,int ibpg, int numsession);
  int get_descriptores(MYSQL*,sesion* , ext2_filsys);///<obtiene descriptores de grupo de particion y las almacena en la base de datos y la almacena en base de datos
  int guardar_descriptor(MYSQL*,int,int,struct ext2_group_desc);///<almacena a DB el descriptor dado
  /*  int get_inodos_usados_por_grupo(int grupo,int id_grupo, ext2_filsys fs, int session_id);*/
  int get_inodos_usados_por_grupo(MYSQL* mydb,sesion* actual, ext2_filsys fs);///<busca inodos usados por grupos de bloques(con por lo menos un enlace) para almacenarlos en DB
  int get_id_grupo(int grupo, ext2_filsys fs, int session_id);///<obtiene id_grupo de la base de datos segun los parametros dados
  //  int guardar_inodo_usado(int grupo,int sesion,struct ext2_inode*,char* path,int esdir);///<almacena en DB el inodo dado
  int guardar_inodo_usado(MYSQL* mydb,int num_sesion,int num_grupo,int num_inodo,struct ext2_inode inodo,int es_dir);///<almacena en DB el inodo usado dado
  int guardar_inodo_libre(MYSQL* mydb,int num_sesion,int num_grupo,int num_inodo,struct ext2_inode inodo,int es_dir);///<almacena en DB el inodo libre dado
  int get_superbloque(MYSQL* mydb,sesion* s,  ext2_filsys fs);///<obtiene superbloque del sistema de archivos dado
  int guardar_superbloque(MYSQL* mydb, int num_sesion, struct ext2_super_block super);///< Almacena superbloque dado a la base de datos
  int get_bitmaps(MYSQL* mydb,sesion* s, ext2_filsys fs);///<obtiene mapas de bits de bloques e inodos
  int guardar_bitmap(MYSQL* mydb,  int num_sesion,  struct ext2fs_struct_generic_bitmap *bmp,  int tipo);///< Almacena mapas de bits a la base de datos
  int guardar_sesion(MYSQL* mydb,sesion* actual);///<Almacena sesion a base de datos
  void print_session(sesion* actual);///<imprime sesion actual a pantalla
  
#ifdef __cplusplus
}
#endif
#endif
