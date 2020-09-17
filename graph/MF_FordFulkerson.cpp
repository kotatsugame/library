//Ford-Fulkerson O(FE)
#include<algorithm>
#include<utility>
#include<vector>
#include<limits>
template<typename T>
struct MF{
	struct edge{
		int to,rev;
		T cap;
	};
	vector<vector<edge> >G;
	vector<int>used;
	MF(int n_=0):G(n_),used(n_,0){}
	void add_edge(int from,int to,T cap)
	{
		G[from].push_back({to,(int)G[to].size(),cap});
		G[to].push_back({from,(int)G[from].size()-1,0});
	}
	T dfs(int u,int t,T f,int dfstime)
	{
		if(u==t)return f;
		used[u]=dfstime;
		for(edge&e:G[u])
		{
			if(used[e.to]<dfstime&&e.cap>0)
			{
				T d=dfs(e.to,t,min(f,e.cap),dfstime);
				if(d>0)
				{
					e.cap-=d;
					G[e.to][e.rev].cap+=d;
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
