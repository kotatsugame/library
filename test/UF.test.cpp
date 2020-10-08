#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include<iostream>
using namespace std;
#include"../include/UF.hpp"
int main()
{
	int N,Q;
	cin>>N>>Q;
	UF uf(N);
	for(;Q--;)
	{
		int t,u,v;cin>>t>>u>>v;
		if(t==0)uf.unite(u,v);
		else cout<<uf.same(u,v)<<endl;
	}
}
