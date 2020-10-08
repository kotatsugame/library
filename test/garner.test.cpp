#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
#include<iostream>
using namespace std;
#include"../include/NTT.hpp"
#include"../include/garner.hpp"
int main()
{
	int N,M;
	cin>>N>>M;
	vector<int>A(N),B(M);
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<M;i++)cin>>B[i];
	vector<int>C1=NTT<998244353,3>().multiply(A,B);
	vector<int>C2=NTT<469762049,3>().multiply(A,B);
	vector<int>C3=NTT<167772161,3>().multiply(A,B);
	for(int i=0;i<C1.size();i++)
	{
		cout<<garner({C1[i],C2[i],C3[i]},{998244353,469762049,167772161},(int)(1e9+7))<<(i+1==C1.size()?"\n":" ");
	}
}
