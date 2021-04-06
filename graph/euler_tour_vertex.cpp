#include<vector>
struct euler_tour{
	int N;
	vector<vector<int> >G;
	vector<int>V;
	vector<pair<int,int> >range;
	euler_tour(int N_=0):N(N_),G(N_),range(N_),V(){}
	void add_edge(int u,int v)
	{
		G[u].push_back(v);
		G[v].push_back(u);
	}
	void dfs(int u,int p)
	{
		range[u].first=V.size();
		V.push_back(u);
		for(int v:G[u])if(v!=p)dfs(v,u);
		range[u].second=V.size();
	}
	void build(int root=0)
	{
		dfs(root,-1);
	}
	size_t size()const{return V.size();}
	int operator[](int k)const{return V[k];}
	const pair<int,int>&subtree(int v)const{return range[v];}
};
