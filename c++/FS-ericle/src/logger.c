#include "logger.h"

FILE* logout;

void iniciarLogFile(const char* path){
    char filename[255];
    if (strlen(path) + 32 < 255){        
        sprintf(filename,"%sericle_log_%d.xml",path,(int)time(NULL));   
    }
    else
	strcpy(filename,"/var/log/ericle_log_%d.xml");
    if((logout = fopen(filename,"w+b")) != NULL){
	fprintf(logout,"<?xml version=\"1.0\"?>\n");
	fprintf(logout,"<ericlelog>\n\n");
    }
}

void mensajeLog(const char* msg){
    time_t t = time(NULL);
    if(logout){
	fprintf(logout,"\t<mensaje hora = \"%s\">\n",ctime(&t));
	fprintf(logout,"\t\t%s\n",msg);
	fprintf(logout,"\t</mensaje>\n\n");		
    }
}

void finalizarLogFile(){
    
    if(logout){
	fprintf(logout,"</ericlelog>\n");
	fclose(logout);
    }
}

void agregarMsgLog(int tipomensaje,int pos,registro *s){
    
    if(logout){
	switch(tipomensaje){	    
	    case MSGS_INSERCION:
	   fprintf(logout,"\t<insercion>\n");
	   fprintf(logout,"\t\tSe ha insertado satisfactoriamente el registro de tipo %d en la posicion %d\n",s->tipo,pos);
	   fprintf(logout,"\t</insercion>\n\n");		
	   break;
	}
    }
}
void agregarErrorLog(int tipomensaje ,registro *s){
    time_t t = time(NULL);
        if(logout){
	    switch(tipomensaje){	    
	    case MSGE_NOTENOUGHROOM:
		fprintf(logout,"\t<error tipo = \"espacial\" hora = \"%s\">\n",ctime(&t));
		fprintf(logout,"\t\tImposible insertar el registro tipo %d\n",s->tipo);
		fprintf(logout,"\t</error>\n\n");		
		break;
	    case MSGE_DUPLICADO:
		fprintf(logout,"\t<error tipo = \"duplicado\" hora = \"%s\">\n",ctime(&t));
		fprintf(logout,"\t\tImposible insertar el registro tipo %d debido a que ya existe un dato con el indice dado\n",s->tipo);
		fprintf(logout,"\t</error>\n\n");		
		break;
	    }
    }
}
