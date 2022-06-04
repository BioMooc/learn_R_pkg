#include<stdio.h>

void add(int* x, int* y){
  *x = *x + *y;
}

int main(){
  int a=1, b=2, a0;
  a0=a;
  add(&a,&b);
  printf("Hello R, from C, %d+%d=%d\n", a0, b, a);
  return 0;
}




/* useC2.c */
void useC2(int *i, double *d, char **c, int *l) {
  i[0] = 11;
  d[0] = 2.333;
  c[1] = "g";
  l[0] = 0;
}

