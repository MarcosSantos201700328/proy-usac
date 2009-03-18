
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
#include "dataoperations.h"

metadata* settings_metadata;/**Configuracion de la base de datos*/
tablespace* tb;/**Posiciones de las tablas*/

///@todo terminar funcion de insertarTupla
int insertarTupla(linkedlist * datos,int tabla){
/*    registro *s = crearRegistro(datos,tabla);
    int pos;
    if(buscarIndice(s) == 0){ // Si la tupla no existe..
	if( ( pos = insertarRegistroDB(s) ) >= 0){
	    switch (tabla){ //agregamos indice segun tipo de tabla
		case T_AUTOR : 
		    insertarIndiceDir(pos,s);
		    insertarIndiceIndir(pos,s);	       
		    break;		
		case T_CONTENIDO : break;
		case T_LIBRO : break;
		case T_PRESTAMO : break;
		case T_TIPOUSUARIO : break;
		case T_TITULO : break;
		case T_USUARIO : break;
		case T_IMAGEN : break;
	    }
	    actualizarMetadata(pos,tabla); //actualizamos metadata
	    actualizarTablespace(pos,tabla); //actualizamos tablespace
	    agregarMsgLog(MSGT_INSERCION,pos,s); //agregamos log
	    free(s);	    
	    return 0;
	}	
	agregarErrorLog(MSGT_NOSPACE,tabla,datos);
	free(s);
	return -1;
    }
    agregarErrorLog(MSGT_DUPLICADO,tabla,datos);
    free(s);
*/    return -1;
}
/**Busca secuencialemente en archivo de indice y devuelve la posicion dentro del mismo*/
int buscarIndice(registro* s){
    FILE* diridxfile = NULL;
    int id = 0;
    indice tmpidx;
    int i = 0;
    if(s!=NULL){
	mensajeLog("Buscando indice...");
	switch(s->tipo){
	    case T_AUTOR:		
		id = s->dato.rAutor.id;		
		break;
            case T_TIPOUSUARIO:		
		id = s->dato.rTipoUsuario.id;		
		break;
	    case T_USUARIO:		
		id = s->dato.rUsuario.id;		
		break;
	    case T_LIBRO:		
		id = s->dato.rLibro.id;		
		break;
	    case T_TITULO:		
		id = s->dato.rTitulo.id;		
		break;
/*	    case T_CONTENIDO:		
		id = s->dato.rContenido.id;		
		break;
*/	    default:
		return ERR_NODATATYPE;
		break;
	}	
	if((diridxfile = fopen(FILE_DIRIDX,"rb"))!=NULL){
	    while(!feof(diridxfile)){
		if(!feof(diridxfile)){
		fread(&tmpidx,sizeof(indice),1,diridxfile);
		if(tmpidx.tipoclave == s->tipo && tmpidx.id == id){		 
		    fclose(diridxfile);
		    return i;
		}
		i++;
		}
	    }
	    fclose(diridxfile);
	    return ERR_NOEXIST;
	}	
	return ERR_NOFILE;
    }
    return ERR_NULLPTR;
}
/**inicializa settings_metadata en metadata*/
void initMetadata(){
    settings_metadata->inicio_bloque_indice_dir = 0;
    settings_metadata->inicio_bloque_indice_indir = 0;
    settings_metadata->inicio_bloque_tablespace = 0;
    settings_metadata->num_bloques_indice_dir = 0;
    settings_metadata->num_bloques_indice_indir=0;
    settings_metadata->num_bloques_tablespace = 0;
    settings_metadata->tam_crecimiento = 0;///< Tamano de superbloques
    settings_metadata->path_logfile[0] = 0;
    settings_metadata->path_history[0] = 0;
    settings_metadata->path_datafile[0] = 0;
    settings_metadata->path_tmpdir[0] = 0;
    settings_metadata->num_macrobloques = 0;
}
/**inicializa tablespace*/
void initTablespace(){
    settings_metadata->inicio_bloque_indice_dir = 0;
    settings_metadata->inicio_bloque_indice_indir = 0;
    settings_metadata->inicio_bloque_tablespace = 0;
    settings_metadata->num_bloques_indice_dir = 0;
    settings_metadata->num_bloques_indice_indir=0;
    settings_metadata->num_bloques_tablespace = 0;
    settings_metadata->tam_crecimiento = 0;///< Tamano de superbloques
    settings_metadata->path_logfile[0] = 0;
    settings_metadata->path_history[0] = 0;
    settings_metadata->path_datafile[0] = 0;
    settings_metadata->path_tmpdir[0] = 0;
    settings_metadata->num_macrobloques = 0;
}
/**Copia metadata*/
void setMetadata(metadata* m){
    if(m!=NULL){
	settings_metadata = m;
	//memcpy(&settings_metadata,m,sizeof(metadata));
    }
}

