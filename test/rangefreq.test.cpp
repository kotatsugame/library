#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include<iostream>
using namespace std;
#include"../datastructure/rangefreq.cpp"
int main()
{
	int N,Q;
	cin>>N>>Q;
	vector<int>A(N);
	for(int i=0;i<N;i++)cin>>A[i];
	rangefreq<int>P(A);
	for(;Q--;)
	{
		int l,r,k;cin>>l>>r>>k;
		int L=0,R=1e9+1;
		while(R-L>1)
		{
			int mid=L+R>>1;
			if(P.query(l,r,mid)>k)R=mid;
			else L=mid;
		}
		cout<<L<<endl;
	}
}
