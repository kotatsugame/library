#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"
#include<iostream>
using namespace std;
#include"modint.hpp"
#include"matrix.hpp"
using mint=modint<998244353>;
using Mat=Matrix<mint>;
int main()
{
	int N,M;cin>>N>>M;
	Mat A(N,M+1);
	for(int i=0;i<N;i++)for(int j=0;j<M;j++)cin>>A[i][j];
	for(int i=0;i<N;i++)cin>>A[i][M];
	int rank=A.elimination();
	{
		bool ex=false;
		for(int j=0;j<M;j++)if(A[rank-1][j]!=0)ex=true;
		if(!ex)rank--;
	}
	for(int i=rank;i<N;i++)if(A[i][M]!=0)
	{
		cout<<-1<<endl;
		return 0;
	}
	vector<int>num(M,-1);
	int cnt=0;
	for(int j=0;j<M;j++)
	{
		if(A[cnt][j]!=0)
		{
			num[j]=cnt++;
			if(cnt==rank)break;
		}
	}
	cout<<M-rank<<endl;
	for(int i=0;i<M;i++)
	{
		cout<<(num[i]>=0?A[num[i]][M]:0)<<(i+1==M?"\n":" ");
	}
	for(int j=0;j<M;j++)if(num[j]<0)
	{
		for(int i=0;i<M;i++)
		{
			cout<<(i==j?1:num[i]<0?0:-A[num[i]][j])<<(i+1==M?"\n":" ");
		}
	}
}
