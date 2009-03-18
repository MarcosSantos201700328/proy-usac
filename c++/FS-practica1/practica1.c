#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ext2fs/ext2fs.h> /**Librerias de Ext2*/


/*int buscarEnDirectorio(ext2_dir_entry*, int, int, char*, void* );

*/
ext2_filsys fs = NULL;
ext2_ino_t dir,cwd;




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

/**Busca recursivamente dentro de los directorios*/
/* int buscarEnDirectorio(ext2_dir_entry *dirent, int offset,  */
/* 		       int blocksize, char* buffer, void *private){ */
/*     int encontrado = 0; */
/*   int ret_inode_number = 0; */

/*   if ( ext2fs_check_directory (fs, dirent->inode)== 0){ /\**Si inode es directorio*\/ */
/*     ext2fs_dir_iterate( fs,dirent->dir,0,buffer,&buscarEnDirectorio,NULL); /\**Buscamos en directorios consecuentes*\/ */
/*     if (/\*ext2fs_namei_follow (fs, 2, 2, argv[2], &ret_inode_number)*\/ */
/* 	ext2fs_lookup(fs, 2, filename, strlen(filename), buffer, &ret_inode_number)!= EXT2_ET_FILE_NOT_FOUND)/\*buscamos nombre de archivo*\/{       */
/*       printf("Archivo encontrado en inode %d\n", ret_inode_number); */
/*       return ret_inode_number; */
/*     }     */
/*     else{ */
/*       return -1; */
     
/*     } */
    
/*   } */
/* } */



/***/
int buscarArchivo(const char* devpath, const char* filename){
  char *buffer = NULL;
  //  cwd = 2;
  /**Directorio*/
  //  ext2_dir_entry root;
  //  root.inode = 2;
  unsigned int retinode = 0;
  /**Buffer para cache*/
  buffer = (char*) malloc(fs->blocksize); /**Asignamos el tamano de bloque a buffer*/
  if( ext2fs_lookup(fs, 2, filename, strlen(filename), buffer, &retinode)!= EXT2_ET_FILE_NOT_FOUND)
     //*buscarEnDirectorio(&root, 0, 0, buffer,NULL)/*) != -1)*/{
    printf("Archivo encontrado en inode %d",retinode);
  //  }
  else
    printf("Archivo no encontrado\n");
  free(buffer);       
  return 0;
}


/**Main*/
int main(int argc, char* argv[]){

  printf("\n\nPractica 1 de Manejo e implementacion de Archivos\n");
  printf("Por: Erik Vladimir Giron Marquez, C# 200313492\n");
  printf("Facultad de Ingenieria, USAC");
  printf(" Agosto de 2006\n");  

  if (argc > 1){
    ismounted(argv[1]); /*verifica si esta montada*/
    if( ext2fs_open(argv[1],EXT2_FLAG_FORCE , 0, 0 ,unix_io_manager, &fs) == 0){
      printf("Sistema de archivos abierto correctamente\n");
      printf("Tamano de bloques: %d\n",fs->blocksize);
      printf("Nombre de imagen:%s \n",fs->device_name);
      printf("Numero magico: %d\n\n",fs->magic);
      buscarArchivo(argv[1],argv[2]);
      
    }
    else
      printf("Imposible abrir: Necesita permisos de superusuario para abrir la particion\n");
    
  }
  else{
    printf("\n\nUso: practica1 [dispositivo] [filename_a_buscar]\n");
    printf("\tEjemplo: practica1 /dev/hda10 archivo.txt\n\n\n");
  }
}

