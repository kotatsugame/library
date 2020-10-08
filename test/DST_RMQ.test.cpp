#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include<iostream>
using namespace std;
#include"DST.hpp"
int main()
{
	int N,Q;
	cin>>N>>Q;
	vector<int>A(N);
	for(int i=0;i<N;i++)cin>>A[i];
	DST<int>P(A);
	for(;Q--;)
	{
		int l,r;cin>>l>>r;
		cout<<P.query(l,r)<<endl;
	}
}
