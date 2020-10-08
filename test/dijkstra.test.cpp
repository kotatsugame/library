#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include<iostream>
using namespace std;
#include"dijkstra.hpp"
int main()
{
	int N,M,s,t;
	cin>>N>>M>>s>>t;
	vector<vector<pair<int,long> > >G(N);
	for(int i=0;i<M;i++)
	{
		int a,b,c;cin>>a>>b>>c;
		G[a].push_back(make_pair(b,c));
	}
	pair<vector<long>,vector<int> >p=dijkstra(s,G);
	vector<long>dist=p.first;
	vector<int>parent=p.second;
	if(dist[t]==numeric_limits<long>::max())
	{
		cout<<-1<<endl;
		return 0;
	}
	vector<pair<int,int> >edges;
	int u=t;
	while(u!=s)
	{
		edges.push_back(make_pair(parent[u],u));
		u=parent[u];
	}
	cout<<dist[t]<<" "<<edges.size()<<endl;
	for(int i=edges.size();i--;)cout<<edges[i].first<<" "<<edges[i].second<<endl;
}
