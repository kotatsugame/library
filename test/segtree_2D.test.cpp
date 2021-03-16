#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068"
#include<iostream>
using namespace std;
#include"segtree_2D.hpp"
int op(int a,int b){return a<b?a:b;}
int main()
{
	int H,W,Q;
	while(cin>>H>>W>>Q,H)
	{
		if(H<=W)
		{
			segtree_2D<int,op>P(H,W,(1L<<31)-1);
			for(int i=0;i<H;i++)for(int j=0;j<W;j++)
			{
				int A;cin>>A;
				P.set(i,j,A);
			}
			for(;Q--;)
			{
				int a,b,c,d;
				cin>>a>>b>>c>>d;
				cout<<P.prod(a,b,c+1,d+1)<<endl;
			}
		}
		else
		{
			segtree_2D<int,op>P(W,H,(1L<<31)-1);
			vector<vector<int> >A(W,vector<int>(H));
			for(int i=0;i<H;i++)for(int j=0;j<W;j++)cin>>A[j][i];
			P.copy(A);
			for(;Q--;)
			{
				int a,b,c,d;
				cin>>a>>b>>c>>d;
				cout<<P.prod(b,a,d+1,c+1)<<endl;
			}
		}
	}
}
