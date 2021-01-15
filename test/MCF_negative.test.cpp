#define PROBLEM "https://yukicoder.me/problems/no/1324"
#include<iostream>
using namespace std;
#include"MCF.hpp"
int N,K;
int A[200];
int ans=0;
int main()
{
	cin>>N>>K;
	MCF<int>Q(2*N+2);
	int st=2*N,go=st+1;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		Q.add_edge(st,i,A[i],0);
	}
	for(int i=0;i<N;i++)
	{
		int B;
		cin>>B;
		Q.add_edge(N+i,go,B,0);
	}
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)
	{
		int P;
		cin>>P;
		ans+=P*P;
		for(int k=1;k<=A[i];k++)Q.add_edge(i,N+j,1,(P-k)*(P-k)-(P-k+1)*(P-k+1));
	}
	cout<<ans+Q.min_cost_flow(st,go,K)<<endl;
}
