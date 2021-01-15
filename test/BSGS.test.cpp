#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"
#include<iostream>
using namespace std;
#include"BSGS.hpp"
int main()
{
	int T;
	cin>>T;
	for(;T--;)
	{
		int X,Y,M;
		cin>>X>>Y>>M;
		cout<<BSGS(X,Y,M)<<endl;
	}
}
