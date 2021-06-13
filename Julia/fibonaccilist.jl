known = Dict(0=>0,1=>1)
function fibonacci(n)
    if n ∈ keys(known)
        return known[n]
    end
    res = fibonacci(n-1) + fibonacci(n-2)
    known[n] = res
    res
end
y = collect(0:1)
println(y)
function fibonacci2(n)
    if n < length(y) && n != 0
        y[n+1]
    elseif n==0
        0
    else
        end
    c = fibonacci2(n-1)+fibonacci2(n-2)
    push!(y,c)
    c
end
println(fibonacci(100))
println(fibonacci2(2))