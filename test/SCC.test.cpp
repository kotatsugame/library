#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include<iostream>
using namespace std;
#include"graph/SCC.cpp"
int main()
{
	int N,M;
	cin>>N>>M;
	SCC P(N);
	for(int i=0;i<M;i++)
	{
		int u,v;cin>>u>>v;
		P.add_edge(u,v);
	}
	int K=P.build();
	cout<<K<<endl;
	vector<vector<int> >ans(K);
	for(int i=0;i<N;i++)ans[P[i]].push_back(i);
	for(vector<int>&a:ans)
	{
		cout<<a.size();
		for(int b:a)cout<<" "<<b;
		cout<<endl;
	}
}
