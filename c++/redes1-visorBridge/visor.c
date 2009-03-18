#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  char ev = 0;
  while (!ev){
    printf("UNIVERSIDAD DE SAN CARLOS DE GUATEMALA\n");
    printf("FACULTAD DE INGENIERIA, INGENIERIA EN CIENCIAS Y SISTEMAS\n");
    printf("REDES DE COMPUTADORAS 1\n");
    printf("PROYECTO FINAL: ROUTING Y BRIDGING DINAMICO LINUX - WINDOWS\n");
    printf("GUATEMALA 19/NOV/2007\n");
    printf("MODULO DE MONITOREO DE INTERFACES DE RED\n");    
    printf("========================================\n");    
    printf("        =========================       \n");    
    printf("\t\tDIRECCIONES MAC\n");
    printf("\t\t================\n");
    system("brctl showmacs br0");
    printf("\n\n\t\tESTADO DE LOS PUERTOS:\n");
    printf("\t\t======================\n");
    system("ifconfig -s");
    system("clear");
    //ev = getchar();
  }
}
