//Dinic O(EV^2)
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
#include<limits>
template<typename T>
struct MF{
	struct edge{
		int to,rev;
		T cap;
	};
	vector<vector<edge> >G;
	vector<int>level,iter;
	MF(int n_=0):G(n_),level(n_),iter(n_){}
	void add_edge(int from,int to,T cap)
	{
		G[from].push_back({to,(int)G[to].size(),cap});
		G[to].push_back({from,(int)G[from].size()-1,0});
	}
	T dfs(int u,int t,T f)
	{
		if(u==t)return f;
		for(;iter[u]<G[u].size();iter[u]++)
		{
			edge&e=G[u][iter[u]];
			if(e.cap>0&&level[u]<level[e.to])
			{
				T d=dfs(e.to,t,min(f,e.cap));
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
		for(;;)
		{
			fill(level.begin(),level.end(),-1);
			queue<int>P;
			level[s]=0;
			P.push(s);
			while(!P.empty())
			{
				int u=P.front();P.pop();
				for(edge&e:G[u])
				{
					if(e.cap>0&&level[e.to]<0)
					{
						level[e.to]=level[u]+1;
						P.push(e.to);
					}
				}
			}
			if(level[t]<0)return ret;
			fill(iter.begin(),iter.end(),0);
			for(T f;(f=dfs(s,t,numeric_limits<T>::max()))>0;)ret+=f;
		}
	}
};
