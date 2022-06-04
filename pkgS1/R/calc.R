

#' Add 100 to the given number
#'
#' @param x a number, float or int
#'
#' @return a number
#' @export
#'
#' @examples
#' add100(5)
#' add100(-90)
add100=function(x){
  x+100
}



#' Get the proportion of each number in an array
#'
#' @param x an array of numbers
#'
#' @return an array of proportions
#' @export
#'
#' @examples
#' prop(c(1,2,3,4,5))
prop=function(x){
  return(x/sum(x))
}


