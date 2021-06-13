#遍历数组
x = [1,2,3]
for ele in x
    println(ele)
end
#out 1 2 3
#遍历数组,且更新数组
x = [1,2,3]
for index in eachindex(x)
    x[index] = 2 * x[index]
end
#x[2,4,6]
#数组分片
x = [1,2,3,4,5,6,7,8,9,10]
y = x[2:end]
#y [2,3,4,5,6,7,8,9,10]
y = x[begin:3]
#y [2,3,4]
y = x[1:3:7]
#y [1,4,7]
#数组库
#push!() 在一个数组的末尾增加一个新元素
x = [1,2,3]
push!(x,3)      #return x
#x [1,2,3,4]
#append!() 将第二个数组的元素追加到第一个数组的末尾
x = [1,2]
y = [2,3]
append!(x,y)   #return x
#x [1,2,2,3]
#sort!()将数组元素从低到高排列
x = [3,1,2]
sort!(x)  #return x
#x [1,2,3]
sort(x)   #return x副本排序后的数组,x没有被排序
#x [3,1,2]
#sum 将一个数组的元素累加
x = [2,3,4,5,6]
h = sum(x)
println(h)
#out 20
#点语法
#对于每一个二元操作符，如^,都有一个点操作符,如.^，这是自动定义的，会在数组上逐元素地完成相关操作。
#例如: [1,2,3] .^ 3  定义为逐个元素计算结果[1^3,2^3,3^3]
x = [2,3,4]
y = x.^3
println.(y)
#y [8,27,64]
#out 8 27 64
#同时就像上面所运用的,任何julia函数f都可以用点语法应用到任何数组中的各个元素。
x = "cewvyv"
x = uppercase.(x)
println(x)
# uppercase.(x) return "CEWVYU"
#splice!()  pop!() popfirst!()
#返回处理的元素
x = [1,2,3]
splice!(x,2)   #x = [1,3] return 2
x = [2,3,4]
pop!(x)       #x = [2,3] return 4
x = [4,5,6]
popfirst!(x)  #x = [5,6] return 4
#deleteat()  insert!()
#返回处理后地数组，数组本身发生改变
#deleteat!() 
x = [1,2,3,4]
deleteat!(x,4)  #删除x中索引为4的元素，并且返回x
println(x)
x = [0,1,2,3,4,5]
insert!(x,2,3)  #在x数组中的索引为2的位置插入3，并且返回x
println(x)


















