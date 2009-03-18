#include "funciones.h"

/* Copia y concatena una cadena n veces */
char *repeat(char* cadena,int n){
  char tmpcad[512];
  tmpcad[0] = 0;
  int i;
  if ((n*sizeof(&cadena)) < 512){
    strcat(tmpcad,cadena);
    for(i = 1; i<n; i++)
      strcat(tmpcad,cadena);
    return strcpy(cadena,tmpcad);
  }
  return NULL;
};

/*Copia n caracteres del final de la cadena y las coloca al inicio*/
char *shiftnright(char* cadena,int n){
  size_t sizestr = strlen(cadena);
  char buffer_inicial[512];
  char buffer_final[512];
  int numchars;
  if ((n % sizestr) == 0){
    return cadena;
  }
  else{
    numchars =sizestr - (n % sizestr);
    strncpy(buffer_inicial,cadena,numchars);
    buffer_inicial[numchars] = 0;
    strncpy(buffer_final,cadena + numchars,sizestr - numchars +1);
    cadena[0] = 0x0;
    strcat(cadena,buffer_final);
    strcat(cadena,buffer_inicial);
    return cadena;
  }
  return NULL;
    
};
/*Copia n caracteres del inicio de la cadena y las coloca al final*/
char *shiftnleft(char* cadena,int n){
  size_t sizestr = strlen(cadena);
  char buffer_inicial[512];
  char buffer_final[512];
  int numchars;
  if ((n % sizestr) == 0){
    return cadena;
  }
  else{
    numchars = n % sizestr;
    strncpy(buffer_inicial,cadena,numchars);
    buffer_inicial[numchars] = 0;
    strncpy(buffer_final,cadena + numchars,sizestr - numchars +1);
    cadena[0] = 0x0;
    strcat(cadena,buffer_final);
    strcat(cadena,buffer_inicial);
    return cadena;
  }
  return NULL;
};

