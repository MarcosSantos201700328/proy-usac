/**@file fscontent.c
   @author Erik Giron
   @brief definiciones de funciones de fscontent.h
*/
#define MSG_STORING_INODES printf("Guardando inodos a la base de datos (esta operacion puede tardar)...");
#define MSG_STORING_FS fprintf(stdout,"Guardando sistema de archivos a la base de datos...");
#define MSG_STORING_GD fprintf(stdout,"Guardando descriptores a la base de datos ...");
#define MSG_STORING_SB fprintf(stdout,"Guardando superbloque a la base de datos ...");
#define MSG_STORING_BMP_BLOCK fprintf(stdout,"Guardando mapas de bits a la base de datos...");
#define MSG_STORING_BMP_INODE fprintf(stdout,"Guardando mapas de bits a la base de datos...");
#define MSG_STORING_SESS fprintf(stdout,"Guardando sesion a la base de datos...");

#define MSG_DONE fprintf(stdout," [hecho]\n");


#include "fscontent.h"

/**@brief Continua la ejecucion si usuario es root.*/
void check_permissions(){
  __uid_t usuario = getuid();
  if(usuario != 0){
    fprintf(stderr,"Error: Usted no esta ejecutando esta aplicacion como root,\nasegurese que tiene permisos de superusuario para ejecutar esta aplicacion\n");
    exit(1);
  }
}

/** Verifica si esta montada la unidad dada e imprime un mensaje
 @param devpath Especifica el path del dispositivo por bloques a verificar*/
int ismounted(const char* devpath){
  int ismounted; /**Parametro para ver si esta montado*/
  ext2fs_check_if_mounted(devpath,&ismounted);/**Revisa si esta montado usando funcion de libext2fs*/
  printf("verificando si esta montada la unidad...\n");
  /*Rutina para ver si la unidad esta montada*/
  if(ismounted == 1)
    printf("\tActualmente la unidad esta montada\n");  
  else if (ismounted == 0)
    printf("\tActualmente la unidad esta desmontada\n");  
  else
    printf("\tImposible averiguar si esta montado el disco... verifique si tiene permisos\n");
  return ismounted;
}

/*  OPEN_FS */
int open_fs(const char* filename,ext2_filsys* fs){
  return ext2fs_open(filename,0,0,0,unix_io_manager,fs);
}
/* GATHER_INFO */
int gather_info(MYSQL* mydb,const char* device){
  sesion sesion_actual; ///<session
  ext2_filsys fs;       ///<sistema de archivos en cuestion 
  int ret = -1;
  /**inicio de sesion*/
  iniciar_sesion(device,&sesion_actual);

  /**Recuperacion y almacenamiento de sistema de archivos a db*/
  if(open_fs(device,&fs) == 0){
    get_particion(mydb,&sesion_actual,fs);    
    get_descriptores(mydb,&sesion_actual,fs);    
    get_superbloque(mydb,&sesion_actual,fs);
    get_inodos_usados_por_grupo(mydb,&sesion_actual,fs);///<busca inodos usados (con por lo menos un enlace) para almacenarlos en DB
    get_bitmaps(mydb,&sesion_actual,fs);    
    
    ret = 0;
  }
  /**cierre de sesion*/
  cerrar_sesion(&sesion_actual);
  guardar_sesion(mydb,&sesion_actual);
  print_session(&sesion_actual);
  /**almacenamiento de sesion a DB*/
  ///@todo  guardar_sesion(&sesion_actual,mydb);//recupera informacion de la particion
  return ret;

}

int get_particion(MYSQL*
		  mydb,sesion* s,
		  ext2_filsys fs){
  /**Almacenamos datos*/
  MSG_STORING_FS;
  guardar_particion(mydb,fs->device_name,fs->flags,
			   fs->blocksize,fs->fragsize,
			   fs->group_desc_count,fs->desc_blocks,
			   fs->inode_blocks_per_group,
			   s->inicio);
  MSG_DONE;
  /**Aumentamos contadores*/
  s->inserciones++;  
  s->elementos++;
  return 0;
}

