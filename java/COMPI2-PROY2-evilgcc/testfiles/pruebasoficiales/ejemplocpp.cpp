//NOMBRE FUNCIoN: suma
//DESCRIPCION: Retorna la suma de dos numeros.
int suma(int,int);
int resta(int, int);

>>

int suma(int num1,int num2)
{
    return(num1+num2);
}

//NOMBRE FUNCIoN: resta
//DESCRIPCIoN: Retorna la resta de dos numeros.
int resta(int num1,int num2)
{
    return(num1-num2);
}

//NOMBRE FUNCIoN: main
//DESCRIPCIoN: La ejecucion de nuestro programa comienza aqui.
void main()
{
    int a=10;
    int b=15;
    int resultadoSuma;
    int resultadoResta;
    //Llamada a las funciones suma y resta, almacenamos los
    //resultados en las variables resultadoSuma y resultadoResta.
    resultadoSuma=suma(a,b);
    resultadoResta=resta(a,b);
    //return 0;
}
