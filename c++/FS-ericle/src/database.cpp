/**
@file archivo.cpp
@brief Implementacion de [archivo].h
@author Erik Giron (C#200313492)
@todo TODO:crear interfaz para indices
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
#include "database.h"
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include "logger.h"



extern int inputparse(const char*);
//extern void setMetadata(metadata* d);
//extern void setTablespace(tablespace* t);

database::database()
{    
    inicializar();
//    leerConfig();
    leerMetadata(); //leemos metadata
    cargarIndices();  //leemos indices
    leerTablespace();//leemos tablespace
    cargarUsuarios();//cargamos usuarios a memoria para hacerles hashing
    setMetadata(config);
    setTablespace(config_tb);    
    iniciarLogFile(config->path_history);
    mensajeLog("Inicializando motor de base de datos...");
//    separar();//separamos archivos
}


database::~database()
{
    finalizar();
    
    free(config);free(config_tb);
}
void database::finalizar(){
    fusionar();
    guardarMetadata();
    guardarIndices();
    guardarTablespace();
    guardarConfig();
    finalizarLogFile();
//    ertmp();
}
bool database::inicializar(){   
    //this->ConfigFilename = "~/";
    //char* logname = (char*)getlogin();
    
    config = (metadata*) malloc(sizeof(metadata));
    config_tb = (tablespace*) malloc(sizeof(tablespace));
    this->ConfigFilename+= (char *)getenv("HOME");
    //this->ConfigFilename+= logname;
    this->ConfigFilename+= '/';
    this->ConfigFilename+= FILE_CONFIG;
    setDefaults();//Asignamos valores por defecto a metadata
    return true;
}

void database::setDefaults(){
    char dirhome[255];
    //seteamos metadata
    strcpy(dirhome,(char *)getenv("HOME"));    
    strcat(dirhome,"/");
    config->tam_crecimiento = 0;///< Tamano de superbloques
    strncpy(config->path_history,dirhome,254);
    strncpy(config->path_datafile,dirhome,254);
    strncpy(config->path_tmpdir,dirhome,254);
    config->estaGuardado = 0;
    config->inicio_bloque_indice_dir = 0;
    config->inicio_bloque_indice_indir = 0;
    config->inicio_bloque_tablespace = 0;
    config->num_bloques_indice_dir = 0;
    config->num_bloques_indice_indir = 0;
    config->num_bloques_tablespace = 0;
    config->tam_crecimiento = 0;
    config->num_macrobloques = 0;    
    //seteamos tablespace
    config_tb->tam_tb_autor = 0;
    config_tb->tam_tb_titulo = 0;
    config_tb->tam_tb_contenido = 0;
    config_tb->tam_tb_libro = 0;
    config_tb->tam_tb_usuario = 0;
    config_tb->tam_tb_prestamo = 0;
    config_tb->tam_tb_tipousuario = 0;
    //seteamos a motor de dataoperations
    //setMetadata(config); 
    //setTablespace(config_tb);
    mensajeLog("Aplicando valores por defecto al motor...");
    
    
}

void database::setConfigFilename(QString filename){
    ConfigFilename = filename + "/biblio.conf";
}

void database::setConfigFilename(char* filename){
    ConfigFilename = filename;
}

QString& database::getConfigFilename(){
    return ConfigFilename;
}


metadata* database::getConfig(){
    return config;
}

void database::setConfig(metadata* data){
    config = data;
    /*if(data != NULL){
	memcpy(&config,data,sizeof(metadata));
    }*/
}

bool database::guardarConfig(){
    FILE* cfg = fopen(ConfigFilename.ascii(),"wb");
    //Cargamos archivo de configuracion
    if ( cfg != NULL ){
	fwrite(config,sizeof(metadata),1,cfg);
	fclose(cfg);
	mensajeLog("Guardando configuracion...");
	return true;
    }
    mensajeLog("Imposible guardar configuracion...");
    return false;
}

