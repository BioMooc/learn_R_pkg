
# 这是启动函数，可以用于初始化设置，包参数设置等 https://oomake.com/question/213412
# .onLoad 是命名空间钩子，细节 F1 查看

.onLoad=function(lib, pkg){
  message("===>>> This is the function called when loading this pkg. \
          Very suit to load .so file here.")
  message("libName:",lib)
  message("pkgName:",pkg)
}
