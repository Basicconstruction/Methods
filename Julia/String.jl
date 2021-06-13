#字符串
#字符串不同于整数,浮点数,和布尔值。字符串是一个序列，这说明这是其他值的一个有序集合。


#字符
#Char值表示单个字符，用单引号包围
x = 's'
y = '我'
println(sizeof(x))
println(sizeof(y))
println(sizeof("$(x)"))
println(sizeof("$(x)$(y)"))
#字符一般占用4个字节，在字符串中，ASCII字符占用1个字节，其他UNICODE字符占用的字符按照适宜的大小，
#总是尽可能占用较小的字节
#比如汉字占用大约3个字符，即使单个汉字字符占用4个字节。这样设计或许是为了让char所占用的字节数一致。


#字符串是一个序列。字符串使用UTF-8编码格式编码。UTF-8是一种变宽编码格式，这意味着，每一个字符比那吗使用的字节数不一定都相同。
#字符串是一个字符序列，可以用中括号操作符([]) 一次访问一个字符。
#julia的所有索引都从1开始，即任何使用整数索引的对象中，第一个元素都位于索引1上，最后一个元素位于索引end上。
x = "hello world"
i = firstindex(x)
println(i)
i = nextind(x,i)
println(i)
#可以使用firstindex(s:string)来获取一个字符串的第一个索引,使用后nextind(s:string,index:int)来获取字符串的下一个字符索引。
#这样设计是因为，有些宽字符例如'我'这个汉字字符占用3个字节，
#对于, x = "我2222ww"
#firstindex(x)  return 1
#nextind(x,1)  return 4
x = "我niced"
println(nextind(x,1)) #out 4
#warrning:
#length() 是一个内置函数，会返回一个字符串中的字符个数。而，sizeof() 返回的是一个对象(字符没字符串，数字等)占用的字节大小。
x = "winding二尺"
println.(length(x))
println(sizeof(x))
#UTF-8字符串中的每一个字节索引不一定是对应一个字符的合法索引。如果用一个不合法的字节索引访问字符串中的字符，会抛出一个错误。

#遍历
#函数中的while循环
#for循环
for i in eachindex("hello")
    println("hello"[i])
end

#字符串分片
#begin 意指数组或字符串的第一个元素或字符的索引，end意指数组或字符串的最后一个元素或字符的索引。
println("ecwh"[begin:end])
println([1,2,][begin])
#切片语法大体都一致
x = "hello world"
println(x[1:2:10])  #out hlowr


#字符串的连接
#将连接两个字符串或者一个字符串和一个字符
println('x' * "hdb")

