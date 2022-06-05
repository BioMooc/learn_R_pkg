#include <R.h>
#include <Rdefines.h>
#include <stdio.h>


SEXP helloA1() {
  printf("Hello World!\n");
  return(R_NilValue);
}
// 虽然返回值是 R_NilValue 也就是 NULL，但是函数类型依旧是 SEXP ，它只能是这一个类型。

