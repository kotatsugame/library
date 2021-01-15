#define PROBLEM "https://yukicoder.me/problems/no/1290"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#include"dualsegtree.hpp"
int N,M;
long B[1<<17];
vector<int>E[1<<17];
int R[1<<17];
int main()
{
	cin>>N>>M;
	for(int i=0;i<N;i++)
	{
		cin>>B[i];
		if(i%2)B[i]=-B[i];
		R[i]=-1;
	}
	for(int i=0;i<M;i++)
	{
		int L,R;cin>>L>>R;
		L--;
		E[L].push_back(R);
	}
	for(int i=0;i<N;i++)if(!E[i].empty())
	{
		sort(E[i].begin(),E[i].end());
		R[i]=E[i][0];
		for(int j=1;j<E[i].size();j++)
		{
			int l=E[i][j-1],r=E[i][j];
			if(l<r)
			{
				E[l].push_back(r);
			}
		}
	}
	dualsegtree<long>P(N,0,[](long a,long b){return a+b;},[](long a,long b){return a+b;});
	P.copy(vector<long>(B,B+N));
	for(int i=0;i<N;i++)
	{
		long T=P.query(i);
		if(R[i]==-1)
		{
			if(T!=0)
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
		else
		{
			P.update(i,R[i],-T);
		}
	}
	cout<<"YES"<<endl;
}
