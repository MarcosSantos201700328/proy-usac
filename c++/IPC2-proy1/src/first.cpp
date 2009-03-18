#ifndef __FIRST_CPP
#define __FIRST_CPP
#ifdef bc
#include "d:\progra\ipc2\proy1\src\first.h"
#else
#include "first.h"
#endif
#undef debug

/************************flush()***************************///
//Borra el contenido del archivo que se le de como parametro
int flush(const char file[]){
  FILE * f;
  if((f = fopen(file,"wb"))!= NULL){
    fwrite(0,0,1,f);
    fclose(f);
    return 0;
  }
  else
    return 1;
}
//***********************setInput():***********************///
//   Establece archivo de entrada;
//   devuelve el path para archivo de salida;
void setInput(char * inpath){
  char path[255];
  cout << endl << endl
	   << "Escriba ruta hacia archivo de entrada" << endl;
  cin >> path;
  strcpy(inpath,path);
}

//***********************setOutput():***********************//
//   Establece archivo de salida;
//   devuelve el path para archivo de salida;
void setOutput(char *outpath){
  char path[255];
  cout << endl << endl
	   << "Escriba el directorio donde desee guardar archivo de salida" << endl;
  cin >> path;
  strcpy(outpath,path);
  strcat(outpath,"salida.txt");
}


// ***********************MsgErr: (06-09)***********************
// Escribe mensaje de error mensaje[], a archivo de salida si
// tipo salida= 1 o solo a stdout si tiposalida = 0
void msgerr(char mensaje[],int tiposalida){
  fstream out;
  switch (tiposalida){
  case 1: // Avisos
    cout<< "Aviso: " << mensaje << endl;
    out.open(salida, fstream::out | fstream::app);
    out << "Aviso: " << mensaje << endl;
    break;
  case 2: // Datos
    cout << mensaje << endl;
    out.open(salida, fstream::out | fstream::app);
    out << mensaje << endl;
    break;
  default: //Avisos solo en pantalla
    cout<< "Aviso: " << mensaje << endl;
    break;
  }
  out.close();
}


//************************ActualizaConfed()*********************/
// Actualiza archivo de Confederaciones, devuelve 0 si se creo 
// registro, o 1 si se actualiza registro a escribir
int ActualizaConfed(confederacion RegData){
  FILE * in,* out;
  //idx IdxData;
  confederacion tmpData;
  int i = 0, encontrado = 0;
  //SI EXISTE ...
  if ( (in = fopen(ArchConfed,"rb")) != NULL){
    while (!feof(in) && encontrado == 0){
      fread(&tmpData,sizeof(confederacion),1,in);
      if (strcasecmp(tmpData.id,RegData.id)==0)	{
	encontrado = 1;
      }
      else
	i++;
    }
    fclose(in);
    //...ACTUALIZA...
    if (encontrado > 0) {
      out = fopen(ArchConfed,"r+b");
      fseek(out,i*sizeof(RegData),0);
      fwrite(&RegData,sizeof(RegData),1,out);
      fclose(out);
      return 1;
    }
    //...SINO CREA...
    else{
    out = fopen(ArchConfed,"ab");
    fwrite(&RegData,sizeof(RegData),1,out);
    fclose(out);
    return 0;
    }
  }
  else {
    out = fopen(ArchConfed,"ab");
    fwrite(&RegData,sizeof(RegData),1,out);
    fclose(out);
 
    return 0;
  }
}

//************************ActualizaTorneo()*********************/
// Actualiza archivo de Torneos, devuelve 0 si se creo 
// registro, o 1 si se actualiza registro a escribir o -1 si hay error
int ActualizaTorneo(torneo RegData){
  FILE * in,* out;
  //  idx IdxData;
  torneo tmpData;
  int i = 0, encontrado = 0;
 
  if (RegData.factor == 0)
    return -1;
  else{
    //Ajustes previos a guardar datos de torneo...
    if (RegData.esoficial == false && RegData.bonif_vis > 0){
      msgerr("Bonificacion debe ser 0 por ser torneo no oficial, este valor sera ajustado ",1);
      RegData.bonif_vis = 0;
    }
    //SI EXISTE ...
    if ( (in = fopen(ArchTorneo,"rb")) != NULL){
      while (!feof(in) && encontrado == 0){
	fread(&tmpData,sizeof(torneo),1,in);
	if (strcasecmp(tmpData.id,RegData.id)==0){
	  encontrado = 1;
	}
	else
	  i++;
      }
      fclose(in);
      //...ACTUALIZA...
      if (encontrado > 0) {
	out = fopen(ArchTorneo,"r+b");
	fseek(out,i*sizeof(RegData),0);
	fwrite(&RegData,sizeof(RegData),1,out);
	fclose(out);
	return 1;
      }
      //...SINO CREA...
      else{
	out = fopen(ArchTorneo,"ab");
	fwrite(&RegData,sizeof(RegData),1,out);
	fclose(out);
	return 0;
      }
    }
    else {
      out = fopen(ArchTorneo,"ab");
      fwrite(&RegData,sizeof(RegData),1,out);
      fclose(out);
      
      return 0;
    }
  }
}

//***********************ActualizaSeleccion()*****************/
// Crea o actualiza seleccion en archivo de selecciones
// retorna 0 si crea, 1 se actualiza
int ActualizaSelec(seleccion RegSelec){
  confederacion RegConfed;
  seleccion RegTmp;
  FILE * arch;
  int existeconfed = 0, existeselec = 0,i = 0;

  // Busca confederacion
  if ((arch = fopen(ArchConfed,"rb"))!=NULL){
    while (!feof(arch)){
      fread(&RegConfed,sizeof(RegConfed),1,arch);
      if (strcasecmp(RegConfed.id,RegSelec.id_conf)==0)
	existeconfed = 1;
    }
    fclose(arch);
  }
  // Si existe confederacion...
  if(existeconfed==1){
    // ...Actualiza archivo OR ...
    if((arch = fopen(ArchSelec,"rb"))!=NULL){
      while (!feof(arch) && existeselec == 0){
	fread(&RegTmp,sizeof(RegTmp),1,arch);
	if(strcasecmp(RegTmp.id,RegSelec.id)==0)
	  existeselec = 1;
	else
	  i++;
      }
      fclose(arch);
      if (existeselec==1){
	arch = fopen(ArchSelec,"r+b");
	fseek(arch,i*sizeof(RegSelec),0);
	fwrite(&RegSelec,sizeof(RegSelec),1,arch);
	fclose(arch);
	return 1;
      }
      //...escribe nuevo registro en archivo.
      else{
	arch = fopen(ArchSelec,"a+b");
	//fseek(arch,0,SEEK_END);
	fwrite(&RegSelec,sizeof(RegSelec),1,arch);
	fclose(arch);
	return 0;
      }
      fclose(arch);
    }
    else{
      arch = fopen(ArchSelec,"a+b");
      fwrite(&RegSelec,sizeof(RegSelec),1,arch);
      fclose(arch);
      return 0;
    }
  }
  //Si no existe confederacion devuelve Error
  else
    return -1; 
}

//*************************GenerarReporteClasif()**************
//Genera reporte de la clasificacion FIFA/CocaCola
int GenerarReporteClasif(idxclasif idc[],int numdatos){
  FILE * in;
  clasif tmp;
  char msg[255];
 
  if ((in=fopen(ArchClasif,"rb"))!=NULL){
    for(int i =0; i < numdatos; i++){
      fseek(in,(idc[i].pos)*sizeof(clasif),0);
      fread(&tmp,sizeof(clasif),1,in);
      sprintf(msg,"%s\t\t%d\t\t\t%d\n",
	      tmp.nombre,tmp.puntos,tmp.diffpuntos);
      msgerr(msg,2);
    }
    fclose(in);
    return 0;
  }
  else
    return -1;
}

//*************************GuardarClasif()*********************
//Almacena registro clasificacion FIFA Cocacola en archivo
//en disco.
int GuardarClasif(clasif c){
  FILE * out;
  if((out=fopen(ArchClasif,"ab"))!=NULL){
    fwrite(&c,sizeof(c),1,out);
    fclose(out);
    return 0;
  }
  else{
    out = fopen(ArchClasif,"ab");
    fwrite(&c,sizeof(c),1,out);
    fclose(out);
    return 0;
  }
}

//*************************AcumularPuntosMes()*****************
//Calcula puntos acumulados del mes que se desee y del mes
//anterior a este del equipo especificado en la estructura
int AcumularPuntosMes(clasif &c,idxclasif &idc){
  FILE * in;
  juego tmp;
  unsigned int encontrado = 0;
  bool salir = false;
  c.diffpuntos = c.puntos = 0;
  if((in=fopen(ArchJuegos,"rb"))!=0){
    while (!feof(in)){
      if(!feof(in) && !salir){
	fread(&tmp,sizeof(juego),1,in);
	if(tmp.a<=c.aa && tmp.m <=c.mm){
	  if (strcasecmp(c.id,tmp.id_eqA)==0){
	    c.puntos = idc.puntos = tmp.puntosacA;
	    encontrado = 1;
	  }
	  else if (strcasecmp(c.id,tmp.id_eqB)==0){
	    c.puntos = idc.puntos = tmp.puntosacB;
	    encontrado = 1;
	  }
	  
	}
	if(tmp.a<=c.aa && tmp.m <= (c.mm - 1) && encontrado == 1){
	  if (strcasecmp(c.id,tmp.id_eqA)==0){
	    c.diffpuntos = c.puntos - tmp.puntosacA;
	    encontrado = 2;
	    salir = true;
	  }
	  else if (strcasecmp(c.id,tmp.id_eqB)==0){
	    c.diffpuntos = c.puntos - tmp.puntosacB;
	    encontrado = 2;
	    salir = true;
	  }
	}
      }
    }
    fclose(in);
    return encontrado;
  }
  else return -1;
}


