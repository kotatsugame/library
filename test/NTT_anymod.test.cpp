#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
#include<iostream>
using namespace std;
#include"../include/NTT_anymod.hpp"
int main()
{
	int N,M;
	cin>>N>>M;
	vector<int>A(N),B(M);
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<M;i++)cin>>B[i];
	vector<int>ans=multiply(A,B,(int)(1e9+7));
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<(i+1==ans.size()?"\n":" ");
}
