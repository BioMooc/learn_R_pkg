#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::NumericVector colSumsCpp(Rcpp::NumericMatrix mat) {
  size_t cols = mat.cols();
  Rcpp::NumericVector res(cols);
  for (size_t i=0; i<cols; i++) {
    res[i] = sum(mat.column(i));
  }
  return(res);
}
