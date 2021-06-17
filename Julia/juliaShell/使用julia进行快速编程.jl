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
println(BigInt(10)^10000)

执行按位运算
~x 按位取反
x & y 按位与
x | y 按位或
按位异或
x >>> y 逻辑或算术右移
x >> y 算术右移
x <<< 逻辑或算术左移

数组和矩阵
rand_array = rand(1:100,6)
println(rand_array)
在1--100内随机选择6 个值创建一个数组

julia 的列表解析式
[x[i] = 3 ^ i for i = 1:10]
10-element Vector{Int64}:
     3
     9
    27
    81
   243
   729
  2187
  6561
 19683
 59049

创建自定义大小数组并填充,在julia中Array和Vector的区别并不大
julia> x = Array{Int64}(undef,10)
10-element Vector{Int64}:
         1
 447021312
         1
 447021392
         1
 447021472
         1
 447021552
         1
 447021632

julia> fill!(x,10)
10-element Vector{Int64}:
 10
 10
 10
 10
 10
 10
 10
 10
 10
 10

数组填充，  fill!(x,10)                    fill(x,10)不同以往
x表示数组


=#
pow2 = Array(Int64,100)
pow[1] = 100
println(pow2)