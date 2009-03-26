#include <stdlib.h>
#include <stdio.h>
/*variables de prueba*/
class MiClase{
private:
	int int1;
	char char1;
	bool bool1;
public:
	MiClase();
	MiClase(int, char);
//	~MiClase();
	int doNothing();
/*protected:
	float float1;
*/
};

MiClase mc1;

int n;
char w;
float w2[20][10];
/*Clase de prueba*/

void haceNada2();

char* str1;

int a,b,c;

int haceNada(char, int);

/**Esto es necesario para cambiar entre declaraciones y definiciones*/
>>

void main(){
	mc1.doNothing();
	char c1;
	int c2,c3;
	c3 = haceNada(c1,c2);
}

int haceNada(char v1, int v2){		
	int f = 1;
	char matc[10][5];
	matc[f+1][v1] = matc[v2][matc[5][5]];
	switch (v1){
	case 0:
		a = 0;
	break;
	case 1:
		a = 1;
	break;
	default:
	break;
	}
/*
	int b1 = 5+v1;
	int b2 = 3+v2;
	
	
	
	while((b1 + a) > (b2 + b) || ((b1 + b) < b2)){
		b2 = b2 + b1;
	}

	if((v1 + 1) > v2){
		a++;
	}*/
}