//Ford-Fulkerson O(FE)
#include<algorithm>
#include<utility>
#include<vector>
#include<limits>
template<typename T>
struct MF{
	vector<vector<pair<pair<int,int>,T> > >G;
	vector<int>used;
	MF(int n_=0):G(n_),used(n_,0){}
	void add_edge(int from,int to,T cap)
	{
		G[from].push_back(make_pair(
			make_pair(to,G[to].size()),cap
		));
		G[to].push_back(make_pair(
			make_pair(from,G[from].size()-1),0
		));
	}
	T dfs(int u,int t,T f,int dfstime)
	{
		if(u==t)return f;
		used[u]=dfstime;
		for(pair<pair<int,int>,T>&e:G[u])
		{
			if(used[e.first.first]<dfstime&&e.second>0)
			{
				T d=dfs(e.first.first,t,min(f,e.second),dfstime);
				if(d>0)
				{
					e.second-=d;
					G[e.first.first][e.first.second].second+=d;
					return d;
				}
			}
		}
		return 0;
	}
	T max_flow(int s,int t)
	{
		T ret=0;
		for(int dfstime=1;;dfstime++)
		{
			T f=dfs(s,t,numeric_limits<T>::max(),dfstime);
			if(f>0)ret+=f;
			else break;
		}
		return ret;
	}
};
