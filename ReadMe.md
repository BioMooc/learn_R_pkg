# Learn how to build R packages

## I

- https://cran.r-project.org/doc/manuals/R-exts.html



## II

- https://r-pkgs.org/
- https://github.com/hadley/r-pkgs
- Local: Y station:/home/wangjl/data/project/learn_R_pkg
- github: https://github.com/BioMooc/learn_R_pkg










# Examples

## pkgS1 The basic R package building process

## pkgS2 How to depend on functions in other pkgs?

## pkgS3 How to use C/C++ in my R pkg? .C() 

* http://dept.stat.lsa.umich.edu/~yizwang/software/maxLinear/noteonR.html
* http://users.stat.umn.edu/~geyer/rc/
* https://github.com/cjgeyer/foo


1. compile the C/C++ codes into a shared library (.dll in Windows and .so (.o) in linux), 
2. load the shared library by dyn.load("LIBNAME"), and 
3. call the compiled C function by .C("FUNNAME",...). Here LIBNAME is the name of the shared library file and FUNNAME is the name of the C function.


> Do settings when loading the pkg, use Hooks for Namespace Events like .onLoad(). In pkgS3/R/zzz.R


```
$ cat C_funcs.c #函数必须返回 void 类型; 只能通过指针传递计算结果;
void useC(int *i) {
  i[0] = 11;
}
$ R CMD SHLIB C_funcs.c

> dyn.load("useC1.so")
> a <- 1:10
> out <- .C("useC", b = as.integer(a)) #第一个参数是C函数名，接着是其他R参数
> out$b
[1] 11 2 3 4 5 6 7 8 9 10


use #' @useDynLib pkgS3 on one function comment.
```


## pkgS4 How to use C/C++ in my R pkg? .Call() 

```
#include <R.h>
#include <Rdefines.h>
#include <string.h>

SEXP add2(SEXP a, SEXP b) {
  SEXP result = PROTECT(allocVector(REALSXP, 1));
  REAL(result)[0] = asReal(a) + asReal(b);
  UNPROTECT(1);

  return result;
}

$ R CMD SHLIB src/helloC1.c

> dyn.load("src/helloC1.so")
> .Call("add2", 10, 20)
[1] 30
```







# Install

```
> #devtools::install_github("userName/my_rpackage/rmytools")
> devtools::install_github("BioMooc/learn_R_pkg/pkgS2")
```