/**Copia tablespace*/
void setTablespace(tablespace* m){
    if(m!=NULL){
	tb = m;
	//memcpy(&tb,m,sizeof(tablespace));
    }
}
/**Inserta registro a archivo de base de datos*/
int insertarRegistroDB(registro* s){
    FILE* datafile;
    if(s!=NULL)  {
	switch(s->tipo){
	    case T_AUTOR:
		datafile = fopen(FILE_TBAUTOR,"a+b");
		break;		
	    case T_CONTENIDO:
		datafile = fopen(FILE_TBCONTENIDO,"a+b");
		break;
	    case T_LIBRO:
		datafile = fopen(FILE_TBLIBRO,"a+b");
		break;
	    case T_PRESTAMO:
		datafile = fopen(FILE_TBPRESTAMO,"a+b");
		break;
	    case T_TIPOUSUARIO:
		datafile = fopen(FILE_TBTIPOUSUARIO,"a+b");
		break;
	    case T_TITULO:
		datafile = fopen(FILE_TBTITULO,"a+b");
		break;
	    case T_USUARIO:
		datafile = fopen(FILE_TBUSUARIO,"a+b");
		break;	
	}
	if(datafile){
	    fwrite(s,sizeof(registro),1,datafile);
	    fclose(datafile);
	    return 0;
	}
	return ERR_NOFILE;
    }
    return ERR_NULLPTR;
}
/**Actualiza posiciones en tablespace dependiendo el tipo*/
int actualizarPosTablespace(int tipo){
	switch(tipo){
	    case T_AUTOR:
		return tb->tam_tb_autor++;		
	    case T_CONTENIDO:
		return tb->tam_tb_contenido++;		
	    case T_LIBRO:
		return tb->tam_tb_libro++;
	    case T_PRESTAMO:
		return tb->tam_tb_prestamo++;
	    case T_TIPOUSUARIO:
		return tb->tam_tb_tipousuario++;
	    case T_TITULO:
		return tb->tam_tb_titulo++;
	    case T_USUARIO:
		return tb->tam_tb_usuario++;
	    default:
		return ERR_NODATATYPE;
	}
}
/**Crea un nuevo indice segun el parametro*/
indice* crearIndice(unsigned int id, unsigned int tipoclave,int pos){
    indice* tmp = (indice*) malloc(sizeof(indice));    
    tmp->id = id;
    tmp->tipoclave = tipoclave;
    tmp->borrado = 0;    
    tmp->num_registro = pos;
    tmp->anterior = 0;
    tmp->siguiente = 0;
    if (tipoclave == T_AUTOR || tipoclave == T_TITULO) {/* para los datos que son cabeza de la lista
						       de indices indirectos*/

	tmp->esInicio = 1;
    }
    else
	tmp->esInicio = 0;
    return tmp;
}
/**Serializa un indice a archivo de indices*/
int guardarIndice(indice* idx){
    FILE* idxfile = fopen(FILE_DIRIDX,"a+b");
    if(idx!=NULL){
	if(idxfile){
	    fwrite(idx,sizeof(indice),1,idxfile);
	    fclose(idxfile);
	}
	return 0;
    }
    return ERR_NOFILE;
    
}
/**Crea un nuevo indice directo en archivo.*/
int insertarIndiceDir(int pos,registro* s){
    indice* idx = NULL;
    if(s!=NULL){
	switch(s->tipo){
	    case T_AUTOR:		
		idx = crearIndice(s->dato.rAutor.id,T_AUTOR,pos);
		break;
	    case T_LIBRO:		
		idx = crearIndice(s->dato.rLibro.id,T_LIBRO,pos);
		break;
	    case T_TITULO:		
		idx = crearIndice(s->dato.rTitulo.id,T_TITULO,pos);
		break;
	    case T_USUARIO:		
		idx = crearIndice(s->dato.rUsuario.id,T_USUARIO,pos);
		break;
	    case T_TIPOUSUARIO:		
		idx = crearIndice(s->dato.rTipoUsuario.id,T_TIPOUSUARIO,pos);
		break;
/*	    case T_CONTENIDO:		
		idx = crearIndice(s->dato.rContenido.id,T_CONTENIDO,pos);
		break;
*/
	    default:		
		return ERR_NODATATYPE;
		break;
	}
	guardarIndice(idx);
	free(idx);
	return 0;
    }
    return ERR_NULLPTR;
}