bool database::leerConfig(){
    metadata tmpcfg;
    FILE* cfg = fopen(ConfigFilename.ascii(),"rb");
    //Cargamos archivo de configuracion
    if ( cfg != NULL){
	fread(&tmpcfg,sizeof(metadata),1,cfg);
	strncpy(config->path_history,tmpcfg.path_history,254);
        strncpy(config->path_datafile,tmpcfg.path_datafile,254);
        strncpy(config->path_tmpdir,tmpcfg.path_tmpdir,254);
	fclose(cfg);
	mensajeLog("Leyendo configuracion...");
	return true;
    }
    mensajeLog("Imposible leer configuracion...");
    return false;
}

int database::parse(char* filename){
    int ret = inputparse(filename);
    if (ret >= 0)
	mensajeLog("Se va a leer archivo de entrada...");
	cargarIndices();
    return ret;
	
}

int database::leerMetadata(){
    char filename[255];    
    FILE* hfile;
    strcpy(filename,config->path_datafile);
    strcat(filename,FILE_HEADER);    
    if((hfile = fopen(filename,"rb"))!=NULL){
	fread(config,sizeof(metadata),1,hfile);
	fclose(hfile);    
	mensajeLog("Metadata leido satisfactoriamente...");
	return 0;
    }
    else if((hfile = fopen(filename,"wb"))!=NULL){	
	fwrite(config,sizeof(metadata),1,hfile);
	fclose(hfile);    
	mensajeLog("Metada Guardado satisfactoriamente...");
	return 1;
    }
    fclose(hfile);    
    return -1;
}

int database::leerTablespace(){
    char filename[255];    
    FILE* in;
    strcpy(filename,config->path_datafile);
    strcat(filename,FILE_HEADER);
    unsigned int offset = sizeof(char);
    if(config->num_bloques_indice_dir !=0){
	if((in = fopen(filename,"rb"))!=NULL){
	    if(fseek(in,OFFSET_TABLESPACE(config),SEEK_SET))
	       fread(config_tb,sizeof(tablespace),1,in);
	    mensajeLog("Leyendo tablespace...");
	    fclose(in);    
	    return 0;
	}
	mensajeLog("Imposible leer tablespace...");
	fclose(in);
	return -1;
    }    
    mensajeLog("Imposible leer tablespace...");
    return -1;
}

