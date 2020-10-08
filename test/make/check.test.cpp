#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"
#include<iostream>
using namespace std;
#include"include/floor_sum.hpp"
int main()
{
	int T;cin>>T;
	for(;T--;)
	{
		long N,M,A,B;
		cin>>N>>M>>A>>B;
		cout<<floor_sum(N,M,A,B)<<endl;
	}
}