/**Actualizar posicion de archivos de indices en Metadata*/
void actualizarPosMetadata(int tipo){
    switch(tipo){
	    case T_AUTOR:		
		settings_metadata->num_bloques_indice_dir++;		
		break;
	    /*case T_CONTENIDO:
	       settings_metadata->num_bloques_indice_dir++;		*/
	    case T_PRESTAMO:
		settings_metadata->num_bloques_indice_dir++;	
		break;	
	    case T_TIPOUSUARIO:
		settings_metadata->num_bloques_indice_dir++;		
		break;
	    case T_TITULO:
		settings_metadata->num_bloques_indice_dir++;		
		break;
	    case T_USUARIO:
		settings_metadata->num_bloques_indice_dir++;		
		break;
	    case T_LIBRO:
		settings_metadata->num_bloques_indice_dir++;		
		//settings_metadata->num_bloques_indice_indir++;				
		break;
	}
}

/**Ingresa un nuevo autor*/
int insertarAutor(r_autor* dato){
    registro *s = crearRegistro((void*)dato,T_AUTOR);
    int pos = 0;
    int ret = -1;
    int indice = buscarIndice(s);
    if(indice < 0 || indice == ERR_NOEXIST || indice == ERR_NOFILE){ // Si la tupla no existe..
	if( ( insertarRegistroDB(s) ) >= 0){
	    pos = actualizarPosTablespace(s->tipo); //actualizamos posicion tablespace
	    insertarIndiceDir(pos,s);
            //insertarIndiceIndir(pos,s);	                   
	    actualizarPosMetadata(s->tipo); //actualizamos posicion metadata	    
agregarMsgLog(MSGS_INSERCION,pos,s); //agregamos log	
	    ret = 0;
	}
else
agregarErrorLog(MSGE_NOTENOUGHROOM,s);
    }
    else
agregarErrorLog(MSGE_DUPLICADO,s);
    free(s);
    return ret;
}   

/**Ingresa un nuevo libro*/
int insertarLibro(r_libro* dato){
    registro *s = crearRegistro((void*)dato,T_LIBRO);
    int pos = 0;
    int ret = -1;
    int indice = buscarIndice(s);
    if(indice < 0 || indice == ERR_NOEXIST || indice == ERR_NOFILE){ // Si la tupla no existe..
	if( ( insertarRegistroDB(s) ) >= 0){
	    pos = actualizarPosTablespace(s->tipo); //actualizamos posicion tablespace
	    insertarIndiceDir(pos,s);
            //insertarIndiceIndir(pos,s);	                   
	    actualizarPosMetadata(s->tipo); //actualizamos posicion metadata	    
agregarMsgLog(MSGS_INSERCION,pos,s); //agregamos log	
	    ret = 0;
	}
else
agregarErrorLog(MSGE_NOTENOUGHROOM,s);
    }
    else
agregarErrorLog(MSGE_DUPLICADO,s);
    free(s);
    return ret;
}   

/**Ingresa un nuevo contenido*/
int insertarContenido(r_contenido* dato){
    registro *s = crearRegistro((void*)dato,T_CONTENIDO);
    int pos = 0;
    int ret = -1;
    int indice = buscarIndice(s);
    if(indice < 0 || indice == ERR_NOEXIST || indice == ERR_NOFILE){ // Si la tupla no existe..
	if( ( insertarRegistroDB(s) ) >= 0){
	    pos = actualizarPosTablespace(s->tipo); //actualizamos posicion tablespace
	    insertarIndiceDir(pos,s);
            //insertarIndiceIndir(pos,s);	                   
	    actualizarPosMetadata(s->tipo); //actualizamos posicion metadata	    
agregarMsgLog(MSGS_INSERCION,pos,s); //agregamos log	
	    ret = 0;
	}
else
agregarErrorLog(MSGE_NOTENOUGHROOM,s);
    }
    else
agregarErrorLog(MSGE_DUPLICADO,s);
    free(s);
    return ret;
}   
/**Ingresa un nuevo prestamo*/
int insertarPrestamo(r_prestamo* dato){
    registro *s = crearRegistro((void*)dato,T_PRESTAMO);
    int pos = 0;
    int ret = -1;
    int indice = buscarIndice(s);
    if(indice < 0 || indice == ERR_NOEXIST || indice == ERR_NOFILE){ // Si la tupla no existe..
	if( ( insertarRegistroDB(s) ) >= 0){
	    pos = actualizarPosTablespace(s->tipo); //actualizamos posicion tablespace
	    insertarIndiceDir(pos,s);
            //insertarIndiceIndir(pos,s);	                   
	    actualizarPosMetadata(s->tipo); //actualizamos posicion metadata	    
agregarMsgLog(MSGS_INSERCION,pos,s); //agregamos log	
	    ret = 0;
	}
else
agregarErrorLog(MSGE_NOTENOUGHROOM,s);
    }
    else
agregarErrorLog(MSGE_DUPLICADO,s);
    free(s);
    return ret;
}   

