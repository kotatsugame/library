#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include<iostream>
using namespace std;
#include"../math/NTT.cpp"
int main()
{
	int N,M;
	cin>>N>>M;
	vector<int>A(N),B(M);
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<M;i++)cin>>B[i];
	vector<int>ans=NTT<998244353,3>().multiply(A,B);
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<(i+1==ans.size()?"\n":" ");
}
