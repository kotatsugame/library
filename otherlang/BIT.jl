type BIT
	n::Int
	bit::Array{Int}
	BIT(n)=new(n,zeros(Int,n))
end
function sum(bit::BIT,i::Int)
	ans=0
	while i>0
		ans+=bit.bit[i]
		i-=i&-i
	end
	ans
end
function add(bit::BIT,i::Int,a::Int)
	while i<=bit.n
		bit.bit[i]+=a
		i+=i&-i
	end
end
