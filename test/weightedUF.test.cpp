#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"
#include<iostream>
using namespace std;
#include"../datastructure/weightedUF.cpp"
int main()
{
	int N,Q;
	cin>>N>>Q;
	weightedUF<int>uf(N);
	for(;Q--;)
	{
		int t;cin>>t;
		if(t==0)
		{
			int x,y,z;cin>>x>>y>>z;
			uf.unite(x,y,z);
		}
		else
		{
			int x,y;cin>>x>>y;
			if(uf.same(x,y))cout<<uf.diff(x,y)<<endl;
			else cout<<"?"<<endl;
		}
	}
}
