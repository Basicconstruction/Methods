#=julia> x
10-element Array{Int64,1}:
  1
  2
  3
  4
  5
  6
  7
  8
  9
 10

julia> using Statistics  #引入包

julia> mean(x)     #平均数
5.5

julia> median(x)   #中位数 Median
5.5

julia> sum(x)       #计算和
55

julia> std(x)       #计算标准差 Standard deviation
3.0276503540974917

julia> var(x)       #计算方差 variance
9.166666666666666



 =#