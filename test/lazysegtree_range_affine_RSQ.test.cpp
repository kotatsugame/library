#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include<iostream>
using namespace std;
#include"lazysegtree.hpp"
#include"modint.hpp"
using mint=modint<998244353>;
int main()
{
	int N,Q;
	cin>>N>>Q;
	vector<pair<mint,mint> >A(N);
	for(int i=0;i<N;i++)cin>>A[i].first;
	lazysegtree<pair<mint,mint> >P(N,make_pair(0,0),
	[](pair<mint,mint>a,pair<mint,mint>b){a.first+=b.first;return a;},
	[](pair<mint,mint>a,pair<mint,mint>b){a.second=a.second*b.first+b.second;a.first*=b.first;return a;},
	[](pair<mint,mint>a,pair<mint,mint>b,int l,int r){a.first=a.first*b.first+b.second*(r-l);return a;});
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
