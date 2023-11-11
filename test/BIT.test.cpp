#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include<iostream>
using namespace std;
#include"BIT.hpp"
int main()
{
	int N,Q;
	cin>>N>>Q;
	BIT<long>P(N);
	for(int i=0;i<N;i++)
	{
		int A;cin>>A;
		P.add(i,A);
	}
	for(;Q--;)
	{
		int t,l,r;cin>>t>>l>>r;
		if(t==0)P.add(l,r);
		else cout<<P.sum(r)-P.sum(l)<<"\n";
	}
}
