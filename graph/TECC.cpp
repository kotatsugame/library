//Two Edge Connected Components require bridge
#include"../include/bridge.hpp"
struct TECC:bridge{
	vector<int>comp;
	TECC(int n_=0):bridge(n_),comp(n_,-1){}
	int operator[](int i)const{return comp[i];}
	void dfs(int u,int p,int&k)
	{
		comp[u]=p==-1||is_bridge(p,u)?k++:comp[p];
		for(int v:G[u])if(comp[v]==-1)dfs(v,u,k);
	}
	int build()
	{
		bridge::build();
		int k=0;
		for(int u=0;u<n;u++)if(comp[u]==-1)dfs(u,-1,k);
		return k;
	}
	int build(vector<vector<int> >&H)
	{
		int k=build();
		H.assign(k,vector<int>());
		for(int u=0;u<n;u++)
		{
			for(int v:G[u])if(comp[u]!=comp[v])
			{
				H[comp[u]].push_back(comp[v]);
			}
		}
		return k;
	}
};