// Inicializa Indice de Clasificacion....
void InicializarIndice(idxclasif * idc,int numelementos){
  for (int i=0; i<= numelementos; i++)
    idc[i].pos = idc[i].puntos = 0;
}
//*************************Clasificacion()*******************
//Funcion principal para calcular la clasificacion fifa/cocacola
int Clasificacion(clasif &c){
  FILE * in;
  seleccion tmp;
  idxclasif idc[255];
  char msg[255];
  int i = 0;
  
  InicializarIndice(idc,255);// Inicializa a 0 el indice
  
  if((in=fopen(ArchSelec,"rb"))!=NULL){
    while(!feof(in) && i != 255){
      if(!feof(in)){
	fread(&tmp,sizeof(seleccion),1,in);
	strcpy(c.id,tmp.id);
	strcpy(c.nombre,tmp.nombre);
	//strcpy(idc[i].id,c.id);
	idc[i].pos = i;
	AcumularPuntosMes(c,idc[i]);
	GuardarClasif(c);
	i++;
      }
    }
    fclose(in);
    if (i > 0){
      QuickSort(idc,0,i-1);
      sprintf(msg,"Linea#%d\nClasificacion Fifa/CocaCola a %s de %d",
	      numlinea,mes(c.mm),c.aa);
      msgerr(msg,2);
      sprintf(msg,"Seleccion\tPuntos Acumulados\tIncr.Decr resp %s de %d",
	      mes(c.mm),c.aa);
      msgerr(msg,2);
      GenerarReporteClasif(idc,i-1);
      return 0;
    }
    else
      return -1;
  }
  else{
    return -1;
  }
}

//*************************buscaDesemp()**********************
//Busca en el archivo ArchDesemp por el equipo con mayor punteo
int buscaDesemp(desemp &d){
  FILE * in;
  desemp tmp1,tmp2;
  int i = 0;
  // Iniciacion
  tmp1.puntos=0;
  tmp2.puntos=0;
  if((in=fopen(ArchDesemp,"rb"))!=NULL){
    while(!feof(in)){
      if(!feof(in)){
	if(i==0)
	  fread(&tmp1,sizeof(desemp),1,in);
	else{
	  fread(&tmp2,sizeof(desemp),1,in);
	  if (tmp2.puntos > tmp1.puntos)
	    memcpy(&tmp1,&tmp2,sizeof(desemp));
	}i++;
      }
    }
    fclose(in);
    memcpy(&d,&tmp1,sizeof(desemp));
    return 0;
  }
  else
    return -1;
}



//*************************calcularPuntosGanados()*************
// Funcion que calcula puntos ganados para cada seleccion contenida
// en el registro desemp;
int calcularPuntosGanados(desemp &d){
  FILE * in;
  juego tmp;
  int puntosAc = 0, puntosgan = 0;
  if((in=fopen(ArchJuegos,"rb"))!=NULL){
    while(!feof(in)){
      if(!feof(in)){
	fread(&tmp,sizeof(juego),1,in);
	if((tmp.a>=(d.aa-12)) && (tmp.a<=d.aa)){
	  if(strcasecmp(d.id,tmp.id_eqA)==0){
	    puntosAc += tmp.punteoA;
	    if(tmp.a == d.aa)
	      puntosgan += tmp.punteoA;
	  }
	  else if(strcasecmp(d.id,tmp.id_eqB)==0){
	    puntosAc += tmp.punteoB;
	    if(tmp.a == d.aa)
	      puntosgan += tmp.punteoB;
	  }
	}
      }
    }
    fclose(in);
    d.puntos = puntosAc * puntosgan;
    return 0;
  }
  else
    return -1;
}

//*************************prem_desemp()*************************
// Funcion principal de calculo de premio de mejor desempeno
int prem_desemp(desemp &d){
  FILE * in,* out;
  seleccion tmp;
  bool encontrado = false;
  int ret = 0;
  if((in=fopen(ArchSelec,"rb"))!=NULL){
    while (!feof(in)){
      if(!feof(in)){
	fread(&tmp,sizeof(seleccion),1,in);
	strcpy(d.id,tmp.id);
	strcpy(d.nombre,tmp.nombre);
	ret = calcularPuntosGanados(d);
	encontrado = true;
      }
      //  if(encontrado==true){
	out = fopen(ArchDesemp,"a+b");
	fwrite(&d,sizeof(desemp),1,out);
	fclose(out);
	//      }

    }
    fclose(in);
  }
  return ret;
  //  }
  //  else
  // return ret+1;
  
}

//*************************premioME()*************************
//Genera reporte del premio al mejor equipo de ano
int PremioME(eq_year &e){
  FILE * in;
  int i = 0;
  eq_year tmp1,tmp2;
  if ((in=fopen(ArchEqYear,"rb"))!=NULL){
    while (!feof(in)){
      if (!feof(in)){
	if(i==0)
	  fread(&tmp1,sizeof(eq_year),1,in);
	else{
	  fread(&tmp2,sizeof(eq_year),1,in);
	  if (tmp1.punteo < tmp2.punteo)
	    memcpy(&tmp1,&tmp2,sizeof(eq_year));
	}
	i++;
      }
    }
    fclose(in);
  }
  memcpy(&e,&tmp1,sizeof(eq_year));
  //Trunca el archivo luego de calcular los resultados
  in = fopen(ArchEqYear,"wb");
  //  fwrite(0,0,1,in);
  fclose(in);
  return 0;
}

//*************************guardarEqA()*************************
// Guarda los registros de los punteos en el a~no de cada seleccion
// en archivo de salida
int guardarEqA(eq_year &e){
  FILE * in;
  in = fopen(ArchEqYear,"a+b");
  //  if (sizeoffile(in)>0)
  //freopen(ArchEqYear,"w+b",in);

  fwrite(&e,sizeof(eq_year),1,in);
  fclose(in);
  return 0;
}


