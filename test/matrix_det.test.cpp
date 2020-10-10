#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"
#include<iostream>
using namespace std;
#include"modint.hpp"
#include"matrix.hpp"
using mint=modint<998244353>;
using Mat=Matrix<mint>;
main()
{
	int N;cin>>N;
	Mat A(N);
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)cin>>A[i][j];
	cout<<A.det()<<endl;
}
