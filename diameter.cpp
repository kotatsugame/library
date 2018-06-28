#include<vector>
#include<algorithm>
template<typename T>
pair<T,int>diameter_dfs(const vector<vector<pair<int,T> > >&G,int u,int p)
{
	pair<T,int>ans(0,u);
	for(const pair<int,T>&e:G[u])
	{
		if(e.first!=p)
		{
			pair<T,int>q=diameter_dfs(G,e.first,u);
			q.first+=e.second;
			ans=max(ans,q);
		}
	}
	return ans;
}
template<typename T>
T diameter(const vector<vector<pair<int,T> > >&G)
{
	pair<T,int>p=diameter_dfs(G,0,-1);
	pair<T,int>q=diameter_dfs(G,p.second,-1);
	return q.first;
}
int diameter(const vector<vector<int> >&G)
{
	vector<vector<pair<int,int> > >H(G.size());
	for(int i=0;i<G.size();i++)for(const int&e:G[i])H[i].push_back(make_pair(e,1));
	return diameter(H);
}
