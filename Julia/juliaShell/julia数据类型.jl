#=
isa() 函数用来判断给定参数的类型是不是指定类型
julia> isa(5.5,Float64)
true

convert() 类型转换
julia> convert(Float32,1e10)
1.0f10

通过四舍五入将浮点数转化为整数，浮点数无法被精确地表示为整数
ceil() 向上取整
floor() 向下取整
round() 四舍五入

supertype(Number) 用于查看作为参数传递类型的父类型
typeof(1) 查看类型 
julia> supertype(Array)
DenseArray{T,N} where N where T
julia> supertype(DenseArray)
AbstractArray{T,N} where N where T
julia> supertype(AbstractArray)
Any
julia> typeof("hello")
String

subtypes(Number)  用于查看作为参数传递类型的子类型
julia> subtypes(Number)
2-element Array{Any,1}:
 Complex
 Real








=#
function printall(a)
    sum = 0
    for i in a
        print(i)
        sum += i
    end  
end
printall(1:10)