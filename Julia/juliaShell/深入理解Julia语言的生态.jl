#=
verinfo() 显示当前存在的全局符号信息
例如：
julia> varinfo()
  name                    size summary
  –––––––––––––––– ––––––––––– –––––––
  Base                         Module
  Core                         Module
  InteractiveUtils 198.387 KiB Module
  Main                         Module

@which 显示函数定义的具体信息  注意: 函数需要加上参数，使其是可运行的函数调用
例如:
julia> @which tan(10)
tan(x::Real) in Base.Math at special/trig.jl:233

versioninfo()
显示计算机的系统信息，julia版本信息等
例如：
julia> versioninfo()
Julia Version 1.5.3
Commit 788b2c77c1 (2020-11-09 13:37 UTC)
Platform Info:
  OS: Windows (x86_64-w64-mingw32)
  CPU: AMD Ryzen 7 4800H with Radeon Graphics
  WORD_SIZE: 64
  LIBM: libopenlibm
  LLVM: libLLVM-9.0.1 (ORCJIT, znver2)

dump() 在屏幕上显示Julia对象的信息
例如：
julia> k = 2
julia> dump(k)
Int64 2

workspace() 擦除我们之前声明的所有变量，创造一个全新的，干净的工作区。/// 不可用 1.5.3

clipboard() 可以将键盘内容复制到REPL中。

less("a.txt")    先; 跳转shell命令      
然后cd 路径到目的路径
然后使用该命令，可以把文件里面的内容展示出来 
f = open("a.txt","w")
close(f)
less("a.txt")
注意，这个不能在脚本里使用，不过也可以复制到REPL中执行

edit() 用于编辑当前目录的文件。
例如: 
edit("a.txt")

clipboard("hello world") 可以将一些信息复制到系统的剪贴板上

Pkg.status()  显示安装的所有包
例如：
julia> Pkg.status()
Status `C:\Users\hay boy\.julia\environments\v1.5\Project.toml`
  [a93c6f00] DataFrames v1.1.1
  [c91e804a] Gadfly v1.3.3
  [c43c736e] Genie v1.18.1
  [09f84164] HypothesisTests v0.10.4
  [7073ff75] IJulia v1.23.2
  [682c06a0] JSON v0.21.1
  [5fb14364] OhMyREPL v0.5.10
  [9b87118b] PackageCompiler v1.2.6
  [91a5bcdd] Plots v1.0.14
  [d330b81b] PyPlot v2.9.0
  [2913bbd2] StatsBase v0.33.8
  [a7f2b756] ThinkJulia v0.0.0 `https://github.com/BenLauwens/ThinkJulia.jl#master`

Pkg.add("Genie.jl")  用于下载包，如果是公有包


Pkg.clone(url) 用于安装未注册包

Pkg.rm("Genie.jl")  用于移除包，首先从REQUIRE删除包，然后通过Pkg.revolve() 来匹配已更新的安装包列表.
可以直接修改REQUIRE文件然后运行，Pkg.revolve() 来一次性添加多个或删除多个包

Pkg.update()  用于更新所有包





=#
