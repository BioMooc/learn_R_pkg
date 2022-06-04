#' Add to number x
#'
#' @param x an int
#'
#' @return an int
#' @export
#'
#' @examples
#' addTo(100)
#' addTo(10)
addTo=function(x){
  sum=0
  for(i in 1:x){
    sum=sum+i;
  }
  return(sum)
}



#' add two number by C
#'
#' @param x int
#' @param y int
#'
#' @return int
#' @export
#' @useDynLib pkgS3
#'
#' @examples
#' addNum(20, 35)
addNum=function(x, y){
  message("this was calc by C function 'add'")
  y = .C("add", a=as.integer(x), b=as.integer(y) )$a
  return(y)
}



#' Add to number from 1 to x, in C
#'
#' @param x an int
#'
#' @return an int
#' @export
#' @useDynLib pkgS3
#'
#' @examples
#' addTo_wrapper(100)
#' addTo_wrapper(10)
addTo_wrapper=function(x){
  if (!is.numeric(x)){ stop("argument x must be numeric") }
  message("this was calc by C function 'addTo'")
  y=0
  out = .C("addTo", a=as.integer(x), b=as.integer(y) )
  return(out$b)
}