int guardar_particion(MYSQL* mydb,
		      char* n, 
		      int flag, 
		      unsigned int bz,
		      int fz, 
		      int gdc, 
		      ulong db,
		      int ibpg, 
		      int numsession)
{
  char query[512];
  query[0] = 0;
  
  sprintf(query,"INSERT INTO `particion` ( `SESSION_ID` , `DISPOSITIVO` , `BANDERAS` , `TAM_BLOQUE` , `TAM_FRAGMENTO` , `NUM_DESCRIPTORES` , `BLOQUES_DESC` , `INODOS_POR_GRUPO` )\nVALUES (\'%d\', \'%s\', \'%d\', \'%d\', \'%d\', \'%d\', \'%ld\', \'%d\'\n);",
	  numsession,n,flag,bz,fz,gdc,db,ibpg);
  mysql_query(mydb,query);
  //  fprintf(stdout,"Query: %s \n Resultado:%s\n\n",query,mysql_info(mydb));  
  return 0;
  
}

int get_descriptores(MYSQL* mydb,
		     sesion* sesion_actual, 
		     ext2_filsys fs){
  int i;
  //  int id_grupo;
  MSG_STORING_GD;
  for (i = 0; i < fs->group_desc_count; i++){
    /**->check!!*/guardar_descriptor(mydb,sesion_actual->inicio, i,(*(fs->group_desc + i)) );
    ///@todoid_grupo = get_id_grupo(i,fs, session_id);//<obtenemos id unico desde la base de datos para relacionarlo con inodos en base de datos
    (sesion_actual->inserciones)++;
    (sesion_actual->elementos)++;
  }
  MSG_DONE;
  return 0;
}

int guardar_descriptor(MYSQL* mydb,
		       int id_session ,
		       int num_grupo,
		       struct ext2_group_desc desc){
  char query[512];
  query[0] = 0;
  
  sprintf(query,"INSERT INTO `descriptor`(`ID_SESION` , `NUM_GRUPO`, `INICIO_BITMAP_INODO`, `INICIO_BITMAP_BLOQUE`, `TABLA_INODOS` ,`BLOQUES_LIBRES` , `INODOS_LIBRES` , `DIR_USADOS` , `RELLENO` )\nVALUES (\'%d\',\'%d\',\'%d\',\'%d\',\'%d\',\'%d\',\'%d\',\'%d\',\'%d\');",
	  id_session,
	  num_grupo,
	  desc.bg_inode_bitmap,
	  desc.bg_block_bitmap,
	  desc.bg_inode_table,	  
	  desc.bg_free_blocks_count,
	  desc.bg_free_inodes_count,
	  desc.bg_used_dirs_count,
	  desc.bg_pad);
  mysql_query(mydb,query);
  //  fprintf(stdout,"Query: %s \n Resultado:%s\n\n",query,mysql_info(mydb));  
  return 0;
}

/* int get_inodos_usados_por_grupo(int grupo,int id_grupo, ext2_filsys fs, int session_id){ */
/*   /\**definimos cotas*\/ */
/*   int inicio = fs->group_desc[grupo].bg_inode_bitmap; */
/*   int fin = inicio + EXT2_INODES_PER_GROUP(fs->super);//(fs->inode_blocks_per_group); */
/*   int actual; */
/*   /\**estructuras*\/ */
/*   struct ext2_inode tmp; */
/*   int esdir = 0; */
/*   char * path; */
/*   /\**leemos todos los inodos del descriptor*\/ */
/*   for(actual = inicio; actual < fin; actual++){ */
    
/*     if(ext2fs_read_inode(fs,actual,&tmp)==0){ */
/*       if(tmp.i_links_count > 0){// si el inodo pertenece a un archivo */
/* 	if(ext2fs_check_directory(fs,actual) == 0)//si es directorio */
/* 	  esdir=1; */
/* 	else{ */
/* 	  esdir = 0; */
/* 	  ext2fs_get_pathname(fs,2,actual,&path);	   */
/* 	} */
/* 	///@todo	guardar_inodo_usado(grupo,sesion,&tmp,path,esdir); */
/* 	//	path[0] = 0 */
/* 	} */
/*       }       */
/*     } */
/*   return 0; */
/* } */

