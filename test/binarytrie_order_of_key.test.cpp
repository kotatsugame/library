#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"
#include<iostream>
using namespace std;
#include"binarytrie.hpp"
int main()
{
	int N,Q;cin>>N>>Q;
	binarytrie<17>P;
	for(;Q--;)
	{
		int t,x,y;cin>>t>>x>>y;
		if(t==0)P.add(x,y);
		else cout<<P.order_of_key(y+1)-P.order_of_key(x)<<endl;
	}
}