int database::separar(){
    FILE* in,* out;
    char filename[255];    
    unsigned int i = 0;
    registro regtmp;
    strcpy(filename,config->path_datafile);
    strcat(filename,FILE_DATA);
    if((in = fopen(filename,"rb") )!= NULL){
	out = fopen(FILE_TBAUTOR,"w+b");
	fseek(in,OFFSET_TBAUTOR,SEEK_SET);
	for(i=OFFSET_TBAUTOR;i < OFFSET_TBCONTENIDO(config_tb); i++){
	    fread(&regtmp,sizeof(registro),1,in);
	    fwrite(&regtmp,sizeof(registro),1,out);
	}	
	fclose(out);
	out = fopen(FILE_TBCONTENIDO,"w+b");	
	fseek(in,OFFSET_TBCONTENIDO(config_tb),SEEK_SET);	
	for(i= OFFSET_TBCONTENIDO(config_tb) ;i < OFFSET_TBLIBRO(config_tb); i++){
	    
	    fread(&regtmp,sizeof(registro),1,in);
	    fwrite(&regtmp,sizeof(registro),1,out);
	}
	fclose(out);
	out = fopen(FILE_TBLIBRO,"w+b");
	fseek(in, OFFSET_TBLIBRO(config_tb) ,SEEK_SET);	
	for(i=OFFSET_TBLIBRO(config_tb);i < OFFSET_TBPRESTAMO(config_tb); i++){
	    
	    fread(&regtmp,sizeof(registro),1,in);
	    fwrite(&regtmp,sizeof(registro),1,out);
	}
	fclose(out);
	out = fopen(FILE_TBPRESTAMO,"w+b");
	fseek(in,OFFSET_TBPRESTAMO(config_tb),SEEK_SET);	
	for(i=OFFSET_TBPRESTAMO(config_tb);i < OFFSET_TBTIPOUSUARIO(config_tb); i++){
	    
	    fread(&regtmp,sizeof(registro),1,in);
	    fwrite(&regtmp,sizeof(registro),1,out);
	}	
	fclose(out);
	out = fopen(FILE_TBTIPOUSUARIO,"w+b");
	fseek(in,OFFSET_TBTIPOUSUARIO(config_tb),SEEK_SET);	
	for(i=OFFSET_TBTIPOUSUARIO(config_tb);i < OFFSET_TBTITULO(config_tb); i++){
	    
	    fread(&regtmp,sizeof(registro),1,in);
	    fwrite(&regtmp,sizeof(registro),1,out);
	}
	fclose(out);
	out = fopen(FILE_TBTITULO,"w+b");
	fseek(in,OFFSET_TBTITULO(config_tb),SEEK_SET);	
	for(i=OFFSET_TBTITULO(config_tb);i < OFFSET_TBUSUARIO(config_tb); i++){
	    
	    fread(&regtmp,sizeof(registro),1,in);
	    fwrite(&regtmp,sizeof(registro),1,out);
	}
	fclose(out);
	out = fopen(FILE_TBUSUARIO,"w+b");
	fseek(in,OFFSET_TBUSUARIO(config_tb),SEEK_SET);	
	for(i=OFFSET_TBUSUARIO(config_tb);i < OFFSET_TBEND(config_tb); i++){
	    
	    fread(&regtmp,sizeof(registro),1,in);
	    fwrite(&regtmp,sizeof(registro),1,out);
	}	
	fclose(in);
	fclose(out);
	return 0;
    }
    return -1;
}

int database::fusionar(){
    FILE* in,* out;
    char filename[255];        
    registro regtmp;
    strcpy(filename,config->path_datafile);    	
    strcat(filename,FILE_DATA);
    if((out = fopen(filename,"w+b"))!=NULL){
	if((in = fopen(FILE_TBAUTOR,"rb")) != 0){
	   while(!feof(in)){
	       if(!feof(in)){
	       fread(&regtmp,sizeof(registro),1,in);	    
	       fwrite(&regtmp,sizeof(registro),1,out);	    
	       }
	   }
	   fclose(in);
	}	
	
	if((in = fopen(FILE_TBCONTENIDO,"rb")) != 0){
	   while(!feof(in)){
	       if(!feof(in)){
	       fread(&regtmp,sizeof(registro),1,in);	    
	       fwrite(&regtmp,sizeof(registro),1,out);	    
	       }
	   }
	   fclose(in);
	}
	
	if((in = fopen(FILE_TBLIBRO,"rb")) != 0){
	   while(!feof(in)){
	       if(!feof(in)){
	       fread(&regtmp,sizeof(registro),1,in);	    
	       fwrite(&regtmp,sizeof(registro),1,out);	    
	       }
	   }
	   fclose(in);
	}
	
	if((in = fopen(FILE_TBPRESTAMO,"rb")) != 0){
	   while(!feof(in)){
	       if(!feof(in)){
	       fread(&regtmp,sizeof(registro),1,in);	    
	       fwrite(&regtmp,sizeof(registro),1,out);	    
	       }
	   }
	   fclose(in);
	}
	
	if((in = fopen(FILE_TBTIPOUSUARIO,"rb")) != 0){
	   while(!feof(in)){
	       if(!feof(in)){
	       fread(&regtmp,sizeof(registro),1,in);	    
	       fwrite(&regtmp,sizeof(registro),1,out);	    \
	       }
	   }
	   fclose(in);
	}
	
	if((in = fopen(FILE_TBTITULO,"rb")) != 0){
	   while(!feof(in)){
	       if(!feof(in)){
	       fread(&regtmp,sizeof(registro),1,in);	    
	       fwrite(&regtmp,sizeof(registro),1,out);	    
	       }
	   }
	   fclose(in);
	}
	
	if((in = fopen(FILE_TBUSUARIO,"rb")) != 0){
	   while(!feof(in)){
	       fread(&regtmp,sizeof(registro),1,in);	    
	       fwrite(&regtmp,sizeof(registro),1,out);	    
	   }
	   fclose(in);
	}
	fclose(out);
	return 0;	
    }
    return -1;
}

