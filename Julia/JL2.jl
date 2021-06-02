//牛顿迭代法开方
function sqrt_r(a)
    if(a==0)
        return 0
    end
    x = 1
    y = (x + a / x) / 2
    for i in 1:100
        if x == y
            return y
        else
            x = y
            y = (x + a / x) / 2
        end
    end
    while myAbs(y - x) > 0.00000001
        x = y
        y = (x + a / x) / 2
    end
    return y
end
//取 绝对值 函数
function myAbs(a)
	if a > 0
		return a
	end
	return -a
end
//判断是否是 互为反转的字符串
function isreverse(word1, word2)
    if length(word1) != length(word2)
        return false
    end
    i = 1
    j = length(word1)
    while j >= 1
        if(word1[i] != word2[j])
            return false
        end
        i += 1
        j -= 1
    end
    true
end
println(sqrt_r(121))
println(isreverse("asc", "csa"))