//*************************leerPunteo()**************************
//Lee punteo actual del registro de Juegos para cada equipo en
//comando premio mejor equipo
int leerPunteoPME(eq_year &e){
  FILE * in;
  juego tmp;
  int punteo[256];// Para 7 mejores
  int puntos[256];// para 12 Ultimos
  int i = 0, x = 0, y = 0; float z = 0;
#ifdef bc
  int j = 0;
  //Inicializacion de Arrays
  for (j = 0; j<256;j++){
#else
  for (int j = 0;j<256;j++) {
#endif
	punteo[i] = 0;
	puntos[i]=0;

  }
  //Lectura de Punteos a Array
  if((in=fopen(ArchJuegos,"rb"))!=NULL){
	while(!feof(in)){
	  fread(&tmp,sizeof(juego),1,in);
	  if(!feof(in)){
	if(strcasecmp(tmp.id_eqA,e.id) == 0){
	  punteo[i]=tmp.punteoA;
	  puntos[i]=tmp.punteoA; i++;
	}
	else if(strcasecmp(tmp.id_eqB,e.id) == 0){
	  punteo[i]=tmp.punteoA;
	  puntos[i]=tmp.punteoA; i++;
	}
	//	i++;
	  }
	}
	fclose(in);
  }
  if(i>0){
	QuickSort((int*)punteo,i,0); // ordena punteo a la inversa
#ifdef bc
	for(j = 0; j<i && j<7; j++){
#else
	for(int j = 0;j<i && j<7;j++) {//Suma en variable X los 7 mejores punteos
#endif
	  x+=punteo[j];
	}
#ifdef bc
	for(j = (i-1); j >= (i-12) && j>=0 ; j--){
#else
	for(int j = (i-1); j >= (i-12) && j>=0 ; j--){ //Suma los 12 ultimos punteos
#endif
	  y+=puntos[j];
	}
  }
  z = (((x+y)*7)/12); // Devuelve Z
  return (int)(z/2);
}

//*************************int eqA*************************
//Funcion principal de calculo para premio mejor equipo
int eqA(eq_year &e){
  FILE * in;
  seleccion tmp;
  if((in=fopen(ArchSelec,"rb"))!=NULL){
	while(!feof(in)){
	  fread(&tmp,sizeof(seleccion),1,in);
	  if(!feof(in)){
	strcpy(e.id,tmp.id);
	strcpy(e.nombre,tmp.nombre);
	e.punteo = leerPunteoPME(e);
	guardarEqA(e);
	  }
	}
	fclose(in);
  }
  return 0;
}


//*************************ValidaJuego()*************************
//valida datos para juego
int ValidarJuego(juego RegData){
  FILE * in;
  seleccion tmp;
  int existe = 0;
  bool fechacorrecta = false;
  if (RegData.d >= 1 && RegData.d <=31 && 
      RegData.m >= 1 && RegData.m <=12 &&
      RegData.a >= 1920)
    fechacorrecta = true;

  if ((in = fopen(ArchSelec,"rb"))!=NULL && fechacorrecta==true){
    while (!feof(in) && existe < 2){
      fread(&tmp,sizeof(tmp),1,in);
      if (strcasecmp(tmp.id,RegData.id_eqA)==0 && !feof(in))
	existe++;
      else if(strcasecmp(tmp.id,RegData.id_eqB)==0 && !feof(in))
	existe++;
    }
    fclose(in);
  }
  else
    return -2;
  if (existe==2)
    return 0;
  else
    return -1;
}
//******************ValidaFecha()*******************************//
//*********************Valida fecha para Puntos Acumulados******//
int ValidaFecha(intervfecha RegData){
  if (RegData.m0 > 0 && RegData.m0 <= 12 &&
      RegData.m1 > 0 && RegData.m1 <= 12 &&
      RegData.a0 > 1920 && RegData.a0 < 9999 &&
      RegData.a1 > 1920 && RegData.a1 < 9999)
    if (RegData.a1 == RegData.a0)
      if (RegData.m1 > RegData.m0) 
	return 0;
      else 
	return -1;
    else if (RegData.a1 > RegData.a0) 
      return 0;
    else 
      return -1;
  else
    return -1;
}

//*************************sizeoffile()*************************//
int sizeoffile(FILE * file){
  int inicio,fin;
  fseek(file,0,0);
  inicio = ftell(file);
  fseek(file,0,2);
  fin = ftell(file);
  rewind(file);
  return(fin - inicio);
}
//************************mes()*********************************//
// Se ingresan numero de mes y regresa el nombre del mes
char*  mes(int num){
  static char ret[16];
  switch(num){
  case 1: 
    sprintf(ret,"Enero");
    return ret;
    break;
  case 2:
    sprintf(ret,"Febrero");
    return ret;
    break;
  case 3:
    sprintf(ret,"Marzo");
    return ret;
    break;
  case 4:
    sprintf(ret,"Abril");
    return ret;
    break;
  case 5:
    sprintf(ret,"Mayo");
    return ret;
    break;
  case 6:
    sprintf(ret,"Junio");
    return ret;
    break;
  case 7:
    sprintf(ret,"Julio");
    return ret;
    break;
  case 8:
    sprintf(ret,"Agosto");
    return ret;
    break;
  case 9:
    sprintf(ret,"Septiembre");
    return ret;
    break;
  case 10:
    sprintf(ret,"Octubre");
    return ret;
    break;
  case 11:
    sprintf(ret,"Noviembre");
    return ret;
    break;
  case 12:
    sprintf(ret,"Diciembre");
    return ret;
    break;
  default:
    return NULL;
    break;
  }
   
}

//************************printPuntosAc()******************/
// Imprime los puntos acumulados en pantalla y archivo
int printPuntosAc(intervfecha fecha){
  char mensaje [255];
  int i = 0;
  idxpuntosac tmp[100];
  puntosac tmp2;

  FILE * in;

  sprintf(mensaje,"PUNTOS ACUMULADOS DE %s %d a %s %d \n\n\n",
	  (char*)mes(fecha.m0),fecha.a0,(char*)mes(fecha.m1),fecha.a1);
  msgerr(mensaje,2);
  // Lee Indices
  if((in= fopen(ArchIdxPuntosac,"rb"))!=NULL){
    sprintf(mensaje,"SELECCION\t\tCONFEDERACION\t\t\tPUNTOS ACUMULADOS\n");
    msgerr(mensaje,2);
    while (!feof(in)){
      if(!feof(in)){
	fread(&tmp[i],sizeof(idxpuntosac),1,in);
	} i++;
    }
    fclose(in);
  }
  
  if((in=fopen(ArchPuntosac,"rb"))!=NULL){
    for(int j = 0; j<(i-1); j++){
      fseek(in,(tmp[j].indice)*sizeof(tmp2),0);
      fread(&tmp2,sizeof(tmp2),1,in);
      if(!feof(in)){
      sprintf(mensaje,"%s\t\t%s\t\t\t%f",
	      tmp2.id,tmp2.id_conf,tmp[j].diffpuntos);
      msgerr(mensaje,2);
      }
    }
    fclose(in);
  }
  return 0;
}


//************************CrearIndicePuntos()******************/
int CrearIndicePuntos(void){
  idxpuntosac idx[100];
  puntosac puntos;
  FILE * file;
  unsigned int i = 0,j = 0;
  bool salir = false;
  // Crea Indice
  if((file=fopen(ArchPuntosac,"rb"))!=NULL){
    //for (i=0;i<100 && salir != true;i++){
    while(!feof(file) && salir!=true && i < 100){
      if (!feof(file)){
	fread(&puntos,sizeof(puntos),1,file);
	idx[i].indice = i;
	idx[i].diffpuntos = (puntos.punto2) - (puntos.punto1);
      }
      else
	salir = true;
      i++;
    }
    fclose(file);
  }
  else
    return -1;
  // Guarda en archivo
  if (i>0){
    //      QuickSort(idx,0,i);
    file = fopen(ArchIdxPuntosac,"w+b");
    for(j=0;j<i;j++){
      fwrite(&idx[j],sizeof(idxpuntosac),1,file);
    }
    fclose(file);
    return 1;
  }
  else return -1;
}
//*************************QuickSort*************************
// Ordena usando el algoritmo recursivo QuickSort de Hoare para
// ordenar punteos en memoria
void QuickSort(idxpuntosac * vec, int primero, int ultimo){
  int i,j,valor;
  idxpuntosac valt;
  
  i = primero;
  j = ultimo;
  //Valor Central
  valor = vec[(int)((primero + ultimo)/2)].diffpuntos;
  while (i<=j){
    while (vec[i].diffpuntos < valor)
      i++;
    while (vec[j].diffpuntos > valor)
      j--;
    if (i<=j){
      memcpy(&valt,&vec[i],sizeof(idxpuntosac));
      memcpy(&vec[i],&vec[j],sizeof(idxpuntosac));
      memcpy(&vec[j],&valt,sizeof(idxpuntosac));
      //valt = vec[i].diffpuntos;
      //vec[i].diffpuntos = vec[j].diffpuntos;
      //vec[j].diffpuntos = valt;
      i++;
      j--;
    }
  }//  }while i>j
  if (primero < j)
    QuickSort(vec,primero,j);
  if (i < ultimo)
    QuickSort(vec,i,ultimo);
}

// *****************QuickSort(idxclasif *,int,int)
// Sobrecargado que ordena un array de indices
void QuickSort(idxclasif * vec, int primero, int ultimo){
  int i,j,valor;
  idxclasif valt;
  
  i = primero;
  j = ultimo;
  //Valor Central
  valor = vec[(int)((primero + ultimo)/2)].puntos;
  while (i<=j){
    while (vec[i].puntos < valor)
      i++;
    while (vec[j].puntos > valor)
      j--;
    if (i<=j){
      memcpy(&valt,&vec[i],sizeof(idxclasif));
      memcpy(&vec[i],&vec[j],sizeof(idxclasif));
      memcpy(&vec[j],&valt,sizeof(idxclasif));
      //valt = vec[i].puntos;
      //vec[i].puntos = vec[j].puntos;
      //vec[j].puntos = valt;
      i++;
      j--;
    }
  }//  }while i>j
  if (primero < j)
    QuickSort(vec,primero,j);
  if (i < ultimo)
    QuickSort(vec,i,ultimo);
}

// *****************QuickSort(int*,int,int)
// Sobrecargado que ordena un array de enteros
void QuickSort(int *vec, int primero, int ultimo){
  int i,j,valor,valt;
  
  i = primero;
  j = ultimo;
  //Valor Central
  valor = vec[(int)((primero + ultimo)/2)];
  while (i<=j){
    while (vec[i]< valor)
      i++;
    while (vec[j] > valor)
      j--;
    if (i<=j){
      valt = vec[i];
      vec[i] = vec[j];
      vec[j] = valt;
      i++;
      j--;
    }
  }//  }while i>j
  if (primero < j)
    QuickSort(vec,primero,j);
  if (i < ultimo)
    QuickSort(vec,i,ultimo);
}

//**************************GuardarPuntos()*************************//
// Almacena puntos acumulados en archivo de tipo puntosac
int GuardarPuntos(char id[], float puntos){
  puntosac p,tmp; //estructura puntos acumulados
  int i =0;//,encontrado = 0;
  seleccion tmpsel;
  bool salir = false, encontrado = false;
  FILE * in;

  strcpy(p.id,id);
  p.punto1=puntos; p.punto2=puntos; // Condiciones iniciales
  // paso 1: Lee confederacion de archivo confed
  if((in=fopen(ArchSelec,"rb"))!=0){
    while (!feof(in) && salir==false){
      fread(&tmpsel,sizeof(tmpsel),1,in);
      if (strcasecmp(id,tmpsel.id)==0){
	strcpy(p.id_conf,tmpsel.id_conf);
	salir = true;
      }
    }
    fclose(in);
  }
  else
    return -1;
  salir = false;
  //paso 2: busca coincidencia de id en puntos anteriores
  if((in=fopen(ArchPuntosac,"r+b"))!=NULL){
    while(!feof(in) && !salir){
      fread(&tmp,sizeof(tmp),1,in);
      if((strcasecmp(tmp.id,id))==0 && !feof(in)){
	p.punto2 += tmp.punto2;
	fseek(in,i*sizeof(tmp),0);
	fwrite(&p,sizeof(p),1,in);
	salir = true;
	encontrado = true;
	fclose(in);
	return 0;
      }
     
      else if (feof(in)){ // escribe los puntos acumulados leidos
	//pone puntos en p(t=0) = puntos cuando no hay puntos anteriores
	//y asigna p(t=1) = puntos*2;
	//	p.puntos1 = 0;
	p.punto2 = puntos*2;
	freopen(ArchPuntosac,"a+b",in);
	//      	fseek(in,0,1);
      	fwrite(&p,sizeof(p),1,in);;
	fclose(in);
      	return 0;
      }
      else i++;
    }
  }
  else /*if (encontrado == false)*/{
    p.punto2 = puntos*2;
    in = fopen(ArchPuntosac,"a+b");
    fwrite(&p,sizeof(p),1,in);
    fclose(in);
    return 0;
  }
}
      //return 1;
      
// ***********************PuntosAC()***************************
// Calcula y escribe estructura puntos en archivo;
int PuntosAC(intervfecha RegData){
  FILE * in;
  juego tmp;
  int sum = 0;
  if((in = fopen(ArchJuegos,"rb"))!=NULL){
    while(!feof(in)){
      fread(&tmp,sizeof(tmp),1,in);
      if (tmp.a == RegData.a0 && tmp.m >= RegData.m0 && !feof(in)){
	if (tmp.a < RegData.a1){
 	  sum += GuardarPuntos(tmp.id_eqA,tmp.puntosacA);
	  sum += GuardarPuntos(tmp.id_eqB,tmp.puntosacB);
	}
	else if (tmp.a == RegData.a1 && tmp.m <= RegData.m1){
 	  sum += GuardarPuntos(tmp.id_eqA,tmp.puntosacA);
	  sum += GuardarPuntos(tmp.id_eqB,tmp.puntosacB);
	}
      }
      else if(tmp.a > RegData.a0)
	if(tmp.a < RegData.a1){
 	  sum += GuardarPuntos(tmp.id_eqA,tmp.puntosacA);
	  sum += GuardarPuntos(tmp.id_eqB,tmp.puntosacB);
	}
	else  if(tmp.a == RegData.a1 && tmp.m <= RegData.m1){
 	  sum += GuardarPuntos(tmp.id_eqA,tmp.puntosacA);
	  sum += GuardarPuntos(tmp.id_eqB,tmp.puntosacB);
	}
      //	else
	 
    }
    fclose(in);
  }
  else
    sum =-2; // Archivo no exite
  return sum;
}

//************************PClasif()*************************/
int PClasif(char IDeq[],unsigned int a,int &puntos1)
{
  FILE * in;
  unsigned int i = 0,size = 0;
  int encontrado = 0;
  int puntos2;
  juego tmp;
  if ((in=fopen(ArchJuegos,"rb"))!=NULL && (size=sizeoffile(in)) > 0){
    for (i=1; (i <(size/sizeof(tmp))) && 
	   (encontrado == 0); i++){
      fseek(in,-i*sizeof(tmp),SEEK_END);
      fread(&tmp,sizeof(tmp),1,in);
      if(strcasecmp(tmp.id_eqA,IDeq)==0){
      	puntos1 = tmp.puntosacA;
	encontrado++;
	//	if j = 0;
      }
      else if (strcasecmp(tmp.id_eqB,IDeq)==0){
      	puntos1 = tmp.puntosacB;
	encontrado++;
	//	if j = 0;
      }
      else{
      }
    }
    fseek(in,0,0);
    while (!feof(in) &&  encontrado == 1){
      if(tmp.a >= (a-8) && tmp.a <= a){
	if (strcasecmp(tmp.id_eqA,IDeq) == 0){
	  encontrado ++;
	  puntos2 = tmp.puntosacA;
	}
	else if(strcasecmp(tmp.id_eqB,IDeq) == 0){
	  encontrado ++;
	  puntos2 = tmp.puntosacB;
	}
      }
    }
    fclose(in); 
  }
  else
  {
    return 1;
  }
  if (encontrado ==2)
    return(puntos2 - puntos1);
  else if (encontrado == 1)
    return (puntos2);
  else return 1;
}


//********************FNR:*******************************
// retorna el Factor Nivel Region respecto el id de seleccion

float FNR(char idsel[]){
  FILE * in;
  seleccion tmpsel;
  confederacion tmp;
  bool salir = false;
  if((in = fopen(ArchSelec,"rb"))!=NULL){
    while (!feof(in) && salir ==false){
      fread(&tmpsel,sizeof(tmpsel),1,in);
      if (strcasecmp(tmpsel.id,idsel) == 0 && salir ==false){
	salir = true; 
      }
    }
    fclose(in);
  }
  if((in = fopen(ArchConfed,"rb"))!=NULL){
    while (!feof(in)){
      fread(&tmp,sizeof(tmp),1,in);
      if (strcasecmp(tmp.id,tmpsel.id_conf)==0 && !feof(in)){
	return (tmp.factor); 
      }
    }
    fclose(in);
  }
  return -1;
}


//*************************CalculaPuntosJuego()***************
// calcula puntos acumulados para cada equipo depenediendo del
// juego
int CalculaPuntosJuego(juego &RegData){
  float PCEA = 0,PCEB = 0,/*fit = 0,*/fnrea = 0,fnreb = 0,bonif = 0,
    FCEA = 0,FCEB = 0,pra =0, prb = 0,totalA = 0,totalB = 0,
    bonifA = 0,bonifB =0; 
  //  float PAA_0 = 0,PAA_1 = 0, PAB_0 = 0, PAB_1 = 0;
  float factor;
  //  bool salir = false;
  int ResPartido = 0, puntosprevA = 0, puntosprevB=0;
  //  int size = 0 , i = 0,j = 0;
  FILE * in;
  //  juego tmp;
  torneo torn;

  // -->>Puntos Iniciales
  if (RegData.golA > RegData.golB){
    PCEA = 1;
    pra = 3;
    ResPartido = 1;
    
  }
  else if (RegData.golA == RegData.golB){
    if (RegData.penA > RegData.penB){
      PCEA = 1;
      pra = 3;
      prb = 1;
    }
    else if(RegData.penA == RegData.penB){
      PCEB = 1;
      prb = 1; 
      PCEA = pra = 1;}
    else{
      PCEB = 1;
      pra = 1;
      prb = 3;
      ResPartido = 2;
    }
  }
  else{
    PCEB = 1;
    prb =3;
    ResPartido = 3;
  }
  // Calcula PCEA, y PCEB
  PCEA = PClasif(RegData.id_eqA,RegData.a,puntosprevA);
  PCEB = PClasif(RegData.id_eqB,RegData.a,puntosprevB);
  // Calcula factor && Bonif
  if ((in=fopen(ArchTorneo,"rb"))!=NULL){
    while(!feof(in)){
      fread(&torn,sizeof(torn),1,in);
      if (!feof(in) && (strcasecmp(torn.id,RegData.id_torneo)==0)){
	factor = torn.factor;
	bonif = torn.bonif_vis;
      }
    }
    fclose(in);
  }
  // calcula FNREA y FNREB
  fnrea = FNR(RegData.id_eqA);
  fnreb = FNR(RegData.id_eqB);
  // Calcula FCEA,FCEB;
  if (PCEB != 0)
    FCEA = PCEA/PCEB;
  else 
    FCEA = 1;
  if (PCEA != 0)
    FCEB = PCEB/PCEA;
  else
    FCEB = 1;
  // Calcula BonifA && BonifB
  if (strcasecmp(RegData.id_eqA,RegData.local)==0)
    bonifB=bonif;
  else
    bonifA=bonif;
  // Calcula Totales
  totalA = ((pra*FCEA*10)+((RegData.golA)*FCEA*3)-
	    ((RegData.golB)*FCEA*3)+bonifA)*fnrea*factor;
  totalB = ((prb*FCEB*10)+((RegData.golB)*FCEB*3)-
	    ((RegData.golA)*FCEB*3)+bonifB)*fnreb*factor;
  //Escribe puntos actuales del juego
  RegData.punteoA = round(totalA);
  RegData.punteoB = round(totalB);
  //Escribe total de puntos actual acumulado
  if ((puntosprevA + totalA) >= 0)
    RegData.puntosacA = round(puntosprevA + totalA);
  else
    RegData.puntosacA = 1;
  if ((puntosprevB + totalB)>=0)
    RegData.puntosacB = round(puntosprevB + totalB);
  else
    RegData.puntosacB = 1;

  //  RegData.puntosacA = round(puntosprevA + totalA);
  //  RegData.puntosacB = round(puntosprevB + totalB);
  return 0;
}


//************************CreaJuego()*************************//
int CreaJuego(juego &RegData){
  FILE * arch;
  juego tmp;
  bool encontrado = 0;
  if(ValidarJuego(RegData)==0){ 
    CalculaPuntosJuego(RegData);
    if((arch = fopen(ArchJuegos,"r+b"))!=NULL){ // si archivo existe
      if(sizeoffile(arch)>0){ // tamano de archivo > 0
	// Busca dato anterior
	fseek(arch,-sizeof(RegData),SEEK_END);
	fread(&tmp,sizeof(tmp),1,arch);
	fclose(arch);
	// Compara Nombres y fechas, y si Fechas son mayores activa bandera
	if (strcasecmp(RegData.id_eqA,tmp.id_eqA)==0 && 
	    strcasecmp(RegData.id_eqB,tmp.id_eqB)==0){
	  if(RegData.a == tmp.a){
	    if(RegData.m == tmp.m){
	      if (RegData.d > tmp.d)
		encontrado = 1;
	      else return -1;
	    }
	    else if (RegData.m > tmp.m)
	      encontrado = 1;
	    else return -1;
	  }
	  else if (RegData.a > tmp.a)
	    encontrado = 1;
	  else return -1;
	}
	else encontrado = 1;
      }
      //Escribe Datos si tamano es 0
      else {
	fseek(arch,0,SEEK_END);
	fwrite(&RegData,sizeof(RegData),1,arch);
	fclose(arch);
	return 0;
      }
      //  fclose(arch);
    }
    //Escribe Datos si no existe archivo
    else {
      arch = fopen(ArchJuegos,"a+b");
      fwrite(&RegData,sizeof(RegData),1,arch);
      fclose(arch);
      return 0;
    }
  }
  else return (-2); //Error, Fecha sin sentido

  //Calcula y Escribe Datos
  if (encontrado == true){
    //    CalculaPuntosJuego(RegData);
    arch = fopen(ArchJuegos,"a+b");
    fwrite(&RegData,sizeof(RegData),1,arch);
    fclose(arch);
    return 0;
  }
  return 0;
}


//*********************** Menu (06-09):***********************//
// Escribe en pantalla menu principal
// Devuelve un entero dependiendo la opcion seleccionada.
int menu(void){
  int eleccion = 0;
  cout //<< endl << endl 
       << "Bienvenido a FIRST" << endl
       << "==================" << endl
       << "(FIFA Ranking System)" << endl << endl;
  cout << "Proyecto 1: IPC 2 " << endl
       << "(c) 2005 Erik Vladimir Giron Marquez" << endl //<< endl << endl
       <<endl<<endl;
  cout << "\tMENU PRINCIPAL" << endl
       << "\t--------------" <<endl
       << "\tSeleccione lo que desea hacer" << endl
       << "\t\t1. Seleccionar Archivo de Entrada..." << endl
       << "\t\t2. Seleccionar Archivo de Salida..." << endl
       << "\t\t3. Procesar datos y generar reporte..." << endl
       << "\t\t[cualquier otra tecla] SALIR..." << endl
    /*<<endl<<endl*/ <<endl<<endl <<"\t\tIngrese su opcion-> ";
  cin >> eleccion;
  //  eleccion = getchar();
  // codigo menu
  if ((eleccion > 0) && (eleccion < 4))
    return eleccion;
  else
    return 0;
}

//***********************Inicializar()***********************
// Inicializa todos los archivos y variables a 0
void inicializar() {
  FILE * out;
  // Inicializa salida
  if((out = fopen(salida,"wt"))!=NULL) {
    fprintf(out,"\t\tReporte General\n\n");
    fclose(out);
  }
  // Inicializa Archivo Confederacion
  if((out = fopen(ArchConfed,"wb"))!=NULL) {
    fwrite(0,0,1,out);
    fclose(out);
  }
  if((out = fopen(ArchIdxConfed,"wb"))!=NULL) {
    fwrite(0,0,1,out);
    fclose(out);
  }
  if((out = fopen(ArchSelec,"wb"))!=NULL) {
    fwrite(0,0,1,out);
    fclose(out);
  }
  if((out = fopen(ArchTorneo,"wb"))!=NULL) {
    fwrite(0,0,1,out);
    fclose(out);
  }
  if((out = fopen(ArchJuegos,"wb"))!=NULL) {
    fwrite(0,0,1,out);
    fclose(out);
  }
  if((out = fopen(ArchPuntosac,"wb"))!=NULL) {
    fwrite(0,0,1,out);
    fclose(out);
  }
  if((out = fopen(ArchIdxPuntosac,"wb"))!=NULL) {
    fwrite(0,0,1,out);
    fclose(out);
  }
  if((out = fopen(ArchEqYear,"wb"))!=NULL) {
    fwrite(0,0,1,out);
    fclose(out);
  }
  if((out = fopen(ArchDesemp,"wb"))!=NULL) {
    fwrite(0,0,1,out);
    fclose(out);
  }
  if((out = fopen(ArchClasif,"wb"))!=NULL) {
    fwrite(0,0,1,out);
    fclose(out);
  }

  msgerr("Se ha inicializado todos los archivos",0);
}

//***********************cmd_creaconfed()***********************
// Analiza la instruccion crear_confederacion y guarda 
// a archivos binarios
int cmd_creaconfed(confederacion &RegData) { 
  //Aqui van los registros a escribir
  //  confederacion RegData;
  //no usa  idx IdxConfed;

  //no usa FILE * out; // archivo de salida
  unsigned int errnum = 0; // contador de errores
  unsigned int i = 0; // contador principal de identificadores
  unsigned int numerr = 0;
  char floatnum[10];
  floatnum[0] = 0;
  //no usaint posidx = 0;

  // Inicializacion
  RegData.id[0]=0;
  RegData.nombre[0]=0;
  RegData.factor=0;
  floatnum[0] = 0;

  // Reconocimiento sintactico
  // Si estado anterior es '('
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0){ // mientras no se llegue a ';'
      Token(1);
      switch (estado){
	// CASO NUMERAL
      case E_num: 
	// validacion para dato factor (float)
	if (i==2){
	  while ((estado != E_coma) && (estado != E_parC)){
	    if ((isdigit(lexema[0]))!=0 || lexema[0]=='.') 
	      strcat(floatnum,lexema);
	    else
	      msgerr("El valor de factor debe ser numerico",1);
	    Token(1);
	  }
	  if (floatnum[0]!=0)
	    RegData.factor = atof(floatnum);
	}
	else
	  {
	    msgerr("Se esperaba valor numerico",1);
	    numerr++;
	  }
	i++;
	break;
	//CASO APOSTROFO
      case E_apos: 
	Token(1);
	while((estado !=E_apos)) {
	  //Validacion para id (string)
	  if (i==0){
	    if (strlen(lexema) <= 10)
	      strcat(RegData.id,lexema);
	    else{
	      msgerr(" Identificador debe ser menor a 10 ",1);
	      numerr++;
	    }
	  }
	  else if (i==1 /*&& estado == E_identificador*/){
	    //Validacion para nombre (string)
	    if (strlen(lexema) <= 40 ){
	      strcat(RegData.nombre,lexema);
	      strcat(RegData.nombre," ");
	    }
	    else{
	      msgerr(" Identificador debe ser menor a 40 ",1);
	      numerr++;
	    }
	  }
	  else{
	    //	    error("cadena incorrecta!!");
	    msgerr("Cadena Incorrecta!!",1);
	    errnum++;
	  }
	  Token(1);
	}
	i++;
	break;
	//Caso para Coma
      case E_coma:
	break;
      case E_puncoma:
	break;
      case E_parC:
	break;
	//OTRO CASO ERROR
      default:
	errnum++;
	msgerr("Se esperaba otro tipo de lexema, esta instruccion sera ignorada",1);
	break;
      }
    }
  }
  else {
    msgerr("Sintaxis incorrecta!!",1);
    errnum++;
  }
  return errnum;
}

//***********************cmd_CreaSelec()***********************
// parser para comando crea_seleccion
int cmd_creaselec(seleccion &RegData) { 
  //Aqui van los registros a escribir
  //no usa//  seleccion RegData;
  //no usa//  idx IdxData;

  //no usa//  FILE * out; // archivo de salida
  unsigned int errnum = 0; // contador de errores
  unsigned int i = 0; // contador principal de identificadores
  unsigned int numerr = 0;
  char floatnum[10];

  RegData.id[0]=0;
  RegData.nombre[0]=0;
  RegData.id_conf[0]=0;
  floatnum[0] = 0;

  // Reconocimiento sintactico
  // Si estado anterior es '('
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0){ // mientras no se llegue a ';'
      Token(1);
      switch (estado){
	//CASO APOSTROFO
      case E_apos: 
	Token(1);
	while((estado !=E_apos)) {
	  //Validacion para id (string)
	  if (i==0){
	    if (strlen(lexema) <= 6)
	      strcat(RegData.id,lexema);
	    else{
	      msgerr(" Identificador debe ser menor a 10 ",1);
	      numerr++;
	    }
	  }
	  else if (i==1/* && estado == E_identificador*/){
	    //Validacion para nombre (string)
	    if (strlen(lexema) <= 40 ){
	      strcat(RegData.nombre,lexema);
	      strcat(RegData.nombre," ");
	    }
	    else{
	      msgerr(" Identificador debe ser menor a 40 ",1);
	      numerr++;
	    }
	  }
	  else if (i==2/* && estado == E_identificador*/){
	    //Validacion para id_conf (string)
	    if (strlen(lexema) <= 10 ){
	      strcat(RegData.id_conf,lexema);
	    }
	    else{
	      msgerr(" Identificador debe ser menor a 40 ",1);
	      numerr++;
	    }
	  }
	  else{
	    //	    error("cadena incorrecta!!");
	    msgerr("Cadena Incorrecta!!",1);
	    errnum++;
	  }
	  Token(1);
	}
	i++;
	break;
	//Caso para caracteres insignificantes
      case E_coma: break;
      case E_puncoma: break;
      case E_parC: break;
	//OTRO CASO ERROR
      default:
	errnum++;
	msgerr("Se esperaba otro tipo de lexema, esta instruccion sera ignorada",1);
	break;
      }
    }
  }
  else {
    msgerr("Sintaxis incorrecta!!",1);
    errnum++;
  }
  return errnum;
}

