#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include<iostream>
using namespace std;
#include"../datastructure/segtree.cpp"
#include"../math/modint.cpp"
using mint=modint<998244353>;
int main()
{
	int N,Q;
	cin>>N>>Q;
	vector<pair<mint,mint> >A(N);
	for(int i=0;i<N;i++)cin>>A[i].first>>A[i].second;
	segtree<pair<mint,mint> >P(N,make_pair(1,0),
	[](pair<mint,mint>a,pair<mint,mint>b){a.second=a.second*b.first+b.second;a.first*=b.first;return a;},
	[](pair<mint,mint>a,pair<mint,mint>b){return b;});
	P.copy(A);
	for(;Q--;)
	{
		int t,a,b,c;cin>>t>>a>>b>>c;
		if(t==0)P.update(a,make_pair(b,c));
		else
		{
			pair<mint,mint>p=P.query(a,b);
			cout<<p.first*c+p.second<<endl;
		}
	}
}
