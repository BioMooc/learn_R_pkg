#include <Rcpp.h>
#include <numeric> // for std::partial_sum
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector cumsum1(NumericVector x){
  double acc = 0; // init an accumulator variable
  NumericVector res(x.size()); // init result vector
  for(int i = 0; i < x.size(); i++){
    acc += x[i];
    res[i] = acc;
  }
  return res;
}


// An STL variant:
// [[Rcpp::export]]
NumericVector cumsum2(NumericVector x){
  // initialize the result vector
  NumericVector res(x.size());
  std::partial_sum(x.begin(), x.end(), res.begin());
  return res;
}


//Or just Rcpp sugar:
// [[Rcpp::export]]
NumericVector cumsum_sug(NumericVector x){
  return cumsum(x); // compute + return result vector
}



