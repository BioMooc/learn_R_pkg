#include<stdio.h>

void addTo(int* x, int* y){
  int i=0;
  *y=0;
  for (i=0; i<=*x; i++){
    *y += i;
  }
}

/*
int main(){
  int a=100, b=0;
  addTo(&a, &b);
  printf("Hello R, from C, add 1+2+...+%d=%d\n", a, b);
  return 0;
}
*/
