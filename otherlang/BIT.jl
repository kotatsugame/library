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
function lower_bound(bit::BIT,k::Int)#k<=sum(ret)
	if k<=0
		return 0
	end
	ret=0
	i=1
	while i*2<=bit.n
		i*=2
	end
	while i>0
		if ret+i<=bit.n&&bit.bit[ret+i]<k
			k-=bit.bit[ret+i]
			ret+=i
		end
		i>>=1
	end
	ret+1
end