// [[Rcpp::depends(RcppEigen)]]
#include <RcppEigen.h>
using namespace Eigen;
using namespace std;

//[[Rcpp::export]]
double myfun(Eigen::MatrixXd X, Eigen::MatrixXd Y) {
  // 主对角线元素的和，叫迹(trace)
  double Z;

  Z = (X.adjoint() * Y).trace(); //X^T . Y
  cout << Z << endl;

  return Z;
}
/*test
A=matrix(1:4, nrow=1)
myfun( A, A)

sum(diag((t(A) %*% A)))
*/


//[[Rcpp::export]]
Eigen::VectorXd getEigenValues(Eigen::MatrixXd X) {
  //https://gallery.rcpp.org/articles/eigen-eigenvalues/
  Eigen::SelfAdjointEigenSolver<MatrixXd> es(X);
  return es.eigenvalues();
}
/*
 A=matrix(c(2, 1, 1, 1, 2, 1,1, 1, 2), byrow = T, nrow=3);A
 getEigenValues(A) #和R求解一致，顺序相反

 eigen(A)
 */
