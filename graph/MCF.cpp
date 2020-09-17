//Minimum Cost Flow O(FE log V)
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
#include<limits>
template<typename T>
struct MCF{
	struct edge{
		int to,rev,cap;
		T cost;
	};
	vector<vector<edge> >G;
	vector<T>h,d;
	vector<int>pv,pe;
	MCF(int n_=0):G(n_),h(n_,0),d(n_),pv(n_),pe(n_){}
	void add_edge(int from,int to,int cap,T cost)
	{
		G[from].push_back({to,(int)G[to].size(),cap,cost});
		G[to].push_back({from,(int)G[from].size()-1,0,-cost});
	}
	T min_cost_flow(int s,int t,int f)//ans or -1
	{
		T ret=0;
		while(f>0)
		{
			priority_queue<pair<T,int>,vector<pair<T,int> >,greater<pair<T,int> > >P;
			fill(d.begin(),d.end(),numeric_limits<T>::max());
			d[s]=0;
			P.push(make_pair(0,s));
			while(!P.empty())
			{
				pair<T,int>p=P.top();P.pop();
				if(d[p.second]<p.first)continue;
				for(int i=0;i<G[p.second].size();i++)
				{
					edge&e=G[p.second][i];
					if(e.cap>0&&d[e.to]>d[p.second]+e.cost+h[p.second]-h[e.to])
					{
						d[e.to]=d[p.second]+e.cost+h[p.second]-h[e.to];
						pv[e.to]=p.second;
						pe[e.to]=i;
						P.push(make_pair(d[e.to],e.to));
					}
				}
			}
			if(d[t]==numeric_limits<T>::max())return -1;
			for(int u=0;u<G.size();u++)h[u]+=d[u];
			int d=f;
			for(int u=t;u!=s;u=pv[u])d=min(d,G[pv[u]][pe[u]].cap);
			f-=d;
			ret+=d*h[t];
			for(int u=t;u!=s;u=pv[u])
			{
				G[pv[u]][pe[u]].cap-=d;
				G[u][G[pv[u]][pe[u]].rev].cap+=d;
			}
		}
		return ret;
	}
};
