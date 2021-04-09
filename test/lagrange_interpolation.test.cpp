#define PROBLEM "https://yukicoder.me/problems/no/42"
#include<iostream>
using namespace std;
#include"modint.hpp"
#include"lagrange_interpolation.hpp"
using mint=modint<(int)1e9+9>;
mint dp[3000];
int main()
{
	int T;cin>>T;
	dp[0]=1;
	for(int x:{1,5,10,50,100,500})for(int i=0;i+x<3000;i++)dp[i+x]+=dp[i];
	for(;T--;)
	{
		long M;
		cin>>M;
		vector<mint>now(6);
		for(int i=0;i<6;i++)now[i]=dp[i*500+M%500];
		cout<<lagrange_interpolation(now,mint(M/500))<<endl;
	}
}