/**Ingresa un nuevo tipousuario*/
int insertarTipoUsuario(r_tipousuario* dato){
    registro *s = crearRegistro((void*)dato,T_TIPOUSUARIO);
    int pos = 0;
    int ret = -1;
    int indice = buscarIndice(s);
    if(indice < 0 || indice == ERR_NOEXIST || indice == ERR_NOFILE){ // Si la tupla no existe..
	if( ( insertarRegistroDB(s) ) >= 0){
	    pos = actualizarPosTablespace(s->tipo); //actualizamos posicion tablespace
	    insertarIndiceDir(pos,s);
            //insertarIndiceIndir(pos,s);	                   
	    actualizarPosMetadata(s->tipo); //actualizamos posicion metadata	    
agregarMsgLog(MSGS_INSERCION,pos,s); //agregamos log	
	    ret = 0;
	}
else
agregarErrorLog(MSGE_NOTENOUGHROOM,s);
    }
    else
agregarErrorLog(MSGE_DUPLICADO,s);
    free(s);
    return ret;
}   

/**Ingresa un nuevo titulo*/
int insertarTitulo(r_titulo* dato){
    registro *s = crearRegistro((void*)dato,T_TITULO);
    int pos = 0;
    int ret = -1;
    int indice = buscarIndice(s);
    if(indice < 0 || indice == ERR_NOEXIST || indice == ERR_NOFILE){ // Si la tupla no existe..
	if( ( insertarRegistroDB(s) ) >= 0){
	    pos = actualizarPosTablespace(s->tipo); //actualizamos posicion tablespace
	    insertarIndiceDir(pos,s);
            //insertarIndiceIndir(pos,s);	                   
	    actualizarPosMetadata(s->tipo); //actualizamos posicion metadata	    
agregarMsgLog(MSGS_INSERCION,pos,s); //agregamos log	
	    ret = 0;
	}
else
agregarErrorLog(MSGE_NOTENOUGHROOM,s);
    }
    else
agregarErrorLog(MSGE_DUPLICADO,s);
    free(s);
    return ret;
}   

/**Ingresa un nuevo usuario*/
int insertarUsuario(r_usuario* dato){
    registro *s = crearRegistro((void*)dato,T_USUARIO);
    int pos = 0;
    int ret = -1;
    int indice = buscarIndice(s);
    if(indice < 0 || indice == ERR_NOEXIST || indice == ERR_NOFILE){ // Si la tupla no existe..
	if( ( insertarRegistroDB(s) ) >= 0){
	    pos = actualizarPosTablespace(s->tipo); //actualizamos posicion tablespace
	    insertarIndiceDir(pos,s);
            //insertarIndiceIndir(pos,s);	                   
	    actualizarPosMetadata(s->tipo); //actualizamos posicion metadata	    
agregarMsgLog(MSGS_INSERCION,pos,s); //agregamos log	
	    ret = 0;
	}
else
agregarErrorLog(MSGE_NOTENOUGHROOM,s);
    }
    else
agregarErrorLog(MSGE_DUPLICADO,s);
    free(s);
    return ret;
}   

registro* leerRegistro(int numregistro, int tipo){
    FILE* in;
    registro* tmpreg = (registro*) malloc(sizeof(registro));
    switch(tipo){
	    case T_AUTOR:		
		in = fopen(FILE_TBAUTOR,"rb");		
		break;
	    /*case T_CONTENIDO:
	       settings_metadata->num_bloques_indice_dir++;		*/
	    case T_PRESTAMO:
		in = fopen(FILE_TBPRESTAMO,"rb");		
		break;	
	    case T_TIPOUSUARIO:
		in = fopen(FILE_TBTIPOUSUARIO,"rb");		
		break;
	    case T_TITULO:
		in = fopen(FILE_TBTITULO,"rb");		
		break;
	    case T_USUARIO:
		in = fopen(FILE_TBUSUARIO,"rb");		
		break;
	    case T_LIBRO:
		in = fopen(FILE_TBLIBRO,"rb");		
		//settings_metadata->num_bloques_indice_indir++;				
		break;
    }
    if(in!=NULL){
	if(fseek(in,sizeof(registro)*numregistro,SEEK_SET)==0){
	   fread(tmpreg,sizeof(registro),1,in);	   
	   return tmpreg;
	}
    }
    return NULL;
}	
