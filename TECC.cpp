//Two Edge Connected Components require bridge
struct TECC:bridge{
	vector<int>comp;
	TECC(int n_=0):bridge(n_),comp(n_,-1){}
	int operator[](int a)const{return comp[a];}
	void dfs(int u,int p,int&k)
	{
		comp[u]=p==-1||is_bridge(p,u)?k++:comp[p];
		for(int&v:G[u])if(comp[v]==-1)dfs(v,u,k);
	}
	int build()
	{
		bridge::build();
		int k=0;
		dfs(0,-1,k);
		return k;
	}
	int build(vector<vector<int> >&H)
	{
		int k=build();
		H.assign(k,vector<int>());
		for(pair<int,int>&e:bridges)
		{
			int x=comp[e.first],y=comp[e.second];
			H[x].push_back(y);
			H[y].push_back(x);
		}
		return k;
	}
};
