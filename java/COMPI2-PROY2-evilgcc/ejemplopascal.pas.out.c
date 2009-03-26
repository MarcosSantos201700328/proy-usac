#include "ejemplopascal.pas.out.h"

void leer(){
printf("%s",'Numero 1: ');
t0 = p + 6;
t1 = STACK[ t0];
scanf("%d\n",&t1);
STACK[ t0] = t1;
printf("%s",'Numero 2: ');
t2 = p + 6;
t3 = STACK[ t2];
scanf("%d\n",&t3);
STACK[ t2] = t3;
}
void operar(){
t4 = numero1 + numero2;
t5 = p + 0;
STACK[ t5] = t4;
t6 = numero1 - numero2;
t7 = p + 0;
STACK[ t7] = t6;
if (numero2 == 0) goto L1;
goto L2;
L1:

t8 = p + 0;
STACK[ t8] = 0;
goto Lsig0;
L2:



t9 = numero1 / numero2;
t10 = p + 0;
STACK[ t10] = t9;
goto Lsig0;

t11 = numero1 * numero2;
t12 = p + 0;
STACK[ t12] = t11;
}
void main(){
t13 = p + 0;
STACK[ t13] = numero1;
t14 = p + 1;
STACK[ t14] = numero2;
p = p + 2;
leer();
p = p - 2;
t15 = STACK[p];
t16 = p + 0;
STACK[ t16] = suma;
t17 = p + 1;
STACK[ t17] = resta;
t18 = p + 2;
STACK[ t18] = multiplicacion;
t19 = p + 3;
STACK[ t19] = division;
p = p + 4;
operar();
p = p - 4;
t20 = STACK[p];
printf("%s%d",'Suma: ',suma);
printf("%s%d",'Resta: ',resta);
printf("%s%d",'Multiplicacion: ',multiplicacion);
printf("%s%f",'Division: ',division);
}
