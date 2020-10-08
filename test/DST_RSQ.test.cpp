#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include<iostream>
using namespace std;
#include"DST.hpp"
int main()
{
	int N,Q;
	cin>>N>>Q;
	vector<long>A(N);
	for(int i=0;i<N;i++)cin>>A[i];
	DST<long>P(A,[](long a,long b){return a+b;});
	for(;Q--;)
	{
		int l,r;cin>>l>>r;
		cout<<P.query(l,r)<<endl;
	}
}
