#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include<iostream>
using namespace std;
#include"../datastructure/segtree.cpp"
const long mod=998244353;
int main()
{
	int N,Q;
	cin>>N>>Q;
	vector<pair<long,long> >A(N);
	for(int i=0;i<N;i++)cin>>A[i].first>>A[i].second;
	segtree<pair<long,long> >P(N,make_pair(1L,0L),
	[](pair<long,long>a,pair<long,long>b){return make_pair(a.first*b.first%mod,(a.second*b.first+b.second)%mod);},
	[](pair<long,long>a,pair<long,long>b){return b;}
	);
	P.copy(A);
	for(;Q--;)
	{
		int t,a,b,c;cin>>t>>a>>b>>c;
		if(t==0)P.update(a,make_pair(b,c));
		else
		{
			pair<long,long>p=P.query(a,b);
			cout<<(p.first*c+p.second)%mod<<endl;
		}
	}
}
