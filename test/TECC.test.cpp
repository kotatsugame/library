#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"
#include<iostream>
using namespace std;
#include"TECC.hpp"
int main()
{
	int N,M;
	cin>>N>>M;
	TECC P(N);
	for(int i=0;i<M;i++)
	{
		int u,v;cin>>u>>v;
		P.add_edge(u,v);
	}
	int k=P.build();
	vector<vector<int> >ans(k);
	for(int i=0;i<N;i++)ans[P[i]].push_back(i);
	cout<<k<<endl;
	for(vector<int>ret:ans)
	{
		cout<<ret.size();
		for(int id:ret)cout<<" "<<id;
		cout<<endl;
	}
}
