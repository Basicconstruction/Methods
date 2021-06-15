#julia语言编程入门-13章案例研究-数据结构的选择
#所提供的一些有用的方法和函数
# 1 -> eachline(filesrc)  可以获得一个可迭代的文件对象。通过迭代访问每一行
# 2 -> replace(string,char/string=>char/string)  将一个字符串中的某一个字符或字符串替换为另一个字符或字符串
# 3 -> split(string,char/string)
# 4 ->rand() 参数为空时，返回一个随机的0.0到1.0(包括0.0但不包括1.0之间的一个随机浮点数)\
#            参数为一个迭代器或数组时，将返回一个随机元素
# 5 -> lowercase(string) 将字符串中的所有字符转换为小写
# 6 -> uppercase(string) 将字符串中的所有字符转换为大写
# 7 -> isletter(char) 判断一个字符是个否是一个字母
for line in eachline("cv.txt")
    line = replace(line,","=>' ')
    line = split(line," ")
    println("length of this line is ",length(line))
    # println.(line)
end
println(rand())
x = []
push!(x,[1,2])
push!(x,[4,3])
println(rand(x)[rand(1:length(x))])
println(isletter('j'))


# 8-> filter(function,collect) 返回一个collect的副本，这个副本中的每一个元素都满足function(x) -> true,
#也即remove在collect中使得function() 为false的元素
#比如
x = collect(1:10)
y = filter(isodd,x)
println(y) #[1, 3, 5, 7, 9]
#当然，这只是最为常用的方法，还有一些不太常用的方法，也可以在文档中以及IE中找到。

#[string...] 会将string 解构为一个字符数组
#(string...,) 会将string解构为字符元组 warrning 对于(string...) 不可用于赋值，但可以用于输出，输出为string 

#string()  参数为多个字符或字符串时会连接这些字符和字符串生成一个字符串，若为其他的比如数组，则会将，数组本身转换为一个字符串
#比如 string([1,2 ,3])
println(string([1,2 ,3])) #转换为[1, 2, 3] 元素之间会有空格和逗号


#简单绘图,在交互式命令行可以用
using Plots
x = [1:10]
y = x .* 3
plot(x,y)