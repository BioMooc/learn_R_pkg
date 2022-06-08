#' @useDynLib pkgS5
#' @import Rcpp
#'
NULL


# Hello, world!
#
# This is an example function named 'hello'
# which prints 'Hello, world!'.
#
# You can learn more about package authoring with RStudio at:
#
#   http://r-pkgs.had.co.nz/
#
# Some useful keyboard shortcuts for package authoring:
#
#   Install Package:           'Ctrl + Shift + B'
#   Check Package:             'Ctrl + Shift + E'
#   Test Package:              'Ctrl + Shift + T'

hello <- function() {
  print("Hello, world!")
}




#' Get max of an array
#'
#' @param x an array of numbers
#'
#' @return a number
#' @export
#'
#' @examples
#' getMax(1:10)
getMax=function(x){
  return(getMaxCpp(x))
}


#' Get sums of each column
#'
#' @param mat a matrix
#'
#' @return a vector
#' @export
#'
#' @examples
#' colSums2(mtcars)
colSums2=function(mat){
  mat=as.matrix(mat)
  return( colSumsCpp(mat) )
}

