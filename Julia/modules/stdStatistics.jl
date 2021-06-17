"""
# module stdStatistics

- Julia version: 1.5.3
- Author: hay boy
- Date: 2021-06-17

# Examples

```jldoctest
julia>
```
"""
module stdStatistics
    using Printf
    export min,max,mean,median,var,std
    import Base.+,Base.-
    function min(a)
        if length(a) === 0
            @printf("You give a empty array.")
            return 0
        else
            minnum = a[1]
            for i in a
                if minnum > i
                    minnum = i
                end
            end
        end
        minnum
    end
    function max(a)
        if length(a) === 0
            @printf("You give a empty array.")
            return 0
        else
            maxnum = a[1]
            for i in a
                if maxnum < i
                    maxnum = i
                end
            end
        end
        maxnum
    end
    function mean(a)
        if length(a) === 0
            @printf("You give a empty array.")
            return 0
        end
        sum = BigFloat(0.0)
        for i in a
            sum += i
        end
        sum / length(a) 
    end
    function median(a)
        if length(a) === 0
            @printf("You give a empty array.")
            return 0
        end
        y = deepcopy(a)
        sort!(y)
        return length(y) % 2 == 0 ? (y[Int32(length(y)/2)] + y[Int32(length(y)/2+1)])/2 : y[Int32((length(y)+1)/2)]
    end
    function var(a)
        #总体方差
        if length(a) === 0
            @printf("You give a empty array.")
            return 0
        end
        meanvalue = mean(a)
        varvalue = BigFloat(0.0)
        for i in a
            varvalue += (i-meanvalue) ^ 2
        end
        return varvalue/length(a)
    end
    function std(a)
        #总体标准差
        if length(a) === 0
            @printf("You give a empty array.")
            return 0
        end
        meanvalue = mean(a)
        stdvalue = BigFloat(0.0)
        for i in a
            stdvalue += (i-meanvalue) ^ 2
        end
        return (stdvalue  / length(a))^ 0.5
    end

end
#=
push!(LOAD_PATH,pwd())
using stdStatistics
=#