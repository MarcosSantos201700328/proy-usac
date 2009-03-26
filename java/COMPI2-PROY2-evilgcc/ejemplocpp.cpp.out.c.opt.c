void suma() {
t1 = STACK[p];
t2 = p + 1;
t3 = STACK[t2];
t4 = t1 + t3;
STACK[p] = t4;
}
void resta() {
t6 = STACK[p];
t8 = STACK[t2];
t9 = t6 - t8;
STACK[p] = t9;
}
void main() {
STACK[p] = 10;
STACK[t2] = 15;
t13 = STACK[p];
t15 = STACK[t2];
STACK[t2] = t13;
t17 = p + 2;
STACK[t17] = t15;
p = p + 3;
suma();
p = p - 3;
t18 = STACK[p];
t19 = p + 2;
STACK[t19] = t18;
t21 = STACK[p];
t22 = p + 1;
t23 = STACK[t22];
STACK[t22] = t21;
STACK[t19] = t23;
p = p + 3;
resta();
p = p - 3;
t26 = STACK[p];
t27 = p + 3;
STACK[t27] = t26;
}