// ***********************cmd_creatorneo()***********************
// parser para comando crear_torneo;
// PARSER BASE
int cmd_creatorneo(torneo &RegData) { 
  //Aqui van los registros a escribir
  //no usa//  seleccion RegData;
  //no usa//  idx IdxData;

  //no usa//  FILE * out; // archivo de salida
  unsigned int errnum = 0; // contador de errores
  unsigned int i = 0; // contador principal de identificadores
  unsigned int numerr = 0;
  char floatnum[10];

  floatnum[0] = 0;
  RegData.id[0]=0;
  RegData.nombre[0]=0;
  RegData.esoficial=false;
  RegData.bonif_vis=0;
  RegData.factor = 0;

  // Reconocimiento sintactico
  // Si estado anterior es '('
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0){ // mientras no se llegue a ';'
      Token(1);
      switch (estado){
	//CASO APOSTROFO
      case E_apos: 
	Token(1);
	while((estado !=E_apos)) {
	  //Validacion para id (string)
	  if (i==0){
	    if (strlen(lexema) <= 10)
	      strcat(RegData.id,lexema);
	    else{
	      msgerr(" Identificador debe ser menor a 10 ",1);
	      numerr++;
	    }
	  }
	  else if (i==1/* && (estado == E_identificador || estado == E_num)*/){
	    //Validacion para nombre (string)
	    if (strlen(lexema) <= 50 ){
	      strcat(RegData.nombre,lexema);
	      strcat(RegData.nombre," ");
	    }
	    else{
	      msgerr(" Identificador debe ser menor a 50 ",1);
	      numerr++;
	    }
	  }
	  else if (i==2 && estado == E_identificador){
	    //Validacion para esoficial (string)
	    if (strlen(lexema) == 1){
	      if (strcasecmp(lexema,"S")==0)
		RegData.esoficial = true;
	      else if (strcasecmp(lexema,"N")==0)
		RegData.esoficial = false;
	      else{
		msgerr("Se esperaba s o n para campo ",1);
		numerr++;
	      }
	    }
	    else{
	      msgerr(" Se esperaba 1 caracter s o n ",1);
	      numerr++;
	    }
	  }
	  else{
	    //	    error("cadena incorrecta!!");
	    msgerr("Cadena Incorrecta!!",1);
	    errnum++;
	  }
	  Token(1);
	}
	i++;
	break;
      case E_num: 
	// validacion para dato factor (float)
	if (i==3){
	  //	  while ((estado != E_coma) && (estado != E_parC)){
	    if ((isdigit(lexema[0]))!=0)
	      RegData.bonif_vis = atoi(lexema);
	    else {
	      msgerr("El valor de factor debe ser numerico",1);
	      numerr++;
	      	    }
	    //	    Token(1);
	    //	  }
	}
	else if (i==4){
	  while ((estado != E_coma) && (estado != E_parC)){
	    if ((isdigit(lexema[0]))!=0 || lexema[0]=='.') 
	      strcat(floatnum,lexema);
	    else
	      msgerr("El valor de factor debe ser numerico",1);
	    Token(1);
	  }
	  if (floatnum[0]!=0)
	    RegData.factor = atof(floatnum);
	}
	else
	  {
	    msgerr("Se esperaba valor numerico",1);
	    numerr++;
	  }
	i++;
	break;
	//Caso para caracteres insignificantes
      case E_coma: break;
      case E_puncoma: break;
      case E_parC: break;
	//OTRO CASO ERROR
      default:
	errnum++;
	msgerr("Se esperaba otro tipo de lexema, esta instruccion sera ignorada",1);
	break;
      }
    }
  }
  else {
    msgerr("Sintaxis incorrecta!!",1);
    errnum++;
  }
  return errnum;
}

