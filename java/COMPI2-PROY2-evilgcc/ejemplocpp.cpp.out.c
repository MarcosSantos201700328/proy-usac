#include "ejemplocpp.cpp.out.h"

void suma(){
t0 = p + 0;
t1 = STACK[ t0];
t2 = p + 1;
t3 = STACK[ t2];
t4 = t1 + t3;
STACK[ p] = t4;
}
void resta(){
t5 = p + 0;
t6 = STACK[ t5];
t7 = p + 1;
t8 = STACK[ t7];
t9 = t6 - t8;
STACK[ p] = t9;
}
void main(){
t10 = p + 0;
STACK[ t10] = 10;
t11 = p + 1;
STACK[ t11] = 15;
t12 = p + 0;
t13 = STACK[ t12];
t14 = p + 1;
t15 = STACK[ t14];
t16 = p + 1;
STACK[ t16] = t13;
t17 = p + 2;
STACK[ t17] = t15;
p = p + 3;
suma();
p = p - 3;
t18 = STACK[p];
t19 = p + 2;
STACK[ t19] = t18;
t20 = p + 0;
t21 = STACK[ t20];
t22 = p + 1;
t23 = STACK[ t22];
t24 = p + 1;
STACK[ t24] = t21;
t25 = p + 2;
STACK[ t25] = t23;
p = p + 3;
resta();
p = p - 3;
t26 = STACK[p];
t27 = p + 3;
STACK[ t27] = t26;
}
