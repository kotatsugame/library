#include<vector>
#include<algorithm>
struct bridge{
	int n;
	vector<int>ord,low;
	vector<bool>art;
	vector<vector<int> >G;
	bridge(int n_=0):n(n_),ord(n_,-1),low(n_),art(n_,false),G(n_){}
	void add_edge(int u,int v)
	{
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bool operator[](int i)const{return art[i];}
	bool is_bridge(int a,int b)const
	{
		if(ord[a]>ord[b])swap(a,b);
		return ord[a]<low[b];
	}
	void dfs(int u,int p,int&k)
	{
		low[u]=ord[u]=k++;
		bool now=false;
		int pc=0;
		for(int v:G[u])
		{
			if(ord[v]==-1)
			{
				dfs(v,u,k);
				low[u]=min(low[u],low[v]);
				now=now||ord[u]<=low[v];
			}
			else if(v!=p||pc++)
			{
				low[u]=min(low[u],ord[v]);
			}
		}
		art[u]=now;
	}
	void build()
	{
		int k=0;
		for(int u=0;u<n;u++)if(ord[u]==-1)
		{
			int cnt=0;
			low[u]=ord[u]=k++;
			for(int v:G[u])if(ord[v]==-1)
			{
				dfs(v,u,k);
				cnt++;
			}
			if(cnt>=2)art[u]=true;
		}
	}
};