int get_inodos_usados_por_grupo(MYSQL* mydb,sesion* actual, ext2_filsys fs)
{
  ext2_inode_scan is;
  struct ext2_inode inodo;
  unsigned int num_inodo;
  int esdir = 0;
  char * path;

  int i,j;
  MSG_STORING_INODES;
  usleep(500);
  if(ext2fs_open_inode_scan(fs,0,&is) == 0){/**abrimos scan*/

    for(i = 0; i < (fs->group_desc_count);i++){/**para todo descriptor en fs...*/
      for(j = 0; j < ( EXT2_INODES_PER_GROUP(fs->super)); j++){/**para todo inodo en descriptor*/
	if(ext2fs_get_next_inode(is,&num_inodo,&inodo)== 0){
	  if(inodo.i_links_count > 0){// si el inodo esta ocupado por un archivo
	    if(ext2fs_check_directory(fs,num_inodo) == 0)//si es directorio
	      esdir=1;
	    else{
	      esdir = 0;
	      /**@TODO
		 ext2fs_get_pathname(fs,2,num_inodo,&path);	  
	      */
	    }	    
	    /*ALMACENAMOS EN DB*/
	    guardar_inodo_usado(mydb,actual->inicio,i,num_inodo,inodo,esdir);
	    /*AUMENTAMOS INSERCIONES*/
	    actual->inserciones++;
	    //	path[0] = 0
	  }
	  else{
	    guardar_inodo_libre(mydb,actual->inicio,i,num_inodo,inodo,esdir);
	    /*AUMENTAMOS INSERCIONES*/
	    actual->inserciones++;
	    //	path[0] = 0

	  }
	  /*AUMENTAMOS ELEMENTOS ENCONTRADOS*/
	  actual->elementos++;	
	}
      } 
    }     
    ext2fs_close_inode_scan(is);
    MSG_DONE;
  }
  return 0;
}

int guardar_inodo_usado(MYSQL* mydb,
			int num_sesion,
			int num_grupo,
			int num_inodo,
			struct ext2_inode inodo,
			int es_dir){
  char query[1024];
  query[0] = 0;
  
  sprintf(query,"INSERT INTO `inodo` (`NUM_INODO`, `USUARIO` , `MODO` , `TAM` , `ACCESADO` , `CREADO` , `MODIFICADO` , `GRUPO` , `NUM_ENLACES` , `NUM_BLOQUES` , `BANDERA` , `BORRADO` , `NUM_GRUPO` , `ID_SESION` , `ES_DIRECTORIO` ) VALUES ( \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\');",
	  num_inodo,
	  inodo.i_uid,
	  inodo.i_mode,
	  inodo.i_size,
	  inodo.i_atime,
	  inodo.i_ctime,
	  inodo.i_mtime,
	  inodo.i_gid,
	  inodo.i_links_count,
	  inodo.i_blocks,
	  inodo.i_flags,
	  inodo.i_dtime,
	  num_grupo,
	  num_sesion,
	  es_dir
	  );
  mysql_query(mydb,query);
  //  fprintf(stdout,"Query: %s \n Resultado:%s\n\n",query,mysql_info(mydb));  
  return 0;

}
int guardar_inodo_libre(MYSQL* mydb,
			int num_sesion,
			int num_grupo,
			int num_inodo,
			struct ext2_inode inodo,
			int es_dir){
  char query[1024];
  query[0] = 0;
  
  sprintf(query,"INSERT INTO `inodo` (`NUM_INODO`, `NUM_ENLACES` , `NUM_GRUPO` , `ID_SESION` , `ES_DIRECTORIO` ) VALUES ( \'%d\', \'%d\', \'%d\', \'%d\', \'%d\');",
	  num_inodo,
	  inodo.i_links_count,
	  num_grupo,
	  num_sesion,
	  es_dir
	  );
  mysql_query(mydb,query);
  //  fprintf(stdout,"Query: %s \n Resultado:%s\n\n",query,mysql_info(mydb));  
  return 0;

}

int get_superbloque(MYSQL*
		  mydb,sesion* s,
		  ext2_filsys fs){
  s->elementos++;
  s->inserciones++;
  MSG_STORING_SB;
  return guardar_superbloque(mydb,s->inicio,*(fs->super));
}

