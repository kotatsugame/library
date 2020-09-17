#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include<iostream>
using namespace std;
#include"../datastructure/BIT.cpp"
int main()
{
	int N,Q;
	cin>>N>>Q;
	BIT<long>P(N);
	for(int i=0;i<N;i++)
	{
		long A;cin>>A;
		P.add(i+1,A);
	}
	for(;Q--;)
	{
		int t,l,r;cin>>t>>l>>r;
		if(t==0)P.add(l+1,r);
		else cout<<P.sum(r)-P.sum(l)<<endl;
	}
}