void database::ertmp(){
	remove(FILE_TBAUTOR);
	remove(FILE_TBCONTENIDO);
	remove(FILE_TBLIBRO);
	remove(FILE_TBPRESTAMO);
	remove(FILE_TBTIPOUSUARIO);
	remove(FILE_TBTITULO);
	remove(FILE_TBUSUARIO);
}

int database::guardarMetadata(){
    char filename[255];    
    FILE* hfile;
    strcpy(filename,config->path_datafile);
    strcat(filename,FILE_HEADER);
    if((hfile = fopen(filename,"wb"))!=NULL){	
	fwrite(config,sizeof(metadata),1,hfile);
	
	fclose(hfile);    
	mensajeLog("Metadata guardado...");
	return 1;
    }
    fclose(hfile);    
    return -1;
}

int database::guardarIndices(){
    FILE* in,*out;
    indice idxtmp;
    char filename[255];    
    strcpy(filename,config->path_datafile);
    strcat(filename,FILE_HEADER);
    if((out = fopen(filename,"ab"))!=NULL){
	if(out!=NULL){
	    in = fopen(FILE_DIRIDX,"rb");
	    if(in!=NULL){
		while(!feof(in)){
		    if(!feof(in)){
		fread(&idxtmp,sizeof(indice),1,in);
		fwrite(&idxtmp,sizeof(indice),1,out);
		    }
		}
		fclose(in);
		mensajeLog("Guardando Indices...");
	    }
	    fclose(out);
	}
    }
    return 0;
}

int database::guardarTablespace(){
    char filename[255];    
    FILE* hfile;
    strcpy(filename,config->path_datafile);
    strcat(filename,FILE_HEADER);
    if((hfile = fopen(filename,"ab"))!=NULL){	
	fwrite(config_tb,sizeof(tablespace),1,hfile);
	fclose(hfile);    
	mensajeLog("Tablespace Guardado...");
	return 1;
    }
    fclose(hfile);    
    return -1;
}

int database::insertarRegistro(registro* r){
    int ret;
    mensajeLog("Insertando nuevo registro a la base de datos...");
    switch(r->tipo){
	case T_AUTOR:
	    ret = insertarAutor(&(r->dato.rAutor));
	    break;
	case T_LIBRO:
	    ret =  insertarLibro(&(r->dato.rLibro));
	    break;
	case T_CONTENIDO:
	    ret =  insertarContenido(&(r->dato.rContenido));
	    break;
	case T_PRESTAMO:
	    ret =  insertarPrestamo(&(r->dato.rPrestamo));
	    break;
	case T_TIPOUSUARIO:
	    ret =  insertarTipoUsuario(&(r->dato.rTipoUsuario));
	    break;
	case T_TITULO:
	    ret =  insertarTitulo(&(r->dato.rTitulo));
	    break;
	case T_USUARIO:
	    ret =  insertarUsuario(&(r->dato.rUsuario));
	    break;
	default:
	   ret = -1;
    }
    if(ret >=0)
	cargarIndices();
    /*
    leerMetadata();
    leerIndices();//actualizamos indices
    leerTablespace();*/
    return ret;
}

