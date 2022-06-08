#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector positives(NumericVector x) {
  return x[x > 0];
}

// [[Rcpp::export]]
List first_three(List x) {
  IntegerVector idx = IntegerVector::create(0, 1, 2);
  return x[idx];
}

// [[Rcpp::export]]
List with_names(List x, CharacterVector y) {
  return x[y];
}
