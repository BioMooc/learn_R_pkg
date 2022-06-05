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



#' test1: func must be SEXP type
#'
#' @return null
#' @export
#' @useDynLib pkgS4
#'
#' @examples
#' helloA1()
helloA1 <- function() {
  result <- .Call("helloA1")
}



#' test2: NEW_CHARACTER()
#'
#' @return string
#' @export
#'
#' @examples
#' helloB1()
helloB1 <- function() {
  result <- .Call("helloB1")
  return(result)
}



#' test3: get the length of str or str vector.
#'
#' data type cast, AS_CHARACTER;
#'
#' @param greeting a string, or string vector
#'
#' @return the length of string or string vector
#' @export
#'
#' @examples
#' helloC1( c("this is me!", "morning") )
helloC1 <- function(greeting) {
  result <- .Call("helloC1", greeting)
  return(result)
}


#' Double the input number
#'
#' (test3)
#'
#' @param x a number
#'
#' @return a number
#' @export
#'
#' @examples
#' #double_me_R(1) #看来R中整数默认是 double，要强制转换类型 as.integer()
#' double_me_R(as.integer(5))
double_me_R <- function(x) {
  result <- .Call("double_me", x)
  return(result)
}




#' convolve of 2 vectors
#'
#' test3
#'
#' @param arr1 int array
#' @param arr2 int array
#'
#' @return int array
#' @export
#'
#' @examples
#' convolve2_R(1:3, 1:4)
#' convolve2_R(1:3, 1:10)
convolve2_R <- function(arr1, arr2) {
  .Call("convolve2", arr1, arr2)
}


#' 向量卷积，相当于两向量做矩阵乘法，然后沿着垂直于主对角线的方向相加。
#'
#' matrix(t(1:3), ncol=1) %*% matrix(1:4, nrow=1)
#'
#' @param arr1 int array
#' @param arr2 int array
#'
#' @return int array
#' @export
#'
#' @examples
#' convolve2_in_R(1:3, 1:4)
#' convolve2_in_R(1:3, 1:4, T)
convolve2_in_R=function(arr1, arr2, verbose=F){
  na=length(arr1)
  nb=length(arr2)
  xab=rep(0, na+nb-1)
  for ( i in 1:na){
    for ( j in 1:nb){
      xab[i+j-1] = xab[i+j-1]+ arr1[i] * arr2[j];
      if(verbose){
        message( sprintf("[i:%s, j:%s]: %s x %s --> %s", i,j,arr1[i], arr2[j], xab[i+j-1]) )
      }
    }
  }
  return(xab)
}



