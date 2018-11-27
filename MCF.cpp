//Minimum Cost Flow O(FE log V)
#include<algorithm>
#include<utility>
#include<vector>
#include<queue>
#include<limits>
template<typename T>
struct MCF{
	vector<vector<pair<pair<int,int>,pair<int,T> > > >G;
	vector<T>h,d;
	vector<int>pv,pe;
	MCF(int n_=0):G(n_),h(n_,0),d(n_),pv(n_),pe(n_){}
	void add_edge(int from,int to,int cap,T cost)
	{
		G[from].push_back(make_pair(
			make_pair(to,G[to].size()),make_pair(cap,cost)
		));
		G[to].push_back(make_pair(
			make_pair(from,G[from].size()-1),make_pair(0,-cost)
		));
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
					pair<pair<int,int>,pair<int,T> >&e=G[p.second][i];
					if(e.second.first>0&&
						d[e.first.first]>d[p.second]+e.second.second+h[p.second]-h[e.first.first])
					{
						d[e.first.first]=d[p.second]+e.second.second+h[p.second]-h[e.first.first];
						pv[e.first.first]=p.second;
						pe[e.first.first]=i;
						P.push(make_pair(d[e.first.first],e.first.first));
					}
				}
			}
			if(d[t]==numeric_limits<T>::max())return -1;
			for(int u=0;u<G.size();u++)h[u]+=d[u];
			int d=f;
			for(int u=t;u!=s;u=pv[u])d=min(d,G[pv[u]][pe[u]].second.first);
			f-=d;
			ret+=d*h[t];
			for(int u=t;u!=s;u=pv[u])
			{
				G[pv[u]][pe[u]].second.first-=d;
				G[u][G[pv[u]][pe[u]].first.second].second.first+=d;
			}
		}
		return ret;
	}
};
