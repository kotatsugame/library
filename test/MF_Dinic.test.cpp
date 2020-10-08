#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include<iostream>
using namespace std;
#include"MF_Dinic.hpp"
int main()
{
	int L,R,M;
	cin>>L>>R>>M;
	MF<int>P(L+R+2);
	int s=L+R,t=L+R+1;
	for(int i=0;i<L;i++)P.add_edge(s,i,1);
	for(int i=0;i<R;i++)P.add_edge(L+i,t,1);
	for(int i=0;i<M;i++)
	{
		int u,v;cin>>u>>v;
		P.add_edge(u,L+v,1);
	}
	cout<<P.max_flow(s,t)<<endl;
	for(int i=0;i<L;i++)
	{
		for(int j=0;j<P.G[i].size();j++)
		{
			int v=P.G[i][j].to-L;
			if(0<=v&&v<R&&P.G[i][j].cap==0)cout<<i<<" "<<v<<endl;
		}
	}
}