int guardar_superbloque(MYSQL* mydb, int num_sesion, struct ext2_super_block super){
  char query[4096];
  query[0] = 0;
  
  sprintf(query,"INSERT INTO `superbloque` (`NUM_INODOS` , `NUM_BLOQUES` , `NUM_BLOQUES_RES` , `NUM_BLOQUES_LIBRES` , `NUM_INODOS_LIBRES` , `PRIMER_BLOQUE_DATOS` , `TAM_BLOQUES` , `TAM_FRAGMENTO` , `BLOQUES_POR_GRUPO` , `FRAGMENTOS_POR_GRUPO` , `INODOS_POR_GRUPO` , `MONTADO_EL` , `ESCRITO_EL` , `VECES_MONTADO` , `MAX_VECES_MONTADO` , `MAGIC` , `ESTADO` , `COMPORT_ERROR` , `REVISION_MENOR` , `ULTIMO_FSCK` , `INTERVALO_FSCK` , `SISTEMA_OPERATIVO` , `REVISION` , `USUARIO_BLOQUES_RES` , `GRUPO_BLOQUES_RES` , `DIR_MONTAJE` , `SESSION_ID` ) VALUES ( \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%d\', \'%s\', \'%d\');",
	  super.s_inodes_count,
	  super.s_blocks_count,
	  super.s_r_blocks_count,
	  super.s_free_blocks_count,
	  super.s_free_inodes_count,
	  super.s_first_data_block,
	  super.s_log_block_size,
	  super.s_log_frag_size,
	  super.s_blocks_per_group,
	  super.s_frags_per_group,
	  super.s_inodes_per_group,
	  super.s_mtime,
	  super.s_wtime,
	  super.s_mnt_count,
	  super.s_max_mnt_count,
	  super.s_magic,
	  super.s_state,
	  super.s_errors,
	  super.s_minor_rev_level,
	  super.s_lastcheck,
	  super.s_checkinterval,
	  super.s_creator_os,
	  super.s_rev_level,
	  super.s_def_resuid,
	  super.s_def_resgid,
	  super.s_last_mounted,
	  num_sesion	  
	  );
  mysql_query(mydb,query);
  MSG_DONE;
  //  fprintf(stdout,"Query: %s \n Resultado:%s\n\n",query,mysql_info(mydb));  
  return 0;
}

int get_bitmaps(MYSQL* mydb,sesion* s, ext2_filsys fs){
  if(ext2fs_read_bitmaps(fs)==0){
    MSG_STORING_BMP_BLOCK;
    guardar_bitmap(mydb,s->inicio,fs->block_map,0); 
    MSG_DONE;
    MSG_STORING_BMP_INODE;
    guardar_bitmap(mydb,s->inicio,fs->inode_map,1); 
    MSG_DONE;
    s->elementos+=2;
    s->inserciones+=2;
    return 0;
  }
  return -1;
}

int guardar_bitmap(MYSQL* mydb, 
		   int num_sesion, 
		   struct ext2fs_struct_generic_bitmap *bmp,
		   int tipo){
  char query[131072];  
  query[0] = 0;
  sprintf(query," INSERT INTO `bitmap` ( `MAGIC` , `DESCRIPCION` , `ID_SESION` , `INICIO` , `FIN` , `FIN_REAL` , `BITMAP` , `CODIGO_ERROR` , `TIPO` ) VALUES ( '\%d\', \'%s\', \'%d\', \'%d\', \'%d\', \'%d\',\'%050000s\','%d', '%d');",
	  bmp->magic,
	  bmp->description,
	  num_sesion,
	  bmp->start,
	  bmp->end,
	  bmp->real_end,
	  bmp->bitmap,
	  bmp->base_error_code,
	  tipo	  
	  );
  mysql_query(mydb,query);
  //  fprintf(stdout,"\n Resultado:%s\n\n",mysql_info(mydb));  
  return 0;

}
		   
int guardar_sesion(MYSQL* mydb,sesion* actual){
  char query[512];
  query[0] = 0;
  MSG_STORING_SESS;
  sprintf(query,"INSERT INTO `sesion`(`ID` , `PARTICION`, `TIEMPO_ANALISIS`, `NUM_ELEMENTOS`, `NUM_INSERCIONES` )\nVALUES (\'%d\',\'%s\',\'%d\',\'%d\',\'%d\');",
	  actual->inicio,
	  actual->particion,
	  (actual->fin)-(actual->inicio),
	  actual->elementos,
	  actual->inserciones
	  );
  
  mysql_query(mydb,query);
  //fprintf(stdout,"Query: %s \n Resultado:%s\n\n",query,mysql_info(mydb));  
  MSG_DONE;

  return 0;
}

void print_session(sesion* actual){
  fprintf(stdout,"Se encontraron %d elementos y se hicieron %d inserciones en %d segundos\n\n",
	  actual->elementos,actual->inserciones,(actual->fin)-(actual->inicio));
}
