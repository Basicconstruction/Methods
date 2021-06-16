#=
整数类型
Int/UInt   -> 8,16,32,64,128
Bool 严格Bool类型


typemax(Int64)  计算整数/浮点数类型的最大值  Bool 类型返回true
typemin(UInt64)  计算整数/浮点数类型的最小值 Bool 类型返回false
例如：
julia> typemax(Int64)
9223372036854775807
julia> typemin(UInt64)
0x0000000000000000
julia> typemin(Float64)
-Inf
julia> typemax(Float64)
Inf
julia> typemax(Bool)
true
julia> typemin(Bool)
false

Sys.WORD_SIZE  获取系统位数

Float64:
2.99e10

Float32:
2.99f10

转换函数 Float64() Float32() Float16()

Inf 表示无穷大
-Inf表示无穷小
NaN表示这不是一个实数

如果需要找到下一个浮点数,可以使用nextfloat(0.0) 
如果需要找到上一个浮点数，可以使用prevfloat(0.0)

setprecision(10) 可以用来设置浮点数精度，10为设置的精度系数
例如：
julia> setprecision(10)do
  BigFloat(1)+parse(BigFloat,"0.1")
  end
1.0996

任意精度的计算
BigFloat
BigInt

=#