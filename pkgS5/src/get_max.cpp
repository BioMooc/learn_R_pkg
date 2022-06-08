#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
double getMaxCpp(Rcpp::NumericVector v) {
  int n = v.size(); // vectors are describing
  double m = v[0]; // initialize
  for (int i=0; i<n; i++) {
    if( v[i] > m ){
      Rcpp::Rcout << "Now " << m << std::endl;
      m = v[i];
    }
  }
  return(m);
}

