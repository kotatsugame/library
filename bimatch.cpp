#include<algorithm>
#include<vector>
struct bimatch{
	int n;
	vector<vector<int> >G;
	vector<int>match;
	vector<bool>used;
	bimatch(int _n=0):n(_n),G(n),match(n),used(n){}
	void add_edge(int u,int v)
	{
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bool dfs(int v)
	{
		used[v]=true;
		for(int u:G[v])
		
		{
			int w=match[u];
			if(w<0||!used[w]&&dfs(w))
			{
				match[v]=u;
				match[u]=v;
				return true;
			}
		}
		return false;
	}
	int count()
	{
		int ans=0;
		fill(match.begin(),match.end(),-1);
		for(int v=0;v<n;v++)
		{
			if(match[v]<0)
			{
				fill(used.begin(),used.end(),false);
				if(dfs(v))ans++;
			}
		}
		return ans;
	}
};