// ***********************cmd_juego()***********************
// parser para comando juego;
int cmd_juego(juego &RegData) { 
  //Aqui van los registros a escribir

  unsigned int errnum = 0; // contador de errores
  unsigned int i = 0; // contador principal de identificadores
  unsigned int numerr = 0;
  char floatnum[10];

  floatnum[0] = 0;
  RegData.local[0]=0;
  RegData.id_eqA[0]=0;
  RegData.id_eqB[0]=0;
  RegData.id_torneo[0]=0;
  RegData.golA=0;
  RegData.golB=0;
  RegData.penA=0;
  RegData.penB=0;
  RegData.duracion = 0;
  RegData.d = RegData.m = RegData.a = 0;
  RegData.puntosacA = RegData.puntosacB = 0;

  // Reconocimiento sintactico
  // Si estado anterior es '('
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0){ // mientras no se llegue a ';'
      Token(1);
      switch (estado){
	//CASO APOSTROFO
      case E_apos: 
	Token(1);
	while((estado !=E_apos)) {
	  //Validacion para ideqA (string)
	  if (i==0){
	    if (strlen(lexema) <= 5)
	      strcat(RegData.id_eqA,lexema);
	    else{
	      msgerr(" Identificador debe ser menor a 5 ",1);
	      numerr++;
	    }
	  }
	  //Validacion para ideqB (string)
	  else if (i==1){
	    if (strlen(lexema) <= 5)
	      strcat(RegData.id_eqB,lexema);
	    else{
	      msgerr(" Identificador debe ser menor a 5 ",1);
	      numerr++;
	    }
	  }
	  //Validacion para local (string)
	  else if (i==2){
	    if (strlen(lexema) <= 5)
	      strcat(RegData.local,lexema);
	    else{
	      msgerr(" Identificador debe ser menor a 5 ",1);
	      numerr++;
	    }
	  }
	  //Validacion para id_torneo (string)
	  else if (i==11){
	    if (strlen(lexema) <= 10)
	      strcat(RegData.id_torneo,lexema);
	    else{
	      msgerr(" Identificador debe ser menor a 10 ",1);
	      numerr++;
	    }
	  }
	  else{
	    //	    error("cadena incorrecta!!");
	    msgerr("Cadena Incorrecta!!",1);
	    errnum++;
	  }
	  Token(1);
	}
	i++;
	break;
      case E_num: 
	// validacion para dato factor (float)
	if (i==3){
	  if ((isdigit(lexema[0]))!=0)
	    RegData.golA= atoi(lexema);
	  else {
	    msgerr("El valor debe ser numerico",1);
	    numerr++;
	  }
	}
	else if (i==4){
	  if ((isdigit(lexema[0]))!=0)
	    RegData.golB = atoi(lexema);
	  else {
	    msgerr("El valor  debe ser numerico",1);
	    numerr++;
	  }
	}
  	else if (i==5){
	  if ((isdigit(lexema[0]))!=0)
	    RegData.penA = atoi(lexema);
	  else {
	    msgerr("El valor  debe ser numerico",1);
	    numerr++;
	  }
	}
	else if (i==6){
	  if ((isdigit(lexema[0]))!=0)
	    RegData.penB = atoi(lexema);
	  else {
	    msgerr("El valor  debe ser numerico",1);
	    numerr++;
	  }
	}
	else if (i==7){
	  if ((isdigit(lexema[0]))!=0)
	    RegData.duracion = atoi(lexema);
	  else {
	    msgerr("El valor  debe ser numerico",1);
	    numerr++;
	  }
	}
	else if (i==8){
	  if ((isdigit(lexema[0]))!=0)
	    RegData.d = atoi(lexema);
	  else {
	    msgerr("El valor  debe ser numerico",1);
	    numerr++;
	  }
	}
	else if (i==9){
	  if ((isdigit(lexema[0]))!=0)
	    RegData.m = atoi(lexema);
	  else {
	    msgerr("El valor  debe ser numerico",1);
	    numerr++;
	  }
	}
	else if (i==10){
	  if ((isdigit(lexema[0]))!=0)
	    RegData.a = atoi(lexema);
	  else {
	    msgerr("El valor debe ser numerico",1);
	    numerr++;
	  }
	}
	else  {
	  msgerr("Se esperaba valor numerico",1);
	  numerr++;
	}
	i++;
	break;
	//Caso para caracteres insignificantes
      case E_coma: break;
      case E_puncoma: break;
      case E_parC: break;
	//OTRO CASO ERROR
      default:
	errnum++;
	msgerr("Se esperaba otro tipo de lexema, esta instruccion sera ignorada",1);
	break;
      }
    }
  }
  else {
    msgerr("Sintaxis incorrecta!!",1);
    errnum++;
  }
  return errnum;
}

