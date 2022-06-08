#include <RcppArmadillo.h>
using namespace Rcpp;
using namespace arma;

// [[Rcpp::depends(RcppArmadillo)]]  // 告诉 g++ 要加头文件

#define CONDIT 1000  //宏定义

// [[Rcpp::export]]
arma::rowvec colSums(arma::mat mat) {
  size_t cols = mat.n_cols; //获取维度 n_rows and n_cols，类似功能，不同包的名字略有不同
  arma::rowvec res(cols);
  for (size_t i=0; i<cols; i++) {
    res[i] = sum(mat.col(i));
  }
  return(res);
}



// [[Rcpp::export]]
RObject getRndMt(){
  arma::cube A(3,4,5,arma::fill::randu);
  std::cout<<CONDIT<<std::endl;
  return wrap(A);
}

/*
// 总是报错，原因未知 //todo
// [[Rcpp::export]]
arma::vec getEigenValues(arma::mat M) {
  return arma::eig_sym(M);
}
*/


// another simple example: outer product of a vector,
// returning a matrix
//
// [[Rcpp::export]]
arma::mat rcpparma_outerproduct(const arma::colvec & x) {
  arma::mat m = x * x.t();
  return m;
}

// and the inner product returns a scalar
//
// [[Rcpp::export]]
double rcpparma_innerproduct(const arma::colvec & x) {
  double v = arma::as_scalar(x.t() * x);
  return v;
}
