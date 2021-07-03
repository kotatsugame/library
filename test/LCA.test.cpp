#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include<iostream>
using namespace std;
#include"LCA.hpp"
int main()
{
	int N,Q;
	cin>>N>>Q;
	LCA P(N);
	for(int i=1;i<N;i++)
	{
		int p;cin>>p;P.add_edge(p,i);
	}
	P.build();
	for(;Q--;)
	{
		int u,v;cin>>u>>v;cout<<P.lca(u,v)<<endl;
	}
}