// ***********************cmd_puntosac()***********************
// parser para comando puntos_acumulados;
int cmd_puntosac(intervfecha &RegData){ 
  //Aqui van los registros a escribir

  unsigned int errnum = 0; // contador de errores
  unsigned int i = 0; // contador principal de identificadores
  unsigned int numerr = 0;
  char floatnum[10];

  floatnum[0] = 0;
  RegData.m0 = RegData.m1 = RegData.a0 = RegData.a1= 0;

  // Reconocimiento sintactico
  // Si estado anterior es '('
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0){ // mientras no se llegue a ';'
      Token(1);
      switch (estado){
	//CASO NUMERICO
      case E_num: 
	if (i==0){
	    if ((isdigit(lexema[0]))!=0)
	      RegData.a0 = atoi(lexema);
	    else {
	      msgerr("El valor de factor debe ser numerico",1);
	      numerr++;
	      	    }
	    //	    Token(1);
	    //	  }
	}
	else if (i==1){
	    if ((isdigit(lexema[0]))!=0)
	      RegData.m0 = atoi(lexema);
	    else {
	      msgerr("El valor de factor debe ser numerico",1);
	      numerr++;
	      	    }
	    //	    Token(1);
	    //	  }
	}
	else if (i==2){
	    if ((isdigit(lexema[0]))!=0)
	      RegData.a1 = atoi(lexema);
	    else {
	      msgerr("El valor de factor debe ser numerico",1);
	      numerr++;
	      	    }
	    //	    Token(1);
	    //	  }
	}
	else if (i==3){
	    if ((isdigit(lexema[0]))!=0)
	      RegData.m1 = atoi(lexema);
	    else {
	      msgerr("El valor de factor debe ser numerico",1);
	      numerr++;
	      	    }
	    //	    Token(1);
	    //	  }
	}
	else
	  {
	    msgerr("Se esperaba valor numerico",1);
	    numerr++;
	  }
	i++;
	break;
	//Caso para caracteres insignificantes
      case E_coma: break;
      case E_puncoma: break;
      case E_parC: break;
	//OTRO CASO ERROR
      default:
	errnum++;
	msgerr("Se esperaba otro tipo de lexema, esta instruccion sera ignorada",1);
	break;
      }
    }
  }
  else {
    msgerr("Sintaxis incorrecta!!",1);
    errnum++;
  }
  return errnum;
}

