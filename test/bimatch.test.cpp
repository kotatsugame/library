#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include<iostream>
using namespace std;
#include"../include/bimatch.hpp"
int main()
{
	int L,R,M;
	cin>>L>>R>>M;
	bimatch P(L+R);
	for(int i=0;i<M;i++)
	{
		int u,v;cin>>u>>v;
		P.add_edge(u,L+v);
	}
	cout<<P.count()<<endl;
	for(int i=0;i<L;i++)
	{
		if(P.match[i]>=L)cout<<i<<" "<<P.match[i]-L<<endl;
	}
}
