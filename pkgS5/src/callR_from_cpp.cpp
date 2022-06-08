#include <Rcpp.h>
using namespace Rcpp;

//' @export
// [[Rcpp::export]]
NumericVector callFunction(NumericVector x, Function f) {
	NumericVector res = f(x);
	return res;
}

