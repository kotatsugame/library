#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include<iostream>
using namespace std;
#include"../datastructure/segtree.cpp"
int main()
{
	int N,Q;
	cin>>N>>Q;
	vector<long>A(N);
	for(int i=0;i<N;i++)cin>>A[i];
	segtree<long>P(N,0,[](long a,long b){return a+b;},[](long a,long b){return a+b;});
	P.copy(A);
	for(;Q--;)
	{
		int t,l,r;cin>>t>>l>>r;
		if(t==0)P.update(l,r);
		else cout<<P.query(l,r)<<endl;
	}
}
