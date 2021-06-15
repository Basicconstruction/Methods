#=
print()
println(a,b,c)
上面两个为常用的输出函数,第二个和第一个的不同之处在于，第二个输出完数据之后会补上一个\n
还有一个
using Printf
@printf("%d%.2f",12,13.929)
用法和C差不多

转换函数
parse(Int64,String)
转换字符串为Int64,注意这里不能转换"12.2899"类似带有.的字符串

parse(Float64,String)
转换字符串为Float64,可以用"12"类似字符串，也会转化为Float64

trunc(Int64,Float64Value)
把浮点数转换为整数，不过不是四舍五入,只是简单的截断小数部分

float(Int64/Float64)
把数字转化为Float64

string(Any)
把所有转化为字符.

常用函数 
sin()   cot()   csc()
cos()   tan()   sec()
log()   log2()  log10()  
exp(n) = e ^ n

=#
a = 10
b =27
c = 34
println(a,b,c)
println(parse(Float64,"12"))
println(float(12.0))