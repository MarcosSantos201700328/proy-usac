#include <stdio.h>
/*variables de prueba*/
class MiClase{
private:
	int int1;
	int int1;
	char int1;
	char char1;
	bool bool1;
public:
	MiClase();
	MiClase(int a, char b);
//	~MiClase();
	int doNothing();
/*protected:
	float float1;
*/
};

int n;
char w;
float w[20][10];
/*Clase de prueba*/

void haceNada();





char* str1;

/*Constructor*/
/*MiClase::MiClase(int a, char b){
	int1 = a;
	char1 = b;
	bool1 = TRUE;
}*/
/*No Hace ni maiz*/
// MiClase::doNothing(){
// 	haceNada();
// }
/*
void haceNada(){
	int i = 0;
	int j = 0;
	char b = 'c';
	MiClase *object = new MiClase(i,b);
	object->doNothing();		

	for(i=0; i < 100; i++){
		b = 'c';
		do{
			b++;
		} while (b < 'z');
		if (((i%3) == 0) || ((i%2) == 0)){
			printf("shit");	
			j++;
		}
		else{
			printf("noshit");
		}

	}
	
}*/
/*
int main(int argc, char* argv[]){
	int a = 1;
	char b = 'a';
	MiClase *object = new MiClase(a,b);
	object->doNothing();		
	haceNada();
}
*/