int database::cargarIndices(){
    FILE* in;
    indice tmpidx;
    IndiceWrapper result;
    if((in = fopen(FILE_DIRIDX,"rb"))!=NULL){
	mensajeLog("Leyendo indices hacia Hash Maps...");
	while(!feof(in)){
	    if(!feof(in)){
		fread(&tmpidx,sizeof(indice),1,in);
		if (tmpidx.borrado == 0){
		    switch(tmpidx.tipoclave){
			case T_AUTOR:		    
			    idxDirAutor[tmpidx.id] = IndiceWrapper(tmpidx);
			    break;
			case T_LIBRO:
			    idxDirLibro[tmpidx.id] = IndiceWrapper(tmpidx);
			    break;
			case T_CONTENIDO:
			    idxDirContenido[tmpidx.id] = IndiceWrapper(tmpidx);
			    break;
			//case T_PRESTAMO:
			//    idxDirPrestamo[tmpidx.dato.rPrestamo.id] = tmpidx;
			//    break;
			case T_TIPOUSUARIO:
			    idxDirTipoUsuario[tmpidx.id] = IndiceWrapper(tmpidx);
			    break;
			case T_TITULO:
			    idxDirTitulo[tmpidx.id] = IndiceWrapper(tmpidx);
			    break;
			case T_USUARIO:
			    idxDirUsuario[tmpidx.id] = IndiceWrapper(tmpidx);
			    break;
			default:
			break;
			
		    }
		}
	    }
	    
	}
	fclose(in);
	result = idxDirContenido[4];
	return 0;
    }
    mensajeLog("Imposible mapear indices a Hash...");
    return -1;
}

int database::cargarUsuarios(){
    FILE* in;
    registro tmpreg;
    r_usuario result;
    if((in = fopen(FILE_TBUSUARIO,"rb"))!=NULL){
	mensajeLog("Leyendo datos de usuarios...");
	while(!feof(in)){
	    if(!feof(in)){
		fread(&tmpreg,sizeof(registro),1,in);
		indiceUsuarios[tmpreg.dato.rUsuario.nombre] = tmpreg.dato.rUsuario;
	    }
	    
	}
	mensajeLog("Datos leidos satisfactoriamente...");
	fclose(in);
	result = indiceUsuarios["kreig"];
	return 0;
    }
    return -1;
}

int database::buscarLibro(indice indicelibro){
    registro* reglibro,* regAutor,* regTitulo;
    indice indiceAutor, indiceTitulo;
    mensajeLog("buscando libro...");
    if((reglibro = leerRegistro(indicelibro.num_registro,T_LIBRO))!=NULL && (reglibro->borrado == 0)){
	memcpy(&indiceAutor,&idxDirAutor[reglibro->dato.rLibro.autor],sizeof(indice));
	memcpy(&indiceTitulo,&idxDirAutor[reglibro->dato.rLibro.titulo],sizeof(indice));
	regAutor = leerRegistro(indiceAutor.num_registro,T_AUTOR);
	regTitulo = leerRegistro(indiceTitulo.num_registro,T_TITULO);
	if(regAutor !=NULL && regTitulo!=NULL && (regAutor->borrado == 0) && (regTitulo->borrado == 0)){
	    erw->addLibro(QString::number(indicelibro.id),
			  QString::fromAscii(regAutor->dato.rAutor.nombre), 
			  QString::fromAscii(regTitulo->dato.rTitulo.nombre),
			  QString::number(reglibro->dato.rLibro.edicion),
			  QString::number(reglibro->dato.rLibro.cantidad), 
			  QString::fromAscii(regTitulo->dato.rTitulo.path_imagen));
	}
		
	delete reglibro;
	delete regAutor;
	delete regTitulo;
	return 0;
    }
    return -1;
    
}

int database::buscarLibroIsbn(int id){
    return buscarLibro(idxDirLibro[id].getIndex());
}

void database::setResultWidget(QWidget* w){
    erw = (EricleResultWidget*) w;
    
}

void database::mostrarLibros(){
    IndexMap::Iterator it;
    erw->clearTable();
    for ( it = idxDirLibro.begin(); it != idxDirLibro.end(); ++it ) {
	buscarLibro(it.data().getIndex());
	/*printf( "%s: %s, %s earns %d\n",
	it.key().latin1(),
	it.data().surname().latin1(),
	it.data().forename().latin1(),
	it.data().salary() );*/
    }
}
