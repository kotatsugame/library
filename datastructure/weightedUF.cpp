#include<vector>
template<typename T>
struct weightedUF{
	int n;
	vector<int>parent,rank;
	vector<T>dweight;
	weightedUF(int n_=0,T defvalue=0):n(n_),parent(n_),rank(n_,1),dweight(n_,defvalue)
	{
		for(int i=0;i<n;i++)parent[i]=i;
	}
	int find(int a)
	{
		if(parent[a]==a)return a;
		else
		{
			int ar=find(parent[a]);
			dweight[a]+=dweight[parent[a]];
			return parent[a]=ar;
		}
	}
	T weight(int a)
	{
		find(a);
		return dweight[a];
	}
	bool same(int a,int b)
	{
		return find(a)==find(b);
	}
	bool unite(int a,int b,T w)//a+w==b
	{
		w+=weight(a);w-=weight(b);
		a=find(a);b=find(b);
		if(a==b)return false;
		if(rank[a]<rank[b])
		{
			parent[a]=b;
			dweight[a]=-w;
			rank[b]+=rank[a];
		}
		else
		{
			parent[b]=a;
			dweight[b]=w;
			rank[a]+=rank[b];
		}
		return true;
	}
	T diff(int a,int b)
	{
		return weight(b)-weight(a);
	}
};
