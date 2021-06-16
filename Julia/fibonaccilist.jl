known = Dict(0=>0,1=>1)
function fibonacci(n::BigInt)::BigInt
    if n ∈ keys(known)
        return known[n]
    end
    res::BigInt = fibonacci(n-1) + fibonacci(n-2)
    known[n] = res
    res
end
y = collect(0:1)
println(y)
function fibonacci2(n::BigInt)::BigInt
    if n < length(y) && n != 0
        return y[n+1]
    elseif n==0
        return 0
    else

    end
    c::BigInt = fibonacci2(n-1)+fibonacci2(n-2)
    push!(y,c)
    c
end
println(fibonacci(BigInt(90)))
println(fibonacci2(BigInt(100)))