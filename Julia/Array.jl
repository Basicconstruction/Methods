#Pkg.add("ThinkJulia") rm(joinpath(homedir(), ".julia", "registries"); recursive=true)
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

#数组和字符串
#字符串是一个字符序列，数组是一个值序列，不过字符数组并不等于字符串，要把一个字符串转化为一个字符数组，可以使用函数collect()
#一般情况下,collect()通常用来生产一个数组如， c = collect(1:3:10)
#c = [1，4，7，10]
#将这个函数用于字符串，得到的是一个字符数组
t = collect("hello world")
println.(t) #out h e l l o  w o r l d
#extra collect函数将一个字符串或其他序列分解为单个元素


#如果想要把一个字符串分解为单词，可以使用split()函数。#默认分割符为' ',空格字符
#split(iterator,divchar)
#eg
s = "s e x j k n"
x = split(s,' ')
print.(x)
println(split(s))

#join与split正好相反，这个函接收一个字符串数组，并连接这些字符
k = ['1','2','3']
println(join(k))
k = ["1","3","hj"]
println(join(k))


#对象和值
#要检查两个变量是否指向同一个对象，可以使用\equip TAB 或者 === 操作符
a = "hello"
b = "hello"
println(a===b)
a = 1
b = 1
println(a===b)
#这可以说明，对于一般的数字和字符串，常常使用一个对象来节省空间，这和python的特点很相似


#别名 
#如果a指示一个对象，然后完成赋值a = b
#那么这两个变量都指向同一个对象
#warning 注意，这里的对象常常指的是非 数字(int,double) 和字符串
a = 10
b = a
a = 100
println(a," ",b)
c = "he"
d = c
c = "vewn"
println.((c,d))
e = [1,2,3]
f = e
println(f===e)
f = [2,3,4]
println.((e,f))
k = [1,2]
j = k
j[1] = 100
println.((j,k))
#实际上，别名的用处并不是很多，而且很容易导致混乱。在这里只有最后一个才正确的完成了我们的任务。
#比如使用 c = [1,2,3] d = c 这是c,d 互为别名,但是再使用 c = [1,23]时，就会重新给c 赋值一个对象，c,d就不是互为别名了。

#数组参数
#将一个数组传入一个函数时，函数会得到那个数组的一个引用。
#如果这个函数修改了数组，调用者会看到这个改变。
#比如 pop!() popfirst!() deleteat!() insert!() sort!() reverse!()
#而vcat()的结果是一个新数组，原来的数组没有改变。和sort() reverse()一样
#但是，似乎很难执行如何删除一个数组的元素而不使用原生方法如pop!()等确实，这一点在官方pdf中得到了求证https://raw.githubusercontent.com/JuliaCN/JuliaZH.jl/pdf/dev/Julia%E4%B8%AD%E6%96%87%E6%96%87%E6%A1%A3.pdf