// ***********************cmd_premio_me()***********************
// parser para comando premio_mejor_equipo;
// PARSER BASE
int cmd_premio_me(eq_year &RegData) { 
  //Aqui van los registros a escribir
  unsigned int errnum = 0; // contador de errores
  unsigned int i = 0; // contador principal de identificadores
  unsigned int numerr = 0;
  char floatnum[10];

  floatnum[0] = 0;
  RegData.id[0]=0;
  RegData.nombre[0]=0;
  RegData.punteo=0;
  RegData.aa = 0;

  // Reconocimiento sintactico
  // Si estado anterior es '('
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0){ // mientras no se llegue a ';'
      Token(1);
      switch (estado){
	//CASO APOSTROFO
      case E_num: 
	// validacion para dato factor (float)
	if (i==0){
	  //	  while ((estado != E_coma) && (estado != E_parC)){
	    if ((isdigit(lexema[0]))!=0)
	      RegData.aa = atoi(lexema);
	    else {
	      msgerr("El valor de factor debe ser numerico",1);
	      numerr++;
	      	    }
	    //	    Token(1);
	    //	  }
	}
	i++;
	break;
	//Caso para caracteres insignificantes
      case E_coma: break;
      case E_puncoma: break;
      case E_parC: break;
	//OTRO CASO ERROR
      default:
	errnum++;
	msgerr("Se esperaba otro tipo de lexema, esta instruccion sera ignorada",1);
	break;
      }
    }
  }
  else {
    msgerr("Sintaxis incorrecta!!",1);
    errnum++;
  }
  return errnum;
}

// ***********************cmd_mejor_desemp()***********************
// parser para comando premio_mejor_equipo;
// PARSER BASE
int cmd_mejor_desemp(desemp &RegData) { 
  //Aqui van los registros a escribir
  unsigned int errnum = 0; // contador de errores
  unsigned int i = 0; // contador principal de identificadores
  unsigned int numerr = 0;
  char floatnum[10];

  floatnum[0] = 0;
  RegData.id[0]=0;
  RegData.nombre[0]=0;
  RegData.puntos=0;
  RegData.aa = 0;

  // Reconocimiento sintactico
  // Si estado anterior es '('
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0){ // mientras no se llegue a ';'
      Token(1);
      switch (estado){
	//CASO APOSTROFO
      case E_num: 
	// validacion para dato factor (float)
	if (i==0){
	  //	  while ((estado != E_coma) && (estado != E_parC)){
	    if ((isdigit(lexema[0]))!=0)
	      RegData.aa = atoi(lexema);
	    else {
	      msgerr("El valor de factor debe ser numerico",1);
	      numerr++;
	      	    }
	    //	    Token(1);
	    //	  }
	}
	i++;
	break;
	//Caso para caracteres insignificantes
      case E_coma: break;
      case E_puncoma: break;
      case E_parC: break;
	//OTRO CASO ERROR
      default:
	errnum++;
	msgerr("Se esperaba otro tipo de lexema, esta instruccion sera ignorada",1);
	break;
      }
    }
  }
  else {
    msgerr("Sintaxis incorrecta!!",1);
    errnum++;
  }
  return errnum;
}

// ***********************cmd_clasif()***********************
// parser para comando clasificacion;
int cmd_clasif(clasif &RegData){ 
  //Aqui van los registros a escribir

  unsigned int errnum = 0; // contador de errores
  unsigned int i = 0; // contador principal de identificadores
  unsigned int numerr = 0;
  char floatnum[10];

  floatnum[0] = 0;
  RegData.id[0] = RegData.nombre[0] = 0;
  RegData.mm = RegData.aa = RegData.puntos = RegData.diffpuntos= 0;

  // Reconocimiento sintactico
  // Si estado anterior es '('
  if (estado == E_parA){
    while(estado != E_puncoma && i >= 0 && errnum == 0){ // mientras no se llegue a ';'
      Token(1);
      switch (estado){
	//CASO NUMERICO
      case E_num: 
	if (i==0){
	    if ((isdigit(lexema[0]))!=0)
	      RegData.aa = atoi(lexema);
	    else {
	      msgerr("El valor de a~no debe ser numerico",1);
	      numerr++;
	      	    }
	    //	    Token(1);
	    //	  }
	}
	else if (i==1){
	    if ((isdigit(lexema[0]))!=0)
	      RegData.mm = atoi(lexema);
	    else {
	      msgerr("El valor de mes debe ser numerico",1);
	      numerr++;
	      	    }
	    //	    Token(1);
	    //	  }
	}
	else
	  {
	    msgerr("Se esperaba valor numerico",1);
	    numerr++;
	  }
	i++;
	break;
	//Caso para caracteres insignificantes
      case E_coma: break;
      case E_puncoma: break;
      case E_parC: break;
	//OTRO CASO ERROR
      default:
	errnum++;
	msgerr("Se esperaba otro tipo de lexema, esta instruccion sera ignorada",1);
	break;
      }
    }
  }
  else {
    msgerr("Sintaxis incorrecta!!",1);
    errnum++;
  }
  return errnum;
}

