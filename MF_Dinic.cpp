//Dinic O(EV^2)
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
#include<limits>
template<typename T>
struct MF{
	vector<vector<pair<pair<int,int>,T> > >G;
	vector<int>level,iter;
	MF(int n_=0):G(n_),level(n_),iter(n_){}
	void add_edge(int from,int to,T cap)
	{
		G[from].push_back(make_pair(
			make_pair(to,G[to].size()),cap
		));
		G[to].push_back(make_pair(
			make_pair(from,G[from].size()-1),0
		));
	}
	T dfs(int u,int t,T f)
	{
		if(u==t)return f;
		for(;iter[u]<G[u].size();iter[u]++)
		{
			pair<pair<int,int>,T>&e=G[u][iter[u]];
			if(e.second>0&&level[u]<level[e.first.first])
			{
				T d=dfs(e.first.first,t,min(f,e.second));
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
		for(;;)
		{
			fill(level.begin(),level.end(),-1);
			queue<int>P;
			level[s]=0;
			P.push(s);
			while(!P.empty())
			{
				int u=P.front();P.pop();
				for(pair<pair<int,int>,T>&e:G[u])
				{
					if(e.second>0&&level[e.first.first]<0)
					{
						level[e.first.first]=level[u]+1;
						P.push(e.first.first);
					}
				}
			}
			if(level[t]<0)return ret;
			fill(iter.begin(),iter.end(),0);
			for(T f;(f=dfs(s,t,numeric_limits<T>::max()))>0;)ret+=f;
		}
	}
};
