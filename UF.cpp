#include<vector>
struct UF{
	int n;
	vector<int>parent,rank;
	UF(int n_=0):n(n_),parent(n_),rank(n_,0)
	{
		for(int i=0;i<n_;i++)parent[i]=i;
	}
	int find(int a)
	{
		return parent[a]!=a?parent[a]=find(parent[a]):a;
	}
	bool same(int a,int b)
	{
		return find(a)==find(b);
	}
	void unite(int a,int b)
	{
		a=find(a),b=find(b);
		if(rank[a]<rank[b])
		{
			parent[a]=b;
		}
		else
		{
			parent[b]=a;
			if(rank[a]==rank[b])rank[a]++;
		}
	}
};
