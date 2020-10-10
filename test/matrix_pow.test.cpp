#define PROBLEM "https://yukicoder.me/problems/no/1050"
#include<iostream>
using namespace std;
#include"modint.hpp"
#include"matrix.hpp"
using mint=modint<(int)1e9+7>;
using Mat=Matrix<mint>;
main()
{
	int M,K;cin>>M>>K;
	Mat A(M);
	for(int i=0;i<M;i++)for(int j=0;j<M;j++)
	{
		A[(i+j)%M][i]++;
		A[i*j%M][i]++;
	}
	cout<<A.pow(K)[0][0]<<endl;
}
