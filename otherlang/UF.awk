function init(N,i)
{
	for(i=1;i<=N;i++)parent[i]=-1;
}
function find(u){return parent[u]<0?u:parent[u]=find(parent[u]);}
function same(a,b){return find(a)==find(b);}
function unite(a,b)
{
	a=find(a);
	b=find(b);
	if(a==b)return 0;
	if(parent[a]>parent[b])
	{
		parent[b]+=parent[a];
		parent[a]=b;
	}
	else
	{
		parent[a]+=parent[b];
		parent[b]=a;
	}
	return 1;
}
function size(a){return -parent[find(a)];}
