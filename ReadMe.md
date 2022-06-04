# Learn how to build R packages

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

- compile the C/C++ codes into a shared library (.dll in Windows and .so (.o) in linux), 
- load the shared library by dyn.load("LIBNAME"), and 
- call the compiled C function by .C("FUNNAME",...). Here LIBNAME is the name of the shared library file and FUNNAME is the name of the C function.


> Do settings when loading the pkg, use Hooks for Namespace Events like .onLoad(). In pkgS3/R/zzz.R





# Install

> # devtools::install_github("userName/my_rpackage/rmytools")
> devtools::install_github("BioMooc/learn_R_pkg/pkgS2")

