#include <R.h>
#include <Rdefines.h>
#include <string.h>

SEXP helloC1(SEXP greeting) {
  int i, vectorLength, stringLength;
  SEXP result;

  PROTECT(greeting = AS_CHARACTER(greeting));
  vectorLength = LENGTH(greeting);
  PROTECT(result = NEW_INTEGER(vectorLength));
  for (i=0; i<vectorLength; i++) {
    stringLength = strlen(CHAR(STRING_ELT(greeting, i)));
    INTEGER(result)[i] = stringLength;
  }
  UNPROTECT(2);
  return(result);
}




//#include <R.h>
//#include <Rdefines.h>

SEXP double_me(SEXP x) {
  // Doubles the value of the first integer element of the SEXP input
  SEXP result;
  PROTECT(result = NEW_INTEGER(1)); // i.e., a scalar quantity
  INTEGER(result)[0] = INTEGER(x)[0] * 2;
  UNPROTECT(1); // Release the one item that was protected
  return result;
}




// 向量的卷积运算
//extern "C" SEXP convolve2(SEXP a , SEXP b)
SEXP convolve2(SEXP a , SEXP b)
{
  int i, j, na, nb, nab;
  double *xa, *xb, *xab;
  SEXP ab;

  PROTECT( a = AS_NUMERIC( a ) );
  PROTECT( b = AS_NUMERIC( b ) );
  na = LENGTH( a ); nb = LENGTH( b ); nab = na + nb - 1;

  PROTECT( ab = NEW_NUMERIC( nab ) );
  xa = NUMERIC_POINTER ( a );
  xb = NUMERIC_POINTER ( b );
  xab = NUMERIC_POINTER ( ab );
  for ( i = 0; i < nab; i++)
    xab[i] = 0.0; //初始化为0

  for ( i = 0; i < na; i++)
    for ( j = 0; j < nb; j++)
      xab [i+j] += xa[i] * xb[j];

  UNPROTECT(3);
  return(ab);
}



// 两个数的加法
SEXP add2(SEXP a, SEXP b) {
  SEXP result = PROTECT(allocVector(REALSXP, 1));
  REAL(result)[0] = asReal(a) + asReal(b);
  UNPROTECT(1);

  return result;
}