// Identificacion sintactica de la instruccion 
// ***********************parse():***********************
// Analiza sintacticamente el archivo de entrada y llama a funciones
// encargadas de cada instruccion.
int parse(char * filename)
{
  int salir = 0, ret = 0;
  char mensaje[300];
  bool juegoCalculado = false; //Bandera para verificar si ya se calculo juego
  //  int Ret
  confederacion RegConfed;
  seleccion RegSelec;
  torneo RegTorneo;
  juego RegJuego;
  intervfecha RegIFecha;
  eq_year RegPremio;
  desemp RegDesemp;
  clasif RegClasif;
  // Si no se logra abrir archivo por rutina de scanner
  if(!abre_arch(filename)) {
    return -1;
  }
  else {
    while(!feof(file_in) && salir<32000){
      Token(1);
      switch(estado){
      case 40:
	Token(1);
	printf("- Instruccion crear_confederacion en linea No. %d a archivo \'%s\'\n",numlinea,ArchConfed);
	if(cmd_creaconfed(RegConfed) == 0){
	  ret = ActualizaConfed(RegConfed);
	  if(ret == 0)
	    sprintf(mensaje,"Linea#%d\nSe Creo la confederacion %s con factor nivel de %f ",
		    numlinea,RegConfed.nombre,RegConfed.factor);
	  else
	    sprintf(mensaje,"Linea#%d\nSe Actualizo la confederacion %s con factor nivel de %f ",
		    numlinea,RegConfed.nombre,RegConfed.factor);
	  msgerr(mensaje,2);
	}
	else
	  msgerr("Se encontraron 1 o mas errores, la instruccion actual sera ignorada",1);
	break;
      case 41:
	Token(1);
	printf("- Instruccion Crear_Seleccion en linea No. %d a archivo \'%s\'\n",numlinea,ArchSelec);
	
	if(cmd_creaselec(RegSelec) == 0){
	  ret = ActualizaSelec(RegSelec);
	  if(ret == 0)
	    sprintf(mensaje,"Linea#%d\nSe Creo la seleccion %s y se asigno a la %s ",
		    numlinea,RegSelec.nombre,RegSelec.id_conf);
	  else if (ret == 1)
	    sprintf(mensaje,"Linea#%d\nSe Actualizo la seleccion %s y se asigno a la %s ",
		    numlinea,RegSelec.nombre,RegSelec.id_conf);
	  else
	    sprintf(mensaje,"Linea#%d\n,Imposible crear seleccion %s, no existe confederacion %s ",
		    numlinea,RegSelec.nombre,RegSelec.id_conf);
	  msgerr(mensaje,2);
	}
	else
	  msgerr("Se encontraron 1 o mas errores, la instruccion actual sera ignorada",1);

      	break;
      case 42:
	Token(1);
	printf("- Instruccion crear_torneo en linea No. %d a archivo \'%s\'\n",numlinea,ArchTorneo);
	if(cmd_creatorneo(RegTorneo) == 0){
	  ret = ActualizaTorneo(RegTorneo);
	  if(ret == 0)
	    sprintf(mensaje,"Linea#%d\nSe Creo el torneo %s(%s), la bonificacion para visitantes es %d ",
		    numlinea,RegTorneo.nombre,RegTorneo.id,RegTorneo.bonif_vis);
	  else if (ret == 1)
	    sprintf(mensaje,"Linea#%d\nSe Actualizo el torneo %s(%s), la bonificacion para visitantes es %d ",
		    numlinea,RegTorneo.nombre,RegTorneo.id,RegTorneo.bonif_vis);
	  else
	    sprintf(mensaje,"Linea#%d\nImposible crear torneo  %s(%s), El factor debe ser mayor a 0 ",
		    numlinea,RegTorneo.nombre,RegTorneo.id);
	  msgerr(mensaje,2);
	}
	else
	  msgerr("Se encontraron 1 o mas errores, la instruccion actual sera ignorada",1);

	//funcion crear torneo
	break;
      case 43:
	Token(1);
	printf("- Instruccion Juego en linea No. %d a archivo \'confed.bin\'\n",numlinea);
	if(cmd_juego(RegJuego) == 0){
	  ret = CreaJuego(RegJuego);
	  if(ret == 0){
	    juegoCalculado = true;
	    sprintf(mensaje,"Linea#%d\nTorneo = %s, Juego %d de %s, %d, %s - %d, %s - %d, en %d Minutos. Puntos de Clasificacion obtenidos: %s : %d, %s : %d",
		    numlinea,RegJuego.id_torneo,RegJuego.d,mes(RegJuego.m),RegJuego.a,RegJuego.id_eqA,RegJuego.golA,
		    RegJuego.id_eqB,RegJuego.golB,RegJuego.duracion,
		    RegJuego.id_eqA,RegJuego.punteoA,RegJuego.id_eqB,RegJuego.punteoB);
	  }
	  else if (ret == -1)
	    sprintf(mensaje,"Linea#%d\nFecha de Juego Invalida, ingrese fecha despues de %d/%d/%d Se Ignora Instruccion",
		    numlinea,RegJuego.d,RegJuego.m,RegJuego.a);
	  else
	    sprintf(mensaje,"Linea#%d\nImposible crear torneo  %s(%s), El factor debe ser mayor a 0 ",
		    numlinea,RegTorneo.nombre,RegTorneo.id);
	  msgerr(mensaje,2);
	}
	else
	  msgerr("Se encontraron 1 o mas errores, la instruccion actual sera ignorada",1);
	
	break;
      case 44:
	Token(1);
	
	if (cmd_puntosac(RegIFecha) == 0 && juegoCalculado){
	  if(ValidaFecha(RegIFecha) == 0){
	    PuntosAC(RegIFecha);
	    CrearIndicePuntos();
	    printPuntosAc(RegIFecha);
	    //	    flush(ArchPuntosac); // borra archivos Temporales
	    flush(ArchIdxPuntosac);
	    //sprintf(mensaje,"");
	  }
	  else{
	    sprintf(mensaje,"Linea#%d\nFecha sin sentido o no se ha calculado juego anterior, debe ingresar una fecha correcta y un juego previo a hacer los calculos",numlinea);
	  }
	  msgerr(mensaje,2);

	}
	//	printf("- Instruccion crear_confederacion en linea No. %d a archivo \'confed.bin\'\n",numlinea);
	// funcion puntos
	break;
      case 45:
	Token(1);
	if(cmd_premio_me(RegPremio)== 0 && juegoCalculado){
	  ret = eqA(RegPremio);
	  PremioME(RegPremio);
	  //	  flush(ArchEqYear); // Limpia el archivo
	    sprintf(mensaje,
		    "Linea#%d\nEn el A~no %d el mejor equipo fue %s con un punteo de %d.",
		    numlinea,RegPremio.aa,RegPremio.nombre,RegPremio.punteo);
	    msgerr(mensaje,2);
	}
	//	printf("- Instruccion premio_mejor_equipo en linea No. %d a archivo \'confed.bin\'\n",numlinea);
	//funcion prem_mejeq
	break;
      case 46:
	Token(1);
	if( cmd_mejor_desemp(RegDesemp) ==0 && juegoCalculado){
	  ret = prem_desemp(RegDesemp);
	  
	  //	  if (ret == 0) {
	    buscaDesemp(RegDesemp);
	    sprintf(mensaje,"Linea#%d\nEn el a~no %d el equipo con mejor desempeno fue %s que genero %ld puntos",
		    numlinea,RegDesemp.aa,RegDesemp.nombre,RegDesemp.puntos);
	    msgerr(mensaje,2);
		    //	  }
	}
	  
	//	printf("- Instruccion crear_confederacion en linea No. %d a archivo \'confed.bin\'\n",numlinea);
        //funcion premio desempeno
	break;
      case 47:
	Token(1);
	if(cmd_clasif(RegClasif)==0){
	  if (RegClasif.mm>0 && RegClasif.mm <13 && RegClasif.aa >= 1920){ // Validacion de Fechas
	    ret = Clasificacion(RegClasif);
	    //	    flush(ArchClasif);

	  }
	  else
	    sprintf(mensaje,"En linea #%d se encontro una fecha incorrecta para el comando Clasif",numlinea);
	  
	}
	//	printf("- Instruccion crear_confederacion en linea No. %d a archivo \'confed.bin\'\n",numlinea);
	// funcion clasificacion
	break;
      case 30:
	Token(1);
	inicializar();
	juegoCalculado = false;
	
	sprintf(mensaje,"Instruccion inicializiar en linea No. %d \n",numlinea);
	msgerr(mensaje,2);
	break;

      }
      salir ++;
    }
    cerrar_archivo();
    return 1;
  }
  return 0;
}

// *************************main()****************************
int main(int argc, char * argv[])
{
  int comando = -1;
  
  if (argc == 1){
    //codigo para cuando se pasa sin parametros el programa desde el shell

    entrada[0]=0;
    salida[0]=0;

    //Ciclo principal
    while (comando >= -1 && comando < 4){
      comando = menu();
      switch (comando){
      case 1:
	//codigo para cuando es opcion 1
	setInput(entrada);
	break;
      case 2:
	//codigo para cuando es opcion 2
	setOutput(salida);

	break;
      case 3:
	//codigo para cuando es opcion 3
#ifdef debug
	strcpy(entrada,"input.txt");
	strcpy(salida,"out.txt");
#endif
	if ((entrada[0] != 0) && (salida[0] != 0) && 
	    (strlen(entrada)>0) && (strlen(salida)>0)){
	  //parse
	  if (  parse(entrada)< 0)
	    msgerr("Imposible abrir archivo de entrada, ingrese otro por favor",0);
	}
	else{
	  //mensaje de advertencia para que escriba path de entrada y salida
	  msgerr("Imposible calcular, debe especificar primero archivo de entrada y salida",0);
	}
	break;
      case 4:
	break;
      default:
	cout << "<<< Hasta Pronto >>> ..." << endl 
	     << "Presione cualquier tecla para salir"<<endl;
	//	cin >> comando ;
	exit(0);
	//mensaje de error cuando no es ningun anterior
	break;
      }
    }
    return 0;
  }
  
  else if (argc > 1){
    //codigo para cuando se pasan parametros al programa desde el shell
    return 0;
  }
}

#endif
