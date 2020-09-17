#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include<iostream>
using namespace std;
#include"../datastructure/lazysegtree.cpp"
const long mod=998244353;
int main()
{
	int N,Q;
	cin>>N>>Q;
	vector<pair<long,long> >A(N);
	for(int i=0;i<N;i++)cin>>A[i].first;
	lazysegtree<pair<long,long> >P(N,make_pair(0L,0L),
	[](pair<long,long>a,pair<long,long>b){return make_pair((a.first+b.first)%mod,0L);},
	[](pair<long,long>a,pair<long,long>b){return make_pair(a.first*b.first%mod,(a.second*b.first+b.second)%mod);},
	[](pair<long,long>a,pair<long,long>b,int l,int r){return make_pair((a.first*b.first+b.second*(r-l))%mod,0L);});
	P.copy(A);
	for(;Q--;)
	{
		int t;cin>>t;
		if(t==0)
		{
			int l,r,b,c;cin>>l>>r>>b>>c;
			P.update(l,r,make_pair(b,c));
		}
		else
		{
			int l,r;cin>>l>>r;
			cout<<P.query(l,r).first<<endl;
		}
	}
}
