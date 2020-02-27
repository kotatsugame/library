type UF
	n::Int
	pr::Array{Int}
	sz::Array{Int}
	UF(n)=new(n,1:n,ones(Int,n))
end
function find(uf::UF,a::Int)
	if uf.pr[a]==a
		a
	else
		uf.pr[a]=find(uf,uf.pr[a])
	end
end
same(uf::UF,a::Int,b::Int)=find(uf,a)==find(uf,b)
function unite(uf::UF,a::Int,b::Int)
	ap=find(uf,a)
	bp=find(uf,b)
	if ap==bp
		false
	else
		if uf.sz[ap]<uf.sz[bp]
			uf.pr[ap]=bp
			uf.sz[bp]+=uf.sz[ap]
		else
			uf.pr[bp]=ap
			uf.sz[ap]+=uf.sz[bp]
		end
		true
	end
end
size(uf::UF,a::Int)=uf.sz[find(uf,a)]
