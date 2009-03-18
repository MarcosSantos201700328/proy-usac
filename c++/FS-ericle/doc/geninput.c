#include <stdio.h>

int main(){
  FILE* out =fopen("salida.txt","a+b");
  int i;
  int j; 
    for(i =1; i<=10; i++){
	for(j=1;j<=10; j++){
     fprintf(out,"insert into LIBRO(libro,autor,titulo,edicion,cantidad)\n");
     fprintf(out,"values(%d,%d,%d,1,10);\n",((i-1)*10)+j,i,j);
	}
     }
     for(i = 1; i<=100; i++){
       fprintf(out,"insert into PRESTAMO(libro,usuario,fecha,fecha_vencimiento)\n");
       fprintf(out,"values(%d,%d,\"2006-10-%d\",\"2006-10-%d\");\n",i,2,i,i+20);	
     }
     for(i = 1; i<=100; i++){
       fprintf(out,"insert into PRESTAMO(libro,usuario,fecha,fecha_vencimiento)\n");
       fprintf(out,"values(%d,%d,\"2006-10-%d\",\"2006-10-%d\");\n",i,3,i,i+20);	
     }
     for(i = 1; i<=20; i++){
       for(j=1;j<=100; j++){
         fprintf(out,"insert into CONTENIDO(linea,texto,libro)\n");
         fprintf(out,"values(%d,\"%c%c%c%c\",%d);\n",j,(j%23)+'a',(j%23)+'b',(j%23)+'c',(j%23)+'d',i);	
	}
     }
  return 0;
}
